/********************************************************************************
** Form generated from reading UI file 'qgpiowidget.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QGPIOWIDGET_H
#define UI_QGPIOWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QGPIOWidget
{
public:

    void setupUi(QWidget *QGPIOWidget)
    {
        if (QGPIOWidget->objectName().isEmpty())
            QGPIOWidget->setObjectName(QStringLiteral("QGPIOWidget"));
        QGPIOWidget->resize(400, 300);

        retranslateUi(QGPIOWidget);

        QMetaObject::connectSlotsByName(QGPIOWidget);
    } // setupUi

    void retranslateUi(QWidget *QGPIOWidget)
    {
        QGPIOWidget->setWindowTitle(QApplication::translate("QGPIOWidget", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class QGPIOWidget: public Ui_QGPIOWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QGPIOWIDGET_H
