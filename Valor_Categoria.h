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


void Valor_Categoria(){
	
	
//==========================================================================================================//

	int identificador = 0;
	int contador = 0;
	int escolha = 0;
	int Opcao = 0;

	std::string Nome_Arquivo = ".txt";
	std::string Linha_Arquivo = "A";
	std::string Formato_Arquivo = ".txt";
	std::string Formato_Segundo_Arquivo = "_Config";

	std::vector<std::string> Armazenar1;
	std::vector<std::string> Armazenar2;

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
		std::cout << "Escolha uma Categoria para Visualizar o Valor TOTAL: ";
		std::cin >> escolha;
		
		if(escolha > contador || escolha <= 0){
			
			std::cout << std::endl;
			std::cout << "Opcao Invalida" << std::endl;
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");	
		}
		
		else{
			
			Nome_Arquivo = Armazenar1[escolha - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
		
			std::fstream receita2;
			receita2.open(Nome_Arquivo,std::fstream::in|std::fstream::app);
		
			while(getline(receita2, Linha_Arquivo)){
				
				Armazenar2.push_back(Linha_Arquivo);	
			}
		
			receita2.close();
			
			system("cls");
			
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "O Valor TOTAL da RECEITA dessa Categoria e de R$" << Armazenar2[1] << " (Reais)." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
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
		std::cout << "Escolha uma Categoria para Visualizar o Valor TOTAL: ";
		std::cin >> escolha;
		
		if(escolha > contador || escolha <= 0){
			
			std::cout << std::endl;
			std::cout << "Opcao Invalida" << std::endl;
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		}
		
		else{
			
			Nome_Arquivo = Armazenar1[escolha - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
			
			std::fstream despesa2;
			despesa2.open(Nome_Arquivo,std::fstream::in|std::fstream::app);
			
			while(getline(despesa2, Linha_Arquivo)){
					
				Armazenar2.push_back(Linha_Arquivo);	
			}
			
			despesa2.close();
			
			system("cls");
			
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "O Valor TOTAL de DESPESA dessa Categoria e de R$" << Armazenar2[1] << " (Reais)." << std::endl;
			std::cout << std::endl;
			std::cout << std::endl;
			std::cout << "--------------------------------------------------------------------------------" << std::endl;
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
	}
	
	else{
		
		std::cout << std::endl;
		std::cout << "Opcao Invalida" << std::endl;
		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");	
	}
}