#include "headers/metro.h"
#include <iomanip>

int main()
{
    // Declaracao das variaveis para lidar com a entrada do programa
    int quant_escalas, quant_desc_cumul, tempo_desc, desconto;
    std::pair<int, int> escala;

    // Leitura da quantidade total de escalas, da quantidade de escalas
    // no desconto acumulativo e do intervalo de tempo desses descontos
    std::cin >> quant_escalas >> quant_desc_cumul >> tempo_desc;
    
    // Declaracao do metro do problema
    Metro viagem(quant_escalas, quant_desc_cumul, tempo_desc);

    // Leitura dos valores de cada desconto acumulado a cada estacao em
    // um intervalo
    for (int i = 0; i < quant_desc_cumul; i++)
    {
        std::cin >> desconto;
        viagem.InsereDesconto(desconto);
    }

    // Leitura dos precos e do temo gasto em cada escala do metro
    for (int i = 0; i < quant_escalas; i++)
    {
        std::cin >> escala.first >> escala.second;
        viagem.InsereEscala(escala);
    }
    
    // Definindo o limite de duas casas decimais para a impressao da saida
    std::cout << std::fixed << std::showpoint;
    std::cout << std::setprecision(2);
    // Imprime o retorno do metodo que calcula o menor custo acumulado do metro
    std::cout << viagem.MenorPreco();
    
    //viagem.ImprimeMetro();
    
    return 0;
}