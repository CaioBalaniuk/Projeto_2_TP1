#include <iostream>
#include "dominios.h"
#include <string>
#include <map>
#include <stdexcept>
#include <sstream>

using namespace std;
string alfabeto=("ABCDEFGHIJKLMNOPQRSTUVWXYZ");



//Metodos classe CodigoPagamento
CodigoPagamento::CodigoPagamento(int b=0){
    codigo=b;
};

void CodigoPagamento::setCodigoP(int a){
    if (a<9999999 || a>100000000){                     //checando se o codigo possui o numero de caracteres desejado
        throw invalid_argument("Codigo invalido.");
    }
    codigo=a;
};

int CodigoPagamento::getCodigoP(){
    return codigo;
};




//Metodos classe CodigoTitulo

CodigoTitulo::CodigoTitulo(string a=" "){
    codigo=a;
};

void CodigoTitulo::setCodigoT(string b){
    bool juri =true;
    int contador;
    apoio+=b[0];
    apoio+=b[1];           //apoio é uma string que possui os 3 primeiros caracteres do codigo a fim de tornar mais facil a checagem
    apoio+=b[2];
    if (apoio=="CDB" ||apoio=="CRA" ||apoio== "CRI" || apoio=="LCA" || apoio=="LCI" || apoio=="DEB"){ //checando se os 3 primeiros caracteres coincidem com as normas
        if (b.length()==11){ //checando se o codigo possui o número necessario de caracteres
            for (char i : b){
                contador=0;
                int len = alfabeto.length();
                for (int k=0;k<len;k+=1){  // checando se todos os caracteres são letras maiusculas
                    if (i==alfabeto[k]){
                        break;
                    }
                    else if (i>='0' && i<='9'){  //após checar se os caracteres não são letras maiusculas, checando se eles são numéricos
                        break;
                    };
                    contador+=1;
                };
                if (contador==(len)){
                    juri=false;
                    break;
                };
            };
            if (juri==true){ // se o juri permaneceu true, significa que não houve problemas, ou seja todos os caracteres estão de acordo com as normas,
            codigo=b;        // logo o codigo é valido
            }
            else{
                throw invalid_argument("Codigo invalido.");
            };
        }
        else{
            throw invalid_argument("Codigo invalido.");
        };
    }
    else{
        throw invalid_argument ("Codigo invalido.");
    };
};

string CodigoTitulo::getCodigoT(){
    return codigo;
};



//Metodos classe CPF

CPF::CPF(string c1=" "){
    cpf=c1;
};

string CPF::calcula_ultimos2(string c2){  //metodo apenas para calcular os ultimos 2 digitos do cpf
    int result=0;
    int peso1=10;
    int peso2=11;
    int m;
    string resp="";
    for (int p=0;p<11;p+=1){        //somando os nove primeiros digitos com seus pesos
        if (c2[p]!='.'){              //tirando os .
            m= (c2[p]);
            m=m-48;       //subtraindo o valor de int '0', para cada int 'numero' ter seu verdadeiro valor
            result+=(peso1*m);
            peso1-=1;
        };
    };
    result=result%11;
    if (result>=2){
        result=11-result;
        string apoi=to_string(result);          // adicionando à resposta o valor relacionado ao primeiro dos ultimos 2 digitos
        resp+=apoi;
    }
    else{
        string apoi=to_string(0);
        resp+=apoi;
    };
    result=0;
    for (int p1=0;p1<13;p1+=1){
        if (c2[p1]!='.' && c2[p1]!='-'){               //somando agora os 9 primeiros digitos com seus pesos, mas cm a adição do digito calculado a cima
            m=c2[p1];
            m=m-48;
            result+=(peso2*m);
            peso2-=1;
        };
    };
    result=result%11;
    if (result>=2){
        result=11-result;
        string apoi=to_string(result);
        resp+=apoi;
    }                                            //adicionando o ultimo digito à resposta
    else{
        string apoi=to_string(0);
        resp+=apoi;
    };
    return resp;
};

void CPF::setCPF(string c){
    apoio+=c[12];             //criando uma variavel que guarde os ultimos 2 digitos do cpf, para comparação com o calculo, a fim de verificar se é valido
    apoio+=c[13];
    bool juri=true;
    if (c.length()!=14){         //verificando se o a string colocada possuí o numero minimo de caracteres a fim de ser valída
        juri=false;
    };
    int l = c.length();
    for (int i=0;i<l;i+=1){
        if (i==11){
            if (c[i]!='-'){
                juri=false;      //verificando se o '-' está no lugar certo
                break;
            };
        }
        else if (i==3 || i==7){
            if (c[i]!='.'){          //verificando se os '.' estão no lugar certo
                juri=false;
                break;
            };
        }
        else if (c[i]<='0' && c[i]>='9'){
            juri=false;                         //verificando se todos os caracteres são numeros
            break;
        };
    };
    if (apoio != calcula_ultimos2(c)){      //chamando o metodo implementado a cima a fim de validar os ultimos 2 digitos
        juri=false;
    };
    if (juri==true){      // se todas as condições foram satisfeitas, o cpf será valido
        cpf=c;
    }
    else{
        throw invalid_argument ("CPF invalido."); //se alguma das condições não foi satisfeita o erro será lançado
    };
};

