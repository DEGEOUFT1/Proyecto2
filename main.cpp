#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include "ExpressionAnalyzer.h"

using namespace std;

void menu() {
	string input;
	const char delimiter = ' ';
	vector <string> expression;
	ExpressionChecker* ec1 = new ExpressionChecker();

	getline(cin, input);
	expression = ec1->splitString(input);

	bool valid = ec1->basePalabras(expression);

    if (!valid) {
        if (ec1->validar(expression) == true){
		cout << "La oración ingresada es válida" << endl;
		} else {
		cout << "Oración inválida, no se puede tener más de un verbo, adjetivo y/o adverbio en una oración simple" << endl;
		}
    } else {
        cout << "La oracion ingresada es inválida" << endl;
        cout << "-------------------------------------------------------------------------------------------" << endl;
    }
}

int main() {
	cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "Bienvenido al analizador de oraciones en español." << endl;
    cout << "Por favor tener en cuenta las siguientes recomendaciones:" << endl;
    cout << "- Cada palabra debe estar separada por un espacio, para ser reconocida." << endl;
    cout << "- Por el momento, la lista de palabras aceptadas es limitada, ver la lista de palabras en el código." << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    while (true) {
        cout << "Ingresa la oración simple a analizar:" << endl;
        menu();
        cout << "¿Deseas evaluar otra oración? (N/S)" << endl;
        string answer;
        getline(cin, answer);
        cout << "-------------------------------------------------------------------------------------------" << endl;
        if (answer == "N" || answer == "n") {
            break;
        }
    }
    cout << "" << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;
    cout << "Programa finalizado." << endl;
    cout << "Gracias por usar el analizador de oraciones simples en español." << endl;
    cout << "-------------------------------------------------------------------------------------------" << endl;

    return 0;
	
}
