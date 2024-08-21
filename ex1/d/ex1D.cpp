/*
João Vitor Morais Dias - 2 Semestre DSM
a) Efetuar o cálculo da quantidade de litros de combustível gasta em uma viagem, utilizando um automóvel que faz 12 Km por litro.
Para obter o cálculo, o usuário deve fornecer o tempo gasto (TEMPO) e a velocidade média (VELOCIDADE) durante a viagem.
Desta forma, pode-se descobrir a distância percorrida com a fórmula DISTANCIA = TEMPO * VELOCIDADE.
Possuindo o valor da distância, basta calcular a quantidade de litros de combustível utilizada na viagem com a fórmula LITROS_USADOS = DISTANCIA / 12.
Ao final, o programa deve apresentar os valores da velocidade média (VELOCIDADE), tempo gasto na viagem (TEMPO), a distancia percorrida (DISTANCIA) e 
a quantidade de litros (LITROS_USADOS) utilizada na viagem.
*/

#include <stdio.h>
#include <iostream>
#include <stdlib.h>
using namespace std;

int main()
{
    float tempo, vel_Media; // variáveis

    cout << "Quanto tempo a viagem durou? (em horas): ";
    cin >> tempo;
    cout << "\nCom uma velocidade media de quantos km/h? ";
    cin >> vel_Media;

    const float distancia = tempo * vel_Media; // fórmula da distância
    const float litros_usados = distancia / 12; // fórmula dos L usados

    cout << "\nO valor da Velocidade Media é de: " << vel_Media << " km/h";
    cout << "\nO tempo gasto foi de: " << tempo << " horas";
    cout << "\nPortanto, a distância foi de: " << distancia << " km";
    cout << "\nE foram utilizados " << litros_usados << " L de combustivel";

    return 0;
}
