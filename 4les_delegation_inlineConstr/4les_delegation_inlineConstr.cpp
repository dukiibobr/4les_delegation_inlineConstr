#include <iostream>
#include <string>
#include <fstream>
using namespace std;
//#define PI 3.14;
//
//inline void hello() {
//	cout << "hello" << endl;
//}
//
//
//class Human {
//	string name;
//	int age;
//	int weight;
//
//public:
//	static int countHumans;
//	Human() :name("no name"), age(0), weight(0) { countHumans++; }
//	//Human()
//	//{
//	//	name = "no name";
//	//	age = 0;
//	//	weight = 0;
//	//}
//
//	Human(string name):Human()
//	{
//		this->name = name;
//		//age = 0;
//		//weight = 0;
//	}
//	//Human(int age)
//	//{
//	//	name = "no name";
//	//	this->age = age;
//	//	weight = 0;
//	//}
//	//Human(int weight)
//	//{
//	//	name = "no name";
//	//	age = 0;
//	//	this->weight = weight;
//	//}
//	
//	Human(string name,int age):Human(name)
//	{
//		//this->name = name;
//		this->age = age;
//		//weight = 0;
//	}
//	//Human(string name,int weight)
//	//{
//	//	this->name = name;
//	//	age = 0;
//	//	this->weight = weight;
//	//}
//	//Human(int age,int weight)
//	//{
//	//	name = "no name";
//	//	this->age = age;
//	//	this->weight = weight;
//	//}
//
//	Human(string name, int age, int weight) :Human(name, age)
//	{
//		//this->name = name;
//		//this->age = age;
//		this->weight = weight;
//	}
//	
//
//
//	void print() {
//		cout << "name: " <<name<< endl;
//		cout << "age: " << age<<endl;
//		cout << "weight: " <<weight<< endl;
//		cout << endl;
//	}
//
//};
//
//
//int Human::countHumans = 0;

//1

class Abonent {
	string name;
	string surname;
	string middlename;

	int homePhone;
	int workPhone;
	int mobilePhone;

	string additionalInfo;

public:
	static int countAbonents;


	Abonent():Abonent("no name", "no surname", "no middlename",0,0,0, "no info")
	{}
	


	Abonent(string name, string surname, string middlename):Abonent( name,  surname,  middlename, 0, 0, 0, "no info")
	{}
	


	Abonent(string name,string surname,string middlename,int homePhone,int workPhone,int mobilePhone,string additionalInfo)
	{
		this->name = name;
		this->surname = surname;
		this->middlename = middlename;

		this->homePhone = homePhone;
		this->workPhone = workPhone;
		this->mobilePhone = mobilePhone;

		this->additionalInfo = additionalInfo;

		countAbonents++;

	}



	void print() {
		cout << "name: " << name << endl;
		cout << "surname: " << surname << endl;
		cout << "middlename: " << middlename << endl;

		cout << "homePhone: " << homePhone << endl;
		cout << "workPhone: " << workPhone << endl;
		cout << "mobilePhone: " << mobilePhone << endl;

		cout << "info: " << additionalInfo << endl;
		cout << endl;
	}


	void changeInfo() {
		cout << "change additional info: ";
		getline(cin >>ws, additionalInfo) ;
	}

	bool hasPhone(int phone) {
		return homePhone == phone or
			 workPhone == phone or
			 mobilePhone == phone;

	}

	string getName() {
		return name;
	}

	void addAbonentToFile(ofstream& out) {
		out << name << endl;;
		out << surname << endl;;
		out << middlename << endl;;
		out << homePhone << endl;;
		out << workPhone << endl;;
		out << mobilePhone << endl;;
		out << additionalInfo << endl;;

		out.close();
	}

};






class PhoneBook
{
	Abonent* abonents=nullptr;
	int size = 0;
public:

	void Add(Abonent a) {
		Abonent* temp = new Abonent[size + 1];

		for (int i = 0; i < size; i++)
		{
			temp[i] = abonents[i];
		}
		temp[size] = a;

		delete[]abonents;
		abonents = temp;
		size++;
	}

	

