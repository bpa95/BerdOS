#include "helpers.h"

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
        res += n;
        nbyte -= n;
    } while (n > 0 && nbyte > 0);
    return res;
}

