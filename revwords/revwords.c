#include <helpers.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define DELIM ' '
#define BUFSIZE 4096

int main()
{
    char buf[BUFSIZE];
    while (1) {
        int n = read_until(STDIN_FILENO, buf, BUFSIZE, ' ');
        if (n == -1) {
            perror("can't read");
            return -1;
        }
        if (n == 0) {
            return 0;
        }
        int f = 0;
        if (buf[n - 1] == ' ') {
            n--;
            f = 1;
        }
        int i, j;
        for (i = 0, j = n - 1; i < j; i++, j--) {
            char ch = buf[i];
            buf[i] = buf[j];
            buf[j] = ch;
        }
        if (write_(STDOUT_FILENO, buf, n + f) == -1) {
            perror("can't write");
            return -1;
        }
    }
}
