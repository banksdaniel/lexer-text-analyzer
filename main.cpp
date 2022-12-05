#include <iostream>
#include <vector>
#include <algorithm>    
#include <cstring>
using namespace std;


struct Dicionario{
    string token;
    string nome;
};

static    vector<string> operadores = {"+","-","/","*","!=" ,"==","=","<","<=",">",">=","++","--","<-"};
static    vector<string> palavrasReservadas = {"for", "if","while","E","OU","NAO"};
static    vector<string> delimitadores = {" ","(",")",";"};

static  Dicionario valores[26] = {
        {"+","OPSOMA"},
        {"-","OP SUB"},
        {"*","OP MUL"},
        {"/","OP DIV"},
        {"!=","NAO IGUAL A"},
        {"==","IGUAL"},
        {"=","ATRIBUICAO"},
        {"<","MENOR QUE"},
        {">","MAIOR QUE"},
        {"<=","MENOR OU IGUAL"},
        {">=","MAIOR OU IGUAL"},
        {"++","INCREMENTO"},
        {"--","DECREMENTO"},
        {";","FIM DA LINHA"},
        {"(","ABRE PARENTESES"},
        {")","FECHA PARENTESES"},
        {"NUMR","NUMERO REAL"},
        {"INT","INTEIRO"},
        {"ID","IDENTIFICADOR"},
        {"FOR","PALAVRA RESERVADA"},
        {"IF","PALAVRA RESERVADA"},
        {"WHILE","PALAVRA RESERVADA"},
        {"<-","ATRIBUICAO"},
        {"E","PALAVRA RESERVADA"},
        {"OU","PALAVRA RESERVADA"},
        {"NAO","PALAVRA RESERVADA"}
    };