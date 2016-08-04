/********************************************************************************
** Form generated from reading UI file 'qloggerdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QLOGGERDIALOG_H
#define UI_QLOGGERDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QLoggerDialog
{
public:
    QVBoxLayout *verticalLayout;
    QPushButton *recordButton;

    void setupUi(QDialog *QLoggerDialog)
    {
        if (QLoggerDialog->objectName().isEmpty())
            QLoggerDialog->setObjectName(QStringLiteral("QLoggerDialog"));
        QLoggerDialog->resize(150, 80);
        verticalLayout = new QVBoxLayout(QLoggerDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        recordButton = new QPushButton(QLoggerDialog);
        recordButton->setObjectName(QStringLiteral("recordButton"));
        recordButton->setCheckable(true);

        verticalLayout->addWidget(recordButton);


        retranslateUi(QLoggerDialog);

        QMetaObject::connectSlotsByName(QLoggerDialog);
    } // setupUi

    void retranslateUi(QDialog *QLoggerDialog)
    {
        QLoggerDialog->setWindowTitle(QApplication::translate("QLoggerDialog", "Dialog", 0));
        recordButton->setText(QApplication::translate("QLoggerDialog", "Record", 0));
    } // retranslateUi

};

namespace Ui {
    class QLoggerDialog: public Ui_QLoggerDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QLOGGERDIALOG_H
