#include <stdio.h>
#include <stdlib.h>


// PBuffer = operação | numPessoas | valoresPessoas
//  sizeof     int         int        20*char+int+20*char

void Menu( void * pBuffer, void * numPessoas ){

    printf( "Selecione a operação: " );
    printf( "1. Adicionar Pessoa" );
    printf( "2. Remover Pessoa" );
    printf( "3. Buscar Pessoa" );
    printf( "4. Listar Todos" );
    printf( "5. Sair" );
    scanf( "%d" , pBuffer );

    switch ( *( int* )pBuffer ){
        case 1:
            pBuffer = AdicionarPessoa( pBuffer , numPessoas );
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

void * AdicionarPessoa( void * pBuffer, void * numPessoas ){
    //numPessoas++
     ( *( int * )numPessoas )++;

    //  Aloque o espaço de:       op e numP       +         numPessoas       *   nome, idade, email
    pBuffer = realloc( pBuffer, 2 * sizeof( int ) + ( *( int * )numPessoas ) * ( 40 * sizeof( char ) + sizeof( int ) ) );

    //pessoaAtual vai apontar depois:  op e numPessoas +    ( numPessoas - 1 )            *   tamanho Pessoa
    void * pessoaAtual = ( pBuffer + 2 * sizeof( int ) + ( ( *( int * )numPessoas ) - 1 ) * ( 40 * sizeof( char ) + sizeof( int ) ) );

    printf( "Digite o nome da pessoa: " );
    //Guarda o nome
    scanf("%s", pessoaAtual);

    printf( "Digite a idade da pessoa: " );
    //Guarda idade após o nome
    scanf("%d", ( pessoaAtual + sizeof( char ) * 20 ) );

    printf( "Digite o email da pessoa: " );
    //Guarda email após o nome e idade
    scanf( "%s", ( pessoaAtual + sizeof( char ) * 20  + sizeof( int ) ) );

    return pBuffer;

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

    //numPessoas -> espaço após operação
    void * numPessoas = ( pBuffer + sizeof( int ) );

    //numPessoas = 0
    *( int * )numPessoas = 0;

    while(1){
        Menu( pBuffer , numPessoas );
    }
}