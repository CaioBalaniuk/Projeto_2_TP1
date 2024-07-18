#include <iostream>
#include "entidades.h"
#include <string>
#include <stdexcept>
#include <vector>
#include <tuple>


using namespace std;

//Implementação da Classe Pagamento
void Pagamento::setPagamento(int novo_codigo, string nova_data, int novo_percentual, string novo_estado){
    codigo.setCodigoP(novo_codigo);
    data.setData(nova_data);
    percentual.setPercentual(novo_percentual);
    estado.setEstado(novo_estado);
}

tuple<int, string, int, string> Pagamento::getPagamento(){
    int f_codigo = codigo.getCodigoP();
    string f_data = data.getData();
    int f_percentual = percentual.getPercentual();
    string f_estado = estado.getEstado();

    return make_tuple(f_codigo, f_data, f_percentual, f_estado);
}


//Implementação da classe Titulo;
void Titulo::setTitulo(string novo_codigo, string novo_nome, string novo_setor, string nova_emissao, string novo_vencimento, float novo_valor) {
    codigo.setCodigoT(novo_codigo);
    emissor.setNome(novo_nome);
    setor.setSetor(novo_setor);
    emissao.setData(nova_emissao);
    vencimento.setData(novo_vencimento);
    valor.setDinheiro(novo_valor);
}

vector<string> Titulo::getTitulo() {
    vector<string> resp;
    string g_codigo = codigo.getCodigoT();
    string g_emissor = emissor.getNome();
    string g_setor = setor.getSetor();
    string g_emissao = emissao.getData();
    string g_vencimento = vencimento.getData();
    string g_valor = to_string(valor.getDinheiro());
    resp.push_back(g_codigo);
    resp.push_back(g_emissor);
    resp.push_back(g_setor);
    resp.push_back(g_emissao);
    resp.push_back(g_vencimento);
    resp.push_back(g_valor);
    return resp;
}


//Implementação da Classe Conta
void Conta::setConta(string novo_cpf, string nova_nome, string novo_senha){
    cpf.setCPF(novo_cpf);
    nome.setNome(nova_nome);
    senha.setSenha(novo_senha);
}

tuple<string, string, string> Conta::getConta(){
    string f_cpf = cpf.getCPF();
    string f_nome = nome.getNome();
    string f_senha = senha.getSenha();

    return make_tuple(f_cpf, f_nome, f_senha);
}
