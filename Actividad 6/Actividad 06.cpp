#include <iostream>
using namespace std;

int busquedaRecursiva(int x, int low, int high);
int a[8] = { 1, 3, 4, 5, 17, 18, 31, 33 };
int main() {
	int low = 0;
	int high = 7;
	int x;
	int i = 0;
	
	cout << "Elemento que desea buscar: "; cin >> x;
	
	i = busquedaRecursiva(x, 0, 7);
	if (i == -1) {
		cout << "Elemento no encontrado.";
	}
	else {
		cout << "Elemento encontrado.";
	}

}

int busquedaRecursiva(int x, int low, int high) {
	if (low > high)
		return -1;

	int mid = (low + high) / 2;

	if (x == a[mid])
	return mid;
	if (x < a[mid])
		return busquedaRecursiva(x, low, mid-1);
	else
		return busquedaRecursiva(x, mid + 1, high);
}
