#ifndef DEF_BITBOARD
#define DEF_BITBOARD

#include <stdint.h>

struct Bitboard {
    int w, h;
    uint64_t state;

    inline Bitboard() : w(8), h(8), state(0x0) {}
    inline Bitboard(int value) : w(8), h(8), state(value) {}
    inline Bitboard(int w, int h) : w(w), h(h), state(0x0) {}
    inline Bitboard(int value, int w, int h) : w(w), h(h), state(value) {}

    inline uint64_t get_from_mask(uint64_t mask) { return state & mask; }
    inline uint64_t get_from_bitpos(int bitpos) { return get_from_mask(UINT64_C(1) << bitpos); }
    inline uint64_t get_from_cartesian(int x, int y) { return get_from_bitpos(y * w + x); }
};

#endif // DEF_BITBOARD
