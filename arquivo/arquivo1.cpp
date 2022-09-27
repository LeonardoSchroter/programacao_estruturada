#include <iostream>
#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    FILE *procurador;
    char nomeArquivo[200];
    cout<<"digite o nome do arquivo";
    cin >> nomeArquivo;
    procurador= fopen(nomeArquivo,"a");
    char nome[100], email[100], opcao;

    do{
        cout << "Nome: ";
        cin >> nome;
        cout << "Email:";
        cin>> email;
        fprintf(procurador,"%s;%s \n",nome,email);
        fflush(procurador); //garante a gravação do arquivo
        cout << "1-continuar\n2-sair";
        cin >> opcao;
    }while(opcao=='1');

    fclose(procurador);


    return 1;
}