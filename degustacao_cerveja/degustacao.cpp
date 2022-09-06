#define TAM 10

#include "util.h"







int main() {
    Degustacao vetor[TAM];
    inicializar(vetor,TAM);
    int qtdCervejas = 0;
    int opcao;
    //montar o menu
    do {
        system("cls");
        cout << "Degustacao de cervejas - MENU\n";
        cout << "1 - Inserir\n";
        cout << "2 - Remover\n";
        cout << "3 - Atualizar\n";
        cout << "4 - Listar\n";
        cout << "5 - Pesquisar\n";
        cout << "6 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
            case 1:
                cout << "INSERIR\n";
                if (inserir(vetor, &qtdCervejas)) {
                    cout << "Cerveja cadastrada com sucesso\n";
                } else {
                    cout << "Problemas para cadastrar cerveja. Falta de espaco\n";
                }
                break;
            case 2:
                cout << "REMOVER\n";
                if (remover(vetor, &qtdCervejas)) {
                    cout << "Cerveja removido\n";
                } else {
                    cout << "Não ha cerveja para remover.\n";
                }

                break;
            case 3:
                cout << "ATUALIZAR\n";
                if (atualizar(vetor, qtdCervejas)) {
                    cout << "Cerveja atualizado\n";
                } else {
                    cout << "Não ha cerveja para atualizar.\n";
                }

                break;
            case 4:
                cout << "LISTAR\n";
                if (listar(vetor, qtdCervejas)) {
                    cout << "Cervejas cadastrados:\n";
                } else {
                    cout << "Estrutura vazia\n";
                }

                break;
            case 5:
                cout << "PESQUISAR\n";
                if (pesquisar(vetor, qtdCervejas)) {
                    cout<< "aqui esta\n";
                } else {
                    cout << "Estrutura vazia\n";
                }

                break;
            case 6:
                cout << "Obrigado por usar o sistema!\n";
                break;                
            default:
                cout << "Opcao invalida!\n";
                break;
        }
        system("pause");
    }  while (opcao != 6);
  
    return 1;
}