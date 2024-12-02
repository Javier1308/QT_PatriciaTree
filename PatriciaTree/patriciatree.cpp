#include "patriciatree.h"
#include "./ui_patriciatree.h"
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QGraphicsEllipseItem>
#include <QGraphicsTextItem>
#include <QMessageBox>
#include <stack>

PatriciaTree::PatriciaTree(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PatriciaTree)
{
    ui->setupUi(this);

    QGraphicsScene* scene = new QGraphicsScene(this);
    ui->graphicsView->setScene(scene);

    ui->ButtonInsert->setEnabled(false);
    ui->ButtonSearch->setEnabled(false);
    ui->ButtonDelete->setEnabled(false);
}

PatriciaTree::~PatriciaTree()
{
    delete ui;
}

QChar valor1 = '0';
QChar valor2 = '1';

void PatriciaTree::on_ButtonAlf_clicked() {
    QString alfabeto1 = ui->txtAlf1->text().trimmed();
    QString alfabeto2 = ui->txtAlf2->text().trimmed();

    if (alfabeto1.isEmpty() || alfabeto2.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ambos valores del alfabeto deben ser ingresados.");
        return;
    }

    if (alfabeto1 == alfabeto2) {
        QMessageBox::warning(this, "Error", "Los valores del alfabeto deben ser distintos.");
        return;
    }

    valor1 = alfabeto1[0];
    valor2 = alfabeto2[0];

    ui->ButtonInsert->setEnabled(true);
    ui->ButtonSearch->setEnabled(true);
    ui->ButtonDelete->setEnabled(true);

    QMessageBox::information(this, "Información", "Alfabeto configurado con éxito: " + QString(valor1) + " y " + QString(valor2));
}


void PatriciaTree::on_ButtonInsert_clicked()
{
    QString clave = ui->txtInsert->text();
    if (clave.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese una clave.");
        return;
    }

    if (!esClaveValida(clave)) {
        QMessageBox::warning(this, "Error", "La clave contiene caracteres no válidos. Use solo: " + QString(valor1) + " y " + QString(valor2));
        return;
    }

    insertar(clave, clave.length());

    ui->txtInsert->clear();

    QGraphicsScene* scene = ui->graphicsView->scene();
    scene->clear();
    visualizar(*scene, raiz, ui->graphicsView->width() / 2, 50, 300);
}

void PatriciaTree::on_ButtonSearch_clicked()
{
    QString clave = ui->txtSearch->text();
    if (clave.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese una clave.");
        return;
    }

    if (buscar(clave)) {
        QMessageBox::information(this, "Información", "Clave encontrada.");
    } else {
        QMessageBox::information(this, "Información", "Clave no encontrada.");
    }
    ui->txtSearch->clear();
}

void PatriciaTree::on_ButtonDelete_clicked()
{
    QString clave = ui->txtDelete->text();
    if (clave.isEmpty()) {
        QMessageBox::warning(this, "Error", "Ingrese una clave.");
        return;
    }

    if (buscar(clave)) {
        raiz = eliminarRec(raiz, clave, 0);
        QMessageBox::information(this, "Información", "Clave eliminada.");

        QGraphicsScene* scene = ui->graphicsView->scene();
        scene->clear();
        visualizar(*scene, raiz, ui->graphicsView->width() / 2, 50, 300);
    } else {
        QMessageBox::information(this, "Información", "Clave no encontrada.");
    }
    ui->txtDelete->clear();
}

void PatriciaTree::on_ButtonFindAll_clicked() {
    QStringList allKeys;
    findAll(allKeys);

    if (allKeys.isEmpty()) {
        QMessageBox::information(this, "Información", "El árbol está vacío.");
    } else {
        QString mensaje = "Claves en el árbol:\n" + allKeys.join(", ");
        QMessageBox::information(this, "Información", mensaje);
    }
}

void PatriciaTree::on_ButtonFindRoot_clicked() {
    QString rootKey = findRoot();
    QMessageBox::information(this, "Información", "Raíz del árbol: " + rootKey);
}

void PatriciaTree::on_ButtonVaciar_clicked() {
    vaciarArbol(raiz);
    raiz = nullptr;

    QGraphicsScene* scene = ui->graphicsView->scene();
    scene->clear();

    QMessageBox::information(this, "Información", "Árbol vaciado.");
}

void PatriciaTree::insertar(QString clave, int indice) {
    raiz = insertarRec(raiz, clave, indice, 0);
}

bool PatriciaTree::buscar(QString clave) {
    return buscarRec(raiz, clave, 0);
}

