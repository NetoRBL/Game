///////////////////////////////////////////////////////////////////////////////////////
//                                                                                   //
//                         <<< ----- JOGO DA FORCA ----- >>>                         //
//                         <<< ----- PRODUZIDO POR ----- >>>                         //
//                          Antonio Arcenio Rabelo Neto - 496018                     //
//                          Luis Davi Gomes dos Santos - 500085                      // 
//                          Itallo Henrique Fernandes da Silva - 496540              //
//                          Joao Vitor Girao Silva - 496248                          //
//                                                                                   //
///////////////////////////////////////////////////////////////////////////////////////


// <--------------------        inclusoes de bibliotecas          --------------------> 

#include <stdio.h>
#include <string.h>
#include <locale.h>
#include <stdlib.h>
#include <time.h>

// <--------------------       /inclusoes de bibliotecas          --------------------> 

// <---------------------- inicializacaoo de variaveis globais ------------------------> 

char palavra[100],letra,letrasDigitadas[26], tematica[50];
int contador = 0, i, j;

// <---------------------- /inicializacao de variaveis globais -----------------------> 

// <------------------------- funcao para desenhar a forca --------------------------->

void drawing(int erro,int qtdletra){
    system("cls");
    
    printf("Tema: %s\n", tematica);

    // <------------- criacao do visor de letras ---------->

    printf("Palavra: ");
    for(i = 0; i < qtdletra; i++){
        int aux = 0;
        for(j = 0;j < contador;j++){
            if(palavra[i] == letrasDigitadas[j]){
                aux = 1;
                break;
            }
        }
        if(aux == 1){
            printf("%c ",palavra[i]);
        }else if(aux == 0){
            if(palavra[i] == ' ' || palavra[i] == '\t' || palavra[i] == '\r' || palavra[i] == '\n' || palavra[i] == '\x0b'){
                printf("- ");
            }else{
                printf("_ ");
            }
        }
    }
    
    // <------------- /criacao do visor de letras --------->

    // <-------------- visor de letras digitadas ---------->

    printf("\nLetras digitadas: ");
    for(i = 0; i < contador; i++){
        if(i == 0){
            printf("%c ", letrasDigitadas[i]);
        }else if(letrasDigitadas[i] != letrasDigitadas[i-1]){
            printf("%c ", letrasDigitadas[i]);
        }
    }
    
    // <------------- /visor de letras digitadas ---------->

    printf("\n\n");

    // <--------- Local de desenho e edicao da forca ------>
    
    printf("|-----FORCA-----|\n");
    switch (erro)
    {
    case 0:
        printf("|\t____ \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|    \t|\n");
        printf("|\t|    \t|\n");
        printf("|\t|    \t|");
        break;
    case 1:
        printf("|\t____ \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|   o \t|\n");
        printf("|\t|      \t|\n");
        printf("|\t|      \t|");
        break;
    case 2:
        printf("|\t____ \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|   o \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|      \t|");
        break;
    case 3:
        printf("|\t____ \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|   o \t|\n");
        printf("|\t|  /|\t|\n");
        printf("|\t|      \t|");
        break;
    case 4:
        printf("|\t____ \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|   o \t|\n");
        printf("|\t|  /|\\\t|\n");
        printf("|\t|      \t|");
        break;
    case 5:
        printf("|\t____ \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|   o \t|\n");
        printf("|\t|  /|\\\t|\n");
        printf("|\t|  /\t|");
        break;
    case 6:
        printf("|\t____ \t|\n");
        printf("|\t|   |\t|\n");
        printf("|\t|   o \t|\n");
        printf("|\t|  /|\\\t|\n");
        printf("|\t|  / \\\t|");
        break;
    default:
        break;
    }
    printf("\n|---------------|\n");

    printf("\n");
    switch(erro){
        case 1:
            printf("Acho que alguem perdeu a cabeca. (*-*)\n");
            break;
        case 2:
            printf("O corpo ja se foi tambem.\n");
            break;
        case 3:
            printf("As vezes vc oferece a mao, e te levam o braco.\n");
            break;
        case 4:
            printf("Espero que nao te faca falta.\n");
            break;
        case 5:
            printf("Uma perna a mais ou a menos nao muda nada ne?.\n");
            break;
        case 6:
            printf("E morreu.\n");
            break;
    }

    // <-------- /Local de desenho e edicao da forca ------>    

        
        printf("\n\n");
    
}

