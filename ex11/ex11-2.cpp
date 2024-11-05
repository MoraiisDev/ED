#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

typedef struct Pessoa pessoa;
struct Pessoa {
    string cpf;
    string nome;
    string email;
    string telefone;
    pessoa *prox;
};

pessoa *primeiro; // armazena o primeiro
pessoa *ultimo;   // armazena o ultimo

pessoa *lerPessoa() {
    pessoa *novaPessoa = new pessoa;
    cout << "Digite o CPF: ";
    cin >> novaPessoa->cpf;
    cout << "Digite o nome: ";
    cin.ignore();
    getline(cin, novaPessoa->nome);
    cout << "Digite o e-mail: ";
    getline(cin, novaPessoa->email);
    cout << "Digite o telefone: ";
    getline(cin, novaPessoa->telefone);
    novaPessoa->prox = NULL;
    return novaPessoa;
}

void construtor() {
    primeiro = ultimo = NULL;
}

void inserir(pessoa *novaPessoa) {
    if (novaPessoa == NULL) {
        cout << "Erro ao inserir pessoa!" << endl;
        return;
    }

    if (primeiro == NULL)
        primeiro = novaPessoa;
    else
        ultimo->prox = novaPessoa;

    ultimo = novaPessoa;
}

void remover() {
    if (primeiro == NULL) {
        cout << "A fila está vazia." << endl;
        return;
    }

    pessoa *temp = primeiro;
    cout << "Removendo a pessoa com CPF: " << temp->cpf << endl;
    primeiro = temp->prox;
    delete temp;
}

void plotar() {
    pessoa *temp = primeiro;
    system("clear");
    while (temp != NULL) {
        cout << "CPF: " << temp->cpf << endl;
        cout << "Nome: " << temp->nome << endl;
        cout << "E-mail: " << temp->email << endl;
        cout << "Telefone: " << temp->telefone << endl;
        temp = temp->prox;
    }
    cout << "Fim do relatório" << endl;
    system("sleep 5");
}

void destrutor() {
    pessoa *temp = primeiro;
    pessoa *aux;
    if (primeiro == NULL) return;
    while (temp != NULL) {
        aux = temp;
        temp = temp->prox;
        delete aux;
    }
    primeiro = ultimo = NULL;
    cout << "A fila foi removida da memória...!" << endl;
    system("sleep 3");
}

int main() {
    int tela;
    construtor();
    while (true) {
        system("clear");
        cout << "1 - Inserir\n2 - Remover\n3 - Plotar\n4 - Destruir\n5 - Sair\nItem> ";
        cin >> tela;
        switch (tela) {
            case 1: {
                pessoa *novaPessoa = lerPessoa();
                inserir(novaPessoa);
                break;
            }
            case 2:
                remover();
                break;
            case 3:
                plotar();
                break;
            case 4:
                destrutor();
                break;
            case 5:
                destrutor();
                exit(0);
                break;
            default:
                cout << "Opção inválida!" << endl;
        }
    }
    return 0;
}