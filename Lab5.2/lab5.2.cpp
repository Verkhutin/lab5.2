#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;
void S(const double x, const double eps, int& n, double& s);
void A(const double x, const int n, double& a);

int main() {
	double x, x2, dx, eps, s = 0;
	int n = 0;

	cout << "x = "; cin >> x;
	cout << "x2 = "; cin >> x2;
	cout << "dx = "; cin >> dx;
	cout << "eps = "; cin >> eps;

	cout << fixed;
	cout << "-----------------------------------------------------------" << endl;
	cout << "|" << setw(10) << "x" << " |"
		<< setw(15) << "exp(x*x)" << " |"
		<< setw(15) << "S" << " |"
		<< setw(10) << "n" << " |"
		<< endl;
	cout << "-----------------------------------------------------------" << endl;

	while (x <= x2) 
	{
		S(x, eps, n, s);

		cout << "|" << setw(10) << setprecision(2) << x << " |"
			<< setw(15) << setprecision(2) << exp(x * x) << " |"
			<< setw(15) << setprecision(2) << s << " |"
			<< setw(10) << n << " |"
			<< endl;
		x += dx;
	}
	cout << "-------------------------------------------------------------" << endl;
	return 0;
}

void S(const double x, const double eps, int &n, double &s)
{
	n = 0; 
	double a = 1;
	s = a;
	do {
		n++;
		A(x, n, a);
		s += a;
	} while (abs(a) >= eps);
}

void A(const double x, const int n, double &a)
{
	double R = x*x / n;
	a *= R;
}