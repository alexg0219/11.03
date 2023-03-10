#include <iostream>

using namespace std;

int main()
{
    string rock, queen, horse;
    int summ = 0;

    cin >> rock >> queen >> horse;

    int r1 = rock[0] - 64 - 1;
    int r2 = rock[1] - 48 - 1;

    int q1 = queen[0] - 64 - 1;
    int q2 = queen[1] - 48 - 1;

    int h1 = horse[0] - 64 - 1;
    int h2 = horse[1] - 48 - 1;

    int desk[8][8] = { 0 };

    for (int i = 0; i < 8; ++i)
        for (int j = 0; j < 8; ++j) 
        {
            if (abs(r1 - j) == abs(r2 - i))
                desk[i][j] = 1;
            else
                if (r1 == j || r2 == i)
                    desk[i][j] = 1;
                else
                    if (q1 == j || q2 == i)
                        desk[i][j] = 1;
                    else
                        if ((abs(h1 - j) == 1 && abs(h2 - i) == 2) || (abs(h1 - j) == 2 && abs(h2 - i) == 1))
                            desk[i][j] = 1;
        }

    desk[r2][r1] = 0;
    desk[q2][q1] = 0;
    desk[h2][h1] = 0;


    for (int i = 0; i < 8; ++i) {
        for (int j = 0; j < 8; ++j)
            summ += desk[i][j];
    }

    cout << summ;
}
