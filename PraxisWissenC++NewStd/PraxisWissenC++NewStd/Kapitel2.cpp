#include "stdafx.h"
#include "Kapitel2.h"

#include <map>

using namespace std;


Kapitel2::Kapitel2() {}


Kapitel2::~Kapitel2() {}

void Kapitel2::bedingungMitInitialisierer()
{
	map<int, string> zw{ {1, "eins"}, {2, "zwei"}, {3, "drei"}};

	// *** geht erst ab MSVC 2018 ***
	/*if (bool it = zw.find(2); it != zw.end())
	{
		cout << it->second << endl;
	}
	else {
		cout << "<NOT FOUND>" << endl;
	}*/

	cout << "Bedingungen mit Initialisierer geht erst ab C++17 und MSVC 2018" << endl;
} 