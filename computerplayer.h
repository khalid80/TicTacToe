#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "player.h"

struct Cell
{
    Cell()
    {

    }

    Cell(int weight) :weight(weight){}

    int index;
    int weight;
};


class ComputerPlayer : public Player
{
    Q_OBJECT
public:
    explicit ComputerPlayer(IBoard * board, CellStatus status);
    virtual void start(int index =-1) override;
private :

};

#endif // COMPUTERPLAYER_H
