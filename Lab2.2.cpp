#include <iostream>
#include <cmath>
#include <iomanip>
using namespace std;

int main() {
    float sum10 = 0;
    float sum = 0;
    float term;
    float sign = 1;
    int n = 0;

    const double eps = 0.000001;
    for (n = 0; n < 10; n++) {
        term = sign / ((n + 1.0) * (n + 2.0) * (n + 3.0));
        sum10 = sum10 + term;
        sign = -sign;
    }

    n = 0;
    sign = 1;
    while (true) {
        term = sign / ((n + 1.0) * (n + 2.0) * (n + 3.0));
        if (fabs(term) <= eps) {
            break;
        }
        sum = sum + term;
        sign = -sign;
        n++;
    }

    cout << fixed << setprecision(9);
    cout << "Sum of first 10 terms = " << sum10 << endl;
    cout << "Total sum of series = " << sum << endl;
    return 0;
}
