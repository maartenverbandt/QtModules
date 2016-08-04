/********************************************************************************
** Form generated from reading UI file 'ballbotdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BALLBOTDIALOG_H
#define UI_BALLBOTDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_BallbotDialog
{
public:
    QGroupBox *control_groupBox;
    QHBoxLayout *horizontalLayout;
    QPushButton *no_control_pushButton;
    QPushButton *attituce_control_pushButton;
    QPushButton *console_control_pushButton;
    QPushButton *position_control_pushButton;

    void setupUi(QDialog *BallbotDialog)
    {
        if (BallbotDialog->objectName().isEmpty())
            BallbotDialog->setObjectName(QStringLiteral("BallbotDialog"));
        BallbotDialog->resize(400, 300);
        control_groupBox = new QGroupBox(BallbotDialog);
        control_groupBox->setObjectName(QStringLiteral("control_groupBox"));
        control_groupBox->setGeometry(QRect(0, -10, 291, 61));
        control_groupBox->setAlignment(Qt::AlignCenter);
        horizontalLayout = new QHBoxLayout(control_groupBox);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        no_control_pushButton = new QPushButton(control_groupBox);
        no_control_pushButton->setObjectName(QStringLiteral("no_control_pushButton"));
        QIcon icon;
        icon.addFile(QStringLiteral("../../../icons/control_none.png"), QSize(), QIcon::Normal, QIcon::Off);
        no_control_pushButton->setIcon(icon);
        no_control_pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(no_control_pushButton);

        attituce_control_pushButton = new QPushButton(control_groupBox);
        attituce_control_pushButton->setObjectName(QStringLiteral("attituce_control_pushButton"));
        QIcon icon1;
        icon1.addFile(QStringLiteral("../../../icons/control_attitude.png"), QSize(), QIcon::Normal, QIcon::Off);
        attituce_control_pushButton->setIcon(icon1);
        attituce_control_pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(attituce_control_pushButton);

        console_control_pushButton = new QPushButton(control_groupBox);
        console_control_pushButton->setObjectName(QStringLiteral("console_control_pushButton"));
        QIcon icon2;
        icon2.addFile(QStringLiteral("../../../icons/control_console.png"), QSize(), QIcon::Normal, QIcon::Off);
        console_control_pushButton->setIcon(icon2);
        console_control_pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(console_control_pushButton);

        position_control_pushButton = new QPushButton(control_groupBox);
        position_control_pushButton->setObjectName(QStringLiteral("position_control_pushButton"));
        position_control_pushButton->setIconSize(QSize(32, 32));

        horizontalLayout->addWidget(position_control_pushButton);


        retranslateUi(BallbotDialog);

        QMetaObject::connectSlotsByName(BallbotDialog);
    } // setupUi

    void retranslateUi(QDialog *BallbotDialog)
    {
        BallbotDialog->setWindowTitle(QApplication::translate("BallbotDialog", "Dialog", 0));
        control_groupBox->setTitle(QString());
        no_control_pushButton->setText(QString());
        attituce_control_pushButton->setText(QString());
        console_control_pushButton->setText(QString());
        position_control_pushButton->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class BallbotDialog: public Ui_BallbotDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BALLBOTDIALOG_H
