#include "formbookmarks.h"
#include "ui_formbookmarks.h"

FormBookmarks::FormBookmarks(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FormBookmarks)
{
    ui->setupUi(this);
}

FormBookmarks::~FormBookmarks()
{
    delete ui;
}
