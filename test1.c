#include <stdio.h>

#define N 4

void gaussian_elimination(double a[N][N+1], double x[N]) {
    for (int i = 0; i < N; i++) {
        // 找到主元
        for (int k = i + 1; k < N; k++) {
            if (a[i][i] == 0) {
                printf("無解或有無限多組解。\n");
                return;
            }
            double factor = a[k][i] / a[i][i];
            for (int j = i; j <= N; j++) {
                a[k][j] -= factor * a[i][j];
            }
        }
    }

    // 回代求解
    for (int i = N - 1; i >= 0; i--) {
        x[i] = a[i][N];
        for (int j = i + 1; j < N; j++) {
            x[i] -= a[i][j] * x[j];
        }
        x[i] /= a[i][i];
    }
}

int main() {
    // 初始化擴展矩陣 [A | b]
    double a[N][N+1] = {
        {0.3, -0.2, 0, 0, 3},
        {-0.2, 1.325, -0.125, -1, -3},
        {0, -0.125, 0.5, -0.125, 0},
        {0, -1, -0.125, 1.625, 6}
    };
    double x[N]; // 用於存儲解向量

    gaussian_elimination(a, x);

    // 輸出結果
    printf("解向量 v 為:\n");
    for (int i = 0; i < N; i++) {
        printf("v%d = %f\n", i + 1, x[i]);
    }

    return 0;
}