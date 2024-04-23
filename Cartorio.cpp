#include <stdio.h>      //bibliteoca de comunicação com o usuarío
#include <stdlib.h>    //biblioteca de alocação de espaço em memória
#include <locale.h>   //bibliteca de alocação de texto por região
#include <string.h>  //bliblioteca responsavel pelo string

			//OBSERVAÇÔES   =   //\n = enter  //\t = espaço  //"Aspas" = texto  //; = confirmar comando 
			//sacanf = pausa o programa enquanto não tem resposta  //%d = Salva variavel de Numero
			//definir variaveis  //if = definir opção //switch = Encadeamento de IF's //for = Repetição
			//TAB para identar  //system("cls") = Apagar tela  //fopen = abrir  //"a" = atualizar
			//"W" = escrever //%s  =  referente a string

int registros() //função de cadastro
{
	setlocale(LC_ALL, "Portuguese");  //localidade de idiomas

	printf("  ---  Cartório da EBAC  ---\n\n");       //informação para usuario
	printf("Digite suas informações pessoais\n\n");   //informação para usuario
	
	char arquivo[40];        //string
	char cpf[40];            //string
	char nome[40];           //string
	char sobrenome[40];      //string
	char data[40];           //string
	char email[40];          //string
	char telefone[40];       //string
	char cargo[40];          //string
	
	printf("CPF:\t\t\t");  //informação para usuário
	scanf("%s", cpf); //scanf = Ler dados //%s = referente a string
	
	strcpy(arquivo, cpf); //responsavel por copiar os valores da string
	
	FILE *file;  //cria o arquivo  //FILE abre o file
	file = fopen(arquivo, "w"); //cria o arquivo //fopen = abrir //"W" = escrever
	fprintf(file,cpf);  //salva o valor variavel
	fclose(file);  // fecha o arquivo
	
	file = fopen(arquivo,"a"); //file  = arquivo  // fopen  =  abrir pasta  //"a" = atualizar
	fprintf(file,","); //Adicionar "," no bloco de notas
	fclose(file);  //fclose  = Fechar pastas
	
	printf("Nome:\t\t\t");  //informação para usuario
	scanf("%s", nome); //Lê a string digitada pelo usuário //%s  = salva a informação

	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, nome); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,","); //Escrever no file
	fclose(file); //fechar
	
	printf("Sobrenome:\t\t"); //informação para usuario
	scanf("%s", sobrenome); //Lê a string digitada pelo usuário //%s  = salva a informação
	
	file = fopen(arquivo, "a");//Abrir e atualizar
	fprintf(file,sobrenome); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	printf("Data de nascimento:\t"); //informação para usuario
	scanf("%s", data); //Lê a string digitada pelo usuário //%s  = salva a informação
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,data); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	
	printf("Email:\t\t\t"); //informação para usuario
	scanf("%s", email); //Lê a string digitada pelo usuário //%s  = salva a informação
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,email); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	printf("Telefone:\t\t"); //informação para usuario
	scanf("%s", telefone); //Lê a string digitada pelo usuário //%s  = salva a informação
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file,telefone); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar
	
	printf("Cargo:\t\t\t"); //informação para usuario
	scanf("%s", cargo); //Lê a string digitada pelo usuário //%s  = salva a informação
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, cargo); //Escrever no file
	fclose(file); //fechar
	
	file = fopen(arquivo, "a"); //Abrir e atualizar
	fprintf(file, ","); //Escrever no file
	fclose(file); //fechar

	system("pause"); //Congelar tela

}

