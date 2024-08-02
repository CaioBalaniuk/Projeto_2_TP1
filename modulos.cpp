#include <iostream>
#include "modulos.h"
#include "dominios.h"
#include "entidades.h"
#include "repositorios.h"
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


//Implementação do Módulo de Serviço de Gerenciamento de Conta
string MSGC::ler_cs(string cpf){
    RC repositorio;
    repositorio.start();
    repositorio.ler_c(cpf)
}

bool MSGC::alterar_senha(string cpf, string senha_nova){
    try{
        Senha* ponteiro_senha = new Senha();
        ponteiro_senha->setSenha(senha_nova);
        
        RC repositorio;
        repositorio.start();
        string original = repositorio.ler_c(cpf);
        string velha = original.substr(original.length() - 6, 6);
        
        repositorio.atualizar_c(cpf, velha, senha_nova);

    } catch(const invalid_argument& e){
        return false;
    }
}

bool MSGC::alterar_nome(string cpf, string nome_novo){
    try{
        Nome* ponteiro_nome = new Nome();
        ponteiro_nome->setNome(nome_novo);
        
        RC repositorio;
        repositorio.start();
        string original = repositorio.ler_c(cpf);
        string velha = original.substr(0, original.length() - 6);
        
        repositorio.atualizar_c(cpf, velha, nome_novo);

    } catch(const invalid_argument& e){
        return false;
    }
}

