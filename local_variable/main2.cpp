#include <iostream>
using namespace std;

int g1 = 30 ,g2 = 20;

int f1(int v) { // v=g2=0
    int g1 = 10; // 區域變數 g1=10
    return g1+v; // 10+0
}

int f2(int v) { //第一次: v=g2=10，第二次: v=f2(g2)=50
    int c = g2; //c=g2=10(全域)
    v = v + c + g1; //第一次: 10+10+30=50，第二次: 50+10+10
    g1 = 10; //第一次被執行時區域g1被改成10，第二次執行時上一行g1要用10
    c = 40;
    return v; //第一次: 50，第二次: 70
}

main(void) {
    g2 = 0;
    g2 = f1(g2); //全域變數g2被改成10
    cout << f2(f2(g2)); // f2(g2) = 50，f2(f2(g2)) = 70
    return 0;
}