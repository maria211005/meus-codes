#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Atendente{
    private:
        string user;
        string senha;
    public:
        string getUser(){
            return this->user;
        }

        string getSenha(){
            return this->senha;
        }

        void setUser(string user){
            this->user = user;
        }

        void setSenha(string senha){
            this->senha = senha;
        }
};

class Cliente{
    private:
        string nome;
        int idade;
        string CPF;
    public:
        string getNome(){
            return this->nome;
        }

        int getIdade(){
            return this->idade;
        }

        string getCPF(){
            return this->CPF;
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setIdade(int idade){
            this->idade = idade;
        }

        void setCPF(string CPF){
            this->CPF = CPF;
        }
};

class Reserva{
    private:
        string localidade;
        string dataCheckIn;
        int quantDias;
        string tipoQuarto;
        Cliente newCliente;
        float desconto;
    public:
        string getLocalidade(){
            return this->localidade;
        }

        string getDataCheckIn(){
            return this->dataCheckIn;
        }

        int getQuantDias(){
            return this->quantDias;
        }

        string getTipoQuarto(){
            return this->tipoQuarto;
        }

        Cliente getCliente(){
            return this->newCliente;
        }

        float getDesconto(){
            return this->desconto;
        }

        void setLocalidade(string localidade){
            this->localidade = localidade;
        }

        void setDataCheckIn(string dataCheckIn){
            this->dataCheckIn = dataCheckIn;
        }

        void setQuantDias(int quantDias){
            this->quantDias = quantDias;
        }

        void setTipoQuarto(string tipoQuarto){
            this->tipoQuarto = tipoQuarto;
        }

        void setCliente(Cliente cliente){
            this->newCliente = cliente;
        }

