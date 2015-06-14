#include "bufio.h"
#include <stdlib.h>

struct buf_t *buf_new(size_t capacity)
{
    return NULL;
}

void buf_free(struct buf_t * buf)
{

}

size_t buf_capacity(struct buf_t * buf)
{
    return 0;
}

size_t buf_size(struct buf_t * buf)
{
    return 0;
}

ssize_t buf_fill(int fd, struct buf_t * buf, size_t required)
{
    return 0;
}

ssize_t buf_flush(int fd, struct buf_t * buf, size_t required)
{
    return 0;
}

