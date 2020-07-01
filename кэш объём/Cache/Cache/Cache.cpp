#include <iostream>
#include <ctime>
#include <stdio.h>
#include <time.h>
using namespace std;


int main()
{
	int n = 1000000;
	int* arr = new int[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = 2;
	}

	unsigned long start = 0,
		end = 0,
		countJump = 0;

	double time = 0,
		timeCash = 0;

	int var = 0;

	double LengthCash = 0;

	for (int k = 0; k < 100; k++)
	{
		for (int i = 0; i < n; i++)
		{
			start = clock();

			var = arr[i];
			var += 5;
			arr[i] = var;

			end = clock();

			time = (double)(end - start) / CLOCKS_PER_SEC;
			if (timeCash < time)
			{
				countJump++;
			}
			timeCash = time;
		}
		LengthCash += (n / countJump) * 32;
	}
	LengthCash /= 100;


	cout << LengthCash << " bit" << endl;
	cout << LengthCash / 8 << " byte" << endl;
	cout << LengthCash / (1024 * 8) << " kb" << endl;


	system("pause");
	return 0;
}