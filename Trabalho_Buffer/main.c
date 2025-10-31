#include <stdio.h>
#include <stdlib.h>

#define TAM_VARIAVEIS ( 2 * sizeof( int ) )
#define TAM_NOME ( 50 * sizeof( char ) )
#define TAM_IDADE ( sizeof(int) )
#define TAM_EMAIL ( 50 * sizeof( char ) )
#define INT_1 ( *( int * )pBuffer )
#define NUM_PESSOAS ( *( int * )( pBuffer + sizeof( int ) ) )

// PBuffer =  INT_1   | NUM_PESSOAS  | valoresPessoas( Nome , Idade , Email )
//  sizeof     int         int                      50*char + int  + 50*char

void * Menu( void * pBuffer );
void * AdicionarPessoa( void * pBuffer );
void RemoverPessoa( void * pBuffer );
void BuscarPessoa( void * pBuffer );
void ListarTodos( void * pBuffer );

int main(){

    //pBuffer -> operação
    void * pBuffer = malloc( TAM_VARIAVEIS );

    //numPessoas = 0
    NUM_PESSOAS = 0;

    while(1){
        pBuffer = Menu( pBuffer );
    }
}

void * Menu( void * pBuffer ){
    
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
            RemoverPessoa( pBuffer );
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
    // numPessoas++
     NUM_PESSOAS++;

    // Adiciona espaço para uma nova pessoa no Buffer
    pBuffer = realloc( pBuffer, TAM_VARIAVEIS + NUM_PESSOAS * ( TAM_EMAIL + TAM_NOME + TAM_IDADE ) );

    // pessoaAtual vai apontar para o novo espaço para pessoa no final da lista
    void * pessoaAtual = ( pBuffer + TAM_VARIAVEIS + ( NUM_PESSOAS - 1 ) * ( TAM_EMAIL + TAM_NOME + TAM_IDADE ) );

    printf( "Digite o nome da pessoa: " );
    // Guarda o nome no Buffer
    scanf("%s", ( char * )pessoaAtual);

    printf( "Digite a idade da pessoa: " );
    // Guarda idade após o nome
    scanf("%d", ( int * )( pessoaAtual + TAM_NOME ) );

    printf( "Digite o email da pessoa: " );
    // Guarda email após o nome e idade
    scanf( "%s", ( char * )( pessoaAtual + TAM_NOME + TAM_IDADE ) );

    return pBuffer;

}

void RemoverPessoa( void * pBuffer ){
    //Remover Pelo Nome ou Indice? Pelo Indice só vai ter 1, mais facil
}

void BuscarPessoa( void * pBuffer ){
    //Busca pelo Nome se tem mais de 1 nome igual, retorna todos com seus respectivos indices
}

void ListarTodos( void * pBuffer ){

    if( NUM_PESSOAS == 0 ) printf("Nenhuma Pessoa adicionada a lista\n\n");
    for( INT_1 = 0 ; INT_1 < NUM_PESSOAS ; INT_1++ ){

        void * pessoaAtual = ( pBuffer + TAM_VARIAVEIS + INT_1 * ( TAM_NOME + TAM_IDADE + TAM_EMAIL ) );

        printf( "%d.\n", INT_1 );
        printf( " Nome: %s\n" , (char *)pessoaAtual );
        printf( " Idade: %d\n" , *(int *)( pessoaAtual + TAM_NOME ) );
        printf( " Email: %s\n\n" , (char *)( pessoaAtual + TAM_NOME + TAM_IDADE ) );
    }
}
