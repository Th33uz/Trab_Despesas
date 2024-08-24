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



void Limite(){

	
//==========================================================================================================//
	
	int contador = 0;
	int escolher = 0;
	int valor_limite = 0;
	
	std::string Linha_Arquivo = "A";
	std::string Nome_Arquivo = "A";
	std::string Formato_Arquivo = ".txt";
	std::string Formato_Segundo_Arquivo = "_Config";
	
	std::vector<std::string> Armazenar1;
	std::vector<std::string> Armazenar2;
	
//==========================================================================================================//	
	
	
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
	std::cout << "Escolha a Categoria que Deseja Alterar o LIMITE: ";
	std::cin >> escolher;
	
	if(escolher > contador || escolher <=0){
		
		std::cout << std::endl;
		std::cout << "Opcao Invalida" << std::endl;
		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");
	}
	
	else{
		
		Nome_Arquivo = Armazenar1[escolher - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
	
		std::fstream despesa2;
		despesa2.open(Nome_Arquivo,std::fstream::in|std::fstream::app);
		
		while(getline(despesa2, Linha_Arquivo)){
			
			Armazenar2.push_back(Linha_Arquivo);
		}
		
		despesa2.close();
		
		system("cls");
		
		std::cout << std::endl;
		std::cout << "O LIMITE Atual da Categoria e R$" << Armazenar2[4] << " (Reais)." << std::endl;
		std::cout << std::endl;
		std::cout << "----------------------------------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "Digite o valor do novo LIMITE desta Categoria: ";
		std::cin >> valor_limite;
		
		if(valor_limite < std::stoi(Armazenar2[4])){
			
			std::cout << std::endl;
			std::cout << "Atencao, voce esta Tentando definir um LIMITE menor que o valor Atual" << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(2));
			system("cls");
		}
		
		else{
			
			Armazenar2[4] = std::to_string(valor_limite);
			
			std::fstream despesa3;
			despesa3.open(Nome_Arquivo,std::fstream::out);
		
			for (const auto& Armazem : Armazenar2){
						
				despesa3 << Armazem << "\n";		
    		}
    	
    		despesa3.close();
    		
    		std::cout << std::endl;
	    	std::cout << "----------------------------------------------------------------" << std::endl;
	    	std::cout << std::endl;
	    	std::cout << "LIMITE Alterada com Suscesso" << std::endl;	
			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
			std::this_thread::sleep_for(std::chrono::seconds(3));
			system("cls");
		}	
	}	
}