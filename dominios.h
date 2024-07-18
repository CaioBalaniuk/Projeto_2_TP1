#include <string>
#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
#include <vector>

using namespace std;

//Classe Codigo Pagamento
class CodigoPagamento{
 private:
    int codigo;
 public:
    CodigoPagamento(int);
    void setCodigoP(int);
    int getCodigoP();
};
// Classe Codigo Titulo
class CodigoTitulo{
    private:
        string codigo;
        string apoio = "";
    public:
        CodigoTitulo(string);
        void setCodigoT(string);
        string getCodigoT();
};
//Classe CPF
class CPF{
    private:
        string cpf;
        string apoio="";
        string calcula_ultimos2(string);
    public:
        CPF(string);
        void setCPF(string);
        string getCPF();
};
// Classe Data
class Data{
    private:
        string data;
        int dia;
        int mes;
        int ano;
        void arrumar(string);
        bool verifica_dia();
        bool verifica_mes();
        bool verifica_ano_bissexto();
    public:
        void setData(string);
        string getData();
};



//Classe Percentual
class Percentual{
private:
    int percentual;
public:
    Percentual(int d=0);
    void setPercentual(int a);
    int getPercentual() const;
};

//Classe Senha
class Senha{
private:
    string senha;
    bool verificador_duplica(const string& password);
    bool verificador_ordem(const string& password);
public:
    Senha(string d=" ");
    void setSenha(const string& a);
    string getSenha();
};

//Classe Nome
class Nome{
private:
    string nome;
    bool verificador_caracteres(const string& name);
    bool verificador_letras(const string& name);
    bool verificador_maiusculo(const string& name);
    vector<string> separador_strings(const string& name);

public:
    Nome(string m=" ");
    void setNome(const string& a);
    string getNome();
};




class Setor {
private:
    string area; // declarando a variavel do valor do dinheiro que será em float porque é um valor em reais

public:
    Setor(string);
    void setSetor(string consultadearea);  // o método é atribuir um valor caso ele esteja entre 0 e 1000000 e retornar um erro caso venha uma exceção, e para isso se deve utilizar o método set
    string getSetor(); // o método get é usado para retornar um valor no output
};

class Estado {
private:
    string status; // a variavel será em string pois são 3 nomes de 3 estados

public:
    Estado(string);
    void setEstado(string statusConfirmation); // método para definir o status (estado), verificando se é um dos valores permitidos, e emitindo um erro caso seja uma exceção, através do if
    string getEstado(); // método get para obter o "status"
};

class Dinheiro {
private:
    float valor; // declarando a variavel do valor do dinheiro que será em float porque é um valor em reais

public:
    Dinheiro();
    void setDinheiro(float $); // o método é atribuir um valor caso ele esteja entre 0 e 1000000 e retornar um erro caso venha uma exceção, e para isso se deve utilizar o método set
    float getDinheiro(); // o método get é usado para retornar um valor no output
};

#endif // DOMINIOS_H_INCLUDED