int consultar() //função
{
	setlocale(LC_ALL, "Portuguese");  //localidade de idioma
	
	char cpf[40];          //string
	char conteudo[400];    //string
	
	printf("  ---  Cartório da EBAC  ---\n\n"); //informação para usuário
	printf("- Digite CPF do Usuário -\n\n"); //informação para usuário
	scanf("%s", cpf); //scanf = Ler dados //%s = Salvar string
	
	system("cls"); //Apaga tela
	
	FILE *file;  //FILE = cria //file = pasta
	file = fopen(cpf,"r"); //fopen  = abre  // "r"  =  lê
	
	if(file == NULL)  //if = definir ação
	{
		printf("CPF não localizado\n"); //informação para usuário
	}
	
	while(fgets(conteudo, 400, file) != NULL)  //while = Estrutura de repetição verdadeira  //fgets = ler string
	{
		printf("  ---  Cartório da EBAC  ---\n\n"); //informação para usuário
		printf("- Informações do Usuário -\n\n");  //informação para usuário
		
		char* token = strtok(conteudo,",");	 //strtok =  Ela divide uma string fornecida em tokens (substrings) com base em um delimitador especificado.
			
		printf("CPF:\t\t\t%s\n", token); //informação para usuário
		token = strtok(NULL,",");  //char* responsavel substituindo a "," por NULL
		
		printf("Nome:\t\t\t%s\n", token); //informação para usuário
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Sobrenome:\t\t%s\n", token); //informação para usuário
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Data de nascimento:\t%s\n", token); //informação para usuário
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Email:\t\t\t%s\n", token); //informação para usuário
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Telefone;\t\t%s\n", token); //informação para usuário
		token = strtok(NULL,","); //char* responsavel substituindo a "," por NULL
		
		printf("Cargo:\t\t\t%s\n", token); //informação para usuário
		token = strtok(NULL,","); ///char* responsavel substituindo a "," por NULL
	}
	
	system("pause"); //Congelar Tela
	
	fclose(file);  //Fechar

}

int deletar()  //função
{
	setlocale(LC_ALL, "portuguese"); //Localidade de idioma
	
	char cpf[40];  //string
	
	printf("      ---  Deletar Usuário  ---\n");  //Informação para usuário
	printf("Digite o CPF do usuário a ser deletado\n\n"); //Informação para usuário
	printf("CPF:\t\t"); //Informação para usuário
	scanf("%s",cpf); //Scanf = ler string  //%s = Salvar
		
	FILE *file; //FILE = Criar
	file = fopen(cpf,"r");  //fopen =  abrir //"r" = Lêr
	fclose (file); // fclose = fechar
	
	if (file == NULL)  //if = dar função
	{
		printf("  ---  Usuario inesistente  ---\n"); //Informação para usuário
	}
	else //else = caso a informação seja falsa
		printf("  ---  Usuario Deletado com Sucesso  ---\n"); //Informação para usuário
	
	remove(cpf); //deletar
	
	system("pause"); //congelar tela
}

int main() //int mai = Função menu 
{
	
	int opcao=0; //int = definir variaveis
	int x=1;    //int = definir variaveis
	
	for(x=1;x=1;)  //for = Repetição
	{
		
		system("cls"); //Apagar tela
	
		setlocale(LC_ALL, "Portuguese"); //setlocale = Seleção de idioma  //LC_ALL = Referência à todos os aspectos da localização
	
		printf("  ---  Cartório da EBAC  ---\n\n");         //printf = comunicação com usuário
		printf("Bem Vindo a EBAC!!\nSelecione a opção do menu:\n\n");    //printf = comunicação com usuário
		printf("\t1 - Registrar usuário\n");               //printf = comunicação com usuário
		printf("\t2 - Consultar usuário\n");              //printf = comunicação com usuário
		printf("\t3 - Deletar usuário\n\n");
		printf("\t4 - Sair do sistema");                 //printf = comunicação com usuário
		printf("\n\nQual a opção desejada:");      //printf = comunicação com usuário
	
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
			printf("Obrigado! Tenha um ótimo dia!!\n\n"); //Informação para usuário
			return 0; //fechar sistema 
			break; //Finalizar IF
			
			default: //Fim do Encadeamento
			printf("  ---  Opção Indisponível  ---\n\n"); //Informação para usuário
			system("pause"); //Pausar em uma tela
			break;	//Finalizar IF
		}
	}

}
