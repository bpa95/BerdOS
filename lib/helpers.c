#include "helpers.h"
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>
#include <sys/stat.h>
#include <fcntl.h>

ssize_t read_(int fd, void *buf, size_t nbyte)
{ 
    if (nbyte == 0) {
        return read(fd, buf, nbyte);
    }
    size_t n;
    size_t res = 0;
    for (;;) {
        n = read(fd, buf, nbyte);
        if (n == -1)
            return -1;
        if (n == 0 || n == nbyte)
            return res + n;
        buf += n;
        res += n;
        nbyte -= n;
    }
}


ssize_t write_(int fd, const void *buf, size_t nbyte)
{
    size_t n;
    size_t res = 0;
    do {
        n = write(fd, buf, nbyte);
        if (n == -1)
            return -1;
        buf += n;
        res += n;
        nbyte -= n;
    } while (n > 0 && nbyte > 0);
    return res;
}

ssize_t read_until(int fd, void *buf, size_t count, char delim)
{
    size_t n;
    size_t res;
    char ch;
    char* cbuf = (char*) buf;
    for (res = 0; res < count; res++) {
        n = read(fd, &ch, 1);
        if (n == -1) {
            return -1;
        }
        if (n == 0) {
            break;
        }
        cbuf[res] = ch;
        if (ch == delim) {
            res++;
            break;
        }
    }
    return res;
}

int spawn(const char * file, char * const argv [])
{
    pid_t c_pid = fork();
    if (c_pid == -1) {
        return -1;
    } else if (c_pid == 0) {
        int dev_null = open("/dev/null", O_WRONLY);
        int def_err = dup(STDERR_FILENO);
        dup2(dev_null, STDERR_FILENO);
        execvp(file, argv);
        dup2(STDERR_FILENO, def_err);
        return 0;
    } else {
        int status = 0;
        while ((waitpid(c_pid, &status, 0)) == -1) {
            if (errno != EINTR) {
                return -1;
            }
        }
        return status;
    }
    return 0;
}

