#ifndef REPOSITORIOS_H_INCLUDED
#define REPOSITORIOS_H_INCLUDED
#include<vector>
#include<string>
using namespace std;
class RP {
private:
    vector<string> repositorio_p;
    vector<string> split(string, char);
public:
    void start();
    void adicionar(string, string);
    string listar_psr(string);
    void add_pagamento(string, string);
    void excluir(string);
    void excluir_linha_exist(string,string);
    void atualizar (string, string, string);
    string ler_pr(string, string);
};

class RT {
private:
    vector<string> repositorio;
    vector<string> split(string, char);
public:
    void start();
    void adicionar(string, string);
    string listar_tsr(string);
    void add_titulo(string, string);
    void excluir(string);
    void excluir_titulo(string,string);
    void atualizar (string, string, string, string);
    string ler_tr(string, string);
};

class RC {
private:
    vector<string> repositorio;
    vector<string> split(string, char);
public:
    void start(); 
    void adicionar_c(string, string); 
    void add_linha_exist(string, string); 
    string ler_c(string);
    void excluir_c(string); 
    void atualizar_c (string, string, string); 
};



#endif // REPOSITORIOS_H_INCLUDED
