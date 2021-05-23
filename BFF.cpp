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
		
int i,opcoes_iniciais, opcao_cliente, opcao_voluntario, opcao_funcionario, mat_funcionario, id_vol, id_cli, dia_nasc_vol[10], dia_nasc_cli[10], dia_nasc_func;
int mes_nasc_vol[10], mes_nasc_cli[10], mes_nasc_func, ano_nasc_vol[10], ano_nasc_cli[10], ano_nasc_func, idade_vol[10], idade_cli[10], idade_func;
int escolha_quipamento, cliente_cadastrado, cadastro_vol, cadastro_cli, qtde_servicos=0, solicitacao_func, opcao_atendimento, informa_fim_atend_cli, informa_fim_atend_vol;
int aux_idade_vol=0, aux_vol=0, aux_idade_cli=0, aux_cli=0, aux_servico, dta_nasc_cli, dta_nasc_vol, dta_nasc_funci, dia_mes_cli, dia_mes_vol, dia_mes_func;
int duracao_atend_cli, duracao_atend_vol;
int dia_atend_cli[i], mes_atend_cli[i], ano_atend_cli[i], hora_atend_cli[i], min_atend_cli[i], seg_atend_cli[i];
int dia_atend_vol[i], mes_atend_vol[i], ano_atend_vol[i], hora_atend_vol[i], min_atend_vol[i], seg_atend_vol[i];
int dia_atend_cli_fim[i], mes_atend_cli_fim[i], ano_atend_cli_fim[i], hora_atend_cli_fim[i], min_atend_cli_fim[i], seg_atend_cli_fim[i];
int dia_atend_vol_fim[i], mes_atend_vol_fim[i], ano_atend_vol_fim[i], hora_atend_vol_fim[i], min_atend_vol_fim[i], seg_atend_vol_fim[i];
float media_idade_vol, media_idade_cli;
char sexo_vol[10], sexo_cli[10], menu_princ, sim_nao_vol, sim_nao_cli, sim_nao_func;
char nome_voluntario[10][100], nome_cliente[10][100], nome_funcionario[100], endereco_vol[10][100], endereco_cli[10][100], endereco_func[100];
char bairro_vol[10][20], bairro_cli[10][20], bairro_func[20], municipio_vol[10][50], municipio_cli[10][50], municipio_func[50], uf_vol[10][3], uf_cli[10][3], uf_func[3];
char cep_vol[10][10], cep_cli[10][10], cep_func[10], cpf_vol[10][11], cpf_cli[10][11], cpf_func[11], email_vol[10][100], email_cli[10][100], email_func[100];

