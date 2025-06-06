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
        bool autenticado;
    public:
        Atendente(){
            setUser("");
            setSenha("");
            setAutenticado(false);
        }
        Atendente(string user, string senha){
            setUser(user);
            setSenha(senha);
            setAutenticado(false);
        }
        string getUser(){
            return this->user;
        }

        string getSenha(){
            return this->senha;
        }

        bool isAutenticado(){
            return this->autenticado;
        }

        void setUser(string user){
            this->user = user;
        }

        void setSenha(string senha){
            this->senha = senha;
        }

        void setAutenticado(bool autenticado){
            this->autenticado = autenticado;
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
        bool confirmada;
        Atendente atendente;
    public:
        Reserva(){
            setID(0);
            setLocalidade(Localidade());
            setDataCheckIn(0, 0, 0);
            setQuantDias(0);
            setQuarto(Quarto());
            setCliente(Cliente());
            this->disponivel = true;
            this->desconto = nullptr;
            setConfirmada(false);
            setAtendente(Atendente());
        }

        Reserva(int ID, Localidade localidade, int dia, int mes, int ano, int quantDias, Quarto quarto, Cliente cliente, bool confirmada, Atendente atendente){
            setID(ID);
            setLocalidade(localidade);
            setDataCheckIn(dia, mes, ano);
            setQuantDias(quantDias);
            setQuarto(quarto);
            setCliente(cliente);
            this->disponivel = true;
            setConfirmada(confirmada);
            setAtendente(atendente);
        }
        
        Atendente getAtendente(){
            return this->atendente;
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

        bool IsConfirmada(){
            return this->confirmada;
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
        
        void setAtendente(Atendente atendente){
            this->atendente = atendente;
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

        void setConfirmada(bool confirmada){
            this->confirmada = confirmada;
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
                atendentes[i].setAutenticado(true);
                cout << "\nBem Vindo " << atendentes[i].getUser() << " ao sistema!" << endl;
            }
        }
        
        //caso não for autenticado, a variavel booleana não se altera
        if(!autenticado){
            cout << "\nAutenticacao invalida. Tente novamente." << endl;
        }
    }
}

void disponibilidadeQuartos(Reserva reserva[], Localidade locais[], int *id){
    int opcao, opcaoLoc, quantDias;
    string data;
    int dia, mes, ano;
    bool dataValida;
    float desconto;
    SemDesconto semDesconto;
    DescontoVIP descontoVIP;
    DescontoBaixaTemporada descontoBaixaTemporada;
    DescontoFeriado descontoFeriado;

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
    int meses[quantDias];
    int anos[quantDias];
    for(int i = 0; i < quantDias; i++){
        if(i == 0){
            dias[i] = dia;
            meses[i] = mes;
            anos[i] = ano;
        }
        else{
            dias[i] = dias[i-1] + 1;
            meses[i] = meses[i-1];
            anos[i] = anos[i-1];
            if(dias[i] > 31 && (meses[i-1] == 1 || meses[i-1] == 3 || meses[i-1] == 5 || meses[i-1] == 7 || meses[i-1] == 8 || meses[i-1] == 10 || meses[i-1] == 12)){
                dias[i] -= 31;
                meses[i] = meses[i-1] + 1;
                anos[i] = anos[i-1];
            }
            else if(dias[i] > 30 && (meses[i-1] == 4 || meses[i-1] == 6 || meses[i-1] == 9 || meses[i-1] == 11)){
                dias[i] -= 30;
                meses[i] = meses[i-1] + 1;
                anos[i] = anos[i-1];
            }
            else if(dias[i] > 28 && meses[i-1] == 2){
                dias[i] -= 28;
                meses[i] = meses[i-1] + 1;
                anos[i] = anos[i-1];
            }
            if(meses[i-1] > 12){
                anos[i]++;
                meses[i] = 1;
            }
        }
    }
    
    cout << "Cliente VIP? (1- Sim, 0- Nao): ";
    cin >> opcao;

    if(opcao == 1){
        cout << "Desconto de cliente VIP aplicado: 10%" << endl;
        desconto = descontoVIP.descontar();
    }else{
        if(mes == 6 || mes == 7 || mes == 8 || mes == 9){
            cout << "Desconto de baixa temporada aplicado: 20%" << endl;
            desconto = descontoBaixaTemporada.descontar();
        }
        else if((dia == 25 && mes == 12) || (dia == 1 && mes == 1)){
            cout << "Desconto de feriado aplicado: 15%" << endl;
            desconto = descontoFeriado.descontar();
        }
        else{
            cout << "Sem desconto aplicado." << endl;
            desconto = semDesconto.descontar();
        }
    }

    cout << "Localidade: " << locais[opcaoLoc - 1].getNome() << endl;
    cout << "Data ida: " << dia << "/" << mes << "/" << ano << endl;
    cout << "Data volta: " << dias[quantDias - 1] << "/" << meses[quantDias-1] << "/" << anos[quantDias-1] << endl;
    cout << "Quartos disponiveis: " << endl;
    cout << "------------------------------------" << endl;  
    for(int i = 0; i < 5; i++){
        if(locais[opcaoLoc - 1].getQuarto(i).isDisponivel()){
            cout << "- " << locais[opcaoLoc - 1].getQuarto(i).getTipo() << " ---- R$ " << locais[opcaoLoc - 1].getQuarto(i).getPreco() << " * "<< quantDias << " dias = " << (locais[opcaoLoc - 1].getQuarto(i).getPreco() * quantDias) << " - " << desconto * 100 << "% = " << (locais[opcaoLoc - 1].getQuarto(i).getPreco() * quantDias * (1 - desconto)) << endl;
        }
        else{
            bool indisponivel = false;
            for(int j = 0; j < *id; j++){
                for(int k = 0; k < quantDias; k++){
                    //verifica se a reserva já existe para o dia, mês e ano selecionados
                    if(reserva[j].getDia() == dias[k] && reserva[j].getMes() == meses[k] && reserva[j].getAno() == anos[k]){
                        if(reserva[j].getLocalidade().getIdLocal() == locais[opcaoLoc - 1].getIdLocal()){
                            if(reserva[j].getQuarto().getTipo() == locais[opcaoLoc - 1].getQuarto(i).getTipo()){
                                if(reserva[j].IsConfirmada()){
                                    cout << "- " << locais[opcaoLoc - 1].getQuarto(i).getTipo() << " ---- (Indisponivel)" << endl;
                                    indisponivel = true;
                                    break;
                                }
                            }
                        }
                    }
                }
            }
            if(!indisponivel){
                cout << "- " << locais[opcaoLoc - 1].getQuarto(i).getTipo() << " ---- R$ " << locais[opcaoLoc - 1].getQuarto(i).getPreco() << " * "<< quantDias << " dias = " << (locais[opcaoLoc - 1].getQuarto(i).getPreco() * quantDias) << " - " << desconto * 100 << "% = " << (locais[opcaoLoc - 1].getQuarto(i).getPreco() * quantDias * (1 - desconto)) << endl;
            }
        }
    }
    cout << "------------------------------------" << endl;
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

FILE* recebeArquivo(){
    FILE* fp = fopen("reservas.txt", "r+");
    if(fp == NULL){
        fp = fopen("reservas.txt", "w+");
        if (fp == NULL) {
            cout << "Erro ao abrir o arquivo." << endl;
            exit(1);
        }
    }
    return fp;
}

bool verificaDataValida(string &data){
    bool dataValida;
    int dia, mes, ano;

    //verifica se a data está no formato correto
    if(data.length() != 10 || data[2] != '/' || data[5] != '/'){
        cout << "Formato de data invalido. Tente novamente." << endl;
        return dataValida = false;
    }

    //verifica se o dia, mês e ano são válidos
    sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);
    
    if(mes == 2 && dia > 28){
        cout << "Mes invalido. Tente novamente." << endl;
        
        return dataValida = false;
    }
    else if((mes == 4 || mes == 6 || mes == 9 || mes == 11) && dia > 30){
        cout << "Mes invalido. Tente novamente." << endl;
        return dataValida = false;
    }
    else if(mes < 1 || mes > 12 || dia < 1 || dia > 31){
        cout << "Data invalida. Tente novamente." << endl;
        return dataValida = false;
    }
    else if(ano < 2025){
        cout << "Ano invalido. Tente novamente." << endl;
        return dataValida = false;
    }

    return dataValida = true;
}

bool verificaReserva(int id, Reserva reserva[], int dia, int mes, int ano, int idLocal, string tipoQuarto){
    for(int i = 0; i < id; i++){
        if(reserva[i].getDia() == dia && reserva[i].getMes() == mes && reserva[i].getAno() == ano){
            if(reserva[i].getLocalidade().getIdLocal() == idLocal){
                if(reserva[i].getQuarto().getTipo() == tipoQuarto){
                    cout << "Quarto ja reservado para essa data. Tente novamente." << endl;
                    return false;
                }
            }
        }
    }
    return true;
}

void defineTipoDesconto(Reserva &reserva, Desconto *&desconto, int opcoes){
    if(reserva.getMes() == 5 || reserva.getMes() == 6 || reserva.getMes() == 7 || reserva.getMes() == 8 || reserva.getMes() == 9){
        desconto = new DescontoBaixaTemporada();
        cout << "Desconto de baixa temporada aplicado: 20%" << endl;
    }
    else if((reserva.getDia() == 25 && reserva.getMes() == 12)||(reserva.getDia() == 1 && reserva.getMes() == 1)){
        desconto = new DescontoFeriado();
        cout << "Desconto de feriado aplicado: 15%" << endl;
    }
    else if(opcoes == 1){
        desconto = new SemDesconto();
        cout << "Cliente normal, sem desconto aplicado." << endl;
    }
    else if(opcoes == 2) {
        desconto = new DescontoVIP();
        cout << "Desconto VIP aplicado: 10%" << endl;
    }
}

void novaReserva(Cliente clientes[], int* id, Reserva reserva[], Localidade local[], Atendente atendente[]){
    int opcoes = -1, opcaoLocal = -1, opcaoQuarto = -1, quantDias = -1, dia = -1, mes = -1, ano = -1;
    string data;
    Desconto* desconto = nullptr;

    cout << "Nova Reserva" << endl;
    cout << "------------------------------------" << endl;
    if(!cadastraCliente(clientes, *id)) return;
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
        cout << "**Data do Check-In (DD/MM/AAAA): ";
        cin >> data;
        dataValida = true;
        
        if(!verificaDataValida(data)){
            dataValida = false;
        }
    }while(!dataValida);
    sscanf(data.c_str(), "%d/%d/%d", &dia, &mes, &ano);
    
    cout << "**Quantos dias de permanencia no hotel: ";
    cin >> quantDias;

    do{
        cout << "**Tipos de Quarto" << endl;
        cout << "  1- Solteiro (uma cama de solteiro) ------------------------------------------- R$ 200,00\n  2- Duplo (duas camas de solteiro) -------------------------------------------- R$ 300,00\n  3- Casal (uma cama de casal) ------------------------------------------------- R$ 350,00\n  4- Triplo (uma cama de casal e uma de solteiro ou tres camas de solteiro) ---- R$ 450,00\n  5- Quadruplo (duas camas de casal ou quatro camas de solteiro) --------------- R$ 550,00" << endl;
        cout << "  Qual opcao o cliente deseja: ";
        cin >> opcoes;

        if(opcoes != 1 && opcoes != 2 && opcoes != 3 && opcoes != 4 && opcoes != 5){
            cout << "Opcao invalida.Tente novamente." << endl;
            continue;
        }
        else if(local[opcaoLocal].getQuarto(opcoes-1).isDisponivel()){
            opcaoQuarto = opcoes - 1;
            break;                   
        }
        else{
            cout << "Quarto indisponivel. Nao foi possivel efetuar a reserva." << endl;
            cout << "Gostaria de tentar novamente? (0- Sim, 1- Nao): ";
            cin >> opcoes;
            if(opcoes == 1){
                cout << "Reserva cancelada." << endl;
                return;
            }
        }

    }while(true);

    if(!verificaReserva(*id, reserva, dia, mes, ano, local[opcaoLocal].getIdLocal(), local[opcaoLocal].getQuarto(opcaoQuarto).getTipo())) return;
    Atendente atend;
    for(int i = 0; i < 4; i++){
        if(atendente[i].isAutenticado())
        atend = atendente[i];
    }
    reserva[*id] = Reserva(*id+1, local[opcaoLocal], dia, mes, ano, quantDias, local[opcaoLocal].getQuarto(opcaoQuarto), clientes[*id], false, atend);

    do{
        cout << "**Tipos de Desconto" << endl;
        cout << "  1- Cliente Normal: Sem desconto\n  2- Clientes VIP: 10\% de desconto." << endl;
        cout << "Qual opcao o cliente se encaixa: ";
        cin >> opcoes;

        defineTipoDesconto(reserva[*id], desconto, opcoes);
        reserva[*id].setDesconto(desconto);

        if(opcoes < 1 || opcoes > 2){
            cout << "Opcao invalida. Tente novamente." << endl;
        }
    }while(opcoes != 1 && opcoes != 2);

    cout << "------------------------------------" << endl;
    cout << "Necessario que o cliente acerte 1/3 do total na hora da reserva." << endl;
    cout << "Valor total sem desconto: R$ " << local[opcaoLocal].getQuarto(opcaoQuarto).getPreco() << " * " << quantDias << " = " << (local[opcaoLocal].getQuarto(opcaoQuarto).getPreco() * quantDias) << endl;
    cout << "Valor total da reserva: R$ " << (local[opcaoLocal].getQuarto(opcaoQuarto).getPreco() * quantDias) * (1 - reserva[*id].getDesconto()) << endl;
    cout << "Valor a ser pago na hora da reserva: R$ " << (local[opcaoLocal].getQuarto(opcaoQuarto).getPreco() * quantDias) * (1 - reserva[*id].getDesconto()) / 3 << endl;
    cout << "O valor foi pago? (1- Sim, 0- Nao): ";
    cin >> opcoes;
    if(opcoes == 1){
        reserva[*id].setConfirmada(true);
        cout << "Reserva efetuada com sucesso!" << endl;
        local[opcaoLocal].getQuarto(opcaoQuarto).setDisponivel(false);
    }
    else if(opcoes == 0){
        reserva[*id].setConfirmada(false);
        cout << "Pendente de Confirmacao" << endl;
    }
    else{
        cout << "Opcao invalida. Reserva nao confirmada." << endl;
        return;
    }
    cout << "------------------------------------" << endl;

    (*id)++;
}

