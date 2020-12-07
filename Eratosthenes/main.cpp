#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

// ############################################################
//                     ERATOSTHEN ALG
// ############################################################

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    auto len_arr = [](int x) { return to_string(x).length()+1; };

    vector<vector<int>> matrix;
    vector<int> matrix_data;
    int n;
    cout << "Размер квадратной матрицы: ";
    cin >> n;

    matrix.resize(n);
    for (auto &i : matrix)
        i.resize(n);

    int c = 1;
    for (auto &i : matrix)
        for (auto &j : i) {
            j = c;
            c++;
        }

    for (auto &i : matrix) {
        for (auto &j : i) {
            cout << setw(len_arr(n*n)) << j;
            matrix_data.push_back(j);
        }
        cout << endl;
    }
    auto [min, max] = minmax_element(begin(matrix_data), end(matrix_data));
    cout << endl;

    vector<int> res, temp_arr;
    temp_arr.resize(n*n+1);
    for (int i = 0; i < (n*n+1); i++) {
        temp_arr[i] = i;
    }

    for (int p = 2; p < (n*n+1); p++) {
        if (temp_arr[p] != 0) {
            int temp_in = temp_arr[p];
            res.push_back(temp_in);
            for (int j = p*p; j < (n*n+1); j += p)
                temp_arr[j] = 0;
        }
    }

    char variant='Y';
    cout << "Графическое представление?(Y/n)";
    cin >> variant;

    if (variant == 'Y' || variant == 'y') {
        cout << "Результат: " << endl;
        c = 0;
        for (auto &i : matrix) {
            for (auto &j : i) {
                if (res[c] == j) {
                    cout << setw(len_arr(*max)) << j;
                    c++;
                } else {
                    cout << setw(len_arr(*max)) << "";
                }
            }
            cout << endl;
        }
    } else {
        cout << "Результат: " << endl;
        for (auto &i : res)
            cout << setw(len_arr(n*n)) << i;
        cout << "\n" << endl;
    }

    return 0;
    return app.exec();
}
