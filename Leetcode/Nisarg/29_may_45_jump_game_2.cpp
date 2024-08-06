//  Recursive Solution, TLE.
class Solution
{
    int help(int index, int jumps, vector<int> &nums)
    {
        if (index >= nums.size() - 1)
            return jumps;

        int j = nums[index];
        int mini = INT_MAX;
        for (int i = 1; i <= j; i++)
        {
            mini = min(mini, help(index + i, jumps + 1, nums));
        }
        return mini;
    }

public:
    int jump(vector<int> &nums)
    {
        return help(0, 0, nums);
    }
};

// MOST OPTIMAL
class Solution
{
public:
    int jump(vector<int> &nums)
    {
        int l = 0, r = 0, n = nums.size() - 1, j, ans = 0;

        while (r < n)
        {
            j = 0;
            for (int i = l; i <= r; i++)
            {
                j = max(j, i + nums[i]);
            }
            l = r + 1;
            r = j;
            ans++;
        }
        return ans;
    }
};