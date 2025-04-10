#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    int a[5];
    // int a[] = {3, 2, 4, 9, 0, 5};
    for (int i=0; i<6; i++) {
        rand() >> a[i];
    }
    int n = sizeof(a) / sizeof(a[0]);
    cout << "a陣列有 " << n << " 個數字" << endl;
    cout << "排序前的a陣列: ";
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    sort (a, a+n);
    cout << endl << "排序後的a陣列: " ;
    for (int i=0; i<n; i++) {
        cout << a[i] << " ";
    }
    return 0;
}