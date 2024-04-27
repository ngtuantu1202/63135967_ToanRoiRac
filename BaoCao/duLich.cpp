#include <stdio.h>
#include <limits.h>

#define N 4

int ChiPhi[N][N];
int minChiPhi = INT_MAX;

void doiCho(int *x, int *y) {
    int tam = *x;
    *x = *y;
    *y = tam;
}

int tinhChiPhi(int hanhTrinh[]) {
    int chiPhi = 0;
    for (int i = 0; i < N - 1; i++) {
        chiPhi += ChiPhi[hanhTrinh[i]][hanhTrinh[i + 1]];
    }
    chiPhi += ChiPhi[hanhTrinh[N - 1]][hanhTrinh[0]];
    return chiPhi;
}

void lietKe(int hanhTrinh[], int muc) {
    if (muc == N - 1) {
        int chiPhi = tinhChiPhi(hanhTrinh);
        if (chiPhi < minChiPhi)
            minChiPhi = chiPhi;
        return;
    }

    for (int i = muc; i < N; i++) {
        doiCho(&hanhTrinh[muc], &hanhTrinh[i]);
        lietKe(hanhTrinh, muc + 1);
        doiCho(&hanhTrinh[muc], &hanhTrinh[i]);
    }
}

int main() {
    printf("Nhap ma tran chi phi:\n");
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++) {
            printf("Chi phi tu diem %d den diem %d: ", i + 1, j + 1);
            scanf("%d", &ChiPhi[i][j]);
        }
    }

    int hanhTrinh[N];
    for (int i = 0; i < N; i++) {
        hanhTrinh[i] = i;
    }

    lietKe(hanhTrinh, 0);

    printf("Chi phi nho nhat la: %d\n", minChiPhi);

    return 0;
}

