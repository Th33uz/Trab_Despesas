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


void Meta(){
	
//==========================================================================================================//

	int contador = 0;
	int escolher = 0;
	int valor_meta = 0;
	
	std::string Linha_Arquivo = "A";
	std::string Nome_Arquivo = "A";
	std::string Formato_Arquivo = ".txt";
	std::string Formato_Segundo_Arquivo = "_Config";

	std::vector<std::string> Armazenar1;
	std::vector<std::string> Armazenar2;

//==========================================================================================================//	
	
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
	std::cout << "Escolha a Categoria que Deseja Alterar a META: ";
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
		
		std::fstream receita2;
		receita2.open(Nome_Arquivo,std::fstream::in|std::fstream::app);
		
		while(getline(receita2, Linha_Arquivo)){
			
			Armazenar2.push_back(Linha_Arquivo);
		}
		
		receita2.close();
		
		system("cls");
		
		std::cout << std::endl;
		std::cout << "A META Atual da Categoria e R$" << Armazenar2[4] << " (Reais)." << std::endl;
		std::cout << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << std::endl;
		std::cout << "Digite o valor da nova META desta Categoria: ";
		std::cin >> valor_meta;	
		
		Armazenar2[4] = std::to_string(valor_meta);
		
		std::fstream receita3;
		receita3.open(Nome_Arquivo,std::fstream::out);
		
		for (const auto& Armazem : Armazenar2){
						
			receita3 << Armazem << "\n";		
    	}
    	
    	receita3.close();
    	
    	std::cout << std::endl;
    	std::cout << "---------------------------------------------" << std::endl;
    	std::cout << std::endl;
    	std::cout << "META Alterada com Suscesso" << std::endl;	
		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");	
	}	
}