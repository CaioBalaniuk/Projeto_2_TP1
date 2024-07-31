#ifndef MODULOS_H_INCLUDED
#define MODULOS_H_INCLUDED

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


#endif // MODULOS_H_INCLUDED
