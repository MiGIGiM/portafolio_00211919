#include <iostream>
#include <string>
using namespace std;

enum genero {ficcion, aventura, policial, romance, misterio};

struct libro {
	string titulo;
	string autor;
	genero tipo;
	int isbn;
	bool espanol;
};

struct nodo {
	libro dato;
	nodo* sig;
};

void Menu();
void MostrarLibros(nodo *lista);
void BorrarMisterio(nodo** lista);
void ContarEsp(nodo* lista, int cont);
void ContarFiccion(nodo* lista, int cont);

int main() {
	int opc = 0;
	nodo* pInicio = NULL;
	nodo* nuevo = NULL;
	char SiNo;
	char clase;

	do {
		Menu(); cin >> opc;
		switch (opc) {
		case 1:
			nuevo = new nodo;
			cout << "ISBN: "; cin >> nuevo->dato.isbn;
			cin.ignore();
			cout << "Titulo: "; getline(cin, nuevo->dato.titulo);
			cout << "Autor: "; getline(cin, nuevo->dato.autor);
			cout << "Genero (f-ficcion|a-aventura|p-policial|r-romance|m-misterio): ";
			cin >> clase;
			switch (clase) {
			case 'f': nuevo->dato.tipo = ficcion;
				break;
			case 'a': nuevo->dato.tipo = aventura;
				break;
			case 'p': nuevo->dato.tipo = policial;
				break;
			case 'r': nuevo->dato.tipo = romance;
				break;
			case 'm': nuevo->dato.tipo = misterio;
				break;
			default: cout << "Opcion erronea!" << endl;
				break;
			}
			cout << "Espanol? (s/n): "; cin >> SiNo;
			switch (SiNo) {
			case 's':
			case 'S': 
				nuevo->dato.espanol = true;
				break;
			case 'n':
			case 'N':
				nuevo->dato.espanol = false;
				break;
			default: 
				cout << "ERROR.<3" << endl;
				break;
			}
			nuevo->sig = NULL;

			nuevo->sig = pInicio;
			pInicio = nuevo;
			break;
		case 2:
			MostrarLibros(pInicio);
			break;
		case 3:
			BorrarMisterio(&pInicio);
			break;
		case 4:
			ContarEsp(pInicio, 0);
			break;
		case 5:
			ContarFiccion(pInicio, 0);
			break;
		}

	} while(opc != 0);
}

void Menu() {
	cout << "MENU: \n" << endl;
	cout << "1. Agregar libro." << endl;
	cout << "2. Mostrar libros." << endl;
	cout << "3. Borrar TODOS los libros de misterio." << endl;
	cout << "4. Verificar si hay libros en espanol. " << endl;
	cout << "5. Veriicar si hay libros de ficcion. " << endl;
	cout << "0. Salir \nSu opcion: ";
}

void MostrarLibros(nodo* lista) {
	if (!lista)
		return;
	else {
		cout << "ISBN: " <<lista->dato.isbn << endl;
		cout << "Titulo: " << lista->dato.titulo << endl;
		cout << "Autor: " << lista->dato.autor << endl;
		if (lista->dato.tipo == ficcion)
			cout << "Genero: Ciencia Ficcion" << endl;


		if (lista->dato.tipo == aventura)
			cout << "Genero: Aventura" << endl;

		if (lista->dato.tipo == policial)
			cout << "Genero: Policial" << endl;

		if (lista->dato.tipo == misterio)
			cout << "Genero: Misterio" << endl;

		if (lista->dato.tipo == romance)
			cout << "Genero: Romance <3" << endl;

		cout << "Idioma: ";
		if (lista->dato.espanol == true)
			cout << "Espanol" << endl;
		else
			cout << "Ingles" << endl;

		MostrarLibros(lista->sig);
	}
}

void BorrarMisterio(nodo** lista) {
	if (*lista) {
		if ((*(*lista)).dato.tipo == misterio) {
			*lista = (*(*lista)).sig;
			BorrarMisterio(lista);
		}
		else {
			BorrarMisterio(&(*(*lista)).sig);
		}
	}
}

void ContarEsp(nodo* lista, int cont) {
	if (!lista)
		cout << "Libros en espanol disponibles:" <<cont << endl;
	else {
		if (lista->dato.espanol == true)
			cont++;

		ContarEsp(lista->sig, cont);
	}
}


void ContarFiccion(nodo* lista, int cont) {
	if (!lista)
		cout << "Libros de Ficcion almacenados: " << cont << endl;
	else {
		if (lista->dato.tipo == ficcion)
			cont++;

		ContarFiccion(lista->sig, cont);
	}
}
