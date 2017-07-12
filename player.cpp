#include "player.h"

Player::Player(QString name, IBoard *board, CellStatus status, int totalGames, int wins, int ties):
  m_name(name),
  m_board(board),
  m_status(status),
  m_totalGames(totalGames++),
  m_wins(wins),
  m_ties(ties)
{

}

int Player::getWins() const
{
    return m_wins;
}

int Player :: getTies() const
{
    return m_ties;
}

int Player::getTotalGames() const
{
    return m_totalGames;
}

void Player::setStatus(GameStatus status)
{
    switch(status)
    {
        case GameStatus::Won:
            m_wins++;
            break;
        case GameStatus::Tie:
            m_ties++;
            break;
        default:
        break;

    }
}

IBoard *::Player::getBoard() const
{
    return m_board;
}


