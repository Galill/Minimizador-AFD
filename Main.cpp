#include "FileReader.h"
#include "Automato.h"

using namespace std;

int main() {
	FileReader file;
	Automato afd;

	file.readFile();
	afd.minimizarAutomato();

	return 0;
}
