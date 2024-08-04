#include "Modulos.h"
#include "Modulos.cpp"
using namespace std;

int main() {
    MAA autenticar;
    MACC criar_conta;
    MAGC gerenciar_conta;
    bool juri = true;
    string a;
    while (juri) {
        int acao;
        cout<<"Digite o numero da acao que deseja realizar"<<endl;
        cout<<"1. Autenticar"<<endl;
        cout<<"2. Criar Conta"<<endl;
        cout<<"3. Sair"<<endl;
        getline(cin,a);
        acao = stoi(a);
        switch(acao) {
            case 1:
                cout<<"Entrando na pagina de autenticacao"<<endl<<endl;
                autenticar.definir_g(gerenciar_conta);
                autenticar.executar();
                break;
            case 2:
                cout<<"Entrando na pagina de criacao de contas"<<endl<<endl;
                criar_conta.executar();
                break;
            case 3:
                juri = false;
                break;
            default:
                cout<<"Acao invalida"<<endl;
        }

    }


}
