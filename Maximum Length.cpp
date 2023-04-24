class Solution 
{
public:
    bool check(int a, int b, int c)
    {
        return ((a - 2) > ((b + c) << 1));
    }
    
    int solve(int a, int b, int c) 
    {
        if(check(a, b, c) || check(b, a, c) || check(c, b, a))
        {
            return -1;
        }
        
        return a + b + c;
    }
};