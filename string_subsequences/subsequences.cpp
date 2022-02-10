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

void getSubsequenceCountHelper(std::string s1, std::string s2, int &count)
{
    // BASE CASE
    if (s1.empty()) ++count;
    if (s2.empty()) return;
    
    for (int i = 0; i < s2.length(); i++)
    {
        if (s1[0] == s2[i])
        {
            getSubsequenceCountHelper(s1.substr(1), s2.substr(i+1), count);
        }
    }
}

int getSubsequenceCount(std::string s1, std::string s2)
{
    int count = 0;
    getSubsequenceCountHelper(s1, s2, count);
    return count;
}

int main(void)
{
    std::cout << getSubsequenceCount(std::string("ABC"), std::string("ABBABC")) << std::endl;

    return 0;
}
