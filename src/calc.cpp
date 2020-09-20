#include <iostream>
#include <cstring>
#include <string>
using namespace std;

static string version = "dev build 1";
string raw;
char selection;
long double a, b, c;

int main() {
	cout << "Calculator version: " << version << endl; // Print version info.
	start: // Start of loop.
	cout << "Enter operator {+,-,*,/} or q to quit:"; // Prompt for operator input.
	cin >> raw;
	if (raw.find_first_not_of("+-*/q") != string::npos) { // Validate operator input.
		cout << "Invalid.\n"; // Invalid? Go to start.
		goto start;
	} else if (raw == "q") { // If 'q' is given, exit with code 0.
		return 0;
	} else {
		selection = raw.at(0);
	}
	cout << "Enter number to operate on: "; // Prompt for number input.
	cin >> raw;
	if (raw.find_first_not_of("1234567890.-") != string::npos) { // Validate input
		cout << "Invalid.\n"; // Invalid? Go to start.
		goto start;
	} else {
		a = atof(raw.c_str()); // Otherwise, store input.
	}
	cout << "Enter number to operate on: ";
	cin >> raw;
	if (raw.find_first_not_of("1234567890.-") != string::npos) { // Validate input
		cout << "Invalid.\n"; // Invalid? Go to start.
		goto start;
	} else {
		b = atof(raw.c_str()); // Otherwise, store input.
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
	cout << "====================\n" << a << selection << b << "=" << c << "\n====================\n"; // Print output.
	goto start; // Restart loop.
}
