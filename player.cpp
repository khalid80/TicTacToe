#include "player.h"

Player::Player(QString name, IBoard *board, CellStatus status):
  m_name(name),
  m_score(0),
  m_board(board),
  m_status(status)
{

}

int Player::getScore()
{
    return m_score;
}

IBoard *::Player::getBoard() const
{
    return m_board;
}


