#include <iostream>
#include <assert.h>
#include <cmath>
#include "Bitboard.h"

void testInit() {
    Bitboard bb = Bitboard();
    assert(bb.state == 0);
    assert(bb.w == 8);
    assert(bb.h == 8);

    bb = Bitboard(1);
    assert(bb.state == 1);
    assert(bb.w == 8);
    assert(bb.h == 8);

    bb = Bitboard(6, 6);
    assert(bb.state == 0);
    assert(bb.w == 6);
    assert(bb.h == 6);

    bb = Bitboard(1, 6, 6);
    assert(bb.state == 1);
    assert(bb.w == 6);
    assert(bb.h == 6);
}

void testPosOperations() {
    // Get cell on first line of board
    uint64_t state = 0x10;
    unsigned int bitpos = log2(state);
    Bitboard bb = Bitboard(state);
    assert(bb.get_from_mask(UINT64_C(1) << bitpos) == state);
    assert(bb.get_from_bitpos(bitpos) == state);
    assert(bb.get_from_cartesian(bitpos%bb.w, (int)(bitpos/bb.w)) == state);

    // Get cell on a line of board to test cartesian coordinates
    state = 0x2000;
    bitpos = log2(state);
    bb = Bitboard(state);
    assert(bb.get_from_mask(UINT64_C(1) << bitpos) == state);
    assert(bb.get_from_bitpos(bitpos) == state);
    assert(bb.get_from_cartesian(bitpos%bb.w, (int)(bitpos/bb.w)) == state);
}

int main() {
    testInit();
    testPosOperations();
}
