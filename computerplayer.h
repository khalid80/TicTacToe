#ifndef COMPUTERPLAYER_H
#define COMPUTERPLAYER_H
#include "player.h"

class ComputerPlayer : public Player
{
    Q_OBJECT
public:
    explicit ComputerPlayer(IBoard *board, CellStatus status);
    virtual void start(int index =-1) override;
};

#endif // COMPUTERPLAYER_H
