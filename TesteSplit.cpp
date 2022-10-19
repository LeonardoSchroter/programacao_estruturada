#include <bits/stdc++.h>
#include <cstdio>
#include <cstdlib>
#include <fstream>
#include <iostream>
#include <sstream>

using namespace std;

typedef struct {
  string codigo;
  string jogador;
  string selecao;
  int quantidade;
  bool especial;
  float preco_estimado;
} FigurinhasRepetidas;

void splitstr(string str, string deli = " ") {
  int start = 0;
  int end = str.find(deli);
  while (end != -1) {
    cout << str.substr(start, end - start) << endl;
    start = end + deli.size();
    end = str.find(deli, start);
  }
  cout << str.substr(start, end - start);
}

void split(FigurinhasRepetidas figuras[5], string str, string deli = " ") {
  int start = 0;
  int end = str.find(deli);
  int i = 0;

  figuras[i].codigo = str.substr(start, end - start);
  start = end + deli.size();
  end = str.find(deli, start);
  figuras[i].jogador = str.substr(start, end - start);
  start = end + deli.size();
  end = str.find(deli, start);
  figuras[i].selecao = str.substr(start, end - start);
  start = end + deli.size();
  end = str.find(deli, start);
  figuras[i].quantidade = stoi(str.substr(start, end - start));
  start = end + deli.size();
  end = str.find(deli, start);
  figuras[i].preco_estimado = stof(str.substr(start, end - start));
  start = end + deli.size();
  end = str.find(deli, start);
}

int main() {
  string s = "codigo;jogador;selecao;20;60"; // Take any string
                                             // with any delimiter
  FigurinhasRepetidas figuras[5];
  string vetor[6];
  split(figuras, s, ";");
  for (int i = 0; i < 1; i++) {
    cout << figuras[i].codigo << endl;
    cout << figuras[i].jogador << endl;
    cout << figuras[i].selecao << endl;
    cout << figuras[i].preco_estimado << endl;
    cout << figuras[i].quantidade << endl;
    
  }

  return 0;
}