#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <math.h>
#include <clocale>
#include <fstream>
#include <thread>
#include <chrono>

#include "Menu_Layouts.h"
#include "Criacao_Categoria.h"
#include "Alteracao_Categoria.h"
#include "Exclusao_Categoria.h"
#include "Criacao_Transacao.h"
#include "Alteracao_Transacao.h"
#include "Historico_Categoria.h"
#include "Historico_Total.h"
#include "Valor_Categoria.h"
#include "Valor_Total.h"
#include "Meta.h"
#include "Limite.h"
#include "Exclusao_Transacao.h"
#include "Relatorio.h"





int main(){
	
//=============================================================================================//

	//Aurora Coelho - 841942
	//David Camara - 841925
	//Gabriel Barbosa dos Santos - 841923
	//Matheus Abilio da Silva Camargo - 841929
	//Rodrigo de Araujo Amaro - 841935

//=============================================================================================//
	
	/*int opc_menu_principal = Menu_Principal(); //Chamar o Menu e Guardar o seu Retorno
	int opc_menu_secundario = Menu_Secundario(); //Chamar o Menu e Guardar o seu Retorno
	int opc_menu_transacao = Menu_Transacao(); //Chamar o Menu e Guardar o seu Retorno
	int opc_menu_categoria = Menu_Categoria(); //Chamar o Menu e Guardar o seu Retorno
	
	std::cout << opc_menu_principal << std::endl;
	std::cout << opc_menu_secundario << std::endl;
	std::cout << opc_menu_transacao << std::endl;
	std::cout << opc_menu_categoria << std::endl;*/
	
	
	while(true){
	
		int opc_menu_principal = Menu_Principal();
	
		if(opc_menu_principal==1){
			
			system("cls");
			
			int opc_menu_categoria = Menu_Categoria();
			
			if(opc_menu_categoria==1){
				Criacao_Categoria();	
			}
			
			else if(opc_menu_categoria==2){
				Alteracao_Categoria();
			}
			
			else if(opc_menu_categoria==3){
				Exclusao_Categoria();	
			}
			
			else if(opc_menu_categoria==4){
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
		
		else if(opc_menu_principal==2){
			
			system("cls");
			
			int opc_menu_transacao = Menu_Transacao();
			
			if(opc_menu_transacao==1){
				Criacao_Transacao();	
			}
			
			else if(opc_menu_transacao==2){
				Alteracao_Transacao();	
			}
			
			else if(opc_menu_transacao==3){
				Exclusao_Transacao();
			}
			
			else if(opc_menu_transacao==4){
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
		
		else if(opc_menu_principal==3){
			
			system("cls");
			
			int opc_menu_secundario = Menu_Secundario();
			
			if(opc_menu_secundario==1){
				Historico_Categoria();		
			}
			
			else if(opc_menu_secundario==2){
				Historico_Total();
			}
			
			else if(opc_menu_secundario==3){
				Valor_Categoria();
			}
			
			else if(opc_menu_secundario==4){
				Valor_Total();
			}
			
			else if(opc_menu_secundario==5){
				Relatorio();
			}
			
			else if(opc_menu_secundario==6){
				Meta();
			}
			
			else if(opc_menu_secundario==7){
				Limite();
			}
			
			else if(opc_menu_secundario==8){
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
		
		else if(opc_menu_principal==4){
		
			return 0;
		}
		
		else{
			
			system("cls");
			std::cout << "ERRO" << std::endl;
			//return 0;
			
			while(true){
				//return 0;	
			}
		}
	}		
}