	void Delete(int phone) {
		int index = -1;
		for (int i = 0; i < size; i++)
		{
			if (abonents[i].hasPhone(phone))
			{
				index = i;
				break;
			}
		}
		if (index==-1)
		{
			cout << "abonent not found" << endl;
			return;
		}
		Abonent* toDelete = new Abonent[size - 1];
		int j = 0;
		for (int i = 0; i < size; i++)
		{
			if (i!=index)
			{
				toDelete[j] = abonents[i];
				j++;
			}
		}
		delete[]abonents;
		abonents = toDelete;
		size--;
	}

	void SearchByName(string name) {
		bool found = 0;
		for (int i = 0; i < size; i++)
		{
			if (abonents[i].getName()==name)
			{
				cout << endl;
				cout << "abonent found" << endl;
				abonents[i].print();
				cout << endl;

				found = 1;
			}
		}
		if (found!=1)
		{
			cout << "name not found" << endl;
		}
	}

	void SearchByPhone(int phone) {
	
		bool found = 0;
		for (int i = 0; i < size; i++)
		{
			if (abonents[i].hasPhone(phone))
			{
				cout << endl;
				cout << "abonent found" << endl;
				abonents[i].print();
				cout << endl;

				found = 1;
			}
		}
		if (found != 1)
		{
			cout << "phone not found" << endl;
		}
	}

	void ShowAll() {
	
		for (int i = 0; i < size; i++)
		{
			abonents[i].print();
		}
	}

	void addToFile(string name) {
		ofstream out("abonents.txt", ios_base::out);
		if (!out.is_open())
		{
			cout << "file is not open" << endl;
			return;
		}
		for (int i = 0; i < size; i++)
		{
			if (abonents[i].getName() == name)
			{
				abonents[i].addAbonentToFile(out);
				cout << "abonent saved" << endl;
				return;
			}
		}
		cout << "abonent not found" << endl;
		out.close();
	}

	void showFromFile() {
		char buff[300];
		ifstream in;
		in.open("abonents.txt", ios_base::out);
		if (in.is_open())
		{
			cout << endl;
			cout << "read from file below" << endl;
			while (!in.getline(buff,300))
			{
				cout << buff << endl;
			}
			in.close();

		}
		else
		{
			cout << "error";
		}
	}

	~PhoneBook() {
		delete[]abonents;
	}
};

int Abonent::countAbonents = 0;
int main()
{
	//2

	PhoneBook p1;
	Abonent a2("q","w","e",1,2,3,"hio");
	Abonent a3("qwfre","wwvegdrf","e",1124,233,3345,"hio");
	Abonent a4("qrjyt","jertyw","jktyee",56342,26534,336524,"hioewrg");
	Abonent a1("qe", "ryjew", "e");

	p1.Add(a1);
	p1.Add(a2);
	p1.Add(a3);
	p1.Add(a4);
	p1.Delete(0);
	p1.SearchByName("q");
	p1.SearchByPhone(233);
	p1.addToFile("q");
	p1.showFromFile();
	p1.ShowAll();
	//1
	
	//Abonent a1;
	//a1.print();

	//Abonent a2("q","w","e",1,2,3,"hio");
	//a2.print();

	//Abonent a3("q","w","e");
	//a3.changeInfo();
	//a3.print();
	//cout << "abonents amount: " << Abonent::countAbonents << endl;






	//cout << "count: " << Human::countHumans << endl;
	//Human h1;
	//h1.print();
	//cout <<"count: "<< h1.countHumans << endl;

	//Human h2("oleg");
	//h2.print();
	//cout << "count: " << h2.countHumans << endl;

	//	Human h5("hjb",36);
	//h5.print();

	//cout << "count: " << h5.countHumans << endl;
	//	Human h8("hjb",30,80);
	//h8.print();
	//cout << "count: " << h8.countHumans << endl;
	//cout << "count: " << h5.countHumans << endl;


	//hello();
	//cout << PI;
}


