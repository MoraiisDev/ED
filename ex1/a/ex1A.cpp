/*
João Vitor Morais Dias - 2 Semestre DSM
a) Ler uma temperatura em graus Celsius e apresentá-la convertida em graus Fahrenheit. A fórmula de
conversão é F ← (9 * C + 160) / 5, sendo F a temperatura em Fahrenheit e C a temperatura em Celsius
*/

#include <iostream>
#include <cstdlib>
using namespace std;

int main()
{
    setlocale(LC_ALL, "Portuguese");
    
    //variáveis
    int celsius;
    
    //dados de entrada
    cout << "\nVamos converter as temperaturas de Celsius para Fahrenheit?";
    cout << "\nValor da temperatura em Celsius: ";
    cin >> celsius;
    
    //cálculo de conversão
    const int fahrenheit = (9*celsius + 160)/5;
    cout << celsius << "ºC convertido para Fahrenheit é: " << fahrenheit << "ºF";

    return 0;
}