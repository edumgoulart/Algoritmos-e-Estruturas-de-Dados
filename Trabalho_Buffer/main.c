#include <stdio.h>
#include <stdlib.h>


// PBuffer = operação | numPessoas | valoresPessoas
//  sizeof     int         int        20*char+int+20*char

void Menu( void * pBuffer ){

    printf( "Selecione a operação: " );
    printf( "1. Adicionar Pessoa" );
    printf( "2. Remover Pessoa" );
    printf( "3. Buscar Pessoa" );
    printf( "4. Listar Todos" );
    printf( "5. Sair" );
    scanf( "%d" , pBuffer );

    switch ( *( int* )pBuffer ){
        case 1:
            AdicionarPessoa( pBuffer );
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
            exit(0);
            break;
        default:
            break;
    }
}

void AdicionarPessoa( void * pBuffer ){
    //numPessoas++
     ( *( int * )( pBuffer + sizeof( int ) ) )++;

    pBuffer = realloc( pBuffer, 2 * sizeof( int ) + ( *( int * )( pBuffer + sizeof( int ) ) ) * ( 40 * sizeof( char ) + sizeof( int ) ) );

}

void RemoverPessoa( void * pBuffer ){
    
}

void BuscarPessoa( void * pBuffer ){
    
}

void ListarTodos( void * pBuffer ){
    
}

int main(){

    //pBuffer -> operação
    void * pBuffer = malloc( 2 * sizeof( int ) );

    //numPessoas = 0
    *( int* )( pBuffer + sizeof( int ) ) = 0;

    while(1){
        Menu( pBuffer );
    }
}