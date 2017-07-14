#include "computerplayer.h"
#include "qdebug.h"
#include "utils.h"
#include "vector"

ComputerPlayer::ComputerPlayer(IBoard *board, CellStatus status) : Player(QString("Computer"), board, status)
{

}
Cell next(CellStatus *cells, int size, CellStatus status, CellStatus computer)
{
    CellStatus winner = Utils::getWinner(cells, size);
    CellStatus other = (computer == Value_O )?  Value_X : Value_O;

    if(winner == computer)
        return Cell(10);
    else if(winner == other)
        return Cell(-10);
    else if(winner == Value_Tie)
        return Cell(0);

    QList<Cell> list;

    for(int i = 0; i < size * size; ++i)
    {
        if(cells[i] == CellStatus::Value_Empty)
        {
            Cell cell;
            cell.index = i;
            cells[i] = status;
            if(status == computer)
                cell.weight = next(cells, size, other, computer).weight;
            else
                cell.weight = next(cells, size, computer, computer).weight;

            list.append(cell);
            cells[i] = Value_Empty;
        }
    }

    int index = 0;
    if(status == computer)
    {
        int max = list[0].weight;

        for(int i = 1; i < list.length(); ++i)
        {
            int weight = list[i].weight;
            if(weight > max)
            {
                max = weight;
                index = i;
            }
        }
    }
    else
    {
        int min = list[0].weight;

        for(int i = 1; i < list.length(); ++i)
        {
            int weight = list[i].weight;
            if(weight < min)
            {
                min = weight;
                index = i;
            }
        }
    }

    return list[index];
}

void ComputerPlayer::start(int index)
{
    if(index!=-1)
        return;

    IBoard * board = getBoard();
    int rowColumns = board->getRowsColumns();
    CellStatus * cells = board->getCells();


    index = next(cells, rowColumns, getStatus(), getStatus()).index;
    board->onStatusChanged(index / 3, index % 3, this, false);

    delete cells;

    /*****************************************Easy Level
    /*IBoard * board = getBoard();
    CellStatus * pCells = board->getCells();
    int rowColumns = board->getRowsColumns();
    int  boardSize = rowColumns * rowColumns;
    QList <int>empty;
    for(int i = 0; i < boardSize; ++i)
    {
        if(pCells[i] == CellStatus::Value_Empty)
        {
            empty.append(i);
            CellStatus value = getStatus();
            CellStatus otherValue = Value_X;

            if(value == CellStatus::Value_X)
                otherValue = CellStatus::Value_O;

            pCells[i] = value;

            int score = Utils::getWinner(pCells, rowColumns);

            if( score == value)
            {
                board->onStatusChanged(i / rowColumns, i % rowColumns, this, false);
                return;
            }

            pCells[i] = otherValue;

            score = Utils::getWinner(pCells, rowColumns);
            if(score == otherValue)
            {
                board->onStatusChanged(i / rowColumns, i % rowColumns, this, false);
                return;
            }

            pCells[i] = Value_Empty;
        }
    }

    if(empty.length() > 0)
        board->onStatusChanged(empty[0] / rowColumns, empty[0] % rowColumns, this, false);
        */
}
