#include <helpers.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

void exwitherr()
{
    char *er = strerror(errno);
    write_(STDERR_FILENO, er, sizeof(char) * strlen(er));
    exit(1);
}

main()
{
    char buf[4096];
    size_t n;
    size_t nw;
    do {
        n = read_(STDIN_FILENO, buf, sizeof(buf));
        if (n == -1) {
            exwitherr();
        }
        if (write_(STDOUT_FILENO, buf, n) < n) {
            exwitherr();
        }
    } while (n == sizeof(buf));
    return 0;
}
