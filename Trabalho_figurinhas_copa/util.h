bool validaNomeCompleto(string nome) {
  for (int i = 0; i < nome.length(); i++) {
    if (nome[i] == ' ' && (nome[i + 1] != ' ' || nome[i + 1] != '\n')) {
      return true;
    }
  }
  return false;
}

string paraMaiusculo(string frase) {
  for (int i = 0; i < frase.length(); i++) {
    frase[i] = toupper(frase[i]);
  }
  return frase;
}
   
  void splitRepetidas(FigurinhasRepetidas figuras[], string str, int i, string deli = " ") {
  int start = 0;
  int end = str.find(deli);
  

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

void splitFaltantes(FigurinhasFaltando figuras[], string str, int i,  string deli = " ") {
  int start = 0;
  int end = str.find(deli);
 
  figuras[i].codigo = str.substr(start, end - start);
  start = end + deli.size();
  end = str.find(deli, start);
  figuras[i].jogador = str.substr(start, end - start);
  start = end + deli.size();
  end = str.find(deli, start);
  figuras[i].selecao = str.substr(start, end - start);
  start = end + deli.size();
  end = str.find(deli, start);
  figuras[i].preco_estimado = stof(str.substr(start, end - start));
  start = end + deli.size();
  end = str.find(deli, start);
}


int contarLinhasArquivo(string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);

  if (!procuradorLeitura)
    return 0;

  int qtdLinhas = 0;
  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;
    qtdLinhas++;
  }
  procuradorLeitura.close();
  return qtdLinhas;
}

void popularListaArquivofigurasRepetidas(FigurinhasRepetidas *lista, string nomeArquivo, int *qtd ) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string nome, selecao ,codigo;
  int qtd;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    splitRepetidas(lista, linha, i , ";");
    i++;
  }
  procuradorLeitura.close();
}

void popularListaArquivoFigurasFaltantes(FigurinhasFaltando *lista, string nomeArquivo, int *qtd) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string nome, selecao ,codigo;
  int qtd;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    splitFaltantes(lista, linha, i , ";");
  }
  procuradorLeitura.close();
}



void exibirListaFigurasRepetidas(FigurinhasRepetidas *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    cout << "Codigo: " << lista[i].codigo << ". Jogador: " << lista[i].jogador
         << ".Selecao : " << lista[i].selecao << ".Quantidade: " << lista[i].quantidade << ".Especial: " 
         << lista[i].especial << ".Preco estimado: " << lista[i].preco_estimado << endl;
  }
}

void exibirListaFigurasFaltantes(FigurinhasFaltando *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    cout << "Codigo: " << lista[i].codigo << ". Jogador: " << lista[i].jogador
         << ".Selecao : " << lista[i].selecao << ".Especial: " 
         << lista[i].especial << ".Preco estimado: " << lista[i].preco_estimado << endl;
  }
}



bool jaCadastrado(string codigo, FigurinhasRepetidas *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    if (lista[i].codigo == codigo) {
      return true;
    }
  }
  return false;
}
bool jaCadastradoFaltantes(string codigo, FigurinhasFaltando *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    if (lista[i].codigo == codigo) {
      return true;
    }
  }
  return false;
}

bool jaCadastradoMatricula(string matricula, string *lista, int qtdPresencas) {
  for (int i = 0; i < qtdPresencas; i++) {
    if (lista[i] == matricula) {
      return true;
    }
  }
  return false;
}

