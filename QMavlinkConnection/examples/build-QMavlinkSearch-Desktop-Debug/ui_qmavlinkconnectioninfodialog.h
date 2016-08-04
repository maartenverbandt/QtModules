/********************************************************************************
** Form generated from reading UI file 'qmavlinkconnectioninfodialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMAVLINKCONNECTIONINFODIALOG_H
#define UI_QMAVLINKCONNECTIONINFODIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include "qcustomplot.h"

QT_BEGIN_NAMESPACE

class Ui_QMavlinkConnectionInfoDialog
{
public:
    QVBoxLayout *verticalLayout;
    QCustomPlot *barPlot;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *resetButton;
    QPushButton *closeButton;

    void setupUi(QDialog *QMavlinkConnectionInfoDialog)
    {
        if (QMavlinkConnectionInfoDialog->objectName().isEmpty())
            QMavlinkConnectionInfoDialog->setObjectName(QStringLiteral("QMavlinkConnectionInfoDialog"));
        QMavlinkConnectionInfoDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(QMavlinkConnectionInfoDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        barPlot = new QCustomPlot(QMavlinkConnectionInfoDialog);
        barPlot->setObjectName(QStringLiteral("barPlot"));

        verticalLayout->addWidget(barPlot);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        resetButton = new QPushButton(QMavlinkConnectionInfoDialog);
        resetButton->setObjectName(QStringLiteral("resetButton"));

        horizontalLayout->addWidget(resetButton);

        closeButton = new QPushButton(QMavlinkConnectionInfoDialog);
        closeButton->setObjectName(QStringLiteral("closeButton"));

        horizontalLayout->addWidget(closeButton);


        verticalLayout->addLayout(horizontalLayout);

        verticalLayout->setStretch(0, 1);

        retranslateUi(QMavlinkConnectionInfoDialog);

        QMetaObject::connectSlotsByName(QMavlinkConnectionInfoDialog);
    } // setupUi

    void retranslateUi(QDialog *QMavlinkConnectionInfoDialog)
    {
        QMavlinkConnectionInfoDialog->setWindowTitle(QApplication::translate("QMavlinkConnectionInfoDialog", "Dialog", 0));
        resetButton->setText(QApplication::translate("QMavlinkConnectionInfoDialog", "Reset", 0));
        closeButton->setText(QApplication::translate("QMavlinkConnectionInfoDialog", "Close", 0));
    } // retranslateUi

};

namespace Ui {
    class QMavlinkConnectionInfoDialog: public Ui_QMavlinkConnectionInfoDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMAVLINKCONNECTIONINFODIALOG_H
