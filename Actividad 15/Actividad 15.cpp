#include <iostream>

using namespace std;

struct nodo{
    int numero;
    nodo *izq;
    nodo *der;
};

nodo *crearNodo(int numero);
void menu();
void agregarNodo(nodo **Inicio, int numero, nodo **Inverso);
void mostrarArbol(nodo *arbol, int espaciado);
void recorrerPre(nodo *Inicio);
void recorrerIn(nodo *Inicio);
void recorrerPos(nodo *Inicio);
void profundidad(nodo *Inicio, int contador);

int main (){
    nodo *Inicio = NULL;
    nodo *Inverso = NULL;
    int opcion =0;
    int numero=0;

    cout<<"digite la raiz del arbol: "<<endl;
    cin>>numero;
    agregarNodo(&Inicio,numero,&Inverso);

    do{
    menu();
    cin>>opcion;

    switch(opcion){
        case 1:
            cout<<"digite numero: "<<endl;
            cin>>numero;
            agregarNodo(&Inicio, numero, &Inverso);
            break;
        case 2:
            cout<<"recorrido en pre-orden: "<<endl;
            recorrerPre(Inicio);
            cout<<"recorrido en in-orden: "<<endl;
            recorrerIn(Inicio);
            cout<<"recorrido en pos-orden: "<<endl;
            recorrerPos(Inicio);
            break;
        case 3:
            mostrarArbol(Inicio,0);
            break;
        case 4:
            cout<<"profundidad"<<endl;
            profundidad(Inicio,0);

            break;
        case 5:
            cout<<"arbol inverso"<<endl;
            mostrarArbol(Inverso,0);
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
    cout<<"2) recorrer arbol"<<endl;
    cout<<"3) mostrar arbol "<<endl;
    cout<<"4) mostrar profundidad"<<endl;
    cout<<"5) arbol inverso "<<endl;
    cout<<"0) salir"<<endl;
}

void agregarNodo(nodo **Inicio, int numero, nodo **Inverso){
    if(!*Inicio){
        *Inicio = crearNodo(numero);
        *Inverso = crearNodo(numero);
    }
    else{
        //insertar a la izquierda
        if(numero < (*(*Inicio)).numero){
            agregarNodo(&(*(*Inicio)).izq, numero,&(*(*Inverso)).der);
        }
        //insertar a la derecha
        else{
            agregarNodo(&(*(*Inicio)).der, numero, &(*(*Inverso)).izq);
        }
    }
}

void mostrarArbol(nodo *arbol, int espaciado){
    if(!arbol){
        return;
    }
    else{
        mostrarArbol(arbol->der, espaciado+1);

        for(int i=0; i < espaciado;i++){
            cout<<"\t";
        }
        cout<<arbol->numero<<endl;

        mostrarArbol(arbol->izq, espaciado+1);
    }
}

void recorrerPre(nodo *Inicio){
    if(!Inicio){
        return;
    }
    else{
        cout<<" "<<Inicio->numero;
        recorrerPre(Inicio->izq);
        recorrerPre(Inicio->der);
    }


}

void recorrerIn(nodo *Inicio){
    if(!Inicio){
        return;
    }
    else{
        recorrerIn(Inicio->izq);
        cout<<" "<<Inicio->numero;
        recorrerIn(Inicio->der);
    }


}

void recorrerPos(nodo *Inicio){
    if(!Inicio){
        return;
    }
    else{
        recorrerPos(Inicio->izq);
        recorrerPos(Inicio->der);
        cout<<" "<<Inicio->numero;
    }


}

void profundidad(nodo *Inicio,int contador){
    if(!Inicio){
        cout<<contador<<endl;
        return;
    }
    else{
        profundidad(Inicio->izq, contador);
        contador++;
        profundidad(Inicio->der, contador);

    }


}