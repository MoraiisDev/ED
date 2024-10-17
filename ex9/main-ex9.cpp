#include <iostream>
#include <cstdlib>  
#include <ctime>

using namespace std;

double gerarNumeroAleatorio();
bool numeroJaExiste(double* array, int tamanho, double numero);

int main() {
    //utilizando time() pra gerar uma semente diferente em cada execução do app
    srand(static_cast<unsigned>(time(0))); 

    double *valores = NULL; //ponteiro nulo/não aponta pra um obj
    int quantidade = 0;
    char opcao;

    do {
        //realoca a memória
        double* novoArray = static_cast<double*>(realloc(valores, (quantidade + 1) * sizeof(double)));
        
        if (!novoArray) {
            cout << "Não foi possível realocar a memória." << endl;
            free(valores);
            return 1;
        }
        valores = novoArray;

        //gera um número que não existe 
        double novoNumero;
        do {
            novoNumero = gerarNumeroAleatorio();
        } while (numeroJaExiste(valores, quantidade, novoNumero));
        valores[quantidade] = novoNumero;
        ++quantidade;

        cout << "Número gerado: " << novoNumero << endl;
        cout << "Deseja adicionar mais um número? (s/n): ";
        cin >> opcao;

    } while (opcao == 's' || opcao == 'S');

    double soma = 0;
    double maior = valores[0];
    double menor = valores[0];

    for (int i = 0; i < quantidade; ++i) {
        soma += valores[i];
        if (valores[i] > maior) maior = valores[i];
        if (valores[i] < menor) menor = valores[i];
    }

    double media = soma / quantidade;

    cout << "\nResultados:\n";
    cout << "Somatório: " << soma << endl;
    cout << "Média: " << media << endl;
    cout << "Maior valor: " << maior << endl;
    cout << "Menor valor: " << menor << endl;

    free(valores);
    return 0;
}

double gerarNumeroAleatorio() {
    return static_cast<double>(rand()) / RAND_MAX * 100;
}

bool numeroJaExiste(double* array, int tamanho, double numero) {
    for (int i = 0; i < tamanho; ++i) {
        if (array[i] == numero) {
            return true; //número já existe
        }
    }
    return false; //número não existe
}