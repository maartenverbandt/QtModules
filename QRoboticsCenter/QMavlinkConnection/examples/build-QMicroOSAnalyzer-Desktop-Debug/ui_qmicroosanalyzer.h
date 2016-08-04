/********************************************************************************
** Form generated from reading UI file 'qmicroosanalyzer.ui'
**
** Created by: Qt User Interface Compiler version 5.6.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QMICROOSANALYZER_H
#define UI_QMICROOSANALYZER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_QMicroOSAnalyzer
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QVBoxLayout *verticalLayout;
    QPushButton *searchButton;
    QComboBox *comboBox;
    QSpacerItem *verticalSpacer;
    QSpacerItem *horizontalSpacer;
    QVBoxLayout *verticalLayout_2;
    QPushButton *threadsButton;
    QPushButton *debugButton;
    QPushButton *messagesButton;
    QPushButton *loggerButton;
    QSpacerItem *verticalSpacer_2;
    QMenuBar *menuBar;

    void setupUi(QMainWindow *QMicroOSAnalyzer)
    {
        if (QMicroOSAnalyzer->objectName().isEmpty())
            QMicroOSAnalyzer->setObjectName(QStringLiteral("QMicroOSAnalyzer"));
        QMicroOSAnalyzer->resize(250, 139);
        QSizePolicy sizePolicy(QSizePolicy::Minimum, QSizePolicy::Minimum);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(QMicroOSAnalyzer->sizePolicy().hasHeightForWidth());
        QMicroOSAnalyzer->setSizePolicy(sizePolicy);
        centralWidget = new QWidget(QMicroOSAnalyzer);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        sizePolicy.setHeightForWidth(centralWidget->sizePolicy().hasHeightForWidth());
        centralWidget->setSizePolicy(sizePolicy);
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(2);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalLayout->setContentsMargins(2, 2, 2, 2);
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        searchButton = new QPushButton(centralWidget);
        searchButton->setObjectName(QStringLiteral("searchButton"));

        verticalLayout->addWidget(searchButton);

        comboBox = new QComboBox(centralWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));

        verticalLayout->addWidget(comboBox);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Ignored);

        verticalLayout->addItem(verticalSpacer);

        verticalLayout->setStretch(2, 1);

        horizontalLayout->addLayout(verticalLayout);

        horizontalSpacer = new QSpacerItem(20, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(0);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMinimumSize);
        threadsButton = new QPushButton(centralWidget);
        threadsButton->setObjectName(QStringLiteral("threadsButton"));

        verticalLayout_2->addWidget(threadsButton);

        debugButton = new QPushButton(centralWidget);
        debugButton->setObjectName(QStringLiteral("debugButton"));

        verticalLayout_2->addWidget(debugButton);

        messagesButton = new QPushButton(centralWidget);
        messagesButton->setObjectName(QStringLiteral("messagesButton"));

        verticalLayout_2->addWidget(messagesButton);

        loggerButton = new QPushButton(centralWidget);
        loggerButton->setObjectName(QStringLiteral("loggerButton"));

        verticalLayout_2->addWidget(loggerButton);

        verticalSpacer_2 = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Ignored);

        verticalLayout_2->addItem(verticalSpacer_2);

        verticalLayout_2->setStretch(4, 1);

        horizontalLayout->addLayout(verticalLayout_2);

        horizontalLayout->setStretch(0, 1);
        QMicroOSAnalyzer->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(QMicroOSAnalyzer);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 250, 25));
        QMicroOSAnalyzer->setMenuBar(menuBar);

        retranslateUi(QMicroOSAnalyzer);

        QMetaObject::connectSlotsByName(QMicroOSAnalyzer);
    } // setupUi

    void retranslateUi(QMainWindow *QMicroOSAnalyzer)
    {
        QMicroOSAnalyzer->setWindowTitle(QApplication::translate("QMicroOSAnalyzer", "QMicroOSAnalyzer", 0));
        searchButton->setText(QApplication::translate("QMicroOSAnalyzer", "Search", 0));
        threadsButton->setText(QApplication::translate("QMicroOSAnalyzer", "Threads", 0));
        debugButton->setText(QApplication::translate("QMicroOSAnalyzer", "Debug", 0));
        messagesButton->setText(QApplication::translate("QMicroOSAnalyzer", "Messages", 0));
        loggerButton->setText(QApplication::translate("QMicroOSAnalyzer", "Logger", 0));
    } // retranslateUi

};

namespace Ui {
    class QMicroOSAnalyzer: public Ui_QMicroOSAnalyzer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QMICROOSANALYZER_H
