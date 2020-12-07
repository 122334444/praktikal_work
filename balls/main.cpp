#include <QCoreApplication>
#include <iostream>
#include <vector>
#include <algorithm>
#include <iterator>
#include <iomanip>

using namespace std;

long double factorial(int N)
{
    if(N < 0)
        return 0;
    if (N == 0)
        return 1;
    else
        return N * factorial(N - 1);
}

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    setlocale(0, "Russia");

    int n;
    cout << "Введите количество шариков N ";
    cin >> n;

    vector<vector<int>> arr, res;
    vector<int> a, b;
    cout << "Количество комбинаций: " << factorial(n) << endl;

    for (int i=1; i<=n; i++)
        a.push_back(i);
    b.resize(a.size());

    auto split = [](int n) { string str; str.append("+"); for (int i=0; i<(n*3+2); i++) { str.append("-"); }; str.append("+"); return str; };

    cout << split(n) << endl;
    cout << "| ";
    for (auto &i : a)
        cout << setw(3) << i;
    cout << " |" << endl;
    cout << split(n) << endl;

    do {
        for (auto ite = begin(a); ite != end(a); ++ite)
            if (is_sorted(begin(a), ite))
            {
                arr.resize(arr.size()+1);
                copy(ite, end(a), back_inserter(arr[arr.size()-1]));
            }
    } while (next_permutation(begin(a), end(a)));

    for (int i=0; i<arr.size(); i++) {
        if (arr[i].size() == n)
            res.push_back(arr[i]);
    }

    auto col1 = [](int i) { return to_string(i).length(); };

    cout << endl;

    for (int i=0; i<res.size(); i++) {
        cout << "| " << setw(col1(res.size())) << (i+1) << " | ";
        for (auto &m : res[i]) {
            cout << setw(col1(res.size())) << m;
        }
        cout << " |" << endl;
    }

    cout << endl;

    for (int i=0; i<res.size(); i++) {
        for (int j=0; j<res[i].size(); j++) {
            if ((j+1) == res[i][j]) b[j]++;
        }
    }

    auto split2 = [](int n, int in) { string str; str.append("+"); for (int i=0; i<(n * in * 5 + 2); i++) { str.append("-"); }; str.append("+"); return str; };

    cout << split2(n, col1(n)) << endl;
    cout << "| ";
    for (auto &i : a)
        cout << setw(col1(n)*5) << i;
    cout << " |" << endl;
    cout << split2(n, col1(n)) << endl;
    cout << "| ";
    for (auto &i : b)
        cout << setw(col1(n)*5) << i;
    cout << " |" << endl;
    cout << split2(n, col1(n)) << endl;

    cin.ignore();
    getchar();

    return 0;
    return app.exec();
}
