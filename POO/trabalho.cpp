#include <iostream>
#include <string>
#include <sstream>
#include <time.h>

using namespace std;
class Desconto {
    public:
        virtual float descontar()=0;
};

class SemDesconto:public Desconto {   
    public:
        float descontar() override{
            return 0.0;
        }
};

class DescontoVIP:public Desconto {   
    public:
        float descontar() override{
            return 0.1;
        }
};

class DescontoBaixaTemporada:public Desconto {   
    public:
        float descontar() override{
            return 0.2;
        }
};

class DescontoFeriado:public Desconto {   
    public:
        float descontar() override{
            return 0.15;
        }
};

class Atendente{
    private:
        string user;
        string senha;
    public:
        Atendente(){
            setUser("");
            setSenha("");
        }
        Atendente(string user, string senha){
            setUser(user);
            setSenha(senha);
        }
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
        Cliente(){
            setNome("");
            setIdade(0);
            setCPF("");
        }
        Cliente(string nome, int idade, string CPF){
            setNome(nome);
            setIdade(idade);
            setCPF(CPF);
        }

        //getters e setters
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

        //método para exibir as informações do cliente
        void exibirCliente(){
            cout << "Nome: " << this->nome << endl;
            cout << "Idade: " << this->idade << endl;
            cout << "CPF: " << this->CPF << endl;
        }
};

class Quarto{
    private:
        string tipo;
        float preco;
        bool disponivel;

    public:
        Quarto(){
            setTipo("");
            setPreco(0.0);
            setDisponivel(false);
        }

        Quarto(string tipo, float preco, bool disponivel){
            setTipo(tipo);
            setPreco(preco);
            setDisponivel(disponivel);
        }

        string getTipo(){
            return this->tipo;
        }

        float getPreco(){
            return this->preco;
        }

        bool isDisponivel(){
            return this->disponivel;
        }

        void setTipo(string tipo){
            this->tipo = tipo;
        }

        void setPreco(float preco){
            this->preco = preco;
        }

        void setDisponivel(bool disponivel){
            this->disponivel = disponivel;
        }
};

class Localidade{
    private:
        string nome;
        Quarto quarto[5];
        int idLocal;
    public:
        Localidade(){
            setNome("");
            for(int i = 0; i < 5; i++){
                quarto[i] = Quarto();
            }
        }

        Localidade(string nome, Quarto quartos[5], int id){
            setNome(nome);
            for(int i = 0; i < 5; i++){
                setQuarto(quartos[i], i);
            }
            setIdLocal(id);
        }

        string getNome(){
            return this->nome;
        }  

        Quarto& getQuarto(int index){
            return this->quarto[index];
        }

        int getIdLocal(){
            return this->idLocal;
        }

        void setNome(string nome){
            this->nome = nome;
        }

        void setQuarto(Quarto novoQuarto, int index){
            this->quarto[index] = novoQuarto;
        }

        void setIdLocal(int id){
            this->idLocal = id;
        }
};

class Reserva{
    private:
        int id;
        Localidade localidade;
        int dia, mes, ano;
        int quantDias;
        Quarto quarto;
        Cliente newCliente;
        bool disponivel;
        Desconto *desconto;
    public:
        Reserva(){
            setID(0);
            setLocalidade(Localidade());
            setDataCheckIn(0, 0, 0);
            setQuantDias(0);
            setQuarto(Quarto());
            setCliente(Cliente());
            this->disponivel = true;
            this->desconto = nullptr; // Inicializa o ponteiro de desconto como nulo
        }

        Reserva(int ID, Localidade localidade, int dia, int mes, int ano, int quantDias, Quarto quarto, Cliente cliente){
            setID(ID);
            setLocalidade(localidade);
            setDataCheckIn(dia, mes, ano);
            setQuantDias(quantDias);
            setQuarto(quarto);
            setCliente(cliente);
            this->disponivel = true;
        }

