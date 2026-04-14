#include <iostream>
using namespace std;

int contador() {
    static int x = 0;
    x++;
    return x;
}

int main() {
    cout << contador() << endl;
    cout << contador() << endl;
    cout << contador() << endl;
    return 0;
}
