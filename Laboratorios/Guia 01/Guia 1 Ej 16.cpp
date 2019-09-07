#include <iostream>
using namespace std;

int main(){
	int a[10];
	int suma;
	
	for(int i = 0; i < 10; i++){
		cout << "Ingrese valor " << i + 1 << ": "; cin >> a[i];
	}
	for(int i = 0; i < 10; i++){
		suma+=a[i];
	}
	for(int i = 0; i < 1; i++){
		cout << "La suma de los numeros ingresados es: " << suma << endl;
	}
	
}
