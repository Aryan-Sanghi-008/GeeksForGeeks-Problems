class Solution
{
public:
    bool isValid(int temp, int i, vector<int> &ans, vector<int> &arr)
    {
        return (temp != -1 && abs(i - ans[i]) > abs(i - temp)) || (temp != -1 && abs(i - ans[i]) == abs(i - temp) && arr[ans[i]] > arr[temp]);
    }
    vector<int> nearestSmallerTower(vector<int> &arr)
    {
        int n = arr.size();
        stack<int> st;
        st.push(-1);
        vector<int> ans(n, -1);
        for(int i = 0; i < n; i++)
        {
            while(st.top() != -1 && arr[i] <= arr[st.top()])
            {
                st.pop();       
            }
            ans[i] = st.top();
            st.push(i);
        }
        
        while(st.top() != -1)
        {
            st.pop();
        }
        
        st.push(n - 1);
        for (int i = n - 2; i >= 0; i--)
        {
            int temp;
            while (st.top() != -1 && arr[i] <= arr[st.top()])
            {
                st.pop();
            }
            temp = st.top();
            if (i == 0)
            {
                ans[i] = temp;
                break;
            }
            else if (ans[i] == -1)
            {
                ans[i] = temp;
            }
            else if (isValid(temp, i, ans, arr))
            {
                ans[i] = temp;
            }
            st.push(i);
        }
        return ans;
    }
    
};