#ifndef REPOSITORIOS_H_INCLUDED
#define REPOSITORIOS_H_INCLUDED
#include <vector>
#include <string>
using namespace std;

/**
 * @brief Classe responsável pelo repositório de pagamentos.
 *
 * Esta classe gerencia as operações relacionadas ao armazenamento e manipulação de dados referentes aos pagamentos.
 */
class RP {
private:
    vector<string> repositorio_p; /**< Vetor que armazena os dados referentes ao pagamentos. */
    
    /**
     * @brief Divide uma string em partes com base em um caractere delimitador.
     * @param str String a ser dividida.
     * @param delim Caractere delimitador.
     * @return Vetor de strings resultante da divisão.
     */
    vector<string> split(string str, char delim);

public:
    /**
     * @brief Responsável por inicializar o repositório de pagamentos.
     */
    void start();

    /**
     * @brief Responsável por adicionar um novo pagamento associado a um novo CPF ao repositório.
     * @param cpf CPF do usuário.
     * @param pagamento Dados do pagamento.
     */
    void adicionar(string cpf, string pagamento);

    /**
     * @brief Responsável por listar os pagamentos associados a um usuário específico.
     * @param cpf CPF do usuário.
     * @return String contendo os dados dos pagamentos do usuário.
     */
    string listar_psr(string cpf);

    /**
     * @brief Responsável por adicionar um pagamento ao repositório de um CPF já existente.
     * @param cpf CPF do usuário.
     * @param pagamento Dados do pagamento.
     */
    void add_pagamento(string cpf, string pagamento);

    /**
     * @brief Responsável por excluir um certo pagamento de um usuário específico.
     * @param cpf CPF do usuário.
     * @param index Endereço do pagamento a ser excluído.
     */
    void excluir_pag(string cpf, int index);

    /**
     * @brief Responsável por excluir todos os pagamentos de um usuário específico.
     * @param cpf CPF do usuário.
     */
    void excluir(string cpf);

    /**
     * @brief Responsável por atualizar os dados de um pagamento específico.
     * @param cpf CPF do usuário.
     * @param index Endereço do pagamento a ser atualizado.
     * @param campo Campo a ser atualizado.
     * @param novoValor Novo valor do campo.
     */
    void atualizar(string cpf, int index, string campo, string novoValor);

    /**
     * @brief Responsável por ler os dados associados a um pagamento específico de um usuário.
     * @param cpf CPF do usuário.
     * @param pagamento Nome do pagamento.
     * @return String contendo os dados do pagamento.
     */
    string ler_pr(string cpf, string pagamento);
};

/**
 * @brief Classe responsável pelo repositório de títulos.
 *
 * Esta classe gerencia operações relacionadas ao armazenamento e manipulação de dados referentes aos títulos do sistema.
 */
class RT {
private:
    vector<string> repositorio; /**< Vetor que armazena os dados dos títulos. */
    
    /**
     * @brief Responsável por dividir uma string em partes com base em um caractere delimitador.
     * @param str String a ser dividida.
     * @param delim Caractere delimitador.
     * @return Vetor de strings resultante da divisão.
     */
    vector<string> split(string str, char delim);

public:
    /**
     * @brief Responsável por inicializar o repositório de títulos.
     */
    void start();

    /**
     * @brief Responsável por adicionar um novo título associado a um novo CPF ao repositório.
     * @param cpf CPF do usuário.
     * @param titulo Dados do título.
     */
    void adicionar(string cpf, string titulo);

    /**
     * @brief Responsável por listar os títulos de um usuário específico.
     * @param cpf CPF do usuário.
     * @return String contendo os dados dos títulos do usuário.
     */
    string listar_tsr(string cpf);

    /**
     * @brief Responsável por adicionar um título ao repositório de um CPF já existente.
     * @param cpf CPF do usuário.
     * @param titulo Dados do título.
     */
    void add_titulo(string cpf, string titulo);

    /**
     * @brief Responsável por excluir todos títulos associados a um usuário específico.
     * @param cpf CPF do usuário.
     */
    void excluir(string cpf);

    /**
     * @brief Responsável por excluir um título de um usuário específico.
     * @param cpf CPF do usuário.
     * @param titulo Nome do título a ser excluído.
     */
    void excluir_titulo(string cpf, string titulo);

    /**
     * @brief Responsável por atualizar os dados de um título específico.
     * @param cpf CPF do usuário.
     * @param titulo Nome do título a ser atualizado.
     * @param campo Campo a ser atualizado.
     * @param novoValor Novo valor do campo.
     */
    void atualizar(string cpf, string titulo, string campo, string novoValor);

    /**
     * @brief Responsável por permitir a leitura dos dados associados a um título específico de um usuário.
     * @param cpf CPF do usuário.
     * @param titulo Nome do título.
     * @return String contendo os dados do título.
     */
    string ler_tr(string cpf, string titulo);
};

/**
 * @brief Classe responsável pelo repositório de contas.
 *
 * Esta classe gerencia as operações relacionadas ao armazenamento e manipulação de dados referentes as contas do sistema.
 */
class RC {
private:
    vector<string> repositorio; /**< Vetor que armazena os dados das contas. */
    
    /**
     * @brief Responsável por dividir uma string em partes com base em um caractere delimitador.
     * @param str String a ser dividida.
     * @param delim Caractere delimitador.
     * @return Vetor de strings resultante da divisão.
     */
    vector<string> split(string str, char delim);

public:
    /**
     * @brief Responsável por inicializar repositório de contas.
     */
    void start();

    /**
     * @brief Responsável por adicionar uma nova conta ao repositório.
     * @param cpf CPF do usuário.
     * @param dados Dados da conta.
     */
    void adicionar_c(string cpf, string dados);

    /**
     * @brief Responsável por adicionar dados a uma conta já existente.
     * @param cpf CPF do usuário.
     * @param dados Dados a serem adicionados.
     */
    void add_linha_exist(string cpf, string dados);

    /**
     * @brief Responsável por ler os dados de uma conta específica.
     * @param cpf CPF do usuário.
     * @return String contendo os dados da conta.
     */
    string ler_c(string cpf);

    /**
     * @brief Responsável por excluir uma conta específica.
     * @param cpf CPF do usuário.
     */
    void excluir_c(string cpf);

    /**
     * @brief Responsável por atualizar a senha associada a uma conta específica.
     * @param cpf CPF do usuário.
     * @param senhaAntiga Senha antiga do usuário.
     * @param novaSenha Nova senha do usuário.
     */
    void atualizar_senha(string cpf, string senhaAntiga, string novaSenha);

    /**
     * @brief Responsável por verificar se a senha fornecida é válida.
     * @param cpf CPF do usuário.
     * @param senha Senha do usuário.
     * @return true se a senha estiver correta, false caso contrário.
     */
    bool verificar_senha(string cpf, string senha);

    /**
     * @brief Responsável por atualizar o nome de um usuário.
     * @param cpf CPF do usuário.
     * @param nomeAntigo Nome antigo do usuário.
     * @param nomeNovo Novo nome do usuário.
     */
    void atualizar_nome(string cpf, string nomeAntigo, string nomeNovo);
};

#endif // REPOSITORIOS_H_INCLUDED
