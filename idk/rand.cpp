#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int main() {
    srand(time(NULL));
    int a[6] = {};
    for(int i=0; i<10; i++) {
        cout << rand()%6+1 << " ";
    }
    return 0;
}