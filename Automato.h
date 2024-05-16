#pragma once
#include <iostream>
#include <string>
#include <set>
#include <map>

class Automato {

public:
   static std::set<std::string> estados;
   static std::set<char> alfabeto;
   static std::set<std::string> estados_finais;
   static std::set<std::string> estado_inicial;
   static std::map<std::pair<std::string, std::pair<std::string, char>>, bool> transicoes;

    void minimizarAutomato();
};
