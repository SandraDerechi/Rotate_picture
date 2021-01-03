#pragma once

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"

enum read_status  {
    READ_OK = 0,
    READ_INVALID_BITS,
    READ_INVALID_HEADER
    /* коды других ошибок  */
};
enum read_status fromBMP( FILE* in, struct image* img);