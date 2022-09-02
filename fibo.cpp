#include <iostream>
using namespace std;

int fib (int n)
{
	if (n ==1)
		return 0;
	else if (n==2)
		return 1;
	else
		return fib(n-2) + fib (n-1);
}

int main()
{
	int n,aux;
    int ult = 1, pen = 1, prox;

	cin >> n;
	
    while (aux > 0) 
    {
        prox = ult + pen;
        ult = pen;
        pen = prox;
        aux--;
        cout << prox << " ";
    }

    return 0;
}
