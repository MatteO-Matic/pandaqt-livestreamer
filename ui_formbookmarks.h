/********************************************************************************
** Form generated from reading UI file 'formbookmarks.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMBOOKMARKS_H
#define UI_FORMBOOKMARKS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QListWidget>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customwidgets/imagebutton.h"

QT_BEGIN_NAMESPACE

class Ui_FormBookmarks
{
public:
    QHBoxLayout *horizontalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    ImageButton *m_buttonRefresh_Bookmarks;
    QSpacerItem *horizontalSpacer_2;
    QListWidget *m_listBookmarksWidget;

    void setupUi(QWidget *FormBookmarks)
    {
        if (FormBookmarks->objectName().isEmpty())
            FormBookmarks->setObjectName(QStringLiteral("FormBookmarks"));
        FormBookmarks->resize(400, 300);
        horizontalLayout_2 = new QHBoxLayout(FormBookmarks);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        m_buttonRefresh_Bookmarks = new ImageButton(FormBookmarks);
        m_buttonRefresh_Bookmarks->setObjectName(QStringLiteral("m_buttonRefresh_Bookmarks"));
        QSizePolicy sizePolicy(QSizePolicy::Fixed, QSizePolicy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_buttonRefresh_Bookmarks->sizePolicy().hasHeightForWidth());
        m_buttonRefresh_Bookmarks->setSizePolicy(sizePolicy);
        m_buttonRefresh_Bookmarks->setMaximumSize(QSize(16, 16));
        m_buttonRefresh_Bookmarks->setPixmap(QPixmap(QString::fromUtf8(":/images/icon_refresh.png")));
        m_buttonRefresh_Bookmarks->setScaledContents(true);

        horizontalLayout->addWidget(m_buttonRefresh_Bookmarks);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer_2);


        verticalLayout->addLayout(horizontalLayout);

        m_listBookmarksWidget = new QListWidget(FormBookmarks);
        m_listBookmarksWidget->setObjectName(QStringLiteral("m_listBookmarksWidget"));
        QSizePolicy sizePolicy1(QSizePolicy::Expanding, QSizePolicy::Expanding);
        sizePolicy1.setHorizontalStretch(0);
        sizePolicy1.setVerticalStretch(0);
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

        verticalLayout->addWidget(m_listBookmarksWidget);


        horizontalLayout_2->addLayout(verticalLayout);


        retranslateUi(FormBookmarks);

        QMetaObject::connectSlotsByName(FormBookmarks);
    } // setupUi

    void retranslateUi(QWidget *FormBookmarks)
    {
        FormBookmarks->setWindowTitle(QApplication::translate("FormBookmarks", "Form", 0));
        m_buttonRefresh_Bookmarks->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormBookmarks: public Ui_FormBookmarks {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMBOOKMARKS_H
