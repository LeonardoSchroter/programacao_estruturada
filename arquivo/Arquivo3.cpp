#include <iostream>
#include <fstream>
#include <string>
#define TAM 10
using namespace std;
typedef struct{
    string email;
    string nome;

}agenda;


string pegarEmail(string email) {
    int posicao;
    string dominio;
    posicao=email.find(";");
    dominio= email.substr(posicao+1, 100);

    return dominio;

}
string pegarNome(string nome) {
    int posicao;
    string dominio;
    posicao=nome.find("@");
    dominio= nome.substr(0, posicao);

    return dominio;

}



int main() {
    //abrir um arquivo texto e exibir seu conteudo na tela

    //solicita pro usuario nome do arquivo origem
	char nomeArquivo[200];
	cout << "Informe nome do arquivo que quer exibir na tela: ";
	cin >> nomeArquivo;

    //abrir arquivo para leitura
	//https://www.tutorialspoint.com/cplusplus/cpp_files_streams
	ifstream procuradorArquivo; //tipo de arquivo para leitura
    procuradorArquivo.open(nomeArquivo);

    if (!procuradorArquivo) {
        cout << "Arquivo não localizado. Programa encerrado." << endl;
        exit(0);
    }


	//le o arquivo capturando as frases
	string linha;
	int posicao;
    agenda lista[3];
    int c=0;
	string nome, email;
	while (!procuradorArquivo.eof()) {
		getline(procuradorArquivo,linha); //lendo a linha inteira
		posicao = linha.find(";");
		lista[c].nome = linha.substr(0, posicao);
		lista[c].email = linha.substr(posicao+1, 200);
        c++;
        if(c==TAM){
            break;
        }
    
	}

	procuradorArquivo.close();

    for(int i=0;i<c;i++){
        cout<< lista[i].nome<<endl;
        cout<< lista[i].email<<endl;
    }

    return 1;
}