void salvaReservas(FILE *fp, Atendente atendentes[], Reserva reserva[], int* id){
    //salva os dados das reservas no arquivo reservas.txt
    cout << "Salvando dados das reservas..." << endl;
    if(fp != NULL) {
        fprintf(fp, "%i\n", *id);
        for(int i = 0; i < 4; i++){
            if(atendentes[i].isAutenticado()) {
                fprintf(fp, "%s\n", atendentes[i].getUser().c_str());
            }
        }
        for(int i = 0; i < *id; i++){
            fprintf(fp, "%s\n", reserva[i].getCliente().getNome().c_str());
            fprintf(fp, "%s\n", reserva[i].getCliente().getCPF().c_str());
            fprintf(fp, "%s\n", reserva[i].getLocalidade().getNome().c_str());
            fprintf(fp, "%s\n", reserva[i].getQuarto().getTipo().c_str());
            fprintf(fp, "%d/%d/%d\n", reserva[i].getDia(), reserva[i].getMes(), reserva[i].getAno());
            fprintf(fp, "%d\n", reserva[i].getQuantDias());
            fprintf(fp, "%.2f%%\n", reserva[i].getDesconto() * 100);
            fprintf(fp, "%.2f\n", (reserva[i].getQuarto().getPreco() * reserva[i].getQuantDias()) * (1 - reserva[i].getDesconto()));
            fprintf(fp, "%.2f\n", (reserva[i].getQuarto().getPreco() * reserva[i].getQuantDias()) * (1 - reserva[i].getDesconto()) / 3);
            fprintf(fp, "%s\n", reserva[i].IsConfirmada() ? "Sim" : "Nao");
            fprintf(fp, "\n");
        }
        fclose(fp);
    } else {
        cout << "Nao foi possivel abrir o arquivo para salvar as reservas." << endl;
    }
    cout << "Obrigado por utilizar nosso sistema Paradise" << endl;
    cout << "Saindo...\n------------------------------------" << endl;
}

int main(){
    
    //objetos que serão utilizados
    Atendente atendentes[4];
    Cliente clientes[20];
    Reserva reserva[20];
    Quarto quarto[5];
    Localidade local[3];
    
    //usadas para receber as informações do usuário
    int id = 0, menu = 0;
    
    FILE *fp = recebeArquivo();
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
                disponibilidadeQuartos(reserva, local, &id);
                break;
            //caso de executar uma nova reserva
            case 2:
                novaReserva(clientes, &id, reserva, local, atendentes);
                break;
            //caso de sair do sistema
            case 3:
                salvaReservas(fp, atendentes, reserva, &id);
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