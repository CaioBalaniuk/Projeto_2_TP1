#ifndef MODULOS_H_INCLUDED
#define MODULOS_H_INCLUDED
#include<vector>
#include<string>
#include "interfaces.h"
#include "repositorios.h"
using namespace std;

class MAI;
class MAGC;


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
    MAGC* gerenciar_c;

public:

    void definir_g(MAGC);
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
    bool autenticar();

    /**
    *@brief Executa as funcionalidades da classe
    */
    void executar();
};





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
    void excluir_g(string);
};

class MAI : public IAI {
private:
    MSI* servico = new MSI;
    MAGC* magc;
    string cpf;
public:
    void listar_t () override;
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
    void passar_cpf(string);
    void excluir_geral(string);
};

//Declaração do Módulo de Serviço de Criação de Conta
class MSCC : public ISCC {
public:
    void salvar_dados(string, string, string) override;
};

class MACC : public IACC {
private:
    MSCC* mscc = new MSCC;
    MAA* maa = new MAA;
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

//Declaração do Módulo de Serviço de Gerenciamento de Conta
class MSGC : public ISGC {
public:
    string ler_cs(string) override;
    bool alterar_senha(string, string) override;
    bool alterar_nome(string, string) override;
    void excluir_cs(string) override;

};

//Declaração do Módulo de Apresentação de Gerenciamento de Conta
class MAGC : public IAGC {
private:
    MSGC* msgc = new MSGC;
    MAI* mai = new MAI;
    MAA* maa = new MAA;
    string cpf_rep;

public:
    void set_CPF(string);
    void ler_c() override;
    void atualizar_c() override;
    void excluir_c() override;
    void ir_invest() override;
    void sair_gerenConta() override;
    void executar() override;
    void definir_i(MAI);
    void definir_a(MAA);
};



#endif // MODULOS_H_INCLUDED
