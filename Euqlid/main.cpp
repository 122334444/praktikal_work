#include <QCoreApplication>
#include <iostream>

using namespace std;

int main(int argc, char *argv[])
{
    QCoreApplication app(argc, argv);

    setlocale(0, "Russia");

    int a;
    int b;
    cout << "Введите B ";
    cin >> a;
    cout << "Введите B ";
    cin >> b;

    auto check = [](int i, string name) {
        if (i < 1) { cout << "Ошибка " << name << " < 1"; return 1; }
    };

    if ((check(a, "a") == 1) or (check(b, "b") == 1) ) return 0;

    while (a != b)
        if (a > b)
            a = a - b;
        else
            b = b - a;

    cout << "A : " << a << endl;
    cout << "B : " << b << endl;

    return 0;
    return app.exec();
}
