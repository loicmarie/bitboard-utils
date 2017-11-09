#include <assert.h>
#include "Bitboard.h"

void testInit() {
    Bitboard bb = Bitboard();
    assert(bb.state == 0);

    bb = Bitboard(1);
    assert(bb.state == 1);
}

int main() {
    testInit();
}
