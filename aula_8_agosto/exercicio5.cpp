/*
 * 5 - Faça um algoritmo que possua dois vetores, 
 * um preenchido com valores seqüenciais de 0 a 9 e outro com valores sequenciais de 10 a 19, 
 * e intercale-os num terceiro vetor formando uma nova variável. Mostre o vetor obtido.
 */

#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
    int vetorA[10], vetorB[10], vetorC[20], cont=0,c=0;
    //Ppoulando o vetorA
    for(int i=0; i<10; i++){
        vetorA[i]= i;
    }
    //Ppoulando o vetorB
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

    
    for(int i=0; i<20; i++){
        if(i<=9){     //if(i%2==0){vetorC[i]=vetorA[c] c++;
            vetorC[i]=vetorA[i];
        }
        else{
            vetorC[i]=vetorB[i-10];    // {vetorC[i]=vetorA[cont] cont++;
        }
       
    }
    cout << "vetorC= " << endl;
    for(int i=0; i<20; i++){
         cout << vetorC[i] << endl;
    }



    return 1;
}
