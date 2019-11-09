#include <iostream>

using namespace std;

struct nodo{
    int numero;
    nodo *izq;
    nodo *der;
};

nodo *crearNodo(int numero);
void menu();
void agregarNodo(nodo **Inicio, int numero);
void mostrarArbol(nodo *arbol, int suma);
void nivelArbol(nodo *Inicio, int izq, int der);

int main (){
    nodo *Inicio = NULL;
    int opcion =0;
    int numero=0;
    int contador = 0;

    cout<<"digite la raiz del arbol: "<<endl;
    cin>>numero;
    contador++;
    agregarNodo(&Inicio, numero);

    do{
        menu();
        cin>>opcion;

        switch(opcion){
            case 1:
                contador++;
                cout<<"digite numero: "<<endl;
                cin>>numero;
                agregarNodo(&Inicio,numero);
                break;
            case 2:
                cout<<"cantidad de nodos: "<<contador<<endl;
                break;
            case 3:
                mostrarArbol(Inicio,0);
                break;
            case 4:
                nivelArbol(Inicio,0,0);
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
    cout<<"1) agregar nodo"<<endl;
    cout<<"2) cantidad de nodos "<<endl;
    cout<<"3) suma de nodos "<<endl;
    cout<<"4) nivel del arbol"<<endl;
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

void mostrarArbol(nodo *arbol, int suma){
    if(!arbol){
        return;
    }
    else{
        suma += arbol->numero;
        mostrarArbol(arbol->izq,suma);
        mostrarArbol(arbol->der,suma);
    }
    cout<<"suma: "<<suma<<endl;
}

void nivelArbol(nodo *Inicio, int izq, int der){
    if(!Inicio){
        return;
    }
    else{
        if(Inicio->izq !=NULL){
            izq++;
            nivelArbol(Inicio->izq,izq,der);
        }
        if(Inicio->der !=NULL){
            der++;
            nivelArbol(Inicio->der,izq,der);
        }

    }
    if(izq > der){
        cout<<"niveles: "<<izq<<endl;
    }
    else{
        cout<<"niveles: "<<der<<endl;
    }
} 	
