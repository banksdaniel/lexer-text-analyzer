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

int main()
{

    string texto;
    std::cout << "Entre com uma expressao:" << std::endl;
    std::getline(cin, texto);

    simbolosLexicos tabela;
    string lexema = "";
    int tamanhoLexema = 0;
    string variavel = "";

    int tamanhoVariavel = 0;
    bool numReal = false;
    int tamanhoExpressao = texto.length();

    for (int i = 0; i < tamanhoExpressao; i++)
    {

        string character(1, texto.at(i));

        if (delimitador(character) or operador(character))
        {
            if (tamanhoLexema > 0)
            {
                if (numReal)
                {
                    tabela.adicionarLexema(lexema, getToken("NUMR"));
                }
                else
                {
                    tabela.adicionarLexema(lexema, getToken("INT"));
                }
                lexema = "";
                tamanhoLexema = 0;
                variavel = "";
                tamanhoVariavel = 0;
                numReal = false;
            }
            else if (tamanhoVariavel > 0)
            {
                if (palavraReservada(variavel))
                {
                    tabela.adicionarLexema(variavel, getToken(variavel));
                }
                else
                {
                    tabela.adicionarLexema(variavel, getToken("ID"));
                }
                variavel = "";
                tamanhoVariavel = 0;
            }
            if (character != " ")
            {
                tabela.adicionarLexema(character, getToken(character));
                lexema = "";
                variavel = "";
                tamanhoVariavel = 0;
                tamanhoLexema = 0;
            }
        }
        else if (numerico(character))
        {
            lexema = lexema + character;
            tamanhoLexema += 1;
            if ((i + 1) == tamanhoExpressao)
            {
                if (numReal)
                {
                    tabela.adicionarLexema(lexema, getToken("NUMR"));
                }
                else
                {
                    tabela.adicionarLexema(lexema, getToken("INT"));
                }
            }
        }
        else if ((character == ".") or (character == ","))
        {
            numReal = true;
            lexema = lexema + character;
        }
        else if (letra(character))
        {
            if ((i + 1) >= tamanhoExpressao)
            {
                variavel = variavel + character;
                if (palavraReservada(character))
                {
                    tabela.adicionarLexema(lexema, getToken(character));
                    variavel = "";
                    tamanhoVariavel = 0;
                }
                else
                {
                    tabela.adicionarLexema(lexema, getToken("ID"));
                    variavel = "";
                    tamanhoVariavel = 0;
                }
            }
            else
            {
                variavel = variavel + character;
                tamanhoVariavel += 1;
            }
        }
    }

    tabela.print();
    cout << "Terminou!" << endl;
    return 0;
}