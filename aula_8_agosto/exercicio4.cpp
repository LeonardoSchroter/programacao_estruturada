/**
 * 4 - Faça um programa que leia uma palavra qualquer e depois mostre apenas as vogais.
 */ 
#include<iostream>
#include<string>
#include <cstdlib>
#include <ctime>


using namespace std;

int main(){
    string palavra;
    int c=0;
    char vogais[5];

    cout << "Digite uma palavra" << endl;
    cin>> palavra;

    for( int i = 0 ; i < palavra.length(); i++){
        if (palavra[i] == 'a' 
        ||palavra[i] == 'e' 
        ||palavra[i] == 'i' 
        || palavra[i] == 'o' 
        ||palavra[i] == 'u')
        {
            vogais[c++]= palavra[i];
           
        }
    }
    cout << "estas sao as vogais: " ;
    for(int i=0; i<5; i++){
        cout<< vogais[i] << endl;
    }

    return 1;
}