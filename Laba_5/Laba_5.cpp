
#include <iostream>
#include <string.h>
#include <fstream>
#include <string>
#include <sstream>
#include <windows.h>

using namespace std;

int task_manager()
{
	int task_number;
RENUMBER:	printf("Menu:\n     1.  Task 1\n     2.  Task 2\n     3.  Task 3\n");
	printf("Enter task number you wanna do: ");
	scanf_s("%d", &task_number);
	if (task_number < 1 || task_number > 3)
	{
		system("cls");
		printf("There is only 3 options!\n\n");
		goto RENUMBER;
	}
	return task_number;
}

/*
Задача 1.
Створити клас вікно, що має координати верхнього лівого й нижнього
правого кута, колір тла. Визначити конструктори, деструктор і функцію друку.
Створити похідний клас - вікно з меню, що має поле рядок. Визначити конструктори
за замовчуванням і з різним числом параметрів, деструктори, функцію друку.
Визначити функції перепризначення кольору тла та рядка меню. Написати програму
тестування всіх можливостей цього класу.*/


class Window
{
protected:
	// координати верхнього лівого й нижнього правого кута, колір тла.
	string hleft;
	string dright;
	string tlo;

public:
	//Визначити конструктори, деструктор і функцію друку
	Window()
	{
		hleft = "Deafoult";
		dright = "Deafoult";
		tlo = "Deafoult";
		cout << " Default constructor Window() \n";
	}
	Window(string hl, string dr, string tlo)
	{
		hleft = hl;
		dright = dr;
		tlo = tlo;
		cout << " Constructor Window(string hl, string dr, string tlo) \n";
	}
	//деструктор
	~Window()
	{
		cout << "\tDestructor Window\n";
	}
	//функцію друку
	friend ostream& operator<<(ostream& os, Window& a);
	friend istream& operator>>(istream& os, Window& a);
};
ostream& operator<<(ostream& os, Window& a) {
	os << a.hleft << endl;
	os << a.dright << endl;
	os << a.tlo << endl;
	return os;
}
istream& operator>>(istream& is, Window& a) {
	is >> a.hleft;
	is >> a.dright;
	is >> a.tlo;
	return is;
}

class Window_with_menu : public Window
{
	//Створити похідний вікно з меню, що має поле рядок.
	string line;

public:
	//Визначити конструктори за замовчуванням і з різним числом параметрів, деструктори, функцію друку
	Window_with_menu()
	{
		line = "No_line";
		cout << " Default constructor Window_with_menu() \n";
	}
	Window_with_menu(string hl, string dr, string tlo, string l) : Window(hl, dr, tlo)
	{
		line = l;
		cout << " Constructor Window_with_menu(string hl, string dr, string tlo, string l) \n";
	}
	//деструктори
	~Window_with_menu()
	{
		cout << "\tDestructor Window_with_menu\n";
	}
	//функцію друку
	friend ostream& operator<<(ostream& os, Window_with_menu& a);
	friend istream& operator>>(istream& os, Window_with_menu& a);
};
ostream& operator<<(ostream& os, Window_with_menu& a) {
	os << a.hleft << endl;
	os << a.dright << endl;
	os << a.tlo << endl;
	os << a.line << endl;
	return os;
}
istream& operator>>(istream& is, Window_with_menu& a) {
	is >> a.hleft;
	is >> a.dright;
	is >> a.tlo;
	is >> a.line;
	return is;
}
void task1()
{
	Window_with_menu test1, test2("125,50", "250,0", "Green", "Please enter text"), test3("30,150", "120,75", "Purpul", "Please enter your name");
	cout << test1;
	cout << test2;
	cout << test3;
}

