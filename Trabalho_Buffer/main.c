#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Tamanho dos espaços que vão ser alocados na memória
#define TAM_VARIAVEIS ( 5 * sizeof( int ) + 100 * sizeof( char ) )
//#define TAM_NOME ( INT_1 * sizeof( char ) ) //Alterar manualmente os scanf, caso mude o valor
//#define TAM_IDADE ( sizeof( int ) )
//#define TAM_EMAIL ( INT_2 * sizeof( char ) )
//#define TAM_PESSOA ( TAM_NOME + TAM_IDADE + TAM_EMAIL )

//Ponteiros para espaços na memórias prontos para usar
#define INT_1 ( *( int * )pBuffer )
#define INT_2 ( *( int * )( pBuffer + sizeof( int ) ) )
#define INT_3 ( *( int * )( pBuffer + 2 * sizeof( int ) ) )
#define TAM_TOTAL ( *( int * )( pBuffer + 3 * sizeof( int ) ) )
#define NUM_PESSOAS ( *( int * )( pBuffer + 4 * sizeof( int ) ) )
#define NOME_PESSOA ( ( char * )( pBuffer + 5 * sizeof( int ) ) )
#define NOME_EMAIL ( ( char * )( pBuffer + 5 * sizeof( int ) + 50 * sizeof( char ) ) )

// PBuffer =  INT_1 |   INT_2  | INT_3 | TAM_TOTAL| NUM_PESSOAS  | NOME_PESSOA |       NOME_EMAIL     |      int               valoresPessoas( Nome , Idade , Email )
//  sizeof     int       int     int        int       int          50*char            50*char          tam_nome + tam_email |    tam_nome*char + int  + tam_email*char

void * Menu( void * pBuffer );
void * AdicionarPessoa( void * pBuffer );
void * RemoverPessoa( void * pBuffer );
void BuscarPessoa( void * pBuffer );
void ListarTodos( void * pBuffer );

int main(){

    //pBuffer -> Única memória do programa
    void * pBuffer = malloc( TAM_VARIAVEIS );

    TAM_TOTAL = TAM_VARIAVEIS;
    NUM_PESSOAS = 0;

    while(1){
        pBuffer = Menu( pBuffer );
    }
}

void * Menu( void * pBuffer ){
    
    printf( "MENU:\n" );
    printf( "1. Adicionar Pessoa\n" );
    printf( "2. Remover Pessoa\n" );
    printf( "3. Buscar Pessoa\n" );
    printf( "4. Listar Todos\n" );
    printf( "5. Sair\n" );
    printf( "Selecione a operação: " );
    scanf( "%d" , (int *)pBuffer );
    printf("\n");

    switch ( INT_1 ){
        case 1:
            pBuffer = AdicionarPessoa( pBuffer );
            break;
        case 2:
            pBuffer = RemoverPessoa( pBuffer );
            break;
        case 3:
            BuscarPessoa( pBuffer );
            break;
        case 4:
            ListarTodos( pBuffer );
            break;
        case 5:
            free(pBuffer);
            exit(0);
            break;
        default:
            break;
    }
    return pBuffer;
}

