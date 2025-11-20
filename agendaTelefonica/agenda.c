#include <stdio.h>
#include <locale.h>
#include <stdlib.h>
#include <string.h>     // para strcmp e strcpy
#define MAX 6

char nomes[MAX][20];     // nomes da agenda
int telefones[MAX];      // telefones da agenda

int qtd = 0;             // quantidade cadastrada
int a;                   // opção do menu

// --------------------------------------------------------
// INCLUIR DADOS
// --------------------------------------------------------
void incluir(void){
	
	if (qtd == MAX){
		printf("A lista está cheia!\n");
		return;
	}

	printf("Digite nome: ");
	scanf("%19s", nomes[qtd]);       // salva o nome na posição qtd

	printf("Digite telefone: ");
	scanf("%d", &telefones[qtd]);    // salva telefone na mesma posição

	printf("\nNome cadastrado: %s", nomes[qtd]);
	printf("\nTelefone cadastrado: %d\n", telefones[qtd]);

	qtd++;  // aumenta quantidade de elementos
}

// --------------------------------------------------------
// LISTAR DADOS
// --------------------------------------------------------
void listar(){
	if (qtd == 0){
		printf("Nenhum dado cadastrado!\n");
		return;
	}

	printf("LISTA DE CONTATOS:\n");
	for (int i = 0; i < qtd; i++){
		printf("%d - Nome: %s | Telefone: %d\n",
			   i+1, nomes[i], telefones[i]);
	}
}

// --------------------------------------------------------
// ORDENAR (alfabético por nome)
// --------------------------------------------------------
void ordenar(){
	char auxNome[20];
	int auxTel;

	if (qtd <= 1){
		printf("Poucos dados para ordenar!\n");
		return;
	}

	for (int i = 0; i < qtd - 1; i++){
		for (int j = i + 1; j < qtd; j++){
			if (strcmp(nomes[i], nomes[j]) > 0){

				// troca nomes
				strcpy(auxNome, nomes[i]);
				strcpy(nomes[i], nomes[j]);
				strcpy(nomes[j], auxNome);

				// troca telefones
				auxTel = telefones[i];
				telefones[i] = telefones[j];
				telefones[j] = auxTel;
			}
		}
	}

	printf("Dados ordenados!\n");
}

// --------------------------------------------------------
// BUSCA SEQUENCIAL
// --------------------------------------------------------
void buscarSeq(){
	char nomeBusca[20];

	if (qtd == 0){
		printf("Agenda vazia!\n");
		return;
	}

	printf("Digite o nome que deseja buscar: ");
	scanf("%19s", nomeBusca);

	for (int i = 0; i < qtd; i++){
		if (strcmp(nomeBusca, nomes[i]) == 0){
			printf("\nEncontrado!\n");
			printf("Nome: %s | Telefone: %d\n",
				   nomes[i], telefones[i]);
			return;
		}
	}

	printf("Contato não encontrado!\n");
}

// --------------------------------------------------------
// BUSCA BINÁRIA (lista precisa estar ordenada!)
// --------------------------------------------------------
void buscarBin(){
	char nomeBusca[20];
	int inicio = 0, fim = qtd - 1, meio, cmp;

	if (qtd == 0){
		printf("Agenda vazia!\n");
		return;
	}

	printf("Digite o nome que deseja buscar: ");
	scanf("%19s", nomeBusca);

	while (inicio <= fim){
		meio = (inicio + fim) / 2;
		cmp = strcmp(nomeBusca, nomes[meio]);

		if (cmp == 0){
			printf("\nEncontrado!\n");
			printf("Nome: %s | Telefone: %d\n",
				   nomes[meio], telefones[meio]);
			return;
		}
		else if (cmp < 0){
			fim = meio - 1;
		}
		else {
			inicio = meio + 1;
		}
	}

	printf("Contato não encontrado!\n");
}

// --------------------------------------------------------
// SAIR
// --------------------------------------------------------
void sair(){
	printf("\nVocê saiu\n");
}

// --------------------------------------------------------
// MENU
// --------------------------------------------------------
int menu(void){
	
	printf("Agenda telefônica\n\n");
	printf("1- Incluir dados\n");
	printf("2- Listar dados\n");
	printf("3- Ordenar dados\n");
	printf("4- Busca sequencial\n");
	printf("5- Busca binária\n");
	printf("6- Sair\n\n");
	
	printf("Escolha uma das opções: ");
	scanf("%d", &a);
	system("cls || clear");

	switch(a){
		case 1: incluir(); break;
		case 2: listar(); break;
		case 3: ordenar(); break;
		case 4: buscarSeq(); break;
		case 5: buscarBin(); break;
		case 6: sair(); break;
		default: printf("Opção inválida!\n");
	}
	return 0;
}

// --------------------------------------------------------
// MAIN
// --------------------------------------------------------
int main(){
	setlocale(LC_ALL,"portuguese");
	
	while(a != 6){
		menu();
		system("pause");
		system("cls || clear");
	}
	return 0;
}
