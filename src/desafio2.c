/*
* Desafio 2
* Matheus Peschke de Azevedo - RA: 20396209
* Gustavo Caldas de Souza    - RA: 21352329
*
* Se você tiver uma conta no Github, envie seu endereço
* cadastrado no Github para 'mpeschke@gmail.com', para ter
* acesso ao repositório privado onde está essa solução, estruturada
* com testes unitários para validação de qualidade.

*/
#include "desafio2.h"

/*
 *
 *********************ANALISADOR LÉXICO (TOKENIZADOR)*****************************************
 *
 * Definições que fazem parte de um analisador léxico:
 *
 * 'sentença' = a linha de comando com todos os seus parâmetros
 * 'token' = um item que esteja separados dos outros por um ou mais espaços.
 *
 * Exemplo:
 *
 *          10        20        30
 *          |         |         |
 * 012345678901234567890123456789
 * 55-11-ANHEMBI-MORUMBI
 * ^                   ^
 * |                   |
 * |   token (número)  |
*/

/* A partir do cursor inicial fornecido, avança até encontrar o próximo token.
 *
 * Exemplo:
 *          10        20        30
 *          |         |         |
 * 012345678901234567890123456789
 * 55-11-ANHEMBI-MORUMBI
 * ^
 * |
 * token (número)
 * |
 * *pposicaoleiturainicial = 0.
 * |
 * *pposicaoleiturainicial = 0.
*/
int advancetonexttoken(const char *const    sentence,
                       const int *const     pinitialposition,
                       const int *const     psentencesize)
{
    // Para procurar pelo próximo token, deve estar apontando para um separador de tokens.
    // Se já estiver num caracter válido para token, retorna essa posição como o início de
    // um token válido.
    int i = *pinitialposition;

    while((i < *psentencesize) && (sentence[i] == SENTENCETOKENSEPARATOR))
        i++;

    return i;
}

/* Copia o token para um buffer, identificando também onde termina esse token na sentença.
 *
 * Exemplo:
 *          10        20        30
 *          |         |         |
 * 012345678901234567890123456789
 * 55-11-ANHEMBI-MORUMBI
 * ^                   ^
 * |                   |
 * token (número)      |
 * |                   |
 * *pposicaoleiturainicial = 0.
 *                     |
 *                     *pposicaoleiturafinal = 20.
 * token = '55-11-ANHEMBI-MORUMBI'
*/
BOOL getsentencetoken(const int* const  pposicaoleiturainicial,
                      int*              pposicaoleiturafinal,
                      const char* const sentence,
                      const int* const  pmaxsizesentence,
                      char*             token,
                      const int* const  pmaxsizetoken)
{
    // Limpa o buffer para receber um novo token.
    memset((void*)token, '\0', *pmaxsizetoken);

    int i = 0;
    int j = -1;
    *pposicaoleiturafinal = *pposicaoleiturainicial;
    for(i = *pposicaoleiturainicial; i < *pmaxsizesentence; i++)
    {
        if(sentence[i] != SENTENCETOKENSEPARATOR)
        {
            // O buffer do token tem um tamanho limitado, não necessariamente igual
            // ao buffer da sentença.
            if(j+1 < *pmaxsizetoken)
            {
                *token = sentence[i];
                token++;
            }
            j++;
        }
        else
            break;
    }

    *pposicaoleiturafinal = *pposicaoleiturainicial + j;
    return (j != -1);
}

/* Combina 'advancetonexttoken' e 'getsentencetoken' para facilitar a sequência de leitura
 * consecutiva dos tokens numa mesma sentença.
 * Copia o token para um buffer, identificando também onde termina esse token na sentença.
 *
 * Exemplo:
 *          10        20        30
 *          |         |         |
 * 01234567890123456789012345678901
 * 55-11-ANHEMBI-MORUMBI OUTROTOKEN
 * ^                    ^^        ^
 * |                    ||        |
 *                      *pposicaoleiturainicial = 21.
 *                       |*pposicaoleiturainicial = 22.
 *                       |        |*pposicaoleiturafinal = 31.
 *                       |token ('OUTROTOKEN')
*/
BOOL getnextsentencetoken(int* const        pposicaoleiturainicial,
                          int*              pposicaoleiturafinal,
                          const char* const sentence,
                          const int* const  pmaxsizesentence,
                          char*             token,
                          const int* const  pmaxsizetoken)
{
    const int sentencesize = strlen(sentence);

    *pposicaoleiturainicial = ++(*pposicaoleiturafinal);
    *pposicaoleiturainicial = *pposicaoleiturafinal = advancetonexttoken(sentence, pposicaoleiturainicial, &sentencesize);
    return getsentencetoken(pposicaoleiturainicial, pposicaoleiturafinal, sentence, pmaxsizesentence, token, pmaxsizetoken);
}

