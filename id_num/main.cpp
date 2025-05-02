#include <iostream>A
using namespace std;

main () {
    cout << "Please enter your ID number: ";
    string id_num;
    cin >> id_num;
    if (id_num.length() != 10) {
        cout << "Invalid ID number length." << endl;
        return 1;
    }

    char first_char = id_num[0];
    if (first_char < 'A' || first_char > 'Z') {
        cout << "Invalid first character." << endl;
        return 1;
    }

    int mapping[] = {10, 11, 12, 13, 14, 15, 16, 17, 34, 18, 19, 20, 21, 22, 35, 23, 24, 25, 26, 27, 28, 29, 32, 30, 31, 33};
    int first_num = mapping[first_char - 'A'];

    int sum = (first_num / 10) + (first_num % 10) * 9;
    for (int i = 1; i <= 8; ++i) {
        if (!isdigit(id_num[i])) {
            cout << "Invalid character in ID number." << endl;
            return 1;
        }
        sum += (id_num[i] - '0') * (9 - i);
    }

    if (id_num[1] != '1' && id_num[1] != '2') {
        cout << "Invalid second character in ID number." << endl;
        return 1;
    }

    if (!isdigit(id_num[9])) {
        cout << "Invalid last character in ID number." << endl;
        return 1;
    }

    sum += (id_num[9] - '0');

    if (sum % 10 == 0) {
        cout << "Valid ID number." << endl;
    } else {
        cout << "Invalid ID number." << endl;
    }
}