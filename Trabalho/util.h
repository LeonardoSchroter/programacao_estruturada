#define TAM 10
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <stdio.h>
using namespace std;
typedef struct{
    string numero;
    string data;
    string hora;
    string marca;
    string modelo;
    string descricao;
    string dono;
    string contato;
    string previsao_data;
    string previsao_hora;

}ordem_de_servico;






string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.length(); i++)
    {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}
bool verificaHora(string hora){
    if(hora[2] != ':') return false;
    return true;
}

bool validaData(string data){
    if (data == "" || data.length() != 10 || data[2] != '/' || data[5] != '/'){
        return false;
    }
    //06/09/2022
    for (int i = 0; i < data.length(); i++) {
        //cout << data[i] << " " << i << endl;
        if (data[i] == '/' && (i != 2 && i != 5)) {
            return false;
        }
    }
    int dia = stoi(data.substr(0,2));
    if (dia < 1 || dia > 31) return false;

    int mes = stoi(data.substr(3,2));
    if (mes < 1 || mes > 12) return false;

    return true;
}

bool validaNome(string nome){
    if (nome == "" || nome[0] == ' ' || nome[nome.length() ] == ' '){
        return false;
    }
    return true;
}



bool inserir(ordem_de_servico vetor[], int *qtd) {
    if (*qtd == TAM) {
        return false;
    } /*else*/
    string nome, descricao,nome_dono, contato, data;
    int numero;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i].marca == "") {
            *qtd = *qtd + 1; //(*qtd)++


            srand(time(NULL));
            for(int j=0 ; j < 10; j++){
                numero =rand() % 1000;
                vetor[i].numero= to_string(numero);
            }
            
            //recebendo um marca
           do{
            cout << "Entre com nome do marca: ";
            getline(cin, nome);
           }while(!validaNome(nome));
            
            nome = paraMaiusculo(nome);
            
            vetor[i].marca = nome;

            do{
            cout << "Entre com nome do modelo: ";
            getline(cin, nome);
           }while(!validaNome(nome));
            
            nome = paraMaiusculo(nome);
            
            vetor[i].modelo = nome;
            
            do{
                cout << "Entre com a descricao: ";
                
                getline(cin, descricao);
            }while(!validaNome(descricao));
            descricao = paraMaiusculo(descricao);
            vetor[i].descricao = descricao;

             do{
                cout << "Entre com o nome do dono: ";
                
                getline(cin, nome_dono);
            }while(!validaNome(nome_dono));
            nome_dono = paraMaiusculo(nome_dono);
            vetor[i].dono = nome_dono;

            //recebendo uma data
            do{
                cout << "Entre a data da ordem[dd/mm/aaaa]: ";
                cin>> vetor[i].data;   
            }while (!validaData(vetor[i].data));
            
            
           
            do{
                cout << "Entre a hora da ordem[hh:mm] ";
                cin >> vetor[i].hora;   
            }while(!verificaHora(vetor[i].hora));

            do{
                cout << "Entre com o contato do dono: ";
                
                getline(cin, contato);
            }while(!validaNome(contato));
            contato = paraMaiusculo(contato);
            vetor[i].contato = contato;

            do{
                cout << "Entre com a data de previsao de entrega do aparelho[dd/mm/aaaa]: ";
                
                getline(cin, data);
            }while(!validaData(data));
        
            vetor[i].previsao_data = data;

             do{
                cout << "Entre com a hora da previsao de entrega: ";
                
                getline(cin, data);
            }while(!verificaHora(data));
        
            vetor[i].previsao_hora = data;


            break;        
        }
    }
    
    return true;
}


bool listar(ordem_de_servico vetor[], int qtd) {
    if (qtd == 0) return false;

    for (int i = 0; i < TAM; i++) {
        if (vetor[i].marca != "") {
            cout << "Numero da ordem: " << vetor[i].numero << endl;
            cout << "Marca: " << vetor[i].marca << endl;
            cout << "Modelo: " << vetor[i].modelo << endl;
            cout << "Data da ordem: " << vetor[i].data << endl;
            cout << "Hora da ordem: " << vetor[i].hora << endl;
            cout << "Descricao: " << vetor[i].descricao << endl;
            cout << "Nome do dono: " << vetor[i].dono << endl;
            cout << "Contato do dono: " << vetor[i].contato << endl;
            cout << "Data da previsao " << vetor[i].previsao_data << endl;
            cout << "Hora da previsao " << vetor[i].previsao_hora << endl;
            cout << "--------------------------------------" << endl;
        }
        else{
            continue;
        }
    }
    return true;
}

bool atualizar(ordem_de_servico vetor[], int qtd){
     if (qtd==0) return false;

    cout<<"digite o numero da ordem ou contato do dono que deseja atualizar \n";
    string nome;
    
    bool encontrei;
    getline(cin,nome);
    
     
   for (int i = 0; i < TAM; i++) {
    if(nome== vetor[i].numero || nome== vetor[i].contato ){
        do{
            cout<<"digite o novo nome da marca: ";
            
            getline(cin,nome);
            
        }while(!validaNome(nome));
        vetor[i].marca= paraMaiusculo(nome);
        
        do{
            cout<<"digite o novo modelo: ";
            getline(cin,nome);
        }while(!validaNome(nome));
        vetor[i].modelo = paraMaiusculo(nome);


        do{
            cout<<"digite a nova data de ordem: ";
            cin>> vetor[i].data;
        }while(!validaData(vetor[i].data));

        do{
            cout<<"digite a nova hora da ordem: ";
            cin>> vetor[i].hora;
        }while(!verificaHora(vetor[i].hora));

        do{
            cout<<"digite a novo descricao: ";
            getline(cin,nome);
        }while(!validaNome(nome));
        vetor[i].descricao = paraMaiusculo(nome);
        
        do{
            cout<<"digite o novo nome do dono: ";
            getline(cin,nome);
        }while(!validaNome(nome));
        vetor[i].dono = paraMaiusculo(nome);

        do{
            cout<<"digite o novo contato do dono: ";
            getline(cin,nome);
        }while(!validaNome(nome));
        vetor[i].contato = nome;

        do{
            cout<<"digite a nova data de previsao: ";
            cin>> vetor[i].previsao_data;
        }while(!validaData(vetor[i].previsao_data));

        do{
            cout<<"digite a nova hora de previsao: ";
            cin>> vetor[i].previsao_hora;
        }while(!verificaHora(vetor[i].previsao_hora));
    
        return true;
       
    }

   }
   return false;

}


bool pesquisar(ordem_de_servico vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite o contato do cliente ou o numero da ordem : ";
    getline(cin,nomePesquisa);
    

    for (int i = 0; i < TAM; i++) {
        if (vetor[i].numero != ""  ) {
            if (vetor[i].numero == nomePesquisa || vetor[i].contato == nomePesquisa) {
                cout << "Numero da ordem: " << vetor[i].numero << endl;
                cout << "Marca: " << vetor[i].marca << endl;
                cout << "Modelo: " << vetor[i].modelo << endl;
                cout << "Data da ordem: " << vetor[i].data << endl;
                cout << "Hora da ordem: " << vetor[i].hora << endl;
                cout << "Descrição: " << vetor[i].descricao << endl;
                cout << "Nome do dono: " << vetor[i].dono << endl;
                cout << "Contato do dono: " << vetor[i].contato << endl;
                cout << "Data da previsao " << vetor[i].previsao_data << endl;
                cout << "Hora da previsao " << vetor[i].previsao_hora << endl;
                cout << "--------------------------------------" << endl;
            }
        }
    }
    return true;
}

