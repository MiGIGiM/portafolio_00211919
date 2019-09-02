#include <iostream>
using namespace std;

int multiplicacionRecursiva(int x, int y);

int main(){
	int a = 0;
	int b = 0;
	
	cout << "Ingrese a: "; cin >> a; 
	cout << "Ingrese b: "; cin >> b;
	cout << "El producto de " << a << "*" << b << " es igual a: " << multiplicacionRecursiva(a,b);
}

int multiplicacionRecursiva(int x, int y){
	if(y == 1){
		return x;
	}else if(y > 1){
		return x + multiplicacionRecursiva(x, y-1);
	}
}
