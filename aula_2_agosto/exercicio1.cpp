#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#define N 10 //define uma constante N com valor 10

using namespace std;

int main(){

    int vetor[N];

    srand(time(NULL));
    for(int i=0 ; i < N; i++){
        vetor[i] =rand() % 101;
    }

    cout<<"Valores do vetor \n ";
    for(int i= 0;i < N;i++){
        cout<< vetor[i] << "\t";
    }

    //descobrir menor valor

    int menor = vetor[0];
    for (int i= 1;i<N; i++){
        if (vetor[i] < menor){
            menor = vetor[i];
        }
    }
    cout<< "o menor valor encontrado no vetor e "<<menor<< endl;

    int maior = vetor[0];
    for (int i= 1;i<N; i++){
        if (vetor[i] > maior){
            maior = vetor[i];
        }
    }
    cout<< "o maior valor encontrado no vetor e "<<maior<< endl;



    return 1;
}