void MSGC::excluir_cs(string cpf){
    RC repositorio;
    repositorio.start();
    repositorio.excluir_c(cpf);
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// implementação Modulo serviço investimentos
string MSI::listar_ts(string cpf) {
    return repositorio_t -> listar_tsr(cpf);
}

bool MSI::salvar_dados_t(Titulo* tit) {
    bool juri = true;
    vector<string> apoio;
    string cpf;
    string resto = "";
    apoio = tit->getTitulo();
    if (apoio.empty()) {
        juri = false;
    }
    cpf = apoio[6];
    apoio.erase(apoio.begin() + 6);
    for (string i : apoio) {
        if (resto == "") {
            resto += i;
        } else {
            resto += " ";
            resto += i;
        }
    }
    string a = repositorio_t ->listar_tsr(cpf);
    if (a == "Linha nao encontrada") {
        repositorio_t->adicionar(cpf, resto);
    } else {
        repositorio_t->add_titulo(cpf, resto);
    }

    return juri;
}

string MSI::ler_ts(string cpf, string codigo_t) {
    return repositorio_t ->ler_tr(cpf,codigo_t);
}

bool MSI::atualizar_dados_t(string cpf, string codigo_t, string dado_a, string dado_n) {
    bool juri = true;
    string com1 = repositorio_t ->ler_tr(cpf,codigo_t);
    repositorio_t ->atualizar(cpf,codigo_t,dado_a,dado_n);
    string com2 = repositorio_t ->ler_tr(cpf,codigo_t);
    if (com1 == com2) {
        juri = false;
    }
    return juri;
}

bool MSI::excluir_ts(string cpf, string codigo_t) {
    bool juri = true;
    string com1 = repositorio_t ->listar_tsr(cpf);
    repositorio_t ->excluir_titulo(cpf,codigo_t);
    string com2 = repositorio_t ->listar_tsr(cpf);
    if (com1 == com2) {
        juri = false;
    }
    return juri;
}

string MSI::listar_ps(string codigo_t) {
    return repositorio_p ->listar_psr(codigo_t);
}

bool MSI::salvar_dados_p(Pagamento* pag) {
    bool juri = true;
    string codigo_t;
    string resto = "";
    tuple<int, string, int, string, string> apoio;
    apoio = pag ->getPagamento();
    codigo_t = get<4>(apoio);
    resto += to_string(get<0>(apoio));
    resto += " ";
    resto += get<1>(apoio);
    resto += " ";
    resto += to_string(get<2>(apoio));
    resto += " ";
    resto += get<3>(apoio);
    string com1 = repositorio_p ->listar_psr(codigo_t);
    if (com1 == "Linha nao encontrada") {
        repositorio_p ->adicionar(codigo_t, resto);
    } else {
        repositorio_p ->add_pagamento(codigo_t,resto);
    }
    string com2 = repositorio_p ->listar_psr(codigo_t);
    if (com1 == com2) {
        juri = false;
        cout<<"porra";
    }
    return juri;

}

string MSI::ler_ps(string codigo_t, int codigo_p) {
    string codigo = to_string(codigo_p);
    return repositorio_p ->ler_pr(codigo_t,codigo);
}

bool MSI::atualizar_dados_p(string codigo_t, int codigo_p, string info_a, string info_n) {
    bool juri = true;
    string com1 = repositorio_p ->ler_pr(codigo_t, to_string(codigo_p));
    repositorio_p ->atualizar(codigo_t, codigo_p, info_a, info_n);
    string com2 = repositorio_p ->ler_pr(codigo_t, to_string(codigo_p));
    if (com1 == com2) {
        juri = false;
    }
    return juri;
}

bool MSI::excluir_ps(string codigo_t, int codigo_p) {
    bool juri = true;
    string com1 = repositorio_p ->listar_psr(codigo_t);
    repositorio_p ->excluir_pag(codigo_t, codigo_p);
    string com2 = repositorio_p ->listar_psr(codigo_t);
    if (com1 == com2) {
        juri = false;
    }
    return juri;
}
///////////////////////////////////////////////////////////////////////////////////////
//implementação Modulo apresentação investimentos
string MAI::listar_t() {
    string cpf;
    cout<<"Digite seu CPF: "<<endl;
    getline(cin,cpf);
    string lista = servico->listar_ts(cpf);
    if (lista == "Linha nao encontrada") {
        cout<<"CPF nao encontrado"<<endl;
        cpf = "";
    } else {
        cout<<"Seu(s) titulos sao: "<<lista<<endl;
    }
    return cpf;
}

void MAI::criar_t() {
    vector<string> infos;
    string apoio;
    Titulo* titulo = new Titulo;
    bool juri = false;
    while (juri == false) {
        juri = true;
        cout<<"Digite, em ordem e um de cada vez, Codigo Titulo, Nome, Setor, Data de emissao, Data de vencimento, Valor e CPF."<<endl;
        for (int i = 0; i < 7; ++i) {
            getline(cin,apoio);
            infos.push_back(apoio);
        }
        try {
            titulo->setTitulo(infos[0],infos[1],infos[2],infos[3],infos[4], stoi(infos[5]),infos[6]);
            juri = true;
        } catch (const invalid_argument& e) {
            juri = false;
        }
    }
    bool fim = servico->salvar_dados_t(titulo);
    if (fim) {
        cout<<"Titulo criado com sucesso!"<<endl;
    } else {
        cout<<"Falha ao tentar criar Titulo."<<endl;
    }

}

void MAI::ler_t() {
    string cpf;
    string codigo_t;
    cout<<"Informe seu CPF: "<<endl;
    getline(cin,cpf);
    string dale = servico->listar_ts(cpf);
    if (dale == "Linha nao encontrada") {
        cout<<"CPF nao encontrado"<<endl;
    } else {
        cout<<"Esses sao seus titulos: "<<dale<<" Escolha qual deles vai querer ler e escreva"<<endl;
        getline(cin,codigo_t);
        cout<<servico->ler_ts(cpf,codigo_t);
    }
}

void MAI::atualizar_t() {
    string cpf;
    string codigo_t;
    string info_a;
    string info_n;
    cpf = listar_t();
    if (cpf != "") {
        cout<<"Escolha qual Titulo deseja alterar e digite seu codigo."<<endl;
        getline(cin,codigo_t);
        cout<<servico->ler_ts(cpf,codigo_t)<<endl;;
        cout<<"Agora, digite qual informacao deseja alterar (da maneira que esta escrita), e depois digite a informacao";
        cout<<" nova (da maneira que sera escrita)."<<endl;
        getline(cin,info_a);
        getline(cin,info_n);
        bool fim = servico->atualizar_dados_t(cpf,codigo_t,info_a,info_n);
        if (fim) {
            cout<<"Titulo alterado com sucesso!"<<endl;
        } else {
            cout<<"Erro ao tentar alterar seu Titulo."<<endl;
        }
    }
}

void MAI::excluir_t() {
    string cpf;
    string codigo_t;
    cout<<"Informe seu CPF para dar inicio a operacao"<<endl;
    getline(cin,cpf);
    cout<<"Esses sao seus Titulos atualmente: "<<servico->listar_ts(cpf);
    cout<<" Escolha qual deles quer apagar e digite abaixo: "<<endl;
    getline(cin,codigo_t);
    bool fim = servico->excluir_ts(cpf,codigo_t);
    if (fim) {
        cout<<"Titulo excluido com sucesso!"<<endl;
    } else {
        cout<<"Erro ao tentar excluir esse Titulo."<<endl;
    }
}

void MAI::listar_p() {
    listar_t();
    string codigo_t;
    cout<<"Informe abaixo o codigo do Titulo que deseja listar os pagamentos: "<<endl;
    getline(cin,codigo_t);
    string dale = servico->listar_ps(codigo_t);
    if (dale == "Linha nao encontrada") {
        cout<<"Esse Titulo ainda nao tem pagamentos."<<endl;
    } else {
        cout<<"Esses sao os pagamentos do Titulo "<<codigo_t<<": ";
        cout<<dale<<endl;
    }
}

void MAI::criar_p() {
    Pagamento* pagamento = new Pagamento;
    int codigo_p;
    string apoio1;
    string data;
    int percentual;
    string apoio2;
    string estado;
    string codigo_t;
    bool juri = false;
    while (juri == false) {
        juri = true;
        cout<<"Informe, em ordem, o Codigo de Pagamento, a Data, o Percentual, o Estado, e o Codigo do Titulo que o pagamento pertence."<<endl;
        getline(cin,apoio1);
        codigo_p = stoi(apoio1);
        getline(cin,data);
        getline(cin,apoio2);
        percentual = stoi(apoio2);
        getline(cin,estado);
        getline(cin,codigo_t);
        try {
            pagamento->setPagamento(codigo_p, data, percentual, estado, codigo_t);
        } catch (const invalid_argument& e) {
            juri = false;
        }
    }
    bool fim = servico->salvar_dados_p(pagamento);
    if (fim) {
        cout<<"Pagamento criado com sucesso!"<<endl;
    } else {
        cout<<"Erro ao tentar criar Pagamento."<<endl;
    }
}

vector<string> MAI::ler_p() {
    int codigo_p;
    string apoio;
    string codigo_t;
    vector<string> retorno;
    string juri = listar_t();
    if (juri != "") {
        cout<<"Informe o codigo do Titulo que deseja ler o pagamento: "<<endl;
        getline(cin,codigo_t);
        string dale = servico->listar_ps(codigo_t);
        if (dale != "Linha nao encontrada") {
            cout<<"Esses sao os pagamentos desse Titulo: "<<dale;
            cout<<" Escolha e digite qual desses pagamentos quer ler"<<endl;
            getline(cin,apoio);
            codigo_p = stoi(apoio);
            cout<<servico->ler_ps(codigo_t, codigo_p);
            retorno.push_back(codigo_t);
            retorno.push_back(to_string(codigo_p));
            return retorno;
        } else {
            cout<<"Esse Titulo nao tem pagamentos."<<endl;
            return retorno;
        }
    } else {
        return retorno;
    }
}

void MAI::atualizar_p() {
    string codigo_t;
    int codigo_p;
    string info_a;
    string info_n;
    vector<string> apoio;
    apoio = ler_p();
    codigo_t = apoio[0];
    codigo_p = stoi(apoio[1]);
    cout<<endl<<"Agora, escolha qual informação sera alterada e a digite(da maneira que esta escrita) e depois digite a nova informacao";
    cout<<" (da maneira que ela sera escrita)."<<endl;
    getline(cin,info_a);
    getline(cin,info_n);
    bool fim = servico->atualizar_dados_p(codigo_t,codigo_p,info_a,info_n);
    if (fim) {
        cout<<"Pagamento alterado com sucesso!"<<endl;
    } else {
        cout<<"Erro ao alterar pagamento."<<endl;
    }
}

void MAI::excluir_p() {
    string codigo_t;
    string apoio;
    int codigo_p;
    listar_t();
    cout<<"Informe o codigo Titulo em que o pagamento a ser excluido se encontra"<<endl;
    getline(cin,codigo_t);
    cout<<"Esses sao os pagamentos desse titulo no momento: "<<servico->listar_ps(codigo_t);
    cout<<" Escolha e digite qual deles deseja excluir"<<endl;
    getline(cin,apoio);
    codigo_p = stoi(apoio);
    bool fim = servico->excluir_ps(codigo_t, codigo_p);
    if (fim) {
        cout<<"Pagamento excluido com sucesso!"<<endl;
    } else {
        cout<<"Erro ao tentar excluir Pagamento."<<endl;
    }
}

void MAI::sair() {
   nullptr;
}

void MAI::executar() {
    string a;
    int acao;
    bool juri = true;
    while (juri) {
        cout<<"Escolha qual acao quer realizar e digite seu numero: "<<endl;
        cout<<"1. Criar titulo"<<endl;
        cout<<"2. Listar Titulos"<<endl;
        cout<<"3. Ler Titulo"<<endl;
        cout<<"4. Atualizar Titulo"<<endl;
        cout<<"5. Excluir Titulo"<<endl;
        cout<<"6. Criar Pagamento"<<endl;
        cout<<"7. Listar Pagamentos"<<endl;
        cout<<"8. Ler Pagamento"<<endl;
        cout<<"9. Atualizar Pagamento"<<endl;
        cout<<"10. Excluir Pagamento"<<endl;
        cout<<"11. Sair"<<endl;
        getline(cin,a);
        acao = stoi(a);
        switch (acao) {
            case 1:
                criar_t();
                cout<<endl;
                cout<<endl;
                break;
            case 2:
                listar_t();
                cout<<endl;
                cout<<endl;
                break;
            case 3:
                ler_t();
                cout<<endl;
                cout<<endl;
                break;
            case 4:
                atualizar_t();
                cout<<endl;
                cout<<endl;
                break;
            case 5:
                excluir_t();
                cout<<endl;
                cout<<endl;
                break;
            case 6:
                criar_p();
                cout<<endl;
                cout<<endl;
                break;
            case 7:
                listar_p();
                cout<<endl;
                cout<<endl;
                break;
            case 8:
                ler_p();
                cout<<endl;
                cout<<endl;
                break;
            case 9:
                atualizar_p();
                cout<<endl;
                cout<<endl;
                break;
            case 10:
                excluir_p();
                cout<<endl;
                cout<<endl;
                break;
            case 11:
                juri = false;
                break;
            default:
                cout<<"Acao invalida."<<endl;
                cout<<endl;
      }
    }

}


