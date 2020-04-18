#include <iostream>
#include <cmath>

using namespace std;

double Y(double x)
{
	double y = 0;
	double first = 0;
	double second = 0;
	double third = 0;

	first = ((1 + (x * x)) / 2);
	second = atan(x);
	third = x / 2;

	y =  (first * second) - third;

	return y;
}

double UpSide(double x, unsigned short int n)
{
	return x = pow(x ,((2 * n) + 1));
}

double DownSide(unsigned short int &n)
{
	double ret = 0;
	ret = (4 * (n * n)) - 1;

	return ret;
}

double S(double x, unsigned short int n)
{
	double value = 0;
	double up = 0;
	double down = 0;
	double sign = 0;

	for(unsigned short int counter = 1; counter <= n; ++counter)
	{
		up = UpSide(x, counter);
		down = DownSide(counter);
		sign = pow(-1, counter + 1);

		value += (sign * (up / down));
	}

	return value;
}

int main()
{
	unsigned short int n = 10;
	double x = 0.1;
	double h = 1;
	double yValue = 0;
	double sValue = 0;

	for(; x < h; x += 0.1)
	{
		sValue = S(x, n);
		yValue = Y(x);

		cout << "x: " << x << "| S: " << sValue << "| Y: " << yValue <<  endl;
	}

	return 0;
}
