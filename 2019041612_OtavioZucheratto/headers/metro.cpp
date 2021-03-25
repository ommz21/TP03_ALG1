#include "metro.h"

#define INFINITO 10000000

// Construtor da classe Metro
Metro::Metro(int q_escalas, int q_desc_cumul, int t_desc)
{
    quant_escalas = q_escalas;
    quant_desc_cumul = q_desc_cumul;
    tempo_desc = t_desc;

    // Vetor para utilizado para armazenar os melhores custos
    // ate chegar a uma dada estacao
    for (int i = 0; i < quant_escalas+1; i++)
        custo_atual.push_back(INFINITO);
}
void Metro::InsereDesconto(int desconto)
{
    // Insere o desconto da respectiva estacao dentro de um 
    // intervalo
    descontos.push_back(desconto);
}
void Metro::InsereEscala(std::pair<int, int> escala)
{
    // Insere as escalas do problema, os precos e tempos de cada
    // escala
    escalas_tempo_preco.push_back(escala);
}
double Metro::MenorPreco()
{
    int desconto, tempo, acresc_tempo;
    double custo = 0;
    custo_atual.at(0) = 0;
    
    // Para cada estacao sera iniciado um intervalo de descontos
    for (int i = 0; i < quant_escalas; i++)
    {
        desconto = 0;
        tempo = 0;

        // Utiliza o melhor custo ate a estacao atual como inicio
        // custo
        custo = custo_atual.at(i);
        
        // Ao iniciar o intervalo, será calculado os custos das
        // proximas estacoes
        for (int j = 0; j < quant_desc_cumul; j++)
        {
            // Verifica se ainda resta tempo no intervalo ou se
            // ja chegamos ao destino final
            if (tempo >= tempo_desc)
                break;
            if (i + j >= quant_escalas)
                break;

            // Adiciona o tempo gasto nessa escala
            acresc_tempo = escalas_tempo_preco.at(i + j).first;
            tempo += acresc_tempo;
            
            // Calcula o custo aplicando o desconto acumulativo
            // correspondente a escala do intervalo
            desconto += descontos.at(j);
            custo += escalas_tempo_preco.at(i + j).second * (1 - (desconto / 100.));
            
            // Caso o custo calculado nesse intervalo for o melhor ate
            // a estacao atual, entao o vetor da programacao dinamica
            // eh atualizada
            if (custo < custo_atual.at(i + j + 1))
                custo_atual.at(i + j + 1) = custo;
        }
    }
    // Retorna o melhor custo apos utilizar a ultima escala do metro
    return custo_atual.at(quant_escalas);
}
// Metodo auxiliar para impressao do metro considerado no problema
void Metro::ImprimeMetro()
{
    std::cout << std::endl;
    std::cout << "N: " << quant_escalas << std::endl;
    std::cout << "D: " << quant_desc_cumul << std::endl;
    std::cout << "T: " << tempo_desc << std::endl;

    std::cout << "Descontos em cada escala: ";
    for (int i = 0; i < quant_desc_cumul; i++)
        std::cout << descontos.at(i) << " ";
    std::cout << std::endl;

    std::cout << "Escalas(tempo e precos): ";
    for (int i = 0; i < quant_escalas; i++)
        std::cout << "("<< escalas_tempo_preco.at(i).first << ", " << escalas_tempo_preco.at(i).second << ") ";
    std::cout << std::endl;
}