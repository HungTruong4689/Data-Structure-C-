#include "show_mains.h"
#include <iostream>
using namespace std;
int version_selector()
{
	int version_number;
	cout << "Select version of program to run." << endl;
	cout << "1. Run searching version of searching/sorting algorithms\n"
		<< "2. Run sorting version of searching/sorting algorithms \n"
		<< "3. Quit the program" << endl;
	cout << "Your choice: ";
	cin >> version_number;

	return version_number;
}

int main()

{

	int version;
	version = version_selector();

	switch (version) {
		//  Let at most one Plane onto the Runway at current_time.
	case 1:
		main_1();
		break;
	case 2:
		main_2();
		break;
	case 3:
		break;
	}
	system("pause");
}