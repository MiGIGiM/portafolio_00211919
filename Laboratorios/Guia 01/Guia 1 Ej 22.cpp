#include <iostream>
using namespace std;


int main(){
	int a[5][5] = {{0, 0, 0, 0, 0}, {0, 0, 0, 0, 0}};
	
	for(int i = 0; i < 5; i++){
		for (int j = 0; j < 5; j++){
			if((i == j) || (j == i-1) || (j == i + 1)){
				cout << "Valor para a[" << i << "][" << j << "]: "; cin >> a[i][j];
			}
	}
}
   cout << "Matriz tri-diagonal resultante: " << endl;
    for(int i = 0; i < 5; i++){
    	for(int j = 0; j < 5; j++){
    		cout << a[i][j] << " ";
    		}
    		cout << endl;
    }
}




