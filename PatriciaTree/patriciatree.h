#ifndef PATRICIATREE_H
#define PATRICIATREE_H

#include <QMainWindow>
#include <QGraphicsScene> // Para la visualización

QT_BEGIN_NAMESPACE
namespace Ui { class PatriciaTree; }
QT_END_NAMESPACE

class PatriciaTree : public QMainWindow
{
    Q_OBJECT

public:
    PatriciaTree(QWidget *parent = nullptr);
    ~PatriciaTree();

private slots:
    void on_ButtonInsert_clicked();
    void on_ButtonSearch_clicked();
    void on_ButtonDelete_clicked();
    void on_ButtonFindAll_clicked();
    void on_ButtonFindRoot_clicked();
    void on_ButtonVaciar_clicked();
    void on_ButtonAlf_clicked();

private:
    Ui::PatriciaTree *ui;

    // Estructura del nodo del árbol
    struct NodoPatricia {
        QString clave;
        int indice;
        NodoPatricia *izquierda;
        NodoPatricia *derecha;
        NodoPatricia(QString clave, int indice) : clave(clave), indice(indice), izquierda(nullptr), derecha(nullptr) {}
    };

    NodoPatricia* raiz = nullptr; // Raíz del árbol

    // Métodos Principales
    void insertar(QString clave, int indice);
    bool buscar(QString clave);
    void eliminar(QString clave);
    void visualizar(QGraphicsScene& scene, NodoPatricia* nodo, int x, int y, int distancia);

    // Métodos auxiliares
    NodoPatricia* insertarRec(NodoPatricia* nodo, QString clave, int indice, int bit);
    bool buscarRec(NodoPatricia* nodo, QString clave, int bit);
    NodoPatricia* eliminarRec(NodoPatricia* nodo, QString clave, int bit);
    int obtenerBit(QString clave, int posicion);
    void findAll(QStringList &result);
    QString findRoot();
    void vaciarArbol(NodoPatricia* nodo);
    bool esClaveValida(QString clave);
};
#endif // PATRICIATREE_H
