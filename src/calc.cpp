#include <iostream> // Library for I/O.
#include <string> // Library for string functions.
#include <cmath> // Library for std::powl.
using namespace std; // Set namespace.

#define VERSION "1.1.0"
string raw;
long double a, b, c;

string exponent() {
	cout << "Enter base: "; // Prompt for input of base.
	getline(cin, raw);
	try { // Test for invalid_argument.
		a = stold(raw);
	} catch (invalid_argument&) {
		return "Invalid."; // invalid_argument exception? Return "Invalid".
	}
	cout << "Enter exponent: ";
	getline(cin, raw); // Prompt for input of expoonent.
	try { // Test for invalid_argument.
		b = stold(raw);
	} catch (invalid_argument&) {
		return "Invalid."; // invalid_argument exception? Return "Invalid".
	}
	c = powl(a, b);
	return to_string(c);
}

string basicMath(char selection) {
	cout << "Enter number to operate on: "; // Prompt for number input.
	getline(cin, raw);
	try { // Test for invalid_argument.
		a = stold(raw);
	} catch (invalid_argument&) {
		return "Invalid."; // invalid_argument exception? Return "Invalid".
	}
	cout << "Enter number to operate on: "; // Prompt for number input.
	getline(cin, raw);
	try { // Test for invalid_argument.
		b = stold(raw);
	} catch (invalid_argument&) {
		return "Invalid."; // invalid_argument exception? Return "Invalid".
	}
	switch (selection) { // Determine operation to run.
		case '+': c = a + b; break;
		case '-': c = a - b; break;
		case '*': c = a * b; break;
		case '/': c = a / b; break;
	}
	return to_string(c);
}

int main() {
	string out;
	do {
		cout << "Calculator version: " << VERSION << endl; // Print version info.
		cout << "Enter operator {+,-,*,/,^} or q to quit:"; // Prompt for operator input.
		getline(cin, raw);
		if (raw.find_first_not_of("+-*/^q") != string::npos) { // Validate operator input.
			cout << "Invalid.\n"; // Invalid? Go to start.
			continue;
		} else if (raw == "^") {
			out = exponent() + "\n";
		} else if (raw == "q") { // If 'q' is given, exit with code 0.
			return 0;
		} else {
			out = basicMath(raw[0]) + "\n";
		}
		cout << endl << out << endl;
	} while (true);
}
