#pragma once
#ifndef OPERATIONHEADER
#define OPERATIONHEADER
#endif
#include "pieces.h"

class Operation {
    public:
        char charOfPiece;
        bool isCapture = false;
        int8_t toRow;
        int8_t toCol;
};