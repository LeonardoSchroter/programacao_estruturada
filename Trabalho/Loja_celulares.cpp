



#include "util.h"


int main() {
    ordem_de_servico vetor[TAM];
    
    int qtdservicos = 0;
    int opcao;
    //montar o menu
    do {
        system("cls");
        cout << "Cadastro de ordens de servico - MENU\n";
        cout << "1 - Cadastrar ordem de servico\n";
        cout << "2 - Listar ordens de servico \n";
        cout << "3 - Atualizar\n";
        cout << "4 - Pesquisar\n";
        cout << "5 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;
        fflush(stdin);

        switch (opcao)
        {
            case 1:
                cout << "INSERIR\n";
                if (inserir(vetor, &qtdservicos)) {
                    cout << "Ordem de servico cadastrada com sucesso\n";
                } else {
                    cout << "Problemas para cadastrar ordem. Falta de espaco\n";
                }
                break;
            
           

                break;
            case 2:
                cout << "LISTAR\n";
                if (listar(vetor, qtdservicos)) {
                    cout << "estas sao as ordens cadastradas\n";
                } else {
                    cout << "Estrutura vazia\n";
                }
                break;
            case 3:
                cout << "ATUALIZAR\n";
                if (atualizar(vetor, qtdservicos)) {
                    cout << "Ordem atualizada\n";
                } else {
                    cout << "Não ha ordem para atualizar.\n";
                }

                break;
            case 4:
                cout << "PESQUISAR\n";
                if (pesquisar(vetor, qtdservicos)) {
                    cout<< "aqui esta:\n";
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