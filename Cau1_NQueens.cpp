#include<iostream>
using namespace std;

#define N 8

void inKQ(int a[][N]) //3. In kq trong mang 2 chieu voi 2 so 0 va 1
{
	for(size_t i = 0; i < N; i++)
	{
		for(size_t j = 0; i < N; j++)
		{
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

bool kiemTra(int a[][N], int cot) //2. Sau khi dat quan hau thi kiem tra theo 3 huong
{
	//kiem tra theo duong ngang
	int i,j;
	for(int i=0; i<cot; i++)
	{
		if(a[hang][i] == 1)
		{
			return false;
		}
	}
	//cheo, trai tren
	i = hang; j = cot;
	while(i >= 0 && j >= 0 )
	{
		if(a[i][j] == 1)
		{
			return false; //ko dat duoc hau
		}
		i--;
		j--;
	}
	//cheo, trai duoi
	i = hang; j = cot;
	while(i < N && j >= 0 )
	{
		if(a[i][j] == 1)
		{
			return false; //ko dat duoc hau
		}
		i++;
		j++;
	}
	return true;
}

bool datQuanHau(int b[][N], int cot)  //1.dung de dat quan hau
{
	if(cot >= N)
	{
		return true;
	}
	for (size_t i = 0; i < length; i++)
	{
		if(kiemTra(a, i, cot))
		{
			a[i][cot] = 1; //dat hau
			if(datQuanHau(a, cot + 1))
			{
				return true;
			}
			a[i][cot] = 0 //lui lai
		}
	}
	return false;
}

int main()
{
	int a[N][N];
	
	for(size_t i = 0; i < N; i++)
	{
		for(size_t j = 0; i < N; j++)
		{
			a[i][j] = 0;
		} 
	}
	
	if(kiemTra(a, 0))
	{
		inKQ(a);
	}
	else
	{
		cout << "Ko tim thay" <<end;
	}
	
	return 0;
}
