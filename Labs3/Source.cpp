#include <iostream>
#include <string>
using namespace std;

double sqr(double x)
{
	return x * x;
}

class Triangle
{
protected:

	double a, b, c; //Стороны

public:

	Triangle(double a, double b, double c) // Конструктор с параметрами
	{
		this->a = a;
		this->b = b;
		this->c = c;
	}
	Triangle() { a = b = c = 0; } // Конструктор по умолчанию
	~Triangle() {}; // деконструктор	

	virtual double getPerimetr() //Возвращает периметр
	{
		return a + b + c;
	}
	virtual double getSquare() // Возвращает площадь
	{
		double p = getPerimetr() / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	virtual string getInfo() // Возвращает строку информации
	{
		string msg = "First side: " + to_string(a) + " | Second side: " + to_string(b) + " | Third side: " + to_string(c) + " | Perimeter: " + to_string(getPerimetr()) + " | Square: " + to_string(getSquare());
		return msg;
	}
};

class Foursquare : public Triangle
{
private:

	double d, e, f; // d - 4 сторона, e и f - длины диагоналей

public:
	Foursquare() { a = b = c = d = e = f = 0; } // Конструтор по умолчанию
	Foursquare(double a, double b, double c, double d, double e, double f) // Конструтор с параметрами
	{
		this->a = a;
		this->b = b;
		this->c = c;
		this->d = d;
		this->e = e;
		this->f = f;
	}
	~Foursquare() {}; // Деконструтор

	virtual double getPerimetr() override // Переопределённый метод, возвращающий периметр
	{
		return a + b + c + d;
	}
	virtual double getSquare() override // Переопределённый метод, возвращающий площадь
	{
		return sqrt((4 * sqr(e) * sqr(f) - sqr(sqr(b) + sqr(d) - sqr(a) - sqr(c))) / 16);
	}
	virtual string getInfo() override // Переопределённый метод, возвращающий строку с информацией
	{
		string msg = "First side: " + to_string(a) + " | Second side: " + to_string(b) + " | Third side: " + to_string(c) + " | Fourth side: " + to_string(d) + " | First diagonal: " + to_string(e) + " | Second Diagonal: " + to_string(f) + " | Perimeter: " + to_string(getPerimetr()) + " | Square: " + to_string(getSquare());
		return msg;
	}
};

int main()
{
	Triangle object1(3, 5, 6);
	Foursquare object2(4, 4, 4, 4, sqrt(32), sqrt(32));

	cout << object1.getInfo() << endl;
	cout << object2.getInfo() << endl;

	system("pause");
	return 0;
}