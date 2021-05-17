// Cadastro no site Tech Friend ou Meu Amigo do TI ou Amigo Tech

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<locale.h>
#include<ctype.h>
#include<time.h> // calcular idade

int main(){
		setlocale(LC_ALL, "Portuguese");
		
struct tm *local; // estrutura para capturar a data do sistema e calcular a idade dos volunt�rios e clientes
time_t t;
t= time(NULL);
local=localtime(&t);

int dia, mes, ano;

dia=local->tm_mday;
mes=local->tm_mon+1;
ano=local->tm_year+1900;
		
int i,opcoes_iniciais, opcao_cliente, opcao_voluntario, opcao_funcionario, mat_funcionario, id_vol, id_cli, dia_nasc_vol[10], dia_nasc_cli[10], dia_nasc_func;
int mes_nasc_vol[10], mes_nasc_cli[10], mes_nasc_func, ano_nasc_vol[10], ano_nasc_cli[10], ano_nasc_func, idade_vol[10], idade_cli[10], idade_func;
int escolha_quipamento, cliente_cadastrado, cadastro_vol, cadastro_cli, media_idade_vol, media_idade_cli, qtde_servicos, solicitacao_func;
int aux_idade_vol, aux_vol, aux_idade_cli, aux_cli, aux_servico;
char sexo_vol[10], sexo_cli[10], menu_princ;
char nome_voluntario[10][100], nome_cliente[10][100], nome_funcionario[100], endereco_vol[10][100], endereco_cli[10][100], endereco_func[100];
char bairro_vol[10][20], bairro_cli[10][20], bairro_func[20], municipio_vol[10][50], municipio_cli[10][50], municipio_func[50], uf_vol[10][2], uf_cli[10][2], uf_func[2];
char cep_vol[10][9], cep_cli[10][9], cep_func[9], cpf_vol[10][10], cpf_cli[10][10], cpf_func[10], email_vol[10][100], email_cli[10][100], email_func[100];

// do-while para voltar ao menu

do{
printf("*****************************************************************\n");
printf("****************   Bem-vindo ao Amigo Tech!   *******************\n");	
printf("*****************************************************************\n\n\n");

printf("Escolha uma das op��es abaixo:\n\n");
printf("Voc� precisa de um Amigo Tech?\nDigite 1\n\n");
printf("Voc� gostaria de se tornar um Amigo Tech?\nDigite 2\n\n");
printf("Portal do Funcion�rio Amigo Tech\nDigite 3\n\n");
printf("Digite a op��o desejada: ");
scanf("%d", &opcoes_iniciais);
fflush(stdin);

system("cls");

switch(opcoes_iniciais){
	
	case 1: printf("Entendido!\nVamos encontrar um amigo agora mesmo, mas para isso precisamos saber qual a ajuda que est� precisando no momento.\n");
			
			printf("Escolha a op��o desejada:\n\n");
			
			printf("Utiliza��o de equipamentos eletr�nicos\nDigite 1\n\nNavegar na Web\nDigite 2\n\nInstala��o de equipamentos\nDigite 3\n\nCompanhia para jogos ou bate-papo\nDigite 4\n");
			scanf("%d", &opcao_cliente);
			
				do{
					
					if(opcao_cliente<1 || opcao_cliente>4)
						printf("Op��o Inv�lida!\n\nInforme a op��o desejada: ");
						scanf("%d", &opcao_cliente);
						fflush(stdin);
						
				}while(opcao_cliente<1 || opcao_cliente>4);
			
			printf("Muito bem.\n\nJ� � cadastrado?\nDigite 1\n\nPara se cadastrar digite 2\n\nInforme a op��o desejada: ");
			scanf("%d", &cliente_cadastrado);
			fflush(stdin);
			
			system("cls");
			
			if(cliente_cadastrado==1){
				if(opcao_cliente==1){printf("Para qual equipamento eletr�nico necessita auxilio?\n\nComputador? Digite 1");
									printf("\nTV? Digite 2\nCelular? Digite 3\nEletrodom�sticos? Digite 4\n\nInforme a op��o desejada: ");
									scanf("%d", &escolha_quipamento);
									fflush(stdin);
									
									qtde_servicos++;
									}																											
							else {printf("Iremos direcionar sua solicita��o ao volunt�rio dispon�vel \ne ele ir� entrar em contato pelo seu telefone para agendar o dia e hora de atendimento");
								  printf("Obrigada por utilizar os servi�os da Amigo Tech!");
								  
								  qtde_servicos++;}
						printf("Iremos direcionar sua solicita��o ao volunt�rio dispon�vel \ne ele ir� entrar em contato pelo seu telefone para agendar o dia e hora de atendimento");
								  printf("Obrigada por utilizar os servi�os da Amigo Tech!");
				} else
				i = 1;
				
				do{	
				if(i == 1){
					printf("Qual � o seu nome completo?\n"); // Cadastrando o volunt�rio no sistma
							fgets(nome_cliente[i],100,stdin);
							fflush(stdin);
							
							printf("\nInforme seu endere�o, Logradouro: ");
							fgets(endereco_cli[i],100,stdin);
							fflush(stdin);
							
							printf("\nBairro: ");
							fgets(bairro_cli[i],20,stdin);
							fflush(stdin);
							
							printf("\nMunic�pio: ");
							fgets(municipio_cli[i],50,stdin);
							fflush(stdin);
							
							printf("\nUF: ");
							fgets(uf_cli[i],2,stdin);
							fflush(stdin);
							
							printf("\nCEP [11111-111]: ");
							fgets(cep_cli[i],9,stdin);
							fflush(stdin);
							
							printf("\nSexo [F|M]: ");
							scanf("%c", &sexo_cli[i]);
							fflush(stdin);
								sexo_cli[i] = toupper(sexo_cli[i]);
								
							printf("\nDia de nascimento: ");
							scanf("%d",&dia_nasc_cli[i]);
							fflush(stdin);
							
							printf("\nM�s de nascimento: ");
							scanf("%d", &mes_nasc_cli[i]);
							fflush(stdin);
							
							printf("\nAno de nascimento[AAAA]: ");
							scanf("%d", &ano_nasc_cli[i]);
							fflush(stdin);
							// calculando a idade do volunt�rio
								idade_cli[i] = ano-ano_nasc_cli[i];
									
									if(mes_nasc_cli[i]>mes)
										idade_cli[i] = idade_cli[i]-1;
										else if(mes_nasc_cli[i]==mes){
												if(dia_nasc_cli[i]>dia)
												idade_cli[i] = idade_cli[i]-1;
												else idade_cli[i]=idade_cli[i];
											}
											else idade_cli[i]=idade_cli[i];
							printf("Idade do volunt�rio: %d", idade_cli[i]);
							
							printf("\nInforme o seu CPF [xxx.xxx.xxx-xx]: ");
							fgets(cpf_cli[i],15,stdin);
							fflush(stdin);
							
							printf("\nInforme seu e-mail: ");
							fgets(email_cli[i],100,stdin);
							fflush(stdin);
							
							aux_idade_cli = aux_idade_cli + idade_cli[i];
							aux_cli++;
							
			//				printf("\nAnexar seu documento de identidade [RG e CPF ou CNH]");
			//				fgets(dcto_cli,100,stdin); //pesquisar
			//				fflush(stdin);
				}
				i=0;
				
				printf("Volte ao menu principal para solicitar o servi�o como cliente cadastrado");
				
			}while(i==1);
						
			
		;break;
		
	case 2: printf("Ok!\nPreciso saber alguns dados...\n\n");
			i = 1;
						
			do{	
				if(i == 1){
					printf("Qual � o seu nome completo?\n"); // Cadastrando o volunt�rio no sistma
							fgets(nome_voluntario[i],100,stdin);
							fflush(stdin);
							
							printf("\nInforme seu endere�o, Logradouro: ");
							fgets(endereco_vol[i],100,stdin);
							fflush(stdin);
							
							printf("\nBairro: ");
							fgets(bairro_vol[i],20,stdin);
							fflush(stdin);
							
							printf("\nMunic�pio: ");
							fgets(municipio_vol[i],50,stdin);
							fflush(stdin);
							
							printf("\nUF: ");
							fgets(uf_vol[i],2,stdin);
							fflush(stdin);
							
							printf("\nCEP [11111-111]: ");
							fgets(cep_vol[i],9,stdin);
							fflush(stdin);
							
							printf("\nSexo [F|M]: ");
							scanf("%c", &sexo_vol[i]);
							fflush(stdin);
								sexo_vol[i] = toupper(sexo_vol[i]);
								
							printf("\nDia de nascimento: ");
							scanf("%d",&dia_nasc_vol[i]);
							fflush(stdin);
							
							printf("\nM�s de nascimento: ");
							scanf("%d", &mes_nasc_vol[i]);
							fflush(stdin);
							
							printf("\nAno de nascimento[AAAA]: ");
							scanf("%d", &ano_nasc_vol[i]);
							fflush(stdin);
							// calculando a idade do volunt�rio
								idade_vol[i] = ano-ano_nasc_vol[i];
									
									if(mes_nasc_vol[i]>mes)
										idade_vol[i] = idade_vol[i]-1;
										else if(mes_nasc_vol[i]==mes){
												if(dia_nasc_vol[i]>dia)
												idade_vol[i] = idade_vol[i]-1;
												else idade_vol[i]=idade_vol[i];
											}
											else idade_vol[i]=idade_vol[i];
							printf("Idade do volunt�rio: %d", idade_vol[i]);
							
							printf("\nInforme o seu CPF [xxx.xxx.xxx-xx]: ");
							fgets(cpf_vol[i],15,stdin);
							fflush(stdin);
							
							printf("\nInforme seu e-mail: ");
							fgets(email_vol[i],100,stdin);
							fflush(stdin);
							
							aux_idade_vol = aux_idade_vol + idade_vol[i];
							aux_vol++;
							
			//				printf("\nAnexar seu documento de identidade [RG e CPF ou CNH]");
			//				fgets(dcto_vol,100,stdin); //pesquisar
			//				fflush(stdin);
				}
				i=0;
			}while(i==1);
			
			break;
	case 3: printf("Favor informar a sua matr�cula: ");
			scanf("%d", &mat_funcionario);
			fflush(stdin);
			
			if(mat_funcionario==1)
				strcpy(nome_funcionario, "Arthur Duarte");
				else if(mat_funcionario==2)
					strcpy(nome_funcionario, "Gustavo Guntzel");
						else if(mat_funcionario==3)
						strcpy(nome_funcionario, "Igor Ribeiro");
							else if(mat_funcionario==4)
							strcpy(nome_funcionario, "Thiago Fernandes");
								else if(mat_funcionario==5)
								strcpy(nome_funcionario, "Kassya Rosa");
			system("cls");
			printf("Bem-vindo(a), %s\n\n", nome_funcionario);
			printf("Deseja saber qual das informa��es abaixo: \n\n1 - M�dia da idade dos volunt�rio\n2 - M�dia da idade dos clientes\n3 - Quantidade de servi�os solicitados");
			scanf("%d", &solicitacao_func);
			fflush(stdin);
			
			media_idade_vol = aux_idade_vol/aux_vol;
			media_idade_cli = aux_idade_cli/aux_cli;
			
			if(solicitacao_func==1)
				printf("\nA m�dia de idade dos volunt�rios cadastrados �: %.1d", media_idade_vol);
				else if(solicitacao_func==2)
					printf("\nA m�dia de idade dos clientes cadastrados �: %.1d", media_idade_cli);
					else printf("\nA quantidade de servi�os solicitados �: %d", qtde_servicos);
					
			system("pause");
			
			break;
	default: printf("Op��o Inv�lida!\n");
			
			}

system("pause");
system("cls");

	do{
			printf("\nDeseja voltar ao menu principal ?[S|N]\n");
			scanf("%c", &menu_princ);
			fflush(stdin);
			menu_princ = toupper(menu_princ); //Converte o caractere em mai�sculo
			if(menu_princ != 'S' && menu_princ != 'N')
				printf("\nOp��o inv�lida!");
		}while(menu_princ != 'S' && menu_princ != 'N');	
		
		i++;		
	
	system("cls");
	
}while(menu_princ=='S');

system("pause");
system("cls");

printf("Programa finalizado");

return 0;
}
