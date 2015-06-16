#include "bufio.h"
#include <stdlib.h>
#include <string.h>

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
    size_t *size = &buf->size;
    size_t *capacity = &buf->capacity;
    void* data = buf->data;
    while (*size < required) {
        ssize_t r = read(fd, data + *size, *capacity - *size);
        if (r == -1) {
            return -1;
        } else if (r == 0) {
            break;
        } else {
            *size += r;
        }
    }
    return *size; 
}

ssize_t buf_flush(int fd, struct buf_t * buf, size_t required)
{
    size_t *size = &buf->size;
    void* data = buf->data;
    ssize_t tw = 0;
    if (required > *size) {
        required = *size;
    }
    while (tw < required) {
        ssize_t w = write(fd, data + tw, required - tw);
        if (w == -1) {
            *size -= tw;
            memmove(data, data + tw, *size);
            return -1;
        } else if (w == 0) {
            break;
        } else {
            tw += w;
        }
    }
    *size -= tw;
    memmove(data, data + tw, *size);
    return tw;
}

