#include <iostream>
using namespace std;

float media (float  z1, float z2)
{
     float media;
     media = (z1 + z2)/2;
     return media;
}

int main ()
{
	float
	 n1, n2;
	cin >> n1 >> n2;
	cout << media(n1,n2);
	return 0;
}
