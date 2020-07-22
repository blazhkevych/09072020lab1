/*
Задание 1
Создайте класс Student, который будет содержать информацию о студенте.
С помощью механизма наследования, реализуйте класс
Aspirant (аспирант – студент, который готовится к защите
кандидатской работы) производный от Student.
*/
#include <iostream>
#include <windows.h>
using namespace std;

class Student {
	char* NAME;
	char* GROUPNUMBER;
	int AGE;
	double AVG;
public:
	Student() : NAME(nullptr), GROUPNUMBER(nullptr), AGE(0), AVG(0.0) {}
	Student(const char* name, const char* groupnumber, int age, double avg) {
		NAME = _strdup(name);
		GROUPNUMBER = _strdup(groupnumber);
		AGE = age;
		AVG = avg;
	}
	void Print() {
		cout << "Прізвище, імя, по батькові : " << NAME << endl;
		cout << "№ групи: " << GROUPNUMBER << endl;
		cout << "Вік студента : " << AGE << endl;
		cout << "Середній бал студента : " << AVG << endl;
	}
	~Student() { delete[]NAME;  delete[]GROUPNUMBER; }
};

class Aspirant : public Student {
	char* PROTECTION_DATE;
	char* TOPIC;
public:
	Aspirant() : Student(), PROTECTION_DATE(nullptr), TOPIC(nullptr) {}
	Aspirant(const char* name, const char* groupnumber, int age, double avg, const char* protection_date,
		const char* topic) : Student(name, groupnumber, age, avg) {
		PROTECTION_DATE = _strdup(protection_date);
		TOPIC = _strdup(topic);
	}
	void Print() {
		Student::Print();
		cout << "Дата захисту кандидатської роботи : " << PROTECTION_DATE << endl;
		cout << "Тема кандидатської роботи : " << TOPIC << endl;
	}
	~Aspirant() { delete[]PROTECTION_DATE;  delete[]TOPIC; }
};

int main()
{
	setlocale(LC_ALL, ""); //працює тільки з потоком виведення
	SetConsoleCP(1251); //встановлює потрібну кодову таблицю, на потік введення
	SetConsoleOutputCP(1251); //встановлює потрібну кодову таблицю, на потік виводу.
	Aspirant A("Ігор Іванович Пупкін", "PE911", 25, 11.5, "25.10.2020", "Державне регулювання розвитку фондового ринку в Україні");
	A.Print();
}