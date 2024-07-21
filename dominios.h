#include <string>
#ifndef DOMINIOS_H_INCLUDED
#define DOMINIOS_H_INCLUDED
#include <vector>

using namespace std;


/**
 * @class CodigoPagamento
 * @brief Representa o domínio Código de Pagamento (Feito por: 231025190).
 */
class CodigoPagamento {
private:
    int codigo; /**< Código de pagamento. */

public:
    /**
     * @brief Construtor do domínio Código de Pagamento.
     * @param codigo Código de Pagamento.
     */
    CodigoPagamento(int codigo);

    /**
     * @brief Método para definir o código de pagamento.
     * @param codigo Novo código de pagamento.
     * @throws invalid_argument Se o código não for válido.
     */
    void setCodigoP(int codigo);

    /**
     * @brief Obtém o código de pagamento.
     * @return O código de pagamento atual.
     */
    int getCodigoP();
};


/**
 * @class CodigoTitulo
 * @brief Representa o domínio Código de Título (Feito por: 231025190).
 */
class CodigoTitulo {
private:
    std::string codigo; /**< Código do título. */
    std::string apoio = ""; /**< Campo de apoio para manipulação interna. */

public:
    /**
     * @brief Construtor do domínio Código de Título.
     * @param codigo Código de Título a ser atribuído.
     */
    CodigoTitulo(std::string codigo);

    /**
     * @brief Método para definir o código de título.
     * @param codigo Novo código de título.
     * @throws invalid_argument Se o código de título não for válido.
     */
    void setCodigoT(std::string codigo);

    /**
     * @brief Obtém o código de título.
     * @return O código de título atual.
     */
    std::string getCodigoT();
};


/**
 * @class CPF
 * @brief Representa o domínio CPF (Feito por: 231025190).
 */
class CPF {
private:
    std::string cpf; /**< Número do CPF. */
    std::string apoio = ""; /**< Campo de apoio para manipulação interna. */

    /**
     * @brief Método para auxiliar na validação do CPF por meio da análise dos dois últimos dígitos.
     * @param cpf Número do CPF.
     * @return Os dois últimos dígitos calculados.
     */
    std::string calcula_ultimos2(std::string cpf);

public:
    /**
     * @brief Construtor do domínio CPF.
     * @param cpf Número do CPF a ser atribuído.
     */
    CPF(std::string cpf);

    /**
     * @brief Método para definir o número do CPF.
     * @param cpf Novo número do CPF.
     * @throws invalid_argument Se o CPF não for válido.
     */
    void setCPF(std::string cpf);

    /**
     * @brief Obtém o número do CPF.
     * @return O número do CPF atual.
     */
    std::string getCPF();
};


/**
 * @class Data
 * @brief Representa o domínio Data (Feito por: 231025190).
 */
class Data {
private:
    std::string data; /**< Data completa em formato string. */
    int dia; /**< Dia da data. */
    int mes; /**< Mês da data. */
    int ano; /**< Ano da data. */

    /**
     * @brief Método para ajusta a string de data para o formato correto.
     * @param data Data em formato string.
     */
    void arrumar(std::string data);

    /**
     * @brief Método para verificar se o dia é válido.
     * @return Verdadeiro se o dia for válido, falso caso contrário.
     */
    bool verifica_dia();

    /**
     * @brief  Método para verificar se o mês é válido.
     * @return Verdadeiro se o mês for válido, falso caso contrário.
     */
    bool verifica_mes();

    /**
     * @brief  Método para verificar se o ano é bissexto.
     * @return Verdadeiro se o ano for bissexto, falso caso contrário.
     */
    bool verifica_ano_bissexto();

public:
    /**
     * @brief  Método para definir a data.
     * @param data Data a ser atribuída em formato string.
     * @throws invalid_argument Se a data não for válida.
     */
    void setData(std::string data);

    /**
     * @brief Obtém a data.
     * @return Data atual em formato string.
     */
    std::string getData();
};


/**
 * @class Percentual
 * @brief Representa o domínio Percentual (Feito por: 231013529).
 */
class Percentual {
private:
    int percentual; /**< Valor percentual. */

public:
    /**
     * @brief Construtor do domínio Percentual.
     * @param d Valor inicial do percentual (padrão é 0).
     */
    Percentual(int d = 0);

    /**
     * @brief Método para definir o percentual.
     * @param a Novo valor percentual.
     * @throws invalid_argument Se o percentual não for válido.
     */
    void setPercentual(int a);

    /**
     * @brief Obtém o percentual.
     * @return O valor percentual atual.
     */
    int getPercentual() const;
};


