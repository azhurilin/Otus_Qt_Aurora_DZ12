#include "calcengine.h"
#include <QDebug>
#include <math.h>


//=====================*******=====================
CalcEngine::CalcEngine(QObject *parent) : QObject(parent)
{

 RX=0;
      qDebug()<<"CalcEngine create";

}
//=====================*******=====================
CalcEngine::~CalcEngine()
{
  qDebug()<<"CalcEngine destroy";

}
//=====================*******=====================
double CalcEngine::GetRX() {

     //return RX / pow(10, RX_E);

     return dRX;

     }
//=====================*******=====================
void CalcEngine::AddDigit(int d)
{
    if (Calc_flag) {RX = 0; RX_E = 0; Calc_flag = 0; Point_flag = 0;}

    RX= RX*10 + d;

    if(Point_flag) RX_E++;

    dRX = RX / pow(10, RX_E);

}
//=====================*******=====================
void CalcEngine::DelDigit()
{
    RX = RX / 10; if(RX_E > 0) RX_E--;

    dRX = dRX / 10;
}
//=====================*******=====================
void CalcEngine::CalcResult()
{
   if (RX_E >= RY_E) {RY = RY * pow(10, RX_E - RY_E); RY_E = RX_E;}
    else {RX = RX * pow(10, RY_E - RX_E); RX_E = RY_E;}


   if (RY>0 && RX>0){



       switch (OP) {

        case 1:         //+
          RX = RY + RX; dRX = dRY + dRX;
          break;

        case 2:         //-
          RX = RY - RX; dRX = dRY - dRX;
          break;

        case 3:
          RX = RY * RX; dRX = dRY * dRX;
          break;

        case 4:
          RX = RY / RX; dRX = dRY / dRX;
          break;

       }

   }

   RY = 0; RY_E =0;
   Calc_flag = 1;
   OP = 0;

}
//=====================*******=====================
QString CPrint(){

return "CalcEngine";
}
//=====================*******=====================


