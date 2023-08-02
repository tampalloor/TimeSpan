#include <iostream>
#include "time_span.h"

using namespace std; 

/*void main()
{
	TimeSpan dur1(77.4, 15, 6), dur2(127.86), dur3(8, -23, 0), dur4(0, 0, 0);
	TimeSpan dur5(-3, 73, 2), dur6(7, 35, 120), dur7, dur8;
	dur7 = dur1 + dur3;
	cout << dur1 << endl;
	cout << dur2 << endl;
	cout << dur3 << endl;
	cout << dur4 << endl;
	cout << dur5 << endl;
	cout << dur6 << endl;
	cout << dur7 << endl;
	dur7 += dur3;
	cout << dur3 << endl;
	cout << dur7 << endl;

	dur7 -= dur3; 
	cout << dur7 << endl;


	if (dur3 != dur6)
	{
		cout << "Durations are different." << endl;
	}
	else
	{
		cout << "Durations are the same" << endl;
	}

	if (dur1 > dur2) {
		cout << "dur1 is greater" << endl;
	}
	else {
		cout << "dur1 is not greater" << endl; 
	}

	if (dur5 < dur4) {
		cout << "dur5 is less" << endl; 
	}
	else {
		cout << "dur5 is not less" << endl;
	}

	if (dur3 >= dur6)
	{
		cout << "Durations are greater than or equal to eachother." << endl;
	}
	else
	{
		cout << "Durations are not greater than or equal to eachother." << endl;
	}

	if (dur1 == dur2) {
		cout << "Durations are equal." << endl;
	}
	else {
		cout << "Durations are not equal." << endl;
	}

	cout << "Input Hours, Minutes, and Seconds: " << endl;
	cin >> dur8; 
	cout << dur8 << endl; 
}*/

int main() {
	//sub
	cout << "NORMAL SUB TESTS" << endl;
	TimeSpan dur50(77, 15, 6), dur51(8, -25, 0), dur52, dur53, dur54, dur55(-3,
		75, 2), dur56(5, 1, 10), dur57(1, 2, 3), dur58(1, 3, 2), dur59;
	dur52 = dur50 + dur51;
	dur54 = dur55 - dur51;
	cout << "Hours: -9, Minutes: -19, Seconds: -58 <- Expected" << endl;
	cout << dur54 << endl << endl;
	return 0;

}