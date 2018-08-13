// PraxisWissenNewStd.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Lambdas.h"
#include "BinaryTreeNode.h"
#include "Kapitel2.h"
#include "Kap3Templates.h"
#include "Kap4Bibliothek.h"
#include "Ressource.h"
#include "Lebewesen.h"
#include "Katze.h"
#include "Hund.h"
#include "HundeNutzer.h"
#include "Person.h"
#include "UserOfConvService.h"
#include "ICurrencyConverter.h"
#include "CurrConvServiceMock.h"
#include "RealtimeCurrConvService.h"


using namespace std;

int main()
{
    Lambdas lam;
	std::cout << lam.add(2, 5) << std::endl;

	lam.doSomething();
	lam.func();
	lam.printName();

	BinaryTreeNode tree(1, new BinaryTreeNode(2, new BinaryTreeNode(3, nullptr, nullptr), new BinaryTreeNode(4, nullptr, nullptr)), new BinaryTreeNode(5, nullptr, nullptr));
	tree.accept([] ( BinaryTreeNode& visitor ) { std::cout << visitor.getValue() << std::endl; });

	// 2.33 Bedingungen mit Initialisierer
	Kapitel2 kap2;
	kap2.bedingungMitInitialisierer();

	Kap3Templates kap3Templates;
	kap3Templates.kap3_1variablenTemplates();
	std::cout << kap3Templates.Max(3.4, 5.6) << std::endl;

	// 3.9 Variadische Templates
	cout << kap3Templates.BinToNumber<1, 1, 1, 1>() << endl;
	cout << kap3Templates.BinToNumber<1, 0, 0, 0, 0, 0, 0, 1>() << endl;

	// 4.3 Shared Pointer
	// TODO

	// ****** Der C++ Programmierer, Kap. 32.1 unique_ptr *******
	cout << "Zeiger auf dynamisches Objekt:\n";
	//unique_ptr<Ressource> p1(new Ressource(1));
	//unique_ptr<Ressource> p1 { make_unique<Ressource>(1) };
	auto p1 { make_unique<Ressource>(1) };
	cout << "Operator -> ";
	p1->hi();
	cout << "Operator * ";
	(*p1).hi();
	unique_ptr<Ressource> nullp1(nullptr);
	// nullp->hi(); // Speicherzugriffsfehler!

	// Kap. 32.1.1 make_unique
	std::vector<std::unique_ptr<Ressource>> vpu(10);
	// Initialisierung aller Elemente:
	for (std::size_t i = 0; i < vpu.size(); ++i)
	{
		vpu[i] = std::make_unique<Ressource>(i); 
		// Zuweisung:
		// Die Zuweisung ist möglich, weil ein temporäres Objekt (R-Wert) zugewiesen wird. Die
		// Zuweisung eines L-Wertes ist nicht erlaubt, weil dann eine Kopie entstünde, die intern
		// auf dasselbe Objekt verweisen würde. Es widerspräche der Eigenschaft unique.

		// statt vpu[i] = std::unique_ptr<Ressource>(new Ressource(i));
	}
	// Benutzung
	std::cout << "Werte:\n";
	for (const auto& ptr : vpu)
	{
		ptr->hi();
	}
	std::cout << '\n';
	// Destruktoren werden automatisch aufgerufen

	// Kap. 32.2 Shared Pointer
	cout << "Zeiger auf dynamische Objekte:\n";
	cout << "Konstruktoraufruf\n";
	//shared_ptr<Ressource> p2(new Ressource(1));
	auto p2{ make_shared<Ressource>(1) };
	cout << "Operator -> ";
	p2->hi();
	cout << "Operator * ";
	(*p2).hi();
	cout << "Benutzungszähler: " << p2.use_count() << '\n'; // 1
	{
		// zweiter shared_ptr für dasselbe Objekt
		//shared_ptr<Ressource> p3(p2);
		auto p3(p2);
		cout << "Benutzungszähler p2: " << p2.use_count() << '\n'; // 2
		cout << "Benutzungszähler p3: " << p3.use_count() << '\n'; // 2
		p2->hi();
	}
	cout << "Benutzungszähler p2: " << p2.use_count() << '\n'; // 1
	cout << "Objekt exisiert noch: ";
	p2->hi();
	// Zuweisung
	//shared_ptr<Ressource> p4(new Ressource(3));
	auto p4{ make_shared<Ressource>(3) };
	p4 = p2; // Ressource 3 wird freigegeben (delete), danach verweisen beide auf das Objekt *p2
	p2->hi();
	p4->hi();
	// Null-Zeiger
	shared_ptr<Ressource> nullp2(nullptr);
	//nullp->hi(); // Speicherzugriffsfehler!
	// p4 und p2 werden am Ende des Programms/Blocks zerstört

	// **********************************************************


	// Vererbung, Interfaces, Assoziationen (Der C++ Programmierer, Kap. 22)
	{
		//shared_ptr<Katze> pKatze(new Katze(75.0f, 1.72f));
		auto pKatze{ make_shared<Katze>(75.0f, 1.72f) };
		cout << "BMI der Katze ist: " << pKatze->berechneBMI() << '\n';
		pKatze->essen();
		pKatze->essen();
		cout << "Neuer BMI der Katze ist: " << pKatze->berechneBMI() << '\n';
	}
	
	Katze *katze = new Katze(75.0f, 1.72f);
	cout << "BMI der Katze ist: " << katze->berechneBMI() << '\n';
	katze->essen();
	katze->~Katze();

	Hund hund(73.5f, 1.72f);
	HundeNutzer hundeNutzer(hund);
	hundeNutzer.essenMitHund();
	hundeNutzer.spieleMitHund();
	cout << "BMI des Hundes ist: " << hundeNutzer.gibBMI() << '\n';
	hund.~Hund();
	hundeNutzer.~HundeNutzer();

	hund.setGewicht(73.5f);
	hund.setGroesse(1.72f);
	cout << "BMI des Hundes ist: " << hund.berechneBMI() << '\n';
	hund.essen();
	hund.spielen();
	hund.spielen();
	hund.spielen();
	cout << "Neuer BMI des Hundes ist: " << hund.berechneBMI() << '\n';
	hund.~Hund();

	// bidirektrionle Assoziation...
	Person antonio("Antonio");
	Person luca("Luca");
	Person alessio("Alessio");
	antonio.lerntkennen(luca);
	antonio.bekannteZeigen();
	luca.bekannteZeigen();
	alessio.bekannteZeigen();
	alessio.lerntkennen(luca);
	alessio.lerntkennen(antonio);
	alessio.lerntkennen(alessio);
	alessio.bekannteZeigen();

	// Clean C++17, Seite 63 --> Real implementation or Test Mock with Interfaces
	std::shared_ptr<ICurrencyConverter> serviceToUse = std::make_shared<CurrConvServiceMock>();
	//std::shared_ptr<ICurrencyConverter> serviceToUse = std::make_shared<RealtimeCurrencyConversionService>();
	UserOfConvService user(serviceToUse);
	user.doSomething();
	
	
	
	//const char* utf8TxtMsg = u8"Bitte druecken Sie eine Taste zum beenden";
	//std::cout << "\n" << utf8TxtMsg;
	//char any;
	//std::cin >> any;
	system("pause");
	return 0;
}