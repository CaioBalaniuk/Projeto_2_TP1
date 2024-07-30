#include <iostream>
#include <vector>
#include <stdexcept>
#include <tuple>
#include <string>
#include <sstream>
#include <map>

using namespace std;

class MACC : public IACC {
private:
    string cpf_rep;
    string nome_rep;
    string senha_rep;

public:
    bool informa_cpf(string) override;
    bool informa_nome(string) override;
    bool informa_senha(string) override;
    void sair_criacao() override;
    void executar();
};

bool MACC::informa_cpf(string cpf){
    try{
        CPF* ponteiro_cpf = new CPF();
        ponteiro_cpf->setCPF(cpf);
        return true;
    } catch(const invalid_argument& e){
        return false;
    }
}

bool MACC::informa_nome(string nome){
    try{
        Nome* ponteiro_nome = new Nome();
        ponteiro_nome->setNome(nome);
        return true;
    } catch(const invalid_argument& e){
        return false;
    }
}

bool MACC::informa_senha(string senha){
    try{
        Senha* ponteiro_senha = new Senha();
        ponteiro_senha->setSenha(senha);
        return true;
    } catch(const invalid_argument& e){
        return false;
    }
}

void MACC::executar(){
    cout << "Informe seu CPF:" << endl;
    cin << cpf_rep << endl;
    while (informa_cpf(cpf_rep) == false) {
        cout << "O CPF n�o est� no formato v�lido." << endl;
        cout << "Informe seu CPF:" << endl;
        cin << cpf_rep << endl;
    }

    RC repositorio;
    if (cpf_rep == repositorio.buscar(cpf_rep)){
        cout << "A conta com o CPF " << cpf_rep << "j� existe." << endl;
        sair_criacao();

    } else {
        cout << "Informe seu Nome:" << endl;
        cin << nome_rep << endl;
        while (informa_nome(nome_rep) == false) {
            cout << "O Nome n�o est� no formato v�lido." << endl;
            cout << "Informe seu Nome:" << endl;
            cin << nome_rep << endl;
        }

        cout << "Informe sua Senha:" << endl;
        cin << senha_rep << endl;

        cout << "Conta criada com Sucesso !!!"

        RC.adicionar(cpf_rep, nome_rep);
        RC.add_linha_exist(cpf_rep, senha_rep);
    }

}



