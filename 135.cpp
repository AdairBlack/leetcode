class Solution
{
public:
    int candy(vector<int> &ratings)
    {
        int result = ratings.size();
        vector<int> candies(result, 1);
        for (int i = 1; i < ratings.size(); i++)
        {
            if (ratings[i] > ratings[i - 1] && candies[i] <= candies[i - 1])
            {
                result += candies[i - 1] + 1 - candies[i];
                candies[i] = candies[i - 1] + 1;
            }
        }
        for (int i = ratings.size() - 2; i >= 0; i--)
        {
            if (ratings[i] > ratings[i + 1] && candies[i] <= candies[i + 1])
            {
                result += candies[i + 1] + 1 - candies[i];
                candies[i] = candies[i + 1] + 1;
            }
        }

        return result;
    }
};