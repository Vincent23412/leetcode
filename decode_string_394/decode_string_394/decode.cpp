#include <iostream>
#include <stack>
#include <string>
using namespace std; 

string decodeString(string s) {
	stack<int>counts; 
	stack<string>results; 
	string currentString = ""; 
	int num = 0; 

	for (char c : s)
	{
		if (isdigit(c))
			num = num * 10 + (c - '0'); 
		else if (c == '[')
		{
			counts.push(num); 
			results.push(currentString); 
			num = 0; 
			currentString = ""; 
		}
		else if (c == ']')
		{
			int repeatCount = counts.top(); 
			counts.pop(); 
			string temp = currentString; 
			for (int i = 1; i < repeatCount; ++i)
			{
				currentString += temp; 
			}

			currentString = results.top() + currentString; 
			results.pop(); 
		}
		else {
			currentString += c; 
		}
			 
	}

	return currentString; 
		
	
}

int main()
{
	string s = "3[a]2[bc]"; 
	string ans = decodeString(s); 
	for (auto i : ans)
		cout << i << " "; 

}