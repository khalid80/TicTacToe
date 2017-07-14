#include "utils.h"
#include "qdebug.h"
CellStatus checkSum(int value, int size)
{
    float val = (float)(value)/(float)(size);

    if(val == CellStatus::Value_O || val == CellStatus::Value_X)
        return (CellStatus)(int)val;

    return CellStatus::Value_Empty;
}

CellStatus Utils:: getWinner(CellStatus *pCells, int size)
{
    if(pCells== NULL)
        return CellStatus::Value_Empty;// TODO:Through user error exception

    // check diagonals
    int firstDiagonal = 0;
    int secondDiagonal = 0;
    for(int i = 0; i < size; ++i)
    {
        int stride = i* size;
        firstDiagonal+= pCells[stride + i];
        secondDiagonal+= pCells[stride + size - i -1];
    }

    CellStatus status = checkSum(firstDiagonal, size);
    if( status != CellStatus::Value_Empty)
        return status;

    status = checkSum(secondDiagonal,size);
    if( status != CellStatus::Value_Empty)
        return status;

    for(int row =0; row < size; ++row)
    {
        int rowSum = 0;
        int columnSum = 0;
        for(int col =  0; col < size; ++col)
        {
            rowSum += pCells[row * size + col];
            columnSum += pCells[col * size + row];
        }

        status = checkSum(rowSum, size);
        if( status != CellStatus::Value_Empty)
            return status;

        status = checkSum(columnSum, size);
        if( status != CellStatus::Value_Empty)
            return status;
    }

    for(int i = 0; i < size * size; ++i)
        if(pCells[i] == Value_Empty) return Value_Empty;

    return CellStatus::Value_Tie;
}



