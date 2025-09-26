/*O objetivo desse exercício é criar um programa capaz de armazenar nomes numa mesma string, apenas separados
por espaços, sem ocupar memória desnecessária, e poder excluir eles pelo nome*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void Menu( void );
void AdicionarNome( void );
void RemoverNome( void );
void ListarNomes( void );

char *nomes = NULL;
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
    //Nome que vai adicionar
    char nome[50];
    printf( "Digite o nome que você deseja adicionar:\n" );
    scanf( "%s", nome );

    int tamNome = strlen( nome ) + 1;//+1 do espaço
    tamTotalNomes += tamNome;
    nomes = ( char * ) realloc( nomes, tamTotalNomes * sizeof(char) );

    strcat( nome, " " ); //Um Byte a mais desnecessário no fim para o espaço
    strcat( nomes, nome );
}

void RemoverNome( void ){
    char nome[50];
    char *ponteiroNomeInicio, *ponteiroNomeFim;
    int tamNomesAteFim;
    int tamnomes = strlen(nomes);

    //Nome que vai remover
    printf( "Digite o nome que você deseja remover:\n" );
    scanf( "%s", nome );

    //O ponteiroNomeInicio vai apontar para o nome encontrado pelo strstr
    ponteiroNomeInicio = strstr( nomes, nome );
    //O ponteiroNomeFim vai apontar para o começo do outro nome logo após do selecionado
    ponteiroNomeFim = ponteiroNomeInicio + strlen(nome) *  sizeof(char) + 1;
    //Variavel que mede a quantidade de caracteres depois do nome selecionado até o /0
    tamNomesAteFim = strlen(ponteiroNomeFim);
    //Tudo que está depois do nome que vai ser removido sobrescreve o nome, começando agora onde o nome que vai ser removido começa
    memmove(ponteiroNomeInicio, ponteiroNomeFim, tamNomesAteFim + 1);//+1 do /0
    nomes = ( char * ) realloc( nomes, (tamnomes - strlen(nome) - 1) * sizeof(char) );
}

void ListarNomes( void ){
    if( nomes != NULL )
        printf( "%s\n", nomes );
}