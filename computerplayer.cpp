#include "computerplayer.h"
#include "qdebug.h"

ComputerPlayer::ComputerPlayer(IBoard *board, CellStatus status) : Player(QString("Computer"), board, status)
{

}

void ComputerPlayer::start(int index)
{
   IBoard * board = getBoard();
   const CellStatus * cells = board->getCells();
   QList<int> empty;

   for(int i =0; i < 9; ++i)
   {
       if(cells[i] == CellStatus::Value_Empty)
           empty.append(i);
   }

   if(empty.length() > 0)
   {
        int cell = empty[qrand() % empty.length()];

        board->onStatusChanged(cell / 3, cell % 3, PlayerType::Computer);
   }
}
