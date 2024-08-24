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




void Valor_Total(){
	
	
//==========================================================================================================//

	int formatar_visualizacao = 0;
	int Opcao = 0;
	int receita_total = 0;
	int despesa_total = 0;

	std::string Formato_Segundo_Arquivo = "_Config";
	std::string Formato_Arquivo = ".txt";
	std::string Linha_Arquivo = "A";
	std::string Arquivo = "A";

	std::vector<std::string> Armazenar1;
	std::vector<std::string> Armazenar2;
	std::vector<std::string> Armazenar3;
	std::vector<std::string> Armazenar4;

//==========================================================================================================//	
	
	system("cls");
	
	std::fstream receita1;
	receita1.open("Categorias_Receita.txt",std::fstream::in|std::fstream::app);
	
	while(getline(receita1, Linha_Arquivo)){
			
		Armazenar1.push_back(Linha_Arquivo);
	}
		
	receita1.close();
	
	std::fstream despesa1;
	despesa1.open("Categorias_Despesa.txt",std::fstream::in|std::fstream::app);
	
	while(getline(despesa1, Linha_Arquivo)){
			
		Armazenar2.push_back(Linha_Arquivo);
	}
		
	despesa1.close();
	
	for (const auto& Armazem1 : Armazenar1){
		
		Arquivo = Armazem1 + Formato_Segundo_Arquivo + Formato_Arquivo;
		
		std::fstream receita2;
		receita2.open(Arquivo,std::fstream::in|std::fstream::app);
		
		while(getline(receita2, Linha_Arquivo)){
			
			Armazenar3.push_back(Linha_Arquivo);
		}
		
		receita_total = receita_total + std::stoi(Armazenar3[1]);
		
		std::cout << std::endl;
		std::cout << std::endl;		
		std::cout << "A Receita TOTAL e de R$" << receita_total << " (Reais)." << std::endl;
		std::cout << std::endl;
			
		receita2.close();
	}
	
	
	for (const auto& Armazem2 : Armazenar2){
		
		Arquivo = Armazem2 + Formato_Segundo_Arquivo + Formato_Arquivo;
		
		std::fstream despesa2;
		despesa2.open(Arquivo,std::fstream::in|std::fstream::app);
		
		while(getline(despesa2, Linha_Arquivo)){
			
			Armazenar4.push_back(Linha_Arquivo);
		}
		
		despesa_total = despesa_total + std::stoi(Armazenar4[1]);
		
		std::cout << std::endl;		
		std::cout << "A Despesa TOTAL e de R$" << despesa_total << " (Reais)." << std::endl;
		std::cout << std::endl;	
		std::cout << std::endl;
		
		despesa2.close();	
	}
	
	std::cout << "-----------------------------------------------" << std::endl;
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