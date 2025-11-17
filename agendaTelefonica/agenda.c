#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#define MAX 6

int dado[MAX], dados[MAX], qtd=0, i=0, a;


void incluir(void){
	
	if (qtd==MAX){
		printf("A lista está cheia");
	}
	else
	{
		
	}
	char nome[20];
	int telefone;

	printf("Digite nome: ");
	scanf("%19s", nome);   // evita estouro de buffer
	
	printf("Digite telefone: ");
	scanf("%d", &telefone);
	
	printf("\nNome cadastrado: %s", nome);
	printf("\nTelefone cadastrado: %d\n", telefone);
}

void sair(){
	system("cls");
	printf("\nVocê saiu\n");
}

int menu(void){
	system("cls");
	
	printf("Agenda telefônica\n\n");
	printf("1- Incluir dados\n");
	printf("2- Listar dados\n");
	printf("3- Ordenar dados\n");
	printf("4- Busca sequencial\n");
	printf("5- Busca binária\n");
	printf("6- Sair\n\n");
	
	printf("Escolha uma das opções: ");
	scanf("%d", &a);
	system("cls");
	switch(a)
	{
		case 1:
			incluir();
		break;
		
		case 2:
			// listar();
		break;
		
		case 3:
			// ordenar();
		break;
		
		case 4:
			// buscarSeq();
		break;
		
		case 5:
			// buscarBin();
		break;
		
		case 6:
			sair();
		break;
	}
	return 0;
}

int main(){
	setlocale(LC_ALL,"portuguese");
	
	while(a!=6)
	{
		menu();
		system("pause");	
	}
	return 2;
}
