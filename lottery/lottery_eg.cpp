# include <iostream>
# include <stdlib.h>
# include <time.h>
using namespace std;

int main() {
    int A[7], B[7];  //宣告兩個陣列A和B有7格，A用來記錄電腦的random數字，B用來記錄使用者輸入的數字
    srand((int)time(NULL)); //用time(NULL)來設定亂數種子
    int tempNum, count = 0;  //宣告tempNum和count變數為0
    bool repeatFlag = false; //宣告repeatFlag為false，repeatFlag用來判斷在生成隨機數字時是否有重複的數字
    for (int i=0; i<=6; i++) {  //用for loop輸入6次
        cout<<"請輸入第 "<<i+1<<" 數字: ";  //提示使用者輸入訊息
        cin>>B[i];  //使用者輸入的數字存入B陣列的第i項
    }
    do {
        repeatFlag = false;
        tempNum = rand() % 38 + 1;
        for (int i=0; i<=count; i++) {
            if (A[i] == tempNum) {
                repeatFlag = true;
            }    
        }
        if (!repeatFlag) {
                A[count] = tempNum;
                count++;
            }
    } while(count <= 6);
    int j, tmp;
    int n = sizeof(A) / sizeof(int); //計算A陣列的長度
    for (int i=0; i<=5; i++) {  //用for loop排序A陣列
        for (j = i+1; j<=6; j++) {  //用for loop排序A陣列
            if (A[i] > A[j]) {
                tmp = A[i];
                A[i] = A[j];
                A[j] = tmp;
            }
        }
    }
    cout << endl << "開獎號碼：";
    for (int k=0; k<n; k++) {  //用for loop輸出n次
        cout << A[k] << " ";  //輸出A陣列的第k項
    }
    cout << endl << "中獎號碼：";
    for (int k=0; k<n; k++) {
        for (int p=0; p<=6; p++) {
            if (B[p] == A[k]) {
                cout << B[p] << " ";
            }
        }
    }
    return 0;
}