        int getID(){
            return this->id;
        }

        Quarto& getQuarto(){
            return this->quarto;
        }
       
        Localidade& getLocalidade(){
            return this->localidade;
        }
        
        int getDia(){
            return this->dia;
        }

        int getMes(){
            return this->mes;
        }

        int getAno(){
            return this->ano;
        }

        int getQuantDias(){
            return this->quantDias;
        }
        
        Cliente& getCliente(){
            return this->newCliente;
        }
        
        float getDesconto(){

            return this->desconto->descontar();
        }

        void setID(int id){
            this->id = id;
        }
        
        void setQuarto(Quarto quarto){
            this->quarto = quarto;
            this->quarto.setDisponivel(false);
        }

        void setLocalidade(Localidade localidade){
            this->localidade = localidade;
        }

        void setDataCheckIn(int dia, int mes, int ano){
            this->dia = dia;
            this->mes = mes;
            this->ano = ano;
        }

        void setQuantDias(int quantDias){
            this->quantDias = quantDias;
        }

        void setCliente(Cliente cliente){
            this->newCliente = cliente;
        }   
        
        void executarDesconto(){
            if(this->desconto!=nullptr){
                desconto->descontar();
            }
            else{
                cout<<"Nenhuma desconto foi definido"<<endl;
            }
        }

        void setDesconto(Desconto *novoDesconto){
            this->desconto=novoDesconto;
        }
};

void preDeclaracao(Atendente atendentes[], Quarto quarto[], Localidade local[]){
    //declaração dos logins e senhas dos atendentes para verificar autenticação do usuário
    atendentes[0] = Atendente("atendente1", "senha1");
    atendentes[1] = Atendente("atendente2", "senha2");
    atendentes[2] = Atendente("atendente3", "senha3");
    atendentes[3] = Atendente("atendente4", "senha4");
    
    //declaração dos tipos de quartos e seus preços
    quarto[0] = Quarto("Solteiro", 200.00, true);
    quarto[1] = Quarto("Duplo", 300.00, true);
    quarto[2] = Quarto("Casal", 350.00, true);
    quarto[3] = Quarto("Triplo", 450.00, true);
    quarto[4] = Quarto("Quadruplo", 550.00, true);

    //declaração das localidades e seus quartos e reservas
    local[0] = Localidade("Jericoacoara", quarto, 0);
    local[1] = Localidade("Canoa Quebrada", quarto, 1);
    local[2] = Localidade("Cumbuco", quarto, 2);

}

void autenticar(Atendente atendentes[]){
    //verifica se o login e senha inseridos são iguais a uma das opções
    string login, senha;
    bool autenticado = false;

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
            }
        }
        
        //caso não for autenticado, a variavel booleana não se altera
        if(!autenticado){
            cout << "\nAutenticacao invalida. Tente novamente." << endl;
        }
    }
}

