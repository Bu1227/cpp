/*
    這是一個模擬樂透遊戲。
    先提示使用者輸入 7 個不重複的數字，並以空格分隔，
    程式會使用 stringstream 處理使用者的輸入，並檢查使用者的輸入是否有效，如果輸入的不是 7 個數字或有其他無效的字元，程式會要求使用者重新輸入。
    程式會使用 randomNum 函式隨機生成 7 個不重複的開獎號碼，並用 sort 函式其排序。
    會將使用者輸入的號碼與開獎號碼進行比對，並輸出中獎的號碼。
*/
# include <iostream>
# include <stdlib.h>
# include <time.h>
# include <algorithm>
# include <sstream>
using namespace std;

/***** 隨機亂數 *****/
void randomNum(int A[], int size) {
    int count = 0;
    while (count < size) {
        int tempNum = rand() % 49 + 1;  // 生成1~49的隨機數
        bool repeatFlag = false;  // 用來判斷是否有重複的數字
        for (int i = 0; i < count; i++) {
            if (A[i] == tempNum) {
                repeatFlag = true;  // 如果有重複的數字，repeatFlag設為true
                break;
            }
        }
        if (!repeatFlag) {
            A[count] = tempNum;  // 如果沒有重複的數字，將tempNum存入A陣列的第count項
            count++;  // count + 1
        }
    }
}

/***** 主程式 *****/
int main() {
    int A[7], B[7];  // 宣告兩個陣列A和B有7格，A用來記錄電腦的random數字，B用來記錄使用者輸入的數字
    srand((int)time(NULL)); // 用time(NULL)來設定亂數種子
    bool repeatFlag = false; // 宣告repeatFlag為false，repeatFlag用來判斷在生成隨機數字時是否有重複的數字
    string input;  // 設定變數input為字串
    bool validInput = false;  // 設定無效輸入的變數
    while (!validInput) {
        validInput = true; // 假設輸入有效
        cout << "請輸入 7 個數字，以空格分隔: ";  // 提示使用者輸入訊息
        getline(cin, input); // 使用 getline 讀取使用者輸入的內容
        stringstream ss(input); // 將輸入字串放入 stringstream
        for (int i = 0; i < 7; i++) {
            if (!(ss >> B[i])) { // 檢查是否成功讀取數字
                validInput = false; // 如果不是數字，設為無效
                break;
            }
        }
        if (!validInput || !ss.eof()) { // 確保輸入剛好是 7 個數字, end of file
            validInput = false;  // 如果不是 7 個數字，設為無效
            cout << "輸入無效，請重新輸入 7 個數字並以空格分隔" << endl;  // 提示輸入無效請重新輸入
        }
    }
    randomNum(A, 7); // 呼叫randomNum函數生成隨機數
    sort (A, A+7); // 排序A陣列
    int n = sizeof(A) / sizeof(A[0]); // 以陣列的大小除以第0項的大小，計算A陣列的長度
    cout << endl << "開獎號碼: ";
    for (int k=0; k<n; k++) {  // 用for loop輸出n次
        cout << A[k] << " ";  // 輸出A陣列的第k項
    }
    cout << endl << "中獎號碼: ";
    for (int k=0; k<n; k++) {  // 用for loop輸出n次
        for (int p=0; p<=6; p++) {  // 用for loop輸出6次
            if (B[p] == A[k]) {  // 如果B陣列的第p項等於A陣列的第k項
                cout << B[p] << " ";  // 輸出B陣列的第p項並在後面加上空格
            }
        }
    }
    return 0;
}