string CPF::getCPF(){
    return cpf;
};




//METODOS CLASSE DATA


void Data::arrumar(string d1){      //metodo que verifica se todos os caracteres, além dos hifens, são númericos e ainda arruma as variavies dia mes e ano
    string apoiodia="";             // as quais são usadas mais na frente no codigo;
    string apoiomes="";
    string apoioano="";
    for (int i=0;i<10;i+=1){
        if (i==0 || i==1){         //pega o dia
            apoiodia+=d1[i];

        }
        else if (i==3 || i==4){  // pega o mes
            apoiomes+=d1[i];
        }
        else if (i==6 || i==7 || i==8 ||i==9){   //pega o ano
            apoioano+=d1[i];
        };
    };
        dia=stoi(apoiodia);      //transforma a string possuindo o dia em um inteiro, se o a string não for composta apenas por caracteres númericos, vai dar erro.
        mes=stoi(apoiomes);      // transforma a string possuindo o mês em um inteiro, a explicação a cima se encaixa aqui também;
        ano=stoi(apoioano);      // faz a mesma coisa das outras mas com o ano;
};

bool Data::verifica_ano_bissexto() {
    for (int i = 2000; i <= 2100; i += 4) {         // verifica se o ano é bissexto, retornando true se for e false se não for;
        if (ano == i) {
            return true;
        };
    };
    return false;
}

bool Data::verifica_mes() {
    int tabela_sim[] = {1, 3, 5, 7, 8, 10, 12};   //verifica se o mês possui 31 dias ou não, retorna true se possuir e false se não possuir;
    int tabela_nao[] = {2, 4, 6, 9, 11};
    for (int i : tabela_sim) {
        if (i == mes) {
            return true;
        }
    };
    for (int i1 : tabela_nao) {
        if (i1 == mes) {
            return false;
        }
    }
    return false;
}

bool Data::verifica_dia() {   // verifica se o dia é valido com base seu mês e o ano;
    bool m = verifica_mes();
    bool b = verifica_ano_bissexto();
    if (dia > 00 && dia < 31 && mes != 2) {   // se for qualquer dia abaixo de 31 e diferente do mês 2, sempre estará certo;
        return true;
    } else if (dia == 29 && mes == 2 && b == true) {  //se for dia 29 e mês 2, mas for ano bissexto, está certo;
        return true;
    } else if (dia == 31 && m == true) {  //verifica se o mes pode ter 31 dias ou não com base na função implementada a cima;
        return true;                                                  // se for dia 31 e for um mês que possua 31 dias, está certo;
    } else if (dia > 00 && dia<29 && mes == 2) {
        return true;            // se for mês 2, mas qualquer dia abaixo de 29, estará sempre correto;
    } else {
        return false;   //se não se aplicar a nenhum dos casos corretos, estará sempre errado;
    }
}

void Data::setData(string d){
    bool juri=true;
    if (d[2]!='-' || d[5]!= '-'){   //verifica se os hifés existem e estão no lugar certo
        juri=false;
    };
    if (d.length()!=10){   //verifica se a string possui o numero correto de caracteres;
        juri=false;
    };
    try{
        arrumar(d);
    } catch (const invalid_argument& e){   // arruma as variaveis dia, mes e ano, além de verificar se os caracteres são todos númericos;
        juri=false;
    };
    if (mes<1 || mes>12){  //verifica se o mês existe;
        juri=false;
    };
    if (ano<2000 || ano>2100){  //verifica se o ano está no intervalo correto;
        juri=false;
    };
    if (verifica_dia() == false) {  //verifica se o dia é válido;
        juri = false;
    }

    if (juri==true){   // se nenhuma das possibilidades a cima foi encontrada, o juri permanecerá true e data será atribuida.
        data=d;
    }
    else {
        throw invalid_argument ("Data invalida.");  // se qualquer uma das possibilidades a cima for encontrada, será lançada exceção;
    };


};

string Data::getData(){
    return data;
};

//Metodos da Classe Percentual
Percentual::Percentual(int d) : percentual(d) {}

void Percentual::setPercentual(int a){
    if (a<0 || a>100) {
        throw invalid_argument("Percentual invalido.");
    }
    percentual=a;
}

int Percentual::getPercentual() const{
    return percentual;
}


//Metodos da Classe Senha
Senha::Senha(string d) : senha(d) {}

