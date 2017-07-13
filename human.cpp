#include "human.h"

HumanPlayer::HumanPlayer(QString& name, IBoard *board, CellStatus status) : Player(name, board, status)
{

}

void HumanPlayer::start(int index)
{
    IBoard *board = getBoard();

    if(board != NULL)
    {
        int rowsColumns = board->getRowsColumns();
        board->onStatusChanged(index / rowsColumns, index % rowsColumns, PlayerType::Human, getStatus());
    }
}
