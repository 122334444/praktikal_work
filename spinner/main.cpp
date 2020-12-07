#include <iostream>

using namespace std;
int DEBUG = false;
//int DEBUG = true;

int factorial(int i) {
    if (i==0) return 1;
    else return (i-1 == 0) ? i : i+factorial(i-1);
}

void sp() {
    double a, b, c;
    cout << "Стоимость основания спиннера\t= ";
    cin >> a;
    cout << "Стоимость одной лопасти\t\t= ";
    cin >> b;
    cout << "Максимальная стоимость спиннера\t= ";
    cin >> c;
    if (DEBUG) cout << endl;
    if (DEBUG) cout << ( (int) (c - a) / (int) b ) << endl;
    if (DEBUG) cout << ( ( (int) (c - a) / (int) b ) * b ) << endl;
    cout << endl;
    if (a > c)
        cout << "Спиннер с " << ( (int) (c - a) / (int) b ) << " лопастями будет стоить " << ( ( (int) (c - a) / (int) b ) * b ) + a << " рублей." << endl;
    else
        cout << "Стоимость основания больше максимальной стоимости.";
    cout << endl;
}

void ssp() {
    int m, tripple = 0, quadro = 0, count_cicles = 20;
    cout << "Количество лопастей M\t= ";
    cin >> m;
    if (DEBUG) cout << endl;
//    if (DEBUG) cout <<  << endl;
    if (DEBUG) cout << (int) ( m * 0.5 ) << endl;
    if (DEBUG) cout << m % 3 << endl;
    if (DEBUG) cout << m % 4 << endl;
    cout << endl;
    if (m < 3)
        cout << "Невозможно купить спиннер" << endl;
    else {
        if (m > 5) {
            if ( (m - 3) % 7 == 0 ) {
                tripple++;
            }
            if ( (m - 4) % 7 == 0 ) {
                quadro++;
            }
            if ( (m - 5) % 7 == 0 ) {
                quadro++;
                quadro++;
                quadro++;
            }
            if ( (m - 6) % 7 == 0 ) {
                tripple++;
                tripple++;
            }
            if ( (m - 8) % 7 == 0 ) {
                quadro++;
                quadro++;
            }
            if ( (m - 9) % 7 == 0 ) {
                tripple++;
                tripple++;
                tripple++;
            }
            if (DEBUG) cout << tripple << " : " << quadro << endl;
            while (true) {
                if (m == tripple*3 + quadro*4) break; else tripple++;
                if (m == tripple*3 + quadro*4) break; else quadro++;

                if (DEBUG) cout << tripple << " : " << quadro << endl;
                if (DEBUG)
                    if (count_cicles == 0)
                        break;
                    else
                        count_cicles--;
            }
        } else
            if (m > 2)
                if (m > 3)
                    quadro++;
                else
                    tripple++;
            else
                cout << "Маленькое количество лопастей." << endl;
        cout << "3-лопастных спиннеров\t= " << tripple << endl;
        cout << "4-лопастных спиннеров\t= " << quadro << endl;
    }
    cout << endl;
}

void nsp() {
    int n, m, c = 0;
    cout << "Длина листа N\t= ";
    cin >> n;
    cout << "Ширина листа M\t= ";
    cin >> m;
    if (DEBUG) cout << endl;
    for (int i=1; i<=m; i++) {
        c += factorial(n) * i;
        if (DEBUG) cout << i << " : " << factorial(n) * i << endl;
    }
    cout << endl;
    cout << "Количество возможных прямоугольников из листа " << n << " x " << m << " = " << c << endl;
}

int main(int argc, char *argv[]) {
    int vibor;
    cout << "Номер задания про спиннеры : ";
    cin >> vibor;
    switch (vibor) {
    case 1: {
        sp();
        break;
    }
    case 2: {
        ssp();
        break;
    }
    case 3: {
        nsp();
        break;
    }
    default: {
        cout << "Нужно выбрать задание со спиннерами." << endl;
        cout << endl;
        break;
    }
    }

    return 0;
}
