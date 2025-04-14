#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <random>

using namespace std;

// 遊戲設定
const int GRID_SIZE = 10;
const int NUM_MINES = 15;

// 遊戲地圖狀態
enum CellState {
    HIDDEN,
    REVEALED,
    FLAGGED
};

// 儲存地圖資訊
struct Cell {
    bool isMine;
    int adjacentMines;
    CellState state;
};

// 初始化遊戲地圖
void initializeBoard(vector<vector<Cell>>& board) {
    // 初始化所有格子為隱藏且非地雷
    for (int i = 0; i < GRID_SIZE; ++i) {
        vector<Cell> row(GRID_SIZE);
        for (int j = 0; j < GRID_SIZE; ++j) {
            row[j] = {false, 0, HIDDEN};
        }
        board.push_back(row);
    }

    // 隨機放置地雷
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<> distrib(0, GRID_SIZE * GRID_SIZE - 1);

    for (int i = 0; i < NUM_MINES; ++i) {
        int pos = distrib(gen);
        int row = pos / GRID_SIZE;
        int col = pos % GRID_SIZE;
        if (!board[row][col].isMine) {
            board[row][col].isMine = true;
        } else {
            i--; // 如果該位置已經是地雷，則重新放置
        }
    }

    // 計算每個格子周圍的地雷數量
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (!board[i][j].isMine) {
                int count = 0;
                for (int x = max(0, i - 1); x <= min(GRID_SIZE - 1, i + 1); ++x) {
                    for (int y = max(0, j - 1); y <= min(GRID_SIZE - 1, j + 1); ++y) {
                        if (board[x][y].isMine) {
                            count++;
                        }
                    }
                }
                board[i][j].adjacentMines = count;
            }
        }
    }
}

// 印出遊戲地圖
void printBoard(const vector<vector<Cell>>& board, bool revealMines = false) {
    cout << "  ";
    for (int j = 0; j < GRID_SIZE; ++j) {
        cout << j << " ";
    }
    cout << endl;
    cout << "--";
    for (int j = 0; j < GRID_SIZE; ++j) {
        cout << "--";
    }
    cout << endl;
    for (int i = 0; i < GRID_SIZE; ++i) {
        cout << i << "| ";
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (board[i][j].state == REVEALED) {
                if (board[i][j].isMine) {
                    cout << "* "; // 地雷
                } else {
                    cout << board[i][j].adjacentMines << " ";
                }
            } else if (board[i][j].state == FLAGGED) {
                cout << "F "; // 旗子
            } else {
                if (revealMines && board[i][j].isMine) {
                    cout << "* "; // 顯示地雷 (遊戲結束時)
                } else {
                    cout << "# "; // 隱藏
                }
            }
        }
        cout << endl;
    }
    cout << endl;
}

// 檢查座標是否在有效範圍內
bool isValid(int row, int col) {
    return (row >= 0 && row < GRID_SIZE && col >= 0 && col < GRID_SIZE);
}

// 揭開一個格子
bool revealCell(vector<vector<Cell>>& board, int row, int col) {
    if (!isValid(row, col) || board[row][col].state != HIDDEN) {
        return false;
    }

    board[row][col].state = REVEALED;

    if (board[row][col].isMine) {
        return true; // 踩到地雷，遊戲結束
    }

    // 如果周圍沒有地雷，則遞迴揭開相鄰的格子
    if (board[row][col].adjacentMines == 0) {
        for (int i = max(0, row - 1); i <= min(GRID_SIZE - 1, row + 1); ++i) {
            for (int j = max(0, col - 1); j <= min(GRID_SIZE - 1, col + 1); ++j) {
                if (i != row || j != col) {
                    revealCell(board, i, j);
                }
            }
        }
    }
    return false;
}

// 標記/取消標記一個格子
void toggleFlag(vector<vector<Cell>>& board, int row, int col) {
    if (isValid(row, col) && board[row][col].state != REVEALED) {
        if (board[row][col].state == HIDDEN) {
            board[row][col].state = FLAGGED;
        } else if (board[row][col].state == FLAGGED) {
            board[row][col].state = HIDDEN;
        }
    }
}

// 檢查是否所有非地雷的格子都被揭開
bool checkWin(const vector<vector<Cell>>& board) {
    int revealedCount = 0;
    int nonMineCount = 0;
    for (int i = 0; i < GRID_SIZE; ++i) {
        for (int j = 0; j < GRID_SIZE; ++j) {
            if (!board[i][j].isMine) {
                nonMineCount++;
            }
            if (board[i][j].state == REVEALED) {
                revealedCount++;
            }
        }
    }
    return revealedCount == nonMineCount;
}

int main() {
    vector<vector<Cell>> board;
    initializeBoard(board);

    bool gameOver = false;
    bool gameWon = false;

    while (!gameOver && !gameWon) {
        printBoard(board);

        int row, col;
        char action;

        cout << "請輸入動作 (r: 揭開, f: 標記/取消標記), 列, 欄 (例如: r 0 0): ";
        cin >> action >> row >> col;

        if (cin.fail() || !isValid(row, col)) {
            cout << "輸入無效，請重新輸入。\n";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            continue;
        }

        if (action == 'r') {
            gameOver = revealCell(board, row, col);
        } else if (action == 'f') {
            toggleFlag(board, row, col);
        } else {
            cout << "無效的動作。\n";
        }

        gameWon = checkWin(board);
    }

    printBoard(board, true); // 顯示所有地雷

    if (gameOver) {
        cout << "你踩到地雷了！遊戲結束。\n";
    } else if (gameWon) {
        cout << "恭喜你！你贏了！\n";
    }

    return 0;
}