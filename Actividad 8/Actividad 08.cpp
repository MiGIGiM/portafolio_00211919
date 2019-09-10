#include <iostream>
using namespace std;

struct Tpila{
float elements[100];
int top;
};
typedef struct Tpila Pila;

void menu();
float initialize(Pila *s);
void push(Pila *s, float e);
void pop(Pila *s, float *e);
void peek(Pila *s);
bool empty(Pila *s);

int main(){
	Pila unaPila;
	initialize(&unaPila);
	char opc;
	int opcion = 0;
	float x = 0, y = 0;
	do{
	
	menu(); cin >> opcion;
	switch(opcion){
		case 1: 
		do{
		cout << "Ingrese valor: "; cin >> x;
		push(&unaPila, x);
		cout << "Agregar otro (s/n) "; cin >> opc;
		}while( opc != 'n');
	break;	
	    case 2: 
	    cout << "Ingrese y: "; cin >> y;
	    while(!empty(&unaPila)){
	    	pop(&unaPila, &y);
	    	cout << "y: " << y << endl;
		}
		break;
		case 3:
		peek(&unaPila);
		break;	
	}
	}while(opcion != 0);
}

void menu(){
	cout <<"1.Ingresar valores." << endl;
	cout <<"2.Hacer POP." <<endl;
	cout <<"3.Hacer PEEk." << endl;
	cout << "0.Salir. " << "Su opcion: "; 
}
float initialize(Pila *s){
	s->top = -1;
}

void push(Pila *s, float e){
if(s->top < 99){
(s->top)++;
s->elements[s->top] = e;
}
}

void pop(Pila *s, float *e){
if(s->top >= 0){
*e = s->elements[s->top];
(s->top)--;
}
}

bool empty(Pila *s){
return s->top < 0;
}

void peek(Pila *s){
for(int i = 0; i < 100; i++){
	if(s->elements[i] == 0){
	return;	
		}else 
			cout << "Elemento " << i + 1 << ": " << s->elements[i] << endl;
	
}
}


