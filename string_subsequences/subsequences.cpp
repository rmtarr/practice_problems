#include <iostream>


/* Given two strings, determine the number of times the first appears as subsequence in the second

    Input:
    s1 = "ABC"
    s2 = "ABCBABC"

    Output:
    5

    Explanation:
    s1 appears in s2 5 times at positions {(0,1,2), (0,2,6), (0,3,6), (0,5,6), (4,5,6)}

*/

int count = 0;

int getSubsequenceCount(std::string s1, std::string s2)
{
    // BASE CASE
    if (s1.empty()) return ++count;
    if (s2.empty()) return count;
    
    for (int i = 0; i < s2.length(); i++)
    {
        if (s1[0] == s2[i])
        {
            count = getSubsequenceCount(s1.substr(1), s2.substr(i+1));
        }
    }
    return count;
}

int main(void)
{
    std::cout << getSubsequenceCount(std::string("ABC"), std::string("ABCBABC")) << std::endl;

    return 0;
}
