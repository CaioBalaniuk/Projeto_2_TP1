#ifndef MODULOS_H_INCLUDED
#define MODULOS_H_INCLUDED
#include<vector>
#include<string>
#include "interfaces.h"
#include "repositorios.h"
//Declaração do Módulo de Apresentação de Criação de Conta
class MACC : public IACC {
private:
    MSCC* mscc;
    string cpf_rep;
    string nome_rep;
    string senha_rep;

public:
    bool informa_cpf(string) override;
    bool informa_nome(string) override;
    bool informa_senha(string) override;
    void sair_criacao() override;
    void executar() override;
};

//Declaração do Módulo de Serviço de Criação de Conta
class MSCC : public ISCC {
public:
    void salvar_dados(string, string, string) override;
};

//Declaração do Módulo de Serviço de Gerenciamento de Conta
class MSGC : public ISGC {
public:
    string ler_cs(string) override;
    bool alterar_senha(string, string) override;
    bool aterar_nome(string, string) override;
    void excluir_cs(string) override;

};

////////////////////////////////////////////////////////////////////////////////////////
//Declaração Modulo de serviço de investimentos
class MSI : public ISI {
private:
    RP *repositorio_p;
    RT *repositorio_t;
public:
    string listar_ts(string) override;
    bool salvar_dados_t(Titulo*) override;
    string ler_ts(string,string) override;
    bool atualizar_dados_t(string,string,string,string) override;
    bool excluir_ts(string,string) override;
    string listar_ps(string) override;
    bool salvar_dados_p(Pagamento*) override;
    string ler_ps(string, int) override;
    bool atualizar_dados_p(string, int, string, string) override;
    bool excluir_ps(string, int) override;
};
//Declaração Modulo de apresentação de investimentos
class MAI : public IAI {
private:
    MSI* servico = new MSI;
public:
    string listar_t () override;
    void criar_t() override;
    void ler_t() override;
    void atualizar_t() override;
    void excluir_t() override;
    void listar_p() override;
    void criar_p() override;
    vector<string> ler_p() override;
    void atualizar_p() override;
    void excluir_p() override;
    void executar() override;
    void sair() override;
};

/**
 * @class MSA
 * @brief Implementação da Interface de Serviço de Autenticação
 *
 * Esta classe implementa a interface ISA e é responsável por buscar o CPF e verificar a senha no repositório de contas.
 */

class MSA : public ISA {
private:
    RC* repositorio;  /**< Instância do repositório de contas */

public:
    /**
     * @brief Busca CPF no repositório de contas.
     * @param cpf CPF do usuário.
     * @return true se o CPF está no repositório de contas, false caso contrário.
     */
    bool busca_CPF(string cpf) override;

    /**
     * @brief Verifica se a senha é correspondente com o CPF digitado.
     * @param cpf CPF do usuário.
     * @param senha Senha do usuário.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool verifica_senha(string cpf, string senha) override;
};

/**
 * @class MAA
 * @brief Implementação da Interface de Autenticação do Usuário
 *
 * Esta classe implementa a interface IAA e é responsável por receber e armazenar o CPF e a senha do usuário.
 */

class MAA : public IAA {
private:
    string cpf;  /**< CPF do usuário */
    string senha; /**< Senha do usuário */
    MSA *servicoAutenticacao = new MSA;/**< Ponteiro para o serviço de autenticação */

public:
    /**
     * @brief Solicita o CPF do usuário.
     */
    void getCPF() override;

    /**
     * @brief Solicita a senha do usuário.
     */
    void getSenha() override;

    /**
     * @brief Retira o usuário da autenticação.
     */
    void sair_autenticacao() override;

    /**
     * @brief Retorna o CPF do usuário.
     * @return CPF do usuário.
     */
    string getCpf() const;

    /**
     * @brief Retorna a senha do usuário.
     * @return Senha do usuário.
     */
    string getSenha() const;

    /**
     * @brief Inicia o processo de autenticação.
     */
    void autenticar();

    /**
    *@brief Executa as funcionalidades da classe
    */
    void executar();
};


#endif // MODULOS_H_INCLUDED
