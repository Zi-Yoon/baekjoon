#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
vector<string> vec;

bool cmp(string a, string b)
{
	if (a.length() == b.length())
		return a < b;
	return a.length() < b.length();
}

int main()
{
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		string str;
		cin >> str;
		// 중복제거
		if (find(vec.begin(), vec.end(), str) == vec.end())
			vec.push_back(str);
	}
	sort(vec.begin(), vec.end(), cmp);
	for (int i = 0; i < vec.size(); i++)
		cout << vec[i] << '\n';
	return 0;
}