#include "computerplayer.h"
#include "qdebug.h"

ComputerPlayer::ComputerPlayer(IBoard *board, CellStatus status) : Player(QString("Computer"), board, status)
{

}

void ComputerPlayer::start(int index)
{
    Q_UNUSED(index);

    IBoard * board = getBoard();
    if(board != NULL)
    {
        int rowColumns = board->getRowsColumns();
        int boardSize = rowColumns * rowColumns;
        const CellStatus * cells = board->getCells();
        if(cells != NULL)
        {

            QList<int> empty;

            for(int i = 0; i < boardSize; ++i)
            {
               if(cells[i] == CellStatus::Value_Empty)
                   empty.append(i);
            }

            if(empty.length() > 0)
            {
                int cell = empty[(qrand() *10000) % empty.length()];

                board->onStatusChanged(cell / rowColumns, cell % rowColumns, PlayerType::Computer, getStatus());
            }
        }
    }
}
