#ifndef INTERFACES_H_INCLUDED
#define INTERFACES_H_INCLUDED
#include "entidades.h"
#include <stdio.h>
#include <string>
#include <vector>
using namespace std;
/**
*@class IAI: Interface de apresentação de investimentos
*@brief Classe puramente abstrata que declara os métodos a serem implementados pelo módulo de apresentação de investimentos;
**/
class IAI {
public:
    /**
    *@brief Metodo puramente abstrato que será responsável por imprimir todos os titulos da conta;
    */
    virtual void listar_t() = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber e, depois, passar as informações de um novo titulo a ser criado;
    *@return True se foi possivel criar o titulo, False se ocorreu alguma falha;
    *@param codigo titulo
    *@param nome de quem emitiu
    *@param setor
    *@param data de emissão
    *@param data de vencimento
    *@param valor
    */
    virtual bool criar_t(string, string, string, string, string, float) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber um codigo titulo e passa-lo para a camada de serviço, para, depois,
    *imprimir suas informações;
    *@param codigo titulo
    */
    virtual void ler_t(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber um codigo titulo e passar quais informações serão alteradas desse titulo
    * para a camada de serviço.
    *@param codigo titulo
    */
    virtual void atualizar_t(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber um codigo titulo e passa-lo para a camada de serviço, que o excluíra;
    *@return True se foi possível excluir o titulo, False se ocorreu algum erro.
    *@param codigo titulo
    */
    virtual bool excluir_t(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber um codigo titulo e , depois, imprimir todos os pagamentos desse titulo;
    *@param codigo titulo
    */
    virtual void listar_p(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por criar um novo pagamento e passar as informações para a camada de serviço salvar;
    *@return True se foi possivel a criação do pagamento, False se ocorreu algum erro;
    *@param codigo titulo no qual sera criado o pagamento
    *@param codigo pagamento
    *@param data do pagamento
    *@param percentual
    *@param estado
    */
    virtual bool criar_p(string, int, string, int, string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber um codigo pagamento e depois imprimir as informações do mesmo;
    *@param codigo pagamento
    */
    virtual void ler_p(int) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber um codigo pagamento e passar as informações a serem alteradas do pagamento;
    *@param codigo pagamento
    */
    virtual void atualizar_p(int) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por receber um codigo pagamento e passa-lo para a camada de serviço exclui-lo;
    *@return True se foi possivel excluir o pagamento, False se ocorreu algum erro;
    *@param codigo pagamento
    */
    virtual bool excluir_p(int) = 0;
};

/**
*@class ISI: Interface de serviço de investimentos;
*@brief Classe responsável por declarar os metodos que serão implementados pelo modulo de serviço de investimentos;
*/
class ISI {
public:
    /**
    *@brief Metodo puramente abstrato responsavel por buscar todos os titulos da conta e retorna-los para a camada de apresentação;
    *@return vetor com todos os titulos e seus respectivos codigos;
    */
    virtual vector<string> listar_ts() = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por salvar um novo titulo com suas informações, no repositorio de investimentos;
    *@return True se foi possivel salvar o titulo, False se ocorreu algum erro;
    *@param Titulo a ser salvo;
    */
    virtual bool salvar_dados_t(Titulo) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por buscar as informações de certo titulo e retorna-las para a camada de apresentação;
    *@return vetor com todas as informações do titulo
    *@param codigo do titulo a ser lido;
    */
    virtual vector<string> ler_ts(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por alterar os novos dados de determinado titulo;
    *@return True se foi possivel a alteração, False se ocorreu algum erro;
    *@param codigo do titulo a ser alterado;
    */
    virtual bool atualizar_dados_t(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por excluir determinado titulo do repositorio;
    *@return True se foi possivel excluir, False se ocorreu algum erro;
    *@param Codigo do titulo a ser excluido;
    */
    virtual bool excluir_ts(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por buscar os pagamentos, de determinado titulo, e depois retorna-los
    * para a camada de apresentação;
    *@return vetor com todos os pagamentos do determinado titulo;
    *@param Codigo do titulo no qual serão lidos os pagamentos;
    */
    virtual vector<int> listar_ps(string) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por salvar um novo pagamento no repositorio de investimentos;
    *@return True se foi possivel salvar, False se ocorreu algum erro;
    *@param codigo do titulo no qual o pagamento será salvo;
    *@param Pagamento a ser salvo;
    */
    virtual bool salvar_dados_p(string, Pagamento) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por buscar as informações do pagamento determinado e retorna-las para
    * a camada de apresentação;
    *@return vetor com todas as informações do pagamento;
    *@param Codigo do titulo no qual o pagamento determinado se encontra;
    *@param codigo do pagamento determinado
    */
    virtual vector<string> ler_ps(string, int) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por alterar os dados determinados de um pagamento também determinado;
    *@return True se foi possivel a alteração, False se ocorreu algum erro;
    *@param Codigo do Pagamento a ser alterado;
    */
    virtual bool atualizar_dados_p(int) = 0;

    /**
    *@brief Metodo puramente abstrato responsavel por excluir determinado pagamento do repositorio de investimentos;
    *@return True se foi possivel excluir, False se ocorreu algum erro;
    *@param Codigo do titulo no qual o pagamento a ser excluido se encontra;
    *@param codigo do pagamento a ser excluido;
    */
    virtual bool excluir_ps(string, int) = 0;
};

#endif // INTERFACES_H_INCLUDED
