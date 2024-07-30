#ifndef MODULOS_H_INCLUDED
#define MODULOS_H_INCLUDED

//Declaração do Módulo de Apresentação de Criação de Conta
class MACC : public IACC {
private:
    string cpf_rep;
    string nome_rep;
    string senha_rep;

public:
    bool informa_cpf(string) override;
    bool informa_nome(string) override;
    void sair_criacao() override;
    void executar();
};


#endif // MODULOS_H_INCLUDED
