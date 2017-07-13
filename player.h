#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "iboard.h"
class Player : public QObject
{
    enum GameStatus
    {
        Won,
        Lost,
        Tie,
    };

public :
    Q_OBJECT
public:
    explicit Player(QString name, IBoard* board, CellStatus status, int totalGames = 0, int wins = 0, int ties = 0);
    int getWins() const;
    int getTies() const;
    int getTotalGames() const;
    virtual void start(int index = -1) = 0;
    virtual void setStatus(GameStatus status = Tie);

signals:

public slots:

protected:
    IBoard * getBoard() const;
    CellStatus getStatus() const;
private :
    QString m_name;
    int m_wins;
    int m_totalGames;
    int m_ties;

    IBoard * m_board;
    CellStatus m_status;
};

#endif // PLAYER_H