// <------------------------- /funcao para desenhar a forca -------------------------->

// <-------------------------- funcao para escolher o tema --------------------------->

int escolhatema(){
    system("cls");
    int num;
    puts("******************************************************");
    puts("Menu de Temas");
    puts("----------------------------------------------------");
    puts("Opcao 1: Animais");
    puts("Opcao 2: Objetos");
    puts("Opcao 3: Partes do corpo");
    puts("Opcao 4: Comidas");
    puts("Opcao 5: Nomes de pessoas");
    puts("----------------------------------------------------");
    printf("Digite o numero do tema escolhido: ");
    scanf("%d",&num);
    puts("******************************************************");

    return num;
}

// <------------------------- /funcao para escolher o tema --------------------------->

// <------------------------ funcao para buscar os arquivos -------------------------->

char* pegar_palavra(int a){
    FILE *arq;
    char linha[50], tema[50][100];
    char* palavra_aux = (char*)calloc(50,sizeof(char));
    int num = a, cont = 0;

    srand(time(NULL));

    switch (num){
    case 1:
        arq = fopen("animais.txt","r");
        while(fgets(linha, 50, arq) != NULL){
  		strcpy(tema[cont], linha);
		    cont++;
	    }
        strcpy(palavra_aux, tema[rand() % cont]);
        fclose(arq);
        strcpy(tematica, "animais");
        break;
    case 2:
        arq = fopen("objetos.txt","r");
        while(fgets(linha, 50, arq) != NULL){
  		strcpy(tema[cont], linha);
		    cont++;
	    }
        strcpy(palavra_aux, tema[rand() % cont]);
        fclose(arq);
        strcpy(tematica, "objetos");
        break;
    case 3:
        arq = fopen("partescorpo.txt","r");
        while(fgets(linha, 50, arq) != NULL){
  		strcpy(tema[cont], linha);
		    cont++;
	    }
        strcpy(palavra_aux, tema[rand() % cont]);
        fclose(arq);
        strcpy(tematica, "partes do corpo");
        break;
    case 4:
        arq = fopen("comidas.txt","r");
        while(fgets(linha, 50, arq) != NULL){
  		strcpy(tema[cont], linha);
		    cont++;
	    }
        strcpy(palavra_aux, tema[rand() % cont]);
        fclose(arq);
        strcpy(tematica, "comidas");
        break;
    case 5:
        arq = fopen("nomes.txt","r");
        while(fgets(linha, 50, arq) != NULL){
  		strcpy(tema[cont], linha);
		    cont++;
	    }
        strcpy(palavra_aux, tema[rand() % cont]);
        fclose(arq);
        strcpy(tematica, "nomes");
        break;
    default:
        system("cls");
        printf("Um valor invalido foi digitado!\n");
        singleplayer();
        break;
    }
    return palavra_aux;
}

// <----------------------- /funcao para buscar os arquivos -------------------------->

// <------------------------- execucao do jogo single player ------------------------->

