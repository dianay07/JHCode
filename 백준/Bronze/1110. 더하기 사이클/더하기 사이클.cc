#include <iostream>
using namespace std;

int main() 
{
	int n;
	int count = 0;
	int num, temp;
	
    cin >> n;
	num = n;

	while (true)
    {
		temp = (n % 10) * 10 + (n / 10 + n % 10) % 10;
		count++;
       n = temp;
        
		if (temp == num)
			break;
	}
    
	cout << count;
}