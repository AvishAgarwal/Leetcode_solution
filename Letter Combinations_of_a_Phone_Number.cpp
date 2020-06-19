C++ code for leetcode
17. Letter Combinations of a Phone Number

Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent.
A mapping of digit to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

Example:
Input: "23"
Output: ["ad", "ae", "af", "bd", "be", "bf", "cd", "ce", "cf"].
Note:
Although the above answer is in lexicographical order, your answer could be in any order you want.
My code:
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Letter Combinations of a Phone Number.
Memory Usage: 6.6 MB, less than 54.09% of C++ online submissions for Letter Combinations of a Phone Number.

class Solution {
public:
    vector<string> letterCombinations(string digits) {
        string table[]={"","","abc","def","ghi","jkl","mno","pqrs","tuv","wxyz"};
        int n= digits.length();
        if(n==0)
            return {};
        int d[n];
        for(int i=0;i<n;i++)
        {
            d[i]= digits[i]-'0';
        }
        queue<string> q;
        vector<string> res;
        q.push("");
        while(!q.empty())
        {
            string s=q.front();
            q.pop();
            if(s.length()==n)
                res.push_back(s);
            else
                for(auto letter : table[d[s.length()]] )
                    q.push(s+letter);
        }
        return res;
    }
};
