#ifndef CALCENGINE_H
#define CALCENGINE_H

#include <QObject>
#include <QDebug>

class CalcEngine : public QObject
{
    Q_OBJECT
public:
    explicit CalcEngine(QObject *parent = nullptr);

            ~CalcEngine();
//=====================*******=====================

   double GetRX();



   //quint8 GetRX();



   void AddDigit(int d);
   void DelDigit();

   void CalcResult();


  // void CalcAdd();




   QString CPrint();

//=====================*******=====================
signals:
    void signal_updateISD();


//=====================*******=====================
public slots:


//=====================*******=====================
void slot_btn_A_1(){
     qDebug()<<"Button F pressed";




     emit signal_updateISD();
    }
//=====================*******=====================




//=====================*******=====================
void slot_btn_B_1(){
     qDebug()<<"Button 1 pressed";

    AddDigit(1);
    emit signal_updateISD();
    }
//=====================*******=====================
void slot_btn_B_2(){
    qDebug()<<"Button 2 pressed";

    AddDigit(2);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_3(){
     qDebug()<<"Button 3 pressed";

    AddDigit(3);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_4(){
     qDebug()<<"Button 4 pressed";

    AddDigit(4);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_5(){
     qDebug()<<"Button 5 pressed";

    AddDigit(5);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_6(){
     qDebug()<<"Button 6 pressed";

    AddDigit(6);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_7(){
     qDebug()<<"Button 7 pressed";

    AddDigit(7);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_8(){
     qDebug()<<"Button 8 pressed";

    AddDigit(8);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_9(){
     qDebug()<<"Button 9 pressed";

    AddDigit(9);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_btn_B_10(){
     qDebug()<<"Button 0 pressed";

    AddDigit(0);
    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_back(){
     qDebug()<<"Button back pressed";

    DelDigit();

    emit signal_updateISD();
    }
//=====================*******=====================
//=====================*******=====================
    void slot_add(){
     qDebug()<<"Button addition pressed";

    if(RX){
      OP = 1;
      RY = RX; RY_E = RX_E;  dRY=dRX;
      Calc_flag = 1;
     }

    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_sub(){
     qDebug()<<"Button subtraction pressed";

    if(RX){
      OP = 2;
      RY = RX; RY_E = RX_E;  dRY=dRX;
      Calc_flag = 1;
     }

    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_mul(){
     qDebug()<<"Button multiply pressed";

    if(RX){
      OP = 3;
      RY = RX; RY_E = RX_E;  dRY=dRX;
      Calc_flag = 1;
     }

    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_div(){
     qDebug()<<"Button division pressed";

    if(RX){
      OP = 4;
      RY = RX; RY_E = RX_E;  dRY=dRX;
      Calc_flag = 1;
     }

    emit signal_updateISD();
    }

//=====================*******=====================
    void slot_point(){
     qDebug()<<"Button point pressed";

    Point_flag = 1;

    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_clear(){
     qDebug()<<"Button clear pressed";

    RX = 0; RX_E = 0;
    RY = 0; RY_E = 0;
    Point_flag = 0;
    Calc_flag = 0;

    emit signal_updateISD();
    }
//=====================*******=====================
    void slot_result(){
     qDebug()<<"Button result pressed";

    CalcResult();

    emit signal_updateISD();
    }
//=====================*******=====================
  void slotPrint()
    {
        qDebug()<<"CalcEngine";
    }
//=====================*******=====================
private:

   double  dRX = 0;
   double  dRY = 0;

   quint8  OP = 0;      //n
                        //1 +
                        //2 -
                        //3 *
                        //4 /

   quint64  RX = 0;  quint16 RX_E = 0;
   quint64  RY = 0;  quint16 RY_E = 0;

   bool Point_flag = 0;
   bool Calc_flag = 0;



 //  quint8  R1 = 0;



};

#endif // CALCENGINE_H
