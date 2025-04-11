#include <iostream>
#include <ctime>
using namespace std;

main() {
    int answer[4]; // 儲存隨機生成的數字
    int guess[4];  // 儲存使用者輸入的數字
    int a = 0, b = 0; // 儲存幾A幾B
    bool used[10] = {false}; // 用來紀錄0~9是否被用過
    bool invalidnum = false;
    srand(time(0)); // 初始化隨機數種子

    // 隨機生成 4 個不重複的數字
    for (int i = 0; i < 4; i++) {
        int num;
        do {
            num = rand() % 10; // 生成 0~9 的隨機數
        } while (used[num]); // 確保數字不重複
        answer[i] = num; // 儲存隨機數字進入答案陣列
        used[num] = true;
    }

    cout << "歡迎來到猜幾A幾B的小遊戲！" << endl;
    cout << "答案是："; // 提示使用者答案是什麼
    for (int i = 0; i < 4; i++) { // 輸出答案陣列的內容
        cout << answer[i]; // 輸出隨機生成的數字
    }
    cout << endl << "請輸入 4 個 0~9 的數字 (例如: 1234): " << endl;

    while (a != 4) { // 當不是 4A 時繼續遊戲
        a = 0; // 重置 a,b 計數為0
        b = 0;

        // 讀取使用者輸入
        string input; // 宣告字串input來儲存使用這輸入的內容
        cin >> input; // 讀取使用者輸入的字串
        if (input.length() != 4) { // 檢查輸入的長度是否為 4
            cout << "請輸入正確的 4 位數字！" << endl;
            // cout << "請重新輸入: ";
            continue; // 略過下面的內容讓使用者重新輸入
        }

        for (int i = 0; i < 4; i++) {
            guess[i] = input[i] - '0'; // 將字元轉換為整數
            if (guess[i] < 0 || guess[i] > 9) {
                cout << "請輸入有效的數字（0~9）！" << endl;
                invalidnum = true;
                break;
            }
        }
        if (invalidnum) {
            invalidnum = false; // 重置無效數字
            continue; // 略過下面的內容讓使用者重新輸入
        }

        // 計算幾A幾B
        for (int i = 0; i < 4; i++) {
            if (guess[i] == answer[i]) {
                a++; // 數字和位置都正確
            } else {
                for (int j = 0; j < 4; j++) {
                    if (guess[i] == answer[j]) {
                        b++; // 數字正確但位置錯誤
                        continue;
                    }
                }
            }
        }

        // 輸出結果
        cout << a << "A" << b << "B" << endl;

        if (a == 4) {
            cout << "恭喜你猜對了！答案是：";
            for (int i = 0; i < 4; i++) {
                cout << answer[i];
            }
            cout << endl;
        } else {
            cout << "再試一次！" << endl;
        }
    }

    return 0;
}