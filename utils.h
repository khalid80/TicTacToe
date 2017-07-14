#ifndef UTILS_H
#define UTILS_H

#include "enums.h"

class Utils
{
private:
    Utils();

public :
    static CellStatus getWinner(CellStatus *pCells, int size);
};

#endif // IUTILS_H
