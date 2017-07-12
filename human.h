#ifndef HUMAN_H
#define HUMAN_H
#include "player.h"

class HumanPlayer : public Player
{
    Q_OBJECT
public:
    explicit HumanPlayer(QString& name, IBoard *board, CellStatus status);
    virtual void start(int index =-1) override;
};

#endif // HUMAN_H
