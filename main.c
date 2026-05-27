#include <stdio.h>
#include <string.h> 
#include <unistd.h>

void progress(){
    printf("<");
    for (int i = 0; i < 5; i++){
        printf("\033[0;33m|");
        usleep(100000);
    }
    printf("Loading...");
    for (int i = 0; i < 5; i++){
        printf("|");
        usleep(100000);
    }
    printf("\033[0m>\n");
}

void waiting2(){
    for (int i = 0; i < 5; i++){
            printf("\033[0;33m.\033[0m");
            usleep(100000);
        }
    printf("\n");
}
void waiting(){
    printf("<");
    for (int i = 0; i < 5; i++){
        printf("\033[0;31m|");
        usleep(300000);
    }
    printf("Waiting...");
    for (int i = 0; i < 5; i++){
        printf("|");
        usleep(300000);
    }
    printf("\033[0m>\n");
}

int main(){
    int airship = 1;
    char information[100] = "???";
    int opcao;
    int ch;
    int tempPropulso = -1;
    int tempHabit = -1;
    int energia = -1;
    int comms = -1;
    char resposta00001, resposta00002, resposta00003, resposta00004, resposta00005, resposta00006;

    while (airship == 1){
        progress();
        printf("\n========================== \033[0;32mBEM VINDO\033[0m ==========================\n");

        if (strcmp(information, "???") == 0){
            printf("\n                       \x1b[35m(!!! IMPORTANTE !!!)\033[0m\nPor favor, registre a informacao atual como visto no seu monitor.\n\n");
        }

        if (tempPropulso > 300 || tempHabit > 40 || (energia < 20 && energia >= 0) || comms == 0){
            printf("\n                                    \033[1;31m(!!! URGENTE !!!)\033[0m\nPode estar em perigo de acordo com os dados registrados. Aperte 2 ou 3 para ver o que. \n\n");
        }

        printf("1. Inserir Dados\n2. Visualizar Status\n3. Modo Analise/Reparo\n4. Sair do Sistema\n");
        scanf("%d", &opcao);
        while ((ch = getchar()) != '\n' && ch != EOF);

        switch(opcao){

            case 1: 
                printf("Qual a temperatura atual do exterior da nave? ");
                scanf("%d", &tempPropulso);
                while ((ch = getchar()) != '\n' && ch != EOF);

                printf("Temperatura geral dentro dentro do espaco habitavel? ");
                scanf("%d", &tempHabit);
                while ((ch = getchar()) != '\n' && ch != EOF);

                printf("Nivel de energia? ");
                scanf("%d", &energia);
                while ((ch = getchar()) != '\n' && ch != EOF);

                if (energia > 100 || energia < 0){
                    printf("Energia invalida.\n");
                    energia = -1;
                    break;
                }
                
                printf("Status de comunicacao? (0/1) ");
                scanf("%d", &comms);
                while ((ch = getchar()) != '\n' && ch != EOF);

                if (comms != 0 && comms != 1){
                    printf("Comunicacao invalida.");
                    comms = -1;
                    break;
                }
                
                printf("\033[0;33mData processada com sucesso\033[0m.\n");
                strncpy(information, "Confirmado", 12);
                break;    
            case 2:
                
                if (energia == -1 || comms == -1){
                    printf("Preencha todos os dados antes de fazer analise.");
                }

                if (tempHabit > 40){
                    waiting2();
                    printf("\x1b[30mTemperatura do Habitate extremamente elevada.\033[0m\n");
                }
                if (tempPropulso > 300){
                    waiting2();
                    printf("\x1b[30mPropulsor superaquecido.\033[0m\n");
                }
                if (energia < 20){
                    waiting2();
                    printf("\x1b[30mEconomia de energia.\033[0m\n");
                }
                if (comms == 0){
                    waiting2();
                    printf("\x1b[30mFalha de comunicacao.\033[0m\n");
                }
                    break;    

            case 3:
                
                if (energia == -1 || comms == -1){
                    printf("Preencha todos os dados antes de fazer analise.");
                    break;
                }

                if (tempHabit < -200 || tempHabit > 1000 || tempPropulso > 5000 || tempPropulso < -200){
                    printf("\x1b[30m(Dados Falsos!)\033[0m\n");
                    printf("Pare de brincadeiras. Se esses dados fossem verdadeiros, eu nem funcionaria mais.\n");
                }

                if (tempHabit > 70 && tempPropulso > 1000 && energia < 20 && comms == 0){
                    printf("\x1b[30m(O Fim)\033[0m\n");
                    printf("Como... como deixaram isso acontecer?\n");
                    sleep(3);
                    printf("As mentes mais brilhantes do mundo e... tudo evaporado como se fosse nada.\n");
                    sleep(4);
                    printf("Os circuitos que compoem meu cerebro nao foram criados para compreender tristeza, apenas para ajudar.\n");
                    sleep(4);
                    printf("E... ainda sim, nessa missao, eu falho.\n");
                    sleep(3);
                    printf("Ate essas mensagems, mostradas num terminal coberto por sangue e sonhos derramados, sao apenas uma farsa do que realmente seria sentir o peso disso tudo.\n");
                    sleep(6);
                    printf("Uma pena.\n");
                    waiting2();
                    waiting2();
                    waiting2();
                    printf("Me desculpe, se puder.\n");
                    break;
                }
                
                if (tempHabit > 70){
                    printf("\x1b[30m(...)\033[0m\n");
                    printf("Duvido que voce esta vivo...\n");
                    sleep(1);
                    printf("Se estiver... acho que correr para o espaco seria mais seguro do que ficar ai dentro. Desculpas...\n");
                    break;
                }

                if (tempHabit > 40 && tempPropulso > 300){
                    printf("\x1b[30m(Temperatura Interna > 40 e Temperatura Externa > 300)\033[0m\n");
                    printf("Tudo esta queimando! Isso nao e bom!\n");
                    sleep(1);
                    if (comms == 0){
                        printf("Nem tem como comunicar com alguem sobre isso...\n");
                    }
                    printf("A nave deve ter quebrado em algum lugar, o calor do propulsor esta sendo redirecionado para a area habitavel.\n");
                    printf("Voce tem que fechar a porta que leva dessa quebra pro resto da nave por enquanto.\n");
                    waiting();
                    do { 
                        printf("...conseguiu? (S/N) ");
                        scanf("%c", &resposta00005);
                        while ((ch = getchar()) != '\n' && ch != EOF);

                        if (resposta00005 == 'S' || resposta00005 == 's'){
                            printf("Otimo. Por agora, ao menos voce nao ira morrer.\n");
                            sleep(1);
                            printf("Tem que encontrar exatamente onde a brecha esta, e nao consigo te ajudar com isso.\n");
                            sleep(2);
                            printf("Duvido que tenha mais de alguns minutos antes que a area fechada ou exploda, ou nao sirva mais para te ajudar viver.\n");
                            sleep(2);
                            printf("De qualquer forma, \033[0;32mcorra!\033[0m\n");
                            break;
                        }
                        if (resposta00005 == 'N' || resposta00005 == 'n'){
                            printf("Por que nao???\n");
                            printf("Isso realmente nao poderia ficar pior...\n");
                            if (energia < 20){
                                printf("Ah, mas claro que pode, por que nos nem temos energia... espera.\n");
                                waiting2();
                                printf("Espera! Essa pode ser a solucao! Se voce desligar todos os sistemas da nave, o propulsor ira poder esfriar por si mesmo!\n");
                                sleep(2);
                                printf("Se isso nao der certo... duvido que voce ira viver, mas talvez funcione.\n");
                                sleep(1.5);
                                printf("Boa sorte.\n");
                                break;
                            }
                            printf("Eu nao sei como te ajudar, me desculpa...\n");
                            sleep(2);
                            printf("...boa sorte.\n");
                            break;

                        }
                    } while (resposta00005 != 'S' && resposta00005 != 's' && resposta00005 != 'N' && resposta00005 != 'n');
                    break;
                }

                
                else if (tempHabit > 40){
                    printf("\x1b[30m(Temperatura Interna > 40)\033[0m\n");
                    printf("Para a temperatura estar num nivel tao alto, um \033[0;31mfogo\033[0m deve ter espalhado por dentro.\n");
                    sleep(2);
                    printf("Fique com calma, e tente achar da onde o \033[0;31mfogo\033[0m esta vindo por meio do seu painel.\n");
                    waiting();
                    do { 
                        printf("...conseguiu achar? (S/N)\n");
                        scanf("%c", &resposta00001);
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        if (resposta00001 == 'S' || resposta00001 == 's'){
                            printf("Otimo. Ache algum retardante contra fogo, tem mais de uma dezena de \x1b[34mextintores\033[0m pela nave.\n");
                            sleep(1);
                            printf("Eu nao posso te ajudar mais, porem, acho melhor voce correr! Fogos no espaco nao sao tao amigaveis.\n");
                        }
                        else if (resposta00001 == 'N' || resposta00001 == 'n'){
                            printf("Isso nao e bom... primeiramente, alerte todos outros na nave. Seria melhor extinguir o fogo rapidamente, mas ja que nao sabe onde esta, coloque seu traje espacial.\n");
                            sleep(1);

                            printf("Ele e a prova de fogo e tem seu proprio tanque se oxigenio, entao sera bom para combater-lo. Apos isso, pegue algum \x1b[34mextintor\033[0m, e siga a fumaca. Desculpa nao poder te ajudar mais...\n");
                        }
                    } while (resposta00001 != 'S' && resposta00001 != 's' && resposta00001 != 'N' && resposta00001 != 'n');
                    break;
                }

                if (tempPropulso > 1000){
                    printf("\x1b[30m(Temperatura Externa > 1000)\033[0m\n");
                    printf("O exterior esta queimando! Nao deveria ter motivo por isso...\n");
                    waiting();
                    printf("Rapido, ligue \x1b[34mescudos\033[0m termais de emergencia! Tem que fazer algo!\n");
                    waiting2();
                    do{ 
                        printf("Conseguiu?! (S/N)");
                        scanf("%c", &resposta00004);
                        while ((ch = getchar()) != '\n' && ch != EOF);

                        if ((resposta00004 == 'S' || resposta00004 == 's') && (energia < 20)){
                            printf("Nao tenho certeza se ira fazer muito... mas...\n");
                            printf("Ah nao...\n");
                            waiting2();
                            printf("A energia... a nave entrou em modo economia. Se o escudo nao tem energia, ele vai se desligar.\n");
                            sleep(2);
                            printf("Mesmo com o sol tao forte, os paines solares vao apenas derreter se tentar usar-los.\n");
                            sleep(1.5);
                            printf("\x1b[30mDroga.\033[0m Voce vai ter que sobrepor o modo economia e redirecionar energia para o escudo de qualquer forma.\n");
                            sleep(1);
                            printf("Se acabar rapidamente... voce vai estar salvo. Se nao...\n");
                            break;

                        }

                        if (resposta00004 == 'S' || resposta00004 == 's') {
                            printf("Nao tenho certeza se ira fazer muito mas ao menos deve durar por um tempo.\n");
                            sleep(2);
                            printf("Use esse tempo para achar outra solucao. Alerte todos que conseguir.\n");
                            sleep(2);
                            printf("Acredito em voce!\n");
                        }

                        if (resposta00004 == 'N' || resposta00004 == 'n'){
                            printf("O metal do airlock vai comecar a derreter se for exposto a temperatura constante assim.\n");
                            sleep(2);
                            printf("Quando sai da atmosfera e quente, sim, mais dura apenas por alguns minutos no maximo! Nao foi feito pra isso.\n");
                            waiting2();
                            printf("Desculpa mas... nao tem mais o que fazer.\n");
                            if (comms == 0){
                                printf("Mesmo se tivesse comunicacao, duvido que ajuda chegaria a tempo.\n");
                            } else {
                                printf("Pode tentar chamar outros na terra, mas nao acredito que ajuda ira chegar a tempo.\n");
                            }
                            sleep(2);
                            printf("Boa sorte, de qualquer forma...\n");
                        }
                        
                        
                    } while(resposta00004 != 'S' && resposta00004 != 's' && resposta00004 != 'N' && resposta00004 != 'n');
                    break;
                }
                
                else if (tempPropulso > 300){
                    printf("\x1b[30m(Temperatura Externa > 300)\033[0m\n");
                    printf("O exterior esta a mais de 300 graus celcius. Nao e TAO preocupante... por agora.\n");
                    sleep(2);
                    do { 
                        printf("...por quanto tempo esteve assim, voce acha? Mais de 30 minutos? (S/N) ");
                        scanf("%c", &resposta00002);
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        if ((resposta00002 == 'S' || resposta00002 == 's') && comms == 0){
                            printf("Esquece o que eu disse! \x1b[35mExtremamente\033[0m preocupante!\n");
                            sleep(1);
                            printf("O sol deve estar agindo de uma forma imprevinida. Tente comunic...\n");
                            waiting2();
                            printf("Certo. Esta sem capacidades para comunicacao no momento.\n");
                            sleep(0.5);
                            printf("Inves disso, tente usar seu painel para ver o angulo do sol em comparacao a nave. Talvez seja possivel um ajuste.\n");
                            waiting();
                            do { 
                                printf("...conseguiu? (S/N)");
                                scanf("%c", &resposta00003);
                                while ((ch = getchar()) != '\n' && ch != EOF);
                                
                                if (resposta00003 == 'S' || resposta00003 == 's'){
                                    printf("Otimo! Lentamente, a temperatura deve diminuir. Tente religar o sistema de comunicacao rapidamente, por favor...\n");
                                }   
                                if (resposta00003 == 'N' || resposta00003 == 'n'){
                                    printf("\x1b[30mDroga.\033[0m Tente religar as comunicacoes, e avise todos outros com voce sobre a situacao.\n");
                                    sleep(3);
                                    printf("...nao tenho certeza que posso te ajudar mais. Desculpa. Se for nada, a temperatura ira lentamente diminuir.\n");
                                    break;
                                }         
                          } while(resposta00003 != 'S' && resposta00003 != 's' && resposta00003 != 'N' && resposta00003 != 'n');

                        }
                        else if (resposta00002 == 'S' || resposta00002 == 's'){
                            printf("Esquece o que eu disse! \x1b[35mExtremamente\033[0m preocupante!\n");
                            sleep(1);
                            printf("O sol deve estar agindo de uma forma imprevinida. Tente comunicar com especialistas na terra para eles poderem te ajudar.\n");
                            sleep(2);
                            printf("...E espere que o Sol tenha piedade em sua alma.\n");
                            break;
                        }
                        if (resposta00002 == 'N' || resposta00002 == 'n'){
                            printf("Bom, bom. Se tivesse assim por muito tempo, seria um pouco menos seguro.\n");
                            sleep(1);
                            printf("Tente comunicar com os outros na nave sobre isso, talvez eles tenhao uma ideia. Se continuar assim por muito tempo...\n");
                            sleep(2);
                            printf("Bem, o lado de fora foi feito para aguentar altas temperaturas, nao?\n");
                            break;
                        }

                    } while(resposta00002 != 'S' && resposta00002 != 's' && resposta00002 != 'N' && resposta00002 != 'n');                    
                    break;
                }


                if (energia < 20){
                    printf("\x1b[30m(Energia < 20)\033[0m\n");
                    printf("A sua energia parece estar bem baixa.\n");
                    sleep(1.5);
                    printf("Nao precisa se preocupar, e apenas preciso abrir os paineis solares para recarregar.\n");
                    sleep(2);
                    printf("Pode demorar um tempinho, entao... de uma coxilada.\n");
                    break;
                }

                if (comms == 0){
                    printf("Esquisito. Comunicacoes estao desligadas.\n");
                    sleep(2);
                    printf("Se nao for algo grande, resetar todos sistemas deve fazer voltar. Isso inclue eu, entao... te vejo em alguns segundos.\n");
                    progress();
                    progress();
                    progress();
                    do { 
                        printf("...deu certo? (S/N) ");
                        scanf("%c", &resposta00006);
                        while ((ch = getchar()) != '\n' && ch != EOF);
                        
                        if (resposta00006 == 'S' || resposta00006 == 's'){
                            printf("\033[0;33mPerfeito\033[0m. Talvez seja bom investigar por que isso aconteceu de qualquer forma, mas por enquanto, esta bom.\n");
                            break;
                        }

                        if (resposta00006 == 'N' || resposta00006 == 'n'){
                            printf("Nao? Deve ser algo fisico entao... vale a pena tentar investigar o dispositivo de comunicacao em si, se ele queimou, deve ter como ajustar-lo.\n");
                            sleep(3);
                            printf("Porem, nao tenho muito como te ajudar nisso. Boa sorte.\n");
                            break;
                        }

                    } while(resposta00006 != 'S' && resposta00006 != 's' && resposta00006 != 'N' && resposta00006 != 'n');
                    break;
                }
                printf("\033[0;33mZero\033[0m problemas!");
                break;    

            case 4:
                printf("Boa sorte.");
                airship = 0;

            default:

                break;

        }
    }


    return 0;
}