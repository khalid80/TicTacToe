#ifndef PLAYER_H
#define PLAYER_H

#include <QObject>
#include "iboard.h"
class Player : public QObject
{
public :
    Q_OBJECT
public:
    explicit Player(QString name, IBoard* board, CellStatus status);
    int getScore();
    virtual void start(int index = -1) = 0;

signals:

public slots:

protected:
    IBoard * getBoard() const;
private :
    QString m_name;
    int m_score;
    IBoard * m_board;
    CellStatus m_status;
};

#endif // PLAYER_H
