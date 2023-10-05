#include <stdio.h> //biblioteca de comunica��o com o usuario
#include <stdlib.h> //biblioteca de aloca��o de espa�o em memoria 
#include <locale.h> //biblioteca de aloca��es de texto por regi�o 
#include <string.h> //biblioteca responsavel por cuidar da string 

int registro()//Fun��o responsavel por cadastrar os usuarios no sistema

{
	//inicio cria��o de variaveis/string
	char arquivo[40];
	char cpf[40];
	char nome[40];
	char sobrenome[40];
	char cargo [40];
	//final da cria��o das variaveis 
	
	printf("Digite o CPF a ser cadastrado:"); //Coletando informa��o do usuario
	scanf("%s", cpf); //%s refere-se a string    
	
	strcpy(arquivo, cpf); //Responsavel por copiar os valores das string

    FILE *file; // cria o arquivo 
    file = fopen(arquivo, "w"); // cria o arquivo e o "w" significa escrever
    fprintf(file,cpf); // salvo o valor da variavel
    fclose(file); // fecha o arquivo

    file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String 
	fprintf(file,","); // salvo o valor da variavel
	fclose (file);  // fecha o arquivo
	
	printf("Digite o nome a ser cadastrado"); //Coletando informa��o do usuario
	scanf("%s",nome); //string, inform��o do usuario
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String
	fprintf(file,nome); // salvo o valor da variavel
	fclose(file); 	// fecha o arquivo
	
	printf("Digite o sobrenome a ser cadastrado"); //Coletando informa��o do usuario
	scanf("%s",sobrenome); //string, informa��o do usuario 
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String
	fprintf(file, sobrenome); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	printf("Digite o cargo a ser cadastrado"); //Coletando informa��o do usuario
	scanf("%s", cargo); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	file = fopen(arquivo, "a"); // cria o arquivo e o "a" significa String
	fprintf(file, cargo); // salvo o valor da variavel
	fclose(file); // fecha o arquivo
	
	system("pause");


}   

int consulta()
{
	//inicio da cria��o das  variaveis
	char cpf[40];
	char conteudo[200];
	//fim da cria��o das variaveis
	
	printf("Digite o CPF a ser consultado:"); //inserindo a informa��o do usuario
	scanf("%s",cpf); //%s refere-se a string
	
	FILE *file; // cria o arquivo 
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa que esta lendo os dados coletados  
		
	if(file == NULL) // Nulo
    {
    	printf("N�o foi possivel abrir o arquivo, n�o localizado!.\n"); //Quando um dado n�o � encontrado, aparece essa op��o na tela
	}
	
	while(fgets(conteudo, 200, file) != NULL)
	{
		 printf("\nEssas s�o as informa��es do usu�rio: "); // Quando o dado � inserido corretamente
		 printf("%s", conteudo); //refere-se a string dos dados inseridos 
		 printf("\n\n"); //Finaliza��o dos dados encontrados 
	}
	
	system("pause");
}

int deletar()
{
	//inicio da cria��o das variaveis
	char cpf[40];
	// fim da cria��o das variaveis
	
	printf("Digitar o CPF a ser deletado:"); //inserindo a informa��o do usuario a ser deletado
	scanf("%s",cpf); //%s refere-se a string
	
	remove(cpf); 
	
	FILE *file; // cria o arquivo
	file = fopen(cpf, "r"); // cria o arquivo e o "r" significa que esta lendo os dados coletados
	
	if(file == NULL)
	{
		printf("O usuario n�o se encontra no sistema!.\n"); // logo que for excluido, ser� mostrado esse texto afirmando que ja n�o se encontra mais o usuario cadastrado
		system("pause"); 
	}
	
}

int main ()
{
	int opcao=0;
	int laco=1;
	char senhadigitada[10]="a"; 
	int comparacao;
	
	printf("### Cart�rio da EBAC ###\n\n");
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
	    printf("op��o "); //fim do menu
	
        scanf("%d", &opcao); //armazenamento a escolha do usuario 
	
        system("cls");
     	switch(opcao)
        {
        	case 1:
        	registro(); // chamada de fun��es
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
