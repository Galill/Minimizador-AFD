#include <fstream>
#include <iostream>
#include <string>
#include <set>
#include <map>
#include "FileReader.h"

using namespace std;

void FileReader::readFile() {
	ifstream file;
	string file_name, line;
	set<string> estados, estados_finais, estado_inicial;
	set<char> alfabeto;
	map<pair<string, pair<string, char>>, bool> transicoes;

	cout << "Arquivo: ";
	cin >> file_name;

	file.open(file_name);

	if (!file.is_open()) {
		cout << "Erro ao abrir o arquivo!" << endl;
	}

	while (getline(file, line)) {
		if (line.find("alfabeto:") != string::npos) {
			size_t aux = line.find(":");
			if (aux != string::npos) {
				string linha_alfabeto = line.substr(aux + 1);
				size_t aux_virgula = 0;
				while ((aux_virgula = linha_alfabeto.find(",")) != string::npos) {
					for (size_t i = 0; i < linha_alfabeto.length(); i++) {
						if (linha_alfabeto[i] != ' ' && linha_alfabeto[i] != ',') {
							alfabeto.insert(linha_alfabeto[i]);
							break;
						}
					}
					linha_alfabeto.erase(0, aux_virgula + 1);
				}
				for (size_t i = 0; i < linha_alfabeto.length(); i++) {
					if (linha_alfabeto[i] != ' ') {
						alfabeto.insert(linha_alfabeto[i]);
						break;
					}
				}
			}
		}
		else if (line.find("estados:") != string::npos) {
			size_t aux = line.find(":");
			if (aux != string::npos) {
				string linha_estados = line.substr(aux + 1);
				size_t aux_virgula = 0;
				while ((aux_virgula = linha_estados.find(",")) != string::npos) {
					string estado = linha_estados.substr(0, aux_virgula);
					estados.insert(estado);
					linha_estados.erase(0, aux_virgula + 1);
				}
				estados.insert(linha_estados);
			}
		}
		else if (line.find("inicial:") != string::npos) {
			size_t aux = line.find(":");
			if (aux != string::npos) {
				string linha_estado_inicial = line.substr(aux + 1);
				estado_inicial.insert(linha_estado_inicial);
			}
		}
		else if (line.find("finais:") != string::npos) {
			size_t aux = line.find(":");
			if (aux != string::npos) {
				string linha_estados_finais = line.substr(aux + 1);
				size_t aux_virgula = 0;
				while ((aux_virgula = linha_estados_finais.find(",")) != string::npos) {
					string estado_final = linha_estados_finais.substr(0, aux_virgula);
					estados_finais.insert(estado_final);
					linha_estados_finais.erase(0, aux_virgula + 1);
				}
				estados_finais.insert(linha_estados_finais);
			}
		}
		else if(line.find("transicoes:") != string::npos){

		}
		else {
			size_t aux_virgula1 = line.find(",");
			size_t aux_virgula2 = line.find(",", aux_virgula1 + 1);
			size_t aux_espaço = line.find(" ", aux_virgula2 + 1);
			string origem = line.substr(0, aux_virgula1);
			string destino = line.substr(aux_virgula1 + 1, aux_virgula2 - aux_virgula1 - 1);
			char simbolo = line[aux_espaço + 1];
			transicoes[make_pair(origem, make_pair(destino, simbolo))] = true;
		}
	}

	file.close();

	cout << "Estados encontrados:" << endl;
	for (auto x : estados) {
		cout << x;
	}
	cout << endl;

	cout << "Alfabeto encontrado:" << endl;
	for (auto x : alfabeto) {
		cout << x;
	}
	cout << endl;

	cout << "Estado inicial encontrado:" << endl;
	for (auto x : estado_inicial) {
		cout << x;
	}
	cout << endl;

	cout << "Estados finais encontrados:" << endl;
	for (auto x : estados_finais) {
		cout << x;
	}
	cout << endl;

	cout << "Transicoes encontradas:" << endl;
	for (auto const& entry : transicoes) {
		auto const& origem = entry.first.first;
		auto const& destino = entry.first.second.first;
		auto const& simbolo = entry.first.second.second;
		cout << origem << " -> " << destino << ": " << simbolo << endl;
	}
}