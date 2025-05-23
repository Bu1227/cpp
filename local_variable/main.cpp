#include <iostream>
using namespace std;

int s=1;

void add(int a) //自訂函式 add，int a 為傳入的 s=1
{
    int s=6;
    for ( ; a>=0; a--) // a=1, a=0，執行兩次
    {
        cout << s << ","; //第一次區域變數 s=6，第二次區域變數 s=7
        s++;
        cout << s << ","; //第一次區域變數 s=7，第二次區域變數 s=8
    }
}

main(void)
{
    cout << s << ","; //全域變數 s=1
    add(s); //呼叫自訂函式 add，傳送全域變數 s=1
    cout << s << ","; //全域變數 s=1
    s=9; //修改全域變數 s=9
    cout << s; //全域變數 s=9
    return 0;
}
