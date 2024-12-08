#include <iostream>
#include <queue>

using namespace std; 

string predictPartyVictory(string senate) {
	queue<int>r; 
	queue<int>d; 
	int length = senate.length(); 
	for (int i = 0; i < length; i++)
		(senate[i] == 'R') ? r.push(i) : d.push(i); 
	while (!r.empty() && !d.empty())
	{
		int x = r.front(); 
		int y = d.front(); 
		r.pop(); 
		d.pop(); 
		if (x < y)
			r.push(length + x);
		else
			d.push(length + y); 
	}

	if (!r.empty())
		return "Radiant";
	else
		return "Dire"; 
}

int main()
{
	string senate = "RD"; 
	string ans = predictPartyVictory(senate); 
	for (auto i : ans)
		cout << i; 
}