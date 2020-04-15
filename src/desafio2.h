#ifndef CABECALHO_DESAFIO2_H_INCLUDED
#define CABECALHO_DESAFIO2_H_INCLUDED

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>

// Não há tipo booleano em C, portanto
// vamos criar um para facilitar a leitura
// de operações booleanas no código:
#define BOOL int
#define TRUE 1
#define FALSE 0

static const char SENTENCETOKENSEPARATOR = ' ';

// Array: descrição de texto dos possíveis verbos de comando.
static const char commandverbs[1][5] =
{
    "00000"
};
static const int DESCRPOSVERBTERMINATE = 0;

// Indicando aqui qual o valor máximo do telefone,
// de acordo com o enunciado do exercício.
#define LARGESTTELEFONEPARAMSIZE 30

/*
 * Constantes e estruturas para organizar as operações de um telefone.
 *
*/
static const char* PLATFORMINDEPENDENTSTREND = "\r\n";
static const char* LINUXSTREND = "\n";
static const char* WINSTREND = "\r\n";

static const char* PVALIDCHARS = "ABCDEFGHIJKLMNOPQRSTUVXWYZ0123456789-";
#define TABELAMAXROWS 8
#define TABELAMAXITEMSIZE 5
static const char TABELADECONVERSAO[TABELAMAXROWS][TABELAMAXITEMSIZE] =
{
    "ABC",
    "DEF",
    "GHI",
    "JKL",
    "MNO",
    "PQRS",
    "TUV",
    "WXYZ"
};

// Enumeração para auxiliar a identificar qual é o
// comando associado ao que o usuário digitou.
enum enumAction {unknown, terminate, translate};

struct Telefone {
    enum enumAction action;
    char numero[LARGESTTELEFONEPARAMSIZE+1];
} typedef stTelefone;

/*
 * Analisadores Léxicos (analisam uma sentença para validar
 * a sintaxe dos comandos).
*/
BOOL telefonelexicalanalyser(const char *const sentence, stTelefone* ptelefone);

BOOL terminatelexicalanalyser(const char *const sentence);

/*
 * Os comandos do sistema.
*/
BOOL terminatecommand(void);
void translatecommand(const stTelefone *const ptelefone);

/*
 * Inicia a captura dos comandos digitados pelo usuário.
 *
*/
void iniciaTELEFONE(void);

#endif
