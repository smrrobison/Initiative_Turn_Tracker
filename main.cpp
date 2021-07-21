#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
#include <utility>
using namespace std;

bool sortbysec(const pair<string,int> &a,
              const pair<string,int> &b)
{
    return (a.second > b.second);
}

int main()
{
	vector<pair<string, int>> characters;
	cout << "Type in character names, followed by their initiative roll" << endl;
	string name;
	int roll;	
	char playerChoice;
	//Outside main loop
	bool keepGoing = true;
	while (keepGoing)
	{
		string name = " ";
		while (name != "q")
		{
			cout << "Player Name: " << endl;
			cin >> name;
			if (name == "q")
				break;
			cout << "Initiative Roll  Value: " << endl;
			cin >> roll;
			pair<string, int> character(name, roll);
			characters.push_back(character);
		}
		cout << endl << endl;
		cout << "Player Order" << endl;
		sort(characters.begin(), characters.end(), sortbysec);
		for_each(characters.begin(), characters.end(), [](const pair<string, int> &var) {cout << var.first << endl; });
		characters.clear();
		cout << endl;
		cout << "Continue?" << endl;
		cout << "Press any key to continue or press\"q\" to quit." << endl;
		cin >> playerChoice;
		if (playerChoice == 'q')
			keepGoing = false;
	}
	return 0;
}