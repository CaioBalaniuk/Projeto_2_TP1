#include <iostream>
#include "modulos.h"
#include "dominios.h"
#include "entidades.h"
#include <vector>
#include <stdexcept>
#include <tuple>
#include <string>
#include <sstream>
#include <map>

using namespace std;

//Implementação do Módulo de Apresentação de Criação de Conta
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
        cout << "O CPF não está no formato válido." << endl;
        cout << "Informe seu CPF:" << endl;
        cin << cpf_rep << endl;
    }

    RC repositorio_cont;
    repositorio_cont.start();
    
    if (repositorio_cont.ler_c() != "Linha nao encontrada"){
        cout << "A conta com o CPF " << cpf_rep << "já existe." << endl;
        sair_criacao();

    } else {
        cout << "Informe seu Nome:" << endl;
        cin << nome_rep << endl;
        while (informa_nome(nome_rep) == false) {
            cout << "O Nome não está no formato válido." << endl;
            cout << "Informe seu Nome:" << endl;
            cin << nome_rep << endl;
        }

        cout << "Informe sua Senha:" << endl;
        cin << senha_rep << endl;
        while (informa_senha(senha_rep) == false) {
            cout << "A Senha não está no formato válido." << endl;
            cout << "Informe sua Senha:" << endl;
            cin << senha_rep << endl;
        }
        
        mscc->salvar_dados(cpf_rep, nome_rep, senha_rep);

        cout << "Conta criada com Sucesso !!!"

        sair_criacao();
    }

}


//Implementação do Módulo de Serviço de Criação de Conta
void MSCC::salvar_dados(string cpf, string nome, string senha){
    RC repositorio;
    repositorio.start();
    repositorio.adicionar_c(cpf, nome);
    repositorio.add_linha_exist(cpf, senha);
} 