void singleplayer(){
    char player[50];
    int opcao;
    int qtdLetra = 0;
    int acertos = 0;
    int erros = 0;
    int teste = 0;

    printf("Player, digite seu nome: ");
    scanf(" %[^\n]s", player);

     opcao = escolhatema();
     strcpy(palavra ,pegar_palavra(opcao));
     strlwr(palavra);

     qtdLetra = strlen(palavra) - 1;
    system("cls");
    drawing(erros,qtdLetra);
    
    // <--------- Lopping usado para rodar o jogo --------->

    while(1){
        int erroInt = 0;
        int acertosInt = 0;
        printf("\t|**TABELA DE PONTOS**|\t\n");
        printf("\t| acertos : %d \t     |\n\t| erros : %d\t     |\n",acertos, erros);
        printf("%s, digite uma letra:\n",player);
        getchar();
        scanf(" %[^\n]c",&letra);
        
        // <--- inicializacao do array letrasDigitadas ----->

        if(contador == 0){
            letrasDigitadas[contador] = letra;
            contador++;
        }

        // <--- /inicializacao do array letrasDigitadas ---->

        // <-- teste para saber se a letra ja foi digitada ->

        for(j = 0; j <= contador;j++ ){
            if(letra == letrasDigitadas[j] && j > 0){
                drawing(erros,qtdLetra);
                printf("letra ja foi digitada. Por favor escolha outra.\n");
                teste = 1;
                break;
            }
        }

        // <- /teste para saber se a letra ja foi digitada ->

        // <---- verificar se existe a letra na palavra ---->

        if(teste != 1){
            letrasDigitadas[contador] = letra;
            contador++;
            for(i = 0; i < qtdLetra; i++){

                if(palavra[i] == letra){
                    acertos++;
                    acertosInt++;
                }else{
                    erroInt++;
                    
                }

            }

            if(acertosInt > 0){
                
                drawing(erros,qtdLetra);
                printf("\t***Letra '%c' encontrada.***\t\n\n",letra);
            }else{
                printf("letra nao encontrada\n");
                drawing(erros,qtdLetra);
            }


        }else{
            teste = 0;
        }

        // <---- /verificar se existe a letra na palavra --->

        // <---- erro caso a letra nao exista na palavra --->

        if(erroInt == qtdLetra) {
            erros++;
            
            drawing(erros,qtdLetra);
        } 

        // <--- /erro caso a letra nao exista na palavra --->
        
        // <--- verificar qual dos dois jogadores ganhou --->

        if(acertos == qtdLetra){
            printf("Parabens %s! Voce acertou a palavra %s!",player, palavra);
            break;
        }else if(erros == 6){
            printf("%s, voce errou!",player);
            printf("\na palavra era: %s", palavra);
            break;
        }

        // <-- /verificar qual dos dois jogadores ganhou --->    

    }

    // <--------- /Lopping usado para rodar o jogo --------->

    restart();

}

// <------------------------ /execucao do jogo single player ------------------------->

// <------------------------- execucao do jogo multiplayer --------------------------->

