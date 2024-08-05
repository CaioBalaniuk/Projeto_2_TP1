#ifndef MODULOS_H_INCLUDED
#define MODULOS_H_INCLUDED
#include <vector>
#include <string>
#include "interfaces.h"
#include "repositorios.h"
using namespace std;

class MAI;
class MAGC;

/**
 * @brief Classe que implementa a Interface de Serviço de Autenticação (Feita por: 231036292).
 *
 * Esta classe implementa a interface ISA e é responsável por buscar o CPF e verificar a senha no repositório de contas.
 */
class MSA : public ISA {
private:
    RC* repositorio; 

public:
    /**
     * @brief Busca CPF no repositório de contas.
     * @param cpf CPF do usuário.
     * @return true se o CPF está no repositório de contas, false caso contrário.
     */
    bool busca_CPF(string cpf) override;

    /**
     * @brief Verifica se a senha é correspondente ao CPF fornecido.
     * @param cpf CPF do usuário.
     * @param senha Senha do usuário.
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool verifica_senha(string cpf, string senha) override;
};

/**
 * @brief Classe que implementa a Interface de Apresentação da Autenticação (Feita por: 231036292).
 *
 * Esta classe implementa a interface IAA e é responsável por receber e armazenar o CPF e a Senha do usuário.
 */
class MAA : public IAA {
private:
    string cpf; 
    string senha; 
    MSA* servicoAutenticacao = new MSA; 
    MAGC* gerenciar_c;

public:
    /**
     * @brief Define o gerenciador de conta.
     * @param g Instância do gerenciador de conta.
     */
    void definir_g(MAGC g);

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
     * @return true se a autenticação for bem-sucedida, false caso contrário.
     */
    bool autenticar();

    /**
     * @brief Executa as funcionalidades da classe.
     */
    void executar();
};

/**
 * @brief Classe que implementa a Interface de Serviço de Investimentos (Feita por: 231025190).
 *
 * Esta classe implementa a interface ISI e é responsável por gerenciar os dados referentes a títulos e pagamentos.
 */
class MSI : public ISI {
private:
    RP* repositorio_p;
    RT* repositorio_t;

public:
    /**
     * @brief Responsável por buscar os títulos do usuário no repositório de títulos e listar todos associados ao usuário.
     * @param cpf CPF do usuário.
     * @return String com a lista de títulos.
     */
    string listar_ts(string cpf) override;

    /**
     * @brief Responsável por salvar um título no repositório de títulos.
     * @param titulo Ponteiro para o objeto Titulo.
     * @return true se o salvamento for bem-sucedido, false caso contrário.
     */
    bool salvar_dados_t(Titulo* titulo) override;

    /**
     * @brief Responsável por acessar os repositórios e disponibilizar os dados associados a um título específico.
     * @param cpf CPF do usuário.
     * @param titulo Nome do título.
     * @return String com os dados do título.
     */
    string ler_ts(string cpf, string titulo) override;

    /**
     * @brief Responsável por atualizar os dados de um título específico no repositório.
     * @param cpf CPF do usuário.
     * @param titulo Nome do título.
     * @param novosDados Novos dados para o título.
     * @return true se a atualização for bem-sucedida, false caso contrário.
     */
    bool atualizar_dados_t(string cpf, string titulo, string novosDados) override;

    /**
     * @brief Responsável por deletar um título específico nos repositórios.
     * @param cpf CPF do usuário.
     * @param titulo Nome do título.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluir_ts(string cpf, string titulo) override;

    /**
     * @brief Responsável por, acessando o repositório de pagamentos, listar todos os pagamentos associados a um título.
     * @param cpf CPF do usuário.
     * @return String com a lista de pagamentos.
     */
    string listar_ps(string cpf) override;

    /**
     * @brief Responsável por salvar dados de um pagamento no repositório de pagamentos.
     * @param pagamento Ponteiro para o objeto Pagamento.
     * @return true se o salvamento for bem-sucedido, false caso contrário.
     */
    bool salvar_dados_p(Pagamento* pagamento) override;

