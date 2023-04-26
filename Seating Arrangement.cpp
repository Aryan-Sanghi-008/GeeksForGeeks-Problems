//User function Template for C++

class Solution{
    public:
    bool is_possible_to_get_seats(int n, int m, vector<int>& seats)
    {
        if(n == 0)
        {
            return 1;
        }
        
        if(m == 1)
        {
            if(seats[0] == 0)
            {
                n--;
            }
            
            return n <= 0;
        }
        
        if(seats[0] == 0 && seats[1] == 0)
        {
            n--;
            seats[0] = 1;
        }
        
        for(int i = 1; i < m - 1; i++)
        {
            if(seats[i] == 0 && seats[i + 1] == 0 && seats[i - 1] == 0)
            {
                seats[i] = 1;
                n--;
            }
        }
        
        if(seats[m - 1] == 0 && seats[m - 2] == 0)
        {
            n--;
        }
        
        return n <= 0;
    }
};