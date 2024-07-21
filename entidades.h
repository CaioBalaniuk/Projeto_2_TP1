#ifndef ENTIDADES_H_INCLUDED
#define ENTIDADES_H_INCLUDED

#include "dominios.h"
#include "dominios.cpp"
#include <string>
#include <tuple>
#include <vector>

using namespace std;

/**
 * @brief Classe da entidade Pagamento (Feito por: 231013529).
 */
class Pagamento {
private:
    /**
     * @brief Código de Pagamento.
     */
    CodigoPagamento codigo;

    /**
     * @brief Data do pagamento.
     */
    Data data;

    /**
     * @brief Percentual do pagamento.
     */
    Percentual percentual;

    /**
     * @brief Estado do pagamento.
     */
    Estado estado;

public:
    /**
     * @brief Construtor da entidade Pagamento.
     */
    Pagamento() { int a = 0; };

    /**
     * @brief Define os atributos de um pagamento.
     *
     * @param novo_codigo Código do pagamento.
     * @param nova_data Data do pagamento.
     * @param novo_percentual Percentual do pagamento.
     * @param novo_estado Estado do pagamento.
     *
     * @throws invalid_argument Se o pagamento não for válido.
     */
    void setPagamento(int novo_codigo, string nova_data, int novo_percentual, string novo_estado);

    /**
     * @brief Obtém os atributos de um pagamento.
     *
     * @return Uma tupla contendo o código de pagamento, data, percentual e estado.
     */
    tuple<int, string, int, string> getPagamento();
};


/**
 * @brief Classe da entidade Título (Feito por: 231025190).
 */
class Titulo {
private:
    /**
     * @brief Código de Título.
     */
    CodigoTitulo codigo;

    /**
     * @brief Nome do emissor.
     */
    Nome emissor;

    /**
     * @brief Setor do título.
     */
    Setor setor;

    /**
     * @brief Data de emissão.
     */
    Data emissao;

    /**
     * @brief Data de vencimento do título
     */
    Data vencimento;

    /**
     * @brief Valor do título.
     */
    Dinheiro valor;

public:
    /**
     * @brief Define os atributos de um título.
     *
     * @param codigo Código do título.
     * @param emissor Emissor do título.
     * @param setor Setor do título.
     * @param emissao Data de emissão do título.
     * @param vencimento Data de vencimento do título.
     * @param valor Valor do título.
     *
     * @throws invalid_argument Se o título não for válido.
     */
    void setTitulo(string codigo, string emissor, string setor, string emissao, string vencimento, float valor);

    /**
     * @brief Obtém os atributos de um título.
     *
     * @return Um vetor de strings contendo o código de título, emissor, setor, data de emissão e data de vencimento do título, além do valor do título.
     */
    vector<string> getTitulo();
};


/**
 * @brief Classe da entidade Conta (Feito por: 231036292).
 */
class Conta {
private:
    /**
     * @brief CPF do usuário.
     */
    CPF cpf;

    /**
     * @brief Nome do usuário.
     */
    Nome nome;

    /**
     * @brief Senha do usuário.
     */
    Senha senha;

public:
    /**
     * @brief Define os atributos de uma conta.
     *
     * @param novo_cpf CPF do titular da conta.
     * @param nova_nome Nome do titular da conta.
     * @param novo_senha Senha da conta.
     *
     * @throws invalid_argument Se a conta não for válida.
     */
    void setConta(string novo_cpf, string nova_nome, string novo_senha);

    /**
     * @brief Obtém os atributos de uma conta.
     *
     * @return Uma tupla contendo o CPF, nome e senha da conta.
     */
    tuple<string, string, string> getConta();
};

#endif // ENTIDADES_H_INCLUDED
