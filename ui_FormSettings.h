/********************************************************************************
** Form generated from reading UI file 'FormSettings.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORMSETTINGS_H
#define UI_FORMSETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_FormSettings
{
public:
    QVBoxLayout *verticalLayout;
    QLabel *m_labelLivestreamerCommands;
    QTextEdit *m_textboxFullLivestreamerCommand;
    QLabel *m_labelAddBookmark;
    QTextEdit *m_textboxAddBookmark;
    QPushButton *m_buttonAddBookmark;
    QCheckBox *m_checkboxMinimizeToTray;
    QSpacerItem *verticalSpacer;

    void setupUi(QWidget *FormSettings)
    {
        if (FormSettings->objectName().isEmpty())
            FormSettings->setObjectName(QStringLiteral("FormSettings"));
        FormSettings->resize(400, 300);
        verticalLayout = new QVBoxLayout(FormSettings);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        m_labelLivestreamerCommands = new QLabel(FormSettings);
        m_labelLivestreamerCommands->setObjectName(QStringLiteral("m_labelLivestreamerCommands"));

        verticalLayout->addWidget(m_labelLivestreamerCommands);

        m_textboxFullLivestreamerCommand = new QTextEdit(FormSettings);
        m_textboxFullLivestreamerCommand->setObjectName(QStringLiteral("m_textboxFullLivestreamerCommand"));
        QSizePolicy sizePolicy(QSizePolicy::Expanding, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(m_textboxFullLivestreamerCommand->sizePolicy().hasHeightForWidth());
        m_textboxFullLivestreamerCommand->setSizePolicy(sizePolicy);
        m_textboxFullLivestreamerCommand->setMinimumSize(QSize(0, 25));
        m_textboxFullLivestreamerCommand->setMaximumSize(QSize(16777215, 25));
        m_textboxFullLivestreamerCommand->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(m_textboxFullLivestreamerCommand);

        m_labelAddBookmark = new QLabel(FormSettings);
        m_labelAddBookmark->setObjectName(QStringLiteral("m_labelAddBookmark"));

        verticalLayout->addWidget(m_labelAddBookmark);

        m_textboxAddBookmark = new QTextEdit(FormSettings);
        m_textboxAddBookmark->setObjectName(QStringLiteral("m_textboxAddBookmark"));
        sizePolicy.setHeightForWidth(m_textboxAddBookmark->sizePolicy().hasHeightForWidth());
        m_textboxAddBookmark->setSizePolicy(sizePolicy);
        m_textboxAddBookmark->setMinimumSize(QSize(0, 25));
        m_textboxAddBookmark->setMaximumSize(QSize(16777215, 25));
        m_textboxAddBookmark->setVerticalScrollBarPolicy(Qt::ScrollBarAlwaysOff);

        verticalLayout->addWidget(m_textboxAddBookmark);

        m_buttonAddBookmark = new QPushButton(FormSettings);
        m_buttonAddBookmark->setObjectName(QStringLiteral("m_buttonAddBookmark"));

        verticalLayout->addWidget(m_buttonAddBookmark);

        m_checkboxMinimizeToTray = new QCheckBox(FormSettings);
        m_checkboxMinimizeToTray->setObjectName(QStringLiteral("m_checkboxMinimizeToTray"));

        verticalLayout->addWidget(m_checkboxMinimizeToTray);

        verticalSpacer = new QSpacerItem(20, 226, QSizePolicy::Minimum, QSizePolicy::Expanding);

        verticalLayout->addItem(verticalSpacer);


        retranslateUi(FormSettings);

        QMetaObject::connectSlotsByName(FormSettings);
    } // setupUi

    void retranslateUi(QWidget *FormSettings)
    {
        FormSettings->setWindowTitle(QApplication::translate("FormSettings", "Form", 0));
        m_labelLivestreamerCommands->setText(QApplication::translate("FormSettings", "Livestreamer commands", 0));
        m_labelAddBookmark->setText(QApplication::translate("FormSettings", "Add bookmark by link", 0));
        m_textboxAddBookmark->setPlaceholderText(QApplication::translate("FormSettings", "http://www.panda.tv/1234", 0));
        m_buttonAddBookmark->setText(QApplication::translate("FormSettings", "Add bookmark", 0));
        m_checkboxMinimizeToTray->setText(QApplication::translate("FormSettings", "Minimize to tray", 0));
    } // retranslateUi

};

namespace Ui {
    class FormSettings: public Ui_FormSettings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORMSETTINGS_H
