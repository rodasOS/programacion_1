#include <iostream>
#include <vector>
using namespace std;

void calcular(int arr[], vector<int> &v, int &res) {
    res = arr[0] + v[0];
    arr[0] = 50;
    v[0] = 100;
}

int main() {
    int a[2] = {5, 10};
    vector<int> b = {20, 30};
    int r;

    calcular(a, b, r);

    cout << r << " " << a[0] << " " << b[0] << endl;

    return 0;
}
