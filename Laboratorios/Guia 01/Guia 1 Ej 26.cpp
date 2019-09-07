#include <iostream>
using namespace std;

struct numeroImaginario{
	int real = 0, imaginario = 0;
};

int conjugado(int dato);
numeroImaginario valor;

int main()
{
		
	cout << "Ingrese la parte real del numero: "; cin >> valor.real;
	cout << "Ingrese la parte imaginaria del numero: "; cin >> valor.imaginario;
	
	if(valor.imaginario > 0)
	cout << "Numero imaginario ingresado: " << valor.real << "+" << valor.imaginario  << "i" << endl;
	
	else
	cout << "Numero imaginario ingresado: " << valor.real << "-" << (-1)*valor.imaginario << "i" << endl;
	
	
	if(conjugado(valor.imaginario) > 0)
	cout << "Conjudada del numero ingresado: " << valor.real << "+" << conjugado(valor.imaginario) << "i" << endl;
	
	else 
	cout << "Conjudada del numero ingresado: " << valor.real << conjugado(valor.imaginario) << "i" << endl;
	return 0;
}

int conjugado(int dato){
	return dato*-1;
}
