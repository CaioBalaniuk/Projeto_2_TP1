#include <iostream>
#include <vector>
#include <string>
#include <fstream>
using namespace std;

class RI {
public:
    vector<string> repositorio;
    void start();
    void adicionar(string, string);
    string buscar(string);
    void add_linha_exist(string, string);
    void excluir(string);
    void excluir_linha_exist(string,string);
    vector<string> split(string, char);
    void atualizar (string, string, string);


};

vector<string> RI::split(string s, char d) {
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

void RI::start() {
    ifstream arq ("repositorio.txt");
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

void RI::adicionar(string cpf, string info) {
    ofstream arqu("repositorio.txt", ios::app);
    if (arqu.is_open()) {
        arqu<<cpf;
        arqu<<" ";
        arqu<<info<<"\n";
        arqu.close();
    }
    repositorio.push_back(cpf);
}

string RI::buscar(string cpf) {
    ifstream ar("repositorio.txt");
    if (!ar.is_open()) {
        cerr<<"erro ao abrir arquivo"<<endl;
    }
    string li;
    string ap;
    while (getline(ar,li)) {
        ap = li.substr(0,14);
        if (ap == cpf) {
            ar.close();
            return li.substr(14,-1);
        }
    }
    ar.close();
    return "Linha nao encontrada";
}
void RI::add_linha_exist(string cpf, string inf) {
    ifstream arqu("repositorio.txt");
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
    ls[cont] += " ";
    ls[cont] += inf;
    ofstream arquivo("repositorio.txt");
    for (string k1 : ls) {
        arquivo<<k1<<"\n";
    }
    arquivo.close();
}
void RI::excluir(string cpf) {
    ifstream arquivo("repositorio.txt");
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
    ofstream arq ("repositorio.txt");
    for (string i1 : linhas) {
        arq<<i1<<endl;
    }
    arq.close();
}

void RI::excluir_linha_exist(string cpf, string info) {
    ifstream arquivo ("repositorio.txt");
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
    ofstream arq ("repositorio.txt");
    for (string i4 : finale) {
        arq<<i4<<endl;
    }
    arq.close();
}

void RI::atualizar(string cpf, string info_a, string info_n) {
    fstream arquivo ("repositorio.txt");
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
    ofstream arq ("repositorio.txt");
    for (string i4 : finale) {
        arq<<i4<<endl;
    }
    arq.close();
}
