#include <stdio.h> // biblioteca de comunica��o com o usu�rio 
#include <stdlib.h> // biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h> // biblioteca de aloca��es de texto por regi�o
#include <string.h> // biblioteca respons�vel por cuidar das string

int registro() //fun��o respons�vel por cadastrar os usu�rios no sistema
{
	//inicio da cria��o de vari�veis/strig
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da cria��o de vari�veis/strig
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infrma��es do usu�rio
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Respons�vel por copiar os valores das strig
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o"w" siginifica "escrever"
	fprintf(file, cpf); //salvo valor da variavel 
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conte�do
	fprintf(file, ","); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	getchar(); // Limpa o caractere de nova linha pendente no buffer
	fgets(nome, sizeof(nome), stdin); // L� uma linha inteira, incluindo espa�os em branco
	nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha do final do nome
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conte�do
	fprintf(file, nome ); //adiciona o nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conte�do
	fprintf(file, ","); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(sobrenome, sizeof(sobrenome), stdin); // L� uma linha inteira, incluindo espa�os em branco
	sobrenome[strcspn(sobrenome, "\n")] = '\0'; // Remove a nova linha do final do sobrenome
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conte�do
	fprintf(file, sobrenome); //adiciona o sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conte�do
	fprintf(file, ","); //adiciona uma v�rgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //l� o cargo
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conte�do
	fprintf(file, cargo); //adiciona o cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a execu��o do programa
	
}
 
int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //defindo a linguagem
	
	char cpf[40]; //vari�vel para armazenar o CPF digitado
	char conteudo[200]; //vari�vel para armazenar o conte�do lido do arquivo
	
	printf("Digite o CPF a ser consultado: "); //solicita��o do CPF
	scanf("%s",cpf); //l� o CPF
	
	FILE *file; //cria um ponteiro para arquivo
	file = fopen(cpf,"r"); //abre o arquivo para leitura
	
	if(file == NULL) //verifica se o arquivo foi aberto corretamente
	{
		printf("N�o foi poss�vel abrir o arquivo, n�o localizado!.\n"); //mensagem de erro
		system("pause"); //pausa a execu��o do programa
		return; //retorna da fun��o
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) //l� as linhas do arquivo enquanto houver conte�do
	{
		printf("\nEssas s�o as informa��es do usu�rio: \n"); //mensagem de cabe�alho
		printf("%s", conteudo); //imprime o conte�do lido
		printf("\n\n"); //linha em branco
	}
	
	fclose(file); //fecha o arquivo
	system("pause"); //pausa a execu��o do programa
}

int deletar()
{
		char cpf[40]; //vari�vel para armazenar o CPF a ser deletado
	
	printf("Digite o CPF a ser deletado:  "); //solicita��o do CPF a ser deletado
	scanf("%s",cpf); //l� o CPF
	
	remove(cpf); //remove o arquivo com o nome correspondente ao CPF
	
	FILE *file; //cria um ponteiro para arquivo
	file = fopen(cpf, "r"); //abre o arquivo para leitura
	
	if(file == NULL) //verifica se o arquivo foi removido corretamente
	{
		printf("CADASTRO DELETADO COM SUCESSO!. \n");
		system("pause");		
	}
}

int main()
{
	int opcao = 0; //definindo vari�veis 
 	int laco = 1; //definindo vari�veis
 	
	for(laco = 1; laco == 1;) //la�o infinito
 	{
	 
	 system("cls"); // respons�vel por limpar a tela 
	 
	
    setlocale(LC_ALL, "Portuguese"); //defindo a linguagem
	
	//in�cio do menu
	printf("\t\t### Cart�rio da EBAC ###\n\n"); 
	printf("\tEscolha a op��o desejada do menu: \n\n");
	printf("\t1 - Registrar nomes \n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n\n\n"); 
	printf("Op��o: "); 
	//fim do menu
	  
	scanf("%d", &opcao); //armazenando a escolha do usu�rio
	
	system("cls"); //limpa a tela do console
	
	switch(opcao) //in�cio da sele��o do menu
		{
			case 1:
			registro(); //chamada da fun��o registro
			break;
		
			case 2:
			consultar(); //chamada da fun��o consultar
			break;
		
			case 3:
			deletar(); //chamada da fun��o deletar
			break;
			
			default:
			printf("Essa op��o n�o est� dispon�vel!\n"); //mensagem de op��o inv�lida
			system("pause"); //pausa a execu��o do programa
			break;	
		} //fim da sele��o
    }
}
