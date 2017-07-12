#include "boardcellbutton.h"
#include "player.h"

//QPixmap BoardCellButton::XIcon(":/Images/X");
//QPixmap BoardCellButton::OIcon(":/Images/O");
//QPixmap BoardCellButton::EmptyIcon = NULL;
BoardCellButton::BoardCellButton(int index):
    m_index(index),
    m_status(CellStatus::Value_Empty)
{
    OIcon = QPixmap(":/images/O");
    XIcon = QPixmap(":/images/X");
    EmptyIcon = QPixmap(":/images/Empty");

    setStatus(CellStatus::Value_Empty);
    setSizePolicy(QSizePolicy::Policy::Minimum, QSizePolicy::Policy::Minimum);
}

BoardCellButton::~BoardCellButton()
{

}

void BoardCellButton::setStatus(CellStatus status)
{
    m_status = status;

    switch (status) {
    case CellStatus::Value_X:
        setIcon(QIcon(XIcon));
        break;
    case CellStatus::Value_O:
        setIcon(QIcon(OIcon));
        break;
    default:
        setIcon(QIcon(EmptyIcon));
        break;
    }

    setIconSize(QSize(128,128));
}

CellStatus BoardCellButton::getStatus()
{
    return m_status;
}

int BoardCellButton::getIndex()
{
    return m_index;
}


