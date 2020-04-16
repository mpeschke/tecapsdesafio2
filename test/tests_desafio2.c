/*
* Desafio 2
* Matheus Peschke de Azevedo - RA: 20396209
* Gustavo Caldas de Souza    - RA: 21352329
* Marcelo                    - RA: 21359738
*
* Se você tiver uma conta no Github, envie seu endereço
* cadastrado no Github para 'mpeschke@gmail.com', para ter
* acesso ao repositório privado onde está essa solução, estruturada
* com testes unitários para validação de qualidade.
*/
#include "tests_desafio2.h"

void test_unittests_desafio_2(const int lexicalanalyser, const char* sentence)
{
    stTelefone telefone = { .action = unknown, .numero = {'\0'} };

    switch(lexicalanalyser)
    {
        case 1:// Testa cenário válido para o analisador léxico 'telefonelexicalanalyser'
        {
            strcpy(telefone.numero, sentence);
            BOOL ret = telefonelexicalanalyser(sentence, &telefone);
            printf("Valor retornado: %s. Número '%s' traduzido para '%s'",
                   ret == TRUE ? "TRUE" : "FALSE",
                   sentence,
                   telefone.numero);
            break;
        }
        default:
            break;
    };
}

int main(int argc, char* argv[])
{
    test_unittests_desafio_2(atoi(argv[1]), argv[2]);

    return 0;
}

// li e concordo com os termos da aps
