#include <iostream>
#include <string>
#include <cstdlib>
#include <math.h>


int Menu_Principal(){

	int principal = 0;
	
	std::cout << "========================== Menu Principal ==========================" << std::endl;
	std::cout << std::endl;
	std::cout << "1 -> Opcoes de Categoria" << std::endl;
	std::cout << "2 -> Opcoes de Transacao" << std::endl;
	std::cout << "3 -> Mais Opcoes..." << std::endl;
	std::cout << "4 -> Sair" << std::endl;
	std::cout << std::endl;
	std::cout << "====================================================================" << std::endl;
	std::cout << "Digite uma opcao: ";
	std::cin >> principal;
	std::cout << std::endl;
	
	return principal;
}


int Menu_Secundario(){

	int secundario = 0;
	
	std::cout << "========================== Menu Secundario ==========================" << std::endl;
	std::cout << "                          Receita / Despesas                         " << std::endl;
	std::cout << std::endl;
	std::cout << "1 -> Historico por Categoria" << std::endl;
	std::cout << "2 -> Historico TOTAL" << std::endl;
	std::cout << "3 -> Valor por Categoria" << std::endl;
	std::cout << "4 -> Valor TOTAl" << std::endl;
	std::cout << "5 -> Relatorios" << std::endl;
	std::cout << "6 -> Metas" << std::endl;
	std::cout << "7 -> Limites" << std::endl;
	std::cout << "8 -> Sair" << std::endl;
	std::cout << std::endl;
	std::cout << "=====================================================================" << std::endl;
	std::cout << "Digite uma opcao: ";
	std::cin >> secundario;
	std::cout << std::endl;
	
	return secundario;
}


int Menu_Transacao(){
	
	int transacao = 0;
	
	std::cout << "========================== Menu Transacao ==========================" << std::endl;
	std::cout << "                         Receita / Despesas                         " << std::endl;
	std::cout << std::endl;
	std::cout << "1 -> Cadastrar uma Transacao" << std::endl;
	std::cout << "2 -> Alterar uma Transacao" << std::endl;
	std::cout << "3 -> Excluir uma Transacao" << std::endl;
	std::cout << "4 -> Sair" << std::endl;
	std::cout << std::endl;
	std::cout << "====================================================================" << std::endl;
	std::cout << "Digite uma opcao: ";
	std::cin >> transacao;
	std::cout << std::endl;
	
	return transacao;
}


int Menu_Categoria(){
	
	int categoria = 0;
	
	std::cout << "========================== Menu Categoria ==========================" << std::endl;
	std::cout << "                         Receita / Despesas                         " << std::endl;
	std::cout << std::endl;
	std::cout << "1 -> Cadastrar uma Categoria" << std::endl;
	std::cout << "2 -> Alterar uma Categoria" << std::endl;
	std::cout << "3 -> Excluir uma Categoria" << std::endl;
	std::cout << "4 -> Sair" << std::endl;
	std::cout << std::endl;
	std::cout << "====================================================================" << std::endl;
	std::cout << "Digite uma opcao: ";
	std::cin >> categoria;
	std::cout << std::endl;
	
	return categoria;
}
