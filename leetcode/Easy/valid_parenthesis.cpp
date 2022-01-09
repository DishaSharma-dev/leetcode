class Solution
{
public:
    bool isValid(string s)
    {
        if (!s.length() % 2)
            return false;
        stack<char> stk;
        vector<char> v{'[', ']', '(', ')', '{', '}'};
        for (int i = 0; i < s.length(); i++)
        {
            if (size(stk))
            {
                if ((stk.top() == v[0] and s[i] == v[1]) or (stk.top() == v[2] and s[i] == v[3]) or (stk.top() == v[4] and s[i] == v[5]))
                {
                    stk.pop();
                }
                else
                    stk.push(s[i]);
            }
            else
                stk.push(s[i]);
        }
        return !size(stk);
    }
};