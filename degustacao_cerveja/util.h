#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#include <cstdio>
#include <stdio.h>

#define TAM 10
using namespace std;

typedef struct{
    string fabricante;
    string tipoCerveja;
    string dataDegustacao;
    int nota;
}Degustacao;


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





string paraMaiusculo(string frase) {
    for (int i = 0; i < frase.length(); i++)
    {
        frase[i] = toupper(frase[i]);
    }
    return frase;
}

bool verificaData(string data){
    if(data.length() == 10){
        return true;
    }
    return false;
}

bool verificaNota(int nota){
    if (nota>= 0 && nota<=5){
        return true;
    }
    return false;
}



void inicializar(Degustacao vetor[], int n) {
    for (int i = 0; i < n; i++) {
        vetor[i].fabricante = "";
        vetor[i].tipoCerveja = "";
        vetor[i].dataDegustacao = "";
        vetor[i].nota = 0;
    }
}
bool validaNome(string nome){
    if (nome == "" || nome[0] == ' ' || nome[nome.length() ] == ' '){
        return false;
    }
    return true;
}



bool inserir(Degustacao vetor[], int *qtd) {
    if (*qtd == TAM) {
        return false;
    } /*else*/
    string nome, tipo;
    for (int i = 0; i < TAM; i++) {
        if (vetor[i].fabricante == "") {
            *qtd = *qtd + 1; //(*qtd)++
            
            //recebendo um nome
           do{
            cout << "Entre com nome do fabricante: ";
            getline(cin, nome);
           }while(!validaNome(nome));
            
            nome = paraMaiusculo(nome);
            
            vetor[i].fabricante = nome;

            //recebendo um tipo
            do{
                cout << "Entre com tipo de cerveja: ";
                
                getline(cin, tipo);
            }while(!validaNome(tipo));
            tipo = paraMaiusculo(tipo);
            vetor[i].tipoCerveja = tipo;

            //recebendo uma data
            do{
                cout << "Entre a data da degustacao[dd/mm/aaaa]: ";
                cin>> vetor[i].dataDegustacao;   
            }while (!validaData(vetor[i].dataDegustacao));
            
            
            //recebendo uma nota
            do{
                cout << "Entre a nota para a cerveja[0 a 5]: ";
                cin >> vetor[i].nota;   
            }while(!verificaNota(vetor[i].nota));
            break;        
        }
    }
    
    return true;
}

bool listar(Degustacao vetor[], int qtd) {
    if (qtd == 0) return false;

    for (int i = 0; i < TAM; i++) {
        if (vetor[i].fabricante != "") {
            cout << "Fabricante: " << vetor[i].fabricante << endl;
            cout << "Tipo da cerveja: " << vetor[i].tipoCerveja << endl;
            cout << "Data de degustacao: " << vetor[i].dataDegustacao << endl;
             cout << "Nota: " << vetor[i].nota << endl;
            cout << "--------------------------------------" << endl;
        }
        else{
            continue;
        }
    }
    return true;
}

bool remover(Degustacao vetor[], int *qtd){
    
    if (*qtd==0) return false;

    cout<<"digite o nome de fabricante que deseja remover \n";
    string nome;
    bool encontrei;
    getline(cin,nome);
    nome = paraMaiusculo(nome);

   for (int i = 0; i < *qtd; i++) {
    if(nome== vetor[i].fabricante){
        vetor[i].fabricante="";
        vetor[i].tipoCerveja="";
        vetor[i].dataDegustacao="";
        vetor[i].nota=0;
        *qtd = *qtd - 1;
        return true;
       
    }

   }
   return false;
}

bool atualizar(Degustacao vetor[], int qtd){
     if (qtd==0) return false;

    cout<<"digite o nome do fabricante que deseja atualizar \n";
    string nome;
    string fabricante;
    string tipo;
    bool encontrei;
    getline(cin,nome);
    nome = paraMaiusculo(nome);
     
   for (int i = 0; i < qtd; i++) {
    if(nome== vetor[i].fabricante){
        do{
            cout<<"digite o novo nome de fabricante: ";
            
            getline(cin,fabricante);
            
        }while(!validaNome(fabricante));
        vetor[i].fabricante= paraMaiusculo(fabricante);
        
        do{
            cout<<"digite o novo tipo: ";
            getline(cin,tipo);
        }while(!validaNome(tipo));
        vetor[i].tipoCerveja = paraMaiusculo(tipo);


        do{
            cout<<"digite a nova data de degustacao: ";
            cin>> vetor[i].dataDegustacao;
        }while(!validaData(vetor[i].dataDegustacao));
        
        do{
            cout<<"digite a nova nota: ";
            cin>> vetor[i].nota;
        }while(!verificaNota(vetor[i].nota));
    
        return true;
       
    }

   }
   return false;

}

bool pesquisar(Degustacao vetor[], int qtd) {
    if (qtd == 0) return false;
    string nomePesquisa;
    cout << "Digite o tipo da cerveja: ";
    getline(cin,nomePesquisa);
    nomePesquisa = paraMaiusculo(nomePesquisa);

    for (int i = 0; i < TAM; i++) {
        if (vetor[i].tipoCerveja != "") {
            if (vetor[i].tipoCerveja.find(nomePesquisa) != -1) {
                cout << "Fabricante: " << vetor[i].fabricante << endl;
                cout << "Tipo decerveja: " << vetor[i].tipoCerveja << endl;
                cout << "Data de degustacao: " << vetor[i].dataDegustacao << endl;
                cout << "Nota: " << vetor[i].nota << endl;
                cout << "--------------------------------------" << endl;
            }
        }
    }
    return true;
}