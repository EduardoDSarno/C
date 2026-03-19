#include "../block/block.h"
#include "../serialize/serialize.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int hash(Block *new_block, Block *prev_block);