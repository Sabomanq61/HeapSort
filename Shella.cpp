// Shella.cpp: определяет точку входа для консольного приложения.
//

#include <iostream>
#include <ctime>
using namespace std;
void Print(int *a, int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << ' ';
	cout << endl;
}

void Change(int *a, int n, int i)
{
	for (int j = 2 * i + 1; j < n; i = j, i = j,j = 2*i+1)
	{
		if (j + 1 < n)
			if (a[j] < a[j + 1])
				j++;
		if (a[i] < a[j])
		{
			swap(a[i], a[j]);
		}
		else
		{
			break;
		}
	}
}

void CreateHeap(int *a, int n)
{
	int i = n / 2 - 1;

	for (int i = n / 2 - 1; i >= 0; i--)
	{
		Change(a, n, i);
	}
}

int main()
{
	srand(time(0));

	int n;
	cout << "Size = ";
	cin >> n;

	int *a = new int[n];

	for (int i = 0; i < n; i++)
		a[i] = rand() % 20 + 1;

	Print(a, n);
	
	
	for (int i = n; i > 0; i--)
	{
		CreateHeap(a, i);
		swap(a[0], a[i - 1]);
	}
	
	Print(a, n);

	system("pause");
    return 0;
}

