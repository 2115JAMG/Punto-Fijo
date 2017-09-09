#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <qmath.h>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

double MainWindow::funcion(double c){
     //F(x)= 2(c^2)-c-5
    return  sqrt((c+5)/2); //G(x)
}

void MainWindow::metodo(){
    QString temp,temp2,temp3,temp4;
    double x1=ui->X1->value();
    double err=ui->Err->value();
    double xr=0.0;
    double ea=100.0;
    double x2=0.0;
    int    a=0;
    while(ea>err){
        xr=sqrt((x1+5)/2);
        ea=100*std::abs(xr-x1)/xr;
        x1=xr;
        x2=xr;
        xr=0;
        a=a+1;
    }
    temp.append("Raíz ubicada en: ").append(temp2.setNum(x2)).append("\nError de: %").append(temp3.setNum(ea)).append("\nNúmero de iteraciones: ").append(temp4.setNum(a));
    ui->Texto->setText(temp);
}

void MainWindow::borrar(){
    ui->X1->setValue(0.0);
    ui->Err->setValue(0.0);
    ui->Texto->clear();
}
