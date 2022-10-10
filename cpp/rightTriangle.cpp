#include <iostream>
#include <cmath>

using namespace std;
int main() {
	float x1, x2, x3,
		y1, y2, y3,
		dist1, dist2, dist3,
		num1, num2,
		gip, kat1, kat2;
	double e = 0.01;
	cin >> x1; cin >> y1;
	cin >> x2; cin >> y2;
	cin >> x3; cin >> y3;
	dist1 = sqrt(pow(abs(x2 - x1), 2) + pow(abs(y2 - y1), 2));
	dist2 = sqrt(pow(abs(x3 - x2), 2) + pow(abs(y3 - y2), 2));
	dist3 = sqrt(pow(abs(x3 - x1), 2) + pow(abs(y3 - y1), 2));

	if (abs(pow(dist1, 2) - (pow(dist2, 2) + pow(dist3, 2))) < e) {
		num1 = x1 + x2 - x3;
		num2 = y1 + y2 - y3;
		cout << "the triangle is rectangular ; the vertex of the rectangle = " << num1 << " ; " << num2 << endl;
	}
	else if (abs(pow(dist2, 2) - (pow(dist1, 2) + pow(dist3, 2))) < e) {
		num1 = x2 + x3 - x1;
		num2 = y2 + y3 - y1;
		cout << "the triangle is rectangular ; the vertex of the rectangle = " << num1 << " ; " << num2 << endl;
	}
	else if (abs(pow(dist3, 2) - (pow(dist2, 2) + pow(dist1, 2))) < e) {
		num1 = x1 + x3 - x2;
		num2 = y1 + y3 - y2;
		cout << "the triangle is rectangular ; the vertex of the rectangle = " << num1 << " ; " << num2 << endl;
	}
	else {
		cout << "error. the triangle is not rectangular" << endl;
	}
}