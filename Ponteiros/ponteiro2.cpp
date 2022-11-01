#include <iostream>
#include <string.h>
#include <cstdio>
using namespace std;


typedef struct {
    int matricula;
    char nome[100];
} Aluno;

int main() {
    Aluno *lista = (Aluno *)malloc(sizeof(Aluno));
    Aluno *entrada = lista;
    int opcao;
    int quantidade = 1;
    do  {
        cout << "Nome: ";
        cin >> lista->nome;

        cout << "Matricula: ";
        cin >> lista->matricula;
        cout << "1 - para: ";
        cin >> opcao;
        if (opcao == 1)
            break;
        lista++;
        quantidade++;
    } while (true);
    
    lista = entrada;
    for (int i = 0; i < quantidade; lista++) {
        cout << lista->nome << endl;
        cout << lista->matricula << endl;
    }

   

    return 1;
}