//leetcode 1482: minimum number of days to make m bouquets
class Solution
{
public:
    bool canWeMakeMBouquetsWithDDays(vector<int> &bloomDay, int m, int k, int D)
    {
        int counter = 0;
        for (int i = 0; i < bloomDay.size(); i++)
        {
            // check whether the ith flower is bloomed or not
            if (bloomDay[i] <= D)
            {
                counter++;
            }
            if (counter == k)
            {
                m--; // one buoquet made
                counter = 0;
                if (m == 0)
                    break;
            }

            // not bloomed
            if (bloomDay[i] > D)
                counter = 0;
        }
        return m == 0; // were you able to make m Bouquets?
    }

    int minDays(vector<int> &bloomDay, int m, int k)
    {
        long long int requirement = (long long int)m * (long long int)k;
        if (bloomDay.size() < requirement)
            return -1;

        int start = *min_element(bloomDay.begin(), bloomDay.end()); // at least 1 flower is bloomed
        int end = *max_element(bloomDay.begin(), bloomDay.end());   // all flowers are bloomed, pkka bna lunga
        int ans = 0;
        while (start <= end)
        {
            int mid = (start + end) >> 1;
            int day = mid;
            if (canWeMakeMBouquetsWithDDays(bloomDay, m, k, day))
            {
                ans = mid;
                end = mid - 1;
            }
            else
                start = mid + 1;
        }
        return ans;
    }
};
