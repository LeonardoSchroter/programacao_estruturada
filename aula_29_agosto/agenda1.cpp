#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#define TAM 10


using namespace std;


typedef struct{
    string name;
    string email;
    string telefone;
}Contato;


#include "util.h"


int main(){
    int opcao;
    Contato vetor[TAM];
    int qtdContatos = 0;
        
        
        do{
    
            system("cls");
            cout << "Menu agenda\n";
            cout << "1 - Inserir\n";
            cout << "2 - Remover\n";
            cout << "3 - Atualizar\n";
            cout << "4 - Listar\n";
            cout << "5 - Pesquisar\n";
            cout << "6 - Sair\n";
            cout << "Opcao: ";
            cin >> opcao;

            switch (opcao){
                case 1:

                    if(qtdContatos==TAM){
                        cout<<"Nao ha mais espaco";
                        break;
                    }
                    else{
                        cout << "Inserindo contato\n";
                    

                        cout << "Digite o seu nome completo \n";
                        getline(cin, vetor[qtdContatos].name);
                        vetor[qtdContatos].name = paraMaiusculo(vetor[qtdContatos].name);
                        cout<< vetor[qtdContatos].name;
                        cout << "Digite o seu email \n";
                        cin >> vetor[qtdContatos].email;
                        cout << "Digite o seu nome telefone \n";
                        cin >> vetor[qtdContatos].telefone;
                        break;
                    }

                case 2:

                    break;

                case 3:

                    break;


                case 4:

                    break;

                case 5:

                    break;


                case 6:

                    break;


                default:
                    cout<<"obrigado por usar o sistema";
                    break;


                






            }
        }while(opcao !=6);
    




    return 0;
}