// https://leetcode.com/problems/find-all-anagrams-in-a-string/
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <list>

using namespace std;

class Solution {
public:
	vector<int> findAnagrams(string s, string p) {
		vector<int> res;
		vector <int> cnt1(26), cnt2(26);
		for (int i = 0; i < p.size(); i++)cnt1[p[i] - 'a']++;
		int j = 0;
		int required = p.size();
		for (int i = 0; i < s.size(); i++){
			char x = s[i];
			cnt2[x - 'a']++;
			if (cnt1[x - 'a'] && cnt2[x - 'a'] <= cnt1[x - 'a']) required--;
			while (j <= i && cnt2[s[j] - 'a'] - 1 >= cnt1[s[j] - 'a']){
				cnt2[s[j] - 'a']--;
				j++;
			}
			if (i - j + 1 == p.size() && required == 0){
				res.push_back(j);
			}
		}
		return res;
	}
};

int main() {
	vector<string> s1 = { "cbaebabacd", "abab" };
	vector<string> s2 = { "abc", "ab" };
	Solution s;

	for (int i = 0; i < s1.size(); i++)
	{
		auto res = s.findAnagrams(s1[i], s2[i]);
		cout << "--------------" << endl;
		cout << "Output [" << s1[i].c_str() << ", " << s2[i].c_str() << "]" << endl;
		for (const auto a : res)
		{
			cout << a;
		}
	}
	getchar();
	return 0;
}