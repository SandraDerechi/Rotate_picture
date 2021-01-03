#pragma once

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"

enum write_status {
    WRITE_OK = 0,
    WRITE_ERROR
};

enum write_status toBmp( FILE* out, struct image const* img);