PatriciaTree::NodoPatricia* PatriciaTree::insertarRec(PatriciaTree::NodoPatricia* nodo, QString clave, int indice, int bit) {
    if (nodo == nullptr) {
        return new NodoPatricia(clave, indice);
    }

    if (nodo->clave == clave) {
        return nodo;
    }

    int bitActual = obtenerBit(nodo->clave, bit);
    int bitClave = obtenerBit(clave, bit);

    if (bitActual != bitClave) {
        NodoPatricia* nuevoNodo = new NodoPatricia(clave, indice);
        if (bitClave < bitActual) {
            nuevoNodo->izquierda = nodo;
        } else {
            nuevoNodo->derecha = nodo;
        }
        return nuevoNodo;
    } else {
        if (clave < nodo->clave) {
            nodo->izquierda = insertarRec(nodo->izquierda, clave, indice, bit + 1);
        } else {
            nodo->derecha = insertarRec(nodo->derecha, clave, indice, bit + 1);
        }
        return nodo;
    }
}

bool PatriciaTree::buscarRec(NodoPatricia* nodo, QString clave, int bit) {
    if (nodo == nullptr) {
        return false;
    }

    if (nodo->clave == clave) {
        return true;
    }

    int bitActual = obtenerBit(nodo->clave, bit);
    int bitClave = obtenerBit(clave, bit);

    if (bitActual != bitClave) {
        return false;
    }

    if (clave < nodo->clave) {
        return buscarRec(nodo->izquierda, clave, bit + 1);
    } else {
        return buscarRec(nodo->derecha, clave, bit + 1);
    }
}

int PatriciaTree::obtenerBit(QString clave, int posicion) {
    if (posicion >= clave.length() * 8) {
        return 0;
    }
    int byteIndex = posicion / 8;
    int bitIndex = 7 - (posicion % 8);
    return (clave[byteIndex].unicode() >> bitIndex) & 1;
}

PatriciaTree::NodoPatricia* PatriciaTree::eliminarRec(PatriciaTree::NodoPatricia* nodo, QString clave, int bit) {
    if (nodo == nullptr) {
        return nullptr;
    }

    if (nodo->clave == clave) {
        if (nodo->izquierda == nullptr && nodo->derecha == nullptr) {
            delete nodo;
            return nullptr;
        }

        if (nodo->izquierda == nullptr) {
            NodoPatricia* temp = nodo->derecha;
            delete nodo;
            return temp;
        }
        if (nodo->derecha == nullptr) {
            NodoPatricia* temp = nodo->izquierda;
            delete nodo;
            return temp;
        }

        NodoPatricia* sucesor = nodo->derecha;
        while (sucesor->izquierda != nullptr) {
            sucesor = sucesor->izquierda;
        }

        nodo->clave = sucesor->clave;
        nodo->indice = sucesor->indice;

        nodo->derecha = eliminarRec(nodo->derecha, sucesor->clave, bit + 1);
        return nodo;
    }

    int bitActual = obtenerBit(nodo->clave, bit);
    int bitClave = obtenerBit(clave, bit);

    if (bitActual != bitClave) {
        return nodo;
    }

    if (clave < nodo->clave) {
        nodo->izquierda = eliminarRec(nodo->izquierda, clave, bit + 1);
    } else {
        nodo->derecha = eliminarRec(nodo->derecha, clave, bit + 1);
    }

    return nodo;
}

void PatriciaTree::visualizar(QGraphicsScene& scene, PatriciaTree::NodoPatricia* nodo, int x, int y, int distancia) {
    if (nodo != nullptr) {
        QGraphicsEllipseItem* ellipse = scene.addEllipse(x - 20, y - 20, 40, 40);
        ellipse->setBrush(Qt::black);

        QGraphicsTextItem* text = scene.addText(nodo->clave);
        text->setPos(x - text->boundingRect().width() / 2, y - text->boundingRect().height() / 2);

        if (nodo->izquierda != nullptr) {
            scene.addLine(x, y, x - distancia, y + 80);
            visualizar(scene, nodo->izquierda, x - distancia, y + 80, distancia / 2);
        }
        if (nodo->derecha != nullptr) {
            scene.addLine(x, y, x + distancia, y + 80);
            visualizar(scene, nodo->derecha, x + distancia, y + 80, distancia / 2);
        }
    }
}

void PatriciaTree::findAll(QStringList &result) {
    std::stack<NodoPatricia*> pila;
    pila.push(raiz);

    while (!pila.empty()) {
        NodoPatricia* nodo = pila.top();
        pila.pop();

        if (nodo != nullptr) {
            result.append(nodo->clave);

            pila.push(nodo->izquierda);
            pila.push(nodo->derecha);
        }
    }
}

QString PatriciaTree::findRoot() {
    if (raiz == nullptr) {
        return "El árbol está vacío.";
    } else {
        return raiz->clave;
    }
}

void PatriciaTree::vaciarArbol(NodoPatricia* nodo) {
    if (nodo != nullptr) {
        vaciarArbol(nodo->izquierda);
        vaciarArbol(nodo->derecha);
        delete nodo;
    }
}

bool PatriciaTree::esClaveValida(QString clave) {
    QSet<QChar> valoresPermitidos = {valor1, valor2};

    for (int i = 0; i < clave.length(); ++i) {
        if (!valoresPermitidos.contains(clave[i])) {
            return false;
        }
    }
    return true;
}

