// N05_HW09_Task02.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int NOD(int a, int b)
{
	while (a > 0 && b > 0)

		if (a > b)
			a %= b;

		else
			b %= a;

	return a + b;
}

class Fraction
{
private:
	int numerator_;
	int denominator_;

public:
	Fraction(int numerator, int denominator)
	{
		numerator_ = numerator;
		denominator_ = denominator;
	}
	double Res() {
		return static_cast<double>(numerator_ / denominator_);
	}
	Fraction Simplifying() {
		int nod = NOD(numerator_, denominator_);
		return Fraction(numerator_/nod, denominator_/nod);
	}
	std::string print_fraction() {
		return std::to_string(numerator_)+"/"+std::to_string(denominator_);
		//return static_cast<std::string>(numerator_) + "/" + static_cast<std::string>(denominator_);
	}
	Fraction operator+(Fraction other) {
		int nod = NOD(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
		return Fraction((numerator_ * other.denominator_ + other.numerator_ * denominator_)/nod, (denominator_ * other.denominator_)/nod);
	}
	Fraction operator-(Fraction other) {
		int nod = NOD(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
		return Fraction((numerator_ * other.denominator_ - other.numerator_ * denominator_)/nod, (denominator_ * other.denominator_)/nod);
	}
	Fraction operator*(Fraction other) {
		int nod = NOD(numerator_ * other.numerator_, denominator_ * other.denominator_);
		return Fraction((numerator_ * other.numerator_)/nod, (denominator_ * other.denominator_)/nod);
	}
	Fraction operator/(Fraction other) {
		int nod = NOD(numerator_ * other.denominator_, denominator_ * other.numerator_);
		return Fraction((numerator_ * other.denominator_)/nod, (denominator_ * other.numerator_)/nod);
	}
	Fraction operator-() {
		int tmp = -1*numerator_;
		this->numerator_ = tmp;
		return *this;
	}
	
	Fraction operator++() {
		int tmp = numerator_ + denominator_;
		this->numerator_ = tmp;
		return *this;
	}
	Fraction operator--() {
		int tmp = numerator_ - denominator_;
		this->numerator_ = tmp;
		return *this;
	}

	/*Fraction operator++(int) {
		return(++(*this));
	}*/

	Fraction operator++(int) {
		Fraction temp = *this;
		++(*this);
		return temp;
	}

	/*Fraction operator--(int) {
		return (--(*this));
	}*/

	Fraction operator--(int) {
		Fraction temp = *this;
		--(*this);
		return temp;
	}

	bool operator==(Fraction other) {
		return Res() == other.Res();
	}
	bool operator!=(Fraction other) {
		return !(*this == other);
	}
	bool operator>(Fraction other) {
		return Res() > other.Res();
	}
	bool operator<(Fraction other) {
		return other > *this;
	}
	bool operator>=(Fraction other) {
		return !(*this < other);
	}
	bool operator<=(Fraction other) {
		return !(*this > other);
	}
};

int main()
{
	setlocale(LC_ALL, "Russian");
	int x1, x2, y1, y2;
	std::cout << "Введите числитель дроби 1: ";
	std::cin >> x1;
	std::cout << "Введите знаменатель дроби 1: ";
	std::cin >> y1;
	std::cout << "Введите числитель дроби 2: ";
	std::cin >> x2;
	std::cout << "Введите знаменатель дроби 2: ";
	std::cin >> y2;
	//Fraction f1(4, 3);
	  //Fraction f2(6, 11);

	Fraction f1(x1, y1);
	Fraction f2(x2, y2);


	std::cout << "f1 = " << f1.print_fraction() << " f2 = "<<f2.print_fraction() << '\n';


	std::cout << f1.print_fraction() << " + " << f2.print_fraction() << " = " << (f1+f2).print_fraction() << '\n';
	std::cout << f1.print_fraction() << " - " << f2.print_fraction() << " = " << (f1-f2).print_fraction() << '\n';
	std::cout << f1.print_fraction() << " * " << f2.print_fraction() << " = " << (f1*f2).print_fraction() << '\n';
	std::cout << f1.print_fraction() << " / " << f2.print_fraction() << " = " << (f1/f2).print_fraction() << '\n';

	std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';
	std::cout << "++f1 = " << (++f1).print_fraction() << '\n';
	//std::cout << "++f1 = " << " ++" << f1.print_fraction() << " = "  << (++f1).print_fraction() << '\n';
	std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';
	std::cout << "f1++= " << (f1++).print_fraction() << '\n';

	std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';
	std::cout << "--f1 = " << (--f1).print_fraction() << '\n';
	std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';
	std::cout << "f1--= " << (f1--).print_fraction() << '\n';
	std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';

	std::cout <<"++" << f1.print_fraction() << " * " << f2.print_fraction() << " = " ;
	std::cout << ((++f1) * f2).print_fraction() << '\n';
	std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';

	std::cout << f1.print_fraction() << "-- * " << f2.print_fraction() << " = " ;
	std::cout << ((f1--) * f2).print_fraction() << '\n';
	std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';

	//std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';
	std::cout << "-f1 = " << (-f1).print_fraction() << '\n';
	std::cout << std::endl;

	//std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';
	//std::cout << "++f1 = " << " ++" << f1.print_fraction() << " = "  << (++f1).print_fraction() << '\n';
	//std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';
	//std::cout << "f1++ = "  << f1.print_fraction() << "++ = " << (f1++).print_fraction() << '\n';
	//std::cout << "Значение дроби 1 " << " = " << f1.print_fraction() << '\n';

	return 0;
}