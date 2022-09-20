 #include<bits/stdc++.h>
 using namespace std ;

class Solution{
	public:
	int findK(vector<vector<int>> &a, int n, int m, int k)
    {
        int sc = 0, ec = m-1;
        int sr = 0, er = n-1;
        int ans = -1 ;
        while(sc<=ec and sr <= er and k)
        {
            for(int c = sc; c<= ec and k; c++, k--)
                ans = a[sr][c]; 
            sr++;
            for(int r = sr; r<= er and k; r++, k--)
                ans = a[r][ec];
            ec--;
            for(int c = ec; c >= sc and k; c--, k--)
                ans = a[er][c];
            er--;
            for(int r = er; r >= sr and k; r--, k--)
                ans = a[r][sc];
            sc++;
        }
        return ans;
    }
};