#include <stdio.h>
#include <stdbool.h>

#define N 6

bool kiemTra(int A[N][N], int hang, int cot) {
    int i, j;
	// Ngang, trai
    for (i = 0; i < cot; i++)
        if (A[hang][i] == 1)
            return false;
	//Cheo, trai tren
    for (i = hang, j = cot; i >= 0 && j >= 0; i--, j--)
        if (A[i][j])
            return false;
	//Cheo, trai duoi
    for (i = hang, j = cot; j >= 0 && i < N; i++, j--)
        if (A[i][j])
            return false;

    return true;
}

bool datQuanHau(int A[N][N], int cot) {
    if (cot >= N)
        return true;

    for (int i = 0; i < N; i++) {
        if (kiemTra(A, i, cot)) {
            A[i][cot] = 1;

            if (datQuanHau(A, cot + 1))
                return true;

            A[i][cot] = 0;
        }
    }

    return false;
}

void inKQ(int A[N][N]) {
    for (int i = 0; i < N; i++) {
        for (int j = 0; j < N; j++)
            printf("%d ", A[i][j]);
        printf("\n");
    }
}

int main() {
    int A[N][N] = {0};

    if (datQuanHau(A, 0) == false) {
        printf("Khong co giai phap ton tai");
        return false;
    }

    inKQ(A);
    return 0;
}

