#include <iostream>
using namespace std;

struct nodo {
	int dato;        
	struct nodo* sig;
};
typedef struct nodo* Tlista;
Tlista pInicio, nuevo;

void MenuPrincipal();
void OrdenarLista(Tlista lista);
void ImprimirLista(Tlista inicio);
void InsertarLista(nodo** lista);

int main()
{
	pInicio = NULL;
	nuevo = NULL;

	int opc;    
	int numero;   



	do
	{
		MenuPrincipal();  cin >> opc;

		switch (opc)
		{
		case 1:
			InsertarLista(&pInicio);
			break;


		case 2:
			cout << "Elementos en la lista: ";
			cout << endl;
			ImprimirLista(pInicio);
			break;


		case 3:
			cout << "Elementos ordenados de menor a mayor: ";
			cout << endl;
			OrdenarLista(pInicio);
			ImprimirLista(pInicio);
			break;

		}

		cout << endl << endl;
		

	} while (opc != 0);

	return 0;
}


void InsertarLista(nodo** lista) {
	nodo* nuevo = new nodo;

	cout << "Ingrese dato: ";
	cin >> nuevo->dato;

	nuevo->sig = NULL;

	if (!*lista)
		* lista = nuevo;

	else {
		nuevo->sig = *lista;
		*lista = nuevo;
	}
}

void ImprimirLista(Tlista inicio)
{

	while (inicio != NULL)
	{
		cout << "Dato: " << inicio->dato << endl;
		inicio = inicio->sig;
	}

}

void OrdenarLista(Tlista lista)
{
	Tlista actual, siguiente;
	int aux;

	actual = lista;
	while (actual->sig != NULL)
	{
		siguiente = actual->sig;

		while (siguiente != NULL)
		{
			if (actual->dato > siguiente->dato)
			{
				aux = siguiente->dato;
				siguiente->dato = actual->dato;
				actual->dato = aux;
			}
			siguiente = siguiente->sig;
		}
		actual = actual->sig;
		siguiente = actual->sig;

	}

}


void MenuPrincipal()
{
	cout << " 1. Ingresar datos." << endl;
	cout << " 2. Imprimir lista." << endl;
	cout << " 3. Imprimir lista ordenada." << endl;
	cout << " 0. Salir.";
	cout << "\t Su opcion: ";
}