void cadastrarNaListaFigurasRepetidas(FigurinhasRepetidas *lista, int *qtdFiguras,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string nome, codigo, selecao;
  bool rara = false;
  int op, quantidade;
  float precoEstimado;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
  cout << "Figura sendo cadastrada na posicao: " << *qtdFiguras << endl;
  do {
    cout << "Digite o nome do jogador: ";
    getline(cin, nome);
    nome = paraMaiusculo(nome);
  } while (!validaNomeCompleto(nome));

  cout << "Digite o codigo da figura: ";
  cin >> codigo;

  cout << "Digite a selecao: ";
  cin >> selecao;
  
  cout << "Digite o preco estimado: ";
  cin >> precoEstimado;
  
  cout << "Digite a quantidade que voce tem: ";
  cin >> quantidade;

  cout << "Digite 1 se a figura for rara e 2 para nao rara: ";

  cin >> op;

  if(op ==1){
    rara = true;
  }


  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastrado(codigo, lista, *qtdFiguras)) {
    cout << "Erro: Figura ja cadastrada no sistema\n";
  } else {
    lista[*qtdFiguras].codigo = codigo;
    lista[*qtdFiguras].selecao = selecao;
    lista[*qtdFiguras].jogador = nome;
    lista[*qtdFiguras].especial = rara;
    lista[*qtdFiguras].quantidade = quantidade;
    lista[*qtdFiguras].preco_estimado = precoEstimado;
    

    *qtdFiguras = *qtdFiguras + 1;
    // adicionar no final do arquivo
    procuradorEscrita << codigo << ";" << nome << ";" << selecao  << ";" << quantidade << ";" << rara << ";" << precoEstimado << endl;
  }
  procuradorEscrita.close();
}

void cadastrarNaListaFigurasFaltantes(FigurinhasFaltando *lista, int *qtdFiguras,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string nome, codigo, selecao;
  bool rara = false;
  int op, quantidade;
  float precoEstimado;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
  cout << "Figura sendo cadastrada na posicao: " << *qtdFiguras << endl;
  do {
    cout << "Digite o nome do jogador: ";
    getline(cin, nome);
    nome = paraMaiusculo(nome);
  } while (!validaNomeCompleto(nome));

  cout << "Digite o codigo da figura: ";
  cin >> codigo;

  cout << "Digite a selecao: ";
  cin >> selecao;
  
  cout << "Digite o preco estimado: ";
  cin >> precoEstimado;
  
  

  cout << "Digite 1 se a figura for rara e 2 para nao rara: ";

  cin >> op;

  if(op ==1){
    rara = true;
  }


  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastradoFaltantes(codigo, lista, *qtdFiguras)) {
    cout << "Erro: Figura ja cadastrada no sistema\n";
  } else {
    lista[*qtdFiguras].codigo = codigo;
    lista[*qtdFiguras].selecao = selecao;
    lista[*qtdFiguras].jogador = nome;
    lista[*qtdFiguras].especial = rara;
    lista[*qtdFiguras].preco_estimado = precoEstimado;
    

    *qtdFiguras = *qtdFiguras + 1;
    // adicionar no final do arquivo
    procuradorEscrita << codigo << ";" << nome << ";" << selecao  << ";" << quantidade << ";" << rara << ";" << precoEstimado << endl;
  }
  procuradorEscrita.close();
}

void menu(FigurinhasRepetidas *listaFigurasRepetidas, FigurinhasFaltando *listaFigurasFaltantes, int qtdInscritos,
          int qtdPresencas, string nomeArquivoFigurasRepetidas,
          string nomeArquivoFigurasFaltantes) {
  int opcao;
  int tecla;
  do {
    // system("clear");
    cout << "MENU\n";
    cout << "1 - Cadastrar figuras repetidas\n";
    cout << "2 - Cadastrar figurinhas faltando\n";
    cout << "3 - Listar Repetidas\n";
    cout << "4 - Listar Faltando\n";
    cout << "5 - Sair\n";
    cout << "Opcao: ";
    cin >> opcao;
    cin.ignore();

    switch (opcao) {
    case 1:
      cout << "CADASTRAR\n";
      cadastrarNaListaFigurasRepetidas(listaFigurasRepetidas, &qtdInscritos,
                                nomeArquivoFigurasRepetidas);
      break;
    case 2:
      cout << "LISTAGEM DE REPETIDAS\n";
      exibirListaFigurasRepetidas(listaFigurasRepetidas, qtdInscritos);
      break;
    case 3:
      cout << "REGISTRAR FALTANTES\n";
      cadastrarNaListaFigurasFaltantes(listaFigurasFaltantes, &qtdPresencas,
                                nomeArquivoFigurasFaltantes);
      break;
    case 4:
      cout << "LISTAGEM DE FALTANTES\n";
      exibirListaFigurasFaltantes(listaFigurasFaltantes, qtdPresencas);
      break;
    case 5:
      break;
    default:
      cout << "Opcao invalida!!\n";
      break;
    }

    // system("sleep 10s");

  } while (opcao != 5);
}