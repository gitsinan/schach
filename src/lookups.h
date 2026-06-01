#pragma once
#include <stdint.h>
typedef uint64_t U64;
struct Magic { U64 mask; U64 magic; uint32_t offset; uint8_t shift; };
extern const Magic BishopMagics[64];
extern const Magic RookMagics[64];
extern const U64 SliderTable[];

