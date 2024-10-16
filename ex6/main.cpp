#include <iostream>
#include <string>
#define max 3 // Tamanho máximo da pilha

using namespace std;

typedef struct registro {
    string nome;
    int idade;
    float salario;
} Registro;

struct lifo {
    int topo;
    Registro dados[max];
};

// Função para ler um registro (nome, idade, salário)
Registro lerRegistro() {
    Registro reg;
    cout << "\nDigite o nome: ";
    cin >> reg.nome;
    cout << "Digite a idade: ";
    cin >> reg.idade;
    cout << "Digite o salário: ";
    cin >> reg.salario;
    return reg;
}

// Verifica se a pilha está cheia
bool pilhaCheia(lifo p) {
    if (p.topo == max - 1) return true;
    return false;
}

// Verifica se a pilha está vazia
bool pilhaVazia(lifo p) {
    if (p.topo == -1) return true;
    return false;
}

// Empilha um novo registro
lifo push(Registro reg, lifo p) {
    if (pilhaCheia(p)) {
        cout << "\nPilha Cheia\n";
        //system("pause");
        return p;
    }

    p.topo++;
    p.dados[p.topo] = reg;
    cout << "\nRegistro empilhado com sucesso!\n";
    //system("pause");
    return p;
}

// Desempilha o último registro
lifo pop(lifo p) {
    if (pilhaVazia(p)) {
        cout << "\nA pilha já está vazia!\n";
        //system("pause");
        return p;
    }

    cout << "\nO registro desempilhado foi: " << p.dados[p.topo].nome << endl;
    p.dados[p.topo].nome = ""; // Apaga os dados (opcional)
    p.dados[p.topo].idade = 0;
    p.dados[p.topo].salario = 0.0;
    p.topo--;
    //system("pause");
    return p;
}

// Mostra todos os registros da pilha
void mostrarPilha(lifo p) {
    if (pilhaVazia(p)) {
        cout << "\nA pilha está vazia!\n";
        //system("pause");
        return;
    }

    cout << "\nRegistros na pilha:\n";
    for (int i = p.topo; i >= 0; i--) {
        cout << "Nome: " << p.dados[i].nome << ", Idade: " << p.dados[i].idade << ", Salário: " << p.dados[i].salario << endl;
    }
    //system("pause");
}

// Exibe o menu e captura a escolha do usuário
int tela() {
    int tecla;
    //system("cls");
    cout << "\nMenu\n1 - Empilhar (Push)\n2 - Desempilhar (Pop)\n3 - Mostrar pilha\n4 - Sair\nEscolha: ";
    cin >> tecla;
    return tecla;
}

// Controla o menu de controle da LIFO
void controlarPilha(lifo p) {
    int tecla;
    Registro reg;
    p.topo = -1; // Inicializa a pilha

    do {
        tecla = tela();
        switch (tecla) {
            case 1:
                reg = lerRegistro();
                p = push(reg, p);
                break;
            case 2:
                p = pop(p);
                break;
            case 3:
                mostrarPilha(p);
                break;
        }
    } while (tecla != 4);

    cout << "\nPrograma Finalizado...!\n";
}

int main() {
    lifo p1;
    controlarPilha(p1);
    return 0;
}
