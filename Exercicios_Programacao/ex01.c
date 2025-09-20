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
char *p;
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
    p = ( char * ) realloc( p, tamTotalNomes * sizeof(char) );
    strcat( nome, " " );
    strcat( p, nome );
    printf( "%s\n", p );
    printf("%ld %ld", strlen(p), sizeof(p)); //Encontrar outra forma de ver o tamanho de uma alocação dinamica
}

void RemoverNome( void ){

}
void ListarNomes( void ){

}