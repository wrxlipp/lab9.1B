#include <iostream>
#include <iomanip>
#include <stdio.h>
#include <Windows.h>
#include <stdarg.h>
#include <conio.h>
#include <string>

using namespace std;

enum Spec { RI, KN, PM };
const char* strSpec[] = { "RI", "KN", "PM" };
const char* Convert(Spec c) {
	return strSpec[c];
}

struct Student {
	string prizv;
	int kurs;
	Spec spec;
	union {
		unsigned infor;
		unsigned methods;
		unsigned ped;
	};
	unsigned fis;
	unsigned math;
};

void Create(Student* s, const int n) {
	int p;

	for (int i = 0; i < n; i++) {
		cout << endl;
		cout << "Student # " << i + 1 << ":" << endl;
		cin.get();
		cin.sync();

		cout << "Surname: "; getline(cin, s[i].prizv);
		cout << "Course: "; cin >> s[i].kurs;
		cout << "Spec (0 - RI, 1 - KN, 2 - PM): ";
		cin >> p;
		s[i].spec = (Spec)p;
		cout << "Scores" << endl;
		cout << endl;
		cout << "Physics: "; cin >> s[i].fis;
		cout << "Math: "; cin >> s[i].math;
		switch (s[i].spec) {
		case RI:
			cout << "Informatics: "; cin >> s[i].infor;
			break;
		case KN:
			cout << "Number Methods: "; cin >> s[i].methods;
			break;
		case PM:
			cout << "Pedagogy: "; cin >> s[i].ped;
			break;

		}
	}
	cout << endl;
}

void Table(Student* s, const int n)
{
	cout << fixed;
	cout << "|" << setw(42) << "Student" << setw(35) << "   |" << endl;
	cout << "------------------------------------------------------------------------------" << endl;

	cout << "|" << setw(10) << "Surname" << "  |  "
		<< setw(3) << "Course" << "  |  "
		<< setw(3) << "Spec" << "  |"
		<< setw(3) << "Physics" << "  |  "
		<< setw(3) << "Math" << "  |  "
		<< setw(3) << "Infor" << "  |  "
		<< setw(3) << "Methods" << "  |  "
		<< setw(3) << "Ped" << "  |" << endl;

	cout << "------------------------------------------------------------------------------" << endl;
	for (int i = 0; i < n; i++) {
		cout << "|  " << setw(2); cout << s[i].prizv << "  |  " << setw(5);
		cout << s[i].kurs << "  |" << setw(5);
		cout << Convert(s[i].spec) << "  |  " << setw(5);
		cout << s[i].fis << "  |" << setw(6);
		cout << s[i].math << "  |" << setw(6);
		switch (s[i].spec) {
		case RI:
			cout << s[i].infor << "  |" << setw(9) <<  "  |" << setw(9) << "  |" << endl; 
			break;
		case KN:
			cout << setw(9) << "  |" << setw(6) << s[i].methods << "  |" << setw(9) << "  |" << endl;
			break;
		case PM:
			cout << setw(9) << "  |" << setw(9) << "  |  " << setw(6) << s[i].ped
				 << "  |" << endl;
			break;
		}
		cout << "------------------------------------------------------------------------------" << endl;
	}
}

int Count1(Student* s, const int n) {
	int c = 0;
	for (int i = 0; i < n; i++) {
		switch (s[i].spec) {
		case RI:
			if (s[i].fis > 3 && s[i].math > 3 && s[i].infor > 3)
				c++;
			break;
		case KN:
			if (s[i].fis > 3 && s[i].math > 3 && s[i].methods > 3)
				c++;
			break;
		case PM:
			if (s[i].fis > 3 && s[i].math > 3 && s[i].ped > 3)
				c++;
			break;
		}
	}
	return c;
}

void Count2(Student* s, const int n) {
	double e = 0, proc;
	for (int i = 0; i < n; i++) {
		switch (s[i].spec) {
		case RI:
			if ((s[i].fis + s[i].math + s[i].infor)/3 < 4)
				e++;
			break;
		case KN:
			if ((s[i].fis + s[i].math + s[i].methods)/3 < 4)
				e++;
			break;
		case PM:
			if ((s[i].fis + s[i].math + s[i].ped)/3 < 4)
				e++;
			break;
		}
	}
	proc = (e / n) * 100;
	cout << "% students with average score 4: " << setprecision(2) << proc << endl;
}

int main() {
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	int n, c;
	cout << "N: "; cin >> n;

	Student* s = new Student[n];

	Create(s, n);
	Table(s, n);
	c = Count1(s, n);
	cout << "Students without 3: " << c << endl;
	Count2(s, n);

	delete[] s;
	system("pause");
	return 0;
}