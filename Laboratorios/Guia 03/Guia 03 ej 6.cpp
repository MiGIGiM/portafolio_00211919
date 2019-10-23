#include <iostream>
using namespace std;

struct nodo{
    int dato;
    nodo* sig;
};

void separacionLista(nodo** lista, nodo** pares, nodo** impares);
void insertarLista(nodo** lista, int dato);
void impresion(nodo* lista);

int main(void){
    nodo* pInicio = NULL, *lPares = NULL, *lImpares = NULL;
    int dato;
    cout << "Ingrese un numero (666 para salir): "; cin >> dato;

    while(dato != 666){
        nodo* nuevo = new nodo;
        nuevo->dato = dato;
        nuevo->sig = NULL;

        nuevo->sig = pInicio;
        pInicio = nuevo;

        cout << "Ingrese un numero (666 para salir): ";cin >> dato;
    }
    cout << "Lista normal" << endl;
    impresion(pInicio);

    separacionLista(&pInicio, &lPares, &lImpares);
    cout << endl << "Lista pares" << endl;
    impresion(lPares);

    cout << endl << "Lista impares" << endl;
    impresion(lImpares);

    return 0;
}

void impresion(nodo* lista){
    if(lista){
        cout << lista->dato << " ";
        impresion(lista->sig);
    }
}

void separacionLista(nodo** lista, nodo** pares, nodo** impares){
    if(*lista){
        if((*(*lista)).dato % 2 == 0){
            insertarLista(pares, (*(*lista)).dato);
        }
        else{
            insertarLista(impares, (*(*lista)).dato);
        }
        *lista = (*(*lista)).sig;
        separacionLista(lista, pares, impares);
    }
}

void insertarLista(nodo** lista, int dato){
    nodo* nuevo = new nodo;
    nuevo->dato = dato;
    nuevo->sig = NULL;

    nuevo->sig = *lista;
    *lista = nuevo;
}
