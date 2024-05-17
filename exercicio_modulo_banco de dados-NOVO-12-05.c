#include <stdio.h> // biblioteca de comunicação com o usuário 
#include <stdlib.h> // biblioteca de alocação de espaço em memória
#include <locale.h> // biblioteca de alocações de texto por região
#include <string.h> // biblioteca responsável por cuidar das string

int registro() //função responsável por cadastrar os usuários no sistema
{
	//inicio da criação de variáveis/strig
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação de variáveis/strig
	
	printf("Digite o CPF a ser cadastrado: "); //coletando infrmações do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das strig
	
	FILE *file; // cria o arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o"w" siginifica "escrever"
	fprintf(file, cpf); //salvo valor da variavel 
	fclose(file); //fecha arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conteúdo
	fprintf(file, ","); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o nome a ser cadastrado: ");
	getchar(); // Limpa o caractere de nova linha pendente no buffer
	fgets(nome, sizeof(nome), stdin); // Lê uma linha inteira, incluindo espaços em branco
	nome[strcspn(nome, "\n")] = '\0'; // Remove a nova linha do final do nome
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conteúdo
	fprintf(file, nome ); //adiciona o nome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conteúdo
	fprintf(file, ","); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado: ");
	fgets(sobrenome, sizeof(sobrenome), stdin); // Lê uma linha inteira, incluindo espaços em branco
	sobrenome[strcspn(sobrenome, "\n")] = '\0'; // Remove a nova linha do final do sobrenome
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conteúdo
	fprintf(file, sobrenome); //adiciona o sobrenome
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conteúdo
	fprintf(file, ","); //adiciona uma vírgula
	fclose(file); //fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo); //lê o cargo
	file = fopen(arquivo, "a"); //abre o arquivo para adicionar conteúdo
	fprintf(file, cargo); //adiciona o cargo
	fclose(file); //fecha o arquivo
	
	system("pause"); //pausa a execução do programa
	
}
 
int consultar()
{
	setlocale(LC_ALL, "Portuguese"); //defindo a linguagem
	
	char cpf[40]; //variável para armazenar o CPF digitado
	char conteudo[200]; //variável para armazenar o conteúdo lido do arquivo
	
	printf("Digite o CPF a ser consultado: "); //solicitação do CPF
	scanf("%s",cpf); //lê o CPF
	
	FILE *file; //cria um ponteiro para arquivo
	file = fopen(cpf,"r"); //abre o arquivo para leitura
	
	if(file == NULL) //verifica se o arquivo foi aberto corretamente
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n"); //mensagem de erro
		system("pause"); //pausa a execução do programa
		return; //retorna da função
		
	}
	
	while(fgets(conteudo, 200, file) != NULL) //lê as linhas do arquivo enquanto houver conteúdo
	{
		printf("\nEssas são as informações do usuário: \n"); //mensagem de cabeçalho
		printf("%s", conteudo); //imprime o conteúdo lido
		printf("\n\n"); //linha em branco
	}
	
	fclose(file); //fecha o arquivo
	system("pause"); //pausa a execução do programa
}

int deletar()
{
		char cpf[40]; //variável para armazenar o CPF a ser deletado
	
	printf("Digite o CPF a ser deletado:  "); //solicitação do CPF a ser deletado
	scanf("%s",cpf); //lê o CPF
	
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
	int opcao = 0; //definindo variáveis 
 	int laco = 1; //definindo variáveis
 	
	for(laco = 1; laco == 1;) //laço infinito
 	{
	 
	 system("cls"); // responsável por limpar a tela 
	 
	
    setlocale(LC_ALL, "Portuguese"); //defindo a linguagem
	
	//início do menu
	printf("\t\t### Cartório da EBAC ###\n\n"); 
	printf("\tEscolha a opção desejada do menu: \n\n");
	printf("\t1 - Registrar nomes \n");
	printf("\t2 - Consultar nomes \n");
	printf("\t3 - Deletar nomes \n\n\n"); 
	printf("Opção: "); 
	//fim do menu
	  
	scanf("%d", &opcao); //armazenando a escolha do usuário
	
	system("cls"); //limpa a tela do console
	
	switch(opcao) //início da seleção do menu
		{
			case 1:
			registro(); //chamada da função registro
			break;
		
			case 2:
			consultar(); //chamada da função consultar
			break;
		
			case 3:
			deletar(); //chamada da função deletar
			break;
			
			default:
			printf("Essa opção não está disponível!\n"); //mensagem de opção inválida
			system("pause"); //pausa a execução do programa
			break;	
		} //fim da seleção
    }
}
