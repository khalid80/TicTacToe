#include "human.h"

HumanPlayer::HumanPlayer(QString& name, IBoard *board, CellStatus status) : Player(name, board, status)
{

}

void HumanPlayer::start(int index)
{
    getBoard()->onStatusChanged(index/3, index%3, PlayerType::Human);
}
