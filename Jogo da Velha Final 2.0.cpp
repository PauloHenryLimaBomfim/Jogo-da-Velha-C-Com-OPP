#include <iostream>
#include <string>
#include <locale.h>
#include <cstdlib>
#include <windows.h>

using namespace std;

class Jogadores{
	private:
	    std::string nome;
	    int vitorias;
  		int derrotas;
  		int empates;
  		
	public:
	    Jogadores(std::string nome){
	        this->nome = nome;
	    	this->vitorias = 0;
			this->derrotas = 0;
			this->empates = 0;
		}
	
	    void setNome(std::string nome){
	        this->nome = nome;
	    }
	    std::string getNome(){
	        return nome;
	    }
	    
	    int getVitorias(){
			return this->vitorias;
		}
	    
	    int getDerrotas(){
			return this->derrotas;
		}
	    
	    int getEmpates(){
			return this->empates;
		}
		
		void setVitorias(){
			this->vitorias++;
		}
		
		void setDerrotas(){
			this->derrotas++;
		}
		
		void setEmpates(){
			this->empates++;
		}
		
		void mostrarStatus(){
			cout<<"\tNome: "<< this->getNome()<<"\n\n";
			cout<<"\tVitorias: "<< this->getVitorias()<<"\n";
			cout<<"\tDerrotas: "<< this->getDerrotas()<<"\n";
			cout<<"\tEmpates: "<< this->getEmpates()<<"\n\n";
		}
};

class Partida{
	private:
	    std::string partida[3][3];
	    int rodada;
	    bool vez, vencedor, sentinela;
	    Jogadores jogador1;
	    Jogadores jogador2;
	public:
	    Partida(Jogadores jogador1, Jogadores jogador2): jogador1(jogador1), jogador2(jogador2){
	        for(int i = 0; i < 3; i++){
	            for(int j = 0; j < 3; j++){
	                this->partida[i][j] = ' ';
	            }
	        }
	        rodada = 1;
	        vez = true;
	        vencedor = false;
	        sentinela = true;
	    }
	
	    void setRodada(int rodada){
	        this->rodada = rodada;
	    }
	    int getRodada(){
	        return this->rodada;
	    }
	
  		
	    void setJogador1(Jogadores jogador1){
	        this->jogador1 = jogador1; 
	    }
	    string getJogador1(){
	        return jogador1.getNome();
	    }
	
	    void setJogador2(Jogadores jogador2){
	        this->jogador2 = jogador2; 
	    }
	    string getJogador2(){
	        return jogador2.getNome();
	    }
	    
	    bool getSentinela(){
	    	return this->sentinela;
		}
		
		void setSentinela(bool sentinela){
			this->sentinela = sentinela;
		}
		
	    void iniciaPartida(){
	    	do{
				rodaPartida();
				verificaVez();
				jogar();
				if(rodada >=5){
					verificaVencedor();
				}
				if(!(vencedor)){
					system("cls");	
				}
			}
			while(!(vencedor));
		}
	    
	    void receberNomes(string nome1, string nome2){
	    	jogador1.setNome(nome1);
	    	jogador2.setNome(nome2);
		}
		
	    void rodaPartida(){
			mostrarTabuleiro();
			cout<<"Rodada: "<< this->rodada << "\n";
		}
		
		void verificaVez(){
		    cout<<"Lembrando: "<< jogador1.getNome()<<" = x e "<< jogador2.getNome()<<" = O \n";	
			if(vez){
				cout<<"É a vez do "<< jogador1.getNome()<<"\n";
			}
			else{
				cout<<"É a vez do "<< jogador2.getNome()<<"\n";
			}
		}
		
		void jogar(){
			int linha, coluna;
			cout<<"Linha: ";
			cin>>linha;
			cout<<"Coluna: ";
			cin>>coluna;
			
			linha--;
			coluna--;
			if(linha <= 2 && coluna <=2){
				if(partida[linha][coluna]== " "){
					if(vez){
						partida[linha][coluna] = 'x';
						rodada++;
					}
					else{
						partida[linha][coluna] = 'O';
						rodada++;
					}
					vez = !(vez);
				}
				else{
					posiInvalida();
				}
			}
			else{
				posiInvalida();
			}
		}
		
		void posiInvalida(){
			cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n";
			cout<<"Posição invalida! Tente novamente! \n";
			cout<<"-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-= \n";
			Sleep(2000);
		}
		
