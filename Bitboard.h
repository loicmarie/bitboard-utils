#ifndef DEF_BITBOARD
#define DEF_BITBOARD

#include <stdint.h>

struct Bitboard {
    uint64_t state;
    inline Bitboard() : state(0x0) {}
    inline Bitboard(int value) : state(value) {};
};

#endif // DEF_BITBOARD
