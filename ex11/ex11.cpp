#include <iostream>
#include "cstdlib"
using namespace std;
 
typedef struct fifo fila;
struct fifo {
    int valor;
    fifo * prox;    
};
 
fila * primeiro; // armazena o primeiro
fila * ultimo;   // armazena o ultimo
 
int lervalor () {
    int n;
    cout << "Digite o valor a ser enfileirado:";
    cin >> n;
    return n;
}
 
void construtor() {
    primeiro = ultimo = NULL;
}
 
void inserir ( int valor ) {
    fila * newFila = (fila *) malloc ( sizeof ( fila ) );
    if (newFila == NULL){ 
        cout << "Erro!Sem memória!"<< endl; 
        system("sleep 2"); 
        return; 
    }
    newFila->valor = valor; 
    newFila->prox = NULL;
 
    if ( primeiro == NULL)
        primeiro = newFila;
     else 
        ultimo->prox =newFila; 
     ultimo = newFila;
}

void remover () {
    if ( primeiro == NULL) return;
 
    fila * temp = primeiro;
    cout << "O valor desenfileirado será " << temp->valor << endl;
    system("sleep 2");
    primeiro = temp->prox; 
    free(temp); // remover o ponteiro da memória
}
 
void plotar () {
    fila * temp = primeiro;
    system("clear");
    while ( temp != NULL ) {
        cout << temp->valor << endl;
        temp=temp->prox;
    }
    cout << "Fim do relatório" << endl;
    system("sleep 5");
}
 
void destrutor () {
    fila * temp = primeiro;
    fila * aux; 
    if (primeiro == NULL) return;
    while (temp != NULL) {
        aux = temp; 
        temp = temp->prox;
        free ( aux );
    }
    cout << "A fila já foi removida da memória...!" << endl;
    system("sleep 3");
}
 
int main() {
    int tela, valor;
    while (true)
    {   system("clear");
        cout << "1 - Inserir\n2 - Remover\n3 - Plotar\n4 - Destruir\n5 - Sair\nItem>";
        cin >> tela;
        switch (tela)
        {
            case 1: valor = lervalor(); 
                    inserir ( valor );
                    break;
            case 2: remover();
                    break;
            case 3: plotar();
                    break;
            case 4: destrutor();
                    break;
            case 5: exit(0); break;
        }
    }
    return 0;
}