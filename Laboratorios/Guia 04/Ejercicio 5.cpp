#include <iostream>

using namespace std;

struct nodo{
    int numero;
    nodo *izq;
    nodo *der;
};

struct lista{
    int numero;
    lista *sig;
} mlista;

nodo *crearNodo(int numero);
void menu();
void agregarNodo(nodo **Inicio, int numero);
bool mostrarArbol(nodo *arbol, int numero);
void agregarlista(lista* lista, int numero);
void mostrarLista(lista lista, int suma);

int main (){
    nodo *Inicio = NULL;
    int opcion =0;
    int numero=0;

    agregarNodo(&Inicio, 50);
    agregarNodo(&Inicio, 25);
    agregarNodo(&Inicio, 60);
    agregarNodo(&Inicio, 15);
    agregarNodo(&Inicio, 70);

    do{
        menu();
        cin>>opcion;

        switch(opcion){
            case 1:
                cout<<"digite numero a buscar "<<endl;
                cin>>numero;
                if(mostrarArbol(Inicio,numero) == true){
                    agregarlista(&mlista, numero);
                }
                else{
                    cout<<"nose encontro el valor"<<endl;
                }
                break;
            case 2:
                mostrarLista(mlista, 0);
                break;
            case 0:
                break;
            default:
                cout<<"digite numero valido"<<endl;
        }

    }
    while(opcion != 0);

    return 0;
}

nodo *crearNodo(int numero){
    nodo *nuevo = new nodo;
    nuevo->numero = numero;
    nuevo->izq = NULL;
    nuevo->der = NULL;

    return nuevo;
}

void menu(){
    cout<<"Menu Principal"<<endl;
    cout<<"1) buscar nodo"<<endl;
    cout<<"2) mostrar promedio encontrados"<<endl;
    cout<<"0) salir"<<endl;
}

void agregarNodo(nodo **Inicio, int numero){
    if(!*Inicio){
        *Inicio = crearNodo(numero);
    }
    else{
        //insertar a la izquierda
        if(numero < (*(*Inicio)).numero){
            agregarNodo(&(*(*Inicio)).izq, numero);
        }
            //insertar a la derecha
        else{
            agregarNodo(&(*(*Inicio)).der, numero);
        }
    }
}

bool mostrarArbol(nodo *arbol, int numero){
    if(!arbol){
        return false;
    }
    else{
        if(arbol->numero == numero){
            return true;
        }
        mostrarArbol(arbol->izq,numero);
        mostrarArbol(arbol->der,numero);
    }

}

void agregarlista(lista **pInicio,int numero){
    if(!pInicio){
        lista *nuevo = new lista;
        nuevo->numero = numero;
        nuevo->sig = NULL;
        (*(*pInicio)).numero = nuevo->numero;
        (*(*pInicio)).sig = NULL;
    }
    else{
        if((*(*pInicio)).sig != NULL){
            agregarlista((*(*pInicio)).sig,numero);
        }
        else{
            return;
        }
    }
}

void mostrarLista(lista *lista, int suma){
    if(!lista){
    return;
    }
    else{
        suma += lista->numero;
        mostrarLista(lista->sig, suma);
    }
}
