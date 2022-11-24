#include <iostream>
#include <string>
#include <vector>
#include <sstream>
#include <algorithm>
#include <iterator>
#include "ExpressionAnalyzer.h"

using namespace std;

ExpressionChecker::ExpressionChecker(){
	this->articulosDefinidos = {"el", "los", "la", "las"};
	this->articulosIndefinidos = {"un", "una", "unas", "unos"};
	this->sustantivosImpropios = {"adulto", "adultos", "joven", "jovenes", "perro", "perros", "gato", "gatos", "papá", "papás"};
	this->sustantivosPropios = {"juan", "diego", "camila", "david", "maria", "ana"};
	this->verbos = {"juega", "juegan", "jugaron", "jugarán", "come", "comen", "comieron", "comerán", "canta", "cantan","cantaron", "cantarán", "salta", "saltan", "saltaron", "saltarán", "corren",  "corre", "corrió", "correrán"};
	this->adjetivos = {"grande", "feo", "malo", "bueno","divertido", "rapido", "bonito", "duro"};
	this->enlace = {"con","y"};
	this->palabrasTotal = {"el", "los", "la", "las", "un", "uno", "una", "unas", "unos", "perro", "perros", "gato", "gatos", "papá", "papás", "juan", "diego", "camila", "david", "maria", "ana", "juega", "juegan", "jugaron", "jugarán", "come", "comen", "comieron", "comerán", "canta", "cantan","cantarán", "cantarán", "salta", "saltan", "saltaron", "saltarán", "corren",  "corre", "corrió", "correrán", "grande", "feo", "malo", "bueno","divertido", "rapido", "bonito", "duro", "con","y"};
}

vector <string> ExpressionChecker::splitString(string &input) {
    istringstream ss(input);
	string token;

	vector<string> expression;
	while(getline(ss, token, ' ')) {
		expression.push_back(token);
	}
	return expression;
}

