// link https://leetcode.com/problems/unique-number-of-occurrences/solutions/4583579/set-map-code-explained/?envType=study-plan-v2&envId=leetcode-75
#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std; 

bool uniqueOccurrences(vector<int>& arr) {
	unordered_map< int, int> freq;
	
	for (int& x : arr) {// store frequencies of numbers in map 
		freq[x]++;
	}

    unordered_set<int>st;
    for (auto& it : freq) {
        int freq = it.second; 
        if (st.find(freq) != st.end()) {
            return false;
        }
        st.insert(freq);
    return true;
}
int main()
{
	vector<int>arr = { 1,2,2,1,1,3 }; 
	cout << uniqueOccurrences(arr); 

}