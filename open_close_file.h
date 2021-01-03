#pragma once

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"

bool open_bmp(FILE **file, const char *filename, const char *modes);

bool close_bmp(FILE **file);