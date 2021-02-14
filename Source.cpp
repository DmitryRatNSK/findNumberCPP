#include <iostream>

using namespace std;

int main() {
	int answer, i, trying, number_hints;
	string hint;
	answer = time(NULL) % 100;
	i = 1;
	number_hints = 0;
	trying = 101;
	cout << "range 100" << endl;
	while (answer != trying) {
		cout << i << "th try: ";
		cin >> trying;
		while (cin.fail()) {
			cin.clear();
			cin.ignore(32767, '\n');
			cout << "Validation ERROR, try again" << endl;
			cout << i << "th try: ";
			cin >> trying;
		}
		while ((i % 2) == 0 && answer != trying) {
			cout << "hint?(y/n): ";
			cin >> hint;
			while (true) {
				if (hint != "y" && hint != "n") {
					cout << "Validation ERROR, try again" << endl;
					cout << "hint?(y/n): ";
					cin >> hint;
				}
				else break;
			}
			if (hint == "y") {
				switch (number_hints)
				{
				case 0:
					if (answer <= 50) {
						cout << "number less or is than 50" << endl;
						number_hints++;
					}
					else if (answer >= 50) {
						cout << "number more than or is 50" << endl;
						number_hints++;
					}
					break;

				case 1:
					if ((answer % 2) == 1) {
						cout << "number is not even" << endl;
						number_hints++;
					}
					else if ((answer % 2) == 0) {
						cout << "number is even" << endl;
						number_hints++;
					}
					break;
				case 2:
					cout << "number has " << answer / 10 << " tens" << endl;
					break;
				case 3:
					cout << "number has " << answer % 10 << "units" << endl;
					break;
				}
			}
			break;
		}
		if (answer != trying) i++;
	}
	cout << "you won with " << i << "th tryings" << endl;
	system("pause");
}