// Parsing do buffer - se tiver a string '00000' interpreta
// como o comando para terminar a aplicação, caso contrário
// sinaliza que o sistema deve tentar traduzir o número.
enum enumAction parsetokenaction(const char* buff)
{
    if(strcmp(buff, commandverbs[DESCRPOSVERBTERMINATE]) == 0)
        return terminate;
    else
        return translate;
}

// Valida caracter a caracter os números do telefone,
// fazendo a tradução das letras para os respectivos números.
BOOL validateandtranslate(stTelefone* ptelefone)
{
    unsigned long numerosize = strlen(ptelefone->numero);

    // A função 'strchr' é crítica nesse algoritmo,
    // que compara o número fornecido pelo usuário
    // com os caracteres válidos, e também vai procurando
    // na matriz de grupos (a tabela de conversão) de letras qual o número correspondente.
    for(unsigned long i = 0U; i < numerosize; i++) // percorre os chars da sentença
    {
        char* ppos = strchr(PVALIDCHARS, ptelefone->numero[i]);
        if(ppos == NULL)
            return FALSE;
        else
            for(unsigned long j = 0U; j < TABELAMAXROWS; j++) // percorre os grupos de letras na tabela de conversão
                if(strchr(TABELADECONVERSAO[j], ptelefone->numero[i]) != NULL) // encontrou o caracter num grupo de conversão
                {
                    char onechar[2] = {'\0'};
                    // Aproveita ordem dos grupos no array de conversão
                    // para inferir o número que corresponde àquele grupo (ex 'ABC' = 0 + 2).
                    sprintf(onechar, "%d", (int)j+2);
                    ptelefone->numero[i] = onechar[0];
                    break;
                }
    }

    return TRUE;
}

/*
 *
 *********************ANALISADOR LÉXICO (COMANDO 'TRANSLATETELEFONE')*************************
 *
* Exemplo de comando 'translatetelefone':
* '1-HOME-SWEET-HOME'
* 'MY-MISERABLE-JOB'
* Máximo comprimento da string: 30
*
* IMPORTANTE:
*
* Assume-se também, pelo enunciado, que uma entrada maior que 30 dígitos é inválida.
* Portanto o sistema vai igorar essas entradas como inválidas.
*/
BOOL telefonelexicalanalyser(const char *const sentence, stTelefone* ptelefone)
{
    int sentencesize = strlen(sentence);
    if (sentencesize > LARGESTTELEFONEPARAMSIZE)
        return FALSE;

    char tokenbuffer[LARGESTTELEFONEPARAMSIZE];
    int tokensize = LARGESTTELEFONEPARAMSIZE;

    int tokeninitialpos = 0;
    int tokenfinalpos = tokeninitialpos;

    // Primeiro token é o comando 'terminar' ou o número para 'traduzir'.
    tokeninitialpos = advancetonexttoken(sentence, &tokeninitialpos, &sentencesize);
    if(!getsentencetoken(&tokeninitialpos, &tokenfinalpos, sentence, &sentencesize, tokenbuffer, &tokensize))
        return FALSE;

    enum enumAction action = parsetokenaction(tokenbuffer);
    ptelefone->action = action;

    // Não pode haver outros tokens.
    if(getnextsentencetoken(&tokeninitialpos, &tokenfinalpos, sentence, &sentencesize, tokenbuffer, &tokensize))
        return FALSE;

    if(action == translate)
        return validateandtranslate(ptelefone);

    return TRUE;
}

/*
 *
 ***************************************(COMANDO 'TRANSLATE')*********************************
 *
*/
void translatecommand(const stTelefone *const ptelefone)
{printf("%s\n", ptelefone->numero);}