	    void mostrarTabuleiro(){
	    	cout<<"\n\n\n\n";
	    
	        for(int i = 0; i < 3; i++){
	            for(int j = 0; j < 3; j++){
	                std::cout <<"\t"+ this->partida[i][j];
	                if(j < 2){
	                    std::cout << "\t|";
	                }
	            }
				std::cout << "\n";
	        }
	        
	        cout<<"\n\n\n\n";
	        for(int i = 0; i < 3; i++){
	            for(int j = 0; j < 3; j++){
	                std::cout <<"\t["<< i+1 <<"]["<< j+1 <<"] ";																																																																																																																																																																											
	                if(j < 2){
	                    std::cout << " |";
	                }
	            }
	            std::cout << "\n";
	        }
	        cout<<"\n\n";
	    }
	    
	    void zerarPartida(){
	    	rodada = 1;
	    	vez = true;
	    	vencedor = false;
			for(int i = 0; i < 3; i++){
	            for(int j = 0; j < 3; j++){
	                this->partida[i][j] = ' ';
	            }
	        }
		}
		
		void verificaVencedor(){
			if((partida[0][0] == partida[1][1] && partida[2][2] == partida[1][1]) || (partida[2][0] == partida[1][1] && partida[1][1] == partida[0][3])){
				if(partida[1][1] == "x"){
					system("cls");
					vencedor = true;
					mostrarTabuleiro();
					cout<<"O vencendor é "<<jogador1.getNome()<<"\n\n\n";
					posPartida();
				}
				else{
					system("cls");
					vencedor = true;
					mostrarTabuleiro();
					cout<<"O vencedor é "<<jogador2.getNome()<<"\n\n\n";
					posPartida();
				}
			}
			for (int i = 0; i < 3; i++) {
		        if ((partida[i][0] == partida[i][1] && partida[i][1] == partida[i][2]) || 
		            (partida[0][i] == partida[1][i] && partida[1][i] == partida[2][i])) {
		            if (partida[i][i] == "x") {
		                system("cls");
		                jogador1.setVitorias();
		                jogador2.setDerrotas();
		                vencedor = true;
		                mostrarTabuleiro();
		                cout << "O vencedor é " << jogador1.getNome()<<"\n\n\n";
		                posPartida();
		            } 
					else if (partida[i][i] == "O") {
		                system("cls");
		                jogador1.setDerrotas();
						jogador2.setVitorias();
		                vencedor = true;
		                mostrarTabuleiro();
		                cout << "O vencedor é " << jogador2.getNome()<<"\n\n\n";
		                posPartida();
		            }
		        }
			}
				if(rodada > 9 && vencedor == false){
					jogador1.setEmpates();
					jogador2.setEmpates();
					vencedor = true;
					system("cls");
					mostrarTabuleiro();
					cout<<"\n Deu velha! \n\n";
					posPartida();
				}
		}
		
		void continuaJogo(bool &sentinela){
			sentinela = false;
		}
		
		void posPartida(){
			int opcao = 0;
			cout<<"Pressione ( 1 ) para revanche \nPressione ( 2 ) para verificar status dos jogadores \nPressione ( 3 ) para fechar a partida\n";
			cin>>opcao;
			switch(opcao){
				case 1:
					zerarPartida();
					break;
				case 2:
					system("cls");
					jogador1.mostrarStatus();
					jogador2.mostrarStatus();
				case 3:
					this->setSentinela(false);
					break;
				default:
					break;
			}
		}
		
		void menu(){
			bool sentinela = true;
			do{
				int opcao;
				cout<<"\n\tPressione ( 1 ) para iniciar partida \n";
				cout<<"\tPressione ( 2 ) para verificar status dos jogadores \n";
	    		cout<<"\tPressione ( 3 ) para fechar o jogo \n";
	    		cin>>opcao;
	    		switch(opcao){
					case 1:
						system("cls");
						this->zerarPartida();
						this->iniciaPartida();
						break;
					case 2:
						jogador1.mostrarStatus();
						jogador2.mostrarStatus();
						Sleep(5000);
						system("cls");
						break;
					case 3:
						sentinela = false;
						this->setSentinela(false);
						break;
					default:
						break;
				}
			}while(sentinela);
		}
};

int main() {
	setlocale(LC_ALL,"Portuguese");
	string nome1, nome2;
	Jogadores j1("Jogador 1");
    Jogadores j2("Jogador 2");
    Partida partida(j1, j2);
    
	do{
		cout<<"Entre com o nome do jogador 1: ";
		cin>>nome1;
		cout<<"Entre com o nome do jogador 2: ";
		cin>>nome2;
    	partida.receberNomes(nome1, nome2);
    	partida.menu();
	}while(partida.getSentinela());
    
    
}
