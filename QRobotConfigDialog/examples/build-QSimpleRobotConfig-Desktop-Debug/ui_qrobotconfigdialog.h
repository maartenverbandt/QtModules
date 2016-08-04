/********************************************************************************
** Form generated from reading UI file 'qrobotconfigdialog.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QROBOTCONFIGDIALOG_H
#define UI_QROBOTCONFIGDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QVBoxLayout>

QT_BEGIN_NAMESPACE

class Ui_QRobotConfigDialog
{
public:
    QVBoxLayout *verticalLayout;
    QTreeWidget *treeWidget;
    QHBoxLayout *horizontalLayout;
    QPushButton *open_pushButton;
    QPushButton *save_pushButton;
    QSpacerItem *horizontalSpacer;
    QPushButton *load_pushButton;
    QPushButton *send_pushButton;

    void setupUi(QDialog *QRobotConfigDialog)
    {
        if (QRobotConfigDialog->objectName().isEmpty())
            QRobotConfigDialog->setObjectName(QStringLiteral("QRobotConfigDialog"));
        QRobotConfigDialog->resize(400, 300);
        verticalLayout = new QVBoxLayout(QRobotConfigDialog);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        treeWidget = new QTreeWidget(QRobotConfigDialog);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(1, QStringLiteral("2"));
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        treeWidget->setFrameShape(QFrame::StyledPanel);
        treeWidget->setFrameShadow(QFrame::Sunken);
        treeWidget->setColumnCount(2);
        treeWidget->header()->setDefaultSectionSize(200);

        verticalLayout->addWidget(treeWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        open_pushButton = new QPushButton(QRobotConfigDialog);
        open_pushButton->setObjectName(QStringLiteral("open_pushButton"));

        horizontalLayout->addWidget(open_pushButton);

        save_pushButton = new QPushButton(QRobotConfigDialog);
        save_pushButton->setObjectName(QStringLiteral("save_pushButton"));

        horizontalLayout->addWidget(save_pushButton);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        load_pushButton = new QPushButton(QRobotConfigDialog);
        load_pushButton->setObjectName(QStringLiteral("load_pushButton"));

        horizontalLayout->addWidget(load_pushButton);

        send_pushButton = new QPushButton(QRobotConfigDialog);
        send_pushButton->setObjectName(QStringLiteral("send_pushButton"));

        horizontalLayout->addWidget(send_pushButton);


        verticalLayout->addLayout(horizontalLayout);


        retranslateUi(QRobotConfigDialog);

        QMetaObject::connectSlotsByName(QRobotConfigDialog);
    } // setupUi

    void retranslateUi(QDialog *QRobotConfigDialog)
    {
        QRobotConfigDialog->setWindowTitle(QApplication::translate("QRobotConfigDialog", "Dialog", 0));
        open_pushButton->setText(QApplication::translate("QRobotConfigDialog", "open", 0));
        save_pushButton->setText(QApplication::translate("QRobotConfigDialog", "save", 0));
        load_pushButton->setText(QApplication::translate("QRobotConfigDialog", "load", 0));
        send_pushButton->setText(QApplication::translate("QRobotConfigDialog", "send", 0));
    } // retranslateUi

};

namespace Ui {
    class QRobotConfigDialog: public Ui_QRobotConfigDialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QROBOTCONFIGDIALOG_H