do{// do-while para voltar ao menu
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
	
	case 1: printf("Muito bem.\n\nDigite 1 se já for cadastrado\n\nDigite 2 para se cadastrar\n\nInforme a opção desejada: ");
			scanf("%d", &cliente_cadastrado);
			fflush(stdin);
			
			system("cls");
			
			switch(cliente_cadastrado){ // responsável por permitir o acesso ao próximo menu de opções
				
				case 1: printf("Entendido!\nVamos encontrar um amigo agora mesmo, mas para isso precisamos saber qual a ajuda que está precisando no momento.\n");
			
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
				
				if(opcao_cliente==1){printf("Para qual equipamento eletrônico necessita auxilio?\n\nComputador? Digite 1");
									printf("\nTV? Digite 2\nCelular? Digite 3\nEletrodomésticos? Digite 4\n\nInforme a opção desejada: ");
									scanf("%d", &escolha_quipamento);
									fflush(stdin);
									
									while(escolha_quipamento<1 && escolha_quipamento>4){// permite ao usuário corrigir caso tenho informado o valor errado	
										if(escolha_quipamento<1 && escolha_quipamento>4)
											printf("Opção Inválida!\n\nInforme a opção desejada: ");
											scanf("%d", &escolha_quipamento);
											fflush(stdin);
										}
									
									qtde_servicos++; // Conta a quantidade de serviços solicitados
									}																											
							else { system("cls");
								  printf("Iremos direcionar sua solicitação ao voluntário disponível \ne ele irá entrar em contato pelo seu telefone para agendar o dia e hora de atendimento");
								  printf("\nObrigado por utilizar os serviços da Amigo Tech!\n");
								  
								  qtde_servicos++;}
						system("cls");
						printf("Iremos direcionar sua solicitação ao voluntário disponível \ne ele irá entrar em contato pelo seu telefone para agendar o dia e hora de atendimento");
						printf("\nObrigado por utilizar os serviços da Amigo Tech!\n");break;
			
				case 2: i = 1;
				
						do{	
						if(i == 1){
							
							do{
								do{
									printf("Qual é o seu nome completo?\n"); // Cadastrando o voluntário no sistma
									fgets(nome_cliente[i],100,stdin);
									fflush(stdin);
										if(strlen(nome_cliente[i]) <= 6) // strlen: verifica o tamanho da string, se for menor ou igual a 6, apresenta o erro
											printf("\nNome inválido!\n");	// apresenta texto na tela	
								}while(strlen(nome_cliente[i]) <= 6);// repetição quando o nome for menor que 5 caracteres
								
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
									fgets(uf_cli[i],3,stdin);
									fflush(stdin);
									
									printf("\nTamanho UF: %d", strlen(uf_cli[i]));
									
										if(strlen(uf_cli[i]) <= 1)
											printf("\nUF inválida!");
								}while(strlen(uf_cli[i]) <= 1);
								
								do{
									printf("\nCEP [11111-111]: ");
									fgets(cep_cli[i],10,stdin);
									fflush(stdin);
									
										printf("\nTamanho CEP: %d", strlen(cep_cli[i]));
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
									
											// calculando a idade do voluntário
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
											printf("\nCEP inválida!");
								}while(strlen(cpf_cli[i]) <= 14);
								
								do{	
									printf("\nInforme seu e-mail: ");
									fgets(email_cli[i],100,stdin);
									fflush(stdin);
										if(strlen(email_cli[i]) <= 5)
											printf("\nE-mail inválida!");
								}while(strlen(email_cli[i]) <= 5);
								
									aux_idade_cli = aux_idade_cli + idade_cli[i];
									aux_cli++;
									
							printf("\nConfira os dados informados:\n\n");
							printf("\nNome: %s", nome_voluntario[i]);
							printf("\nCPF: %s", cpf_vol[i]);
							printf("\nSexo: %c", sexo_vol[i]);
							printf("\nEndereço: %s - ", endereco_vol[i], bairro_vol[i]);
							printf("\n%s - %s", municipio_vol[i], uf_vol[i]);
							printf("\nCEP: %s", cep_vol[i]);							
							printf("\nData de Nascimento: %d/%d/%d", dia_nasc_vol[i], mes_nasc_vol[i], ano_nasc_vol[i]);							
							printf("\nE-mail: %s", email_vol[i]);	
							printf("\n\nOs dados informados estão corretos [S|N]? ");
							scanf("%c", &sim_nao_cli);
							fflush(stdin);
							
							sim_nao_cli=toupper(sim_nao_cli);
							
								if(sim_nao_cli == 'N'){
									printf("\nFavor preencher novamente");
									system("cls");}
						}while(sim_nao_cli == 'N');
						
						}
						i=0;
						
						system("cls");
						
						printf("Volte ao menu principal para solicitar o serviço como cliente cadastrado\n\n");
						
					}while(i==1);
				break;	
				default: printf("Opção inválida!");
			}
		;break;
		
	case 2: printf("Ok!\nPreciso saber alguns dados...\n\n");
			i = 1;
						
			do{	
				if(i == 1){
						do{	
							do{
								printf("Qual é o seu nome completo?\n"); // Cadastrando o voluntário no sistma
									fgets(nome_voluntario[i],100,stdin);
									fflush(stdin);
										if(strlen(nome_voluntario[i]) <= 6) // strlen: verifica o tamanho da string, se for menor ou igual a 6, apresenta o erro
											printf("\nNome inválido!\n");	// apresenta texto na tela	
								}while(strlen(nome_voluntario[i]) <= 6);// repetição quando o nome for menor que 5 caracteres
								
								do{	
									printf("\nInforme seu endereço, Logradouro: ");
									fgets(endereco_vol[i],100,stdin);
									fflush(stdin);
										if(strlen(endereco_vol[i]) <= 1)
											printf("\nLogradouro inválido!");
								}while(strlen(endereco_vol[i]) <= 1);
								
								do{	
									printf("\nBairro: ");
									fgets(bairro_vol[i],20,stdin);
									fflush(stdin);
										if(strlen(bairro_vol[i]) <= 1)
											printf("\nBairro inválido!");
								}while(strlen(bairro_vol[i]) <= 1);
								
								do{
									printf("\nMunicípio: ");
									fgets(municipio_vol[i],50,stdin);
									fflush(stdin);
										if(strlen(municipio_vol[i]) <= 3)
											printf("\nMunicípio inválido!");
								}while(strlen(municipio_vol[i]) <= 3);
								
								do{
									printf("\nUF: ");
									fgets(uf_vol[i],3,stdin);
									fflush(stdin);
									
									printf("\nTamanho UF: %d", strlen(uf_vol[i]));
									
										if(strlen(uf_vol[i]) <= 1)
											printf("\nUF inválida!");
								}while(strlen(uf_vol[i]) <= 1);
								
								do{
									printf("\nCEP [11111-111]: ");
									fgets(cep_vol[i],10,stdin);
									fflush(stdin);
									
										printf("\nTamanho CEP: %d", strlen(cep_vol[i]));
										if(strlen(cep_vol[i]) <= 8)
											printf("\nCEP inválida!");
								}while(strlen(cep_vol[i]) <= 8);
									
									printf("\nSexo [F|M]: ");
									scanf("%c", &sexo_vol[i]);
									fflush(stdin);
										sexo_vol[i] = toupper(sexo_vol[i]);
										
											do{// permite ao usuário corrigir caso tenha informado o valor errado
												if (sexo_vol[i]!= 'F'&& sexo_vol[i] != 'M'){ 
												printf("\nSexo inválido!\nInforme[F|M]: ");
												scanf("%c", &sexo_vol[i]);
												fflush(stdin);
												sexo_vol[i] = toupper(sexo_vol[i]);
											}}while(sexo_vol[i]!= 'F'&& sexo_vol[i] != 'M');
								
								do{
									dia_mes_vol=0;
									do{	
										printf("\nDia de nascimento: ");
										scanf("%d",&dia_nasc_vol[i]);
										fflush(stdin);
												if(dia_nasc_vol[i]<1 || dia_nasc_vol[i]>31)
													printf("\nDia inválido!\n");
									}while(dia_nasc_vol[i]<1 || dia_nasc_vol[i]>31);
									
									do{	
											printf("\nMês de nascimento: ");
											scanf("%d", &mes_nasc_vol[i]);
											fflush(stdin);
												if(mes_nasc_vol[i]<1 || mes_nasc_vol[i]>12)
												printf("\nMês inválido!");
									}while(mes_nasc_vol[i]<1 || mes_nasc_vol[i]>12);
					
										if((mes_nasc_vol[i] == 2|| mes_nasc_vol[i] ==4|| mes_nasc_vol[i] == 6|| mes_nasc_vol[i] == 9|| mes_nasc_vol[i] == 11) && dia_nasc_vol[i] == 31){
											printf("%d/%d não existe! Tente novamente\n", dia_nasc_vol[i], mes_nasc_vol[i]);
											dia_mes_vol = 1;}
											
										if(mes_nasc_vol[i] == 2 && dia_nasc_vol[i] == 30){
											printf("%d/%d não existe! Tente novamente\n", dia_nasc_vol[i], mes_nasc_vol[i]);
											dia_mes_vol = 1;}
								}while(dia_mes_vol==1);
								
								
								do{
									dta_nasc_vol=0;
										printf("\nAno de nascimento[AAAA]: ");
										scanf("%d", &ano_nasc_vol[i]);
										fflush(stdin);
										
											if(ano_nasc_vol[i]<1910 || ano_nasc_vol[i]>ano-16){
												printf("\nAno inválido!");
												dta_nasc_vol = 1;
											}
											if (mes_nasc_vol[i] == 2 && dia_nasc_vol[i] ==29){
												if((( ano_nasc_vol[i] % 4 == 0 && ano_nasc_vol[i] % 100 != 0 ) || ano_nasc_vol[i] % 400 == 0 )){
												}
											
											 else {
												printf("\n%d/%d/%d não é uma data válida.", dia_nasc_vol[i], mes_nasc_vol[i], ano_nasc_vol[i]);
												dta_nasc_vol=1;
											}}
								}while(dta_nasc_vol==1);
									
											// calculando a idade do voluntário
												idade_vol[i] = ano-ano_nasc_vol[i];
													
													if(mes_nasc_vol[i]>mes)
														idade_vol[i] = idade_vol[i]-1;
														else if(mes_nasc_vol[i]==mes){
																if(dia_nasc_vol[i]>dia)
																idade_vol[i] = idade_vol[i]-1;
																else idade_vol[i]=idade_vol[i];
															}
															else idade_vol[i]=idade_vol[i];
								do{	
									printf("\nInforme o seu CPF [xxx.xxx.xxx-xx]: ");
									fgets(cpf_vol[i],16,stdin);
									fflush(stdin);
										if(strlen(cpf_vol[i]) <= 14)
											printf("\nCEP inválida!");
								}while(strlen(cpf_vol[i]) <= 14);
								
								do{	
									printf("\nInforme seu e-mail: ");
									fgets(email_vol[i],100,stdin);
									fflush(stdin);
										if(strlen(email_vol[i]) <= 5)
											printf("\nE-mail inválida!");
								}while(strlen(email_vol[i]) <= 5);
							
							aux_idade_vol = aux_idade_vol + idade_vol[i];
							aux_vol++;
							
							printf("\nConfira os dados informados:\n\n");
							printf("\nNome: %s", nome_voluntario[i]);
							printf("\nCPF: %s", cpf_vol[i]);
							printf("\nSexo: %c", sexo_vol[i]);
							printf("\nEndereço: %s - ", endereco_vol[i], bairro_vol[i]);
							printf("\n%s - %s", municipio_vol[i], uf_vol[i]);
							printf("\nCEP: %s", cep_vol[i]);							
							printf("\nData de Nascimento: %d/%d/%d", dia_nasc_vol[i], mes_nasc_vol[i], ano_nasc_vol[i]);							
							printf("\nE-mail: %s", email_vol[i]);	
							printf("\n\nOs dados informados estão corretos [S|N]? ");
							scanf("%c", &sim_nao_vol);
							fflush(stdin);
							
							sim_nao_vol=toupper(sim_nao_vol);
							
								if(sim_nao_vol == 'N'){
									printf("\nFavor preencher novamente");
									system("cls");}
						}while(sim_nao_vol == 'N');
							
				}
				i=0;
			}while(i==1);
			
			break;
	case 3: printf("Informe se é cliente ou volutário\n\n1 - CLiente\n\n2 - Voluntário\n\nInforme a opção correta: ");
			scanf("%d", &opcao_atendimento);
			fflush(stdin);
			
				switch(opcao_atendimento){
					
					case 1: printf("\nInforme o seu número de cadastro: ");
							scanf("%d", &i);
							fflush(stdin);
							
							printf("\nAtendimento iniciado!");
							
							
							t= time(NULL);
							local=localtime(&t);
							
							dia_atend_cli[i]=local->tm_mday;
							mes_atend_cli[i]=local->tm_mon+1;
							ano_atend_cli[i]=local->tm_year+1900;
							hora_atend_cli[i]=local->tm_hour;
							min_atend_cli[i]=local->tm_min;
							seg_atend_cli[i]=local->tm_sec;
							
							system("cls");
							
							do{							
								printf("\nPara confirmar a finalização do atendimento digite 1");
								scanf("%d", &informa_fim_atend_cli);
								fflush(stdin);
									if(informa_fim_atend_cli != 1)
										printf("\nAtendimento não finalizado, digite 1 para finalizar");
							}while(informa_fim_atend_cli != 1);
							
							t= time(NULL);
							local=localtime(&t);
														
							dia_atend_cli_fim[i]=local->tm_mday;
							mes_atend_cli_fim[i]=local->tm_mon+1;
							ano_atend_cli_fim[i]=local->tm_year+1900;
							hora_atend_cli_fim[i]=local->tm_hour;
							min_atend_cli_fim[i]=local->tm_min;
							seg_atend_cli_fim[i]=local->tm_sec;
							
							duracao_atend_cli = (((hora_atend_cli_fim[i]*60)+min_atend_cli_fim[i] +(seg_atend_cli_fim[i]/60))-((hora_atend_cli[i]*60)+min_atend_cli_fim[i]+(seg_atend_cli[i]/60)));
							break;
							
					case 2: printf("\nInforme o seu número de cadastro: ");
							scanf("%d", &i);
							fflush(stdin);
							
							printf("\nAtendimento iniciado!");
							
							t= time(NULL);
							local=localtime(&t);
							
							dia_atend_vol[i]=local->tm_mday;
							mes_atend_vol[i]=local->tm_mon+1;
							ano_atend_vol[i]=local->tm_year+1900;
							hora_atend_vol[i]=local->tm_hour;
							min_atend_vol[i]=local->tm_min;
							seg_atend_vol[i]=local->tm_sec;
							
							system("cls");
							
							do{							
								printf("\nPara confirmar a finalização do atendimento digite 1");
								scanf("%d", &informa_fim_atend_vol);
								fflush(stdin);
									if(informa_fim_atend_vol != 1)
										printf("\nAtendimento não finalizado, digite 1 para finalizar");
							}while(informa_fim_atend_vol != 1);
							
							t= time(NULL);
							local=localtime(&t);
							
							dia_atend_vol_fim[i]=local->tm_mday;
							mes_atend_vol_fim[i]=local->tm_mon+1;
							ano_atend_vol_fim[i]=local->tm_year+1900;
							hora_atend_vol_fim[i]=local->tm_hour;
							min_atend_vol_fim[i]=local->tm_min;
							seg_atend_vol_fim[i]=local->tm_sec;
							
							duracao_atend_vol = (((hora_atend_vol_fim[i]*60)+min_atend_vol_fim[i] +(seg_atend_vol_fim[i]/60))-((hora_atend_vol[i]*60)+min_atend_vol_fim[i]+(seg_atend_vol[i]/60)));
							break;
					default:printf("\nOpção inválida!");
				};
	case 4: printf("Favor informar a sua matrícula: ");
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
			printf("Deseja saber qual das informações abaixo: \n\n1 - Média da idade dos voluntário\n2 - Média da idade dos clientes\n3 - Quantidade de serviços solicitados\n\nInforme a opção desejada: ");
			scanf("%d", &solicitacao_func);
			fflush(stdin);
			
			media_idade_vol = aux_idade_vol/aux_vol;
			media_idade_cli = aux_idade_cli/aux_cli;
						
			if(solicitacao_func==1)
				printf("\nA média de idade dos voluntários cadastrados é: %.1f\n", media_idade_vol);
				else if(solicitacao_func==2)
					printf("\nA média de idade dos clientes cadastrados é: %.1f\n", media_idade_cli);
					else printf("\nA quantidade de serviços solicitados é: %d\n", qtde_servicos);
					
			system("pause");
			
			break;
	default: printf("Opção Inválida!\n");
			
			}

system("pause");
system("cls");

	do{
			printf("\nDeseja voltar ao menu principal ?[S|N]\n");
			scanf("%c", &menu_princ);
			fflush(stdin);
			menu_princ = toupper(menu_princ); //Converte o caractere em maiúsculo
			if(menu_princ != 'S' && menu_princ != 'N')
				printf("\nOpção inválida!");
		}while(menu_princ != 'S' && menu_princ != 'N');	
		
		i++;		
	
	system("cls");
	
}while(menu_princ=='S');

system("pause");
system("cls");

printf("Programa finalizado");

return 0;
}
