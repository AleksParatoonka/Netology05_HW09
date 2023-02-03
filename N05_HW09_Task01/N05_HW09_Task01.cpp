// N05_HW09_Task01.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

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
	Fraction f1(4, 3);
	Fraction f2(6, 11);

	std::cout << "f1" << ((f1 == f2) ? " == " : " not == ") << "f2" << '\n';
	std::cout << "f1" << ((f1 != f2) ? " != " : " not != ") << "f2" << '\n';
	std::cout << "f1" << ((f1 < f2) ? " < " : " not < ") << "f2" << '\n';
	std::cout << "f1" << ((f1 > f2) ? " > " : " not > ") << "f2" << '\n';
	std::cout << "f1" << ((f1 <= f2) ? " <= " : " not <= ") << "f2" << '\n';
	std::cout << "f1" << ((f1 >= f2) ? " >= " : " not >= ") << "f2" << '\n';
	return 0;
}