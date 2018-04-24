#include "extgraphicswindow.h"

ExtGraphicsWindow::ExtGraphicsWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new UI_ExtGraphicsWindow)
{
    ui->setupUi(this);
}

ExtGraphicsWindow::~ExtGraphicsWindow()
{
    delete ui;
}