void disponibilidadeQuartos(Reserva reserva[], Localidade locais[], int id){
    int opcao, opcaoLoc, quantDias;
    string data;
    int dia, mes, ano, mesVolta, anoVolta;
    bool dataValida;
    float desconto = 0.0;

    cout << "Disponibilidade de quartos" << endl;
    cout << "------------------------------------" << endl;
    do{
        cout << "Para qual localidade deseja verificar a disponibilidade?" << endl;
        cout << "1- Jericoacoara\n2- Canoa Quebrada\n3- Cumbuco" << endl;
        cin >> opcaoLoc;
        if(opcaoLoc < 1 || opcaoLoc > 3){
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }while(opcaoLoc < 1 || opcaoLoc > 3);
    cout << "------------------------------------" << endl;
    
    cout << "Para qual data deseja verificar a disponibilidade?" << endl;
    do{
        cout << "Data (DD/MM/AAAA): ";
        cin >> data;
        dataValida = true;

        //verifica se a data está no formato correto
        if(data.length() != 10 || data[2] != '/' || data[5] != '/'){
            cout << "Data invalida. Tente novamente." << endl;
            dataValida = false;
        }
    }while(!dataValida);
    sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);
    cout << "------------------------------------" << endl;

    cout << "Quantos dias de permanencia no hotel: ";
    cin >> quantDias;

    int dias[quantDias];
    mesVolta = mes;
    anoVolta = ano;
    for(int i = 0; i < quantDias; i++){
        if(i == 0)
            dias[i] = dia;
        else{
            dias[i] = dias[i-1] + 1;
            if(dias[i] > 31 && (mes == 1 || mes == 3 || mes == 5 || mes == 7 || mes == 8 || mes == 10 || mes == 12)){
                mesVolta++;
                dias[i] -= 31;
            }
            else if(dias[i] > 30 && (mes == 4 || mes == 6 || mes == 9 || mes == 11)){
                mesVolta++;
                dias[i] -= 30;
            }
            else if(dias[i] > 28 && mes == 2){
                mesVolta++;
                dias[i] -= 28;
            }
            if(mesVolta > 12){
                anoVolta++;
                mesVolta = 1;
            }
        }
    }
    
    cout << "Cliente VIP? (1- Sim, 0- Nao): ";
    cin >> opcao;

    if(opcao == 1){
        cout << "Desconto de cliente VIP aplicado: 10%" << endl;
        desconto = 0.1;
    }else{
        if(mes == 6 || mes == 7 || mes == 8 || mes == 9){
            cout << "Desconto de baixa temporada aplicado: 20%" << endl;
            desconto = 0.2;
        }
        else if((dia == 25 && mes == 12) || (dia == 1 && mes == 1)){
            cout << "Desconto de feriado aplicado: 15%" << endl;
            desconto = 0.15;
        }
        else{
            cout << "Sem desconto aplicado." << endl;
        }
    }

    cout << "Localidade: " << locais[opcaoLoc - 1].getNome() << endl;
    cout << "Data ida: " << dia << "/" << mes << "/" << ano << endl;
    cout << "Data volta: " << dias[quantDias - 1] << "/" << mesVolta << "/" << anoVolta << endl;
    cout << "Quartos disponiveis: " << endl;

    if(id == 0){
        for(int i = 0; i < 5; i++){
            if(locais[opcaoLoc - 1].getQuarto(i).isDisponivel()){
                cout << "- " << locais[opcaoLoc - 1].getQuarto(i).getTipo() << " ---- R$ " << locais[opcaoLoc - 1].getQuarto(i).getPreco() << endl;
            }
            else{
                cout << "- " << "\033[9m" << locais[opcaoLoc - 1].getQuarto(i).getTipo() << "\033[0m" << " ---- " << " (Indisponivel)" << endl;
            }
        }
    }else{
        //falta terminar de verificar a disponibilidade dos quartos em mais de um dia
        for(int k = 0; k < quantDias; k++){
            for(int j = 0; j < 5; j++){
                for(int i = 0; i < id; i++){
                    if(reserva[i].getDia() == dias[k] && reserva[i].getMes() == mes && reserva[i].getAno() == ano && reserva[i].getLocalidade().getIdLocal() == locais[opcaoLoc - 1].getIdLocal()){
                        if(reserva[i].getQuarto().getTipo() == locais[opcaoLoc - 1].getQuarto(j).getTipo()){
                            cout << "- " << "\033[9m" << locais[opcaoLoc - 1].getQuarto(j).getTipo() << "\033[0m" << " ---- " << " (Indisponivel)" << endl;
                        }
                        else{
                            cout << "- " << locais[opcaoLoc - 1].getQuarto(j).getTipo() << " ---- R$ " << locais[opcaoLoc - 1].getQuarto(j).getPreco() << endl;
                        }
                    }
                }
            }
        }
    }
    
}

