#include "helpers.h"
#include <stdlib.h>

#define BUFSIZE 4096
#define ARGSIZE 4096

int main(int argc, char * argv[])
{
    char** args = (char**) calloc(ARGSIZE, sizeof(char*));

    char buf[BUFSIZE];
    char buf2[BUFSIZE];
    while (1) {
        ssize_t n = read_until(STDIN_FILENO, buf, BUFSIZE, '\n');
        if (n == -1) {
            perror("can't read");
            break;
        } else if (n == 0) {
            break;
        } else {
            args[0] = &buf[0];
            int i;
            int j = 1;
            int l = 0;
            for (i = 0; i < n; i++) {
                buf2[l++] = buf[i];
                if (buf[i] == ' ' || buf[i] == '\n') {
                    buf[i] = '\0';
                    while (i+1 < n && buf[i+1] == ' ') {
                        i++;
                    }
                    if (i+1 < n) {
                        args[j++] = &buf[i+1];
                    }
                }
            }
            args[j+1] = NULL;
            for (i = 1; i < argc; i++) {
                args[j] = argv[i];
                int f = 0;
                if (buf2[l-1] == '\n') {
                    f = 1;
                    l--;
                }
                int k = 0;
                buf2[l++] = ' ';
                while (argv[i][k] != '\0') {
                    buf2[l++] = argv[i][k++];
                }
                if (f == 1) {
                    buf2[l++] = '\n';
                }
                if (spawn(args[0], args) == 0) {
                    if (write(STDOUT_FILENO, buf2, l) == -1) {
                        perror("can't write");
                    }
                }
                l -= k + 1;
                if (f == 1) {
                    buf2[l-1] = '\n';
                }
            }
        }
    }

    free(args);
    return 0;
}
