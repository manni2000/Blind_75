#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
       vector<vector<string>> ans;
       unordered_map<string,vector<string>> umap;

       for(auto s: strs){  // s = eat, tea, tan, ate, nat, bat
          string temp = s; // temp = eat, tea, tan , ate, nat, bat
          sort(s.begin(),s.end()); // after sort -> aet, aet, ant, aet, ant, abt
          umap[s].push_back(temp); // aet -> eat, tea, ate
                                   // ant -> tan, nat
                                   // abt -> bat
       }

       for(auto x: umap){
           ans.push_back(x.second); // ans = [["bat"],["eat", "tea", "aet"],["tan", nat]]
       }
       return ans;                  // map = ans.
    }
};

int main() {
    vector<string> strs = {"eat", "tea", "tan", "ate", "nat", "bat"};

    Solution obj;
    vector<vector<string>> ans = obj.groupAnagrams(strs);
    for (auto group : ans) {
        for (auto word : group) {
            cout << word << " ";
        }
        cout << endl;
    }

    return 0;
}

//TC-O(N*M*log M)
//SC-O(N)