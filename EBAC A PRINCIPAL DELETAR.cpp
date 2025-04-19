#include <stdio.h> //biblioteca de comunicação com o usuário
#include <stdlib.h> //biblioteca de alocação de espaço em memória
#include <locale.h> //biblioteca de alocações de texto por região
#include <string.h> //biblioteca responsável por cuidar das string

int registro() //Função responsável para cadastrar os usuários nbo sisterma
{
	//inicio criação de variáveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo[40];
	//final da criação das variáveis
	
	printf("Digite o CPF a ser cadastrado: "); //coletando informação do usuário
	scanf("%s", cpf); //%s refere-se a string
	
	strcpy(arquivo, cpf); //Responsável por copiar os valores das string
	
	FILE *file; //cria  arquivo
	file = fopen(arquivo, "w"); //cria o arquivo e o "w' significa escrever
	fprintf(file,cpf); //salvo o valor da variável
	fclose(file); //fecha o arquivo
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o nome a ser cadastrado: ");
	scanf("%s",nome);
	
	file = fopen(arquivo, "a");
	fprintf(file,nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o sobrenome a ser cadastrado: ");
	scanf("%s",sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);

	file = fopen(arquivo, "a");
	fprintf(file,",");
	fclose(file);
	
	printf("Digite o cargo a ser cadastrado: ");
	scanf("%s",cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file,cargo);
	fclose(file);
	
	system("pause");
}

int consulta()
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[200];
	
	printf("Digite o CPF a ser contultado: "); //QUAL O USUÁRIO SERÁ CONSULTADO
	scanf("%s",cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("Não foi possível abrir o arquivo, não localizado!.\n");
		
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		printf("\nEssas são as informações do usuário: ");
		printf("%s", conteudo);
		printf("\n\n");		
	}
	
	system("pause");
}

int deletar()
{
	char cpf[40];
	
	printf("Digite o CPF DO USUÁRIO A SER DELETADO: ");
	scanf("%s",cpf);
	
	remove(cpf);
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("O usuário não se encontra no sistema!.\n");
		fclose(file);
		system("pause");
		
	}
}
	
	
	
	
	
	
int main()
	{
	int opcao=0; //definindo variáveis
	int x=1;
	char senhadigitada[10]="a";
	int comparacao; 
	
	setlocale(LC_ALL,"portuguese");//Definindo linguagem
	
	printf("\t\t\t\t\t### CARTÓRIO DA EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s",senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)
	{
	
		system ("cls"); //responsável por limpar a tela
		for(x=1;x=1;)
		{
		system("cls");
		
			setlocale(LC_ALL, "Portuguese"); //definindo linguagem
	
			printf("### CARTÓRIO DA EBAC ###\n\n");
			printf("Escolha a opção desejada do menu\n\n");
			printf("\t1 - Registrar nomes\n\n");
			printf("\t2 - Consultar nomes\n\n");
			printf("\t3 - Deletar nomes\n\n");
			printf("\t4 - Sair do sistema\n\n");
			printf("Opção: "); //fim do menu

			scanf("%d", &opcao); //armazenando a escolha do usuário
	
			system("cls"); //responsável por limpar a tela
	
			switch(opcao) //inicio da seleção do menu
			{
				case 1:
				registro(); //chamada de funções
				break;
			
				case 2:
				consulta();
				break;
			
				case 3:
				deletar();
				break;
			
				case 4:
				printf("Obrigado por utilizar o sistema!\n");
				return 0;
				break;
			
				default:
				printf("Essa opção não está disponível!\n");
				system("pause");
				break;
			}
		}
	}
	
	{	
		printf("\nSenha Incorreta!\n\n");
		system("pause");
		system("cls");
		main();
	}

}
