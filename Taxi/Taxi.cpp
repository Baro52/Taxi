#include <iostream>

using namespace std;

struct przedzial
{
	int jedna=0, dwie=0, trzy=0, cztery = 0;
};

int main()
{
	int n;
	cin >> n;
	przedzial osoby;
	int *a = new int[n];
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
		switch (a[i])
		{
		case 1:
			osoby.jedna++;
			break;
		case 2:
			osoby.dwie++;
			break;
		case 3:
			osoby.trzy++;
			break;
		case 4:
			osoby.cztery++;
			break;
		}
	}
	int wynik = 0;
	wynik += osoby.cztery;
	if (osoby.trzy >= osoby.jedna) wynik += osoby.trzy, wynik += osoby.dwie % 2 ? (osoby.dwie + 1) / 2 : osoby.dwie / 2;
	else 
	{
		wynik += osoby.trzy;
		osoby.jedna -= osoby.trzy;
		if (osoby.dwie % 2) osoby.jedna -= 2;
		wynik += osoby.dwie % 2 ? (osoby.dwie + 1) / 2 : osoby.dwie / 2;
		wynik += osoby.jedna % 4 ? (osoby.jedna + 3) / 4 : osoby.jedna / 4;
	}

	cout << wynik;
}