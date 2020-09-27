#include <iostream> // Library for I/O.
#include <string> // Library for string functions.
#include <cmath> // Library for extended math functions.
using namespace std;

#define VERSION "1.2.0"
const char *manual =
		" + => Addition\n"
		" - => Subtraction\n"
		" * => Multiplication\n"
		" / => Division\n"
		" ^ => Exponentiate by <>\n"
		"r2 => Square root of <>\n"
		"r3 => Cubic root of <>\n"
		" q => Quit\n"
		" m => This page\n";
string raw;
long double a, b, c;

string root(bool cube) {
	if (cube == true) {
		cout << "Enter value to get the cube root of: ";
		getline(cin, raw);
		try { // Test for invalid_argument.
			a = stold(raw);
		} catch (invalid_argument&) {
			return "Invalid."; // invalid_argument exception? Return "Invalid".
		}
		c = cbrt(a); // Get cubic root of a.
	} else {
		cout << "Enter value to get the square root of: ";
		getline(cin, raw);
		try { // Test for invalid_argument.
			a = stold(raw);
		} catch (invalid_argument&) {
			return "Invalid."; // invalid_argument exception? Return "Invalid".
		}
		c = sqrt(a); // Get square root of a.
	}
	return to_string(c);
}

string exponent() {
	cout << "Enter base: "; // Prompt for input of base.
	getline(cin, raw);
	try { // Test for invalid_argument.
		a = stold(raw);
	} catch (invalid_argument&) {
		return "Invalid."; // invalid_argument exception? Return "Invalid".
	}
	cout << "Enter exponent: ";
	getline(cin, raw); // Prompt for input of exponent.
	try { // Test for invalid_argument.
		b = stold(raw);
	} catch (invalid_argument&) {
		return "Invalid."; // invalid_argument exception? Return "Invalid".
	}
	c = powl(a, b); // Raise a to the power of b.
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
		cout << "Enter operator to use (m for manual, q for quit): "; // Prompt for operator input.
		getline(cin, raw);
		if (raw.find_first_not_of("+-*/^qr23m") != string::npos) { // Validate operator input.
			cout << "Invalid.\n"; // Invalid? Go to start.
			continue;
		} else if (raw.empty()){
			continue;
		} else if (raw == "^") { // If '^' is given, call exponent function.
			out = exponent() + "\n";
		} else if (raw == "r2") { // If 'r2' is given, call square root function.
			out = root(false) + "\n";
		} else if (raw == "r3") { // If 'r3' is given, call cubic root function.
			out = root(true) + "\n";
		} else if (raw == "m") { // If 'm' is given, call manual.
			out = manual;
		} else if (raw == "q") { // If 'q' is given, exit with code 0.
			return 0;
		} else if (raw == "+" || "-" || "*" || "/") { // Otherwise, call basic math function.
			out = basicMath(raw[0]) + "\n";
		}
		cout << endl << out << endl;
	} while (true);
}
