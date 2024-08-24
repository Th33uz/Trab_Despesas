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


void Exclusao_Categoria(){
	
//==========================================================================================================//

	int identificador = 0;
	int contador = 0;
	int escolher = 0;
	
	std::string Linha_Arquivo = "A";
	std::string Excluir_Arquivo = "A";
	std::string Excluir_Arquivo_Configuracao = "A";
	std::string Formato_Arquivo = ".txt";
	std::string Formato_Segundo_Arquivo = "_Config";
	
	std::vector<std::string> Armazenar;
	
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
			Armazenar.push_back(Linha_Arquivo);
		}
		
		receita1.close();
		
		std::cout << std::endl;
		std::cout << "=====================" << std::endl;
		std::cout << std::endl;
		std::cout << "Escolha a Categoria que deseja Excluir: ";
		std::cin >> escolher;
		
		if(escolher > contador || escolher <= 0){
			
			std::cout << std::endl;
			std::cout << "Opcao Invalida" << std::endl;
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		}
		
		else{
			
			Excluir_Arquivo = Armazenar[escolher - 1] + Formato_Arquivo;
			Excluir_Arquivo_Configuracao = Armazenar[escolher - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
			
			if(remove(Excluir_Arquivo.c_str()) == 0){
				
				if(remove(Excluir_Arquivo_Configuracao.c_str()) ==0){
					
					std::fstream receita1;
					receita1.open("Categorias_Receita.txt",std::fstream::out);
				
					for (const auto& Armazem : Armazenar){
							
						if(Armazem == Armazenar[escolher - 1]){
								
						}
							
						else{
								
							receita1 << Armazem << "\n";
						}
	    			}
						
					receita1.close();
					
					std::cout << "Categoria Excluida com Sucesso." << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");	
				}
				
				else{
					
					std::cout << std::endl;
        			std::cout << "Erro ao tentar Excluir a Categoria" << std::endl;
        			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
			}
			
			else{
				
				std::cout << std::endl;
        		std::cout << "Erro ao tentar Excluir a Categoria" << std::endl;
        		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				system("cls");
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
			Armazenar.push_back(Linha_Arquivo);
		}
		
		despesa1.close();
		
		std::cout << std::endl;
		std::cout << "=====================" << std::endl;
		std::cout << std::endl;
		std::cout << "Escolha a Categoria que deseja Excluir: ";
		std::cin >> escolher;
		
		if(escolher > contador || escolher <= 0){
			
			std::cout << std::endl;
			std::cout << "Opcao Invalida" << std::endl;
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		}
		
		else{
			
			Excluir_Arquivo = Armazenar[escolher - 1] + Formato_Arquivo;
			Excluir_Arquivo_Configuracao = Armazenar[escolher - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
			
			if(remove(Excluir_Arquivo.c_str()) == 0){
				
				if(remove(Excluir_Arquivo_Configuracao.c_str()) ==0){
					
					std::fstream despesa1;
					despesa1.open("Categorias_Despesa.txt",std::fstream::out);
				
					for (const auto& Armazem : Armazenar){
							
						if(Armazem == Armazenar[escolher - 1]){
								
						}
							
						else{
								
							despesa1 << Armazem << "\n";
						}
	    			}
						
					despesa1.close();
					
					std::cout << "Categoria Excluida com Sucesso." << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");	
				}
				
				else{
					
					std::cout << std::endl;
        			std::cout << "Erro ao tentar Excluir a Categoria" << std::endl;
        			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
			}
			
			else{
				
				std::cout << std::endl;
        		std::cout << "Erro ao tentar Excluir a Categoria" << std::endl;
        		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
				std::this_thread::sleep_for(std::chrono::seconds(3));
				system("cls");
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