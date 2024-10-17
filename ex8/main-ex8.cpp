/*
II - Faça um programa com menu de três opções (1-ler linha, 2- mostrar e 3- sair), contendo um STRUCT para
cadastrar o nome, à idade, o sexo, salário e salarioNovo de pelo menos duas pessoas. Crie um ponteiro para
manipular o STRUCT. O programa deverá conter as seguintes sub rotinas abaixo: (use switch case)
a) void NovaLinhaStruct ()
b) void listarLinhasStruct ()
e) ler idade ()
d) lersexo()
e) lernome()
f) lersalario ()
g) getAumento ( double * salario ) // aumento de 10% sobre o salário digitado
*/

#include <iostream>
#include <string>
using namespace std;

struct Pessoa {
    string nome;
    int idade;
    char sexo;
    double salario;
    double salarioNovo;
};

void NovaLinhaStruct(Pessoa * pessoas, int total);
void listarLinhasStruct(Pessoa * pessoas, int total);
void lerIdade(int &idade);
void lerSexo(char &sexo);
void lerNome(string &nome);
void lerSalario(double &salario);
void getAumento(double* salario);

int main() {
    int totalPessoas;  

    cout << "Digite o número de pessoas para cadastrar: ";
    cin >> totalPessoas;

    Pessoa * pessoas = new Pessoa[totalPessoas];
    int opcao;

    do {
        cout << "\nMenu de Opções:\n";
        cout << "1 - Ler Linha\n";
        cout << "2 - Mostrar Linhas\n";
        cout << "3 - Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                NovaLinhaStruct(pessoas, totalPessoas);
                break;
            case 2:
                listarLinhasStruct(pessoas, totalPessoas);
                break;
            case 3:
                cout << "Obrigado por utilizar o programa!\n";
                break;
            default:
                cout << "Opção inválida, tente novamente.\n";
                break;
        }
    } while (opcao != 3);
    
    delete[] pessoas;

    return 0;
}

void NovaLinhaStruct(Pessoa * pessoas, int total) {
    for (int i = 0; i < total; i++) {
        cout << "\nCadastro da Pessoa " << i + 1 << ":\n";
        lerNome(pessoas[i].nome);
        lerIdade(pessoas[i].idade);
        lerSexo(pessoas[i].sexo);
        lerSalario(pessoas[i].salario);
        getAumento(&pessoas[i].salario);  
        pessoas[i].salarioNovo = pessoas[i].salario;
    }
}

void listarLinhasStruct(Pessoa * pessoas, int total) {
    for (int i = 0; i < total; i++) {
        cout << "\nDados da Pessoa " << i + 1 << ":\n";
        cout << "Nome: " << pessoas[i].nome << "\n";
        cout << "Idade: " << pessoas[i].idade << "\n";
        cout << "Sexo: " << pessoas[i].sexo << "\n";
        cout << "Salário: R$ " << pessoas[i].salarioNovo << "\n";
    }
}

void lerIdade(int &idade) {
    cout << "Digite a idade: ";
    cin >> idade;
}

void lerSexo(char &sexo) {
    cout << "Digite o sexo (M/F): ";
    cin >> sexo;
}

void lerNome(string &nome) {
    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, nome);
}

void lerSalario(double &salario) {
    cout << "Digite o salário: ";
    cin >> salario;
}

void getAumento(double* salario) {
    *salario += *salario * 0.10;
    cout << "Salário com aumento de 10%: R$ " << *salario << "\n";
}