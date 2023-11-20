#include <iostream>
using namespace std;

struct Chunk
{
	int repeatNum = 0;
	string text = "";
};

int main()
{	
	int a;
	cin >> a;

	Chunk* ChunkArray = new Chunk[a];

	for (int i = 0; i < a; i++)
	{
		cin >> ChunkArray[i].repeatNum;
		cin >> ChunkArray[i].text;
	}

	for (int i = 0; i < a; i++)
	{
		for (int j = 0; j < ChunkArray[i].text.size(); j++)
		{
			for (int k = 0; k < ChunkArray[i].repeatNum; k++)
			{
				cout << ChunkArray[i].text[j];
			}
		}
		cout << endl;
	}
}