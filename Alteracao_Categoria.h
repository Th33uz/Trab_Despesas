#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <fstream>
#include <cstdio>
#include <thread>
#include <chrono>


void Alteracao_Categoria(){
		
//==========================================================================================================//

	int identificador = 0;
	int opcao = 0;
	int contador = 0;
	int escolha = 0;
	
	std::string Nome_Categoria_Para_Alterar = "A";
	std::string Checar_Categoria_Existentes = "A";
	std::string Novo_Nome_Categoria = "A";
	std::string Nome_Novo_Formatado = "A";
	std::string Nome_Velho_Formatado = "A";
	std::string Antigo_Nome_Segundo_Arquivo_Formatado = "A";
	std::string Novo_Nome_Segundo_Arquivo_Formatado = "A";	
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
	
	if(identificador==1 || identificador==2){
		
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Escolha o Modo para Alteracao:" << std::endl;
		std::cout << "1 -> Pesquisar Nome" << std::endl;
		std::cout << "2 -> Mostrar Arquivos Disponiveis" << std::endl;
		std::cout << "---------------------------------------------" << std::endl;
		std::cout << "Opcao: ";
		std::cin >> opcao;
		
		if(identificador==1){
			
			if(opcao==1){
				
				std::cout << std::endl;
				std::cout << "Digite o nome da Categoria que Deseja Alterar: ";
				std::cin >> Nome_Categoria_Para_Alterar;
				
				std::fstream receita1;
				receita1.open("Categorias_Receita.txt",std::fstream::in|std::fstream::app);
				
				while(getline(receita1, Checar_Categoria_Existentes)){
					
					if(Checar_Categoria_Existentes == Nome_Categoria_Para_Alterar){
				
						contador++;	
					}
					
					else{
						
						Armazenar.push_back(Checar_Categoria_Existentes);
					}	
				}
				
				receita1.close();
				
				if(contador==0){
					
					std::cout << std::endl;
					std::cout << "Categoria nao Encontrada, Digite um Nome VALIDO" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
				
				else{
					
					std::cout << std::endl;
					std::cout << "Digite um NOVO nome da Categoria que Deseja Alterar: ";
					std::cin >> Novo_Nome_Categoria;
					
					
					Nome_Novo_Formatado = Novo_Nome_Categoria + Formato_Arquivo;
					Nome_Velho_Formatado = Nome_Categoria_Para_Alterar + Formato_Arquivo;
					Antigo_Nome_Segundo_Arquivo_Formatado = Nome_Categoria_Para_Alterar + Formato_Segundo_Arquivo + Formato_Arquivo;
					Novo_Nome_Segundo_Arquivo_Formatado = Novo_Nome_Categoria + Formato_Segundo_Arquivo + Formato_Arquivo;
					
					
					if (rename(Nome_Velho_Formatado.c_str(), Nome_Novo_Formatado.c_str()) == 0){
						
						Armazenar.push_back(Novo_Nome_Categoria);
						
						std::fstream receita1;
						receita1.open("Categorias_Receita.txt",std::fstream::out);
						
						for (const auto& Armazem : Armazenar){
						
        					receita1 << Armazem << "\n";
    					}
						
						receita1.close();
						
						if(rename(Antigo_Nome_Segundo_Arquivo_Formatado.c_str(), Novo_Nome_Segundo_Arquivo_Formatado.c_str()) == 0){
							
							std::cout << std::endl;
							std::cout << "Categoria Renomeada com Sucesso" << std::endl;
		        			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
						
						else{
							
							std::cout << std::endl;
							std::cout << "Erro ao Renomear a Categoria" << std::endl;
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");	
						}
	    			} 		
				
					else{
						
						std::cout << std::endl;
						std::cout << "Erro ao Renomear a Categoria" << std::endl;
						std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");
	    			}
				}
			}
		
			else if(opcao==2){
				
				system("cls");
				
				std::cout << std::endl;
				std::cout << "Categorias de RECEITA" << std::endl;
				std::cout << "=======================" << std::endl;
				std::cout << std::endl;
				
				std::fstream receita1;
				receita1.open("Categorias_Receita.txt",std::fstream::in|std::fstream::app);
				
				while(getline(receita1, Checar_Categoria_Existentes)){
					
					contador++;	
					std::cout << contador << " -> " << Checar_Categoria_Existentes << std::endl;
					Armazenar.push_back(Checar_Categoria_Existentes);
				}
				
				receita1.close();
				
				std::cout << std::endl;
				std::cout << "=====================" << std::endl;
				std::cout << std::endl;
				std::cout << "Escolha a Categoria que Deseja Alterar: ";
				std::cin >> escolha;
				
				if(escolha > contador || escolha <= 0){
					
					std::cout << std::endl;
					std::cout << "Opcao Invalida" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");	
				}
				
				else{
					
					std::cout << std::endl;
					std::cout << "Digite um NOVO nome da Categoria que Deseja Alterar: ";
					std::cin >> Novo_Nome_Categoria;
					
					Nome_Novo_Formatado = Novo_Nome_Categoria + Formato_Arquivo;
					Nome_Velho_Formatado = Armazenar[escolha - 1] + Formato_Arquivo;
					Antigo_Nome_Segundo_Arquivo_Formatado = Armazenar[escolha - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
					Novo_Nome_Segundo_Arquivo_Formatado = Novo_Nome_Categoria + Formato_Segundo_Arquivo + Formato_Arquivo;
					
					
					if (rename(Nome_Velho_Formatado.c_str(), Nome_Novo_Formatado.c_str()) == 0){
						
						Armazenar.push_back(Novo_Nome_Categoria);
						
						std::fstream receita1;
						receita1.open("Categorias_Receita.txt",std::fstream::out);
						
						for (const auto& Armazem : Armazenar){
						
							if(Armazem == Armazenar[escolha - 1]){
							}
						
							else{
							
								receita1 << Armazem << "\n";
							}
    					}
						
						receita1.close();
						
						if(rename(Antigo_Nome_Segundo_Arquivo_Formatado.c_str(), Novo_Nome_Segundo_Arquivo_Formatado.c_str()) == 0){
							
							std::cout << std::endl;
							std::cout << "Categoria Renomeada com Sucesso" << std::endl;
		        			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
						
						else{
							
							std::cout << std::endl;
							std::cout << "Erro ao Renomear a Categoria" << std::endl;
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");	
						}
					}
					
					else{
						
						std::cout << std::endl;
						std::cout << "Erro ao Renomear a Categoria" << std::endl;
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
			
			if(opcao==1){
				
				std::cout << std::endl;
				std::cout << "Digite o nome da Categoria que Deseja Alterar: ";
				std::cin >> Nome_Categoria_Para_Alterar;
				
				std::fstream despesa1;
				despesa1.open("Categorias_Despesa.txt",std::fstream::in|std::fstream::app);
				
				while(getline(despesa1, Checar_Categoria_Existentes)){
					
					if(Checar_Categoria_Existentes == Nome_Categoria_Para_Alterar){
				
						contador++;	
					}
					
					else{
						
						Armazenar.push_back(Checar_Categoria_Existentes);
					}	
				}
				
				despesa1.close();
				
				if(contador==0){
					
					std::cout << std::endl;
					std::cout << "Categoria nao Encontrada, Digite um Nome VALIDO" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");
				}
				
				else{
					
					std::cout << std::endl;
					std::cout << "Digite um NOVO nome da Categoria que Deseja Alterar: ";
					std::cin >> Novo_Nome_Categoria;
					
					
					Nome_Novo_Formatado = Novo_Nome_Categoria + Formato_Arquivo;
					Nome_Velho_Formatado = Nome_Categoria_Para_Alterar + Formato_Arquivo;
					Antigo_Nome_Segundo_Arquivo_Formatado = Nome_Categoria_Para_Alterar + Formato_Segundo_Arquivo + Formato_Arquivo;
					Novo_Nome_Segundo_Arquivo_Formatado = Novo_Nome_Categoria + Formato_Segundo_Arquivo + Formato_Arquivo;
					
					
					if (rename(Nome_Velho_Formatado.c_str(), Nome_Novo_Formatado.c_str()) == 0){
						
						Armazenar.push_back(Novo_Nome_Categoria);
						
						std::fstream despesa1;
						despesa1.open("Categorias_Despesa.txt",std::fstream::out);
						
						for (const auto& Armazem : Armazenar){
						
        					despesa1 << Armazem << "\n";
    					}
						
						despesa1.close();
						
						if(rename(Antigo_Nome_Segundo_Arquivo_Formatado.c_str(), Novo_Nome_Segundo_Arquivo_Formatado.c_str()) == 0){
							
							std::cout << std::endl;
							std::cout << "Categoria Renomeada com Sucesso" << std::endl;
		        			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
						
						else{
							
							std::cout << std::endl;
							std::cout << "Erro ao Renomear a Categoria" << std::endl;
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");	
						}
	    			} 		
				
					else{
						
						std::cout << std::endl;
						std::cout << "Erro ao Renomear a Categoria" << std::endl;
						std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
						std::this_thread::sleep_for(std::chrono::seconds(3));
						system("cls");
	    			}
				}
			}
		
			else if(opcao==2){
				
				system("cls");
				
				std::cout << std::endl;
				std::cout << "Categorias de DESPESA" << std::endl;
				std::cout << "=======================" << std::endl;
				std::cout << std::endl;
				
				std::fstream despesa1;
				despesa1.open("Categorias_Despesa.txt",std::fstream::in|std::fstream::app);
				
				while(getline(despesa1, Checar_Categoria_Existentes)){
					
					contador++;	
					std::cout << contador << " -> " << Checar_Categoria_Existentes << std::endl;
					Armazenar.push_back(Checar_Categoria_Existentes);
				}
				
				despesa1.close();
				
				std::cout << std::endl;
				std::cout << "=====================" << std::endl;
				std::cout << std::endl;
				std::cout << "Escolha a Categoria que Deseja Alterar: ";
				std::cin >> escolha;
				
				if(escolha > contador || escolha <= 0){
					
					std::cout << std::endl;
					std::cout << "Opcao Invalida" << std::endl;
					std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
					std::this_thread::sleep_for(std::chrono::seconds(3));
					system("cls");	
				}
				
				else{
					
					std::cout << std::endl;
					std::cout << "Digite um NOVO nome da Categoria que Deseja Alterar: ";
					std::cin >> Novo_Nome_Categoria;
					
					Nome_Novo_Formatado = Novo_Nome_Categoria + Formato_Arquivo;
					Nome_Velho_Formatado = Armazenar[escolha - 1] + Formato_Arquivo;
					Antigo_Nome_Segundo_Arquivo_Formatado = Armazenar[escolha - 1] + Formato_Segundo_Arquivo + Formato_Arquivo;
					Novo_Nome_Segundo_Arquivo_Formatado = Novo_Nome_Categoria + Formato_Segundo_Arquivo + Formato_Arquivo;
					
					
					if (rename(Nome_Velho_Formatado.c_str(), Nome_Novo_Formatado.c_str()) == 0){
						
						Armazenar.push_back(Novo_Nome_Categoria);
						
						std::fstream despesa1;
						despesa1.open("Categorias_Despesa.txt",std::fstream::out);
						
						for (const auto& Armazem : Armazenar){
						
							if(Armazem == Armazenar[escolha - 1]){
							}
						
							else{
							
								despesa1 << Armazem << "\n";
							}
    					}
						
						despesa1.close();
						
						if(rename(Antigo_Nome_Segundo_Arquivo_Formatado.c_str(), Novo_Nome_Segundo_Arquivo_Formatado.c_str()) == 0){
							
							std::cout << std::endl;
							std::cout << "Categoria Renomeada com Sucesso" << std::endl;
		        			std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");
						}
						
						else{
							
							std::cout << std::endl;
							std::cout << "Erro ao Renomear a Categoria" << std::endl;
							std::cout << "Voltando para o MENU PRINCIPAL................." << std::endl;
							std::this_thread::sleep_for(std::chrono::seconds(3));
							system("cls");	
						}
					}
					
					else{
						
						std::cout << std::endl;
						std::cout << "Erro ao Renomear a Categoria" << std::endl;
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