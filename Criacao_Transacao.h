#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <locale.h>
#include <fstream>
#include <cstdio>
#include <thread>
#include <chrono>


void Criacao_Transacao(){
	
//==========================================================================================================//
	
	int identificador = 0;
	int contador = 0;
	int escolher = 0;
	int opcao_meta_limite = 0;
	int nova_meta_limite = 0;
	int antiga_meta_limite = 0;
	int codigo_transacao = 0;
	
	std::string Linha_Arquivo = "A";
	std::string Categoria_Config_Transacao = "A";
	std::string Categoria_Inserir_Transacao = "A";
	std::string Formato_Arquivo = ".txt";
	std::string Formato_Segundo_Arquivo = "_Config";
	
	std::vector<std::string> Armazenar1;
	std::vector<std::string> Armazenar2;
	
//==========================================================================================================//	
	
	int Valor_Transacao = 0;
	std::string Descricao_Transacao = "A";
	std::string Data_Transacao = "A";
	std::string Metodo_Transacao = "A";
	
//==========================================================================================================//
	
	
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Escolha Uma das opcoes Abaixo:" << std::endl;
	std::cout << "1 -> Receita" << std::endl;
	std::cout << "2 -> Despesa" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Opcao: ";
	std::cin >> identificador;
	
	if(identificador==1){
		
		system("cls");
		std::cout << std::endl;
		std::cout << "Categorias de RECEITA" << std::endl;
		std::cout << "=====================" << std::endl;
		std::cout << std::endl;
		
		std::fstream receita1;
		receita1.open("Categorias_Receita.txt",std::fstream::in|std::fstream::app);
		
		while(getline(receita1, Linha_Arquivo)){
				
			contador++;	
			std::cout << contador << " -> " << Linha_Arquivo << std::endl;
			Armazenar1.push_back(Linha_Arquivo);	
		}
		
		receita1.close();
		
		std::cout << std::endl;
		std::cout << "=====================" << std::endl;
		std::cout << std::endl;
		std::cout << "Escolha a Categoria que Deseja adicionar uma Transacao: ";
		std::cin >> escolher;
		
		if(escolher > contador || escolher <=0){
			
			std::cout << std::endl;
			std::cout << "Opcao Invalida" << std::endl;
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		}
		
		else{
			
			system("cls");
			
			std::cout << std::endl;
			std::cout << "Informacoes da Transacao" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << "Descricao: ";
			std::cin.ignore();
			std::getline(std::cin, Descricao_Transacao);
			//std::cin >> Descricao_Transacao;
			std::cout << "DATA: ";
			std::cin.ignore();
			std::getline(std::cin, Data_Transacao);
			//std::cin >> Data_Transacao;
			std::cout << "VALOR: ";
			std::cin >> Valor_Transacao;
			std::cout << "Metodo de Recebimento: ";
			std::cin.ignore();
			std::getline(std::cin, Metodo_Transacao);
			//std::cin >> Metodo_Transacao;
			std::cout << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			std::cout << std::endl;
			
			Categoria_Inserir_Transacao = Armazenar1[escolher - 1] + Formato_Arquivo;
			Categoria_Config_Transacao = Armazenar1[escolher - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
			
			std::fstream transacao1;
			transacao1.open(Categoria_Config_Transacao,std::fstream::in|std::fstream::app);
			
			while(getline(transacao1, Linha_Arquivo)){
				
				Armazenar2.push_back(Linha_Arquivo);
			}
			
			transacao1.close();
			
			antiga_meta_limite = std::stoi(Armazenar2[4]);
			
			if(antiga_meta_limite <= Valor_Transacao){
				std::cout << "Voce Bateu a META definida nessa Categoria!" << std::endl;
				std::cout << "META Atual: R$" <<  Armazenar2[4] << std::endl;
				std::cout << std::endl;
				std::cout << "-------------------------------------------" << std::endl;
				std::cout << "Deseja Redefinir a META desta Categoria?" << std::endl;
				std::cout << "1 -> Sim" << std::endl;
				std::cout << "2 -> Nao" << std::endl;
				std::cout << "-------------------------------------------" << std::endl;
				std::cout << "Opcao: ";
				std::cin >> opcao_meta_limite;
				
				if(opcao_meta_limite==1){
					
					std::cout << std::endl;
					std::cout << "Digite o Valor da nova META desta Categoria: ";
					std::cin >> nova_meta_limite;
					
					Armazenar2[4] = std::to_string(nova_meta_limite);
				}
				
				else if(opcao_meta_limite==2){
					
					std::cout << std::endl;
					std::cout << "Voce pode Alterar o Valor da META desta Categoria posteriormente!" << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(1));
				}
				
				else{
					
					std::cout << std::endl;
					std::cout << "Opcao Invalida" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
			}
			
			if(opcao_meta_limite==1 || opcao_meta_limite==2 || antiga_meta_limite > Valor_Transacao){
			
				std::fstream transacao2;
				transacao2.open(Categoria_Inserir_Transacao,std::fstream::out|std::fstream::app);
				
				if(transacao2.is_open()){
					
					codigo_transacao = std::stoi(Armazenar2[7]) + 1;
					Armazenar2[7] = std::to_string(codigo_transacao);
					
					transacao2 << Armazenar2[7] << "\n";
					transacao2 << Descricao_Transacao << "\n";
					transacao2 << Data_Transacao << "\n";
					transacao2 << Valor_Transacao << "\n";
					transacao2 << Metodo_Transacao << "\n";
					transacao2 << "\n";
					
					transacao2.close();
					
					std::fstream transacao1;
					transacao1.open(Categoria_Config_Transacao,std::fstream::out);
					
					if(transacao1.is_open()){
						
						Valor_Transacao = Valor_Transacao + std::stoi(Armazenar2[1]);
						Armazenar2[1] = std::to_string(Valor_Transacao);
						
						for (const auto& Armazem : Armazenar2){
							
							transacao1 << Armazem << "\n";		
	    				}
	    				
	    				transacao1.close();
	    				
						std::cout << "Transacao realizada com Suscesso" << std::endl;	
						std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");		
					}
					
					else{
						
						transacao1.close();
						std::cout << std::endl;
						std::cout << "Nao foi Possivel realizar a Transacao" << std::endl;	
						std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");	
					}
				}
			
				else{
					
					transacao2.close();
					std::cout << std::endl;
					std::cout << "Nao foi Possivel realizar a Transacao" << std::endl;	
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");	
				}
			}
		}
	}
	
	else if(identificador==2){
		
		system("cls");
		std::cout << std::endl;
		std::cout << "Categorias de DESPESA" << std::endl;
		std::cout << "=====================" << std::endl;
		std::cout << std::endl;
		
		std::fstream despesa1;
		despesa1.open("Categorias_Despesa.txt",std::fstream::in|std::fstream::app);
		
		while(getline(despesa1, Linha_Arquivo)){
				
			contador++;	
			std::cout << contador << " -> " << Linha_Arquivo << std::endl;
			Armazenar1.push_back(Linha_Arquivo);	
		}
		
		despesa1.close();
		
		std::cout << std::endl;
		std::cout << "=====================" << std::endl;
		std::cout << std::endl;
		std::cout << "Escolha a Categoria que Deseja adicionar uma Transacao: ";
		std::cin >> escolher;
		
		if(escolher > contador || escolher <=0){
			
			std::cout << std::endl;
			std::cout << "Opcao Invalida" << std::endl;
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		}
		
		else{
			
			system("cls");
			
			std::cout << std::endl;
			std::cout << "Informacoes da Transacao" << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << "Descricao: ";
			std::cin.ignore();
			std::getline(std::cin, Descricao_Transacao);
			//std::cin >> Descricao_Transacao;
			std::cout << "DATA: ";
			std::cin.ignore();
			std::getline(std::cin, Data_Transacao);
			//std::cin >> Data_Transacao;
			std::cout << "VALOR: ";
			std::cin >> Valor_Transacao;
			std::cout << "Metodo de Pagamento: ";
			std::cin.ignore();
			std::getline(std::cin, Metodo_Transacao);
			//std::cin >> Metodo_Transacao;
			std::cout << std::endl;
			std::cout << "-------------------------------------------" << std::endl;
			std::cout << std::endl;
			
			Categoria_Inserir_Transacao = Armazenar1[escolher - 1] + Formato_Arquivo;
			Categoria_Config_Transacao = Armazenar1[escolher - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
			
			std::fstream transacao3;
			transacao3.open(Categoria_Config_Transacao,std::fstream::in|std::fstream::app);
			
			while(getline(transacao3, Linha_Arquivo)){
				
				Armazenar2.push_back(Linha_Arquivo);
			}
			
			transacao3.close();
			
			antiga_meta_limite = std::stoi(Armazenar2[1]) + Valor_Transacao;
			
			if(antiga_meta_limite <= std::stoi(Armazenar2[4])){
				
				std::fstream transacao4;
				transacao4.open(Categoria_Inserir_Transacao,std::fstream::out|std::fstream::app);
				
				if(transacao4.is_open()){
					
					codigo_transacao = std::stoi(Armazenar2[7]) + 1;
					Armazenar2[7] = std::to_string(codigo_transacao);
					
					transacao4 << Armazenar2[7] << "\n";
					transacao4 << Descricao_Transacao << "\n";
					transacao4 << Data_Transacao << "\n";
					transacao4 << Valor_Transacao << "\n";
					transacao4 << Metodo_Transacao << "\n";
					transacao4 << "\n";
					
					transacao4.close();
					
					std::fstream transacao3;
					transacao3.open(Categoria_Config_Transacao,std::fstream::out);
					
					if(transacao3.is_open()){
						
						Valor_Transacao = Valor_Transacao + std::stoi(Armazenar2[1]);
						Armazenar2[1] = std::to_string(Valor_Transacao);
						
						for (const auto& Armazem : Armazenar2){
							
							transacao3 << Armazem << "\n";		
	    				}
	    				
	    				transacao3.close();
	    				
						std::cout << "Transacao realizada com Suscesso" << std::endl;	
						std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");		
					}
					
					else{
						
						transacao3.close();
						std::cout << std::endl;
						std::cout << "Nao foi Possivel realizar a Transacao" << std::endl;	
						std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");	
					}
				}
			
				else{
					
					transacao4.close();
					std::cout << std::endl;
					std::cout << "Nao foi Possivel realizar a Transacao" << std::endl;	
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");	
				}		
			}
			
			else{
				
				std::cout << "Voce Atingiu o LIMITE definido nessa Categoria!" << std::endl;
				std::cout << "LIMITE Atual: R$" <<  Armazenar2[4] << std::endl;
				std::cout << std::endl;
				std::cout << "-------------------------------------------" << std::endl;
				std::cout << "Deseja Redefinir o LIMITE desta Categoria?" << std::endl;
				std::cout << "1 -> Sim" << std::endl;
				std::cout << "2 -> Nao" << std::endl;
				std::cout << "-------------------------------------------" << std::endl;
				std::cout << "Opcao: ";
				std::cin >> opcao_meta_limite;
				
				if(opcao_meta_limite==1){
					
					std::cout << std::endl;
					std::cout << "Digite o novo LIMITE desta Categoria: ";
					std::cin >> nova_meta_limite;
					
					if(nova_meta_limite <= std::stoi(Armazenar2[4])){
						
						std::cout << "Voce Nao pode Alterar o LIMITE da Categoria por um Valor MENOR OU IGUAL ao Atual!" << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(1));
						std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");
					}
					
					else{
						
						Armazenar2[4] = std::to_string(nova_meta_limite);
						
						std::fstream transacao3;
						transacao3.open(Categoria_Config_Transacao,std::fstream::out);
						
						if(transacao3.is_open()){
							
							for (const auto& Armazem1 : Armazenar2){
								
								transacao3 << Armazem1 << "\n";		
		    				}
		    				
		    				transacao3.close();	
		    			
							std::cout << "LIMITE Alterado com Suscesso" << std::endl;	
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
						
						else{
							
							transacao3.close();
							std::cout << std::endl;
							std::cout << "Nao foi Possivel Redefinir o LIMITE" << std::endl;	
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
					}
				}
				
				else if(opcao_meta_limite==2){
					
					std::cout << std::endl;
					std::cout << "Voce pode Alterar o LIMITE desta Categoria posteriormente!" << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(1));
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
				
				else{
					
					std::cout << std::endl;
					std::cout << "Opcao Invalida" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}	
			}
		}		
	}
	
	else{
		
		std::cout << std::endl;
		std::cout << "Opcao Invalida" << std::endl;
		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");	
	}	
}