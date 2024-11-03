#include <iostream>
#include <cstdlib>
#include <cstring>
using namespace std;

typedef struct nopilha pilha;

struct nopilha {
    char nome[50];
    float salario;
    pilha *ant;
};

pilha *topo = NULL;

void push(const char *nome, float salario) {
    pilha *newpilha = (pilha *) malloc(sizeof(pilha));
    if (newpilha == NULL) { 
        cout << "Não tem mais memória!" << endl;
        system("sleep 2");
        return;
    }
    strncpy(newpilha->nome, nome, sizeof(newpilha->nome));
    newpilha->nome;
    newpilha->salario = salario;
    newpilha->ant = topo;
    topo = newpilha;
}

void pop() {
    if (topo == NULL) {
        cout << "A pilha já está vazia!" << endl;
        system("sleep 2");
        return;
    }
    pilha *temp = topo;
    topo = temp->ant;
    free(temp);
}

void exibir() {
    pilha *temp = topo;
    system("clear");
    cout << "Pilha de pessoas:\n";
    while (temp != NULL) {
        cout << "Nome: " << temp->nome << ", Salário: " << temp->salario << endl;
        temp = temp->ant;
    }
    system("sleep 4");
}

void destrutor() { 
    pilha *temp, *aux;
    temp = topo;
    while (temp != NULL) {
        aux = temp;
        temp = temp->ant;
        free(aux);
    }
    topo = NULL;
    system("clear");
    cout << "\nA pilha foi destruída!\n";
    system("sleep 2");
}

int main() {
    int opcao;
    char nome[50];
    float salario;

    do {
        system("clear");
        cout << "Menu da Pilha de Pessoas (LIFO):\n";
        cout << "1. Empilhar Pessoa (push)\n";
        cout << "2. Desempilhar Pessoa (pop)\n";
        cout << "3. Exibir a pilha\n";
        cout << "4. Destruir a pilha\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;
        cin.ignore();

        switch (opcao) {
            case 1:
                cout << "Digite o nome: ";
                cin.getline(nome, 50);
                cout << "Digite o salário: ";
                cin >> salario;
                push(nome, salario);
                break;
            case 2:
                pop();
                break;
            case 3:
                exibir();
                break;
            case 4:
                destrutor();
                break;
            case 5:
                cout << "Obrigado por utilizar o programa!\n";
                break;
            default:
                cout << "Insira um valor válido!\n";
                system("sleep 2");
        }
    } while (opcao != 5);

    return 0;
}