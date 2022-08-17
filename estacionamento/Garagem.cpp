#include <iostream>
#include <string>
#include <cstdlib>
#include <sstream>
#include <ctime>
#define TAM 10

using namespace std;

typedef struct {
    string placa;
    string data;
    int horaE;
    int horaS;
    int tempoPermanecia;
    float valor;
} Garagem;

int main() {
    bool encontrei=false;
    int opcao;
    string horarioAtual;
    string horaAtual;
    
    string placa;
    Garagem lista[TAM];
    int totalVeiculos = 0, ultimaVaga=-1;
    
    
    do {
        system("cls");
        cout << "Menu Garagem\n";
        cout << "1 - Entrada veiculo\n";
        cout << "2 - Saida veiculo\n";
        cout << "3 - Lista veiculos em garagem\n";
        cout << "4 - Sair\n";
        cout << "Opcao: ";
        cin >> opcao;

        switch (opcao)
        {
        case 1:
            cout << "Entrando veiculo....\n";
            if (totalVeiculos == TAM) {
                cout << "Garagem lotada\n";
            } 
            
            else {
                totalVeiculos++;
                ultimaVaga++;
                
                

                do{
                    
                    cout <<  "informe a placa do veiculo: ";
                    cin >> lista[ultimaVaga].placa;
                }while (lista[ultimaVaga].placa.length() != 7);
                do{
                    cout << "Digite a data [dd/mm/aaaa]: "; 
                    cin >> lista[ultimaVaga].data;
                } while (lista[ultimaVaga].data.length() != 10);
                
                do{
                    cout << "Digite a hora de entrada[hh:mm]: "; 
                    cin >>  horaAtual;

                    string horaE= horaAtual.substr(0,2);
                    string minE= horaAtual.substr(3,2);
                    lista[ultimaVaga].horaE= stoi(horaE) * 60 + stoi(minE) ;
                    if(lista[ultimaVaga].horaE<=430 || lista[ultimaVaga].horaE>=1320){
                        cout<< "estamos fechados, volte outra hora\n";
                        lista[ultimaVaga].placa=nullptr;
                        lista[ultimaVaga].data=nullptr;
                        lista[ultimaVaga].horaE=0;
                        ultimaVaga--;
                        totalVeiculos--;
                       

                }

                 } while (horaAtual.length() != 5);

                
                    
               
            }
            break;
        case 2:
            cout << "Saindo veiculo....\n";
            if (totalVeiculos == 0) {
                cout << "Garagem vazia\n";
            } else {
                 cout << "digite a placa de seu veiculo\n ";
                cin >> placa;

                for (int i = 0; i < totalVeiculos; i++) {
                    if (placa == lista[i].placa) {
                        cout << "Que horas sao?\n";
                        cin>> horarioAtual;

                        string horaS= horarioAtual.substr(0,2);
                        string minS=horarioAtual.substr(3,2);
                          lista[i].horaS= stoi(horaS) * 60 + stoi(minS) ;
                          lista[i].tempoPermanecia= lista[i].horaS - lista[i].horaE;
                       

                        cout<< "voce ficou aqui: "<< lista[i].tempoPermanecia<<" min \n";
                        cout << "Adeus " ;
                        lista[i].placa=nullptr;
                        lista[i].data=nullptr;
                        lista[i].horaE=0;
                        lista[i].horaS=0;
                        totalVeiculos--;
                        encontrei=true;
                        
                    
                    }
                }
                if (!encontrei){
                    cout <<"esta placa não existe\n";
                }
                //desafio
            }
            break;
        case 3:
            cout << "Listando garagem....\n";
            if (totalVeiculos == 0) {
                cout << "Garagem vazia\n";
            } else {
                for (int i = 0; i <= totalVeiculos; i++) {
                    cout << "placa: " << lista[i].placa << ". Data: " << lista[i].data << ". Hora: " << lista[i].horaE << endl;
                }
                
            }
            break;
        case 4:
            cout << "Obrigado por usar o sistema\n";            
            break;
        
        default:
            cout << "Opcao invalida!\n";
            break;
        }
        system("pause");
    } while (opcao != 4);
    return 1;
    
}