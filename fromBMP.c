#include "fromBMP.h"

enum read_status fromBMP( FILE* in, struct image* img){
    const size_t wigth = img->width;
    const size_t height = img->height;
    if(wigth == 0 && height == 0)
    {
        printf("invalid header");
        return READ_INVALID_HEADER;
    }
    size_t count = 0;
    size_t padding = 0;
    if ((wigth*3)%4 != 0)
        padding = 4-(wigth*3)%4;
    struct pixel buffer[wigth*height];

    fseek(in, sizeof (struct bmp_header), SEEK_CUR);
    for (size_t h = 0; h < height; ++h) {
        for (size_t w = 0; w < wigth; ++w)
            count += fread(buffer + (wigth * h + w), sizeof(struct pixel), 1, in);
        fseek(in, padding, SEEK_CUR);
    }
    if(count != wigth*height)
    {
        printf("count of pixels in header != read count of pixels");
        return READ_INVALID_BITS;
    }

    img->data = buffer;

    return READ_OK;
};