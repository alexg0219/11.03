#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int sizei, sizej;
    cin >> sizei >> sizej;
    vector<vector<char>> a(sizei, vector<char>(sizej));

    for (int i = 0; i < sizei; i++)
        for (int j = 0; j < sizej; j++)
            cin >> a[i][j];

    int mini = sizei;
    int maxi = -1;
    int minj = sizej;
    int maxj = -1;

    for (int i = 0; i < sizei; i++)
        for (int j = 0; j < sizej; j++)
            if (a[i][j] == '*')
            {
                mini = min(mini, i);
                maxi = max(maxi, i);
                minj = min(minj, i);
                maxj = max(maxj, i);
            }

    for (int i = mini - 1; i < mini+2; i++)
        for (int j = maxi - 1; j < maxi+2 ; j++)
            for (int v = minj - 1; v < minj + 2; v++)
                for (int b = maxj - 1; b < maxj + 2; b++)
                    if (j - i == b - v && j - i >= 2 && 0 <= i && j <= sizei && 0 <= v && b <= sizej)
                    {
                        bool bFlag = 1;
                        for (int c = i + 1; c < j - 2 && bFlag; c++)
                            for (int d = v + 1; d < b - 2 && bFlag; d++)
                                if (a[c][d] != '*')
                                    bFlag = 0;
                        if (bFlag)
                        {
                            cout << "SQUARE";
                            return 0;
                        }
                    }

    cout << "CIRCLE";
}
