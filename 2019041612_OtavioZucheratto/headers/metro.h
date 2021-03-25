#ifndef METRO_H
#define METRO_H

#include <iostream>
#include <vector>

/*Assinatura dos atributos e metodos da classe Metro*/
class Metro
{
    public:
        Metro(int q_escalas, int q_desc_cumul, int t_desc);
        void InsereDesconto(int desconto);
        void InsereEscala(std::pair<int, int> escala);
        double MenorPreco();
        void ImprimeMetro();
        
    private:
        int quant_escalas, quant_desc_cumul, tempo_desc;
        std::vector<std::pair<int, int>> escalas_tempo_preco;
        std::vector<double> custo_atual;
        std::vector<int> descontos;
};

#endif /* METRO_H */