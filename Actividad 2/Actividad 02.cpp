#include <iostream>

using namespace std;

int main(){
    int n;
    cout<<"digite el tamano de su arreglo"<<endl;
    cin>>n;

    int *arreglo = new int[n];

    for(int i=0;i<n;i++){
        cout<<"digite numero para arreglo["<<i<<"]: "<<endl;
        cin>>arreglo[i];
    }

    if(n%2 != 0){
        cout<<"la mediana es: "<<arreglo[n/2]<<endl;
    }
    else{
        float mediana=0;
        cout<<"la mediana es: "<<arreglo[(n/2-1)]<<endl;
        cout<<"la mediana es: "<<arreglo[(n/2)]<<endl;
        mediana = (arreglo[(n/2-1)] + arreglo[(n/2)]);
        mediana /= 2;
        cout<<"la media promediada: "<<mediana<<endl;
    }

}


