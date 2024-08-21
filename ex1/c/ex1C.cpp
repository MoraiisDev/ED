/*
João Vitor Morais Dias - 2 Semestre DSM
c) Calcular e apresentar o valor do volume de uma lata de óleo, utilizando a fórmula:
Volume <- PI * Raio^2 * Altura 
*/

#include "iostream"
#include "cstdlib"
#include <math.h>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    //variáveis
    const float PI = 3.14; //valor de PI simplificado
    float r; //raio
    float h; //altura
    
    //dados de entrada
    cout << "\nVamos calcular o Volume de uma lata de óleo!";
    cout << "\nInsira o valor do raio desta lata ";
    cin >> r; //recebe e armazena o valor do raio
    cout << "\nAgora insira o valor da altura ";
    cin >> h; //recebe e armazena o valor da altura
    
    //cálculo de conversão
    const int v = (PI * pow(r, 2.0) * h); //calcula o valor do volume
    cout << "O valor do volume da sua lata de óleo é de " << v << "cm³";

    return 0;
}