#include <iostream> // Library for I/O.
#include <string> // Library for string functions.
using namespace std; // Set namespace.

#define VERSION "1.0.1"

int main() {
	string raw;
	char selection;
	long double a, b, c;
	do {
		cout << "Calculator version: " << VERSION << endl; // Print version info.
		cout << "Enter operator {+,-,*,/} or q to quit:"; // Prompt for operator input.
		getline(cin, raw);
		if (raw.find_first_not_of("+-*/q") != string::npos) { // Validate operator input.
			cout << "Invalid.\n"; // Invalid? Go to start.
			continue;
		} else if (raw == "q") { // If 'q' is given, exit with code 0.
			return 0;
		} else {
			selection = raw[0];
		}
		cout << "Enter number to operate on: "; // Prompt for number input.
		getline(cin, raw);
		try { // Test for invalid_argument.
			a = stof(raw);
		} catch (invalid_argument&) {
			cout << "Invalid.\n"; // invalid_argument? Go to start.
			continue;
		}
		cout << "Enter number to operate on: ";
		getline(cin, raw);
		try { // Test for invalid_argument.
			b = stof(raw);
		} catch (invalid_argument&) {
			cout << "Invalid.\n"; // invalid_argument? Go to start.
			continue;
		}
		if (selection == '+') { // Determine operation to run.
			c = a + b;
		} else if (selection == '-') {
			c = a - b;
		} else if (selection == '*') {
			c = a * b;
		} else if (selection == '/') {
			c = a / b;
		}
		cout << "========================================\n" << a << selection << b << "=" << c << "\n========================================\n"; // Print output.
	} while (true);
}
