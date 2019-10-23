#include <iostream>
#include <cmath>
using namespace std;

struct nodo{
    float coef;
    float exp;
    nodo *sig;
};

float evaluacionPolinomio(nodo* lista);

int main(void){
    nodo* pInicio = NULL;

    float c, e;
    cout << "Ingrese numero (666 para salir.)" << endl;
    cout << "Coeficiente: " ; cin >> c;
	cout << "Exponente: "; cin >> e;
	
    while(c != 666 & e != 666){
        nodo *nuevo =  new nodo;
        nuevo->coef = c;
        nuevo->exp = e;
        nuevo->sig = NULL;

        nuevo->sig = pInicio;
        pInicio = nuevo;
        
		cout << "Ingrese numero (666 para salir.)" << endl;
        cout << "Coeficiente: " ; cin >> c;
		cout << "Exponente: "; cin >> e;
    }

    cout << "Suma: " << evaluacionPolinomio(pInicio) << endl;
}

float evaluacionPolinomio(nodo* lista){
    if(lista){
        return pow(lista->coef, lista->exp) + evaluacionPolinomio(lista->sig);
    }
    else{
        return 0;
    }
}
