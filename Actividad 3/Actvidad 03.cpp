#include <iostream>

using namespace std;

int main() {
    int a[10][20];
    int numero=100;

    for(int i=0;i<10;i++){
        for(int j=0;j<20;j++){
            a[i][j]=numero;
            numero +=1;
        }
    }

    //direccion de los elementos
    cout<<"direccion a[0][0]"<<a[0][0]<<endl;
    cout<<"direccion a[2][1]"<<a[2][1]<<endl;
    cout<<"direccion a[5][1]"<<a[5][1]<<endl;
    cout<<"direccion a[1][10]"<<a[1][10]<<endl;
    cout<<"direccion a[2][10]"<<a[2][10]<<endl;
    cout<<"direccion a[5][3]"<<a[5][3]<<endl;
    cout<<"direccion a[9][19]"<<a[9][19]<<endl;
    cout<<endl;
    cout<<"validacion  *(*(matrix)): "<<*(*a)<<endl;

    for(int i=0;i<1;i++){
        for(int j=0;j<1;j++){
            cout<<"validacion: *((*(a))+(i*COLS + j)) la palabra reservada COLS no existe en mi compilador"<<endl;
            cout<<"validacion *(*(a + i)+ j): "<<*(*(a+i)+j)<<endl;
            cout<<"validacion: (*(a + i))[j]: "<<(*(a + i))[j]<<endl;
        }
    }

    return 0;
}