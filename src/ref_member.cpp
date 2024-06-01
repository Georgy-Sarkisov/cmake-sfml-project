#include <iostream>
#include <string>
using namespace std;

struct Person {
	explicit Person(string& name) : name(name) {};
	string& name;
};

// int main() {
//   string name = "Ilya";
//   Person person(name);
//   cout << person.name << endl;
//   name = "Alex";
//   cout << person.name << endl;
//   person.name = "John";
//   cout << name;
//   return 0;
// }

Person default_name() {
	string def_name = "Ivan";
	return Person(def_name);
}

int main() {

	string Ilya = "Ilya";
	Person ilya(Ilya);
	string Alex = "Alex";
	Person alex(Alex);

	// ilya = move(alex);

	cout << ilya.name << ", " << alex.name << "|" << endl;

	cout << default_name().name; // ¬ис€ча€ ссылка
}