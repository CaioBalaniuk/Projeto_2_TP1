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

#endif // MODULOS_H_INCLUDED