void multiplayer(){
    
    // <-------- inicializacao de variaveis locais -------->

    char player1name[50], player2name[50];
    int qtdLetra = 0;
    int acertos = 0;
    int erros = 0;
    int teste = 0;
    int qtdEspacos = 0;
    int i;

    // <------- /inicializacao de variaveis locais -------->

    // <--------- adicao dos nomes dos jogadores ---------->

    printf("Player 1 digite seu nome:\n");
    scanf(" %[^\n]s", player1name);
    
    printf("Player 2 digite seu nome:\n");
    scanf(" %[^\n]s", player2name);

    // <-------- /adicao dos nomes dos jogadores ---------->

    // <-------- tema da palavra que sera usada ----------->

    printf("%s, digite o tema da palavra para a forca:\n",player1name);
    scanf(" %[^\n]s", tematica);

    // <-------- /tema da palavra que sera usada ---------->

    // <-------- palavra que sera usada na forca ---------->

    printf("%s, digite a palavra para a forca:\n",player1name);
    scanf(" %[^\n]s", palavra);

    strlwr(palavra);

    qtdLetra = strlen(palavra);
    for(i = 0; i < qtdLetra; i++){
        if(palavra[i] == ' ' || palavra[i] == '\t' || palavra[i] == '\r' || palavra[i] == '\n' || palavra[i] == '\x0b'){
            qtdEspacos++;
        }
    }

    // <------- /palavra que sera usada na forca ---------->
    
    system("cls");
    drawing(erros,qtdLetra);

    // <-------- Lopping usado para rodar o jogo ---------->

    while(1){
        int erroInt = 0;
        int acertosInt = 0;
        printf("\t|**TABELA DE PONTOS**|\t\n");
        printf("\t| acertos : %d \t     |\n\t| erros : %d\t     |\n",acertos, erros);
        printf("Digite uma letra %s:\n",player2name);
        getchar();
        scanf("%c",&letra);

        // <-- inicializacao do array letrasDigitadas ----->

        if(contador == 0){
            letrasDigitadas[contador] = letra;
            contador++;
        }

        // <-- /inicializacao do array letrasDigitadas ---->

        // <---- verificar se a letra ja foi digitada ----->

        for(j = 0; j <= contador;j++ ){
            if(letra == letrasDigitadas[j] && j > 0){
                drawing(erros,qtdLetra);
                printf("letra ja foi digitada. Por favor escolha outra.\n");
                teste = 1;
                break;
            }
        }

        // <---- /verificar se a letra ja foi digitada ---->

        // <---- verificar se existe a letra na palavra --->

        if(teste != 1){
            letrasDigitadas[contador] = letra;
            contador++;
            for(i = 0; i < qtdLetra; i++){

                if(palavra[i] == letra){
                    acertos++;
                    acertosInt++;
                }else{
                    erroInt++;
                    
                }

            }

            if(acertosInt > 0){
                
                drawing(erros,qtdLetra);
                printf("\t***Letra '%c' encontrada.***\t\n\n",letra);
            }else{
                printf("letra nao encontrada\n");
                drawing(erros,qtdLetra);
            }


        }else{
            teste = 0;
        }

        // <--- /verificar se existe a letra na palavra --->

        // <--- erro caso a letra nao exista na palavra --->

        if(erroInt == qtdLetra) {
            erros++;
            
            drawing(erros,qtdLetra);
        } 
        
        // <-- /erro caso a letra nao exista na palavra --->

        // <-- verificar qual dos dois jogadores ganhou --->

        if(acertos == (qtdLetra - qtdEspacos)){
            printf("%s ganhou, Parabens!",player2name);
            break;
        }else if(erros == 6){
            printf("%s ganhou! Parabens!",player1name);
            printf("\na palavra era: %s", palavra);
            break;
        }    

        // <-- /verificar qual dos dois jogadores ganhou -->

    }

    // <--------- /Lopping usado para rodar o jogo --------->

    restart();

}

// <------------------------ /execucao do jogo multiplayer --------------------------->

// <------------------------------- escolha do modo ---------------------------------->

void escolhamodo(){
    int modo;
    puts("******************************************");
    puts("1 - Jogo Solo");
    puts("2 - Jogador Vs. Jogador");
    puts("******************************************");
    printf("Modo de jogo a escolher: ");
    scanf("%d", &modo);
    system("cls");

    switch (modo){
        case 1:
            singleplayer();
            break;
        case 2:
            multiplayer();
            break;
        default:
            system("cls");
            puts("===========================");
            puts("DIGITE UM VALOR VALIDO!");
            puts("===========================");
            escolhamodo();
            break;
    }
}

// <------------------------------ /escolha do modo ---------------------------------->

// <------------------------------ funcao de restart --------------------------------->

void restart(){
    int newgame = 0;
    memset(palavra, 0, sizeof(palavra));
    memset(letrasDigitadas, 0, sizeof(letrasDigitadas));
    printf("\nQuer jogar novamente?\n");
    printf("1 - Sim\n");
    printf("2 - Nao\n");
    scanf("%d", &newgame);
    if(newgame == 1){
        system("cls");
        escolhamodo();
    }else{
        system("cls");
        printf("Game encerrado.");
    }
}

// <----------------------------- /funcao de restart --------------------------------->

int main(){

    escolhamodo();

    return 0;
}
