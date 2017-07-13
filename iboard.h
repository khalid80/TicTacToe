#ifndef IBOARD_H
#define IBOARD_H
#include "enums.h"

class IBoard {

public:
    virtual ~IBoard() {}
    virtual const CellStatus * getCells() const = 0;
    virtual int getRowsColumns() const = 0;
    virtual void onStatusChanged(int row, int col, PlayerType type, CellStatus status) = 0;
};

Q_DECLARE_INTERFACE(IBoard, "IBoard")

#endif // IBOARD_H

