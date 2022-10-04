#include <iostream>
#include <fstream>
#include <string>
using namespace std;

typedef struct{
    string nome;
    string email;
}Contato;

int contarContatosArquivo(string nomeArquivo){
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo);

    if(!procuradorArquivo){
        return 0;
    }
    int qtdContatos = 0;
    string linha;
    while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
        if(linha=="") break;
		qtdContatos++;
	}
    procuradorArquivo.close();
    return qtdContatos;
}

void popularListaArquivo(Contato *lista, string nomeArquivo){
    ifstream procuradorArquivo;
    procuradorArquivo.open(nomeArquivo);

    
    int i=0;
    string linha, nome, email;
    int posicao;
    while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
        if(linha=="") break;
        posicao = linha.find(";");
        nome = linha.substr(0, posicao);
        email = linha.substr(posicao+1, 200);

        lista[i].nome = nome;
        lista[i].email = email;
        i++;
		
	}
    procuradorArquivo.close();
   
}

void exibirLista(Contato *lista, int qtdContatos){
    for(int i=0; i < qtdContatos; i++){
        cout << "Nome: " << lista[i].nome << "  Email: " << lista[i].email << endl;
    }
}

void menu(Contato *lista, int qtdContatos){
    int opcao;
    do {
        system("cls");
        cout <<  "MENU\n";
        cout << "1 - Cadastrar contato" << endl;
        cout << "2 - Listar contatos" << endl;
        cout << "3 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao; 


        switch(opcao){
            case 1 :
                cout<<"CADASTRO DE CONTATO\n";
                break;
            case 2:
                cout << "LISTANDO CONTATOS\n";
                exibirLista(lista, qtdContatos);
                break;
            case 3:
                break; 
            default:
                cout << "OPCAO INVALIDA";
                break;
        }
        system("pause");
    } while(opcao != 3);
}

#include "util.h"

int main(){
    Contato *lista;
    int qtdContatos;

    //DESCOBRIR QUANTOS ELEMENTOS HÁ NO ARQUIVO, PARAD DEFINIR O TAMANHO DA LISTA
    qtdContatos = contarContatosArquivo("dadosTrab3.csv");
    lista = (Contato*)malloc(sizeof(Contato) * (qtdContatos+100));

    
    //Poupular a lsita
    popularListaArquivo(lista,"dadosTrab3.csv");
    
    menu(lista,qtdContatos);

    return 1;
}