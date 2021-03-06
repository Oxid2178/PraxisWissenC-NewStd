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
#include "SmartPointer.h"
#include "Account.h"
#include "Customer.h"
#include "IOwner.h"
#include "AccountImpl.h"
#include "CustomerImpl.h"
#include "GCDwithTemplate.h"
#include "RandomNumberGenerator.h"
#include "IncreasingNumberGenerator.h"
#include "ToSquare.h"
#include "ILoggingFacility.h"
#include "StandardOutputLoggerImpl.h"
#include "CustomerRepository.h"
#include "CustomerStrategy.h"
#include "JsonFormatter.h"
#include "XmlFormatter.h"
#include "PlainTextFormatter.h"
#include "Formatter.h"
#include "Client.h"
#include "DrawClient.h"
#include "CompositeClient.h"
#include "SpreadsheetModel.h"
#include "TableView.h"
#include "PieChartView.h"
#include "BarChartView.h"
#include "LoggerFactory.h"
#include "ProcessFactory.h"
#include "IProcessService.h"


using namespace std;

// CleanC++17FunctionalProgFunctor
using Numbers = std::vector<short>;
const std::size_t AMOUNT_OF_NUMBERS{ 100 };

Numbers createVectorFilledWithRandomNumbers()
{
	RandomNumberGenerator<short> randomNumberGenerator{};
	Numbers randomNumbers(AMOUNT_OF_NUMBERS);
	std::generate(begin(randomNumbers), end(randomNumbers), std::ref(randomNumberGenerator));
	return randomNumbers;
}