void * AdicionarPessoa( void * pBuffer ){

     NUM_PESSOAS++;

     printf( "Digite o nome da pessoa: " );
     scanf(" %[^\n]", NOME_PESSOA);
 
     INT_1 = strlen( NOME_PESSOA ) + 1;
 
     printf( "Digite a idade da pessoa: " );
     scanf("%d", &INT_2 );
 
     printf( "Digite o email da pessoa: " );
     scanf( " %[^\n]", NOME_EMAIL );
 
     INT_3 = strlen( NOME_EMAIL ) + 1;

     printf("\n");

    // Adiciona espaço para uma nova pessoa no Buffer
    pBuffer = realloc( pBuffer, TAM_TOTAL + 2 * sizeof( int ) + ( INT_1 + INT_3 ) * sizeof( char ) );

    // pessoaAtual vai apontar para o novo espaço para pessoa no final da lista
    void * pessoaAtual = ( pBuffer + TAM_TOTAL );

    //Tamanho da nova pessoa adicionado | pessoaAtual aponta depois do int
    *( int *)pessoaAtual = 2 * sizeof( int ) + ( INT_1 + INT_3 ) * sizeof( char );
    pessoaAtual += sizeof( int );

    //Nome da pessoa adicionado | pessoaAtual aponta depois do \0
    strcpy(pessoaAtual, NOME_PESSOA);
    pessoaAtual += INT_1 * sizeof(char);

    //Idade da nova pessoa adicionado | pessoaAtual aponta depois da idade
    *( int *)pessoaAtual = INT_2;
    pessoaAtual += sizeof( int );

    //Nome da pessoa adicionado | pessoaAtual aponta depois do \0
    strcpy(pessoaAtual, NOME_PESSOA);
    pessoaAtual += INT_1 * sizeof(char);

    //Email da pessoa adicionado
    strcpy(pessoaAtual, NOME_EMAIL);

    TAM_TOTAL += 2 * sizeof( int ) + ( INT_1 + INT_3 ) * sizeof( char );

    return pBuffer;

}

void * RemoverPessoa( void * pBuffer ){
    // BuscarPessoa( pBuffer );
    // printf( "Digite o ID da pessoa que você deseja remover: " );
    // scanf( "%d", &INT_1 );
    // if( INT_1 >= NUM_PESSOAS || INT_1 < 0 ){
    //     printf( "Esse ID não existe" );
    //     return pBuffer;
    // }
    // //Aponta para pessoa que vai ser removida
    // void * pessoaAtual = ( pBuffer + TAM_VARIAVEIS + INT_1 * TAM_PESSOA );

    // //Move memória que está atrás da pessoa (NUM_PESSOAS depois do ID) a ser removida, para pessoaAtual
    // memmove( pessoaAtual, ( pessoaAtual + TAM_PESSOA ), ( ( NUM_PESSOAS - ( INT_1 + 1 ) ) * TAM_PESSOA ) );
    
    // NUM_PESSOAS--;

    // pBuffer = realloc( pBuffer, TAM_VARIAVEIS + NUM_PESSOAS * TAM_PESSOA );

    // return pBuffer;
}

void BuscarPessoa( void * pBuffer ){

    // printf( "Digite o nome da pessoa: " );
    // scanf( " %49[^\n]", NOME_PESSOA );

    // for( INT_1 = 0 ; INT_1 < NUM_PESSOAS ; INT_1++ ){

    //     void * pessoaAtual = ( pBuffer + TAM_VARIAVEIS + INT_1 * TAM_PESSOA );
        
    //     if( strstr( pessoaAtual, NOME_PESSOA ) ){
    //         printf( "%d.\n", INT_1 );
    //         printf( " Nome: %s\n" , (char *)pessoaAtual );
    //         printf( " Idade: %d\n" , *(int *)( pessoaAtual + TAM_NOME ) );
    //         printf( " Email: %s\n\n" , (char *)( pessoaAtual + TAM_NOME + TAM_IDADE ) );
    //     }
       
    // }
}

void ListarTodos( void * pBuffer ){

    // if( NUM_PESSOAS == 0 ) printf("Nenhuma Pessoa adicionada a lista\n\n");

    // for( INT_1 = 0 ; INT_1 < NUM_PESSOAS ; INT_1++ ){

    //     void * pessoaAtual = ( pBuffer + TAM_VARIAVEIS + INT_1 * TAM_PESSOA );

    //     printf( "%d.\n", INT_1 );
    //     printf( " Nome: %s\n" , (char *)pessoaAtual );
    //     printf( " Idade: %d\n" , *(int *)( pessoaAtual + TAM_NOME ) );
    //     printf( " Email: %s\n\n" , (char *)( pessoaAtual + TAM_NOME + TAM_IDADE ) );
    // }
}
