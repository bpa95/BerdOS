#include "bufio.h"
#include <stdlib.h>

struct buf_t* buf_new(size_t capacity)
{
    struct buf_t* buf = (struct buf_t*) malloc(sizeof(struct buf_t));
    if (buf == NULL) {
        return NULL;
    }
    buf->capacity = capacity;
    buf->size = 0;
    if ((buf->data = malloc(capacity)) == NULL) {
        free(buf);
        return NULL;
    }
    return buf;
}

void buf_free(struct buf_t * buf)
{
    free(buf->data);
    free(buf);
}

size_t buf_capacity(struct buf_t * buf)
{
    return buf->capacity;
}

size_t buf_size(struct buf_t * buf)
{
    return buf->size;
}

ssize_t buf_fill(int fd, struct buf_t * buf, size_t required)
{
    return 0;
}

ssize_t buf_flush(int fd, struct buf_t * buf, size_t required)
{
    return 0;
}