        void setDesconto(float desconto){
            this->desconto = desconto;
        }       

};

int main(){
    //objetos que serão utilizados
    Atendente atendentes[4];
    Cliente clientes;
    Reserva reserva;
    
    //variáveis usadas para receber as informações do usuário
    string login, senha;
    string nome, cpf;
    string localidade, data, tipo;
    bool autenticado = false;
    int menu, opcoes;
    int idade;
    int quantDias;
    float desconto;

    //declaração dos logins e senhas dos atendentes para verificar autenticação do usuário
    atendentes[0].setUser("atendente1");
    atendentes[0].setSenha("senha1");

    atendentes[1].setUser("atendente2");
    atendentes[1].setSenha("senha2");

    atendentes[2].setUser("atendente3");
    atendentes[2].setSenha("senha3");

    atendentes[3].setUser("atendente4");
    atendentes[3].setSenha("senha4");
    
    //início do sistema
    cout << "------------------------------------" << endl;
    cout << "Bem vindo a rede de hoteis Paradise!" << endl;
    cout << "------------------------------------" << endl;
    
    //verifica autenticação enquanto for incorreto
    while(!autenticado){
        cout << "Login: ";
        cin >> login;
        cout << "Senha: ";
        cin >> senha;

        //caso o login e senha inseridos forem iguais a uma das opções
        for(int i = 0; i < 4; i++){
            if(login == atendentes[i].getUser() && senha == atendentes[i].getSenha()){
                autenticado = true;
                cout << "\nBem Vindo " << atendentes[i].getUser() << " ao sistema!" << endl;
                cout << "------------------------------------" << endl;
            }
        }

        //caso não for autenticado, a variavel booleana não se altera
        if(!autenticado){
            cout << "\nAutenticacao invalida. Tente novamente." << endl;
        }
    }
    
    //caso autenticas, começa o menu de opções
    cout << "MENU DO SISTEMA DE RESERVAS DO HOTEL PARADISE" << endl;
    do{
        cout << "1- Verificar disponibilidade dos quartos" << endl;
        cout << "2- Efetuar nova reserva" << endl;
        cout << "3- Sair" << endl;
        cout << "O que deseja fazer: ";
        cin >> menu;
        cout << "------------------------------------" << endl;
    
        switch(menu){
            //caso de verificação de disponibilidade de quartos para reserva
            case 1:
                cout << "disponibilidade de quartos" << endl;
                break;
            //caso de executar uma nova reserva
            case 2:
                cout << "Nova Reserva" << endl;
                cout << "------------------------------------" << endl;
                cout << "Sobre o cliente" << endl;
                cout << "**Cliente: ";
                cin >> nome;
                clientes.setNome(nome);
                
                cout << "**Idade: ";
                cin >> idade;
                if (idade < 18){
                    cout << "Menor de idade, nao pode efetuar reserva" << endl;
                    break;
                }
                clientes.setIdade(idade);
                
                cout << "**CPF (999.999.999-99): ";
                cin >> cpf;
                clientes.setCPF(cpf);
            
                reserva.setCliente(clientes);
                
                cout << "\nSobre a reserva" << endl;
                while(opcoes != 1 && opcoes != 2 && opcoes != 3){
                    cout << "**Lugares disponiveis:\n  1- Jericoacoara\n  2- Canoa Quebrada\n  3- Cumbuco" << endl;
                    cout << "  Para qual dos lugares o cliente deseja ir: ";
                    cin >> opcoes;
                    
                    if (opcoes == 1) localidade = "Jericoacoara";
                    else if (opcoes == 2) localidade = "Canoa Quebrada";
                    else if (opcoes == 3) localidade = "Cumbuco";
                    else cout << "Opcao invalida. Tente novamente\n" << endl;
                }
                reserva.setLocalidade(localidade);
    
                cout << "**Data do Check-In (DD/MM/AAAA): ";
                cin >> data;
                reserva.setDataCheckIn(data);

                cout << "**Quantos dias de permanencia no hotel: ";
                cin >> quantDias;
                reserva.setQuantDias(quantDias);
                
                do{
                    cout << "**Tipos de Quarto" << endl;
                    cout << "  1- Solteiro (uma cama de solteiro)\n  2- Duplo (duas camas de solteiro)\n  3- Casal (uma cama de casal)\n  4- Triplo (uma cama de casal e uma de solteiro ou tres camas de solteiro)\n  5- Quadruplo (duas camas de casal ou quatro camas de solteiro)" << endl;
                    cout << "  Qual opcao o cliente deseja: ";
                    cin >> opcoes;
        
                    if(opcoes == 1) tipo = "Solteiro";
                    else if(opcoes == 2) tipo = "Duplo";
                    else if(opcoes == 3) tipo = "Casal";
                    else if(opcoes == 4) tipo = "Triplo";
                    else if(opcoes == 5) tipo = "Quadruplo";
                    else cout << "Opcao invalida. Tente novamente\n" << endl;
                }while(opcoes != 1 && opcoes != 2 && opcoes != 3 && opcoes != 4 && opcoes != 5);
                reserva.setTipoQuarto(tipo);
                
                do{
                    cout << "**Tipos de Desconto" << endl;
                    cout << "  1- Sem desconto\n  2- Clientes VIP: 10\% de desconto.\n  3- Baixa temporada: 20\% de desconto.\n  4- Promocao de feriados especificos: 15\% de desconto." << endl;
                    cout << "Qual opcao o cliente se encaixa: ";
                    cin >> opcoes;

                    if(opcoes == 1) desconto = 0;
                    else if(opcoes == 2) desconto = 0.10;
                    else if(opcoes == 3) desconto = 0.20;
                    else if(opcoes == 4) desconto = 0.15;
                    else cout << "Opcao invalida. Tente novamente\n" << endl;
                }while(opcoes != 1 && opcoes != 2 && opcoes != 3 && opcoes != 4);
                reserva.setDesconto(desconto);
            
                cout << "------------------------------------" << endl;
                cout << "Cliente: " << reserva.getCliente().getNome() << endl;
                break;
            //caso de sair do sistema
            case 3:
                //salvar todas as informações num arquivo .txt
                cout << "Obrigado por utilizar nosso sistema Paradise" << endl;
                cout << "Saindo...\n------------------------------------" << endl;
                return 0;
            //caso não for uma das opções escolhidas
            default:
                cout << "Opcao incorreta. Tente novamente" << endl;
                cout << "------------------------------------" << endl;
                break;
        }//switch
    }while(menu != 3);  //enquanto não quiser sair, continua a repetir o menu

    return 0;
}