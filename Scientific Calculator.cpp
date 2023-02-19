#include <iostream>
#include <cmath>
using namespace std;
double sqrt(double num) {
    return sqrt(num);
}
double power(double base, double exponent) {
    return pow(base, exponent);
}
double log(double base, double num) {
    return log(num) / log(base);
}
double sin(double angle) {
    return sin(angle);
}
double cos(double angle) {
    return cos(angle);
}
double tan(double angle) {
    return tan(angle);
}
double deg_to_rad(double degrees) {
    return degrees * M_PI / 180.0;
}
double rad_to_deg(double radians) {
    return radians * 180.0 / M_PI;
}
double factorial(double num) {
    double result = 1;
    for (int i = 2; i <= num; i++) {
        result *= i;
    }
    return result;
}
double abs_val(double num) {
    return abs(num);
}
double inv(double num) {
    return 1/num;
}
double percent(double num) {
    return num/100;
}
double exp(double num) {
    return exp(num);
}
double get_pi() {
    return M_PI;
}
double get_e() {
    return M_E;
}
int main() {
    // Prompt the user for what type of calculation they want to perform
    string calculation;
    cout << "What type of calculation would you like to perform? (sqrt, power, log, sin, cos, tan, deg_to_rad, rad_to_deg, factorial, abs_val, inv, percent, exp, get_pi, get_e): ";
    cin >> calculation;
    // Perform the calculation based on the user's input
    if (calculation == "sqrt") {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        double result = sqrt(num);
        cout << "Square root of " << num << " is " << result << endl;
    }
    else if (calculation == "power") {
        double base, exponent;
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the exponent: ";
        cin >> exponent;
        double result = power(base, exponent);
        cout << base << " to the power of " << exponent << " is " << result << endl;
    }
    else if (calculation == "log") {
        double base, num;
        cout << "Enter the base: ";
        cin >> base;
        cout << "Enter the number: ";
        cin >> num;
        double result = log(base, num);
        cout << "Log base " << base << " of " << num << " is " << result << endl;
    }
    else if (calculation == "sin") {
        double angle;
        cout << "Enter the angle in degrees: ";
        cin >> angle;
        double result = sin(deg_to_rad(angle));
        cout << "Sine of " << angle << " degrees is " << result << endl;
    }
    else if (calculation == "cos") {
        double angle;
        cout << "Enter the angle in degrees: ";
        cin >> angle;
        double result = cos(deg_to_rad(angle));
        cout << "Cosine of " << angle << " degrees is " << result << endl;
    }
    else if (calculation == "tan") {
        double angle;
        cout << "Enter the angle in degrees: ";
        cin >> angle;
        double result = tan(deg_to_rad(angle));
        cout << "Tangent of " << angle << " degrees is " << result;
    }
    else if (calculation == "deg_to_rad") {
        double degrees;
        cout << "Enter the angle in degrees: ";
        cin >> degrees;
        double result = deg_to_rad(degrees);
        cout << degrees << " degrees is " << result << " radians" << endl;
    }
    else if (calculation == "rad_to_deg") {
        double radians;
        cout << "Enter the angle in radians: ";
        cin >> radians;
        double result = rad_to_deg(radians);
        cout << radians << " radians is " << result << " degrees" << endl;
    }
    else if (calculation == "factorial") {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        double result = factorial(num);
        cout << num << "! is " << result << endl;
    }
    else if (calculation == "abs_val") {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        double result = abs_val(num);
        cout << "Absolute value of " << num << " is " << result << endl;
    }
    else if (calculation == "inv") {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        double result = inv(num);
        cout << "Inverse of " << num << " is " << result << endl;
    }
    else if (calculation == "percent") {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        double result = percent(num);
        cout << num << " as a percentage is " << result << "%" << endl;
    }
    else if (calculation == "exp") {
        double num;
        cout << "Enter the number: ";
        cin >> num;
        double result = exp(num);
        cout << "e to the power of " << num << " is " << result << endl;
    }
    else if (calculation == "get_pi") {
        double result = get_pi();
        cout << "The value of pi is " << result << endl;
    }
    else if (calculation == "get_e") {
        double result = get_e();
        cout << "The value of e is " << result << endl;
    }
    else {
        cout << "Invalid input. Please try again." << endl;
    }
    return 0;
}
