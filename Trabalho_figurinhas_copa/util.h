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

void popularListaArquivofiguras(Figurinhas *lista, string nomeArquivo) {
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

    int posicaoPrimeiroPontoVirgula = linha.find(";");
    int posicaoUltimoPontoVirgula = linha.find_last_of(";");
    cout << linha << endl;
    cout << "posicaoUltimoPontoVirgula: " << posicaoUltimoPontoVirgula << endl;

    nome = linha.substr(0, posicaoPrimeiroPontoVirgula);
    email = linha.substr(posicaoPrimeiroPontoVirgula + 1,
                         posicaoUltimoPontoVirgula -
                             (posicaoPrimeiroPontoVirgula + 1));
    matricula = linha.substr(posicaoUltimoPontoVirgula + 1, 200);

    lista[i].jogador = nome;
    lista[i].email = email;
    lista[i].matricula = matricula;
    i++;
  }
  procuradorLeitura.close();
}

void popularListaArquivoPresencas(string *lista, string nomeArquivo) {
  ifstream procuradorLeitura;
  procuradorLeitura.open(nomeArquivo);
  string matricula;
  int i = 0;

  string linha;
  while (!procuradorLeitura.eof()) {
    getline(procuradorLeitura, linha); // lendo a linha inteira
    if (linha == "")
      break;

    int posicaoPrimeiroPontoVirgula = linha.find(";");

    matricula = linha.substr(0, posicaoPrimeiroPontoVirgula);

    lista[i] = matricula;

    i++;
  }
  procuradorLeitura.close();
}

void exibirListaInscritos(Inscrito *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    cout << "Matricula: " << lista[i].matricula << ". Nome: " << lista[i].nome
         << ". Email: " << lista[i].email << endl;
  }
}

void exibirListaPresencas(string *lista, int qtdPresencas) {
  for (int i = 0; i < qtdPresencas; i++) {
    cout << "Matricula: " << lista[i] << endl;
  }
}

bool jaCadastrado(string email, Inscrito *lista, int qtdInscritos) {
  for (int i = 0; i < qtdInscritos; i++) {
    if (lista[i].email == email) {
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

void cadastrarNaListaInscritos(Inscrito *lista, int *qtdInscritos,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string nome, email, matricula;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);
  cout << "Inscrito sendo cadastrado na posicao " << *qtdInscritos << endl;
  do {
    cout << "Digite seu nome completo: ";
    getline(cin, nome);
    nome = paraMaiusculo(nome);
  } while (!validaNomeCompleto(nome));

  cout << "Digite seu email: ";
  cin >> email;

  cout << "Digite sua matricula: ";
  cin >> matricula;

  // teria que verificar se esse par nome e email já estão na lista
  if (jaCadastrado(email, lista, *qtdInscritos)) {
    cout << "Erro: Email ja cadastrado no sistema\n";
  } else {
    lista[*qtdInscritos].nome = nome;
    lista[*qtdInscritos].email = email;
    lista[*qtdInscritos].matricula = matricula;
    *qtdInscritos = *qtdInscritos + 1;
    // adicionar no final do arquivo
    procuradorEscrita << nome << ";" << email << ";" << matricula << endl;
  }
  procuradorEscrita.close();
}

void cadastrarNaListaPresencas(string *lista, int *qtdPresencas,
                               string nomeArquivo) {
  ofstream procuradorEscrita;
  string matricula, data;
  procuradorEscrita.open(nomeArquivo, ios::out | ios::app);

  do {
    cout << "Presenca sendo cadastrado na posicao " << *qtdPresencas << endl;

    cout << "Digite sua matricula (-27 para sair): ";
    cin >> matricula;
    if (matricula == "-27") {
      procuradorEscrita.close();
      return;
    }

    if (jaCadastradoMatricula(matricula, lista, *qtdPresencas)) {
      cout << "Erro: Matrícula ja registrada no evento\n";
    } else {
      time_t t = time(nullptr);
      tm *now = localtime(&t);

      string dia = to_string(now->tm_mday);
      string mes = to_string(now->tm_mon + 1);
      string ano = to_string(now->tm_year + 1900);

      lista[*qtdPresencas] = matricula;
      *qtdPresencas = *qtdPresencas + 1;

      // adicionar no final do arquivo
      procuradorEscrita << matricula << ";" << dia << "/" << mes << "/" << ano
                        << endl;

      procuradorEscrita.close();
    }
  } while (true);
}