#include <iostream>
using namespace std;

int main()
{
	int a, i; // a = ilość liczb rzeczywistych podanych przez użytkownika
	float num[100], suma = 0.0, average;
	
	cout << "Wpisz ilość liczb rzeczywistych, pamiętaj że nie może ona być" << endl; 
	cout << "ujemna ";
	cin >> a;
	while (a>100 || a <= 0)
	{
		cout << "ERROR" << '\n';
		return 0;	
	}
	for(i=0;i<a;++i)
	{
		cout << i + 1 << ". Wpisz liczbe rzeczywistą: ";
		cin >> num[i];
		suma = suma + num[i];
	}  
	average = suma / a;
	cout << "średnia arytmetyczna liczb = " << average << '\n';
	return 0;
}
