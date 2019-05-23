/********************************************************************************
** Form generated from reading UI file 'dialogaddabonent.ui'
**
** Created by: Qt User Interface Compiler version 5.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOGADDABONENT_H
#define UI_DIALOGADDABONENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DialogAddAbonent
{
public:
    QDialogButtonBox *buttonBox;
    QWidget *widget;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QWidget *widget1;
    QVBoxLayout *verticalLayout_2;
    QLineEdit *lNameEdit;
    QLineEdit *fNameEdit;
    QLineEdit *phoneEdit;

    void setupUi(QDialog *DialogAddAbonent)
    {
        if (DialogAddAbonent->objectName().isEmpty())
            DialogAddAbonent->setObjectName(QStringLiteral("DialogAddAbonent"));
        DialogAddAbonent->resize(249, 150);
        buttonBox = new QDialogButtonBox(DialogAddAbonent);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(-100, 120, 341, 32));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        widget = new QWidget(DialogAddAbonent);
        widget->setObjectName(QStringLiteral("widget"));
        widget->setGeometry(QRect(10, 10, 61, 101));
        verticalLayout = new QVBoxLayout(widget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(widget);
        label->setObjectName(QStringLiteral("label"));

        verticalLayout->addWidget(label);

        label_2 = new QLabel(widget);
        label_2->setObjectName(QStringLiteral("label_2"));

        verticalLayout->addWidget(label_2);

        label_3 = new QLabel(widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout->addWidget(label_3);

        widget1 = new QWidget(DialogAddAbonent);
        widget1->setObjectName(QStringLiteral("widget1"));
        widget1->setGeometry(QRect(90, 10, 151, 101));
        verticalLayout_2 = new QVBoxLayout(widget1);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        verticalLayout_2->setContentsMargins(0, 0, 0, 0);
        lNameEdit = new QLineEdit(widget1);
        lNameEdit->setObjectName(QStringLiteral("lNameEdit"));

        verticalLayout_2->addWidget(lNameEdit);

        fNameEdit = new QLineEdit(widget1);
        fNameEdit->setObjectName(QStringLiteral("fNameEdit"));

        verticalLayout_2->addWidget(fNameEdit);

        phoneEdit = new QLineEdit(widget1);
        phoneEdit->setObjectName(QStringLiteral("phoneEdit"));

        verticalLayout_2->addWidget(phoneEdit);


        retranslateUi(DialogAddAbonent);
        QObject::connect(buttonBox, SIGNAL(accepted()), DialogAddAbonent, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), DialogAddAbonent, SLOT(reject()));

        QMetaObject::connectSlotsByName(DialogAddAbonent);
    } // setupUi

    void retranslateUi(QDialog *DialogAddAbonent)
    {
        DialogAddAbonent->setWindowTitle(QApplication::translate("DialogAddAbonent", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("DialogAddAbonent", "\320\244\320\260\320\274\320\270\320\273\320\270\321\217", Q_NULLPTR));
        label_2->setText(QApplication::translate("DialogAddAbonent", "\320\230\320\274\321\217", Q_NULLPTR));
        label_3->setText(QApplication::translate("DialogAddAbonent", "\320\242\320\265\320\273\320\265\321\204\320\276\320\275", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DialogAddAbonent: public Ui_DialogAddAbonent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOGADDABONENT_H
