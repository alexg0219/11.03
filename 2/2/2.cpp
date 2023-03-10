#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sizei, sizej;
    int collum = 0;
    int wall = 0;
    cin >> sizei >> sizej;

    vector<vector<int>>a(sizei, vector<int>(sizej));

    for (int i = 0; i < sizei; i++)
        for (int j = 0; j < sizej; j++)
            cin >> a[i][j];

    for (int i = 0; i < sizei - 1; i++)
        for (int j = 0; j < sizej - 1; j++)
            if (!(a[i][j] == a[i + 1][j] && a[i][j] == a[i][j + 1] && a[i][j] == a[i + 1][j + 1]))
                collum += 1;
    
    for (int i = 0; i < sizei - 1; i++)
        for (int j = 0; j < sizej; j++)
            if (a[i][j] != a[i + 1][j])
                wall += 1;

    for (int i = 0; i < sizei; i++)
        for (int j = 0; j < sizej - 1; j++)
            if (a[i][j] != a[i][j + 1])
                wall += 1;

    cout << 0.2 * 0.2 * 3 * collum + 0.2 * 0.8 * 3 * wall;
}