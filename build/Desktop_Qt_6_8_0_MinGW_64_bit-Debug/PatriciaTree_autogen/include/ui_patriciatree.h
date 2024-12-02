/********************************************************************************
** Form generated from reading UI file 'patriciatree.ui'
**
** Created by: Qt User Interface Compiler version 6.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PATRICIATREE_H
#define UI_PATRICIATREE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_PatriciaTree
{
public:
    QWidget *centralwidget;
    QLabel *labelInsert;
    QLabel *labelSearch;
    QLabel *labelDelete;
    QLineEdit *txtInsert;
    QLineEdit *txtSearch;
    QLineEdit *txtDelete;
    QPushButton *ButtonInsert;
    QPushButton *ButtonSearch;
    QPushButton *ButtonDelete;
    QGraphicsView *graphicsView;
    QLabel *label;
    QLabel *members;
    QLabel *members_2;
    QLabel *members_3;
    QLabel *members_4;
    QLabel *labelInsert_2;
    QPushButton *ButtonFindAll;
    QLabel *labelDelete_2;
    QPushButton *ButtonFindRoot;
    QLabel *label_2;
    QPushButton *ButtonVaciar;
    QLabel *label_3;
    QLineEdit *txtAlf1;
    QLineEdit *txtAlf2;
    QPushButton *ButtonAlf;

    void setupUi(QMainWindow *PatriciaTree)
    {
        if (PatriciaTree->objectName().isEmpty())
            PatriciaTree->setObjectName("PatriciaTree");
        PatriciaTree->resize(1280, 1024);
        centralwidget = new QWidget(PatriciaTree);
        centralwidget->setObjectName("centralwidget");
        labelInsert = new QLabel(centralwidget);
        labelInsert->setObjectName("labelInsert");
        labelInsert->setGeometry(QRect(20, 30, 81, 21));
        QFont font;
        font.setFamilies({QString::fromUtf8("Arial")});
        font.setPointSize(12);
        labelInsert->setFont(font);
        labelSearch = new QLabel(centralwidget);
        labelSearch->setObjectName("labelSearch");
        labelSearch->setGeometry(QRect(20, 70, 81, 21));
        labelSearch->setFont(font);
        labelDelete = new QLabel(centralwidget);
        labelDelete->setObjectName("labelDelete");
        labelDelete->setGeometry(QRect(20, 110, 81, 21));
        labelDelete->setFont(font);
        txtInsert = new QLineEdit(centralwidget);
        txtInsert->setObjectName("txtInsert");
        txtInsert->setGeometry(QRect(90, 30, 113, 24));
        txtSearch = new QLineEdit(centralwidget);
        txtSearch->setObjectName("txtSearch");
        txtSearch->setGeometry(QRect(90, 70, 113, 24));
        txtDelete = new QLineEdit(centralwidget);
        txtDelete->setObjectName("txtDelete");
        txtDelete->setGeometry(QRect(90, 110, 113, 24));
        ButtonInsert = new QPushButton(centralwidget);
        ButtonInsert->setObjectName("ButtonInsert");
        ButtonInsert->setGeometry(QRect(220, 30, 80, 24));
        ButtonSearch = new QPushButton(centralwidget);
        ButtonSearch->setObjectName("ButtonSearch");
        ButtonSearch->setGeometry(QRect(220, 70, 80, 24));
        ButtonDelete = new QPushButton(centralwidget);
        ButtonDelete->setObjectName("ButtonDelete");
        ButtonDelete->setGeometry(QRect(220, 110, 80, 24));
        graphicsView = new QGraphicsView(centralwidget);
        graphicsView->setObjectName("graphicsView");
        graphicsView->setGeometry(QRect(60, 260, 1151, 711));
        label = new QLabel(centralwidget);
        label->setObjectName("label");
        label->setGeometry(QRect(420, 40, 471, 61));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Arial")});
        font1.setPointSize(26);
        font1.setBold(true);
        label->setFont(font1);
        members = new QLabel(centralwidget);
        members->setObjectName("members");
        members->setGeometry(QRect(1010, 40, 171, 31));
        QFont font2;
        font2.setFamilies({QString::fromUtf8("Arial")});
        font2.setPointSize(14);
        members->setFont(font2);
        members_2 = new QLabel(centralwidget);
        members_2->setObjectName("members_2");
        members_2->setGeometry(QRect(1010, 70, 171, 31));
        members_2->setFont(font2);
        members_3 = new QLabel(centralwidget);
        members_3->setObjectName("members_3");
        members_3->setGeometry(QRect(1010, 100, 171, 31));
        members_3->setFont(font2);
        members_4 = new QLabel(centralwidget);
        members_4->setObjectName("members_4");
        members_4->setGeometry(QRect(1010, 130, 171, 31));
        members_4->setFont(font2);
        labelInsert_2 = new QLabel(centralwidget);
        labelInsert_2->setObjectName("labelInsert_2");
        labelInsert_2->setGeometry(QRect(20, 150, 201, 21));
        labelInsert_2->setFont(font);
        ButtonFindAll = new QPushButton(centralwidget);
        ButtonFindAll->setObjectName("ButtonFindAll");
        ButtonFindAll->setGeometry(QRect(220, 150, 80, 24));
        labelDelete_2 = new QLabel(centralwidget);
        labelDelete_2->setObjectName("labelDelete_2");
        labelDelete_2->setGeometry(QRect(20, 180, 101, 21));
        labelDelete_2->setFont(font);
        ButtonFindRoot = new QPushButton(centralwidget);
        ButtonFindRoot->setObjectName("ButtonFindRoot");
        ButtonFindRoot->setGeometry(QRect(220, 180, 80, 24));
        label_2 = new QLabel(centralwidget);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(20, 210, 101, 16));
        label_2->setFont(font);
        ButtonVaciar = new QPushButton(centralwidget);
        ButtonVaciar->setObjectName("ButtonVaciar");
        ButtonVaciar->setGeometry(QRect(220, 210, 80, 24));
        label_3 = new QLabel(centralwidget);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(570, 130, 131, 16));
        label_3->setFont(font);
        txtAlf1 = new QLineEdit(centralwidget);
        txtAlf1->setObjectName("txtAlf1");
        txtAlf1->setGeometry(QRect(520, 160, 113, 24));
        txtAlf2 = new QLineEdit(centralwidget);
        txtAlf2->setObjectName("txtAlf2");
        txtAlf2->setGeometry(QRect(640, 160, 113, 24));
        ButtonAlf = new QPushButton(centralwidget);
        ButtonAlf->setObjectName("ButtonAlf");
        ButtonAlf->setGeometry(QRect(600, 190, 80, 24));
        PatriciaTree->setCentralWidget(centralwidget);

        retranslateUi(PatriciaTree);

        QMetaObject::connectSlotsByName(PatriciaTree);
    } // setupUi

    void retranslateUi(QMainWindow *PatriciaTree)
    {
        PatriciaTree->setWindowTitle(QCoreApplication::translate("PatriciaTree", "PatriciaTree", nullptr));
        labelInsert->setText(QCoreApplication::translate("PatriciaTree", "Insertar:", nullptr));
        labelSearch->setText(QCoreApplication::translate("PatriciaTree", "Buscar:", nullptr));
        labelDelete->setText(QCoreApplication::translate("PatriciaTree", "Eliminar:", nullptr));
        ButtonInsert->setText(QCoreApplication::translate("PatriciaTree", "Insertar", nullptr));
        ButtonSearch->setText(QCoreApplication::translate("PatriciaTree", "Buscar", nullptr));
        ButtonDelete->setText(QCoreApplication::translate("PatriciaTree", "Eliminar", nullptr));
        label->setText(QCoreApplication::translate("PatriciaTree", "Patricia Tree Implementation", nullptr));
        members->setText(QCoreApplication::translate("PatriciaTree", "Integrantes:", nullptr));
        members_2->setText(QCoreApplication::translate("PatriciaTree", "Javier Olivares", nullptr));
        members_3->setText(QCoreApplication::translate("PatriciaTree", "Matias Meneses", nullptr));
        members_4->setText(QCoreApplication::translate("PatriciaTree", "Santiago Silva", nullptr));
        labelInsert_2->setText(QCoreApplication::translate("PatriciaTree", "Encontrar todos los valores:", nullptr));
        ButtonFindAll->setText(QCoreApplication::translate("PatriciaTree", "Encontrar", nullptr));
        labelDelete_2->setText(QCoreApplication::translate("PatriciaTree", "Encontrar ra\303\255z:", nullptr));
        ButtonFindRoot->setText(QCoreApplication::translate("PatriciaTree", "Encontrar", nullptr));
        label_2->setText(QCoreApplication::translate("PatriciaTree", "Eliminar \303\241rbol:", nullptr));
        ButtonVaciar->setText(QCoreApplication::translate("PatriciaTree", "Eliminar", nullptr));
        label_3->setText(QCoreApplication::translate("PatriciaTree", "Alfabeto a utilizar:", nullptr));
        ButtonAlf->setText(QCoreApplication::translate("PatriciaTree", "Usar", nullptr));
    } // retranslateUi

};

namespace Ui {
    class PatriciaTree: public Ui_PatriciaTree {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PATRICIATREE_H
