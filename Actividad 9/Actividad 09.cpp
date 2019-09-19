#include <iostream>

using namespace std;

struct nodo {
	int dato;
	nodo* sig;
};

void menu();
void imprimirLista(nodo* lista);

int main() {
	int opc = 0;
	nodo* pInicio = NULL;
	nodo* nuevo = NULL;


	do {
		menu(); cin >> opc;
		switch (opc) {
		case 1:
			nuevo = new nodo;

			cout << "Ingrese un numero: "; cin >> nuevo->dato;


			if (pInicio == NULL){
				pInicio = nuevo;
				nuevo->sig = NULL;
			}
			else {
				nuevo->sig = pInicio;
				pInicio = nuevo;
			}
			
			break;
		case 2:
				imprimirLista(pInicio);
			break;
		}

	} while (opc != 0);
	
	return 0;
}


void menu() {
	cout << "1. Ingresar dato." << endl;
	cout << "2. Mostrar datos en la lista." << endl;
	cout << "0. Salir \tIngrese su opcion: ";
}

void imprimirLista(nodo* lista) {
	if (lista == NULL)
		return;
	else {
		cout << "Dato: " << lista->dato << endl;
		imprimirLista(lista->sig);
	}
		
}
