#include <iostream>
using namespace std;

void countDown(int n) {
    if (n == 0) return;
    cout << n << " ";
    countDown(n - 1);
}

int main() {
    countDown(10);
    return 0;
}