/*
Задача 2. 
Створити клас жорсткий диск, що має обсяг (Мбайт). Визначити
конструктори й метод доступу. Створити клас комп'ютер, що містить клас жорсткий
диск. Додатково є марка (вказівник на рядок), ціна. Визначити конструктори й
деструктор. Визначити private-, public- похідний клас комп'ютерів з монітором
розмір, що має додатково, монітора. Визначить конструктори, деструктори й
функцію друку.
*/
//комп'ютер
class Computer
{
protected:
	//клас диск
	class drive
	{
	public:
		int volume;
		drive() : volume(0) {}
		drive(int vol) : volume(vol) {}
		~drive()
		{
			cout << " drive Dtor " << endl;
		}
	};
	drive driveObj;
	//марка
	string mark;
	//ціна
	int price;

public:
	Computer() : driveObj(), mark(), price(0) {}
	Computer(int vol) : driveObj(vol), mark(), price(0) {}
	Computer(int vol, string sqk) : driveObj(vol), mark(sqk), price(0) {}
	Computer(int vol, string sqk, int pc) : driveObj(vol), mark(sqk), price(pc) {}
	~Computer()
	{
		cout << " Computer Dtor " << endl;
	}
};
//Визначити public-похідний клас комп'ютерів з монітором
class Computer_with_monitor : public Computer
{
	//додатковий параметр - розмір монітора
	string size;

public:
	Computer_with_monitor() : Computer()
	{
		size = "Deafoult";
	}
	Computer_with_monitor(int vol) : Computer(vol)
	{
		size = "Deafoult";
	}
	Computer_with_monitor(int vol, string sqk) : Computer(vol, sqk)
	{
		size = "Deafoult";
	}
	Computer_with_monitor(int vol, string sqk, int pr) : Computer(vol, sqk, pr)
	{
		size = "Deafoult";
	}
	Computer_with_monitor(string s, int vol, string sqk, int pr) : Computer(vol, sqk, pr)
	{
		size = s;
	}
	~Computer_with_monitor()
	{
		cout << " Computer_with_monitor Dtor" << endl;
	}
	//функцію друку
	friend ostream& operator<<(ostream& os, Computer_with_monitor& a);
	friend istream& operator>>(istream& os, Computer_with_monitor& a);
	void Output();
};
ostream& operator<<(ostream& os, Computer_with_monitor& a) {
	os << "drive volume: " << a.driveObj.volume << endl;
	os << "Mark`s name: " << a.mark << endl;
	os << "Price: " << a.price << endl;
	os << "Size monitor: " << a.size << endl;
	return os;
}
istream& operator>>(istream& is, Computer_with_monitor& a) {
	is >> a.driveObj.volume;
	is >> a.mark;
	is >> a.price;
	is >> a.size;
	return is;
}
void Computer_with_monitor::Output()
{
	cout << "Drive volume: " << driveObj.volume << endl;
	cout << "Mark`s name: " << mark << endl;
	cout << "Price: " << price << endl;
	cout << "Monitor size: " << size << endl;
}
void task2()
{
	cout << " Enter drive volume: ";
	int dv;
	cin >> dv;
	cout << " Enter Mark: ";
	string mk;
	cin >> mk;
	cout << " Enter price: ";
	int pc;
	cin >> pc;
	cout << " Enter monitor size : ";
	string s;
	cin >> s;

	Computer_with_monitor Computer_with_monitorObj0, Computer_with_monitorObj1(dv), Computer_with_monitorObj2(dv, mk), Computer_with_monitorObj3(dv, mk, pc), Computer_with_monitorObj4(s, dv, mk, pc);
	cout << "Computer_with_monitorObj0: ";
	Computer_with_monitorObj0.Output();
	cout << "Computer_with_monitorObj1(dv): ";
	Computer_with_monitorObj1.Output();
	cout << "Computer_with_monitorObj2(dv, mk): ";
	Computer_with_monitorObj2.Output();
	cout << "Computer_with_monitorObj3(dv, mk, pc): ";
	Computer_with_monitorObj3.Output();
	cout << "Computer_with_monitorObj4(s, dv, mk, pc): ";
	Computer_with_monitorObj4.Output();
}

