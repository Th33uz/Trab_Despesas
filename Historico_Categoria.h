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


void Historico_Categoria(){
	

//==========================================================================================================//

	int identificador = 0;
	int contador = 0;
	int escolher = 0;
	int formatar_visualizacao = 0;
	int Opcao = 0;
	
	std::string Linha_Arquivo = "A";
	std::string Categoria_Historico = "A";
	std::string Formato_Arquivo = ".txt";

	std::vector<std::string> Armazenar1;
	
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
		std::cout << "Escolha a Categoria que Deseja obter o Historico: ";
		std::cin >> escolher;
		
		Categoria_Historico = Armazenar1[escolher - 1] + Formato_Arquivo;
		
		system("cls");
		
		std::cout << std::endl;
		std::cout << "Historico de Transacoes" << std::endl;
		std::cout << "=======================" << std::endl;
		std::cout << std::endl;
		
		std::fstream receita2;
		receita2.open(Categoria_Historico,std::fstream::in|std::fstream::app);
		
		while(getline(receita2, Linha_Arquivo)){
			
			formatar_visualizacao++;
			
			if(formatar_visualizacao==1){
				
				std::cout << "Codigo: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==2){
				
				std::cout << "Descricao: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==3){
				
				std::cout << "DATA: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==4){
				
				std::cout << "VALOR: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==5){
				
				std::cout << "Metodo de Recebimento: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==6){
				
				std::cout << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cout << std::endl;
				formatar_visualizacao = 0;
			}		
		}
				
		receita2.close();
		
		std::cout << std::endl;
		std::cout << "Selecione a opcao para Voltar ao MENU PRINCIPAL" << std::endl;
		std::cout << "===============================================" << std::endl;
		std::cout << "1 -> SAIR" << std::endl;
		std::cout << "===============================================" << std::endl;
		std::cout << "Opcao: ";
		std::cin >> Opcao;
		
		if(Opcao==1){
			
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
		std::cout << "Escolha a Categoria que Deseja obter o Historico: ";
		std::cin >> escolher;
		
		Categoria_Historico = Armazenar1[escolher - 1] + Formato_Arquivo;
		
		system("cls");
		
		std::cout << std::endl;
		std::cout << "Historico de Transacoes" << std::endl;
		std::cout << "=======================" << std::endl;
		std::cout << std::endl;
		
		std::fstream despesa2;
		despesa2.open(Categoria_Historico,std::fstream::in|std::fstream::app);
		
		while(getline(despesa2, Linha_Arquivo)){
			
			formatar_visualizacao++;
			
			if(formatar_visualizacao==1){
				
				std::cout << "Codigo: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==2){
				
				std::cout << "Descricao: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==3){
				
				std::cout << "DATA: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==4){
				
				std::cout << "VALOR: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==5){
				
				std::cout << "Metodo de Pagamento: " << Linha_Arquivo << std::endl;
			}
			
			else if(formatar_visualizacao==6){
				
				std::cout << std::endl;
				std::cout << "---------------------------------------------" << std::endl;
				std::cout << std::endl;
				formatar_visualizacao = 0;
			}		
		}
			
		despesa2.close();
		
		std::cout << std::endl;
		std::cout << "Selecione a opcao para Voltar ao MENU PRINCIPAL" << std::endl;
		std::cout << "===============================================" << std::endl;
		std::cout << "1 -> SAIR" << std::endl;
		std::cout << "===============================================" << std::endl;
		std::cout << "Opcao: ";
		std::cin >> Opcao;
		
		if(Opcao==1){
			
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
	
	else{
		
		std::cout << std::endl;
		std::cout << "Opcao Invalida" << std::endl;
		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");
	}	
}