#include<iostream>
#include <cmath>
using namespace std;
void zadanie(int x, int y, int n, int m)
{
	int max_x;
	int max_y;
	double max_d = 0.0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			double d = sqrt(pow(x - i, 2) + (y - j, 2));
			if (d > max_d)
			{
				max_d = d;
				max_x = i;
				max_y = j;
			}
		}
	}
	cout << "\nDruga figura k najbardziej od niej oddalona jest na pozycji:(" << max_x << "," << max_y << ")\n";
}
int main()
{
	int x = 4;
	int y = 5;
	int N, M;
	cout << "Liczba wierszy: ";
	cin >> N;
	cout << "Liczba kolumn: ";
	cin >> M;
	int** tab2 = new int* [N];
	for (int i = 0; i < N; i++)
	{
		tab2[i] = new int[M];
	}
	zadanie(x, y, N, M);
	return 0;
}