#include <bits/stdc++.h>
using namespace std;

class Solution
{
public:
    bool isPalindrome(string s)
    {

        int left = 0, right = s.length() - 1;
        while (left < right)
        {
            // Ignore non-alphanumeric characters from the left side
            if (!isalnum(s[left])) // isalnum -> means all characters as well as numbers
                left++;
            // Ignore non-alphanumeric characters from the right side
            else if (!isalnum(s[right]))
                right--;
            // Compare the lowercase characters from both sides
            else if (tolower(s[left]) != tolower(s[right]))
                return false;
            // Move the pointers towards each other
            else
            {
                left++;
                right--;
            }
        }
        // If the loop completes without returning false, it is a palindrome
        return true;
    }
};

int main()
{
    string s = "A man, a plan, a canal: Panama";

    Solution obj;
    int result = obj.isPalindrome(s);

    if (result)
    {
        std::cout << s << " is Palindrome string";
    }
    else
    {
        std::cout << s << " is not Palindrome string";
    }
    return 0;
}

// TC-O(n)
// SC-O(1)