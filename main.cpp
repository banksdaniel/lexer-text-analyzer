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
static vector<string> delimitadores = {" ", "(", ")", ";"};
static vector<string> palavrasReservadas = {"for", "if", "while", "E", "OU", "NAO"};

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

class simbolosLexicos
{
private:
    int id;
    vector<int> identificador = {};
    vector<string> lexema = {};
    vector<string> token = {};

public:
    simbolosLexicos()
    {
        id = 1;
    }
    void print()
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

bool operador(string character)
{
    if (std::find(operadores.begin(), operadores.end(), character) != operadores.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool delimitador(string character)
{
    if (std::find(delimitadores.begin(), delimitadores.end(), character) != delimitadores.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

bool palavraReservada(string character)
{
    if (std::find(palavrasReservadas.begin(), palavrasReservadas.end(), character) != palavrasReservadas.end())
    {
        return true;
    }
    else
    {
        return false;
    }
}

string getToken(string nome)
{
    for (int i = 0; i < 26; i++)
    {
        if (nome.compare(valores[i].token) == 0)
        {
            return valores[i].nome;
        }
    }
}
bool numerico(string character)
{
    if ((int(character.at(0)) >= 48) and (int(character.at(0)) <= 57))
    {
        return true;
    }
    else
    {
        return false;
    }
}
bool letra(string character)
{
    if ((int((character.at(0)) >= 65) and (int(character.at(0)) <= 90)) or ((int(character.at(0)) >= 96) and (int(character.at(0)) <= 122)))
    {
        return true;
    }
    else
    {
        return false;
    }
}