/*
Задача 3. 
Створити ієрархію класів чотирикутник і квадрат. Перевизначити вивід у
потік і введення з потоку, конструктор копіювання, оператор присвоювання через
відповідні функції базового класу.
*/
class Quadrangle
{
protected:
	int Side1;
	long Side2;
	long long Side3;
	short Side4;
	string Color;

public:
	Quadrangle() : Side1(1), Side2(1),Side3(1),Side4(1),  Color("No color") {}
	Quadrangle(int s1) : Side1(s1), Side2(1),Side3(1), Side4(1), Color("No color") {}
	Quadrangle(long s2) : Side1(1), Side2(s2), Side3(1), Side4(1), Color("No color") {}
	Quadrangle(long long s3) : Side1(1), Side2(1), Side3(s3), Side4(1), Color("No color") {}
	Quadrangle(short s4) : Side1(1), Side2(1), Side3(1), Side4(s4), Color("No color") {}
	Quadrangle(int s1, long s2) : Side1(s1), Side2(s2), Side3(1), Side4(1), Color("No color") {}
	Quadrangle(int s1, long long s3) : Side1(s1), Side2(1), Side3(s3), Side4(1), Color("No color") {}
	Quadrangle(int s1, short s4) : Side1(s1), Side2(1), Side3(1), Side4(s4), Color("No color") {}
	Quadrangle(long s2, long long s3) : Side1(1), Side2(s2), Side3(s3), Side4(1), Color("No color") {}
	Quadrangle(long s2, short s4) : Side1(1), Side2(s2), Side3(1), Side4(s4), Color("No color") {}
	Quadrangle(long long s3, short s4) : Side1(1), Side2(1), Side3(s3), Side4(s4), Color("No color") {}
	Quadrangle(int s1,long long s3, short s4) : Side1(s1), Side2(1), Side3(s3), Side4(s4), Color("No color") {}
	Quadrangle(long s2, long long s3, short s4) : Side1(1), Side2(s2), Side3(s3), Side4(s4), Color("No color") {}
	Quadrangle(int s1, long s2, short s4) : Side1(s1), Side2(s2), Side3(1), Side4(s4), Color("No color") {}
	Quadrangle(int s1, long long s3, long s2) : Side1(s1), Side2(s2), Side3(s3), Side4(1), Color("No color") {}
	Quadrangle(int s1, long s2, long long s3, short s4) : Side1(s1), Side2(s2), Side3(s3), Side4(s4), Color("No color") {}
	Quadrangle(string c) : Side1(1), Side2(1), Side3(1), Side4(1), Color(c) {}
	Quadrangle(int s1, string c) : Side1(s1), Side2(1), Side3(1), Side4(1), Color(c) {}
	Quadrangle(long s2, string c) : Side1(1), Side2(s2), Side3(1), Side4(1), Color(c) {}
	Quadrangle(long long s3, string c) : Side1(1), Side2(1), Side3(s3), Side4(1), Color(c) {}
	Quadrangle(short s4, string c) : Side1(1), Side2(1), Side3(1), Side4(s4), Color(c) {}
	Quadrangle(int s1, long s2, string c) : Side1(s1), Side2(s2), Side3(1), Side4(1), Color(c) {}
	Quadrangle(int s1, long long s3, string c) : Side1(s1), Side2(1), Side3(s3), Side4(1), Color(c) {}
	Quadrangle(int s1, short s4, string c) : Side1(s1), Side2(1), Side3(1), Side4(s4), Color(c) {}
	Quadrangle(long s2, long long s3, string c) : Side1(1), Side2(s2), Side3(s3), Side4(1), Color(c) {}
	Quadrangle(long s2, short s4, string c) : Side1(1), Side2(s2), Side3(1), Side4(s4), Color(c) {}
	Quadrangle(long long s3, short s4, string c) : Side1(1), Side2(1), Side3(s3), Side4(s4), Color(c) {}
	Quadrangle(int s1, long long s3, short s4, string c) : Side1(s1), Side2(1), Side3(s3), Side4(s4), Color(c) {}
	Quadrangle(long s2, long long s3, short s4, string c) : Side1(1), Side2(s2), Side3(s3), Side4(s4), Color(c) {}
	Quadrangle(int s1, long s2, short s4, string c) : Side1(s1), Side2(s2), Side3(1), Side4(s4), Color(c) {}
	Quadrangle(int s1, long long s3, long s2, string c) : Side1(s1), Side2(s2), Side3(s3), Side4(1), Color(c) {}
	Quadrangle(int s1, long s2, long long s3, short s4, string c) : Side1(s1), Side2(s2), Side3(s3), Side4(s4), Color(c) {}

	// конструктори копіювання
	Quadrangle(const Quadrangle& a)
	{
		Side1 = a.Side1;
		Side2 = a.Side2;
		Side3 = a.Side3;
		Side4 = a.Side4;
		Color = a.Color;
		cout << " Constructor Copy Quadrangle(const Quadrangle& a) \n";
		cout << endl;
	}
	//перенесення
	Quadrangle(Quadrangle&& a)
	{
		Side1 = a.Side1;
		Side2 = a.Side2;
		Side3 = a.Side3;
		Side4 = a.Side4;
		Color = a.Color;
		a.Side1 = 1;
		a.Side2 = 1;
		a.Side3 = 1;
		a.Side4 = 1;
		a.Color = "no color";
		cout << " Constructor Move Quadrangle(Quadrangle&& a) \n";
		cout << endl;
	}
	//оператори присвоювання
	Quadrangle& operator=(const Quadrangle& s)
	{
		Side1 = s.Side1;
		Side2 = s.Side2;
		Side3 = s.Side3;
		Side4 = s.Side4;
		Color = s.Color;
		cout << " operator=(const Quadrangle& s) Copy \n";
		cout << endl;
		return *this;
	}
	Quadrangle& operator=(Quadrangle&& s)
	{
		Side1 = s.Side1;
		Side2 = s.Side2;
		Side3 = s.Side3;
		Side4 = s.Side4;
		Color = s.Color;
		s.Side1 = 1;
		s.Side2 = 1;
		s.Side3 = 1;
		s.Side4 = 1;
		s.Color = "no color";
		cout << " operator=( Quadrangle&& s) Move \n";
		cout << endl;
		return *this;
	}
	~Quadrangle()
	{
		cout << "Destructor Quadrangle\n";
		cout << endl;
	}