bool Senha::verificador_duplica(const string& password) {
    map<char, int> contador;
    for (char c : password) {
        contador[c]++;
        if(contador[c] > 1) {
            return true;
        }
    }
    return false;
}

bool Senha::verificador_ordem(const string& password) {
    if (password.size() < 2) return false;
        bool crescente = true;
        bool decrescente = true;
        for (size_t i = 0; i < password.size() - 1; ++i) {
            crescente &= password[i] < password[i+1];
            decrescente &= password[i] > password[i+1];
        }
        return crescente || decrescente;
}

void Senha::setSenha(const string& a) {
    string numeros = "0123456789";
    if (a.length()<=6){ //Verifica se tem no maximo 6 digitos
        if (a[0] != '0'){ //Verifica se o primeiro dígito eh diferente de 0
            int opera = 0;
            for (size_t i=0; i<a.length(); ++i){
                if(numeros.find(a[i])==std::string::npos){
                    opera++;
                }
            }
            if (opera==0) { //Verifica se todos digitos sao numericos
                if (verificador_duplica(a)==false && verificador_ordem(a)==false){
                    senha=a;
                }
                else{
                   throw invalid_argument ("Senha invalida.");
                }
            }
            else {
                throw invalid_argument ("Senha invalida.");
            }
        }
        else{
            throw invalid_argument ("Senha invalida.");
        }
    }
    else{
        throw invalid_argument ("Senha invalida.");
    }

}

string Senha::getSenha(){
    return senha;
}


//Metodos da Classe Nome
Nome::Nome(string m) : nome(m) {}

bool Nome::verificador_caracteres(const string& name){
    if (name.length()>=3 && name.length()<=10){
        return true;
    }
    else{
        return false;
    }
}

bool Nome::verificador_letras(const string& name){
    string letras="ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    int opera=0;
    for (size_t i=0;i<name.length();i++){
        if (letras.find(name[i])==std::string::npos){
            opera++;
        }
    }
    if (opera==0){
        return true;
    }
    else{
        return false;
    }
}

bool Nome::verificador_maiusculo(const string& name){
    if(!name.empty()){
        return std::isupper(name[0]);
    }
    return false;
}

vector<string> Nome::separador_strings(const string& name){
    vector<string> partes;
    istringstream iss(name);
    string parte;

    while (getline(iss,parte,' ')){
        partes.push_back(parte);
    }

    return partes;
}


void Nome::setNome(const string& a){
    int spaces = 0;
    for (char c : a){
        if (c==' '){
            spaces++;
        }
    }
    if (spaces>1){
        throw invalid_argument("Nome invalido.");
    }
    else{
        if (spaces==0){
            if (verificador_caracteres(a)==true && verificador_letras(a)==true && verificador_maiusculo(a)==true){
                nome=a;
            }
            else{
                throw invalid_argument("Nome invalido.");
            }
        }
        if (spaces==1){
            vector<string>lista=separador_strings(a);
            if (verificador_caracteres(lista[0])==true && verificador_letras(lista[0])==true && verificador_maiusculo(lista[0])==true && verificador_caracteres(lista[1])==true && verificador_letras(lista[1])==true && verificador_maiusculo(lista[1])==true){
                    nome=a;
            }
            else{
                throw invalid_argument("Nome invalido.");
            }
        }

    }
}

string Nome::getNome(){
    return nome;
}


//Implementacao metodos Setor
Setor::Setor(string a=" "){
    area=a;
}

void Setor::setSetor(string consultadearea) {
        if (consultadearea == "Agricultura" || consultadearea == "Construção civil" || consultadearea == "Energia" || consultadearea == "Finanças" || consultadearea == "Imobiliário" || consultadearea == "Papel e celulose" || consultadearea == "Pecuária" || consultadearea == "Química e petroquímica" || consultadearea == "Metalurgia e siderurgia" || consultadearea == "Mineração") {
            area = consultadearea;
        } else {
            throw invalid_argument("Setor invalido.");
        }
}

string Setor::getSetor(){
    return area;
}


//Implementacao metodos Estado
Estado::Estado(string a= " "){
    status=a;
}

void Estado::setEstado(string statusConfirmation){
        if (statusConfirmation == "Previsto" || statusConfirmation == "Liquidado" || statusConfirmation == "Inadimplente") {
            status = statusConfirmation;
        } else {
            throw invalid_argument("Erro: Estado Inexistente!");
        }
}

string Estado::getEstado(){
    return status;
}


//Implementacao metodos Dinheiro
Dinheiro::Dinheiro(){
    valor=0;
}

void Dinheiro::setDinheiro(float $) {
        if ($ >= 0 && $ <= 1000000) {  // o if verifica se o valor está dentro do intervalo permitido (0 a 1000000) e atribui o valor se estiver dentro do intervalo
            valor = $;
        } else {
            throw invalid_argument("Dinheiro invalido.");
        }
}

float Dinheiro::getDinheiro() {
        return valor;
}


