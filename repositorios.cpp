#include "repositorios.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

vector<string> RP::split(string s, char d) {
    vector<string> resp;
    int cont = 0;
    int con = 0;
    int comprimento = -1;
    for (char i : s ) {
        comprimento += 1;
        if (i == d) {
            resp.push_back(s.substr(cont,comprimento));
            cont = con + 1;
            comprimento = -1;
        }
        con +=1;
    }
    return resp;
}

void RP::start() {
    ifstream arq ("repositorio_p.txt");
    if (!arq.is_open()) {
        cerr<<"arquivo n abriu"<<endl;
    }
    string linha;
    string apoio;
    while (getline(arq, linha)) {
        apoio = linha.substr(0,11);
        repositorio_p.push_back(apoio);
    }
    arq.close();
}

void RP::adicionar(string codigo_t, string info) {
    ofstream arqu("repositorio_p.txt", ios::app);
    if (arqu.is_open()) {
        arqu<<codigo_t;
        arqu<<";";
        arqu<<info<<"\n";
        arqu.close();
    }
    repositorio_p.push_back(codigo_t);
}

string RP::listar_psr(string codigo_t) {
    ifstream ar("repositorio_p.txt");
    if (!ar.is_open()) {
        cerr<<"erro ao abrir arquivo"<<endl;
    }
    string li;
    string ap;
    while (getline(ar,li)) {
        ap = li.substr(0,11);
        if (ap == codigo_t) {
            break;
        }
    }
    vector <string> finale;
    string fim = "";
    finale = split(li + ';', ';');
    finale.erase(finale.begin());
    for (string i : finale) {
        fim += i.substr(0,8);
        fim += " ";
    }
    if (fim == "") {
      return "Linha nao encontrada";
    } else {
        return fim;
    }

}

void RP::add_pagamento(string codigo_t, string inf) {
    ifstream arqu("repositorio_p.txt");
    string l;
    string apoi;
    vector<string> ls;
    if (arqu.is_open()) {
        while (getline(arqu, l)) {
            ls.push_back(l);
        }
    }
    arqu.close();
    int cont = 0;
    for (string k : ls) {
        apoi = k.substr(0,11);
        if (apoi == codigo_t) {
            break;
        }
        cont +=1;
    }
    ls[cont] += ";";
    ls[cont] += inf;
    ofstream arquivo("repositorio_p.txt");
    for (string k1 : ls) {
        arquivo<<k1<<"\n";
    }
    arquivo.close();
}

void RP::excluir(string codigo_t) {
    ifstream arquivo("repositorio_p.txt");
    string linha;
    string apoio;
    vector<string> linhas;
    while (getline(arquivo,linha)) {
        linhas.push_back(linha);
    }
    arquivo.close();
    int contador = 0;
    for (string i : linhas) {
        apoio = i.substr(0,11);
        if (apoio == codigo_t) {
            linhas.erase(linhas.begin() + contador);
            break;
        }
        contador += 1;
    }
    ofstream arq ("repositorio_p.txt");
    for (string i1 : linhas) {
        arq<<i1<<endl;
    }
    arq.close();
}

void RP::excluir_linha_exist(string codigo_t, string info) {
    ifstream arquivo ("repositorio_p.txt");
    string linha;
    string apoio;
    vector<string> linhas;
    vector<string> need;
    vector<string> finale;
    while (getline(arquivo,linha)) {
        linhas.push_back(linha);
    }
    arquivo.close();
    int cont = 0;
    for (string i : linhas) {
        apoio = i.substr(0,11);
        if (apoio == codigo_t) {
            need = split(i + ' ',' ');
            break;
        }
        cont += 1;
    }
    int contador = 0;
    for (string i1 : need) {
        if (i1 == info) {
            need.erase(need.begin() + contador);
            break;
        }
        contador += 1;
    }
    linha = "";
    for (string i2 : need) {
        if (linha == "") {
            linha += i2;
        } else {
            linha += " ";
            linha += i2;
        }
    }
    int c = 0;
    for (string i3 : linhas) {
        if (c == cont) {
            finale.push_back(linha);
        } else {
            finale.push_back(i3);
        }
        c +=1;
    }
    ofstream arq ("repositorio_p.txt");
    for (string i4 : finale) {
        arq<<i4<<endl;
    }
    arq.close();
}

