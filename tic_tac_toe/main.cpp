#include <iostream>
#include <sstream>
using namespace std;

int main (void) {
    char map[4][4], player;
    int x, y, a, b;
    int count = 0, end = 0, inputok = 0;

    cout << "###################" << endl;
    cout << " 井   字   遊   戲 " << endl;
    cout << "###################" << endl;
    cout << endl;
    cout << " (1,1) | (1,2) | (1,3)" << endl;
    cout << "-------+-------+-------" << endl;
    cout << " (2,1) | (2,2) | (2,3)" << endl;
    cout << "-------+-------+-------" << endl;
    cout << " (3,1) | (3,2) | (3,3)" << endl;
    cout << endl; // 換行

    for (x=1; x<4; x++)
        for (y=1; y<4; y++)
            map[x][y] = '.';

    cout << "請輸入 exit 來提前結束遊戲!" << endl; // 提示使用者可以輸入 exit 來結束遊戲
    while (end == 0 & count < 9) {
        while (end == 0, inputok == 0) {
            if ((count % 2) == 0) {
                player = 'O';
            } else {
                player = 'X';
            }
            cout << "目前輪到玩家 " << player << " 輸入 (例如: 1,1): ";
            
            string input;
            cin >> input;
            if (input == "exit") {
                cout << "遊戲結束! (使用者終止)" << endl;
                return 0; // 結束程式
            }
            stringstream ss(input);
            char comma; // 檢查逗號
            ss >> a >> comma >> b; // 解析行列

            if (ss.fail() || comma != ',' || a < 1 || a > 3 || b < 1 || b > 3) {
                cout << "請輸入正確的格式 (例如: 1,1) 且範圍為 1~3!" << endl;
            } else if (map[a][b] != '.') {
                cout << "該位置已經被佔用!" << endl;
            } else {
                inputok = 1;
            }
        }
        inputok = 0;
        map[a][b] = player;

        for (x = 1; x < 4; x++) {
            for (y = 1; y < 4; y++) {
                cout << " " << map[x][y];
                if (y < 3) cout << " |"; // 直分隔 最後一個不要加
            }
            cout << endl;
            if (x < 3) {
                cout << "---+---+---" << endl;
            } // 如果不是最後一行 加上橫分隔
        }

        if ((map[1][1] == player && map[1][2] == player && map[1][3] == player) ||
            (map[2][1] == player && map[2][2] == player && map[2][3] == player) ||
            (map[3][1] == player && map[3][2] == player && map[3][3] == player) ||
            (map[1][1] == player && map[2][1] == player && map[3][1] == player) ||
            (map[1][2] == player && map[2][2] == player && map[3][2] == player) ||
            (map[1][3] == player && map[2][3] == player && map[3][3] == player) ||
            (map[1][1] == player && map[2][2] == player && map[3][3] == player) ||
            (map[1][3] == player && map[2][2] == player && map[3][1] == player)) {
            end = 1;
            cout << "遊戲結束!" << endl;
            cout << "玩家 " << player << " 贏了!" << endl; // 顯示勝利者
        } else if (count == 8) { // 如果已經下滿 9 步且沒有勝利者
            end = 1;
            cout << "遊戲結束!" << endl;
            cout << "平手!" << endl; // 顯示平手
        } else {
            count++;
        }
    }
}