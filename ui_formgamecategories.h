/********************************************************************************
** Form generated from reading UI file 'formgamecategories.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMGAMECATEGORIES_H
#define UI_FORMGAMECATEGORIES_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include "customwidgets/pandalistwidget.h"

QT_BEGIN_NAMESPACE

class Ui_FormGameCategories
{
public:
    QVBoxLayout *verticalLayout;
    PandaListWidget *m_listWidgetGameCategories;

    void setupUi(QWidget *FormGameCategories)
    {
        if (FormGameCategories->objectName().isEmpty())
            FormGameCategories->setObjectName(QStringLiteral("FormGameCategories"));
        FormGameCategories->resize(400, 300);
        verticalLayout = new QVBoxLayout(FormGameCategories);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_listWidgetGameCategories = new PandaListWidget(FormGameCategories);
        m_listWidgetGameCategories->setObjectName(QStringLiteral("m_listWidgetGameCategories"));
        m_listWidgetGameCategories->setFlow(QListView::LeftToRight);
        m_listWidgetGameCategories->setResizeMode(QListView::Adjust);
        m_listWidgetGameCategories->setViewMode(QListView::IconMode);

        verticalLayout->addWidget(m_listWidgetGameCategories);


        retranslateUi(FormGameCategories);

        QMetaObject::connectSlotsByName(FormGameCategories);
    } // setupUi

    void retranslateUi(QWidget *FormGameCategories)
    {
        FormGameCategories->setWindowTitle(QApplication::translate("FormGameCategories", "Form", 0));
    } // retranslateUi

};

namespace Ui {
    class FormGameCategories: public Ui_FormGameCategories {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMGAMECATEGORIES_H
