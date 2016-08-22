/********************************************************************************
** Form generated from reading UI file 'pandaqt5.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PANDAQT5_H
#define UI_PANDAQT5_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Pandaqt5
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_logo;
    QPushButton *m_buttonChannels;
    QPushButton *m_buttonGameCategories;
    QPushButton *m_buttonBookmarks;
    QPushButton *m_buttonSettings;
    QTabWidget *tabWidget;

    void setupUi(QMainWindow *Pandaqt5)
    {
        if (Pandaqt5->objectName().isEmpty())
            Pandaqt5->setObjectName(QStringLiteral("Pandaqt5"));
        Pandaqt5->resize(956, 520);
        Pandaqt5->setStyleSheet(QStringLiteral(""));
        centralWidget = new QWidget(Pandaqt5);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        centralWidget->setEnabled(true);
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(5);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        gridLayout->setContentsMargins(5, 5, 5, 5);
        widget = new QWidget(centralWidget);
        widget->setObjectName(QStringLiteral("widget"));
        verticalLayout_2 = new QVBoxLayout(widget);
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setContentsMargins(11, 11, 11, 11);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        m_logo = new QLabel(widget);
        m_logo->setObjectName(QStringLiteral("m_logo"));
        m_logo->setPixmap(QPixmap(QString::fromUtf8(":/icon.png")));

        verticalLayout_2->addWidget(m_logo);

        m_buttonChannels = new QPushButton(widget);
        m_buttonChannels->setObjectName(QStringLiteral("m_buttonChannels"));
        m_buttonChannels->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));

        verticalLayout_2->addWidget(m_buttonChannels);

        m_buttonGameCategories = new QPushButton(widget);
        m_buttonGameCategories->setObjectName(QStringLiteral("m_buttonGameCategories"));
        m_buttonGameCategories->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));

        verticalLayout_2->addWidget(m_buttonGameCategories);

        m_buttonBookmarks = new QPushButton(widget);
        m_buttonBookmarks->setObjectName(QStringLiteral("m_buttonBookmarks"));
        m_buttonBookmarks->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));

        verticalLayout_2->addWidget(m_buttonBookmarks);

        m_buttonSettings = new QPushButton(widget);
        m_buttonSettings->setObjectName(QStringLiteral("m_buttonSettings"));
        m_buttonSettings->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));

        verticalLayout_2->addWidget(m_buttonSettings);


        gridLayout->addWidget(widget, 0, 0, 1, 1, Qt::AlignTop);

        tabWidget = new QTabWidget(centralWidget);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tabWidget->setIconSize(QSize(0, 0));
        tabWidget->setUsesScrollButtons(false);
        tabWidget->setDocumentMode(true);
        tabWidget->setTabsClosable(false);
        tabWidget->setTabBarAutoHide(false);

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        Pandaqt5->setCentralWidget(centralWidget);

        retranslateUi(Pandaqt5);

        tabWidget->setCurrentIndex(-1);


        QMetaObject::connectSlotsByName(Pandaqt5);
    } // setupUi

    void retranslateUi(QMainWindow *Pandaqt5)
    {
        Pandaqt5->setWindowTitle(QApplication::translate("Pandaqt5", "Pandaqt5", 0));
        m_logo->setText(QString());
        m_buttonChannels->setText(QApplication::translate("Pandaqt5", "Channels", 0));
        m_buttonGameCategories->setText(QApplication::translate("Pandaqt5", "Games", 0));
        m_buttonBookmarks->setText(QApplication::translate("Pandaqt5", "Bookmarks", 0));
        m_buttonSettings->setText(QApplication::translate("Pandaqt5", "Settings", 0));
    } // retranslateUi

};

namespace Ui {
    class Pandaqt5: public Ui_Pandaqt5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANDAQT5_H
