#include <iostream>
#include <tuple>
using namespace std;

tuple<double, double> getIntersectionPoint(tuple<double, double, double> line1, tuple<double, double, double> line2) {
    double a1, b1, c1, a2, b2, c2;
    tie(a1, b1, c1) = line1;
    tie(a2, b2, c2) = line2;

    double x = (b2 * c1 - c2 * b1) / (b1 * a2 - a1 * b2);
    double y = (a1 * x + c1) / -b1;

    return make_tuple(x, y);
}

tuple<double, double, double> getPerpendicular(tuple<double, double, double> line, tuple<double, double> point) {
    double a, b, c, x, y;
    tie(a, b, c) = line;
    tie(x, y) = point;

    double c1 = a * y - b * x;
    return make_tuple(b, -a, c1);
}

string getLineFormula(double a, double b, double c) {
    string s1 = b >= 0 ? "+" : "-";
    string s2 = c >= 0 ? "+" : "-";
    return to_string(a) + "x " + s1 + " " + to_string(abs(b)) + "y " + s2 + " " + to_string(abs(c)) + " = 0";
}

tuple<double, double, double, double, double> readUserInput() {
    double a, b, c, x, y;
    cout << "Enter a: ";
    cin >> a;
    cout << "Enter b: ";
    cin >> b;
    cout << "Enter c: ";
    cin >> c;
    cout << "Enter x: ";
    cin >> x;
    cout << "Enter y: ";
    cin >> y;

    return make_tuple(a, b, c, x, y);
}

int main() {
    cout << "Input:     line (ax + by + c = 0)," << endl;
    cout << "           point (x, y)," << endl;
    cout << "Output:    point (x1, y1)," << endl;
    cout << "Algorithm: Find the intersection point of the given line and its perpendicular passing through the given point." << endl;
    cout << endl;

    double a, b, c, x, y;
    tie(a, b, c, x, y) = readUserInput();
    cout << endl;
    cout << "Input:     " << getLineFormula(a, b, c) << " line," << endl;
    cout << "           (" << x << ", " << y << ") point" << endl;
    cout << endl;

    tuple<double, double, double> perpendicularLine = getPerpendicular(make_tuple(a, b, c), make_tuple(x, y));
    cout << "Output:    " << getLineFormula(get<0>(perpendicularLine), get<1>(perpendicularLine), get<2>(perpendicularLine)) << " line," << endl;
    tuple<double, double> intersectionPoint = getIntersectionPoint(make_tuple(a, b, c), perpendicularLine);
    cout << "           (" << get<0>(intersectionPoint) << ", " << get<1>(intersectionPoint) << ") intersection point." << endl;

    return 0;
}
