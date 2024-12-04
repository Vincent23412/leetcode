#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <set>
using namespace std; 


bool closeStrings(string word1, string word2) {

	unordered_map<char, int> a; 
	unordered_map<char, int> b; 

	for (auto& i : word1)
		a[i]++; 

	for (auto& i : word2)
		b[i]++; 

	vector<int>count_a; 
	vector<int>count_b; 
	set<char>char_a; 
	set<char>char_b; 

	for (auto& i : a)
	{
		count_a.push_back(i.second);
		char_a.insert(i.first); 
	}

	for (auto& i : b)
	{
		count_b.push_back(i.second);
		char_b.insert(i.first); 
	}

	vector<char>a_1(char_a.begin(), char_a.end());
	vector<char>b_1(char_b.begin(), char_b.end()); 

	


	sort(count_a.begin(), count_a.end()); 
	sort(count_b.begin(), count_b.end()); 
	sort(a_1.begin(), a_1.end()); 
	sort(b_1.begin(), b_1.end());

	for (auto i : a_1)
		cout << i << " "; 

	if (a_1.size() != b_1.size()) return false;

	for (int i = 0; i < a_1.size(); i++)
	{
		if (a_1[i] != b_1[i]) return false;

	}


	if (count_a.size() != count_b.size()) return false; 

	for (int i = 0; i < count_a.size(); i++)
		if (count_a[i] != count_b[i]) return false;

	return true; 

}

int main()
{
	string word1 = "uau"; 
	string word2 = "ssx"; 
	cout << closeStrings(word1, word2); 


}