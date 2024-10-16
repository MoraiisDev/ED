#include <iostream>
using namespace std;

// armazenar os valores de entrada
struct DadosEntrada {
    int A;
    int B;
    int C;
    int D;
};

// armazenar os resultados
struct DadosSaida {
    int produto; // produto de A * C
    int soma;    // soma de B + D
};

// função para ler os valores de entrada
void lerDadosEntrada(DadosEntrada &dados) {
    cout << "Digite o valor de A: ";
    cin >> dados.A;
    cout << "Digite o valor de B: ";
    cin >> dados.B;
    cout << "Digite o valor de C: ";
    cin >> dados.C;
    cout << "Digite o valor de D: ";
    cin >> dados.D;
}

// calcular o produto de A e C
void calcularProduto(const DadosEntrada &dados, DadosSaida &resultado) {
    resultado.produto = dados.A * dados.C;
}

// calcular a soma de B e D
void calcularSoma(const DadosEntrada &dados, DadosSaida &resultado) {
    resultado.soma = dados.B + dados.D;
}

// exibir o resultado
void exibirResultados(const DadosSaida &resultado) {
    cout << "Resultado do Produto (A * C): " << resultado.produto << endl;
    cout << "Resultado da Soma (B + D): " << resultado.soma << endl;
}

int main() {
    DadosEntrada dadosEntrada;    
    DadosSaida dadosSaida;        
    int opcao;

    do {
        // exibindo o menu de opções
        cout << "Menu de Opções:\n";
        cout << "1. Ler valores de entrada\n";
        cout << "2. Calcular Produto (A * C)\n";
        cout << "3. Calcular Soma (B + D)\n";
        cout << "4. Exibir Resultados\n";
        cout << "5. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                lerDadosEntrada(dadosEntrada);  // ler valores de entrada
                break;
            case 2:
                calcularProduto(dadosEntrada, dadosSaida);  // calcular produto
                cout << "Produto calculado com sucesso.\n";
                break;
            case 3:
                calcularSoma(dadosEntrada, dadosSaida);  // calcular soma
                cout << "Soma calculada com sucesso.\n";
                break;
            case 4:
                exibirResultados(dadosSaida);  // exibir resultados
                break;
            case 5:
                cout << "Programa finalizado\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 5);  // loop até que o usuário escolha sair

    return 0;
}