    /**
     * @brief Responsável por ler dados associados a um pagamento específico.
     * @param cpf CPF do usuário.
     * @param id Identificador do pagamento.
     * @return String com os dados do pagamento.
     */
    string ler_ps(string cpf, int id) override;

    /**
     * @brief Responsável por atualizar os dados de um pagamento específico no repositório.
     * @param cpf CPF do usuário.
     * @param id Identificador do pagamento.
     * @param novosDados Novos dados para o pagamento.
     * @return true se a atualização for bem-sucedida, false caso contrário.
     */
    bool atualizar_dados_p(string cpf, int id, string novosDados) override;

    /**
     * @brief Responsável por excluir um pagamento específico no repositório.
     * @param cpf CPF do usuário.
     * @param id Identificador do pagamento.
     * @return true se a exclusão for bem-sucedida, false caso contrário.
     */
    bool excluir_ps(string cpf, int id) override;

    /**
     * @brief Responsável por excluir todos os dados associados a um usuário.
     * @param cpf CPF do usuário.
     */
    void excluir_g(string cpf);
};

/**
 * @brief Classe que implementa a Interface de Apresentação de Investimento (Feita por: 231025190).
 *
 * Esta classe implementa a interface IAI e é responsável por receber e armazenar as ações referentes aos investimento do usuário.
 */
class MAI : public IAI {
private:
    MSI* servico = new MSI;
    MAGC* magc;
    string cpf;

public:
    /**
     * @brief Responsável por listar todos os títulos ao usuário.
     */
    void listar_t() override;

    /**
     * @brief Responsável por interagir com o usuário a fim de criar um novo título.
     */
    void criar_t() override;

    /**
     * @brief  Responsável por ler um título específico ao usuário.
     */
    void ler_t() override;

    /**
     * @brief Responsável por interagir com o usuário a fim de atualizar um título específico.
     */
    void atualizar_t() override;

    /**
     * @brief Responsável por excluir um título específico.
     */
    void excluir_t() override;

    /**
     * @brief Responsável por listar todos os pagamentos associados a um título ao usuário
     */
    void listar_p() override;

    /**
     * @brief Responsável por interagir com o usuário a fim de criar um novo pagamento.
     */
    void criar_p() override;

    /**
     * @brief Responsável por ler os dados associados a um pagamento específico.
     * @return Vetor de strings com os detalhes do pagamento.
     */
    vector<string> ler_p() override;

    /**
     * @brief Responsável por interagir com o usuário a fim de atualizar um pagamento específico.
     */
    void atualizar_p() override;

    /**
     * @brief Responsável por excluir um pagamento específico.
     */
    void excluir_p() override;

    /**
     * @brief Responsável por executar as funcionalidades da classe.
     */
    void executar() override;

    /**
     * @brief Responsável por sair da interface de investimentos.
     */
    void sair() override;

    /**
     * @brief Responsável por definir o valor do atributo cpf.
     * @param cpf CPF do usuário.
     */
    void passar_cpf(string cpf);

    /**
     * @brief Responsável por excluir todos os dados associados ao usuário.
     * @param cpf CPF do usuário.
     */
    void excluir_geral(string cpf);
};

/**
 * @brief Classe que implementa a Interface de Serviço de Criação de Conta (Feita por: 231013529).
 *
 * Esta classe implementa a interface ISCC e é responsável por salvar os dados de uma nova conta no repositório de contas.
 */
class MSCC : public ISCC {
public:
    /**
     * @brief Responsável por salvar os dados de uma nova conta diretamente no repositório.
     * @param cpf CPF do usuário.
     * @param nome Nome do usuário.
     * @param senha Senha do usuário.
     */
    void salvar_dados(string cpf, string nome, string senha) override;
};

/**
 * @brief Classe que implementa a Interface de Apresentação de Criação de Conta (Feita por: 231013529).
 *
 * Esta classe implementa a interface IACC e é responsável por interagir com o usuário para a criação de conta.
 */
class MACC : public IACC {
private:
    MSCC* mscc = new MSCC;
    MAA* maa = new MAA;
    string cpf_rep;
    string nome_rep;
    string senha_rep;

public:
    /**
     * @brief Responsável por verificar se o CPF fornecido pelo usuário é válido.
     * @param cpf CPF do usuário.
     * @return true se o CPF for válido, false caso contrário.
     */
    bool informa_cpf(string cpf) override;

