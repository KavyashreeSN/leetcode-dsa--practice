/*126. Word Ladder ||

A transformation sequence from word beginWord to word endWord using a dictionary wordList is a sequence of words beginWord -> s1 -> s2 -> ... -> sk such that:

Every adjacent pair of words differs by a single letter.
Every si for 1 <= i <= k is in wordList. Note that beginWord does not need to be in wordList.
sk == endWord
Given two words, beginWord and endWord, and a dictionary wordList, return all the shortest transformation sequences from beginWord to endWord, or an empty list if no such sequence exists. Each sequence should be returned as a list of the words [beginWord, s1, s2, ..., sk].

 */


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:

    vector<vector<string>> ans;

    void dfs(string word,
             string beginWord,
             unordered_map<string, vector<string>>& parent,
             vector<string>& path) {

        if (word == beginWord) {
            vector<string> temp = path;

            reverse(temp.begin(), temp.end());

            ans.push_back(temp);

            return;
        }

        for (string p : parent[word]) {

            path.push_back(p);

            dfs(p, beginWord, parent, path);

            path.pop_back();
        }
    }

    vector<vector<string>> findLadders(string beginWord,
                                        string endWord,
                                        vector<string>& wordList) {

        unordered_set<string> st(wordList.begin(), wordList.end());

        if (st.find(endWord) == st.end())
            return {};

        unordered_map<string, vector<string>> parent;

        queue<string> q;

        q.push(beginWord);

        st.erase(beginWord);

        bool found = false;

        while (!q.empty() && !found) {

            int n = q.size();

            unordered_set<string> usedThisLevel;

            for (int k = 0; k < n; k++) {

                string word = q.front();
                q.pop();

                string temp = word;

                for (int i = 0; i < temp.size(); i++) {

                    char original = temp[i];

                    for (char c = 'a'; c <= 'z'; c++) {

                        if (c == original)
                            continue;

                        temp[i] = c;

                        if (st.find(temp) != st.end()) {

                            if (usedThisLevel.find(temp) ==
                                usedThisLevel.end()) {

                                q.push(temp);

                                usedThisLevel.insert(temp);
                            }

                            parent[temp].push_back(word);

                            if (temp == endWord)
                                found = true;
                        }
                    }

                    temp[i] = original;
                }
            }

            // Remove words only after completing the level
            for (string word : usedThisLevel) {
                st.erase(word);
            }
        }

        if (!found)
            return {};

        vector<string> path;

        path.push_back(endWord);

        dfs(endWord, beginWord, parent, path);

        return ans;
    }
};


int main() {

    Solution obj;

    string beginWord = "hit";
    string endWord = "cog";

    vector<string> wordList = {
        "hot",
        "dot",
        "dog",
        "lot",
        "log",
        "cog"
    };

    vector<vector<string>> result =
        obj.findLadders(beginWord, endWord, wordList);

    for (auto path : result) {

        for (auto word : path) {
            cout << word << " ";
        }

        cout << endl;
    }

    return 0;
}