void printNumbersOnStdOut(const Numbers &numbers)
{
	for (const auto &number : numbers)
	{
		std::cout << number << std::endl;
	}
}



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

	// Clean C++17, Seite 166 --> weak_ptr
	auto sharedResource(make_shared<Ressource>(4));
	weak_ptr<Ressource> weakResource(sharedResource);

	SmartPointer smartPointer;
	smartPointer.doSomethingWithNoOwnedResource(weakResource);
	smartPointer.doSomethingWithNoOwnedResource(weakResource);
	smartPointer.doSomethingWithNoOwnedResource(weakResource);
	smartPointer.doSomethingWithNoOwnedResource(weakResource);
	sharedResource.reset(); // Delete the managed instance of ResourceType
	smartPointer.doSomethingWithNoOwnedResource(weakResource);

	// Vorsicht mit shared_ptr bei cycles (e.g. zwei Klassen die voneinander
	// abhängig sind). Da wird der ptr-Counter nie auf 0 herunter gezählt.
	// Dadurch ensteht ein Memory Leak. Der Einsatz von weak_ptr ist hier 
	// die Lösung.


	// CleanC++17AvoidCyclicDependencyPrinciple
	// Bad implementation, page 265
	cout << "*** The bad implementation with cyclic dependency ***" << '\n';
	Account  *account = new Account();
	Customer *customer = new Customer();
	account->setOwner(customer);
	customer->setAccount(account);

	// CleanC++17DependencyInvPrinciple
	// Almost good and very good implementation, page 270/271
	cout << "*** The almost good and very good implementation without cyclic dependency ***" << '\n';
	//IOwnerPtr owner = std::make_shared<CustomerImpl>();
	CustomerPtr owner = std::make_shared<CustomerImpl>();
	AccountPtr account2 = std::make_shared<AccountImpl>();
	owner->setAccount(account2);
	account2->setOwner(owner);

	// CleanC++17FunctionalProgGCD
	cout << "*** GCD with Templates ***" << '\n';
	cout << "The GCD of 40 and 10 is: " << GCDwithTemplate::GreatestCommonDivisor<40u, 10u>::result << '\n';
	cout << "*** C++11 GCD with constexpr function ***" << '\n';
	cout << "The GCD of 256 and 8 is: " << GCDwithTemplate::greatestCommonDivisor(256u, 8) << '\n';
	cout << "*** C++17 GCD with Standard Library gcd --> std::gcd not supported with this compiler...***" << '\n';
	//constexpr auto result = std::gcd(80, 4);
	//cout << "The GCD of 40 and 10 is: " << result << '\n';

	// CleanC++17FunctionalProgFunctor
	cout << "*** Functional Programming with Functor ***" << '\n';
	Numbers randomNumbers = createVectorFilledWithRandomNumbers();
	printNumbersOnStdOut(randomNumbers);

	// CleanC++17FunctionalProgUnaryFunction
	cout << "*** Functional Programming with Unary Function ***" << '\n';
	Numbers numbers(AMOUNT_OF_NUMBERS);
	generate(begin(numbers), end(numbers), IncreasingNumberGenerator());
	transform(begin(numbers), end(numbers), begin(numbers), ToSquare());
	printNumbersOnStdOut(numbers);

	// CleanC++17DesignPatternDependInject
	LoggerPtr logger = std::make_shared<StandardOutputLoggerImpl>();
	const int CUSTOMID = 1;
	CustomerRepository customerRepository{ logger };
	customerRepository.findCustomerById(CUSTOMID);

	// CleanC++17DesignPatternStrategy
	FormatPtr formatter = make_unique<JsonFormatter>();
	CustomerStrategy customerStrategy{};
	cout << customerStrategy.getAsFormattedString(formatter);

	FormatPtr formatter2 = make_unique<XmlFormatter>();
	cout << customerStrategy.getAsFormattedString(formatter2);

	FormatPtr formatter3 = make_unique<PlainTextFormatter>();
	cout << customerStrategy.getAsFormattedString(formatter3);

	// CleanC++17DesignPatternCommand
	cout << "CleanC++17DesignPatternCommand" << "\n";
	Client client{};
	client.run();

	// CleanC++17DesignPatternCommandProcessor
	cout << "CleanC++17DesignPatternCommandProcessor" << "\n";
	DrawClient drawClient{};
	drawClient.run();

	// CleanC++17DesignPatternComposite
	cout << "CleanC++17DesignPatternComposite" << "\n";
	CompositeClient compositeClient{};
	compositeClient.run();

    // CleanC++17DesignPatternObserver
	cout << "CleanC++17DesignPatternObserver" << "\n";
    SpreadsheetModel spreadsheetModel{};

    IObserverPtr observer1 = std::make_shared<TableView>(spreadsheetModel);
    spreadsheetModel.addObserver(observer1);

    IObserverPtr observer2 = std::make_shared<BarChartView>(spreadsheetModel);
    spreadsheetModel.addObserver(observer2);

    IObserverPtr observer3 = std::make_shared<PieChartView>(spreadsheetModel);
    spreadsheetModel.addObserver(observer3);

    spreadsheetModel.changeCellValue("A", 1, 42.5);

    spreadsheetModel.removeObserver(observer1);

    spreadsheetModel.changeCellValue("B", 2, 23.1);

    spreadsheetModel.removeObserver(observer2);

    spreadsheetModel.changeCellValue("C", 3, 3.14);

    spreadsheetModel.removeObserver(observer3);

    // CleanC++17DesignPatternFactory
    cout << "CleanC++17DesignPatternFactory" << "\n";
    string configFilePath = "../configFileForLoggerCreationFile.txt";
    LoggerFactory loggerFactory{ configFilePath };
    try
    {
        LoggerPtr loggerPtr = loggerFactory.create();
        CustomerRepository customRepo{ loggerPtr };
        customRepo.findCustomerById(CUSTOMID);
    }
    catch (const char* e)
    {
        cerr << e;
    }
    
    // CleanC++17DesignPatternFacade
    cout << "CleanC++17DesignPatternFacade" << "\n";
    ProcessFactory processFactory{};
    IProcessServicePtr processService = processFactory.createProcessServiceInstance();
    processService->doProcess();

    // CleanC++17DesignPatternMoneyClass
    cout << "CleanC++17DesignPatternMoneyClass" << "\n";



	//const char* utf8TxtMsg = u8"Bitte druecken Sie eine Taste zum beenden";
	//std::cout << "\n" << utf8TxtMsg;
	//char any;
	//std::cin >> any;
	system("pause");
	return 0;
}