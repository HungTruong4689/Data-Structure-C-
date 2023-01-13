#include "Utility.h"
#include "Key.h"
#include "Random.h"
#include "Timer.h"
#include "List.h"

#include "Ordered_list.h"
#include "Search.h"
void intro() {
	cout << "Testing program for sequential and binary search.\n"
		<< "Options are:\n"
		<< "[Q]uit [F]ill list [T]est sequential search "
		<< "test [B]inary search "
		<< "[S]how two test"
		<< endl;
}
void print_out(string comment, float t, int a, int search) {
	float average;
	cout << "Statistics:  " << endl;
	cout << "Status: " << comment << endl;
	cout << "Eslapsed per search: " << 1000*t << endl;
	cout << "Comparisons per search:" << a << endl;
	cout << "Searches: " << search << endl;
}

void test_search(int searches, Ordered_list& the_list)
/*

Pre:  None.
Post: The number of key comparisons and CPU time for a
	  sequential searching function have been calculated.
Uses: Methods of the classes List, Random, and Timer,
	  together with an output function print_out
*/
{
	int list_size = the_list.size();
	if (searches <= 0 || list_size < 0) {
		cout << " Exiting test: " << endl
			<< " The number of searches must be positive." << endl
			<< " The number of list entries must exceed 0." << endl;
		return;
	}
	int i, target, found_at;
	Key::comparisons = 0;
	Random number;
	Timer clock;

	for (i = 0; i < searches; i++) {
		target = 2 * number.random_integer(0, list_size - 1) + 1;
		if (sequential_search(the_list, target, found_at) == not_present)
			cout << "Error: Failed to find expected target " << target << endl;
	}
	print_out("Successful", clock.elapsed_time(), Key::comparisons, searches);

	Key::comparisons = 0;
	clock.reset();
	for (i = 0; i < searches; i++) {
		target = 2 * number.random_integer(0, list_size);
		if (sequential_search(the_list, target, found_at) == success)
			cout << "Error: Found unexpected target " << target
			<< " at " << found_at << endl;
	}
	print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches);
}
void test_search1(int searches, Ordered_list& the_list)
/*

Pre:  None.
Post: The number of key comparisons and CPU time for a
	  sequential searching function have been calculated.
Uses: Methods of the classes List, Random, and Timer,
	  together with an output function print_out
*/
{
	int list_size = the_list.size();
	if (searches <= 0 || list_size < 0) {
		cout << " Exiting test: " << endl
			<< " The number of searches must be positive." << endl
			<< " The number of list entries must exceed 0." << endl;
		return;
	}
	int i, target, found_at;
	Key::comparisons = 0;
	Random number;
	Timer clock;
	cout << "Binary Search 1 " << endl;
	for (i = 0; i < searches; i++) {
		target = 2 * number.random_integer(0, list_size - 1) + 1;
		if (binary_search_1(the_list, target, found_at) == not_present)
			cout << "Error: Failed to find expected target " << target << endl;
	}
	print_out("Successful", 1000*clock.elapsed_time(), Key::comparisons, searches);

	Key::comparisons = 0;
	clock.reset();
	for (i = 0; i < searches; i++) {
		target = 2 * number.random_integer(0, list_size);
		if (binary_search_1(the_list, target, found_at) == success)
			cout << "Error: Found unexpected target " << target
			<< " at " << found_at << endl;
	}
	print_out("Unsuccessful", 1000*clock.elapsed_time(), Key::comparisons, searches);
}
void test_search2(int searches, Ordered_list& the_list)
/*

Pre:  None.
Post: The number of key comparisons and CPU time for a
	  sequential searching function have been calculated.
Uses: Methods of the classes List, Random, and Timer,
	  together with an output function print_out
*/
{
	int list_size = the_list.size();
	if (searches <= 0 || list_size < 0) {
		cout << " Exiting test: " << endl
			<< " The number of searches must be positive." << endl
			<< " The number of list entries must exceed 0." << endl;
		return;
	}
	int i, target, found_at;
	Key::comparisons = 0;
	Random number;
	Timer clock;
	cout << "Binary Search 2 " << endl;
	for (i = 0; i < searches; i++) {
		target = 2 * number.random_integer(0, list_size - 1) + 1;
		if (binary_search_2(the_list, target, found_at) == not_present)
			cout << "Error: Failed to find expected target " << target << endl;
	}
	print_out("Successful", clock.elapsed_time(), Key::comparisons, searches);

	Key::comparisons = 0;
	clock.reset();
	for (i = 0; i < searches; i++) {
		target = 2 * number.random_integer(0, list_size);
		if (binary_search_2(the_list, target, found_at) == success)
			cout << "Error: Found unexpected target " << target
			<< " at " << found_at << endl;
	}
	print_out("Unsuccessful", clock.elapsed_time(), Key::comparisons, searches);
}
int main_1() 
{
	intro();
	int n, searches = 10;
	char command = ' ';
	Ordered_list the_list;
	while (command != 'q' && command != 'Q') {
		cout << "Enter a command of H, Q, F, T,B,S: " << flush;
		cin >> command;
		switch (command) {
		case 'h': case 'H':
			cout << "User options are:\n"
				<< "[H]elp [Q]uit [F]ill list [T]est sequential search, test [B]inary search, [S]how two test"
				<< endl;
			break;
		case 't': case 'T':
			test_search(searches, the_list);
			break;
		case 'b': case 'B':
			test_search1(searches, the_list);
			test_search2(searches, the_list);
			break;
		case 's': case 'S':
			test_search(searches, the_list);
			test_search1(searches, the_list);
			test_search2(searches, the_list);
			break;
		case 'f': case 'F':
			the_list.clear();
			cout << "Enter an upper bound n for the size of list entries:"
				<< flush;
			cin >> n;
			for (int i = 1; i <= n; i += 2)
				if (the_list.insert(the_list.size(), i) != success)
					cout << " Overflow in filling list." << endl;
			break;
		}
	}
	return 0;
}