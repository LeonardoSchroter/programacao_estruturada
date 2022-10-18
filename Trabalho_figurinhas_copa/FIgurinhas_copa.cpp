#include <ctime>
#include <fstream>
#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <cstdio>
using namespace std;

typedef struct{
    string codigo;
    string jogador;
    string selecao;
    int quantidade;
    bool especial;
    float preco_estimado;
}Figurinhas;

#include "util.h"

int main() {
  Figurinhas *listaFigurasRepetidas; 
  string *listaFaltas;   
  int quantidadefiguras;
  int quantidadePresencas;
  string nomeArquivofiguras = "figuras.csv";
  string nomeArquivoPresencas = "presencas.csv";

  quantidadefiguras = contarLinhasArquivo(nomeArquivofiguras);
  quantidadePresencas = contarLinhasArquivo(nomeArquivoPresencas);
  listaFigurasRepetidas =(Figurinhas *)malloc(sizeof(Figurinhas) * (quantidadefiguras + 600));
  listaFaltas =(string *)malloc(sizeof(string) * (quantidadePresencas + 600));

  // popular lista com dados do arquivo ao iniciar o sistema
  popularListaArquivofiguras(listaFigurasRepetidas, nomeArquivofiguras);
  popularListaArquivoPresencas(listaFaltas, nomeArquivoPresencas);
  // chamar menu
  menu(listaFigurasRepetidas, listaFaltas, quantidadefiguras, quantidadePresencas,
       nomeArquivofiguras, nomeArquivoPresencas);

  return 1;
}