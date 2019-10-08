#include <iostream>
#include <string>
using namespace std;

struct Orden{
	int Revueltas = 0;
	int FQ = 0;
	int Queso = 0;
	bool arroz;
	Orden* sig;
};

void menu();
void MostrarOrden(Orden *lista);

int main(){
	int opc = 0;
	char rice;
	Orden pupusas;
	Orden *pInicio = NULL;
	Orden * nuevo = NULL;
	
	do{
		menu(); cin >> opc;
		switch(opc){
			case 1:
				nuevo = new Orden;
				cout << "Desea que sus pupusas sean de arroz? (s/n)"; cin >> rice;
				if(rice == 's'){
					
					pupusas.arroz = true;
					cout << "Ingrese cantidad de pupusas de Frijol y Queso: "; cin >> nuevo->FQ;
					cout << "Ingrese cantidad de pupusas de Revueltas: "; cin >> nuevo->Revueltas;
					cout << "Ingrese cantidad de pupusas de Queso: "; cin >> nuevo->Queso;
					
					nuevo->sig = NULL;
					if(pInicio == NULL)
					pInicio = nuevo;
					else{
					Orden* aux = pInicio;
					while(aux->sig != NULL)
					aux = aux->sig;
					
					aux->sig = nuevo; 
					}	
				}
				
				
				else{
				pupusas.arroz = false;
				cout << "Ingrese cantidad de pupusas de Frijol y Queso: "; cin >> nuevo->FQ;
					cout << "Ingrese cantidad de pupusas de Revueltas: "; cin >> nuevo->Revueltas;
					cout << "Ingrese cantidad de pupusas de Queso: "; cin >> nuevo->Queso;
					
					nuevo->sig = NULL;
					if(pInicio == NULL)
					pInicio = nuevo;
					else{
					Orden* aux = pInicio;
					while(aux->sig != NULL)
					aux = aux->sig;
					
					aux->sig = nuevo; 
	
				 }
				}
	
				break;
				case 2:
					cout << "Desea ver las pupusas de Arroz ingresadas?(1/0): "; cin >> opc;
					if(opc == 1)
					pupusas.arroz = true;
					
					if(opc == 0)
					pupusas.arroz = false;
					
					if(pupusas.arroz == true){
					cout << "Pupusas de Arroz en la orden:" << endl ;
					MostrarOrden(pInicio);
					
					}else if (pupusas.arroz == false){
					cout << "Pupusas de Maiz en la orden:" << endl ;
					MostrarOrden(pInicio);
					}
					break;
		}
	}while(opc != 0);
	
}


void menu(){
	cout << "MENU PRINCIPAL" << endl;
	cout << endl;
	cout << "\t1.Agregar orden." << endl;
	cout << "\t2. Mostrar orden." << endl;
	cout << "\0. Salir \t Ingrese su opcion: ";
}

void MostrarOrden(Orden *lista){
	if(!lista)
	return;
	else{
		if(lista->arroz == true){
	cout << "Frijol y Queso: " <<  lista->FQ << endl;
	cout << "Revueltas: " <<  lista->Revueltas << endl;
	cout << "Queso: " <<  lista->Queso << endl;
		}
		else{
	cout << "Frijol y Queso: " <<  lista->FQ << endl;
	cout << "Revueltas: " <<  lista->Revueltas << endl;
	cout << "Queso: " <<  lista->Queso << endl;
		}
	MostrarOrden(lista->sig);					
	}
}
