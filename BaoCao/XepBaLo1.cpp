#include <stdio.h>

int timMAX(int a, int b) {
    if (a > b) {
        return a;
    } else {
        return b;
    }
}

int xepBaLo(int W, int trongLuong[], int giaTri[], int n) {
    int i, w;
    int K[n + 1][W + 1];

    for (i = 0; i <= n; i++) {
        for (w = 0; w <= W; w++) {
            if (i == 0 || w == 0)
                K[i][w] = 0;
            else if (trongLuong[i - 1] <= w)
                K[i][w] = timMAX(giaTri[i - 1] + K[i - 1]
				[w - trongLuong[i - 1]], K[i - 1][w]);
            else
                K[i][w] = K[i - 1][w];
        }
    }

    return K[n][W];
}

int main() {
    int n, W;
    printf("Nhap so luong vat: ");
    scanf("%d", &n);
    printf("Nhap trong luong toi da cua ba lo: ");
    scanf("%d", &W);
	printf("\n");
    int giaTri[n];
    int trongLuong[n];

    for (int i = 0; i < n; i++) {
        printf("Nhap gia tri cua vat thu %d: ", i + 1);
        scanf("%d", &giaTri[i]);
        printf("Nhap trong luong cua vat thu %d: ", i + 1);
        scanf("%d", &trongLuong[i]);
        printf("\n");
    }

    printf("Tong gia tri lon nhat co the xep vao ba lo: %d\n", 
	xepBaLo(W, trongLuong, giaTri, n));
    return 0;
}

