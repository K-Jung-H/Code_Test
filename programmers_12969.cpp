#include <iostream>

using namespace std;

int main(void) {
    int a;
    int b;
    cin >> a >> b;

    for (int i = 0; i < b; ++i) {
        for (int k = 0; k < a; ++k)
            cout << "*";
        cout << '\n';
    }
    return 0;
}

// O(N)
int main(void) {
    int a;
    int b;
    cin >> a >> b;

    string s(a, '*');
    for (int i = 0; i < b; ++i) {
        cout << s << '\n';
    }

    return 0;
}