#include "stdafx.h"
#include "Kap3Templates.h"

using namespace std;


Kap3Templates::Kap3Templates()
{
}


Kap3Templates::~Kap3Templates()
{
}

void Kap3Templates::kap3_1variablenTemplates()
{
	var<int> = 3;
	var<double> = 2.702;
	var<string> = "Antonio";
	// Ausgabe: 3, 2.702, Antonio
	cout << var<int> << ", " << var<double> << ", " << var<string> << endl;

}
