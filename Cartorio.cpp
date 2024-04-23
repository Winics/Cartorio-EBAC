#include <stdio.h>      //bibliteoca de comunica��o com o usuar�o
#include <stdlib.h>    //biblioteca de aloca��o de espa�o em mem�ria
#include <locale.h>   //bibliteca de aloca��o de texto por regi�o
#include <string.h>  //bliblioteca responsavel pelo string

			//OBSERVA��ES   =   //\n = enter  //\t = espa�o  //"Aspas" = texto  //; = confirmar comando 
			//sacanf = pausa o programa enquanto n�o tem resposta  //%d = Salva variavel de Numero
			//definir variaveis  //if = definir op��o //switch = Encadeamento de IF's //for = Repeti��o
			//TAB para identar  //system("cls") = Apagar tela  //fopen = abrir  //"a" = atualizar
			//"W" = escrever //%s  =  referente a string

int registros() //fun��o de cadastro
{
	setlocale(LC_ALL, "Portuguese");

	printf("  ---  Cart�rio da EBAC  ---\n\n");       //informa��o para usuario
	printf("Digite suas informa��es pessoais\n\n");   //informa��o para usuario
	
	char arquivo[40];        //string
	char cpf[40];            //string
	char nome[40];           //string
	char sobrenome[40];      //string
	char data[40];           //string
	char email[40];          //string
	char telefone[40];       //string
	char cargo[40];          //string
	
	printf("CPF:\t\t\t");  //informa��o para usuario
	scanf("%s", cpf);  //%s = referente a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file;  //cria o arquivo  //FILE abre o file
	file = fopen(arquivo, "w"); //cria o arquivo //fopen = abrir //"W" = escrever
	fprintf(file,cpf);  //salva o valor variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo,"a"); //file  = arquivo  // fopen  =  abrir pasta  //"a" = atualizar
	fprintf(file,","); //Adicionar "," no bloco de notas
	fclose(file);  //fclose  = Fechar pastas
	
	printf("Nome:\t\t\t");  
	scanf("%s", nome);

	file = fopen(arquivo, "a");
	fprintf(file, nome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file,","); //Gambiarra est�tica
	fclose(file);
	
	printf("Sobrenome:\t\t");
	scanf("%s", sobrenome);
	
	file = fopen(arquivo, "a");
	fprintf(file,sobrenome);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //Gambiarra est�tica
	fclose(file);
	
	printf("Data de nascimento:\t");
	scanf("%s", data);
	
	file = fopen(arquivo, "a");
	fprintf(file,data);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //Gambiarra est�tica
	fclose(file);
	
	
	printf("Email:\t\t\t");
	scanf("%s", email);
	
	file = fopen(arquivo, "a");
	fprintf(file,email);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //Gambiarra est�tica
	fclose(file);
	
	printf("Telefone:\t\t");
	scanf("%s", telefone);
	
	file = fopen(arquivo, "a");
	fprintf(file,telefone);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ","); //Gambiarra est�tica
	fclose(file);
	
	printf("Cargo:\t\t\t");
	scanf("%s", cargo);
	
	file = fopen(arquivo, "a");
	fprintf(file, cargo);
	fclose(file);
	
	file = fopen(arquivo, "a");
	fprintf(file, ",");
	fclose(file);

	system("pause");

}

int consultar() //fun��o
{
	setlocale(LC_ALL, "Portuguese");
	
	char cpf[40];
	char conteudo[400];
	
	printf("  ---  Cart�rio da EBAC  ---\n\n");
	printf("- Digite CPF do Usu�rio -\n\n");
	scanf("%s", cpf);
	
	system("cls");
	
	FILE *file;
	file = fopen(cpf,"r");
	
	if(file == NULL)
	{
		printf("CPF n�o localizado\n");
	}
	
	while(fgets(conteudo, 400, file) != NULL)
	{
		printf("  ---  Cart�rio da EBAC  ---\n\n");
		printf("- Informa��es do Usu�rio -\n\n");
		
		char* token = strtok(conteudo,",");	
			
		printf("CPF:\t\t\t%s\n", token);
		token = strtok(NULL,",");
		
		printf("Nome:\t\t\t%s\n", token);
		token = strtok(NULL,",");
		
		printf("Sobrenome:\t\t%s\n", token);
		token = strtok(NULL,",");
		
		printf("Data de nascimento:\t%s\n", token);
		token = strtok(NULL,",");
		
		printf("Email:\t\t\t%s\n", token);
		token = strtok(NULL,",");
		
		printf("Telefone;\t\t%s\n", token);
		token = strtok(NULL,",");
		
		printf("Cargo:\t\t\t%s\n", token);
		token = strtok(NULL,",");
	}
	
	system("pause");
	
	fclose(file);

}

int deletar()  //fun��o
{
	setlocale(LC_ALL, "portuguese");
	
	char cpf[40];
	
	printf("      ---  Deletar Usu�rio  ---\n");
	printf("Digite o CPF do usu�rio a ser deletado\n\n");
	printf("CPF:\t\t");
	scanf("%s",cpf);
		
	FILE *file;
	file = fopen(cpf,"r");
	fclose (file);
	
	if (file == NULL)
	{
		printf("  ---  Usuario inesistente  ---\n");
	}
	else
		printf("  ---  Usuario Deletado com Sucesso  ---\n");
	
	remove(cpf);
	
	system("pause");
}

int main() //int mai = Fun��o menu 
{
	
	int opcao=0; //int = definir variaveis
	int x=1;    //int = definir variaveis
	
	for(x=1;x=1;)  //for = Repeti��o
	{
		
		system("cls"); //Apagar tela
	
		setlocale(LC_ALL, "Portuguese"); //setlocale = Sele��o de idioma  //LC_ALL = Refer�ncia � todos os aspectos da localiza��o
	
		printf("  ---  Cart�rio da EBAC  ---\n\n");         //printf = comunica��o com usu�rio
		printf("Bem Vindo a EBAC!!\nSelecione a op��o do menu:\n\n");    //printf = comunica��o com usu�rio
		printf("\t1 - Registrar usu�rio\n");               //printf = comunica��o com usu�rio
		printf("\t2 - Consultar usu�rio\n");              //printf = comunica��o com usu�rio
		printf("\t3 - Deletar usu�rio\n\n");
		printf("\t4 - Sair do sistema");                 //printf = comunica��o com usu�rio
		printf("\n\nQual a op��o desejada:");      //printf = comunica��o com usu�rio
	
		scanf("%d", &opcao); //sacanf = pausa o programa enquanto n�o tem resposta
	
		system("cls"); //Apagar tela
	
	
		switch(opcao)  //switch = Encadeamento de IF's
		{
			case 1:  //Inicio de IF
			registros();
			break;  //Finalizar IF
			
			case 2:  //Inicio de IF
			consultar();
			break;  //Finalizar IF
			
			case 3: //Inicio de IF
			deletar();
			break;  //Finalizar IF
			
			case 4:
			printf("Obrigado! Tenha um �timo dia!!\n");
			return 0;
			break;
			
			default: //Fim do Encadeamento
			printf("  ---  Op��o Indispon�vel  ---\n\n");
			system("pause"); //Pausar em uma tela
			break;	//Finalizar IF
		}
	}

}
