#include "helpers.h"
#include <stdlib.h>

#define BUFSIZE 4096

int main(int argc, char * argv[])
{
    char** args = (char**) calloc(argc + 1, sizeof(char*));
    int i;
    for (i = 0; i < argc - 1; i++) {
        args[i] = argv[i + 1];
    }
    args[argc] = NULL;

    char buf[BUFSIZE];
    while (1) {
        ssize_t n = read_until(STDIN_FILENO, buf, BUFSIZE, '\n');
        if (n == -1) {
            perror("can't read");
            break;
        } else if (n == 0) {
            break;
        } else {
            args[argc - 1] = buf;
            if (buf[n-1] == '\n') {
                buf[n-1] = '\0';
            }
            if (spawn(args[0], args) == 0) {
                if (buf[n-1] == '\0') {
                    buf[n-1] = '\n';
                }
                if (write(STDOUT_FILENO, buf, n) == -1) {
                    perror("can't write");
                }
            }
        }
    }

    free(args);
    return 0;
}
