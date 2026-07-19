#include <iostream>
using namespace std;

long long power(int base, int exp) {
    long long result = 1;

    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }

    return result;
}

int main() {
    cout << "2^10 = " << power(2, 10) << endl;
    return 0;
}
