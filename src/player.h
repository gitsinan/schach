#pragma once
#include "pieces.h"
#include "operation.h"
#include <string>
enum StateFlags : uint16_t {
    NONE                = 0x0000, // 0000 0000
    CASTLED             = 0x0001, // 0000 0001
    EN_PASSANT_AVAIL    = 0x0002, // 0000 0010
    IS_CHECK            = 0x0004, // 0000 0100 
    MOVED_KING          = 0x0008, // 0000 1000 
    MOVED_ROOK_L        = 0x0010, // 0001 0000
    MOVED_ROOK_R        = 0x0020, // 0010 0000
    HOLDING             = 0x0040, // 0100 0000
    HOLDING2            = 0x0080, // 1000 0000
    A                   = 0x0000, // 0000 0000
    B                   = 0x0100, // 0000 0001
    C                   = 0x0200, // 0000 0010
    D                   = 0x0400, // 0000 0100 
    E                   = 0x0800, // 0000 1000 
    F                   = 0x1000, // 0001 0000
    G                   = 0x2000, // 0010 0000
    H                   = 0x4000, // 0100 0000
};

class Player{
    public:
        uint16_t flags;
        Side _side;
        Player(Side side);
        Operation HandleInput();
        std::string SideToString(Side side);
        
};