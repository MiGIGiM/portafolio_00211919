#include <iostream>

using namespace std;

struct Nodo
{
    int dato;
    Nodo *sig;
};

struct arbol{
    int dato;
    arbol *izq;
    arbol *der;
};

class LinkedList
{
private:
    Nodo *inicio;

public:
    Nodo* crearNodo(int valor)
    {
        Nodo *n = new Nodo;
        n->dato = valor;
        n->sig = nullptr;
        return n;
    }
    void insertar(int valor)
    {
        Nodo *n = crearNodo(valor), *temp = inicio;
        if (!inicio)
        {
            inicio = n;
        }else
        {
            while (temp)
            {
                if (temp->sig == nullptr)
                {
                    temp->sig = n;
                    temp = nullptr;
                }else
                {
                    temp = temp->sig;
                }
            }
        }
    }
    Nodo* buscarParaBorrarNodo(int valor)
    {
        Nodo *temp = inicio;
        if (!inicio)
        {
            return nullptr;
        }else
        {
            while (temp)
            {
                if (temp->sig != nullptr)
                {
                    if (temp->sig->dato != valor)
                    {
                        temp = temp->sig;
                    }else
                    {
                        return temp;
                    }
                }else
                {
                    return nullptr;
                }
            }
        }
    }
    void eliminarNodo(int valor)
    {
        Nodo *temp = buscarParaBorrarNodo(valor), *aux;
        if (temp != nullptr)
        {
            if (temp->sig->sig != nullptr)
            {
                aux = temp->sig;
                temp = temp->sig->sig;
                delete(aux);
                temp->sig = nullptr;
            }else
            {
                aux = temp->sig;
                delete(aux);
                temp->sig = nullptr;

            }
        }else
        {
            cout << "La lista esta vacia";
        }
    }
    void mostrarLista()
    {
        Nodo *temp = inicio;
        if (!inicio)
        {
            cout << "La lista no tiene elementos";
        }else
        {
            while(temp)
            {
                cout<< temp->dato << ", ";
                temp = temp->sig;
            }
        }
    }
    LinkedList()
    {
        inicio = nullptr;
    }
    arbol *crearArbol(int numero){
        arbol *nuevo = new arbol;
        nuevo->dato = numero;
        nuevo->izq = NULL;
        nuevo->der = NULL;

        return nuevo;
    }

    void agregarNodo(arbol **Inicio, int numero){
        if(!*Inicio){
            *Inicio = crearArbol(numero);
        }
        else{
            //insertar a la izquierda
            if(numero < (*(*Inicio)).dato){
                agregarNodo(&(*(*Inicio)).izq, numero);
            }
                //insertar a la derecha
            else{
                agregarNodo(&(*(*Inicio)).der, numero);
            }
        }
    }
    void mostrarArbol(arbol *arbol){
        if(!arbol){
            return;
        }
        else {
            mostrarArbol(arbol->izq);
            mostrarArbol(arbol->der);
        }
    }
};

void mostrarPO(arbol *a){
    if (a == nullptr){
        return;
    }else{
        cout << a->dato << endl;
        mostrarPO(a->izq);
        mostrarPO(a->der);
    }

}

int main()
{
    arbol *pInicio = NULL;
    LinkedList lista;
    lista.insertar(5);
    lista.insertar(8);
    lista.insertar(10);
    lista.insertar(2);

    lista.mostrarLista();
    system("pause");
    lista.agregarNodo(&pInicio, 5);
    lista.agregarNodo(&pInicio, 8);
    lista.agregarNodo(&pInicio, 10);
    lista.agregarNodo(&pInicio, 2);
    mostrarPO(pInicio);

    system("pause");
    lista.eliminarNodo(5);
    lista.eliminarNodo(8);
    lista.eliminarNodo(10);
    lista.eliminarNodo(2);

    lista.mostrarLista();

}
