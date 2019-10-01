#include <iostream> 
using namespace std;

struct nodo{
	int dato;
	nodo* sig;
};

void ListaCircular(nodo* pCola, int x, int y);
void Menu();

int main(){
	int dato = 0, cont = 0, opc = 0;
	nodo *pCola = NULL;
	nodo *aux = NULL;
	nodo *nuevo = NULL;
	do{
		Menu(); cin >> opc;
		switch(opc){
			case 1:
				
				cout << "Ingrese dato o ingrese 69 para salir: ";cin >> dato;
	do{
	nodo *nuevo = new nodo;
		cont++;
		nuevo->	dato = dato;
		nuevo->sig = NULL;
		
		if(pCola == NULL)
		   pCola = nuevo;
		else{
			nodo* aux = pCola;
			while(aux->sig != NULL)
			    aux = aux->sig;
			aux->sig = nuevo;    
		}   
		cin >> dato;
	}while(dato != 69);
	
	aux = pCola;
	while (aux->sig != NULL)
		aux = aux->sig;

	aux->sig = pCola;
	break;
		case 2:
		ListaCircular(pCola, cont, 0);
		break;
		}
		
			
	}while(opc != 0);
}

void Menu(){
	cout << "\t1.Ingresar datos." << endl;
	cout << "\t2.Imprimir cola." << endl;
	cout << "\t0. Salir \nSu opcion: ";
}
void ListaCircular(nodo* pCola, int x, int y){
	if(x == y)
	return;
	else{
		cout << "Dato: " << pCola->dato << endl;
		ListaCircular(pCola->sig, x, y + 1);
	}
}
