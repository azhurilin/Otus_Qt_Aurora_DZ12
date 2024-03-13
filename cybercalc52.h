#ifndef CYBERCALC52_H
#define CYBERCALC52_H

#include "calcengine.h"
#include <QDialog>
#include <QDebug>




QT_BEGIN_NAMESPACE
namespace Ui { class CyberCalc52; }
QT_END_NAMESPACE



class CyberCalc52 : public QDialog
{
    Q_OBJECT

public:
    CyberCalc52(QWidget *parent = nullptr);


    void CalcGeometry(qint8 BSize);

    ~CyberCalc52();

    void setEngine(CalcEngine *E);





public slots:


    void slot_updateISD();

//=====================*******=====================


  void slotPrint()
    {
        qDebug()<<"CyberCalc52";
    }
//=====================*******=====================


private:

    CalcEngine *CEngine;

    Ui::CyberCalc52 *ui;

};
#endif // CYBERCALC52_H