/**
 * @class Senha
 * @brief Representa o domínio Senha (Feito por: 231013529).
 */
class Senha {
private:
    string senha; /**< Senha. */

    /**
     * @brief Método para verificar se há dígitos duplicados na senha.
     * @param password Senha a ser verificada.
     * @return Verdadeiro se não houver dígitos duplicados, falso caso contrário.
     */
    bool verificador_duplica(const string& password);

    /**
     * @brief Método para verificar se a ordem dos caracteres na senha está em ordem crescente ou decrescente.
     * @param password Senha a ser verificada.
     * @return Verdadeiro se a ordem for válida, falso caso contrário.
     */
    bool verificador_ordem(const string& password);

public:
    /**
     * @brief Construtor do domínio senha.
     * @param d Valor inicial da senha (padrão é um espaço).
     */
    Senha(string d = " ");

    /**
     * @brief Método para definir a senha.
     * @param a Nova senha.
     * @throws invalid_argument Se a senha não for válida.
     */
    void setSenha(const string& a);

    /**
     * @brief Obtém a senha.
     * @return A senha atual.
     */
    string getSenha();
};


/**
 * @class Nome
 * @brief Representa o domínio Nome (Feito por: 231013529).
 */
class Nome {
private:
    string nome; /**< Nome. */

    /**
     * @brief Verifica caracteres no nome.
     * @param name Nome a ser verificado.
     * @return Verdadeiro se os caracteres forem válidos, falso caso contrário.
     */
    bool verificador_caracteres(const string& name);

    /**
     * @brief Método para verificar se todos caracteres são válidos.
     * @param name Nome a ser verificado.
     * @return Verdadeiro se os caracteres forem válidas, falso caso contrário.
     */
    bool verificador_letras(const string& name);

    /**
     * @brief Método para verificar se a primeira letra é maiúscula.
     * @param name Nome a ser verificado.
     * @return Verdadeiro se a primeira letra for maiúscula, falso caso contrário.
     */
    bool verificador_maiusculo(const string& name);

    /**
     * @brief Método para para uma string em palavras.
     * @param name String a ser separada.
     * @return Vetor de strings separadas.
     */
    vector<string> separador_strings(const string& name);

public:
    /**
     * @brief Construtor do domínio Nome.
     * @param m Valor inicial do nome (padrão é um espaço).
     */
    Nome(string m = " ");

    /**
     * @brief Define o nome.
     * @param a Novo nome.
     * @throws invalid_argument Se o nome não for válido.
     */
    void setNome(const string& a);

    /**
     * @brief Obtém o nome.
     * @return O nome atual.
     */
    string getNome();
};


/**
 * @class Setor
 * @brief Representa o domínio Setor (Feito por: 231036292).
 */
class Setor {
private:
    string area; /**< Área do setor. */

public:
    /**
     * @brief Construtor do domínio Setor.
     * @param area Setor inicial.
     */
    Setor(string area);

    /**
     * @brief Método para definir o Setor.
     * @param consultadearea Novo Setor.
     * @throws invalid_argument Se o setor não for válido.
     */
    void setSetor(string consultadearea);

    /**
     * @brief Obtém o setor.
     * @return O setor atual.
     */
    string getSetor();
};


/**
 * @class Estado
 * @brief Representa o setor Estado (Feito por: 231036292).
 */
class Estado {
private:
    string status; /**< Status do estado. */

public:
    /**
     * @brief Construtor do domínio Estado.
     * @param status Estado inicial.
     */
    Estado(string status);

    /**
     * @brief Método para definir o Estado.
     * @param statusConfirmation Novo Estado.
     * @throws invalid_argument Se o estado não for válido.
     */
    void setEstado(string statusConfirmation);

    /**
     * @brief Obtém o estado.
     * @return O estado atual.
     */
    string getEstado();
};


/**
 * @class Dinheiro
 * @brief Representa o domínio Dinheiro (Feito por: 231036292).
 */
class Dinheiro {
private:
    float valor; /**< Valor em reais. */

public:
    /**
     * @brief Construtor do domínio Dinheiro.
     */
    Dinheiro();

    /**
     * @brief Define o dinheiro.
     * @param valor Novo dinheiro.
     * @throws invalid_argument Se o dinheiro não for válido.
     */
    void setDinheiro(float valor);

    /**
     * @brief Obtém o dinheiro.
     * @return O dinheiro atual.
     */
    float getDinheiro();
};

#endif // DOMINIOS_H_INCLUDED
