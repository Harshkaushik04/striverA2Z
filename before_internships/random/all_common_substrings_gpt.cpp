#include <bits/stdc++.h>
using namespace std;

void f(int i, int j, string& s1, string& s2, vector<string>& answers, string& current_answer) {
    if (i < 0 || j < 0) return;

    if (s1[i] == s2[j]) {
        current_answer.push_back(s1[i]);
        f(i - 1, j - 1, s1, s2, answers, current_answer);
        if (current_answer.size() >= 3) {
            string temp = current_answer;
            reverse(temp.begin(), temp.end());
            answers.push_back(temp);
        }
        current_answer.pop_back();  // Backtrack
    }

    f(i - 1, j, s1, s2, answers, current_answer);
    f(i, j - 1, s1, s2, answers, current_answer);
}

void all_substrings(string& s, vector<string>& ans) {
    int n = s.size();
    for (int i = 0; i < n; ++i) {
        string curr;
        for (int j = i; j < n; ++j) {
            curr += s[j];
            if (curr.size() >= 3) ans.emplace_back(curr);
        }
    }
}

vector<string> all_common_substrings(string& s1, string& s2) {
    vector<string> answers;
    string current_answer;
    f(s1.size() - 1, s2.size() - 1, s1, s2, answers, current_answer);

    vector<string> ans;
    for (auto& match : answers) {
        all_substrings(match, ans);
    }

    return ans;
}

int main() {
    string s1, s2;
    cin >> s1 >> s2;

    vector<string> vec = all_common_substrings(s1, s2);
    for (const string& s : vec) cout << s << " ";
    return 0;
}
