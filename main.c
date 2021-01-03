#include <stdio.h>

#include "bmp.h"
#include "util.h"
#include "fromBMP.h"
#include "toBMP.h"
#include "rotatedMethod.h"
#include "open_close_file.h"


void usage() {
    fprintf(stderr, "Usage: ./print_header BMP_FILE_NAME\n");
}

int main(int argc, char **argv) {
    if (argc != 2) usage();
    if (argc < 2) err("Not enough arguments \n");
    if (argc > 2) err("Too many arguments \n");

    struct bmp_header h = {0};
    struct image img;
    if (read_header_from_file(argv[1], &h)) {
        bmp_header_print(&h, stdout);
    } else {
        err("Failed to open BMP file or reading header.\n");
    }

    FILE *input;
    FILE *output;
    open_bmp(&input, argv[1], "rb");
    open_bmp(&output, "../img/newImage.bmp", "wb");
//        FILE *input = fopen(argv[1], "rb");
//        FILE *output = fopen("../img/newImage.bmp", "wb");
    img.height = h.biHeight;
    img.width = h.biWidth;
    if (fromBMP(input, &img) != READ_OK)
        err ("read error");
    h.biWidth = img.height;
    h.biHeight = img.width;
    img = rotate(img);
    fwrite(&h, sizeof (struct  bmp_header), 1, output);
    if(toBmp(output, &img) != READ_OK)
        err("write error");
    close_bmp(&input);
    close_bmp(&output);
    // fclose(input);
    //fclose(output);

    return 0;
}