bool cadastraCliente(Cliente cliente[], int id){
    string nome, cpf;
    int idade;

    cout << "Sobre o cliente" << endl;
    cout << "**Cliente: ";
    cin >> nome;
    
    cout << "**Idade: ";
    cin >> idade;
    if (idade < 18){
        cout << "Menor de idade, nao pode efetuar reserva" << endl;
        return false;
    }

    cpf = "";
    while(cpf.length() != 14 || cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
        cout << "**CPF (999.999.999-99): ";
        cin >> cpf;
        if(cpf.length() != 14 || cpf[3] != '.' || cpf[7] != '.' || cpf[11] != '-'){
            cout << "CPF invalido. Tente novamente." << endl;
        }
    }

    cliente[id] = Cliente(nome, idade, cpf);
    return true;
}

int main(){
    FILE *fp;
    fp = fopen("reservas.txt", "a+");
    if (fp == NULL) {
        cout << "Erro ao abrir o arquivo." << endl;
        return 1;
    }else{
        //falta ler o arquivo nas funções
    }

    //objetos que serão utilizados
    Atendente atendentes[4];
    Cliente clientes[20];
    Reserva reserva[20];
    Quarto quarto[5];
    Localidade local[3];
    SemDesconto semDesconto;
    DescontoVIP descontoVIP;
    DescontoBaixaTemporada descontoBaixaTemporada;
    DescontoFeriado descontoFeriado;
    
    //usadas para receber as informações do usuário
    string login, senha, nome, data;
    int checkoutDia, checkoutMes, checkoutAno;
    int menu, opcoes, quantDias, dia, mes, ano;
    int id = 0;
    int opcaoLocal = 0, opcaoQuarto = 0;
    
    preDeclaracao(atendentes, quarto, local);
    //---------------------------------------------------------------------------------------------------
    //início do sistema
    cout << "------------------------------------" << endl;
    cout << "Bem vindo a rede de hoteis Paradise!" << endl;
    cout << "------------------------------------" << endl;
    
    //verifica autenticação enquanto for incorreto
    autenticar(atendentes);

    //caso autenticas, começa o menu de opções
    do{
        cout << "------------------------------------" << endl;
        cout << "MENU DO SISTEMA DE RESERVAS DO HOTEL PARADISE" << endl;
        cout << "1- Verificar disponibilidade dos quartos" << endl;
        cout << "2- Efetuar nova reserva" << endl;
        cout << "3- Sair" << endl;
        cout << "O que deseja fazer: ";
        cin >> menu;
        cout << "------------------------------------" << endl;
    
        switch(menu){
            //caso de verificação de disponibilidade de quartos para reserva
            case 1:
                disponibilidadeQuartos(reserva, local, id);
                break;
            //caso de executar uma nova reserva
            case 2:
                cout << "Nova Reserva" << endl;
                cout << "------------------------------------" << endl;
                if(!cadastraCliente(clientes, id)) break;
                cout << "------------------------------------" << endl;
                cout << "\nSobre a reserva" << endl;
            
                do{
                    cout << "**Lugares disponiveis:\n  1- Jericoacoara\n  2- Canoa Quebrada\n  3- Cumbuco" << endl;
                    cout << "  Para qual dos lugares o cliente deseja ir: ";
                    cin >> opcoes;

                    if(opcoes < 1 || opcoes > 3) cout << "Opcao invalida. Tente novamente\n" << endl;
                    else opcaoLocal = opcoes - 1;

                }while(opcoes != 1 && opcoes != 2 && opcoes != 3);
                
                bool dataValida;
                do{
                    do{
                        cout << "**Data do Check-In (DD/MM/AAAA): ";
                        cin >> data;
                        dataValida = true;
                        
                        //verifica se a data está no formato correto
                        if(data.length() != 10 || data[2] != '/' || data[5] != '/'){
                            cout << "Data invalida. Tente novamente." << endl;
                            dataValida = false;
                        }
                    }while(!dataValida);
                    
                    //verifica se o dia, mês e ano são válidos
                    sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);
                    
                    if(mes == 2 && dia > 28){
                        cout << "Mes invalido. Tente novamente." << endl;
                        dataValida = false;
                    }
                    else if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30){
                        cout << "Mes invalido. Tente novamente." << endl;
                        dataValida = false;
                    }
                    else if(mes < 1 || mes > 12 || dia < 1 || dia > 31){
                        cout << "Data invalida. Tente novamente." << endl;
                        dataValida = false;
                    }
                    else if(ano > 2025){
                        cout << "Ano invalido. Tente novamente." << endl;
                        dataValida = false;
                    }
                }while(!dataValida); // continua até que a data seja válida
                
                cout << "**Quantos dias de permanencia no hotel: ";
                cin >> quantDias;

                checkoutDia = (dia - 1) + quantDias;
                checkoutMes = mes;
                checkoutAno = ano;

                if(checkoutDia > 31){
                    checkoutDia -= 31;
                    checkoutMes += 1;
                    if(checkoutMes > 12){
                        checkoutMes = 1;
                        checkoutAno += 1;
                    }
                }
                else if(checkoutDia > 30 && (checkoutMes == 4 || checkoutMes == 6 || checkoutMes == 9 || checkoutMes == 11)){
                    checkoutDia -= 30;
                    checkoutMes += 1;
                    if(checkoutMes > 12){
                        checkoutMes = 1;
                        checkoutAno += 1;
                    }
                }
                else if(checkoutDia > 28 && checkoutMes == 2){
                    checkoutDia -= 28;
                    checkoutMes += 1;
                    if(checkoutMes > 12){
                        checkoutMes = 1;
                        checkoutAno += 1;
                    }
                }

                cout << "Data de Check-In: " << dia << "/" << mes << "/" << ano << endl;
                cout << "Data de Check-Out: " << checkoutDia << "/" << checkoutMes << "/" << checkoutAno << endl;
                cout << "------------------------------------" << endl;

                do{
                    cout << "**Tipos de Quarto" << endl;
                    cout << "  1- Solteiro (uma cama de solteiro) ------------------------------------------- R$ 200,00\n  2- Duplo (duas camas de solteiro) -------------------------------------------- R$ 300,00\n  3- Casal (uma cama de casal) ------------------------------------------------- R$ 350,00\n  4- Triplo (uma cama de casal e uma de solteiro ou tres camas de solteiro) ---- R$ 450,00\n  5- Quadruplo (duas camas de casal ou quatro camas de solteiro) --------------- R$ 550,00" << endl;
                    cout << "  Qual opcao o cliente deseja: ";
                    cin >> opcoes;

                    if(local[opcaoLocal].getQuarto(opcoes-1).isDisponivel()){
                        opcaoQuarto = opcoes - 1;
                        local[opcaoLocal].getQuarto(opcaoQuarto).setDisponivel(false);                        
                    }
                    else{
                        cout << "Quarto indisponivel. Nao foi possivel efetuar a reserva." << endl;
                        cout << "Gostaria de tentar novamente? (1- Sim, 0- Nao): ";
                        cin >> opcoes;
                        if(opcoes == 1){
                            opcoes = 6; // Forçar o loop a continuar
                        }
                        else if(opcoes == 0){
                            cout << "Reserva cancelada." << endl;
                            break;
                        }
                    }

                }while(opcoes != 1 && opcoes != 2 && opcoes != 3 && opcoes != 4 && opcoes != 5);
                if(opcoes == 0)break; // Se o usuário escolheu cancelar a reserva, sai do loop
                
                for(int i = 0; i < id; i++){
                    dataValida = true;
                    //caso a reserva for na mesma data, localidade e tipo de quarto, não permite a reserva
                    if(reserva[i].getDia() == reserva[id].getDia() && reserva[i].getMes() == reserva[id].getMes() && reserva[i].getAno() == reserva[id].getAno() && reserva[i].getLocalidade().getIdLocal() == local[opcaoLocal].getIdLocal() && reserva[i].getQuarto().getTipo() == local[opcaoLocal].getQuarto(opcaoQuarto).getTipo()){
                        cout << "Quarto ja reservado para essa data. Tente novamente." << endl;
                        dataValida = false;
                        break;
                    }
                }
                if(!dataValida) break; // Se a data não for válida, cancela a reserva
                reserva[id] = Reserva(id+1, local[opcaoLocal], dia, mes, ano, quantDias, local[opcaoLocal].getQuarto(opcaoQuarto), clientes[id]);
                
                do{
                    cout << "**Tipos de Desconto" << endl;
                    cout << "  1- Cliente Normal: Sem desconto\n  2- Clientes VIP: 10\% de desconto." << endl;
                    cout << "Qual opcao o cliente se encaixa: ";
                    cin >> opcoes;

                    if(reserva[id].getMes() == 5 || reserva[id].getMes() == 6 || reserva[id].getMes() == 7 || reserva[id].getMes() == 8 || reserva[id].getMes() == 9){
                        reserva[id].setDesconto(&descontoBaixaTemporada);
                        cout << "Desconto de baixa temporada aplicado: 20%" << endl;
                    }
                    else if((reserva[id].getDia() == 25 && reserva[id].getMes() == 12)||(reserva[id].getDia() == 1 && reserva[id].getMes() == 1)){
                        reserva[id].setDesconto(&descontoFeriado);
                        cout << "Desconto de feriado aplicado: 15%" << endl;
                    }
                    else if(opcoes == 1){
                        reserva[id].setDesconto(&semDesconto);
                        cout << "Cliente normal, sem desconto aplicado." << endl;
                    }
                    else if(opcoes == 2) {
                        reserva[id].setDesconto(&descontoVIP);
                        cout << "Desconto VIP aplicado: 10%" << endl;
                    }

                    if(opcoes < 1 || opcoes > 2){
                        cout << "Opcao invalida. Tente novamente." << endl;
                    }
                }while(opcoes != 1 && opcoes != 2 && opcoes != 3 && opcoes != 4);
                
                cout << "------------------------------------" << endl;
                cout << "Reserva efetuada com sucesso!" << endl;

                id++;
                break;

            //caso de sair do sistema
            case 3:
                cout << "Salvando dados das reservas..." << endl;
                if(fp != NULL) {
                    for(int i = 0; i < id; i++){
                        fprintf(fp, "Reserva %d\n", reserva[i].getID());
                        fprintf(fp, "Localidade: %s\n", reserva[i].getLocalidade().getNome().c_str());
                        fprintf(fp, "Cliente: %s\n", reserva[i].getCliente().getNome().c_str());
                        fprintf(fp, "Data de Check-In: %d/%d/%d\n", reserva[i].getDia(), reserva[i].getMes(), reserva[i].getAno());
                        fprintf(fp, "Data de Check-Out: %d/%d/%d\n", checkoutDia, checkoutMes, checkoutAno);
                        fprintf(fp, "Quarto reservado: %s\n", reserva[i].getQuarto().getTipo().c_str());
                        fprintf(fp, "Preço cheio: R$ %.2f\n", reserva[i].getQuarto().getPreco() * reserva[i].getQuantDias());
                        fprintf(fp, "Desconto aplicado: %.2f%%\n", reserva[i].getDesconto() * 100);
                        fprintf(fp, "Preco total: R$ %.2f\n", (reserva[i].getQuarto().getPreco() * reserva[i].getQuantDias()) * (1 - reserva[i].getDesconto()));
                        fprintf(fp, "------------------------------------\n");
                    }
                    fclose(fp);
                    cout << "Dados das reservas salvos no arquivo reservas.txt" << endl;
                } else {
                    cout << "Nao foi possivel abrir o arquivo para salvar as reservas." << endl;
                }
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