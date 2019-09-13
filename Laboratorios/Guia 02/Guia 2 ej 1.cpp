#include <iostream>
using namespace std;

int Euclides(int mayor, int menor, int mcd);

int main(){
	int mayor = 0, menor = 0, mcd = 0;
	
	cout << "Ingrese mayor: "; cin >> mayor;
	cout << "Ingrese menor: "; cin >> menor;
	mcd = mayor % menor;
	cout << "El MCD es " << Euclides(mayor,menor, mcd);
	 
	
}

int Euclides(int mayor, int menor, int mcd){
	if(mcd == 0)
	return menor;
	
	else{
		mayor = menor;
		menor = mcd;
		mcd = mayor%menor;
		return Euclides(mayor, menor, mcd);
	}
	
}
