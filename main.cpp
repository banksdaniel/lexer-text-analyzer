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

