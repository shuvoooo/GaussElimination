#include <iostream>

using namespace std;

int main() {
    int i, j, k, n;

    float a[11][11], b, x[11];

    cout << "\nEnter number of unknown’s variables:";
    cin >> n;

    if (n > 10) {
        cout << "Unknown variable number maximum 10";
        exit(0);
    }

    for (i = 1; i <= n; i++) {
        for (j = 1; j <= (n + 1); j++) {
            cout << "A[" << i << "][" << j << "] = ";
            cin >> a[i][j];
        }
    }

    for (j = 1; j <= n; j++) {
        for (i = 1; i <= n; i++) {
            if (i != j) {
                b = a[i][j] / a[j][j];
                for (k = 1; k <= n + 1; k++) {
                    a[i][k] = a[i][k] - b * a[j][k];
                }
            }
        }
    }

    cout << "\nSolution of the Systems: \n";

    for (i = 1; i <= n; i++) {
        x[i] = a[i][n + 1] / a[i][i];
        printf("%c = %f\n", (90 - n) + i, x[i]);
    }

    return 0;
}
