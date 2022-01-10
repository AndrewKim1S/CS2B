#include "Complex.h"

int
main()
{
	Complex c1 = 3.14;
	cout << "expect (3.14, 0) : " << c1 << endl;

	Complex c2 = Complex(1, 1), 
	        c3 = Complex(2, 2);
	cout << c2 << c3 << " same? " << to_string(c2==c3)<<endl;
	cout << c2 << c3 << " diff? " << to_string(c2!=c3)<<endl;
	cout << c2 << " + " << c3 << " = " << c2+c3 << endl;
	cout << c2 << " - " << c3 << " = " << c2-c3 << endl;
	cout << c2 << " * " << c3 << " = " << c2*c3 << endl;
	cout << "1/" << c3 << " = " << c3.reciprocal() << endl;
	cout << c2 << " / " << c3 << " = " << c2/c3 << endl;

	Complex c4 = Complex(0,0);
	try {
		cout << "1/" << c4 << " = " << c4.reciprocal() << endl;
	} catch (Complex::Div_By_Zero_Exception e) {
		cout << e.what() << endl;
	}

	try {
		cout << c2 << " / " << c4 << c2/c4 << endl;
	} catch (Complex::Div_By_Zero_Exception e) {
		cout << e.what() << endl;
	}

	return 0;
}
