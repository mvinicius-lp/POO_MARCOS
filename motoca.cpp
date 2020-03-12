#include <iostream>
#include <sstream>

using namespace std;

struct Pessoa {
    string nome;
    int idade;

    Pessoa(string nome = "", int idade = -1){
        this->nome = nome;
        this->idade = idade;
        cout << this->nome << " esta nascendo\n"; 
    }
    ~Pessoa(){
        cout << this->nome << " esta morrendo\n";
    }
};

struct Motinha{
    Pessoa * pessoa = NULL; //agregação
    //Pessoa pessoa = null;
    int potencia;
    Motinha (int potencia = 0){
		this -> potencia = potencia;
	}
    void embarcar(Pessoa * pessoa){
        if(this->pessoa != NULL)
            cout << "ja tem gente na motinha\n";
        else
            this->pessoa = pessoa;
    }
    void barulho(){
		for(int i = 0; i < this->potencia; i++){
			cout << "run ";
		}
	}

    Pessoa * desembarcar(){
        if(this->pessoa == NULL)
            return NULL;
        Pessoa * temp = this->pessoa;
        this->pessoa = NULL;
        return temp; 
    }

    void dirigir(){
        if(this->pessoa == NULL)
            cout << "nao tem ninguem na motinha\n"; 
        else if(this->pessoa->idade >= 4){
            cout << pessoa->nome << ": Urruuu, dando uma voltinha\n";
            this->barulho();
        }
        else
            cout << pessoa->nome << "Você não sabe andar ainda\n";
    }

};

int main() {
	Motinha *motinha=new Motinha();
    while(true){
        string line;
        getline(cin, line);
        stringstream ss(line);
        string cmd;
        ss >> cmd;
        if(cmd == "end"){
            break;
        }else if(cmd == "embarcar"){//nome idade
            string nome;
            int idade;
            ss >> nome >> idade;
            
            motinha->embarcar(new Pessoa(nome, idade));

        }else if(cmd == "init"){
			int potencia;
			ss>> potencia;
			motinha = new Motinha(potencia);
		}else if(cmd == "dirigir"){
            motinha->dirigir();
        }else if(cmd == "desembarcar"){
            Pessoa * temp = motinha->desembarcar();
            if(temp != NULL)
                delete temp;
        }else{
            cout << "comando invalido\n";
        }
    }
}


