#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <stdio.h>
using namespace std;
void minmax(int *menor, int *maior, int *vetor, int posicao){
    *menor= vetor[0];
    *maior= vetor[0];
    for (int i=0;i<posicao;i++){
        if(vetor[i]<*menor){
            *menor=vetor[i];
        }
        if(vetor[i]>*maior){
            *maior=vetor[i];
        }
    }
    

}

void imprimirvetor(int *vetor, int posicao){
    for(int i=0; i<posicao; i++){
        cout<<"vetor["<< i << "]=" << vetor[i]<<endl;
        
    }
}

main(){
    int vetor[] = {30,10,1000,40,50}; 
    int menor, maior;
    minmax(&menor,&maior, vetor,5);
    
    cout << "menor valor:" <<  menor<<endl;
    cout << "maior valor:" << maior<<endl;

    imprimirvetor(vetor,5);

    



    return 1;
}