	//Перевизначити вивід у потік і введення з потоку
	friend ostream& operator<<(ostream& os, Quadrangle& a);
	friend istream& operator>>(istream& os, Quadrangle& a);
};
ostream& operator<<(ostream& os, Quadrangle& a) {
	os << "side 1 : " << a.Side1 << endl;
	os << "side 2 : " << a.Side2 << endl;
	os << "side 3 : " << a.Side3 << endl;
	os << "side 4 : " << a.Side4 << endl;
	os << "color: " << a.Color << endl;
	return os;
}
istream& operator>>(istream& is, Quadrangle& a) {
	is >> a.Side1;
	is >> a.Side2;
	is >> a.Side3;
	is >> a.Side4;
	is >> a.Color;
	return is;
}
class quadrate : public Quadrangle
{
	string color_contur;
public:
	quadrate() : Quadrangle()
	{
		color_contur = "Deafoult";
	}
	quadrate(int s1) : Quadrangle(s1)
	{
		color_contur = "Deafoult";
	}
	quadrate(int s1, string c ) : Quadrangle(s1,c)
	{
		color_contur = "Deafoult";
	}
	quadrate(int s1, string c, string t) : Quadrangle(s1,c)
	{
		color_contur = t;
	}
	~quadrate()
	{
		cout << "\tDestructor quadrate\n";
		cout << endl;
	}

	// конструктори копіювання
	quadrate(const quadrate& a)
	{
		Side1 = a.Side1;
		Color = a.Color;
		color_contur = a.color_contur;
		cout << " Constructor Copy quadrangle(const quadrangle& a) \n";
	}
	//перенесення
	quadrate(quadrate&& a)
	{
		Side1 = a.Side1;
		Color = a.Color;
		color_contur = a.color_contur;
		a.Side1 = 1;
		a.Color = "no color";
		a.color_contur = "Deafoult";
		cout << " Constructor Move quadrangle(quadrangle&& a) \n";
	}
	//оператори присвоювання
	quadrate& operator=(const quadrate& s) {
		this->Quadrangle::operator=(s);
		color_contur = s.color_contur;
		cout << " quadrangle& operator =(const quadrangle &s) \n";
		return *this;
	}
	quadrate& operator=(quadrate&& s) {
		Side1 = s.Side1;
		Color = s.Color;
		s.Side1 = 1;
		s.Color = "no color";
		color_contur = s.color_contur;
		s.color_contur = "Deafoult";
		cout << " quadrangle& operator =(quadrangle &&s) \n";
		return *this;
	}

