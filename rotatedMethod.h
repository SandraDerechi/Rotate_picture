#pragma once

#include <stdio.h>
#include <stdint.h>
#include <inttypes.h>
#include <stdlib.h>
#include "bmp.h"

struct image rotate( struct image const source );
