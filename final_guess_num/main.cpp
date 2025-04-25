#include <iostream>
#include <ctime>
#include <limits>
using namespace std;

int main() {
    srand(time(0)); // 初始化隨機數種子
    int number = rand() % 100 + 1; // 生成 1 ~ 100 的隨機數
    int guess;
    int count = 0;
    int low = 1, high = 100; // 初始化數字範圍

    cout << "==================================================" << endl;
    cout << "🎉 歡迎來到猜數字遊戲！ 🎉" << endl;
    cout << "🤔 我已經想好了一個 1 到 100 的數字，你能猜出來嗎？" << endl;
    cout << "==================================================" << endl;

    do {
        cout << "🔍 請輸入你的猜測（範圍：" << low << " ~ " << high << "）：";
        cin >> guess;

        // 檢查輸入是否為有效數字
        if (cin.fail()) {
            cin.clear(); // 清除錯誤標記
            cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 忽略輸入緩衝區中的內容
            cout << "⚠️ 無效的輸入！請輸入一個數字。" << endl;
            continue; // 要求重新輸入
        }

        count++;

        if (guess > number) {
            cout << "📉 太大了！再試一次。" << endl;
            high = guess - 1; // 更新範圍的上限
        } else if (guess < number) {
            cout << "📈 太小了！再試一次。" << endl;
            low = guess + 1; // 更新範圍的下限
        } else {
            cout << "🎊 恭喜你！你猜對了！ 🎊" << endl;
            cout << "🏆 你總共猜了 " << count << " 次！" << endl;
        }
        cout << "========================================" << endl;
    } while (guess != number);

    cout << "🎮 感謝你玩猜數字遊戲！再見！ 👋" << endl;

    return 0;
}