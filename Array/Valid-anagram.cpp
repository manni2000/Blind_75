#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
//     bool isAnagram(string s, string t) {
    
//       if(s.length()!=t.length()){
//            return false;
//        } 
//       sort(s.begin(),s.end());
//       sort(t.begin(),t.end());
//        if(s==t){
//            return true;
//        }
//        return false;
//     }
// };

//TC-O(nlogn)
//SC-O(1)

bool isAnagram(string s, string t){
    if(s.length()!=t.length()){
        return false;
    }

    int arr[26] = {0};
    for(int i=0;i<s.length();i++){
        arr[s[i]-'a']++;
        arr[t[i]-'a']--;
    }

 for(int i=0;i<26;i++){
     if(arr[i]>0){
         return false;
     }
  }
  return true;
 }
};

int main(){
    string s,t;
    cin>>s>>t;

    Solution obj;
    bool result = obj.isAnagram(s,t);
    cout << result;
    return 0;  
}

//TC-O(n)
//SC-O(1)

