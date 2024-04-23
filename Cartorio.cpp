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
	setlocale(LC_ALL, "Portuguese");  //localidade de idiomas

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
	
	printf("CPF:\t\t\t");  //informa��o para usu�rio
	scanf("%s", cpf); //scanf = Ler dados //%s = referente a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file;  //cria o arquivo  //FILE abre o file
	file = fopen(arquivo, "w"); //cria o arquivo //fopen = abrir //"W" = escrever
	fprintf(file,cpf);  //salva o valor variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo,"a"); //file  = arquivo  // fopen  =  abrir pasta  //"a" = atualizar
	fprintf(file,","); //Adicionar "," no bloco de notas
	fclose(file);  //fclose  = Fechar pastas
	
	printf("Nome:\t\t\t");  //informa��o para usuario
	scanf("%s", nome); //L� a string digitada pelo usu�rio //%s  = salva a informa��o

	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, nome); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,","); //Escrever no file
	fclose(file); //fechar
	
	printf("Sobrenome:\t\t"); //informa��o para usuario
	scanf("%s", sobrenome); //L� a string digitada pelo usu�rio //%s  = salva a informa��o
	
	file = fopen(arquivo, "a");//Abrir e atualizar
	fprintf(file,sobrenome); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	printf("Data de nascimento:\t"); //informa��o para usuario
	scanf("%s", data); //L� a string digitada pelo usu�rio //%s  = salva a informa��o
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,data); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	
	printf("Email:\t\t\t"); //informa��o para usuario
	scanf("%s", email); //L� a string digitada pelo usu�rio //%s  = salva a informa��o
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,email); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	printf("Telefone:\t\t"); //informa��o para usuario
	scanf("%s", telefone); //L� a string digitada pelo usu�rio //%s  = salva a informa��o
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,telefone); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	printf("Cargo:\t\t\t"); //informa��o para usuario
	scanf("%s", cargo); //L� a string digitada pelo usu�rio //%s  = salva a informa��o
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, cargo); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar

	system("pause"); //Congelar tela

}

int consultar() //fun��o
{
	setlocale(LC_ALL, "Portuguese");  //localidade de idioma
	
	char cpf[40];          //string
	char conteudo[400];    //string
	
	printf("  ---  Cart�rio da EBAC  ---\n\n"); //informa��o para usu�rio
	printf("- Digite CPF do Usu�rio -\n\n"); //informa��o para usu�rio
	scanf("%s", cpf); //scanf = Ler dados //%s = Salvar string
	
	system("cls"); //Apaga tela
	
	FILE *file;  //FILE = cria //file = pasta
	file = fopen(cpf,"r"); //fopen  = abre  // "r"  =  l�
	
	if(file == NULL)  //if = definir a��o
	{
		printf("CPF n�o localizado\n"); //informa��o para usu�rio
	}
	
	while(fgets(conteudo, 400, file) != NULL)  //while = Estrutura de repeti��o verdadeira  //fgets = ler string
	{
		printf("  ---  Cart�rio da EBAC  ---\n\n"); //informa��o para usu�rio
		printf("- Informa��es do Usu�rio -\n\n");  //informa��o para usu�rio
		
		char* token = strtok(conteudo,",");	 //strtok =  Ela divide uma string fornecida em tokens (substrings) com base em um delimitador especificado.
			
		printf("CPF:\t\t\t%s\n", token); //informa��o para usu�rio
		token = strtok(NULL,",");  //char* responsavel substituindo a "," por NULL
		
		printf("Nome:\t\t\t%s\n", token); //informa��o para usu�rio
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Sobrenome:\t\t%s\n", token); //informa��o para usu�rio
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Data de nascimento:\t%s\n", token); //informa��o para usu�rio
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Email:\t\t\t%s\n", token); //informa��o para usu�rio
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Telefone;\t\t%s\n", token); //informa��o para usu�rio
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Cargo:\t\t\t%s\n", token); //informa��o para usu�rio
		token = strtok(NULL,","); ///char* responsavel substituindo a "," por NULL
	}
	
	system("pause"); //Congelar Tela
	
	fclose(file);  //Fechar

}

int deletar()  //fun��o
{
	setlocale(LC_ALL, "portuguese"); //Localidade de idioma
	
	char cpf[40];  //string
	
	printf("      ---  Deletar Usu�rio  ---\n");  //Informa��o para usu�rio
	printf("Digite o CPF do usu�rio a ser deletado\n\n"); //Informa��o para usu�rio
	printf("CPF:\t\t"); //Informa��o para usu�rio
	scanf("%s",cpf); //Scanf = ler string  //%s = Salvar
		
	FILE *file; //FILE = Criar
	file = fopen(cpf,"r");  //fopen =  abrir //"r" = L�r
	fclose (file); // fclose = fechar
	
	if (file == NULL)  //if = dar fun��o
	{
		printf("  ---  Usuario inesistente  ---\n"); //Informa��o para usu�rio
	}
	else //else = caso a informa��o seja falsa
		printf("  ---  Usuario Deletado com Sucesso  ---\n"); //Informa��o para usu�rio
	
	remove(cpf); //deletar
	
	system("pause"); //congelar tela
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
	
		scanf("%d", &opcao); //sacanf = Ler dados  //%d = Armazena no sistema
	
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
			
			case 4: //Inicios de IF
			printf("Obrigado! Tenha um �timo dia!!\n\n"); //Informa��o para usu�rio
			return 0; //fechar sistema 
			break; //Finalizar IF
			
			default: //Fim do Encadeamento
			printf("  ---  Op��o Indispon�vel  ---\n\n"); //Informa��o para usu�rio
			system("pause"); //Pausar em uma tela
			break;	//Finalizar IF
		}
	}

}
