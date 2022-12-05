#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
using namespace std;

struct Dicionario
{
    string token;
    string nome;
};

static vector<string> operadores = {"+", "-", "/", "*", "!=", "==", "=", "<", "<=", ">", ">=", "++", "--", "<-"};
static vector<string> palavrasReservadas = {"for", "if", "while", "E", "OU", "NAO"};
static vector<string> delimitadores = {" ", "(", ")", ";"};

static Dicionario valores[26] = {
    {"+", "OPSOMA"},
    {"-", "OP SUB"},
    {"*", "OP MUL"},
    {"/", "OP DIV"},
    {"!=", "NAO IGUAL A"},
    {"==", "IGUAL"},
    {"=", "ATRIBUICAO"},
    {"<", "MENOR QUE"},
    {">", "MAIOR QUE"},
    {"<=", "MENOR OU IGUAL"},
    {">=", "MAIOR OU IGUAL"},
    {"++", "INCREMENTO"},
    {"--", "DECREMENTO"},
    {";", "FIM DA LINHA"},
    {"(", "ABRE PARENTESES"},
    {")", "FECHA PARENTESES"},
    {"NUMR", "NUMERO REAL"},
    {"INT", "INTEIRO"},
    {"ID", "IDENTIFICADOR"},
    {"FOR", "PALAVRA RESERVADA"},
    {"IF", "PALAVRA RESERVADA"},
    {"WHILE", "PALAVRA RESERVADA"},
    {"<-", "ATRIBUICAO"},
    {"E", "PALAVRA RESERVADA"},
    {"OU", "PALAVRA RESERVADA"},
    {"NAO", "PALAVRA RESERVADA"}};

class tabelaSimbolosLexico
{
private:
    int id;
    vector<int> identificador = {};
    vector<string> lexema = {};
    vector<string> token = {};

public:
    tabelaSimbolosLexico()
    {
        id = 1;
    }
    void printar()
    {
        cout << "id\t\t\tLexema\t\t\tTipo de Token" << endl;
        for (int i = 0; i < identificador.size(); i++)
        {
            cout << identificador[i] << "\t\t\t" << lexema[i] << "\t\t\t" << token[i] << endl;
        }
    };
    void adicionarLexema(string lexemaSTR, string tokenSTR)
    {
        identificador.push_back(id);
        id += 1;
        lexema.push_back(lexemaSTR);
        token.push_back(tokenSTR);
    };
};