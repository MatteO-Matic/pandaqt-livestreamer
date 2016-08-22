/********************************************************************************
** Form generated from reading UI file 'formchannels.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMCHANNELS_H
#define UI_FORMCHANNELS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customwidgets/imagebutton.h"
#include "customwidgets/pandalistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_FormChannels
{
public:
    QVBoxLayout *verticalLayout_2;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    ImageButton *m_buttonRefresh;
    QSpacerItem *horizontalSpacer;
    PandaListWidget *m_listChannels;

    void setupUi(QWidget *FormChannels)
    {
        if (FormChannels->objectName().isEmpty())
            FormChannels->setObjectName(QStringLiteral("FormChannels"));
        FormChannels->resize(400, 300);
        verticalLayout_2 = new QVBoxLayout(FormChannels);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(5);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setSizeConstraint(QLayout::SetDefaultConstraint);
        m_buttonRefresh = new ImageButton(FormChannels);
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

        m_listChannels = new PandaListWidget(FormChannels);
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


        verticalLayout_2->addLayout(verticalLayout);


        retranslateUi(FormChannels);

        QMetaObject::connectSlotsByName(FormChannels);
    } // setupUi

    void retranslateUi(QWidget *FormChannels)
    {
        FormChannels->setWindowTitle(QApplication::translate("FormChannels", "Form", 0));
        m_buttonRefresh->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class FormChannels: public Ui_FormChannels {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMCHANNELS_H
