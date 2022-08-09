/*3 - Escreva um algoritmo para calcular o reajuste salarial de uma empresa que possui 1000 
 * funcionários, de acordo com os seguintes critérios:
 *	• os funcionários com salário inferior a 10.000 devem receber 55% de reajuste
 *	• os funcionários com salário entre 10.000 e 25.000 devem receber 30% de reajuste.
 *	• os funcionários com salário acima de 25.000 devem receber 20% de reajuste.*/
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>
#define N 1000

using namespace std;

int main(){
    float salario,salarioInicial;
    for(int i=0; i<N ; i++){
    
    cout << "digite seu salario \n";
    cin >> salarioInicial;

    
        if (salarioInicial<10000){
            salario= salarioInicial*1.55;
        }
        else if ( salarioInicial< 25000){
            salario= salarioInicial*1.3;
        }
        else if (salarioInicial> 25000){
            salario= salarioInicial*1.2;
        }

    

        
        cout << "Seu novo salario eh: " << salario << endl;
    }


    return 1;
}
