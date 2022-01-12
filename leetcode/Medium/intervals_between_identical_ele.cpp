class Solution {
public:
    #define ll long long
    vector<long long> getDistances(vector<int>& arr) {
        ll n = arr.size();
        vector<ll> ans(n, 0);
        unordered_map<ll, pair<ll, ll>> left;
        for(int i = 0; i < n; i++){
            ll left_count = left[arr[i]].first;
            ll left_sum = left[arr[i]].second;
            ans[i] = left_count*i - left_sum;
            left[arr[i]].first += 1;
            left[arr[i]].second += i;
        }
        unordered_map<ll, pair<ll, ll>> right; 
        for(int i = n-1; i >= 0; i--){
            ll right_count = right[arr[i]].first;
            ll right_sum = right[arr[i]].second;
            ans[i] += right_sum - right_count*i;
            right[arr[i]].first += 1;
            right[arr[i]].second += i;
        }
        return ans;
    }
};