#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "iboard.h"
class Player : public QObject
{
public :
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
    virtual void setResult(GameStatus status = Tie);
    virtual void setStatus(CellStatus status);
    CellStatus getStatus() const;
signals:

public slots:

protected:
    IBoard * getBoard() const;
private :
    QString m_name;
    int m_wins;
    int m_totalGames;
    int m_ties;

    IBoard * m_board;
    CellStatus m_status;
};

#endif // PLAYER_H
