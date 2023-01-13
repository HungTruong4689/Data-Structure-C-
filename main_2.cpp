#include "Utility.h"
#include "Key.h"
#include "Random.h"
#include "Timer.h"
#include "List.h"

#include "Sortable_list.h"
void choose() {
	cout << "Your options are:\n"
		<< "[Q]uit[F]ill list \n"
		<< "Write [D] data \n"
		<< "Show [O] output\n"
		<< "[1] insertion sort\n"
		<< "[2] selection sort\n"
		<< "[3] quick sort\n"
		<< endl;
}
void introduction() {
	cout << "Testing program for sorting methods."
		<< endl;
	choose();
}
void write_data(Record& c)
{
	cout << ((Key)c).the_key() << " ";
}
int main_2(){
	List<Record> s;
	List<Record> t = s;
	introduction();
	int n;
	Random dice;
	Error_code report;
	Record target;
	Sortable_list<Record> the_list;
	Sortable_list<Record> copy_list;
	char command = ' ';
	while (command != 'q' && command != 'Q') {
		cout << "Enter a command of H, Q, F, O,D,S "
			<< "1,2,3: "
			<< flush;
		cin >> command;
		switch (command) {
		case 'h': case 'H':
			cout << "User options are:\n"
				<< "[Q]uit[F]ill list \n"
				<< "Write [D] data \n"
				<< "Show [O] output\n"
				<< "[1] insertion sort\n"
				<< "[2] selection sort\n"
				<< "[3] quick sort\n"
				<< endl;
			break;
		case 'd': case 'D':
			cout << "\nUnsorted list \n";
			the_list.traverse(write_data);
			cout << endl;
			break;
		case 'o': case 'O':
			cout << "\nLast sorted list \n";
			copy_list.traverse(write_data);
			cout << endl;
			break;
		case 'f': case 'F':
			the_list.clear();
			cout << "Enter the list entries :"
				<< flush;
			cin >> n;
			for (int i = 0; i < n; i++) {
				target = dice.random_integer(0, 10 * n);
				report = the_list.insert(i, target);
				if (report == overflow) {
					cout << "List space will be filled up with " << i << " entries." << endl;
					cout << " Overflow in filling list." << endl;
				}
			}
			break;
		case '1': case '2': case '3': case '4': {
			copy_list = the_list;
			Key::comparisons = 0;
			Key::assignments = 0;

			Timer clock;
			switch (command) {
			case '1':
				cout << "Insertion Sort ";
				copy_list.insertion_sort_node();
				break;
			case '2':
				cout << "Selection Sort ";
				copy_list.selection_sort();
				break;
			case '3':
				cout << "Quick Sort ";
				copy_list.quick_sort();
				break;
			}

			cout << "Comparisons: " << Key::comparisons << "\n"
				<< "Assignments: " << Key::assignments << "\n"
				<< "Operations: " << Key::comparisons + Key::assignments << "\n"
				<< "Time: " << 1000*clock.elapsed_time() << " milliseconds."
				<< endl;
		}
		break;
		}
	}
	return 0;
}