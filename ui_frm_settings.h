/********************************************************************************
** Form generated from reading UI file 'frm_settings.ui'
**
** Created by: Qt User Interface Compiler version 5.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FRM_SETTINGS_H
#define UI_FRM_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_frm_settings
{
public:
    QVBoxLayout *verticalLayout;
    QTextEdit *m_textboxFullLivestreamerCommand;
    QCheckBox *m_checkboxMinimizeToTray;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *frm_settings)
    {
        if (frm_settings->objectName().isEmpty())
            frm_settings->setObjectName(QStringLiteral("frm_settings"));
        frm_settings->resize(400, 300);
        verticalLayout = new QVBoxLayout(frm_settings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_textboxFullLivestreamerCommand = new QTextEdit(frm_settings);
        m_textboxFullLivestreamerCommand->setObjectName(QStringLiteral("m_textboxFullLivestreamerCommand"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_textboxFullLivestreamerCommand->sizePolicy().hasHeightForWidth());
        m_textboxFullLivestreamerCommand->setSizePolicy(sizePolicy);
        m_textboxFullLivestreamerCommand->setMinimumSize(QSize(0, 21));
        m_textboxFullLivestreamerCommand->setMaximumSize(QSize(16777215, 21));
        m_textboxFullLivestreamerCommand->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(m_textboxFullLivestreamerCommand);

        m_checkboxMinimizeToTray = new QCheckBox(frm_settings);
        m_checkboxMinimizeToTray->setObjectName(QStringLiteral("m_checkboxMinimizeToTray"));

        verticalLayout->addWidget(m_checkboxMinimizeToTray);

        verticalSpacer = new QSpacerItem(20, 226, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(frm_settings);

        QMetaObject::connectSlotsByName(frm_settings);
    } // setupUi

    void retranslateUi(QWidget *frm_settings)
    {
        frm_settings->setWindowTitle(QApplication::translate("frm_settings", "Form", 0));
        m_checkboxMinimizeToTray->setText(QApplication::translate("frm_settings", "Minimize to tray", 0));
    } // retranslateUi

};

namespace Ui {
    class frm_settings: public Ui_frm_settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FRM_SETTINGS_H
