#include <helpers.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

#define DELIM ' '

void exwitherr()
{
    char *er = strerror(errno);
    write_(STDERR_FILENO, er, sizeof(char) * strlen(er));
    exit(1);
}

void reverse(char* word, size_t ws)
{
    int i;
    for (i = 0; i < ws / 2; i++) {
        char ch = word[i];
        word[i] = word[ws - i - 1];
        word[ws - i - 1] = ch;
    }
}

main()
{
    char buf[4096];
    size_t n;
    char word[4096];
    size_t ws = 0;
    do {
        n = read_until(STDIN_FILENO, buf, sizeof(buf), DELIM);
        if (n == -1) {
            exwitherr();
        }

        int i;
        for (i = 0; i < n; i++) {
            if (buf[i] != DELIM) {
                word[ws++] = buf[i];
            } else {
                reverse(word, ws);
                word[ws++] = DELIM;
                write_(STDOUT_FILENO, word, ws);
                ws = 0;
            }
        }
    } while (n > 0);
    reverse(word, ws);
    write_(STDOUT_FILENO, word, ws);
    return 0;
}
