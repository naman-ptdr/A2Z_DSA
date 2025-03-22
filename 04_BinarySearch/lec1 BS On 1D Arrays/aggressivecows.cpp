#include <bits/stdc++.h>
using namespace std;
bool isPossible(vector<int> &nums, int dis, int cows)
{
    int cntCows = 1;
    int last = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        if (nums[i] - last >= dis)
        {
            cntCows++;
            last = nums[i];
        }
        if (cntCows >= cows)
            return true;
    }
    return false;
}
int aggressiveCow(vector<int> &nums, int cows)
{
    sort(nums.begin(), nums.end());
    int n = nums.size();
    int low = 1;
    int high = nums[n - 1] - nums[0];
    int ans = -1;
    while (low <= high)
    {
        int mid = low + ((high - low) >> 1);
        if (isPossible(nums, mid, cows))
        {
            ans = mid;
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
    return ans;
}
int main()
{
    // your code goes here
    int T;
    cin >> T;
    while (T--)
    {
        int N, C;
        cin >> N >> C;
        vector<int> nums;
        for (int i = 0; i < N; i++)
        {
            int ele;
            cin >> ele;
            nums.push_back(ele);
        }
        int maxOfmin = aggressiveCow(nums, C);
        cout << maxOfmin << endl;
    }
    return 0;
}