void RP::atualizar(string codigo_t, string info_a, string info_n) {
    fstream arquivo ("repositorio_p.txt");
    string linha;
    string apoio;
    vector<string> linhas;
    vector<string> need;
    vector<string> finale;
    while (getline(arquivo,linha)) {
        linhas.push_back(linha);
    }
    arquivo.close();
    int cont = 0;
    for (string i : linhas) {
        apoio = i.substr(0,11);
        if (apoio == codigo_t) {
            need = split(i + ' ',' ');
            break;
        }
        cont += 1;
    }
    int contador = 0;
    for (string i1 : need) {
        if (i1 == info_a) {
            need[contador] = info_n;
            break;
        }
        contador += 1;
    }
    linha = "";
    for (string i2 : need) {
        if (linha == "") {
            linha += i2;
        } else {
            linha += " ";
            linha += i2;
        }
    }
    int c = 0;
    for (string i3 : linhas) {
        if (c == cont) {
            finale.push_back(linha);
        } else {
            finale.push_back(i3);
        }
        c +=1;
    }
    ofstream arq ("repositorio_p.txt");
    for (string i4 : finale) {
        arq<<i4<<endl;
    }
    arq.close();
}

string RP::ler_pr(string codigo_t, string codigo_p) {
    ifstream ar("repositorio_p.txt");
    if (!ar.is_open()) {
        cerr<<"erro ao abrir arquivo"<<endl;
    }
    string li;
    string ap;
    while (getline(ar,li)) {
        ap = li.substr(0,11);
        if (ap == codigo_t) {
            break;
        }
    }
    vector <string> finale;
    string fim = "";
    finale = split(li + ';', ';');
    finale.erase(finale.begin());
    for (string i : finale) {

        if (i.substr(0,8) == codigo_p) {
            fim += i;
        }
    }
    ar.close();
    return fim;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
vector<string> RT::split(string s, char d) {
    vector<string> resp;
    int cont = 0;
    int con = 0;
    int comprimento = -1;
    for (char i : s ) {
        comprimento += 1;
        if (i == d) {
            resp.push_back(s.substr(cont,comprimento));
            cont = con + 1;
            comprimento = -1;
        }
        con +=1;
    }
    return resp;
}
void RT::start() {
    ifstream arq ("repositorio_t.txt");
    if (!arq.is_open()) {
        cerr<<"arquivo n abriu"<<endl;
    }
    string linha;
    string apoio;
    while (getline(arq, linha)) {
        apoio = linha.substr(0,14);
        repositorio.push_back(apoio);
    }
    arq.close();
}

void RT::adicionar(string cpf, string info) {
    ofstream arqu("repositorio_t.txt", ios::app);
    if (arqu.is_open()) {
        arqu<<cpf;
        arqu<<";";
        arqu<<info<<"\n";
        arqu.close();
    }
    repositorio.push_back(cpf);
}

string RT::listar_tsr(string cpf) {
    ifstream ar("repositorio_t.txt");
    if (!ar.is_open()) {
        cerr<<"erro ao abrir arquivo"<<endl;
    }
    string li;
    string ap;
    vector<string> finale;
    string fim = "";
    while (getline(ar,li)) {
        ap = li.substr(0,14);
        if (ap == cpf) {
            break;
        }
    }
    finale = split(li + ';', ';');
    finale.erase(finale.begin());
    for (string k : finale) {
        fim += k.substr(0,11);
        fim += " ";
    }
    ar.close();
    if (fim == "") {
        return "Linha nao encontrada";
    } else {
        return fim;
    }
}

void RT::add_titulo(string cpf, string inf) {
    ifstream arqu("repositorio_t.txt");
    string l;
    string apoi;
    vector<string> ls;
    if (arqu.is_open()) {
        while (getline(arqu, l)) {
            ls.push_back(l);
        }
    }
    arqu.close();
    int cont = 0;
    for (string k : ls) {
        apoi = k.substr(0,14);
        if (apoi == cpf) {
            break;
        }
        cont +=1;
    }
    ls[cont] += ";";
    ls[cont] += inf;
    ofstream arquivo("repositorio_t.txt");
    for (string k1 : ls) {
        arquivo<<k1<<"\n";
    }
    arquivo.close();
}

void RT::excluir(string cpf) {
    ifstream arquivo("repositorio_t.txt");
    string linha;
    string apoio;
    vector<string> linhas;
    while (getline(arquivo,linha)) {
        linhas.push_back(linha);
    }
    arquivo.close();
    int contador = 0;
    for (string i : linhas) {
        apoio = i.substr(0,14);
        if (apoio == cpf) {
            linhas.erase(linhas.begin() + contador);
            break;
        }
        contador += 1;
    }
    ofstream arq ("repositorio_t.txt");
    for (string i1 : linhas) {
        arq<<i1<<endl;
    }
    arq.close();
}

void RT::excluir_titulo(string cpf, string codigo_t) {
    ifstream arquivo ("repositorio_t.txt");
    string linha;
    string apoio;
    vector<string> linhas;
    vector<string> need;
    vector<string> finale;
    while (getline(arquivo,linha)) {
        linhas.push_back(linha);
    }
    arquivo.close();
    int cont = 0;
    for (string i : linhas) {
        apoio = i.substr(0,14);
        if (apoio == cpf) {
            need = split(i + ';',';');
            break;
        }
        cont += 1;
    }
    int contador = 0;
    for (string i1 : need) {
        if (i1.substr(0,11) == codigo_t) {
            need.erase(need.begin() + contador);
            break;
        }
        contador += 1;
    }
    linha = "";
    for (string i2 : need) {
        if (linha == "") {
            linha += i2;
        } else {
            linha += ";";
            linha += i2;
        }
    }
    int c = 0;
    for (string i3 : linhas) {
        if (c == cont) {
            finale.push_back(linha);
        } else {
            finale.push_back(i3);
        }
        c +=1;
    }
    ofstream arq ("repositorio_t.txt");
    for (string i4 : finale) {
        arq<<i4<<endl;
    }
    arq.close();
}

string RT::ler_tr(string cpf, string codigo_t) {
    ifstream ar("repositorio_t.txt");
    if (!ar.is_open()) {
        cerr<<"erro ao abrir arquivo"<<endl;
    }
    string li;
    string ap;
    vector<string> finale;
    string fim = "";
    int cont1 = 0;
    int cont2 = 0;
    while (getline(ar,li)) {
        ap = li.substr(0,14);
        if (ap == cpf) {
            break;
        }
    }
    finale = split(li + ';', ';');
    finale.erase(finale.begin());
    for (string k : finale) {
        if (k.substr(0,11) == codigo_t) {
            fim = k;
        }
    }
    ar.close();
    return fim;
}

void RT::atualizar(string cpf, string codigo_t, string info_a, string info_n) {
    fstream arquivo ("repositorio_t.txt");
    string linha;
    string apoio;
    vector<string> linhas;
    vector<string> need;
    vector<string> finale;
    while (getline(arquivo,linha)) {
        linhas.push_back(linha);
    }
    arquivo.close();
    int cont = 0;
    for (string i : linhas) {
        apoio = i.substr(0,14);
        if (apoio == cpf) {
            need = split(i + ';',';');
            break;
        }
        cont += 1;
    }
    int contador = 0;
    int co = 0;
    vector<string> aaa;
    for (string i1 : need) {
        if (i1.substr(0,11) == codigo_t) {
            aaa = split(i1 + ' ', ' ');
            for (string i4 : aaa) {
                if (i4 == info_a) {
                    aaa[contador] = info_n;
                    break;
                }
                contador += 1;
            }
           break;
        }
        co += 1;
    }

    string linhaa = "";
    for (string i5 : aaa) {
        if (linhaa == "") {
            linhaa += i5;
        } else {
            linhaa += " ";
            linhaa += i5;
        }
    }
    need[co] = linhaa;
    linha = "";
    for (string i2 : need) {
        if (linha == "") {
            linha += i2;
        } else {
            linha += ";";
            linha += i2;
        }
    }
    int c = 0;
    for (string i3 : linhas) {
        if (c == cont) {
            finale.push_back(linha);
        } else {
            finale.push_back(i3);
        }
        c +=1;
    }
    ofstream arq ("repositorio_t.txt");
    for (string i4 : finale) {
        arq<<i4<<endl;
    }
    arq.close();
}
