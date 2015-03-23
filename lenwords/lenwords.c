#include <helpers.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define DELIM ' '

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
    size_t ws = 0;
    char delim = DELIM;
    char len[4096];
    int ll;
    do {
        n = read_until(STDIN_FILENO, buf, sizeof(buf), DELIM);
        if (n == -1) {
            exwitherr();
        }
        int i;
        for (i = 0; i < n; i++) {
            if (buf[i] != DELIM) {
                ws++;
            } else {
                ll = sprintf(len, "%d", (int) ws);
                if (write_(STDOUT_FILENO, len, ll) == -1) {
                    exwitherr();
                }
                if (write_(STDOUT_FILENO, &delim, (size_t) 1) == -1) {
                    exwitherr();
                }
                ws = 0;
            }
        }
    } while (n > 0);
    ll = sprintf(len, "%d", (int) ws);
    if (write_(STDOUT_FILENO, len, ll) == -1) {
        exwitherr();
    }
    if (write_(STDOUT_FILENO, &delim, (size_t) 1) == -1) {
        exwitherr();
    }
    return 0;
}
