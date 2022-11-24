#pragma once
#include <iostream>
#include <string>
#include <vector>

using namespace std;

class ExpressionChecker {
	private:
		vector <string> articulosDefinidos;
		vector <string> articulosIndefinidos;
		vector <string> sustantivosImpropios;
		vector <string> sustantivosPropios;
		vector <string> verbos;
		vector <string> adjetivos;
		vector <string> adverbios;
		vector <string> enlace;
		vector <string> palabrasTotal;
		vector <string> listIndex;

	public:
		ExpressionChecker();
		vector <string> splitString(string &input);
		bool verificacion1(vector <string> expression);
		bool verificacion2(vector <string> expression);
		bool verificacion3(vector <string> expression);
		bool verificacion4(vector <string> expression);
		bool verificacion5(vector <string> expression);
		bool verificacion6(vector <string> expression);
		bool verificacion7(vector <string> expression);
		bool verificacion8(vector <string> expression);
		bool verificacionVerbo(vector <string> expression);
		bool verificacionAdjetivo(vector <string> expression);
		bool verificacionAdverbio(vector <string> expression);
		bool Inicio(vector <string> expression);
		bool validar(vector <string> expression);
		bool basePalabras(vector <string> expression);

};
