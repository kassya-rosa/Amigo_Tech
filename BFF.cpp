// Cadastro no site Tech Friend ou Meu Amigo do TI ou Amigo Tech

#include<stdio.h> //biblioteca para printf e scanf 
#include<stdlib.h> //biblioteca para comandos Windows
#include<string.h> //biblioteca para strlen e strcmp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<ctype.h> //biblioteca para o uso do toupper e tolower: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/
#include<locale.h> // biblioteca para utilizar acentua��o do portugu�s: http://linguagemc.com.br/localizacao-de-programas-com-locale-h/
#include<time.h> // biblioteca para capturar a data do sistema: http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/

int main(){
		setlocale(LC_ALL, "Portuguese");
		
struct tm *local; // ponteiro para struct que armazena data
time_t t;
t= time(NULL);
local=localtime(&t);// para converter para o tempo local utiliza-se a fun��o localtime

int dia, mes, ano;

// para acessar os membros de uma struct usando o ponteiro utilizamos o operador -> no nosso caso temos: 
// local->membro_da_struct
// guardamos o valor em vari�veis para poder utilizar no c�lculo da idade

dia=local->tm_mday;
mes=local->tm_mon+1;
ano=local->tm_year+1900;

// nomes de variavel com significado (C�digo limpo)
		
int i=1, j=1,opcoes_iniciais, opcao_cliente, opcao_voluntario, opcao_funcionario, mat_funcionario, id_vol, id_cli, dia_nasc_vol[10], dia_nasc_cli[10];
int mes_nasc_vol[10], mes_nasc_cli[10], ano_nasc_vol[10], ano_nasc_cli[10];
int escolha_quipamento, cliente_cadastrado, cadastro_vol, cadastro_cli, qtde_servicos=0, solicitacao_func, opcao_atendimento, informa_fim_atend_cli, informa_fim_atend_vol;
int aux_idade_vol=0, aux_vol=0, aux_idade_cli=0, aux_cli=0, aux_servico, dta_nasc_cli, dta_nasc_vol, dia_mes_cli, dia_mes_vol, nota_vol;
float duracao_atend_cli=0, duracao_atend_vol=0, media_duracao_atende_vol, media_duracao_atende_cli;
float hora_atend_cli[10], min_atend_cli[10], seg_atend_cli[10], dur_atend_cli_atual[10], dur_atend_vol_atual[10];
float hora_atend_vol[10], min_atend_vol[10], seg_atend_vol[10];
float hora_atend_cli_fim[10], min_atend_cli_fim[10], seg_atend_cli_fim[10];
float hora_atend_vol_fim[10], min_atend_vol_fim[10], seg_atend_vol_fim[10];
float media_idade_vol, media_idade_cli, total_nota_vol=0, media_nota_vol, aux_atend_cli=0, aux_atend_vol=0,  idade_vol[10], idade_cli[10];
char sexo_vol[10], sexo_cli[10], menu_princ, sim_nao_vol, sim_nao_cli, nome_funcionario[16], aux_solicitacao_func;
char nome_voluntario[10][100], nome_cliente[10][100],endereco_vol[10][100], endereco_cli[10][100];
char bairro_vol[10][20], bairro_cli[10][20], municipio_vol[10][50], municipio_cli[10][50], uf_vol[10][5], uf_cli[10][5];
char cep_vol[10][10], cep_cli[10][10], cpf_vol[10][11], cpf_cli[10][11], email_vol[10][100], email_cli[10][100], tel_vol[10][100], tel_cli[10][100];

// Utilizando o m�ximo de repeti��o para diminuir o tamanho do c�digo (C�digo limpo)

do{// do-while para voltar ao menu principal
printf("*****************************************************************\n");// constr�i o menu para o usu�rio
printf("****************   Bem-vindo ao Amigo Tech!   *******************\n");	
printf("*****************************************************************\n\n\n");

printf("Escolha uma das op��es abaixo:\n\n");
printf("Voc� precisa de um Amigo Tech?\nDigite 1\n\n");
printf("Voc� gostaria de se tornar um Amigo Tech?\nDigite 2\n\n");
printf("Tenho um ho�rio agendado.\nDigite 3\n\n");
printf("Portal do Funcion�rio Amigo Tech\nDigite 4\n\n");
printf("Digite a op��o desejada: ");
scanf("%d", &opcoes_iniciais);// guarda a informa��o da op��o desejada do menu
fflush(stdin); // limpa o buffer de mem�ria

system("cls"); // limpa a tela do terminal

switch(opcoes_iniciais){ // respons�vel por permitir o acesso ao pr�ximo menu de op��es
	
	case 1: printf("*****************************************************************\n");
			printf("*************   Amigo Tech! - Portal do Cliente  ****************\n");	
			printf("*****************************************************************\n\n\n");
	
	
			printf("Muito bem.\n\nDigite 1 se j� for cadastrado\n\nDigite 2 para se cadastrar\n\nInforme a op��o desejada: ");
			scanf("%d", &cliente_cadastrado);
			fflush(stdin);
			
			system("cls");
			
			switch(cliente_cadastrado){ 
				
				case 1: printf("*****************************************************************\n");
						printf("*************   Amigo Tech! - Portal do Cliente  ****************\n");	
						printf("*****************************************************************\n\n\n");
				
						printf("Entendido!\nVamos encontrar um amigo agora mesmo, mas para isso precisamos saber qual a ajuda que est� precisando no momento.\n");
			
						printf("Escolha a op��o desejada:\n\n");
						
						printf("Utiliza��o de equipamentos eletr�nicos\nDigite 1\n\nNavegar na Web\nDigite 2\n\nInstala��o de equipamentos\nDigite 3\n\nCompanhia para jogos ou bate-papo\nDigite 4\n\nInforme a op��o desejada: ");
						scanf("%d", &opcao_cliente);
						fflush(stdin);
							
							while(opcao_cliente<1 && opcao_cliente>4){// permite ao usu�rio corrigir caso tenho informado o valor errado	
								if(opcao_cliente<1 && opcao_cliente>4)
									printf("Op��o Inv�lida!\n\nInforme a op��o desejada: ");
									scanf("%d", &opcao_cliente);
									fflush(stdin);
								}
						
						system("cls");
						
						printf("*****************************************************************\n");
						printf("*************   Amigo Tech! - Portal do Cliente  ****************\n");	
						printf("*****************************************************************\n\n\n");
				
							if(opcao_cliente==1){printf("Para qual equipamento eletr�nico necessita auxilio?\n\nComputador? Digite 1");
									printf("\nTV? Digite 2\nCelular? Digite 3\nEletrodom�sticos? Digite 4\n\nInforme a op��o desejada: ");
									scanf("%d", &escolha_quipamento);
									fflush(stdin);
									
									while(escolha_quipamento<1 && escolha_quipamento>4){
										if(escolha_quipamento<1 && escolha_quipamento>4)
											printf("Op��o Inv�lida!\n\nInforme a op��o desejada: ");
											scanf("%d", &escolha_quipamento);
											fflush(stdin);
										}
									
									qtde_servicos++; // Conta a quantidade de servi�os solicitados
									}																											
							else {
								  printf("Iremos direcionar sua solicita��o ao volunt�rio dispon�vel \ne ele ir� entrar em contato pelo seu telefone para agendar o dia e hora de atendimento");
								  printf("\nObrigado por utilizar os servi�os da Amigo Tech!\n");
								  
								  qtde_servicos++;}
					
						break;
			
				case 2: do{ printf("*****************************************************************\n");
							printf("*******************  Cadastro de cliente   **********************\n");	
							printf("*****************************************************************\n\n\n");
								do{
								   
									printf("Qual � o seu nome completo?\n"); // Cadastrando o cliente no sistma
									fgets(nome_cliente[i],100,stdin);
									fflush(stdin);
										if(strlen(nome_cliente[i]) <= 6) // strlen: verifica o tamanho da string, se for menor ou igual a 6, apresenta o erro
											printf("\nNome inv�lido!\n");	// apresenta texto na tela	
								}while(strlen(nome_cliente[i]) <= 6);// repeti��o quando o nome for menor que 5 caracteres
								
								do{	
									printf("\nInforme seu telefone para contato com DDD: ");
									fgets(tel_cli[i],11,stdin);
									fflush(stdin);
										if(strlen(tel_cli[i]) <= 10)
											printf("\nLogradouro inv�lido!");
								}while(strlen(tel_cli[i]) <= 10);
								
								do{	
									printf("\nInforme seu endere�o, Logradouro: ");
									fgets(endereco_cli[i],100,stdin);
									fflush(stdin);
										if(strlen(endereco_cli[i]) <= 1)
											printf("\nLogradouro inv�lido!");
								}while(strlen(endereco_cli[i]) <= 1);
								
								do{	
									printf("\nBairro: ");
									fgets(bairro_cli[i],20,stdin);
									fflush(stdin);
										if(strlen(bairro_cli[i]) <= 1)
											printf("\nBairro inv�lido!");
								}while(strlen(bairro_cli[i]) <= 1);
								
								do{
									printf("\nMunic�pio: ");
									fgets(municipio_cli[i],50,stdin);
									fflush(stdin);
										if(strlen(municipio_cli[i]) <= 3)
											printf("\nMunic�pio inv�lido!");
								}while(strlen(municipio_cli[i]) <= 3);
								
								do{
									printf("\nUF: ");
									fgets(uf_cli[i],5,stdin);
									fflush(stdin);
										if(strlen(uf_cli[i]) <= 2)
											printf("\nUF inv�lida!");
								}while(strlen(uf_cli[i]) <= 2);
								
								do{
									printf("\nCEP [11111-111]: ");
									fgets(cep_cli[i],10,stdin);
									fflush(stdin);
									
										if(strlen(cep_cli[i]) <= 8)
											printf("\nCEP inv�lida!");
								}while(strlen(cep_cli[i]) <= 8);
									
									printf("\nSexo [F|M]: ");
									scanf("%c", &sexo_cli[i]);
									fflush(stdin);
										sexo_cli[i] = toupper(sexo_cli[i]);
										
											do{// permite ao usu�rio corrigir caso tenha informado o valor errado
												if (sexo_cli[i]!= 'F'&& sexo_cli[i] != 'M'){ 
												printf("\nSexo inv�lido!\nInforme[F|M]: ");
												scanf("%c", &sexo_cli[i]);
												fflush(stdin);
												sexo_cli[i] = toupper(sexo_cli[i]);
											}}while(sexo_cli[i]!= 'F'&& sexo_cli[i] != 'M');
								
								do{
									dia_mes_cli=0;
									do{	
										printf("\nDia de nascimento: ");
										scanf("%d",&dia_nasc_cli[i]);
										fflush(stdin);
												if(dia_nasc_cli[i]<1 || dia_nasc_cli[i]>31)
													printf("\nDia inv�lido!\n");
									}while(dia_nasc_cli[i]<1 || dia_nasc_cli[i]>31);
									
									do{	
											printf("\nM�s de nascimento: ");
											scanf("%d", &mes_nasc_cli[i]);
											fflush(stdin);
												if(mes_nasc_cli[i]<1 || mes_nasc_cli[i]>12)
												printf("\nM�s inv�lido!");
									}while(mes_nasc_cli[i]<1 || mes_nasc_cli[i]>12);
					
										if((mes_nasc_cli[i] == 2|| mes_nasc_cli[i] ==4|| mes_nasc_cli[i] == 6|| mes_nasc_cli[i] == 9|| mes_nasc_cli[i] == 11) && dia_nasc_cli[i] == 31){
											printf("%d/%d n�o existe! Tente novamente\n", dia_nasc_cli[i], mes_nasc_cli[i]);
											dia_mes_cli = 1;}
											
										if(mes_nasc_cli[i] == 2 && dia_nasc_cli[i] == 30){
											printf("%d/%d n�o existe! Tente novamente\n", dia_nasc_cli[i], mes_nasc_cli[i]);
											dia_mes_cli = 1;}
								}while(dia_mes_cli==1);
								
								
								do{
									dta_nasc_cli=0;
										printf("\nAno de nascimento[AAAA]: ");
										scanf("%d", &ano_nasc_cli[i]);
										fflush(stdin);
										
											if(ano_nasc_cli[i]<1910 || ano_nasc_cli[i]>ano-16){
												printf("\nAno inv�lido!");
												dta_nasc_cli = 1;
											}
											if (mes_nasc_cli[i] == 2 && dia_nasc_cli[i] ==29){
												if((( ano_nasc_cli[i] % 4 == 0 && ano_nasc_cli[i] % 100 != 0 ) || ano_nasc_cli[i] % 400 == 0 )){
												}
											
											 else {
												printf("\n%d/%d/%d n�o � uma data v�lida.", dia_nasc_cli[i], mes_nasc_cli[i], ano_nasc_cli[i]);
												dta_nasc_cli=1;
											}}
								}while(dta_nasc_cli==1);
									
											// calculando a idade do cliente
												idade_cli[i] = ano-ano_nasc_cli[i];
													
													if(mes_nasc_cli[i]>mes)
														idade_cli[i] = idade_cli[i]-1;
														else if(mes_nasc_cli[i]==mes){
																if(dia_nasc_cli[i]>dia)
																idade_cli[i] = idade_cli[i]-1;
																else idade_cli[i]=idade_cli[i];
															}
															else idade_cli[i]=idade_cli[i];
								do{	
									printf("\nInforme o seu CPF [xxx.xxx.xxx-xx]: ");
									fgets(cpf_cli[i],16,stdin);
									fflush(stdin);
										if(strlen(cpf_cli[i]) <= 14)
											printf("\nCPF inv�lido!");
								}while(strlen(cpf_cli[i]) <= 14);
								
								do{	
									printf("\nInforme seu e-mail: ");
									fgets(email_cli[i],100,stdin);
									fflush(stdin);
										if(strlen(email_cli[i]) <= 5)
											printf("\nE-mail inv�lido!");
								}while(strlen(email_cli[i]) <= 5);
								
							system("cls");
							
							// Imprime na tela os dados digitados para cadastro do cliente
									
							printf("*****************************************************************\n");
							printf("*******************  Cadastro de cliente   **********************\n");	
							printf("*****************************************************************\n\n\n");
									
							printf("\nConfira os dados informados:\n\n");
							printf("\nNome: %s", nome_cliente[i]);
							printf("\nTelefone: %s", tel_cli[i]);
							printf("\nCPF: %s", cpf_cli[i]);
							printf("\nSexo: %c", sexo_cli[i]);
							printf("\nEndere�o: %s - %s", endereco_cli[i], bairro_cli[i]);
							printf("\n%s - %s", municipio_cli[i], uf_cli[i]);
							printf("\nCEP: %s", cep_cli[i]);							
							printf("\nData de Nascimento: %d/%d/%d", dia_nasc_cli[i], mes_nasc_cli[i], ano_nasc_cli[i]);							
							printf("\nE-mail: %s", email_cli[i]);	
							printf("\n\nOs dados informados est�o corretos [S|N]? ");
							scanf("%c", &sim_nao_cli);
							fflush(stdin);
							
							sim_nao_cli=toupper(sim_nao_cli);
							
								if(sim_nao_cli == 'N'){
									printf("\nFavor preencher novamente");
									system("cls");}
						}while(sim_nao_cli == 'N');
						
						aux_idade_cli = aux_idade_cli + idade_cli[i];
						aux_cli++;
							
						system("cls");
						
						printf("*****************************************************************\n");
						printf("*******************  Cadastro de cliente   **********************\n");	
						printf("*****************************************************************\n\n\n");
						
						printf("Seu n�mero de cadastro �: %d\n", i);
						
						printf("\nVolte ao menu principal para solicitar o servi�o como cliente cadastrado\n\n");
					
						i++;
				break;	
				default: printf("Op��o inv�lida!\n");
			}
		;break;
		
	case 2: do{	printf("*****************************************************************\n");
				printf("******************  Cadastro de volunt�rio   ********************\n");	
				printf("*****************************************************************\n\n\n");
						
				printf("Ok!\nPreciso saber alguns dados...\n\n");
				do{
					printf("Qual � o seu nome completo?\n"); // Cadastrando o volunt�rio no sistma
						fgets(nome_voluntario[j],100,stdin);
						fflush(stdin);
							if(strlen(nome_voluntario[j]) <= 6) // strlen: verifica o tamanho da string, se for menor ou igual a 6, apresenta o erro
								printf("\nNome inv�lido!\n");	// apresenta texto na tela	
					}while(strlen(nome_voluntario[j]) <= 6);// repeti��o quando o nome for menor que 5 caracteres
					
					do{	
						printf("\nInforme seu telefone para contato com DDD: ");
						fgets(tel_vol[i],11,stdin);
						fflush(stdin);
							if(strlen(tel_vol[i]) <= 10)
								printf("\nLogradouro inv�lido!");
					}while(strlen(tel_vol[i]) <= 10);
					
					do{	
						printf("\nInforme seu endere�o, Logradouro: ");
						fgets(endereco_vol[j],100,stdin);
						fflush(stdin);
							if(strlen(endereco_vol[j]) <= 1)
								printf("\nLogradouro inv�lido!");
					}while(strlen(endereco_vol[j]) <= 1);
					
					do{	
						printf("\nBairro: ");
						fgets(bairro_vol[j],20,stdin);
						fflush(stdin);
							if(strlen(bairro_vol[j]) <= 1)
								printf("\nBairro inv�lido!");
					}while(strlen(bairro_vol[j]) <= 1);
					
					do{
						printf("\nMunic�pio: ");
						fgets(municipio_vol[j],50,stdin);
						fflush(stdin);
							if(strlen(municipio_vol[j]) <= 3)
								printf("\nMunic�pio inv�lido!");
					}while(strlen(municipio_vol[j]) <= 3);
					
					do{
						printf("\nUF: ");
						fgets(uf_vol[j],5,stdin);
						fflush(stdin);
							if(strlen(uf_vol[j]) <= 2)
								printf("\nUF inv�lida!");
					}while(strlen(uf_vol[j]) <= 2);
					
					do{
						printf("\nCEP [11111-111]: ");
						fgets(cep_vol[j],10,stdin);
						fflush(stdin);
							if(strlen(cep_vol[j]) <= 8)
								printf("\nCEP inv�lida!");
					}while(strlen(cep_vol[j]) <= 8);
						
						printf("\nSexo [F|M]: ");
						scanf("%c", &sexo_vol[j]);
						fflush(stdin);
							sexo_vol[j] = toupper(sexo_vol[j]);
							
								do{// permite ao usu�rio corrigir caso tenha informado o valor errado
									if (sexo_vol[j]!= 'F'&& sexo_vol[j] != 'M'){ 
									printf("\nSexo inv�lido!\nInforme[F|M]: ");
									scanf("%c", &sexo_vol[j]);
									fflush(stdin);
									sexo_vol[j] = toupper(sexo_vol[j]);
								}}while(sexo_vol[j]!= 'F'&& sexo_vol[j] != 'M');
					
					do{
						dia_mes_vol=0;
						do{	
							printf("\nDia de nascimento: ");
							scanf("%d",&dia_nasc_vol[j]);
							fflush(stdin);
									if(dia_nasc_vol[j]<1 || dia_nasc_vol[j]>31)
										printf("\nDia inv�lido!\n");
						}while(dia_nasc_vol[j]<1 || dia_nasc_vol[j]>31);
						
						do{	
								printf("\nM�s de nascimento: ");
								scanf("%d", &mes_nasc_vol[j]);
								fflush(stdin);
									if(mes_nasc_vol[j]<1 || mes_nasc_vol[j]>12)
									printf("\nM�s inv�lido!");
						}while(mes_nasc_vol[j]<1 || mes_nasc_vol[j]>12);
		
							if((mes_nasc_vol[j] == 2|| mes_nasc_vol[j] ==4|| mes_nasc_vol[j] == 6|| mes_nasc_vol[j] == 9|| mes_nasc_vol[j] == 11) && dia_nasc_vol[j] == 31){
								printf("%d/%d n�o existe! Tente novamente\n", dia_nasc_vol[j], mes_nasc_vol[j]);
								dia_mes_vol = 1;}
								
							if(mes_nasc_vol[j] == 2 && dia_nasc_vol[j] == 30){
								printf("%d/%d n�o existe! Tente novamente\n", dia_nasc_vol[j], mes_nasc_vol[j]);
								dia_mes_vol = 1;}
					}while(dia_mes_vol==1);
					
					
					do{
						dta_nasc_vol=0;
							printf("\nAno de nascimento[AAAA]: ");
							scanf("%d", &ano_nasc_vol[j]);
							fflush(stdin);
							
								if(ano_nasc_vol[j]<1910 || ano_nasc_vol[j]>ano-16){
									printf("\nAno inv�lido!");
									dta_nasc_vol = 1;
								}
								if (mes_nasc_vol[j] == 2 && dia_nasc_vol[j] ==29){
									if((( ano_nasc_vol[j] % 4 == 0 && ano_nasc_vol[j] % 100 != 0 ) || ano_nasc_vol[j] % 400 == 0 )){
									}
								
								 else {
									printf("\n%d/%d/%d n�o � uma data v�lida.", dia_nasc_vol[j], mes_nasc_vol[j], ano_nasc_vol[j]);
									dta_nasc_vol=1;
								}}
					}while(dta_nasc_vol==1);
						
								// calculando a idade do volunt�rio
									idade_vol[j] = ano-ano_nasc_vol[j];
										
										if(mes_nasc_vol[j]>mes)
											idade_vol[j] = idade_vol[j]-1;
											else if(mes_nasc_vol[j]==mes){
													if(dia_nasc_vol[j]>dia)
													idade_vol[j] = idade_vol[j]-1;
													else idade_vol[j]=idade_vol[j];
												}
												else idade_vol[j]=idade_vol[j];
					do{	
						printf("\nInforme o seu CPF [xxx.xxx.xxx-xx]: ");
						fgets(cpf_vol[j],16,stdin);
						fflush(stdin);
							if(strlen(cpf_vol[j]) <= 14)
								printf("\nCEP inv�lida!");
					}while(strlen(cpf_vol[j]) <= 14);
					
					do{	
						printf("\nInforme seu e-mail: ");
						fgets(email_vol[j],100,stdin);
						fflush(stdin);
							if(strlen(email_vol[j]) <= 5)
								printf("\nE-mail inv�lida!");
					}while(strlen(email_vol[j]) <= 5);
				
				system("cls");
				
				// Imprime na tela os dados digitados para cadastro do volunt�rio
				
				printf("*****************************************************************\n");
				printf("******************  Cadastro de volunt�rio   ********************\n");	
				printf("*****************************************************************\n\n\n");
				
				printf("\nConfira os dados informados:\n\n");
				printf("\nNome: %s", nome_voluntario[j]);
				printf("\nTelefone: %s", tel_vol[j]);
				printf("\nCPF: %s", cpf_vol[j]);
				printf("\nSexo: %c", sexo_vol[j]);
				printf("\nEndere�o: %s - ", endereco_vol[j], bairro_vol[j]);
				printf("\n%s - %s", municipio_vol[j], uf_vol[j]);
				printf("\nCEP: %s", cep_vol[j]);							
				printf("\nData de Nascimento: %d/%d/%d", dia_nasc_vol[j], mes_nasc_vol[j], ano_nasc_vol[j]);							
				printf("\nE-mail: %s", email_vol[j]);	
				printf("\n\nOs dados informados est�o corretos [S|N]? ");
				scanf("%c", &sim_nao_vol);
				fflush(stdin);
				
				sim_nao_vol=toupper(sim_nao_vol);
				
					if(sim_nao_vol == 'N'){
						printf("\nFavor preencher novamente");
						system("cls");}
			}while(sim_nao_vol == 'N');
							
			aux_idade_vol = aux_idade_vol + idade_vol[j];
			aux_vol++;
			
			system("cls");
			
			printf("*****************************************************************\n");
			printf("*****************  Cadastro de volunt�rio   *********************\n");	
			printf("*****************************************************************\n\n\n");
			
			printf("Seu n�mero de cadastro �: %d\n", j);
		
			j++;
			
			break;
	case 3: printf("*****************************************************************\n");
			printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");	
			printf("*****************************************************************\n\n\n");
	
			printf("Informe se � cliente ou volunt�rio\n\n1 - Cliente\n\n2 - Volunt�rio\n\nInforme a op��o correta: ");
			scanf("%d", &opcao_atendimento);
			fflush(stdin);
			
				switch(opcao_atendimento){
					
					case 1: printf("\nInforme o seu n�mero de cadastro: ");
							scanf("%d", &i);
							fflush(stdin);
							
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");	
							printf("*****************************************************************\n\n\n");
							
							printf("Bem-vindo(a), Sr(a) %s\n", nome_cliente[i]);
							
							// captura a hora de inicializa��o do atendimento
							
							t= time(NULL);
							local=localtime(&t);
							
							hora_atend_cli[i]=local->tm_hour;
							min_atend_cli[i]=local->tm_min;
							seg_atend_cli[i]=local->tm_sec;
							
							printf("\nAtendimento iniciado!\n");
							
							system("pause");
							
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");
							printf("*****************************************************************\n");
							printf("***************************  Cliente  ***************************\n");	
							printf("*****************************************************************\n\n\n");
							
							
							do{							
								printf("\nPara confirmar a finaliza��o do atendimento digite 1\n\nDeseja finalizar? ");
								scanf("%d", &informa_fim_atend_cli);
								fflush(stdin);
									if(informa_fim_atend_cli != 1)
										printf("\nAtendimento n�o finalizado\n");
							}while(informa_fim_atend_cli != 1);
							
							// captura a hora de finalizaliza��o do atendimento
							
							t= time(NULL);
							local=localtime(&t);
														
							hora_atend_cli_fim[i]=local->tm_hour;
							min_atend_cli_fim[i]=local->tm_min;
							seg_atend_cli_fim[i]=local->tm_sec;
							
							duracao_atend_cli =duracao_atend_cli+((hora_atend_cli_fim[i]*60)+min_atend_cli_fim[i]+(seg_atend_cli_fim[i]/60))-((hora_atend_cli[i]*60)+min_atend_cli[i]+(seg_atend_cli[i]/60));
							
							dur_atend_cli_atual[i]=  ((hora_atend_cli_fim[i]*60)+min_atend_cli_fim[i]+(seg_atend_cli_fim[i]/60))-((hora_atend_cli[i]*60)+min_atend_cli[i]+(seg_atend_cli[i]/60));
														
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");
							printf("*****************************************************************\n");
							printf("***************************  Cliente  ***************************\n");	
							printf("*****************************************************************\n\n\n");
							
							do{
								printf("Dura��o do atendimento: %.1f minutos\n\n\nAvalia��o do atendimento Amigo Tech:\n",dur_atend_cli_atual[i]);
								printf("1 - P�ssimo\n2 - Razo�vel\n3 - Regular\n4 - Bom\n5 - Excelente\n\nInforme a nota para o Amigo Tech: ");
								scanf("%d", &nota_vol);
								fflush(stdin);
									if(nota_vol<1 && nota_vol >5)
										printf("\nNota Inv�lida!");
							}while(nota_vol<1 && nota_vol >5);
							
							total_nota_vol = total_nota_vol + nota_vol;
							
							aux_atend_cli++;
							
							printf("Obrigado por utilizar o Amigo Tech!\n\nAt� breve!\n");
							
							break;
							
					case 2: printf("\nInforme o seu n�mero de cadastro: ");
							scanf("%d", &i);
							fflush(stdin);
							
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");
							printf("*****************************************************************\n");
							printf("*************************  Volunt�rio  **************************\n");	
							printf("*****************************************************************\n\n\n");
							
							printf("Bem-vindo(a), %s\n", nome_voluntario[j]);
							
							// captura a hora de inicializa��o do atendimento
							
							t= time(NULL);
							local=localtime(&t);
							
							hora_atend_vol[j]=local->tm_hour;
							min_atend_vol[j]=local->tm_min;
							seg_atend_vol[j]=local->tm_sec;
							
							printf("\nAtendimento iniciado!\n");
							
							system("pause");
							
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");
							printf("*****************************************************************\n");
							printf("*************************  Volunt�rio  **************************\n");	
							printf("*****************************************************************\n\n\n");
							
							do{							
								printf("\nPara confirmar a finaliza��o do atendimento digite 1\n\nDeseja finalizar? ");
								scanf("%d", &informa_fim_atend_vol);
								fflush(stdin);
									if(informa_fim_atend_vol != 1)
										printf("\nAtendimento n�o finalizado\n");
							}while(informa_fim_atend_vol != 1);
							
							// captura a hora de finaliza��o do atendimento
							
							t= time(NULL);
							local=localtime(&t);
							
							hora_atend_vol_fim[j]=local->tm_hour;
							min_atend_vol_fim[j]=local->tm_min;
							seg_atend_vol_fim[j]=local->tm_sec;
							
							duracao_atend_vol =duracao_atend_vol+((hora_atend_vol_fim[j]*60)+min_atend_vol_fim[j]+(seg_atend_vol_fim[j]/60))-((hora_atend_vol[j]*60)+min_atend_vol[j]+(seg_atend_vol[j]/60));
							
							dur_atend_vol_atual[j] = ((hora_atend_vol_fim[j]*60)+min_atend_vol_fim[j]+(seg_atend_vol_fim[j]/60))-((hora_atend_vol[j]*60)+min_atend_vol[j]+(seg_atend_vol[j]/60));
							
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");
							printf("*****************************************************************\n");
							printf("*************************  Volunt�rio  **************************\n");	
							printf("*****************************************************************\n\n\n");
							
							printf("Dura��o do atendimento: %.1f minutos\n\n\nAt� o pr�ximo atendimento!\n",dur_atend_vol_atual[j]);
							
							aux_atend_vol++;
							
							break;
					default:printf("\nOp��o inv�lida!");
				};break;
	case 4: printf("*****************************************************************\n");
			printf("***********   Amigo Tech! - Portal do Funcion�rio  **************\n");	
			printf("*****************************************************************\n\n\n");
	
			printf("Favor informar a sua matr�cula: ");
			scanf("%d", &mat_funcionario);
			fflush(stdin);
			
			switch(mat_funcionario){
				case 1: strcpy(nome_funcionario, "Arthur Duarte");break;
				case 2: strcpy(nome_funcionario, "Gustavo Guntzel");break;
				case 3: strcpy(nome_funcionario, "Igor Ribeiro");break;
				case 4: strcpy(nome_funcionario, "Thiago Fernandes");break;
				case 5: strcpy(nome_funcionario, "Kassya Rosa");break;
				default:strcpy(nome_funcionario, "");
			};
			
			system("cls");
			
			do{			
				printf("*****************************************************************\n");
				printf("***********   Amigo Tech! - Portal do Funcion�rio  **************\n");	
				printf("*****************************************************************\n\n\n");
				
				printf("Bem-vindo(a), %s\n\n", nome_funcionario);
				printf("Deseja saber qual das informa��es abaixo: \n\n");
				printf("1 - M�dia da idade dos volunt�rios\n2 - M�dia da idade dos clientes\n3 - Quantidade de servi�os solicitados");
				printf("\n4 - M�dia nota de atendimento dos volunt�rios\n5 - Dura��o m�dia atendimento (Vis�o Clientes)");
				printf("\n6 - Dura��o m�dia atendimento (Vis�o Volunt�rios)\n\nInforme a op��o desejada: ");
				scanf("%d", &solicitacao_func);
				fflush(stdin);
				
				// C�lculo das a��es sobre as informa��es cadastradas
				
				if(aux_vol==0)
					media_idade_vol=0;
					else
						media_idade_vol = aux_idade_vol/aux_vol;
						
				if(aux_cli==0)
					media_idade_cli=0;
					else
						media_idade_cli = aux_idade_cli/aux_cli;
						
				if(aux_atend_cli==0)
					media_nota_vol=0;
					else 
						media_nota_vol = total_nota_vol/aux_atend_cli;
						
				if(aux_atend_cli==0)
					media_duracao_atende_cli=0;
					else 
						media_duracao_atende_cli = duracao_atend_cli/aux_atend_cli;
					
				if(aux_atend_vol==0)
					media_duracao_atende_vol=0;
					else 
						media_duracao_atende_vol = duracao_atend_vol/aux_atend_vol;
						
				switch(solicitacao_func){
					case 1:printf("\nA m�dia de idade dos volunt�rios cadastrados �: %.1f\n", media_idade_vol);break;
					case 2:printf("\nA m�dia de idade dos clientes cadastrados �: %.1f\n", media_idade_cli);break;
					case 3:printf("\nA quantidade de servi�os solicitados �: %d\n", qtde_servicos);break;
					case 4:printf("\nA nota m�dia de avalia��o dos volunt�rios �: %.1f\n", media_nota_vol);break;
					case 5:printf("\nA dura��o m�dia de atendimento na vis�o Cliente �: %.1f\n minutos", media_duracao_atende_cli);break;
					case 6:printf("\nA dura��o m�dia de atendimento na vis�o Volunt�rios �: %.1f\n minutos", media_duracao_atende_vol);break;
					default:printf("Op��o inv�lida!");
				}
				
				do{
					printf("\nDeseja voltar ao menu do funcion�rio ?[S|N]");
					scanf("%c", &aux_solicitacao_func);
					fflush(stdin);
					aux_solicitacao_func = toupper(aux_solicitacao_func); //Converte o caractere em mai�sculo
					if(aux_solicitacao_func != 'S' && aux_solicitacao_func != 'N')
						printf("\nOp��o inv�lida!");
				}while(aux_solicitacao_func != 'S' && aux_solicitacao_func != 'N');	
			
			system("cls");
				
			}while(aux_solicitacao_func != 'N');
						
	break;
	default: printf("Op��o Inv�lida!\n");
			
	}

system("pause");
system("cls");

	do{
			printf("\nDeseja voltar ao menu principal ?[S|N]\n");
			scanf("%c", &menu_princ);
			fflush(stdin);
			menu_princ = toupper(menu_princ);
			if(menu_princ != 'S' && menu_princ != 'N')
				printf("\nOp��o inv�lida!");
		}while(menu_princ != 'S' && menu_princ != 'N');	
		
	system("cls");
	
}while(menu_princ=='S');

system("cls");

printf("Programa finalizado");

return 0;
}
