#include "rotatedMethod.h"

struct image rotate( struct image const source ){
    struct image i;
    const size_t wigth = source.width;
    const size_t height = source.height;
    i.width = height;
    i.height = wigth;
    struct pixel buffer[2*wigth*height];
    for (size_t h = 0; h < height; ++h) {
        for (size_t w = 0; w < wigth; ++w)
            buffer[(height - 1 - h)+height*w] = source.data[h*wigth + w];
    }
    i.data = buffer;
    return i;
}