/*
 * Infelizmente o Ruindows considera como terminador de
 * linha dois caracteres, '\r' e '\n'. Como não sabemos se o
 * exercício será avaliado num Ruindows, tratamos as diferenças
 * de plataforma nessa função.
*/
char* platformindependent_terminatorchar(char* buff)
{
    // Retorna a posição ao encontrar o primeiro desses caracteres terminadores.
    unsigned long pos = strcspn(buff, "\r\n");
    // Como pode encontrar o caracter terminador APÓS a string,
    // Identificamos como não encontrado (string vazia).
    if(pos >= strlen(buff))
        return NULL;
    else
        return &buff[pos];
}

// Identifica se a string contém apenas os caracteres terminadores de linha
// (ou CRLF - 'Carriage Return, Line Feed'), tanto pra Linux como pra Windows.
BOOL platformindependent_str_terminatorchar(char* buff)
{return (strcmp(buff, LINUXSTREND) == 0) || (strcmp(buff, WINSTREND));}

/*
 * fgets, ao contrário da função (insegura) scanf, inclui
 * os caracteres terminadores de linha (\n no Linux, \r\n no Windows).
 * Essa função coloca um caracter nulo na primeira instância desses
 * caracteres terminadores, garantindo um buffer contendo apenas
 * o token da sentença.
*/
void zero_fgets_trailchars(char* buff)
{buff[strcspn(buff, PLATFORMINDEPENDENTSTREND)] = 0;}

/*
 * fgets, por segurança, vai continuamente alimentando o buffer
 * até o final da entrada (stdin), até encontrar um caracter terminador.
 * Por isso tratamos a função de acordo, considerando apenas a primeira
 * vez em que ela preenche o buffer, e ignorando o resto das entradas.
*/
void read_fgets_firstbuffer(char* buff, char* finalbuff, BOOL* potherbuffersfound)
{
    /* BUFF[MAXBUFFPLACAR+2U]
     *          |10
     * 01234567890123456789
     * 20 19n0
     *      ^^
     *      ||
     *      fgets vai adicionar na posição 5 o terminador (se houver)
     *      e terminar a string adicionando \0 na posição 6.
     *       |
     *       |tamanho real do buffer: (MAXBUFFPLACAR+2U).
    */
    char* presult = fgets(buff, LARGESTTELEFONEPARAMSIZE+1U, stdin);
    // Nos interessa apenas o conteúdo da primeira vez em
    // que o fgets preenche o buffer vindo de stdin (entrada do teclado).
    strcpy(finalbuff, buff);
    char* newlinefound = platformindependent_terminatorchar(presult);
    zero_fgets_trailchars(finalbuff);
    while(newlinefound == NULL)
    {
        // Ainda não encontrou o terminador nessa cópia do
        // buffer - preenche continuamente o buffer até encontrar.
        presult = fgets(buff, LARGESTTELEFONEPARAMSIZE+1U, stdin);
        newlinefound = platformindependent_terminatorchar(presult);
        // Se na próxima leitura do buffer houver algo além do terminador,
        // o usuário digitou mais do que o limite de 30 números/caracteres.
        if(!platformindependent_str_terminatorchar(buff))
            *potherbuffersfound = TRUE;
    }
}

/*
 *
 ***************************************INICIA A LEITURA E CONVERSÃO DOS TELEFONES*************
 *
*/
void iniciaTELEFONE(void)
{
    BOOL bterminate = FALSE;

    // Fica num looping eterno, até que o usuário digite o
    // comando para sair.
    while(!bterminate)
    {
        char BUFF[LARGESTTELEFONEPARAMSIZE+2U] = {'\0'};
        BOOL otherbuffersfound = FALSE;

        stTelefone tel = {
            .action = unknown,
            .numero = {'\0'}
        };

        read_fgets_firstbuffer(BUFF, tel.numero, &otherbuffersfound);
        if(otherbuffersfound)
            continue;

        if (telefonelexicalanalyser(tel.numero, &tel))
        {
            if(tel.action == terminate)
                bterminate = TRUE;
            else
                translatecommand(&tel);
        }
    }
}

// li e concordo com os termos da aps
