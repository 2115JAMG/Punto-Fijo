#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QString>
#include <qmath.h>
#include <cmath>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);//The interface connections to the program are created
    connect(ui->Procesar,SIGNAL(clicked()),this,SLOT(metodo()));
    connect(ui->Borrar,SIGNAL(clicked()),this,SLOT(borrar()));
    connect(ui->Salir,SIGNAL(clicked()),this,SLOT(close()));
}

MainWindow::~MainWindow()
{
    delete ui;
}
//Enter the function to be evaluated
double MainWindow::funcion(double c){
     //F(x)= 2(c^2)-c-5
    return  sqrt((c+5)/2); //G(x)
}
//read the values entered by the user
void MainWindow::metodo(){
    QString temp,temp2,temp3,temp4;
    double x1=ui->X1->value();
    double err=ui->Err->value();
    double xr=0.0;
    double ea=100.0;
    double x2=0.0;
    int    a=0;
    //The cycle is created for the solution of the method
    while(ea>err){
        xr=sqrt((x1+5)/2);
        ea=100*std::abs(xr-x1)/xr;//the error is calculated
        x1=xr;//change the value of X with the result of Xr
        x2=xr;
        xr=0;
        a=a+1;//the iteration number is increased
    }
    //the result is generated as string
    temp.append("Raíz ubicada en: ").append(temp2.setNum(x2)).append("\nError de: %").append(temp3.setNum(ea)).append("\nNúmero de iteraciones: ").append(temp4.setNum(a));
    ui->Texto->setText(temp);
}
//funtion "Limpiar" is defined to clean the interface
void MainWindow::borrar(){
    ui->X1->setValue(0.0);
    ui->Err->setValue(0.0);
    ui->Texto->clear();
}
