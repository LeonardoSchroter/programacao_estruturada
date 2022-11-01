#include <iostream>
#include <string>
#include <cstdio>
using namespace std;

int main() {

    //variavel ponteiro guarda endereço de outra variável
    int idade;  //variável normal
    int *pIdade = NULL;//variável ponteiro que guarda o endereço da variável idade

    idade = 48;

    system("cls");
    // cout << "Conteudo da variavel idade: " << idade << endl;
    // cout << "Endereco da variavel idade: " << &idade << endl;

    // pIdade = &idade;
    // cout << "Conteudo de pIdade: " << pIdade << endl;
    // cout << "Endereco de pIdade: " << &pIdade << endl;
    // cout << "Conteudo do endereco guardado por pIdade: " << *pIdade << endl;


    
    int *vetor;
    vetor = (int *)malloc(sizeof(int) * 4);
    int *entrada = vetor;

    cout << vetor << endl;
    cout << *vetor << endl;

    for (int i = 0; i < 4; i++, vetor++) {
        *vetor = i;
    }

    // vetor = entrada;
    // for (int i = 0; i < 2; i++, vetor= vetor + 2) {
    //     cout << *vetor << endl;
    // }

    // vetor--;
    // for (int i = 0; i < 4; i++, --vetor) {
    //     cout << *vetor << endl;
    // }
    
    
    // // vetor = entrada;
    // // for (int i = 0; i < 4; i++) {
    // //     cout << vetor[i] << endl;
    // // }

    // free(vetor);


    char *letras = (char *)malloc(sizeof(char) * 4);
    cout << letras << endl;

    for (int i = 65; i < 69; i++, letras++) {
        *letras = i;
    }

    letras--;
    for (int i = 0; i < 4; i++, letras--) {
        cout << letras << ": " << *letras << endl;
    }

    return 1;
}