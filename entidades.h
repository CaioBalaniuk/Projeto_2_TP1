#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED
#include "dominios.h"
#include "dominios.cpp"
#include <string>
#include <tuple>
#include <vector>

using namespace std;

//Declaração da Classe Pagamento
class Pagamento{
private:
    CodigoPagamento codigo;
    Data data;
    Percentual percentual;
    Estado estado;

public:
    Pagamento() {int a=0;};
    void setPagamento(int novo_codigo, string nova_data, int novo_percentual, string novo_estado);
    tuple<int, string, int, string> getPagamento();
};

//Declaração da Classe Titulo;
class Titulo {
    private:
        CodigoTitulo codigo;
        Nome emissor;
        Setor setor;
        Data emissao;
        Data vencimento;
        Dinheiro valor;
    public:
        void setTitulo (string, string, string, string, string, float);
        vector<string> getTitulo();

};

//Declaração da Classe Conta
class Conta {
private:
    CPF cpf;
    Nome nome;
    Senha senha;

public:
    void setConta(string novo_cpf, string nova_nome, string novo_senha);
    tuple<string, string, string> getConta();

};
#endif // ENTIDADES_H_INCLUDED