	friend ostream& operator<<(ostream& os, quadrate& a);
	friend istream& operator>>(istream& os, quadrate& a);
};
ostream& operator<<(ostream& os, quadrate& a)
{
	os << "sides: " << a.Side1 << endl;
	os << "color: " << a.Color << endl;
	os << "Contur color: " << a.color_contur << endl;
	return os;
}
istream& operator>>(istream& is, quadrate& a)
{
	is >> a.Side1;
	is >> a.Color;
	is >> a.color_contur;
	return is;
}
void task3()
{
	cout << "Enter sides: ";
	cout << endl;
	cout << "Side 1 = ";
	int s1;
	cin >> s1;
	cout << endl;
	cout << "Side 2 = ";
	long s2;
	cin >> s2;
	cout << endl;
	cout << "Side 3 = ";
	long long s3;
	cin >> s3;
	cout << endl;
	cout << "Side 4 = ";
	short s4;
	cin >> s4;
	cout << endl;
	cout << "Enter color ";
	string c;
	cin >> c;
	cout << "Enter contur color: ";
	string t;
	cin >> t;
	cout << endl;
	Quadrangle  fObj0, fObj1(s1), fObj2(s1, s2), fObj3(s2), fObj4(s3), fObj5(s4), fObj6(s1,s2), fObj7(s1,s3), fObj8(s1,s4), fObj9(s2,s3), fObj10(s2,s4), fObj11(s3,s4), fObj1p1(s1,s3,s4), fObj12(s2,s3,s4), fObj13(s1,s2,s4), fObj14(s1,s3,s4), fObj15(s1,s2,s3), fObj16(s1,s2,s3,s4), fObj17(c), fObj18(s1,c), fObj19(s1, s2,c), fObj20(s2,c), fObj21(s3,c), fObj22(s4,c), fObj23(s1, s2,c), fObj24(s1, s3,c), fObj25(s1, s4,c), fObj26(s2, s3,c), fObj27(s2, s4,c), fObj28(s3, s4,c), fObj29(s1, s3, s4,c), fObj30(s2, s3, s4,c), fObj31(s1, s2, s4,c), fObj32(s1, s3, s4,c), fObj33(s1, s2, s3,c), fObj34(s1, s2, s3, s4,c);
	quadrate fObj35(s1), fObj36(s1,c), fObj37( s1,c, t);

	cout << " fObj0: "<< endl << fObj0;
	cout << endl;
	cout << " fObj1: " << endl << fObj1;
	cout << endl;
	cout << " fObj2: " << endl << fObj2;
	cout << endl;
	cout << " fObj3: " << endl << fObj3;
	cout << endl;
	cout << " fObj4: " << endl << fObj4;
	cout << endl;
	cout << " fObj5: " << endl << fObj5;
	cout << endl;
	cout << " fObj6: " << endl << fObj6;
	cout << endl;
	cout << " fObj7: " << endl << fObj7;
	cout << endl;
	cout << " fObj8: " << endl << fObj8;
	cout << endl;
	cout << " fObj9: " << endl << fObj9;
	cout << endl;
	cout << " fObj10: " << endl << fObj10;
	cout << endl;
	cout << " fObj11: " << endl << fObj11;
	cout << endl;
	cout << " fObj12: " << endl << fObj1p1;
	cout << endl;
	cout << " fObj13: " << endl << fObj12;
	cout << endl;
	cout << " fObj14: " << endl << fObj13;
	cout << endl;
	cout << " fObj15: " << endl << fObj14;
	cout << endl;
	cout << " fObj16: " << endl << fObj15;
	cout << endl;
	cout << " fObj17: " << endl << fObj16;
	cout << endl;
	cout << " fObj18: " << endl << fObj17;
	cout << endl;
	cout << " fObj19: " << endl << fObj18;
	cout << endl;
	cout << " fObj20: " << endl << fObj19;
	cout << endl;
	cout << " fObj21: " << endl << fObj20;
	cout << endl;
	cout << " fObj22: " << endl << fObj21;
	cout << endl;
	cout << " fObj23: " << endl << fObj22;
	cout << endl;
	cout << " fObj24: " << endl << fObj23;
	cout << endl;
	cout << " fObj25: " << endl << fObj24;
	cout << endl;
	cout << " fObj26: " << endl << fObj25;
	cout << endl;
	cout << " fObj27: " << endl << fObj26;
	cout << endl;
	cout << " fObj28: " << endl << fObj27;
	cout << endl;
	cout << " fObj29: " << endl << fObj28;
	cout << endl;
	cout << " fObj30: " << endl << fObj29;
	cout << endl;
	cout << " fObj31: " << endl << fObj30;
	cout << endl;
	cout << " fObj32: " << endl << fObj31;
	cout << endl;
	cout << " fObj33: " << endl << fObj32;
	cout << endl;
	cout << " fObj34: " << endl << fObj33;
	cout << endl;
	cout << " fObj35: " << endl << fObj34;
	cout << endl;
	cout << " fObj36: " << endl << fObj35;
	cout << endl;
	cout << " fObj37: " << endl << fObj36;
	cout << endl;
	cout << " fObj38: " << endl << fObj37;
	cout << endl;
}

int main()
{
TASK:	int task_number = task_manager();
	switch (task_number)
	{
	case 1:
		task1();
		break;
	case 2:
		task2();
		break;
	case 3:
		task3();
		break;
	default:
		break;
	}

	string answer;
FIN:	printf("\nDo you want to do one more task? Enter '1' if you do, and '0' if you don`t: ");
	cin >> answer;
	if (answer == "1")
	{
		system("cls");
		goto TASK;
	}
	if (answer == "0")
	{
		system("cls");
		printf("Bye!");
	}
	else
	{
		printf("Please enter '1' or '0'\n");
		goto FIN;
	}
}