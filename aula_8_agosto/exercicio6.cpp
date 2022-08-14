/*
 * 6 - Elabore um algoritmo que dados dois vetores inteiros de 20 posições, 
 * efetue as respectivas operações matemáticas indicadas em um terceiro vetor de 20 
 * posições de caracteres. Armazene o resultado de cada operação em outro vetor de 20 inteiros. 
 * Utilize as quatro operações aritméticas (+, -, *, /).
 */
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
    int vetorA[10], vetorB[10], vetorMais[20],vetorMenos[20],vetorVezes[20],vetorDivisão[20];
    //Poulando o vetorA
    for(int i=0; i<10; i++){
        vetorA[i]= i;
    }
    //Poulando o vetorB
    for(int i=0; i<10; i++){
        vetorB[i]= i+10;
    }
    //mostrando o vetorA
    cout << "vetorA= " << endl;
    for(int i=0; i<10; i++){
        cout << vetorA[i] << endl;
    }
    //mostrando o vetorB
    cout << "vetorB= " << endl;
    for(int i=0; i<10; i++){
        cout << vetorB[i] << endl;
    }

    //Somando A e B
   
    for(int i=0; i<20; i++){
        vetorMais[i]=vetorA[i]+vetorB[i];
         cout << "Soma= "<< vetorA[i]<<"+"<< vetorB[i]<< "=" ;
         cout << vetorMais[i] << endl;
    }
    //Subtraindo A e B
   
    for(int i=0; i<20; i++){
        vetorMenos[i]=vetorA[i]-vetorB[i];
         cout << "Soma= "<< vetorA[i]<<"-"<< vetorB[i]<< "=" ;
         cout << vetorMenos[i] << endl;
    }


    return 1;
}