#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->slider, SIGNAL(valueChanged(int)),
            this, SLOT(setNumber()));
    connect(ui->dial, SIGNAL(valueChanged(int)),
            this, SLOT(setNumber()));
    connect(ui->sliderButton, SIGNAL(toggled(bool)),
            this, SLOT(setNumber()));
    connect(ui->dialButton, SIGNAL(toggled(bool)),
            this, SLOT(setNumber()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::setNumber()
{
    if (ui->sliderButton->isChecked()){
        ui->slider->setDisabled(false);
        ui->lcdNumber->display(ui->slider->value());
        ui->dial->setValue(0);
        ui->dial->setDisabled(true);
    }
    if(ui->dialButton->isChecked()){
        ui->dial->setDisabled(false);
        ui->lcdNumber->display(ui->dial->value());
        ui->slider->setValue(0);
        ui->slider->setDisabled(true);
    }

}
