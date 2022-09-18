
class Solution{
	public:
    	long long findNth(long long N)
    {
         long long result = 0;
         long long p = 1;

    while (N > 0) {
 
        result += (p * (N % 9));
        N = N / 9;
        p = p * 10;
    }

    return result;
    }
};