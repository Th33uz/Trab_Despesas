#include <iostream>
#include <string>
#include <vector>
#include <cstdio>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <thread>
#include <chrono>


void Criacao_Categoria(){
	
//======================================================================================================================================================//
	
	int contador = 0;
	int identificador = 0;
	int definir = 0; 
	int Limite_Meta_Categoria = 0;
	
	std::string Nome_Novo_Categoria = "A";
	std::string formato_Arquivo = ".txt"; 
	std::string Checar_Arquivos_Existentes = "A"; 
	std::string Formacao_Nome_Nova_Categoria = "A";
	std::string Formacao_Nome_Conf_Categoria = "A";
	std::string segundo_arquivo = "_Config";

//======================================================================================================================================================//
	
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Escolha Uma das opcoes Abaixo:" << std::endl;
	std::cout << "1 -> Receita" << std::endl;
	std::cout << "2 -> Despesa" << std::endl;
	std::cout << "---------------------------------------------" << std::endl;
	std::cout << "Opcao: ";
	std::cin >> identificador;
	
	if(identificador==1 || identificador==2){
		
		std::cout << "Digite o nome da Categoria: ";
		std::cin.ignore();
		std::getline(std::cin, Nome_Novo_Categoria);
		//std::cin >> Nome_Novo_Categoria;

	
		Formacao_Nome_Nova_Categoria = Nome_Novo_Categoria + formato_Arquivo;
		Formacao_Nome_Conf_Categoria = Nome_Novo_Categoria + segundo_arquivo + formato_Arquivo;
	
		if(identificador==1){
			
			std::cout << std::endl;
			std::cout << "-------------------------------------------------" << std::endl;
			std::cout << "Deseja definir uma META para essa Categoria?" << std::endl;
			std::cout << "1 -> Sim" << std::endl;
			std::cout << "2 -> Nao" << std::endl;
			std::cout << "-------------------------------------------------" << std::endl;
			std::cout << "Opcao: ";
			std::cin >> definir;
			
			if(definir==1){
				std::cout << "Digite uma Meta para a Categoria: ";
				std::cin >> Limite_Meta_Categoria;	
			}
			
			if(definir==1 || definir==2){
				
				std::fstream receita1;
				receita1.open("Categorias_Receita.txt",std::fstream::in|std::fstream::app);
			
				while(getline(receita1, Checar_Arquivos_Existentes)){
				
					if(Checar_Arquivos_Existentes == Nome_Novo_Categoria){
					
						contador++;	
					}
				}
				
				receita1.close();
				
				if(contador>0){
				
					std::cout << "Essa Categoria ja Existe" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
			
				else{
				
					receita1.open("Categorias_Receita.txt",std::fstream::out|std::fstream::app);
					receita1 << Nome_Novo_Categoria << "\n";
					receita1.close();
			
					std::fstream receita2;
					receita2.open(Formacao_Nome_Nova_Categoria,std::fstream::out|std::fstream::app);
			
					if(receita2.is_open()){
						
						std::fstream receita3;
						receita3.open(Formacao_Nome_Conf_Categoria,std::fstream::out|std::fstream::app);
						
						if(receita3.is_open()){
							
							receita3 << "Valor TOTAL:" << "\n";
							receita3 << "0" << "\n";
							receita3 << "\n";
							receita3 << "META:" << "\n";
							receita3 << Limite_Meta_Categoria << "\n";
							receita3 << "\n";
							receita3 << "Ultimo Cadastro:" << "\n";
							receita3 << "0" << "\n";
							
							receita3.close();
							
							std::cout << std::endl;
							std::cout << "Categoria Criada com Suscesso" << std::endl;
							receita2.close();
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
						
						else{
							
							std::cout << "Nao foi possivel Criar a Categoria" << std::endl;	
							receita2.close();
							receita3.close();
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");	
						}
					}
			
					else{
				
						std::cout << "Nao foi possivel Criar a Categoria" << std::endl;	
						receita2.close();
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
		
		else if(identificador==2){
			
			std::cout << std::endl;
			std::cout << "-------------------------------------------------" << std::endl;
			std::cout << "Deseja definir um LIMITE para essa Categoria?" << std::endl;
			std::cout << "1 -> Sim" << std::endl;
			std::cout << "2 -> Nao" << std::endl;
			std::cout << "-------------------------------------------------" << std::endl;
			std::cout << "Opcao: ";
			std::cin >> definir;
			
			if(definir==1){
				std::cout << "Digite um LIMITE para a Categoria: ";
				std::cin >> Limite_Meta_Categoria;	
			}
			
			if(definir==1 || definir==2){
			
				std::fstream despesa1;
				despesa1.open("Categorias_Despesa.txt",std::fstream::in|std::fstream::app);
			
				while(getline(despesa1, Checar_Arquivos_Existentes)){
				
					if(Checar_Arquivos_Existentes == Nome_Novo_Categoria){
					
						contador++;	
					}
				}
				
				despesa1.close();
				
				if(contador>0){
				
					std::cout << "Essa Categoria ja Existe" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
			
				else{
				
					despesa1.open("Categorias_Despesa.txt",std::fstream::out|std::fstream::app);
					despesa1 << Nome_Novo_Categoria << "\n";
					despesa1.close();
			
					std::fstream despesa2;
					despesa2.open(Formacao_Nome_Nova_Categoria,std::fstream::out|std::fstream::app);
			
					if(despesa2.is_open()){
						
						std::fstream despesa3;
						despesa3.open(Formacao_Nome_Conf_Categoria,std::fstream::out|std::fstream::app);
						
						
						if(despesa3.is_open()){
							
							despesa3 << "Valor TOTAL:" << "\n";
							despesa3 << "0" << "\n";
							despesa3 << "\n";
							despesa3 << "LIMITE:" << "\n";
							despesa3 << Limite_Meta_Categoria << "\n";
							despesa3 << "\n";
							despesa3 << "Ultimo Cadastro:" << "\n";
							despesa3 << "0" << "\n";
							
							despesa3.close();
							
							std::cout << std::endl;
							std::cout << "Categoria Criada com Suscesso" << std::endl;
							despesa2.close();
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
						
						else{
							
							std::cout << "Nao foi possivel Criar a Categoria" << std::endl;	
							despesa2.close();
							despesa3.close();
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
					}
			
					else{
						
						std::cout << "Nao foi possivel Criar a Categoria" << std::endl;	
						despesa2.close();
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
	}
	
	else{
		
		std::cout << std::endl;
		std::cout << "Opcao Invalida" << std::endl;
		std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(3));
		system("cls");	
	}			
}