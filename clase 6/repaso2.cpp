#include <iostream>
using namespace std;

string unir(string a, string b) {
    return a + b + to_string(5);
}

int main() {
    cout << unir("Hola", "Mundo") << endl;
    return 0;
}
