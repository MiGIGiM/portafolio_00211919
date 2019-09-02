#include <iostream>
#include <cmath>
#include <string>
using namespace std;




struct continente {
    int poblacion[0];
    string pais;
    string capital;

}hyrule[5];
struct continiente {
    int poblacion[0];
    string pais;
    string capital;

}termina[5];
struct contineinte {
    int poblacion[0];
    string pais;
    string capital;

}altarea[5];

struct continentei {
    int poblacion[0];
    string pais;
    string capital;

}hoen[5];
struct cointinente {
    int poblacion[0];
    string pais;
    string capital;

}kanto[5];



int main(void)
{int pob=0;
    int i;
    int a;
    int max=0;
    int x;
    string capitalm;

    cout<<"Ingrese 5 paises , luego ingrese las capitales de dichos paises, y por ultimo la poblacion de cada pais , son 5 continentes a ingresar"<<endl;

    cout<<"Continente hyrule"<<endl;

    for(i=0;i<5;i++)
    {
        cout<<"Ingrese pais"<<" "<< i+1<< ":"<<endl;
        cin>> hyrule[i].pais[i];
        cout<<"Ingrese capital"<<" "<< i+1<< ":"<<endl;
        cin>> hyrule[i].capital[i];
        cout<<"Ingrese poblacion"<<" "<< i+1<< ":"<<endl;
        cin>> hyrule[i].poblacion[i];
        cout<<endl;

    }

    cout<<"Continente termina"<<endl;

    for(i=0;i<5;i++){
        cout<<"Ingrese pais"<<" "<< i+1<< ":"<<endl;
        cin>> termina[i].pais[i];
        cout<<"Ingrese capital"<<" "<< i+1<< ":"<<endl;
        cin>>termina[i].capital[i];
        cout<<"Ingrese poblacion"<<" "<< i+1<< ":"<<endl;
        cin>> termina[i].poblacion[i];

    }


    cout<<"Continente altarea"<<endl;
    for(i=0;i<5;i++){
        cout<<"Ingrese pais"<<" "<< i+1<< ":"<<endl;
        cin>> altarea[i].pais[i];
        cout<<"Ingrese capital"<<" "<< i+1<< ":"<<endl;
        cin>> altarea[i].capital[i];
        cout<<"Ingrese poblacion"<<" "<< i+1<< ":"<<endl;
        cin>> altarea[i].poblacion[i];}

    cout<<"Continente hoen"<<endl;

    for(i=0;i<5;i++){
        cout<<"Ingrese pais"<<" "<< i+1<< ":"<<endl;
        cin>> hoen[i].pais[i];
        cout<<"Ingrese capital"<<" "<< i+1<< ":"<<endl;
        cin>> hoen[i].capital[i];
        cout<<"Ingrese poblacion"<<" "<< i+1<< ":"<<endl;
        cin>> hoen[i].poblacion[i];

    }


    cout<<"Continente kanto"<<endl;

    for(i=0;i<5;i++){
        cout<<"Ingrese pais"<<" "<<i+1<< ":"<<endl;
        cin>> kanto[i].pais[i];
        cout<<"Ingrese capital"<<" "<<i+1<< ":"<<endl;
        cin>> kanto[i].capital[i];
        cout<<"Ingrese poblacion"<<" "<<i+1<< ":"<<endl;
        cin>> kanto[i].poblacion[i];

    }

    cout<<"1.hyrule, 2.termina, 3.altarea, 4.hoen, 5.kanto";
    cout<<"Ingrese el numero del  continente del cual quiere saber la poblacion total:";
    cin>>a;
    cout<<endl;

    if(a==1){
        for(i=0;i<5;i++){
            pob=pob+hyrule[i].poblacion[i];}
        for ( i = 0; i < 5; i++){

            if(hyrule[i].poblacion[i] > max){
                max = hyrule[i].poblacion[i];
                x=i;

            }
        }
        capitalm=hyrule[i].capital[x];}

    if(a==2){
        for(i=0;i<5;i++){
            pob=pob+termina[i].poblacion[i];}
        for ( i = 0; i < 5; i++){

            if(termina[i].poblacion[i] > max){
                max = termina[i].poblacion[i];
                x=i;
            }
        }
        capitalm=termina[i].capital[x];}
    if(a==3){
        for(i=0;i<5;i++){
            pob=pob+altarea[i].poblacion[i];}
        for ( i = 0; i < 5; i++){

            if(altarea[i].poblacion[i] > max){
                max = altarea[i].poblacion[i];
                x=i;}

        }
        capitalm=altarea[i].capital[x];}



    if(a==4){
        for(i=0;i<5;i++){
            pob=pob+hoen[i].poblacion[i];}
        for ( i = 0; i < 5; i++){

            if(hoen[i].poblacion[i] > max){
                max = hoen[i].poblacion[i];
                x=i;
            }

        }
        capitalm=hoen[i].capital[x];}
    if(a==5){
        for(i=0;i<5;i++){
            pob=pob+kanto[i].poblacion[i];}
        for ( i = 0; i < 5; i++){

            if(kanto[i].poblacion[i] > max){
                max = kanto[i].poblacion[i];
                x=i;
            }
        }
        capitalm=kanto[i].capital[x];}



    cout<<"La poblacion total del continente es:"<<pob<<endl;
    cout<<"la capital con mayor poblacion es:"<<capitalm<<endl;




    return 0;
}