    /**
     * @brief Responsável por verificar se o nome fornecido pelo usuário é válido.
     * @param nome Nome do usuário.
     * @return true se o nome for válido, false caso contrário.
     */
    bool informa_nome(string nome) override;

    /**
     * @brief Responsável por verificar se a senha fornecido pelo usuário é válida.
     * @param senha Senha do usuário.
     * @return true se a senha for válida, false caso contrário.
     */
    bool informa_senha(string senha) override;

    /**
     * @brief Responsável por retirar o usuário da interface.
     */
    void sair_criacao() override;

    /**
     * @brief Responsável por executar as funcionalidades da interface.
     */
    void executar() override;
};

/**
 * @brief Classe que implementa a Interface de Serviço de Gerenciamento de Conta (Feita por: 231013529).
 *
 * Esta classe implementa a interface ISGC e é responsável por gerenciar os dados de conta, incluindo leitura, alteração e exclusão de dados, dentro do repositório de contas.
 */
class MSGC : public ISGC {
public:
    /**
     * @brief Responsável por fornecer a leitura de dados da conta de um usuário por meio de uma busca no repositório de contas.
     * @param cpf CPF do usuário.
     * @return String com os dados da conta.
     */
    string ler_cs(string cpf) override;

    /**
     * @brief Responsável por alterar a senha de um usuário no repositório de contas.
     * @param cpf CPF do usuário.
     * @param novaSenha Nova senha do usuário.
     * @return true se a alteração for bem-sucedida, false caso contrário.
     */
    bool alterar_senha(string cpf, string novaSenha) override;

    /**
     * @brief Responsável por alterar o nome de um usuário no repositório de contas.
     * @param cpf CPF do usuário.
     * @param novoNome Novo nome do usuário.
     * @return true se a alteração for bem-sucedida, false caso contrário.
     */
    bool alterar_nome(string cpf, string novoNome) override;

    /**
     * @brief Responsável por excluir a conta de um usuário.
     * @param cpf CPF do usuário.
     */
    void excluir_cs(string cpf) override;
};

/**
 * @brief Classe que implementa a Interface de Apresentação de Gerenciamento de Conta (Feita por: 231013529).
 *
 * Esta classe implementa a interface IAGC e é responsável por gerenciar a interface de apresentação para as ações de conta, como leitura, alteração e exclusão de dados ao usuário.
 */
class MAGC : public IAGC {
private:
    MSGC* msgc = new MSGC;
    MAI* mai = new MAI;
    MAA* maa = new MAA;
    string cpf_rep;

public:
    /**
     * @brief Responsável por definir o CPF do usuário, que será utilizado nas ações da interface.
     * @param cpf CPF do usuário.
     */
    void set_CPF(string cpf);

    /**
     * @brief Responsável por fornecer ao usuário a leitura dos dados da conta do usuário.
     */
    void ler_c() override;

    /**
     * @brief Responsável por atualizar os dados da conta do usuário.
     */
    void atualizar_c() override;

    /**
     * @brief Responsável por excluir a conta do usuário.
     */
    void excluir_c() override;

    /**
     * @brief Responsável por direcionar o usuário a interface de apresentação de investimentos.
     */
    void ir_invest() override;

    /**
     * @brief Responsável por retirar o usuário da interface.
     */
    void sair_gerenConta() override;

    /**
     * @brief Responsável por executar as funcionalidades da classe.
     */
    void executar() override;

    /**
     * @brief Define a instância da interface de apresentação de investimentos.
     * @param i Instância de MAI.
     */
    void definir_i(MAI i);

    /**
     * @brief Define a instância da interface de autenticação de usuários.
     * @param a Instância de MAA.
     */
    void definir_a(MAA a);
};

#endif // MODULOS_H_INCLUDED
