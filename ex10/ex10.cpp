#include <iostream>
#include <cstdlib>
#include <stdlib.h>
using namespace std;

typedef struct nopilha pilha;

struct nopilha {
    int valor;
    pilha *ant;
};

pilha *topo = NULL;

void push(int valor) {
    pilha *newpilha = (pilha *) malloc(sizeof(pilha));
    if (newpilha == NULL) { 
        cout << "Não tem mais memória!" << endl;
        system("sleep 2");
        return;
    }
    newpilha->valor = valor;
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
    while (temp != NULL) {
        cout << "\n" << temp->valor << endl;
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
    int opcao, valor;

    do {
        system("clear");
        cout << "Menu da Pilha (LIFO):\n";
        cout << "1. Empilhar (push)\n";
        cout << "2. Desempilhar (pop)\n";
        cout << "3. Exibir a pilha\n";
        cout << "4. Destruir a pilha\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                cout << "Digite um valor para empilhar: ";
                cin >> valor;
                push(valor);
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