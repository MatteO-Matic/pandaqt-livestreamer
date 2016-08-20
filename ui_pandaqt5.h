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
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customwidgets/imagebutton.h"
#include "customwidgets/pandalistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_Pandaqt5
{
public:
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QWidget *widget;
    QVBoxLayout *verticalLayout_2;
    QLabel *m_logo;
    QPushButton *pushButton_4;
    QPushButton *pushButton_3;
    QPushButton *m_buttonBookmarks;
    QPushButton *m_buttonSettings;
    QTabWidget *tabWidget;
    QWidget *tab;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    ImageButton *m_buttonRefresh;
    QSpacerItem *horizontalSpacer;
    PandaListWidget *m_listChannels;
    QWidget *m_tabBookmarks;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_3;
    ImageButton *m_buttonRefresh_Bookmarks;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *m_listBookmarksWidget;

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

        pushButton_4 = new QPushButton(widget);
        pushButton_4->setObjectName(QStringLiteral("pushButton_4"));
        pushButton_4->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton_4);

        pushButton_3 = new QPushButton(widget);
        pushButton_3->setObjectName(QStringLiteral("pushButton_3"));
        pushButton_3->setStyleSheet(QStringLiteral("background-color: rgba(255, 255, 255, 255);"));

        verticalLayout_2->addWidget(pushButton_3);

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
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        verticalLayout = new QVBoxLayout(tab);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        m_buttonRefresh = new ImageButton(tab);
        m_buttonRefresh->setObjectName(QStringLiteral("m_buttonRefresh"));
        m_buttonRefresh->setEnabled(true);
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_buttonRefresh->sizePolicy().hasHeightForWidth());
        m_buttonRefresh->setSizePolicy(sizePolicy);
        m_buttonRefresh->setMaximumSize(QSize(16, 16));
        m_buttonRefresh->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_refresh.png")));
        m_buttonRefresh->setScaledContents(true);
        m_buttonRefresh->setMargin(0);

        horizontalLayout_2->addWidget(m_buttonRefresh);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout->addLayout(horizontalLayout_2);

        m_listChannels = new PandaListWidget(tab);
        m_listChannels->setObjectName(QStringLiteral("m_listChannels"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
        sizePolicy1.setHeightForWidth(m_listChannels->sizePolicy().hasHeightForWidth());
        m_listChannels->setSizePolicy(sizePolicy1);
        m_listChannels->setDragEnabled(false);
        m_listChannels->setDragDropMode(QAbstractItemView::NoDragDrop);
        m_listChannels->setSelectionMode(QAbstractItemView::NoSelection);
        m_listChannels->setMovement(QListView::Static);
        m_listChannels->setResizeMode(QListView::Adjust);
        m_listChannels->setViewMode(QListView::IconMode);

        verticalLayout->addWidget(m_listChannels);

        tabWidget->addTab(tab, QString());
        m_tabBookmarks = new QWidget();
        m_tabBookmarks->setObjectName(QStringLiteral("m_tabBookmarks"));
        verticalLayout_3 = new QVBoxLayout(m_tabBookmarks);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(5);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        horizontalLayout_3->setSizeConstraint(QLayout::SetDefaultConstraint);
        m_buttonRefresh_Bookmarks = new ImageButton(m_tabBookmarks);
        m_buttonRefresh_Bookmarks->setObjectName(QStringLiteral("m_buttonRefresh_Bookmarks"));
        sizePolicy.setHeightForWidth(m_buttonRefresh_Bookmarks->sizePolicy().hasHeightForWidth());
        m_buttonRefresh_Bookmarks->setSizePolicy(sizePolicy);
        m_buttonRefresh_Bookmarks->setMaximumSize(QSize(16, 16));
        m_buttonRefresh_Bookmarks->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_refresh.png")));
        m_buttonRefresh_Bookmarks->setScaledContents(true);

        horizontalLayout_3->addWidget(m_buttonRefresh_Bookmarks);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_3->addItem(horizontalSpacer_2);


        verticalLayout_3->addLayout(horizontalLayout_3);

        m_listBookmarksWidget = new QListWidget(m_tabBookmarks);
        m_listBookmarksWidget->setObjectName(QStringLiteral("m_listBookmarksWidget"));
        sizePolicy1.setHeightForWidth(m_listBookmarksWidget->sizePolicy().hasHeightForWidth());
        m_listBookmarksWidget->setSizePolicy(sizePolicy1);
        m_listBookmarksWidget->setTabKeyNavigation(false);
        m_listBookmarksWidget->setAlternatingRowColors(false);
        m_listBookmarksWidget->setSelectionMode(QAbstractItemView::NoSelection);
        m_listBookmarksWidget->setIconSize(QSize(0, 0));
        m_listBookmarksWidget->setMovement(QListView::Static);
        m_listBookmarksWidget->setFlow(QListView::LeftToRight);
        m_listBookmarksWidget->setProperty("isWrapping", QVariant(true));
        m_listBookmarksWidget->setResizeMode(QListView::Adjust);
        m_listBookmarksWidget->setViewMode(QListView::IconMode);
        m_listBookmarksWidget->setModelColumn(0);
        m_listBookmarksWidget->setUniformItemSizes(true);
        m_listBookmarksWidget->setSelectionRectVisible(true);

        verticalLayout_3->addWidget(m_listBookmarksWidget);

        tabWidget->addTab(m_tabBookmarks, QString());

        gridLayout->addWidget(tabWidget, 0, 1, 1, 1);

        Pandaqt5->setCentralWidget(centralWidget);

        retranslateUi(Pandaqt5);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Pandaqt5);
    } // setupUi

    void retranslateUi(QMainWindow *Pandaqt5)
    {
        Pandaqt5->setWindowTitle(QApplication::translate("Pandaqt5", "Pandaqt5", 0));
        m_logo->setText(QString());
        pushButton_4->setText(QApplication::translate("Pandaqt5", "Channels", 0));
        pushButton_3->setText(QApplication::translate("Pandaqt5", "Games", 0));
        m_buttonBookmarks->setText(QApplication::translate("Pandaqt5", "Bookmarks", 0));
        m_buttonSettings->setText(QApplication::translate("Pandaqt5", "Settings", 0));
        m_buttonRefresh->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("Pandaqt5", "Channels", 0));
        m_buttonRefresh_Bookmarks->setText(QString());
        tabWidget->setTabText(tabWidget->indexOf(m_tabBookmarks), QApplication::translate("Pandaqt5", "Bookmarks", 0));
    } // retranslateUi

};

namespace Ui {
    class Pandaqt5: public Ui_Pandaqt5 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PANDAQT5_H
