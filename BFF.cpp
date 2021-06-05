// Cadastro no site Tech Friend ou Meu Amigo do TI ou Amigo Tech

#include<stdio.h> //biblioteca para printf e scanf 
#include<stdlib.h> //biblioteca para comandos Windows
#include<string.h> //biblioteca para strlen e strcmp: http://linguagemc.com.br/a-biblioteca-string-h/
#include<ctype.h> //biblioteca para o uso do toupper e tolower: http://linguagemc.com.br/ctype-h-toupper-tolower-isalpha-isdigit-em-c/
#include<locale.h> // biblioteca para utilizar acentuação do português: http://linguagemc.com.br/localizacao-de-programas-com-locale-h/
#include<time.h> // biblioteca para capturar a data do sistema: http://linguagemc.com.br/exibindo-data-e-hora-com-time-h/

int main(){
		setlocale(LC_ALL, "Portuguese");
		
struct tm *local; // ponteiro para struct que armazena data
time_t t;
t= time(NULL);
local=localtime(&t);// para converter para o tempo local utiliza-se a função localtime

int dia, mes, ano;

// para acessar os membros de uma struct usando o ponteiro utilizamos o operador -> no nosso caso temos: 
// local->membro_da_struct
// guardamos o valor em variáveis para poder utilizar no cálculo da idade

dia=local->tm_mday;
mes=local->tm_mon+1;
ano=local->tm_year+1900;

// nomes de variavel com significado (Código limpo)
		
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

// Utilizando o máximo de repetição para diminuir o tamanho do código (Código limpo)

do{// do-while para voltar ao menu principal
printf("*****************************************************************\n");// constrói o menu para o usuário
printf("****************   Bem-vindo ao Amigo Tech!   *******************\n");	
printf("*****************************************************************\n\n\n");

printf("Escolha uma das opções abaixo:\n\n");
printf("Você precisa de um Amigo Tech?\nDigite 1\n\n");
printf("Você gostaria de se tornar um Amigo Tech?\nDigite 2\n\n");
printf("Tenho um hoário agendado.\nDigite 3\n\n");
printf("Portal do Funcionário Amigo Tech\nDigite 4\n\n");
printf("Digite a opção desejada: ");
scanf("%d", &opcoes_iniciais);// guarda a informação da opção desejada do menu
fflush(stdin); // limpa o buffer de memória

system("cls"); // limpa a tela do terminal

switch(opcoes_iniciais){ // responsável por permitir o acesso ao próximo menu de opções
	
	case 1: printf("*****************************************************************\n");
			printf("*************   Amigo Tech! - Portal do Cliente  ****************\n");	
			printf("*****************************************************************\n\n\n");
	
	
			printf("Muito bem.\n\nDigite 1 se já for cadastrado\n\nDigite 2 para se cadastrar\n\nInforme a opção desejada: ");
			scanf("%d", &cliente_cadastrado);
			fflush(stdin);
			
			system("cls");
			
			switch(cliente_cadastrado){ 
				
				case 1: printf("*****************************************************************\n");
						printf("*************   Amigo Tech! - Portal do Cliente  ****************\n");	
						printf("*****************************************************************\n\n\n");
				
						printf("Entendido!\nVamos encontrar um amigo agora mesmo, mas para isso precisamos saber qual a ajuda que está precisando no momento.\n");
			
						printf("Escolha a opção desejada:\n\n");
						
						printf("Utilização de equipamentos eletrônicos\nDigite 1\n\nNavegar na Web\nDigite 2\n\nInstalação de equipamentos\nDigite 3\n\nCompanhia para jogos ou bate-papo\nDigite 4\n\nInforme a opção desejada: ");
						scanf("%d", &opcao_cliente);
						fflush(stdin);
							
							while(opcao_cliente<1 && opcao_cliente>4){// permite ao usuário corrigir caso tenho informado o valor errado	
								if(opcao_cliente<1 && opcao_cliente>4)
									printf("Opção Inválida!\n\nInforme a opção desejada: ");
									scanf("%d", &opcao_cliente);
									fflush(stdin);
								}
						
						system("cls");
						
						printf("*****************************************************************\n");
						printf("*************   Amigo Tech! - Portal do Cliente  ****************\n");	
						printf("*****************************************************************\n\n\n");
				
							if(opcao_cliente==1){printf("Para qual equipamento eletrônico necessita auxilio?\n\nComputador? Digite 1");
									printf("\nTV? Digite 2\nCelular? Digite 3\nEletrodomésticos? Digite 4\n\nInforme a opção desejada: ");
									scanf("%d", &escolha_quipamento);
									fflush(stdin);
									
									while(escolha_quipamento<1 && escolha_quipamento>4){
										if(escolha_quipamento<1 && escolha_quipamento>4)
											printf("Opção Inválida!\n\nInforme a opção desejada: ");
											scanf("%d", &escolha_quipamento);
											fflush(stdin);
										}
									
									qtde_servicos++; // Conta a quantidade de serviços solicitados
									}																											
							else {
								  printf("Iremos direcionar sua solicitação ao voluntário disponível \ne ele irá entrar em contato pelo seu telefone para agendar o dia e hora de atendimento");
								  printf("\nObrigado por utilizar os serviços da Amigo Tech!\n");
								  
								  qtde_servicos++;}
					
						break;
			
				case 2: do{ printf("*****************************************************************\n");
							printf("*******************  Cadastro de cliente   **********************\n");	
							printf("*****************************************************************\n\n\n");
								do{
								   
									printf("Qual é o seu nome completo?\n"); // Cadastrando o cliente no sistma
									fgets(nome_cliente[i],100,stdin);
									fflush(stdin);
										if(strlen(nome_cliente[i]) <= 6) // strlen: verifica o tamanho da string, se for menor ou igual a 6, apresenta o erro
											printf("\nNome inválido!\n");	// apresenta texto na tela	
								}while(strlen(nome_cliente[i]) <= 6);// repetição quando o nome for menor que 5 caracteres
								
								do{	
									printf("\nInforme seu telefone para contato com DDD: ");
									fgets(tel_cli[i],11,stdin);
									fflush(stdin);
										if(strlen(tel_cli[i]) <= 10)
											printf("\nLogradouro inválido!");
								}while(strlen(tel_cli[i]) <= 10);
								
								do{	
									printf("\nInforme seu endereço, Logradouro: ");
									fgets(endereco_cli[i],100,stdin);
									fflush(stdin);
										if(strlen(endereco_cli[i]) <= 1)
											printf("\nLogradouro inválido!");
								}while(strlen(endereco_cli[i]) <= 1);
								
								do{	
									printf("\nBairro: ");
									fgets(bairro_cli[i],20,stdin);
									fflush(stdin);
										if(strlen(bairro_cli[i]) <= 1)
											printf("\nBairro inválido!");
								}while(strlen(bairro_cli[i]) <= 1);
								
								do{
									printf("\nMunicípio: ");
									fgets(municipio_cli[i],50,stdin);
									fflush(stdin);
										if(strlen(municipio_cli[i]) <= 3)
											printf("\nMunicípio inválido!");
								}while(strlen(municipio_cli[i]) <= 3);
								
								do{
									printf("\nUF: ");
									fgets(uf_cli[i],5,stdin);
									fflush(stdin);
										if(strlen(uf_cli[i]) <= 2)
											printf("\nUF inválida!");
								}while(strlen(uf_cli[i]) <= 2);
								
								do{
									printf("\nCEP [11111-111]: ");
									fgets(cep_cli[i],10,stdin);
									fflush(stdin);
									
										if(strlen(cep_cli[i]) <= 8)
											printf("\nCEP inválida!");
								}while(strlen(cep_cli[i]) <= 8);
									
									printf("\nSexo [F|M]: ");
									scanf("%c", &sexo_cli[i]);
									fflush(stdin);
										sexo_cli[i] = toupper(sexo_cli[i]);
										
											do{// permite ao usuário corrigir caso tenha informado o valor errado
												if (sexo_cli[i]!= 'F'&& sexo_cli[i] != 'M'){ 
												printf("\nSexo inválido!\nInforme[F|M]: ");
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
													printf("\nDia inválido!\n");
									}while(dia_nasc_cli[i]<1 || dia_nasc_cli[i]>31);
									
									do{	
											printf("\nMês de nascimento: ");
											scanf("%d", &mes_nasc_cli[i]);
											fflush(stdin);
												if(mes_nasc_cli[i]<1 || mes_nasc_cli[i]>12)
												printf("\nMês inválido!");
									}while(mes_nasc_cli[i]<1 || mes_nasc_cli[i]>12);
					
										if((mes_nasc_cli[i] == 2|| mes_nasc_cli[i] ==4|| mes_nasc_cli[i] == 6|| mes_nasc_cli[i] == 9|| mes_nasc_cli[i] == 11) && dia_nasc_cli[i] == 31){
											printf("%d/%d não existe! Tente novamente\n", dia_nasc_cli[i], mes_nasc_cli[i]);
											dia_mes_cli = 1;}
											
										if(mes_nasc_cli[i] == 2 && dia_nasc_cli[i] == 30){
											printf("%d/%d não existe! Tente novamente\n", dia_nasc_cli[i], mes_nasc_cli[i]);
											dia_mes_cli = 1;}
								}while(dia_mes_cli==1);
								
								
								do{
									dta_nasc_cli=0;
										printf("\nAno de nascimento[AAAA]: ");
										scanf("%d", &ano_nasc_cli[i]);
										fflush(stdin);
										
											if(ano_nasc_cli[i]<1910 || ano_nasc_cli[i]>ano-16){
												printf("\nAno inválido!");
												dta_nasc_cli = 1;
											}
											if (mes_nasc_cli[i] == 2 && dia_nasc_cli[i] ==29){
												if((( ano_nasc_cli[i] % 4 == 0 && ano_nasc_cli[i] % 100 != 0 ) || ano_nasc_cli[i] % 400 == 0 )){
												}
											
											 else {
												printf("\n%d/%d/%d não é uma data válida.", dia_nasc_cli[i], mes_nasc_cli[i], ano_nasc_cli[i]);
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
											printf("\nCPF inválido!");
								}while(strlen(cpf_cli[i]) <= 14);
								
								do{	
									printf("\nInforme seu e-mail: ");
									fgets(email_cli[i],100,stdin);
									fflush(stdin);
										if(strlen(email_cli[i]) <= 5)
											printf("\nE-mail inválido!");
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
							printf("\nEndereço: %s - %s", endereco_cli[i], bairro_cli[i]);
							printf("\n%s - %s", municipio_cli[i], uf_cli[i]);
							printf("\nCEP: %s", cep_cli[i]);							
							printf("\nData de Nascimento: %d/%d/%d", dia_nasc_cli[i], mes_nasc_cli[i], ano_nasc_cli[i]);							
							printf("\nE-mail: %s", email_cli[i]);	
							printf("\n\nOs dados informados estão corretos [S|N]? ");
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
						
						printf("Seu número de cadastro é: %d\n", i);
						
						printf("\nVolte ao menu principal para solicitar o serviço como cliente cadastrado\n\n");
					
						i++;
				break;	
				default: printf("Opção inválida!\n");
			}
		;break;
		
	case 2: do{	printf("*****************************************************************\n");
				printf("******************  Cadastro de voluntário   ********************\n");	
				printf("*****************************************************************\n\n\n");
						
				printf("Ok!\nPreciso saber alguns dados...\n\n");
				do{
					printf("Qual é o seu nome completo?\n"); // Cadastrando o voluntário no sistma
						fgets(nome_voluntario[j],100,stdin);
						fflush(stdin);
							if(strlen(nome_voluntario[j]) <= 6) // strlen: verifica o tamanho da string, se for menor ou igual a 6, apresenta o erro
								printf("\nNome inválido!\n");	// apresenta texto na tela	
					}while(strlen(nome_voluntario[j]) <= 6);// repetição quando o nome for menor que 5 caracteres
					
					do{	
						printf("\nInforme seu telefone para contato com DDD: ");
						fgets(tel_vol[i],11,stdin);
						fflush(stdin);
							if(strlen(tel_vol[i]) <= 10)
								printf("\nLogradouro inválido!");
					}while(strlen(tel_vol[i]) <= 10);
					
					do{	
						printf("\nInforme seu endereço, Logradouro: ");
						fgets(endereco_vol[j],100,stdin);
						fflush(stdin);
							if(strlen(endereco_vol[j]) <= 1)
								printf("\nLogradouro inválido!");
					}while(strlen(endereco_vol[j]) <= 1);
					
					do{	
						printf("\nBairro: ");
						fgets(bairro_vol[j],20,stdin);
						fflush(stdin);
							if(strlen(bairro_vol[j]) <= 1)
								printf("\nBairro inválido!");
					}while(strlen(bairro_vol[j]) <= 1);
					
					do{
						printf("\nMunicípio: ");
						fgets(municipio_vol[j],50,stdin);
						fflush(stdin);
							if(strlen(municipio_vol[j]) <= 3)
								printf("\nMunicípio inválido!");
					}while(strlen(municipio_vol[j]) <= 3);
					
					do{
						printf("\nUF: ");
						fgets(uf_vol[j],5,stdin);
						fflush(stdin);
							if(strlen(uf_vol[j]) <= 2)
								printf("\nUF inválida!");
					}while(strlen(uf_vol[j]) <= 2);
					
					do{
						printf("\nCEP [11111-111]: ");
						fgets(cep_vol[j],10,stdin);
						fflush(stdin);
							if(strlen(cep_vol[j]) <= 8)
								printf("\nCEP inválida!");
					}while(strlen(cep_vol[j]) <= 8);
						
						printf("\nSexo [F|M]: ");
						scanf("%c", &sexo_vol[j]);
						fflush(stdin);
							sexo_vol[j] = toupper(sexo_vol[j]);
							
								do{// permite ao usuário corrigir caso tenha informado o valor errado
									if (sexo_vol[j]!= 'F'&& sexo_vol[j] != 'M'){ 
									printf("\nSexo inválido!\nInforme[F|M]: ");
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
										printf("\nDia inválido!\n");
						}while(dia_nasc_vol[j]<1 || dia_nasc_vol[j]>31);
						
						do{	
								printf("\nMês de nascimento: ");
								scanf("%d", &mes_nasc_vol[j]);
								fflush(stdin);
									if(mes_nasc_vol[j]<1 || mes_nasc_vol[j]>12)
									printf("\nMês inválido!");
						}while(mes_nasc_vol[j]<1 || mes_nasc_vol[j]>12);
		
							if((mes_nasc_vol[j] == 2|| mes_nasc_vol[j] ==4|| mes_nasc_vol[j] == 6|| mes_nasc_vol[j] == 9|| mes_nasc_vol[j] == 11) && dia_nasc_vol[j] == 31){
								printf("%d/%d não existe! Tente novamente\n", dia_nasc_vol[j], mes_nasc_vol[j]);
								dia_mes_vol = 1;}
								
							if(mes_nasc_vol[j] == 2 && dia_nasc_vol[j] == 30){
								printf("%d/%d não existe! Tente novamente\n", dia_nasc_vol[j], mes_nasc_vol[j]);
								dia_mes_vol = 1;}
					}while(dia_mes_vol==1);
					
					
					do{
						dta_nasc_vol=0;
							printf("\nAno de nascimento[AAAA]: ");
							scanf("%d", &ano_nasc_vol[j]);
							fflush(stdin);
							
								if(ano_nasc_vol[j]<1910 || ano_nasc_vol[j]>ano-16){
									printf("\nAno inválido!");
									dta_nasc_vol = 1;
								}
								if (mes_nasc_vol[j] == 2 && dia_nasc_vol[j] ==29){
									if((( ano_nasc_vol[j] % 4 == 0 && ano_nasc_vol[j] % 100 != 0 ) || ano_nasc_vol[j] % 400 == 0 )){
									}
								
								 else {
									printf("\n%d/%d/%d não é uma data válida.", dia_nasc_vol[j], mes_nasc_vol[j], ano_nasc_vol[j]);
									dta_nasc_vol=1;
								}}
					}while(dta_nasc_vol==1);
						
								// calculando a idade do voluntário
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
								printf("\nCEP inválida!");
					}while(strlen(cpf_vol[j]) <= 14);
					
					do{	
						printf("\nInforme seu e-mail: ");
						fgets(email_vol[j],100,stdin);
						fflush(stdin);
							if(strlen(email_vol[j]) <= 5)
								printf("\nE-mail inválida!");
					}while(strlen(email_vol[j]) <= 5);
				
				system("cls");
				
				// Imprime na tela os dados digitados para cadastro do voluntário
				
				printf("*****************************************************************\n");
				printf("******************  Cadastro de voluntário   ********************\n");	
				printf("*****************************************************************\n\n\n");
				
				printf("\nConfira os dados informados:\n\n");
				printf("\nNome: %s", nome_voluntario[j]);
				printf("\nTelefone: %s", tel_vol[j]);
				printf("\nCPF: %s", cpf_vol[j]);
				printf("\nSexo: %c", sexo_vol[j]);
				printf("\nEndereço: %s - ", endereco_vol[j], bairro_vol[j]);
				printf("\n%s - %s", municipio_vol[j], uf_vol[j]);
				printf("\nCEP: %s", cep_vol[j]);							
				printf("\nData de Nascimento: %d/%d/%d", dia_nasc_vol[j], mes_nasc_vol[j], ano_nasc_vol[j]);							
				printf("\nE-mail: %s", email_vol[j]);	
				printf("\n\nOs dados informados estão corretos [S|N]? ");
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
			printf("*****************  Cadastro de voluntário   *********************\n");	
			printf("*****************************************************************\n\n\n");
			
			printf("Seu número de cadastro é: %d\n", j);
		
			j++;
			
			break;
	case 3: printf("*****************************************************************\n");
			printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");	
			printf("*****************************************************************\n\n\n");
	
			printf("Informe se é cliente ou voluntário\n\n1 - Cliente\n\n2 - Voluntário\n\nInforme a opção correta: ");
			scanf("%d", &opcao_atendimento);
			fflush(stdin);
			
				switch(opcao_atendimento){
					
					case 1: printf("\nInforme o seu número de cadastro: ");
							scanf("%d", &i);
							fflush(stdin);
							
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");	
							printf("*****************************************************************\n\n\n");
							
							printf("Bem-vindo(a), Sr(a) %s\n", nome_cliente[i]);
							
							// captura a hora de inicialização do atendimento
							
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
								printf("\nPara confirmar a finalização do atendimento digite 1\n\nDeseja finalizar? ");
								scanf("%d", &informa_fim_atend_cli);
								fflush(stdin);
									if(informa_fim_atend_cli != 1)
										printf("\nAtendimento não finalizado\n");
							}while(informa_fim_atend_cli != 1);
							
							// captura a hora de finalizalização do atendimento
							
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
								printf("Duração do atendimento: %.1f minutos\n\n\nAvaliação do atendimento Amigo Tech:\n",dur_atend_cli_atual[i]);
								printf("1 - Péssimo\n2 - Razoável\n3 - Regular\n4 - Bom\n5 - Excelente\n\nInforme a nota para o Amigo Tech: ");
								scanf("%d", &nota_vol);
								fflush(stdin);
									if(nota_vol<1 && nota_vol >5)
										printf("\nNota Inválida!");
							}while(nota_vol<1 && nota_vol >5);
							
							total_nota_vol = total_nota_vol + nota_vol;
							
							aux_atend_cli++;
							
							printf("Obrigado por utilizar o Amigo Tech!\n\nAté breve!\n");
							
							break;
							
					case 2: printf("\nInforme o seu número de cadastro: ");
							scanf("%d", &i);
							fflush(stdin);
							
							system("cls");
							
							printf("*****************************************************************\n");
							printf("***********   Amigo Tech! - Portal de Atendimento  **************\n");
							printf("*****************************************************************\n");
							printf("*************************  Voluntário  **************************\n");	
							printf("*****************************************************************\n\n\n");
							
							printf("Bem-vindo(a), %s\n", nome_voluntario[j]);
							
							// captura a hora de inicialização do atendimento
							
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
							printf("*************************  Voluntário  **************************\n");	
							printf("*****************************************************************\n\n\n");
							
							do{							
								printf("\nPara confirmar a finalização do atendimento digite 1\n\nDeseja finalizar? ");
								scanf("%d", &informa_fim_atend_vol);
								fflush(stdin);
									if(informa_fim_atend_vol != 1)
										printf("\nAtendimento não finalizado\n");
							}while(informa_fim_atend_vol != 1);
							
							// captura a hora de finalização do atendimento
							
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
							printf("*************************  Voluntário  **************************\n");	
							printf("*****************************************************************\n\n\n");
							
							printf("Duração do atendimento: %.1f minutos\n\n\nAté o próximo atendimento!\n",dur_atend_vol_atual[j]);
							
							aux_atend_vol++;
							
							break;
					default:printf("\nOpção inválida!");
				};break;
	case 4: printf("*****************************************************************\n");
			printf("***********   Amigo Tech! - Portal do Funcionário  **************\n");	
			printf("*****************************************************************\n\n\n");
	
			printf("Favor informar a sua matrícula: ");
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
				printf("***********   Amigo Tech! - Portal do Funcionário  **************\n");	
				printf("*****************************************************************\n\n\n");
				
				printf("Bem-vindo(a), %s\n\n", nome_funcionario);
				printf("Deseja saber qual das informações abaixo: \n\n");
				printf("1 - Média da idade dos voluntários\n2 - Média da idade dos clientes\n3 - Quantidade de serviços solicitados");
				printf("\n4 - Média nota de atendimento dos voluntários\n5 - Duração média atendimento (Visão Clientes)");
				printf("\n6 - Duração média atendimento (Visão Voluntários)\n\nInforme a opção desejada: ");
				scanf("%d", &solicitacao_func);
				fflush(stdin);
				
				// Cálculo das ações sobre as informações cadastradas
				
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
					case 1:printf("\nA média de idade dos voluntários cadastrados é: %.1f\n", media_idade_vol);break;
					case 2:printf("\nA média de idade dos clientes cadastrados é: %.1f\n", media_idade_cli);break;
					case 3:printf("\nA quantidade de serviços solicitados é: %d\n", qtde_servicos);break;
					case 4:printf("\nA nota média de avaliação dos voluntários é: %.1f\n", media_nota_vol);break;
					case 5:printf("\nA duração média de atendimento na visão Cliente é: %.1f\n minutos", media_duracao_atende_cli);break;
					case 6:printf("\nA duração média de atendimento na visão Voluntários é: %.1f\n minutos", media_duracao_atende_vol);break;
					default:printf("Opção inválida!");
				}
				
				do{
					printf("\nDeseja voltar ao menu do funcionário ?[S|N]");
					scanf("%c", &aux_solicitacao_func);
					fflush(stdin);
					aux_solicitacao_func = toupper(aux_solicitacao_func); //Converte o caractere em maiúsculo
					if(aux_solicitacao_func != 'S' && aux_solicitacao_func != 'N')
						printf("\nOpção inválida!");
				}while(aux_solicitacao_func != 'S' && aux_solicitacao_func != 'N');	
			
			system("cls");
				
			}while(aux_solicitacao_func != 'N');
						
	break;
	default: printf("Opção Inválida!\n");
			
	}

system("pause");
system("cls");

	do{
			printf("\nDeseja voltar ao menu principal ?[S|N]\n");
			scanf("%c", &menu_princ);
			fflush(stdin);
			menu_princ = toupper(menu_princ);
			if(menu_princ != 'S' && menu_princ != 'N')
				printf("\nOpção inválida!");
		}while(menu_princ != 'S' && menu_princ != 'N');	
		
	system("cls");
	
}while(menu_princ=='S');

system("cls");

printf("Programa finalizado");

return 0;
}
