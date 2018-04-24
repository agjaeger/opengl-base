#ifndef EXTGRAPHICSWINDOW_H
#define EXTGRAPHICSWINDOW_H

#include <QMainWindow>
#include "ui_extgraphicswindow.h"

class ExtGraphicsWindow : public QMainWindow
{
public:
    ExtGraphicsWindow(QWidget *parent = 0);
    ~ExtGraphicsWindow();

private:
    UI_ExtGraphicsWindow *ui;
};

#endif // EXTGRAPHICSWINDOW_H
