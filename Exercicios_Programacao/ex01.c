/*O objetivo desse exercício é criar um programa capaz de armazenar nomes numa mesma string, apenas separados
por espaços, sem ocupar memória desnecessária, e poder excluir eles pelo nome*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu( void );
void AdicionarNome( void );
void RemoverNome( void );
void ListarNomes( void );

int numNomes = 0;
char *nomes;
int tamTotalNomes = 1; //Contar o tamanho total da string de nomes, número de caracteres + \0

int main(){

    while( 1 ){ //Loop infinito enquanto o usuário não usa a opção de sair.
        Menu();
    }

    return 0;
}

void Menu( void ){
    int opc;
    printf( "Digite o número da função que você deseja realizar:\n" );
    printf( "1. Adicionar nome\n" );
    printf( "2. Remover nome\n" );
    printf( "3. Listar nomes\n" );
    printf( "4. Sair\n" );
    scanf( "%d", &opc );

    switch ( opc )
    {
    case 1:
        AdicionarNome();
        break;
    case 2:
        RemoverNome();
        break;
    case 3:
        ListarNomes();
        break;
    case 4:
        free(nomes);
        exit( 0 );
        break;
    default:
        printf( "Digite um número válido\n" );
        break;
    }
}

void AdicionarNome( void ){
    char nome[50];
    printf( "Digite o nome que você deseja adicionar:\n" );
    scanf( "%s", nome );
    numNomes++;
    int tamNome = strlen( nome );
    tamTotalNomes += tamNome;
    nomes = ( char * ) realloc( nomes, tamTotalNomes * sizeof(char) );
    strcat( nome, " " ); //Um Byte a mais desnecessário no fim para o espaço
    strcat( nomes, nome );
}

void RemoverNome( void ){
    char nome[50];
    char *ponteiroNomeInicio, *ponteiroNomeFim;
    int tamNomesAteFim;
    printf( "Digite o nome que você deseja remover:\n" );
    scanf( "%s", nome );
    ponteiroNomeInicio = strstr( nomes, nome );
    ponteiroNomeFim = ponteiroNomeInicio + strlen(nome) *  sizeof(char) + 1;
    tamNomesAteFim = strlen(ponteiroNomeFim);
    memmove(ponteiroNomeInicio, ponteiroNomeFim, tamNomesAteFim + 1);
    nomes = ( char * ) realloc( nomes, (strlen(nomes) - strlen(nome) - 1) * sizeof(char) );
}

void ListarNomes( void ){
    printf( "%s\n", nomes );
}