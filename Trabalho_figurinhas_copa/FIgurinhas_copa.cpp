#include <ctime>
#include <fstream>
#include <iostream>
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
}FigurinhasRepetidas;
typedef struct{
    string codigo;
    string jogador;
    string selecao;
    bool especial;
    float preco_estimado;
}FigurinhasFaltando;

#include "util.h"

int main() {
  FigurinhasRepetidas *listaFigurasRepetidas; 
  FigurinhasFaltando *listaFigurasFaltantes;   
  int quantidadefigurasRepetidas;
  int quantidadeFigurasFaltantes;
  string nomeArquivofigurasRepetidas = "figurasRepetidas.csv";
  string nomeArquivoFigurasFaltantes = "figurasFaltando.csv";

  quantidadefigurasRepetidas = contarLinhasArquivo(nomeArquivofigurasRepetidas);
  quantidadeFigurasFaltantes = contarLinhasArquivo(nomeArquivoFigurasFaltantes);
  listaFigurasRepetidas =(FigurinhasRepetidas *)malloc(sizeof(FigurinhasRepetidas) * (quantidadefigurasRepetidas + 600));
  listaFigurasFaltantes =(FigurinhasFaltando *)malloc(sizeof(FigurinhasFaltando) * (quantidadeFigurasFaltantes + 600));

  // popular lista com dados do arquivo ao iniciar o sistema
  popularListaArquivofigurasRepetidas(listaFigurasRepetidas, nomeArquivofigurasRepetidas);
  popularListaArquivoFigurasFaltantes(listaFaltas, nomeArquivoFigurasFaltantes);
  // chamar menu
  menu(listaFigurasRepetidas, listaFaltas, quantidadefiguras, quantidadePresencas,
       nomeArquivofiguras, nomeArquivoPresencas);

  return 1;
}