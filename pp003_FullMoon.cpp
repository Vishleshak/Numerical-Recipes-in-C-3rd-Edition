#include <iostream>

int kingJulian(int, int, int);

using namespace std;

/*
		authors' description:
		
		to compute the mean and variance of Julian day
		numbers of the first 20 full moons after the
		date of January 1900.
		
*/

/*
		what is the julian day number?
		
		from Wikipedia: 
		the julian day number(jdn) is the integer assigned
		to a whole solar day in the julian day counting
		from noon Greenwich Mean Time; with jdn 0 assigned
		to the day starting at noon on january 1, 4713 BC;
		in the proplectic georgian calender... blah... blah...
		
		Alternatively(Maybe...):
		In short julian day number is something used by
		astronomers to avoid the complexities of calender
		airthmatic. It is a simple algebraic equation
		which takes three inputs(month, day, year) to 
		generate a unique real number corresponding to the
		inputs. This unique real number is called julian
		day number.
		
		n.b. ~ i'm not making any claims to the uniqueness
		of the jdn but just wishing it so. there would be 
		no surprise for me, if it is rigorously proved to
		not to be so. the obivious and trivial case, -depending
		on the compatibilities of defintions of uniqueness
		from astronomy and number theroy,- here, 
		for example, is for very very very large n.
*/

int main()

{	
	int i;
	double mean, variance, sum;
	int n[19] = {0};
	
	sum = 0.0;
	for (i = 0; i <= 19; i++)
	{
		n[i] = kingJulian(1900, i+1, 15);
		sum = sum + n[i];
	}
	
	mean = sum/20.0;
	
	cout << " the total sum " << sum << endl;
	cout << " the mean is " << mean << endl;
	
	// calculation of variance
	
	double var[19] = {0};
	int k;
	for (i = 0, k = 0; i <= 19, k <= 19; i++, k++)
	{
		var[k] = n[i] - mean;
	}
	
	double newVar[19] = {0};
	double total;
	total = 0.0;
	for (k = 0; k <= 19; k++)
	{
		newVar[k] = var[k] * var[k];
		total = total + newVar[k];
	}
	
	variance = total / 20.0;;
	cout << " the variance is " << variance << endl;
	
	return 0;
}

int kingJulian(int year, int month, int day)
{
	int a, y, m, julianDayNumber;
	
	a = (14 - month) / 12;
	y = year + 4800 -  a;
	m = month + 12 * a - 3;
	
	julianDayNumber = day + (153*m + 2)/ 5 + 365*y + y/4 - y/100 + y/400 - 32045;
	
	return julianDayNumber;	
}
