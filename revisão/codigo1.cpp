#include<iostream>
#include<string>

using namespace std;

int main(){
    cout<<"ola turma"<<"\n"; //equivale ao printf ou puts

    string nome;

    cout<<"digite seu nome: ";
    cin>>nome; //equivale ao scanf
    


    cout<<nome<<endl;
    cout<<"o nome digitado tem "<< nome.size() <<" caracteres \n";
    




    return 1;
}