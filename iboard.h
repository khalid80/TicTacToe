#ifndef IBOARD_H
#define IBOARD_H
#include "enums.h"
class Player;

class IBoard {

public:
    virtual ~IBoard() {}
    virtual CellStatus * getCells() const = 0;
    virtual int getRowsColumns() const = 0;
    virtual void onStatusChanged(int row, int col, Player *player, bool disableBoard) = 0;
    static CellStatus getWinner(CellStatus *cells, int size);// return Empty if tie;
};

Q_DECLARE_INTERFACE(IBoard, "IBoard")

#endif // IBOARD_H

