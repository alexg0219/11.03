#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, m;

    cin >> n;
    m = n + 1;
    vector<vector<double>> arr(n, vector<double>(m));

    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++)
            cin >> arr[i][j];

    double  tmp;
    vector <double> x(m);

    for (int i = 0; i < n; i++)
    {
        tmp = arr[i][i];
        for (int j = n; j >= i; j--)
            arr[i][j] /= tmp;
        for (int j = i + 1; j < n; j++)
        {
            tmp = arr[j][i];
            for (int k = n; k >= i; k--)
                arr[j][k] -= tmp * arr[i][k];
        }
    }

    x[n - 1] = arr[n - 1][n];
    for (int i = n - 2; i >= 0; i--)
    {
        x[i] = arr[i][n];
        for (int j = i + 1; j < n; j++) x[i] -= arr[i][j] * x[j];
    }


    for (int i = 0; i < n; i++)
        cout << x[i] << " ";
    cout << endl;
}