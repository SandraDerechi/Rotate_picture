#include "open_close_file.h"

bool open_bmp(FILE **file, const char *filename, const char *modes)
{
    *file = fopen(filename, modes);

    if (*file)
        return true;
    printf("open error\n");
    return false;
}

bool close_bmp(FILE **file)
{
    if (fclose(*file) != -1)
        return true;
    printf("close error\n");
    return false;
}