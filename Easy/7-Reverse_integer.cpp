class Solution {
public:
    int reverse(int x) {
        int reversed = 0;
        int pop;

        while ( x!= 0 )
        {
            pop = x % 10;
            x /= 10;

            if ( (reversed>INT_MAX/10) || (reversed<INT_MIN/10) ) return 0;

            reversed = (10*reversed) + pop;
        }

        return reversed;
    }
};