#include "toBMP.h"

enum write_status toBmp( FILE* out, struct image const* img){
    const size_t wigth = img->width;
    const size_t height = img->height;
    size_t count = 0;

    size_t padding = 0;
    if ((wigth*3)%4 != 0)
        padding = 4-(wigth*3)%4;
    for (size_t h = 0; h < height; ++h) {
        for (size_t w = 0; w < wigth; ++w)
            count += fwrite( img->data + (wigth * h + w), sizeof(struct pixel), 1, out);
        fwrite("0", 1, padding, out);
    }

    if (count != height*wigth)
        return WRITE_ERROR;

    return WRITE_OK;
}

