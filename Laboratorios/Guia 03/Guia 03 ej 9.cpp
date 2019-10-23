#include <iostream>
#include <string>
using namespace std;

struct nodo {
	string carnet;
	string nombre;
	string apellido;
	string correo;
	int edad = 0, tel = 0;
	nodo* sig;
};


void menu();
void eliminarPersona(nodo** lista, string carnet);
bool compararCarnet(string cadena1, string cadena2);
void mostrarLista(nodo* lista);
void actualizarPersona(nodo** lista, string carnet);


int main(void) {
	int opc = 0;
	string carnetBuscar;
	nodo* pInicio = NULL;
	nodo* nuevo = new nodo;

	do {
		menu(); cin >> opc;
		switch (opc) {
		case 1: //Llenar lista
			do {
				nuevo = new nodo;
				cout << "Carnet: "; cin >> nuevo->carnet;
				cout << "Nombre: "; cin >> nuevo->nombre;
				cout << "Apellido: "; cin >> nuevo->apellido;
				cout << "Edad: "; cin >> nuevo->edad;
				cout << "Correo: "; cin>>nuevo->correo;
				cout << "Telefono: "; cin >> nuevo->tel;

				if (pInicio == NULL) {
					pInicio = nuevo;

				}
				else {
					nuevo->sig = pInicio;
					pInicio = nuevo;
				}

				cout << "Desea ingresar otra persona?\t1.Si\t2.No\t"; cin >> opc;
			} while (opc != 2);
			break;
		case 2:
			cout << "Ingrese carnet de persona a elimnar:"; cin >> carnetBuscar;
			eliminarPersona(&pInicio, carnetBuscar);
			break;
		case 4:
			mostrarLista(pInicio);
			break;
		case 3:
			cout <<"Ingrese carnet de persona a actualizar:"; cin >> carnetBuscar;
			actualizarPersona(&pInicio, carnetBuscar);

		}
	} while (opc != 0);

	return 0;
}

void menu() {
	cout << "1. Llenar la lista. " << endl;
	cout << "2. Eliminar una persona. " << endl;
	cout << "3. Actualizar datos de una persona. " << endl;
	cout << "4. Mostrar todas las personas. " << endl;
	cout << "0. Salir.\nSu opcion :";
}

void eliminarPersona(nodo** lista, string carnet) {
	if (*lista) {
		if(compararCarnet((*(*lista)).carnet, carnet)){
			*lista = (*(*lista)).sig;

		}
		else {
			eliminarPersona(&(*(*lista)).sig, carnet);
		}

	}
}

bool compararCarnet(string cadena1, string cadena2) {
	if (cadena1.length() != cadena2.length())
		return false;
	else {
		for (int i = 0; i < cadena1.length(); i++)
			if (cadena1[i] != cadena2[i])
				return false;
		return true;
	}
}

void mostrarLista(nodo* lista) {
	if (lista) {
		cout << "Carnet: " << lista->carnet << endl;
		cout << "Nombre: " << lista->nombre << endl;
		cout << "Apellido: " << lista->apellido << endl;
		cout << "Edad: " << lista->edad << endl;
		cout << "Correo: "<< lista->correo << endl;
		cout << "Telefono: " << lista->tel << endl;

		mostrarLista(lista->sig);
	}
}

void actualizarPersona(nodo** lista, string carnet) {
	if (*lista) {
		if (compararCarnet((*(*lista)).carnet, carnet)) {
			
			cout << "Carnet: "; cin >> (*(*lista)).carnet;
			cout << "Nombre: "; cin >> (*(*lista)).nombre;
			cout << "Apellido: "; cin >> (*(*lista)).apellido;
			cout << "Edad: "; cin >> (*(*lista)).edad;
			cout << "Correo: "; cin >> (*(*lista)).correo;
			cout << "Telefono: "; cin >> (*(*lista)).tel;

		}
		else {
			eliminarPersona(&(*(*lista)).sig, carnet);
		}

	}
}
