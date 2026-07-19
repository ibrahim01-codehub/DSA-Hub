#include <iostream>
#include <cstring>
using namespace std;

void reverseString(char str[]) {
    int start = 0;
    int end = strlen(str) - 1;

    while (start < end) {
        swap(str[start], str[end]);
        start++;
        end--;
    }
}

int main() {
    char str[] = "algorithm";
    reverseString(str);
    cout << str << endl;
    return 0;
}