bool ExpressionChecker::verificacion1(vector <string> expression){
	bool containsSustantivosPropios = false;
	bool containsArticulosDefinidos = false;
	bool containsVerbos = false;

	for(int i = 0; i<this->sustantivosPropios.size(); i++){
		if(expression[0].compare(this->sustantivosPropios[i]) == 0){
			containsSustantivosPropios = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[0].compare(this->articulosDefinidos[i]) == 0){
			containsArticulosDefinidos = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){
		if(expression[1].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}

	if (containsSustantivosPropios || (containsArticulosDefinidos && containsVerbos)){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacion2(vector <string> expression){
	bool containsArticulosDefinidos = false;
	bool containsArticulosIndefinidos = false;
	bool containsSustantivosImpropios = false;
	bool containsVerbos = false;

	for(int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[0].compare(this->articulosDefinidos[i]) == 0){
			containsArticulosDefinidos = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosIndefinidos.size(); i++){
		if(expression[0].compare(this->articulosIndefinidos[i]) == 0){
			containsArticulosIndefinidos = true;
			break;
		}
	}

	for(int i = 0; i<this->sustantivosImpropios.size(); i++){
		if(expression[1].compare(this->sustantivosImpropios[i]) == 0){
			containsSustantivosImpropios = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){
		if(expression[2].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}

	if (containsArticulosDefinidos || (containsArticulosIndefinidos && containsSustantivosImpropios && containsVerbos)){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacion3(vector <string> expression){
	bool containsArticulosIndefinidos = false;
	bool containsSustantivosImpropios = false;
	bool containsVerbos = false;

	for(int i = 0; i<this->articulosIndefinidos.size(); i++){
		if(expression[0].compare(this->articulosIndefinidos[i]) == 0){
			containsArticulosIndefinidos = true;
			break;
		}
	}
	
	for(int i = 0; i<this->sustantivosImpropios.size(); i++){
		if(expression[1].compare(this->sustantivosImpropios[i]) == 0){
			containsSustantivosImpropios = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){	
		if(expression[2].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}

	if (containsArticulosIndefinidos && containsSustantivosImpropios && containsVerbos){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacion4(vector <string> expression){
	bool containsArticulosDefinidos = false;
	bool containsArticulosIndefinidos = false;
	bool containsSustantivosImpropios = false;
	bool containsVerbos = false;
	bool containsAdjetivos = false;

	for(int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[0].compare(this->articulosDefinidos[i]) == 0){
			containsArticulosDefinidos = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosIndefinidos.size(); i++){
		if(expression[0].compare(this->articulosIndefinidos[i]) == 0){
			containsArticulosIndefinidos = true;
			break;
		}
	}

	for(int i = 0; i<this->sustantivosImpropios.size(); i++){
		if(expression[1].compare(this->sustantivosImpropios[i]) == 0){
			containsSustantivosImpropios = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){
		if(expression[2].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}

	for(int i = 0; i<this->adjetivos.size(); i++){
		if(expression[3].compare(this->adjetivos[i]) == 0){
			containsAdjetivos = true;
			break;
		}
	}

	if (containsArticulosDefinidos || (containsArticulosIndefinidos && containsSustantivosImpropios && containsVerbos && containsAdjetivos)){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacion5(vector <string> expression){
	bool containsSustantivosPropios = false;
	bool containsVerbos = false;
	bool containsAdjetivos = false;
	bool containsAdverbios = false;

	for(int i = 0; i<this->sustantivosPropios.size(); i++){
		if(expression[0].compare(this->sustantivosPropios[i]) == 0){
			containsSustantivosPropios = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){
		if(expression[1].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}
	
	for(int i = 0; i<this->adjetivos.size(); i++){
		if(expression[2].compare(this->adjetivos[i]) == 0){
			containsAdjetivos = true;
			break;
		}
	}

	for(int i = 0; i<this->adverbios.size(); i++){
		if(expression[2].compare(this->adverbios[i]) == 0){
			containsAdverbios = true;
			break;
		}
	}

	if ((containsSustantivosPropios && containsVerbos && containsAdjetivos) || containsAdverbios){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacion6(vector <string> expression){
	bool containsSustantivosPropios = false;
	bool containsArticulosDefinidos = false;
	bool containsVerbos = false;
	bool containsAdverbios = false;
	bool containsAdjetivos = false;

	for(int i = 0; i<this->sustantivosPropios.size(); i++){
		if(expression[0].compare(this->sustantivosPropios[i]) == 0){
			containsSustantivosPropios = true;
			break;
		}
	}

	for( int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[0].compare(this->verbos[i]) == 0){
			containsArticulosDefinidos = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){
		if(expression[1].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}
	
	for(int i = 0; i<this->adjetivos.size(); i++){
		if(expression[2].compare(this->adjetivos[i]) == 0){
			containsAdjetivos = true;
			break;
		}
	}

	for(int i = 0; i<this->adverbios.size(); i++){
		if(expression[2].compare(this->adverbios[i]) == 0){
			containsAdverbios = true;
			break;
		}
	}

	if (containsSustantivosPropios || containsArticulosDefinidos && containsVerbos && containsAdverbios || containsAdjetivos){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacion7(vector <string> expression){
	bool containsSustantivosPropios = false;
	bool containsVerbos = false;
	bool containsEnlace = false;
	bool containsArticulosDefinidos = false;
	bool containsSustantivosImpropios = false;
	bool containsArticulosIndefinidos = false;

	for(int i = 0; i<this->sustantivosPropios.size(); i++){
		if(expression[0].compare(this->sustantivosPropios[i]) == 0){
			containsSustantivosPropios = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){
		if(expression[1].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}

	for(int i = 0; i<this->enlace.size(); i++){
		if(expression[2].compare(this->enlace[i]) == 0){
			containsEnlace = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[3].compare(this->verbos[i]) == 0){
			containsArticulosDefinidos = true;
			break;
		}
	}
	
	for(int i = 0; i<this->sustantivosImpropios.size(); i++){
		if(expression[4].compare(this->sustantivosImpropios[i]) == 0){
			containsSustantivosImpropios = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosIndefinidos.size(); i++){
		if(expression[4].compare(this->articulosIndefinidos[i]) == 0){
			containsArticulosIndefinidos = true;
			break;
		}
	}

	if (containsSustantivosPropios && containsVerbos && containsEnlace && containsArticulosDefinidos && containsSustantivosImpropios || containsArticulosIndefinidos){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacion8(vector <string> expression){
	bool containsArticulosDefinidos1 = false;
	bool containsArticulosIndefinidos1 = false;
	bool containsSustantivosImpropios1 = false;
	bool containsVerbos = false;
	bool containsEnlace = false;
	bool containsArticulosDefinidos2 = false;
	bool containsArticulosIndefinidos2 = false;
	bool containsSustantivosImpropios2 = false;

	for(int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[0].compare(this->verbos[i]) == 0){
			containsArticulosDefinidos1 = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosIndefinidos.size(); i++){
		if(expression[0].compare(this->articulosIndefinidos[i]) == 0){
			containsArticulosIndefinidos1 = true;
			break;
		}
	}

	for(int i = 0; i<this->sustantivosImpropios.size(); i++){
		if(expression[1].compare(this->sustantivosImpropios[i]) == 0){
			containsSustantivosImpropios1 = true;
			break;
		}
	}

	for(int i = 0; i<this->verbos.size(); i++){
		if(expression[2].compare(this->verbos[i]) == 0){
			containsVerbos = true;
			break;
		}
	}

	for(int i = 0; i<this->enlace.size(); i++){
		if(expression[3].compare(this->enlace[i]) == 0){
			containsEnlace = true;
			break;
		}
	}
	
	for(int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[4].compare(this->verbos[i]) == 0){
			containsArticulosDefinidos2 = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosIndefinidos.size(); i++){
		if(expression[4].compare(this->articulosIndefinidos[i]) == 0){
			containsArticulosIndefinidos2 = true;
			break;
		}
	}

	for(int i = 0; i<this->sustantivosImpropios.size(); i++){
		if(expression[5].compare(this->sustantivosImpropios[i]) == 0){
			containsSustantivosImpropios2 = true;
			break;
		}
	}

	if (containsArticulosDefinidos1 || containsArticulosIndefinidos1 && containsSustantivosImpropios1 && containsVerbos && containsEnlace && containsArticulosDefinidos2 || containsArticulosIndefinidos2 && containsSustantivosImpropios2){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::verificacionVerbo(vector <string> expression){
	int c = 0;
	for(int i = 0; i<expression.size(); i++){
		for(int j = 0; j<this->verbos.size(); j++){
			if(expression[i].compare(this->verbos[j]) == 0){
				c++;
			}
		}
	}

	if(c >= 2){
		return false;
	} else {
		return true;
	}
}

bool ExpressionChecker::verificacionAdjetivo(vector <string> expression){
	int c = 0;
	for(int i = 0; i<expression.size(); i++){
		for(int j = 0; j<this->adjetivos.size(); j++){
			if(expression[i].compare(this->adjetivos[j]) == 0){
				c++;
			}
		}
	}
	
	if(c >= 2){
		return false;
	} else {
		return true;
	}
}

bool ExpressionChecker::verificacionAdverbio(vector <string> expression){
	int c = 0;
	for(int i = 0; i<expression.size(); i++){
		for(int j = 0; j<this->adverbios.size(); j++){
			if(expression[i].compare(this->adverbios[j]) == 0){
				c++;
			}
		}
	}
	
	if(c >= 2){
		return false;
	} else {
		return true;
	}
}

bool ExpressionChecker::Inicio(vector <string> expression){
	bool inicioarticulosDefinidos = false;
  bool inicioarticulosIndefinidos =false;
  bool iniciosustantivosPropios= false;
  bool iniciosustantivosImpropios=false;
  for(int i = 0; i<this->sustantivosImpropios.size(); i++){
		if(expression[0].compare(this->sustantivosImpropios[i]) == 0){
			iniciosustantivosImpropios = true;
			break;
		}
	}
	for(int i = 0; i<this->sustantivosPropios.size(); i++){
		if(expression[0].compare(this->sustantivosPropios[i]) == 0){
			iniciosustantivosPropios = true;
			break;
		}
	}
  for(int i = 0; i<this->articulosIndefinidos.size(); i++){
		if(expression[0].compare(this->articulosIndefinidos[i]) == 0){
			inicioarticulosIndefinidos = true;
			break;
		}
	}

	for(int i = 0; i<this->articulosDefinidos.size(); i++){
		if(expression[0].compare(this->articulosDefinidos[i]) == 0){
			inicioarticulosDefinidos= true;
			break;
		}
	}
	if(inicioarticulosDefinidos||inicioarticulosIndefinidos||iniciosustantivosPropios||iniciosustantivosImpropios){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::validar(vector <string> expression){
	if(this->Inicio(expression) != true){
		return false;
	}
	
	if(this->verificacionAdjetivo(expression) != true){
		return false;
	}
	if(this->verificacionAdverbio(expression) != true){
		return false;
	}
	if(this->verificacionVerbo(expression) != true){
		return false;
	} else if(this->verificacionVerbo(expression) || this->verificacionAdverbio(expression) || this->verificacionAdjetivo(expression) || this->verificacion1(expression) || this->verificacion2(expression) || this->verificacion3(expression) || this->verificacion4(expression) || this->verificacion5(expression) || this->verificacion6(expression) || this->verificacion7(expression) || this->verificacion8(expression)){
		return true;
	} else {
		return false;
	}
}

bool ExpressionChecker::basePalabras(vector<string> expression){
	bool variable = false;
	for(int i = 0; i<expression.size(); i++){
		if(count(this->palabrasTotal.begin(), this->palabrasTotal.end(), expression[i]) == 0){
			variable = true;
		}
	}
	return variable;
}
