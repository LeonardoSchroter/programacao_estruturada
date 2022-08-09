#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#define N 5

using namespace std;

typedef struct{
    string sigla;
    int x;
    int y;
    int z;
}atomos;

int main(){
    atomos atomo[N];
     srand (time(NULL));

    for (int i=0; i<N; i++){
        cout<<"digite a sigla do atomo \n";
        cin>> atomo[i].sigla;
        atomo[i].x=rand() % 10;
        atomo[i].y= rand() % 10;
        atomo[i].z=rand() % 10;


        

    } 
     for (int i=0; i<N; i++){
        cout<<"----------------------------\n";
         cout<< "o elemento eh "<< atomo[i].sigla<<"\n";
         cout<< "posicao x eh "<< atomo[i].x<<"\n";
         cout<< "posicao y eh "<< atomo[i].y<<"\n";
         cout<< "posicao z eh "<< atomo[i].z<<"\n";
     }



    return 1;
}