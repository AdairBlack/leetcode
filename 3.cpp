class Solution
{
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> posMap;
        int result = 0;
        int preP = 0, postP = 0;
        for (auto c : s)
        {
            ++postP;
            if (posMap.find(c) != posMap.end())
            {
                result = max(result, postP - preP - 1);
                preP = posMap[c] + 1;
                vector<char> removeVec;
                for (auto itemPosMap : posMap)
                {
                    if (itemPosMap.second <= posMap[c])
                    {
                        removeVec.push_back(itemPosMap.first);
                    }
                }
                for (auto itemRemoveVec : removeVec)
                {
                    posMap.erase(itemRemoveVec);
                }
            }
            else
            {
                result = max(result, postP - preP);
            }
            posMap[c] = postP - 1;
        }

        return result;
    }
};