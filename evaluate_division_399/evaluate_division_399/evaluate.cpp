#include <iostream>
#include <vector>
#include <unordered_map>
#include <set>
#include <unordered_set>
using namespace std; 


unordered_map<string, unordered_map<string, double>> buildGraph(
	const vector<vector<string>>& equations, 
	const vector<double>& values
)
{
	unordered_map<string, unordered_map<string, double>>gr; 

	for (int i = 0; i < equations.size(); i++)
	{
		string dividend = equations[i][0]; 
		string divisor = equations[i][1]; 
		gr[dividend][divisor] = values[i]; 
		gr[divisor][dividend] = 1 / values[i]; 
	}
	return gr; 
}

void dfs(
	string node,
	string& dest,
	unordered_map<string, unordered_map<string, double>>& gr,
	set<string>& vis,
	double& ans,
	double temp
)
{
	if (vis.find(node) != vis.end()) return;

	vis.insert(node); 

	if (node == dest)
	{
		ans = temp; 
		return; 
	}

	for (auto ne : gr[node])
		dfs(ne.first, dest, gr, vis, ans, temp * ne.second); 
}


vector<double> calcEquation(
	vector<vector<string>>& equations,
	vector<double>& values,
	vector<vector<string>>& queries
) {
	unordered_map<string, unordered_map<string, double>> gr = buildGraph(equations, values);
	vector<double> finalAns;

	for (auto query : queries) {
		string dividend = query[0];  // �d�ߪ����l
		string divisor = query[1];   // �d�ߪ�����

		// �d�ߨ���ܼƬO�_�s�b��Ϥ�
		if (gr.find(dividend) == gr.end() || gr.find(divisor) == gr.end()) {
			finalAns.push_back(-1.0);  // �ܼƤ��s�b�A��^ -1.0
		}
		else {
			set<string> vis;  // �O���X�ݪ��A�A�קK�`��
			double ans = -1, temp = 1.0;
			dfs(dividend, divisor, gr, vis, ans, temp);
			finalAns.push_back(ans);  // �[�J�d�ߵ��G
		}
	}

	return finalAns;
}

int main()
{
	vector<vector<string>> equations = { {"a", "b"},{"b", "c"} };
	vector<double>values = { 2.0, 3.0 };
	vector < vector<string>>queries = { {"a", "c"},{"b", "a"},{"a", "e"},{"a", "a"},{"x", "x"} };
	vector<double>temp = calcEquation(equations, values, queries);
	for (auto i : temp)
		cout << i << " "; 

}
