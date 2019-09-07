#include <iostream>
using namespace std;

void Recursiva(int n, int cont);

int main(){
	int n = 0;
	
	cout << "Ingrese numero: "; cin >> n;
	Recursiva(n, 1);
	return 0;
}

void Recursiva(int n, int cont){
	if(n == cont)
	return;
	else{
		cout << cont << endl;
		Recursiva(n, cont + 1);
		cout << cont << endl;
	}
}

