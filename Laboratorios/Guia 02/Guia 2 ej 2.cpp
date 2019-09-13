#include <iostream>
using namespace std;

int Cifras(int numero, int residuo);

int main(){
	int numero = 0;
	
	cout << "Ingrese un numero: "; cin >> numero;
	cout << "El numero contiene " << Cifras(numero, 0) << " digitos." << endl;
	
	return 0;
}

int Cifras(int numero, int residuo){
	if(numero < 9)
	return 1;
	
	else if(numero > 9){
		residuo = numero%10;
		return 1 + Cifras(numero/10, residuo);
	}
}
