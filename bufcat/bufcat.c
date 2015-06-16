#include "bufio.h"

#define BUFSIZE 4096

int main()
{
    struct buf_t* buf = buf_new(BUFSIZE);
    while (1) {
        ssize_t r = buf_fill(STDIN_FILENO, buf, buf_capacity(buf));
        if (r == -1) {
            perror("can't read");
            break;
        } else if (r == 0) {
            break;
        } else {
            if (buf_flush(STDOUT_FILENO, buf, r) == -1) {
                perror("can't write");
                break;
            }
        }
    }
    buf_free(buf);
    return 0;
}
