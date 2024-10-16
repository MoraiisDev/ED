#include <iostream>
using namespace std;

// armazenar os dados de entrada
struct DadosEntrada {
    double salarioMensal;  // Salário mensal (SM)
    double percentualReajuste;  // Percentual de reajuste (PR)
};

// armazenar o dado de saída
struct DadosSaida {
    double novoSalario;  // Novo salário após o reajuste (NS)
};

// ler os valores de entrada
void lerDadosEntrada(DadosEntrada &dados) {
    cout << "Digite o valor do salário mensal (SM): ";
    cin >> dados.salarioMensal;
    cout << "Digite o valor do percentual de reajuste (PR): ";
    cin >> dados.percentualReajuste;
}

// calcular o novo salário
void calcularNovoSalario(const DadosEntrada &dados, DadosSaida &resultado) {
    resultado.novoSalario = dados.salarioMensal * (1 + dados.percentualReajuste / 100);
}

// exibir o resultado
void exibirResultado(const DadosSaida &resultado, bool calculado) {
    if (calculado) {
        cout << "O novo salário após o reajuste é: " << resultado.novoSalario << endl;
    } else {
        cout << "O novo salário ainda não foi calculado. Por favor, calcule o salário primeiro." << endl;
    }
}

int main() {
    DadosEntrada dadosEntrada;  
    DadosSaida dadosSaida;      
    int opcao;              
    bool salarioCalculado = false;  // verificar se o cálculo foi feito

    do {
        // exibindo o menu de opções
        cout << "Menu de Opções:\n";
        cout << "1. Ler valores de entrada\n";
        cout << "2. Calcular Novo Salário\n";
        cout << "3. Exibir Resultado\n";
        cout << "4. Sair\n";
        cout << "Escolha uma opção: ";
        cin >> opcao;

        switch (opcao) {
            case 1:
                lerDadosEntrada(dadosEntrada);  // ler valores de entrada
                salarioCalculado = false;       // resetar a variável de controle
                break;
            case 2:
                calcularNovoSalario(dadosEntrada, dadosSaida);  // calcular novo salário
                salarioCalculado = true;       // atualizar a variável de controle
                cout << "Novo salário calculado com sucesso.\n";
                break;
            case 3:
                exibirResultado(dadosSaida, salarioCalculado);  // exibir resultado
                break;
            case 4:
                cout << "Finalizando o programa\n";
                break;
            default:
                cout << "Opção inválida. Tente novamente.\n";
        }

    } while (opcao != 4);  // loop até que o usuário escolha sair

    return 0;
}