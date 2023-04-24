class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(g.begin(), g.end());
        sort(s.begin(), s.end());
        auto i = g.begin();
        auto j = s.begin();
        int result = 0;
        while(i != g.end() && j != s.end())
        {
            if(*i <= *j)
            {
                result++;
                i++;
            }
            j++;
        }
        return result;
    }
};