#include <iostream>
#include <string>
using namespace std;

// 加密函式
string encrypt(const string & input) {
    string result;
    for (char c : input) {
        if (isalpha(c)) { // 檢查是否為英文字母
            if (islower(c)) {
                result += (c - 'a' + 2) % 26 + 'a'; // 處理小寫字母
            } else {
                result += (c - 'A' + 2) % 26 + 'A'; // 處理大寫字母
            }
        } else {
            result += c; // 非字母保持不變
        }
    }
    return result;
}

// 解密函式
string decrypt(const string & input) {
    string result;
    for (char c : input) {
        if (isalpha(c)) { // 檢查是否為英文字母
            if (islower(c)) {
                result += (c - 'a' - 2 + 26) % 26 + 'a'; // 處理小寫字母
            } else {
                result += (c - 'A' - 2 + 26) % 26 + 'A'; // 處理大寫字母
            }
        } else {
            result += c; // 非字母保持不變
        }
    }
    return result;
}

int main() {
    cout << "請輸入加密或解密指令 (+ 或 -)，後接字串：";
    string input;
    cin >> input;

    if (input[0] == '+') {
        string toEncrypt = input.substr(1); // 去掉第一個字元 '+'
        cout << "加密結果：" << encrypt(toEncrypt) << endl;
    } else if (input[0] == '-') {
        string toDecrypt = input.substr(1); // 去掉第一個字元 '-'
        cout << "解密結果：" << decrypt(toDecrypt) << endl;
    } else {
        cout << "無效的指令，請輸入 + 或 -。" << endl;
    }

    return 0;
}