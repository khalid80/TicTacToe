#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>


class MainWindow;
class Player;
class TicTacToeWidget;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void onResetClick();
    void onQuitClick();
    void onInfoClick();
    void onSettingsClick();

private:
    Player * m_computer;
    Player * m_you;

    TicTacToeWidget *m_pTicTacToeWidget;
};

#endif // MAINWINDOW_H
