#include <stdio.h> //biblioteca de comunicação com o usuario
#include <stdlib.h> //biblioteca de alocação de espaço em memoria 
#include <locale.h> //biblioteca de alocações de texto por região 
#include <string.h> //biblioteca responsavel por cuidar da string 

int registro()//Função responsavel por cadastrar os usuarios no sistema

{
	//inicio criação de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da criação das variaveis 
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informação do usuario
	scanf("%s", cpf); //%s refere-se a string    
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo

    file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String 
	fprintf(file,","); // salvo o valor da variavel
	fclose (file);  // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado"); //Coletando informação do usuario
	scanf("%s",nome); //string, informção do usuario
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file); 	// fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado"); //Coletando informação do usuario
	scanf("%s",sobrenome); //string, informação do usuario 
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String
	fprintf(file, sobrenome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado"); //Coletando informação do usuario
	scanf("%s", cargo); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String
	fprintf(file, cargo); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause");


}   

int consulta()
{
	//inicio da criação das  variaveis
	char cpf[40];
	char conteudo[200];
	//fim da criação das variaveis
	
	printf("Digite o CPF a ser consultado:"); //inserindo a informação do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo 
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa que esta lendo os dados coletados  
		
	if(file == NULL) // Nulo
    {
    	printf("Não foi possivel abrir o arquivo, não localizado!.\n"); //Quando um dado não é encontrado, aparece essa opção na tela
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		 printf("\nEssas são as informações do usuário: "); // Quando o dado é inserido corretamente
		 printf("%s", conteudo); //refere-se a string dos dados inseridos 
		 printf("\n\n"); //Finalização dos dados encontrados 
	}
	
	system("pause");
}

int deletar()
{
	//inicio da criação das variaveis
	char cpf[40];
	// fim da criação das variaveis
	
	printf("Digitar o CPF a ser deletado:"); //inserindo a informação do usuario a ser deletado
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); 
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa que esta lendo os dados coletados
	
	if(file == NULL)
	{
		printf("O usuario não se encontra no sistema!.\n"); // logo que for excluido, será mostrado esse texto afirmando que ja não se encontra mais o usuario cadastrado
		system("pause"); 
	}
	
}

int main ()
{
	int opcao=0;
	int laco=1;
	char senhadigitada[10]="a"; 
	int comparacao;
	
	printf("### Cartório da EBAC ###\n\n");
	printf("Login de administrador!\n\nDigite a sua senha: ");
	scanf("%s", senhadigitada);
	
	comparacao = strcmp(senhadigitada, "admin");
	
	if(comparacao == 0)	    
	{
	    system ("cls"); 
	    for(laco=1;laco=1;)
    {
		system("cls"); // responsavel por limpar a tela 
	
	    setlocale(LC_ALL, "Portuguese"); //Definindo a linguagem
	
	    printf("### Cartorio da EBAC ###\n\n"); //inicio do menu
	    printf("Escolha a opcao desejada do menu\n\n");
	    printf("\t1 - Registrar nomes\n");
	    printf("\t2 - Consultar nomes\n");
	    printf("\t3 - Deletar nomes\n");
	    printf("\t4 - sair do Sistema\n\n"); 
	    printf("opção "); //fim do menu
	
        scanf("%d", &opcao); //armazenamento a escolha do usuario 
	
        system("cls");
     	switch(opcao)
        {
        	case 1:
        	registro(); // chamada de funções
		    break;

		    case 2: 
		    consulta();
		    break;
		  
		    case 3:
		    deletar();
		    break;
		    
		    case 4:
		    printf("Obrigado por utilizar o sistema\n");
		    return 0;
		    break;
		  
		  
		  
		   default: 
		   printf("Essa opcao nao esta disponivel");
		   system("pause");
		   break;
 
	    }
	
    }

}

    else 
        printf("Senha Incorreta!");
    }
