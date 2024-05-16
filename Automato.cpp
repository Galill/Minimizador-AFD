#include <iostream>
#include <string>
#include <set>
#include <map>
#include "Automato.h"

using namespace std;

std::set<std::string> Automato::estados;
std::set<char> Automato::alfabeto;
std::set<std::string> Automato::estados_finais;
std::set<std::string> Automato::estado_inicial;
std::map<std::pair<std::string, std::pair<std::string, char>>, bool> Automato::transicoes;

void Automato::minimizarAutomato() {
    std::map<pair<string, string>, bool> tabela_distinguibilidade;
    for (auto estado_origem : estados) {
        for (auto estado_destino : estados) {
            if (estado_origem > estado_destino) {
                if ((estados_finais.count(estado_origem) && !estados_finais.count(estado_destino)) ||
                    (!estados_finais.count(estado_origem) && estados_finais.count(estado_destino))) {
                    tabela_distinguibilidade[std::make_pair(estado_origem, estado_destino)] = true;
                }
                else {
                    tabela_distinguibilidade[std::make_pair(estado_origem, estado_destino)] = false;
                }
            }
        }
    }
    cout << "Passo 1: \nCriar a tabela de distinguibilidade e preencher ela com os pares em que apenas um estado e final" << endl;
    for (auto x : tabela_distinguibilidade) {
        auto par = x.first;
        bool distinguivel = x.second;

        if (par.first > par.second) {
            cout << par.first << " " << par.second << ": " << (distinguivel ? "Distinguivel" : "Nao distinguivel") << endl;
        }
    }
    cout << endl;
     
   

    for (auto x : tabela_distinguibilidade) {
        auto par = x.first;
        bool distinguivel = x.second;

        if (par.first > par.second) {
            cout << par.first << " " << par.second << ": " << (distinguivel ? "Distinguivel" : "Nao distinguivel") << endl;
        }
    } 
}
