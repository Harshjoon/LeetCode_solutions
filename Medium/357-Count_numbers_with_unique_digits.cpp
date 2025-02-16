class Solution {
public:
    int countNumbersWithUniqueDigits(int n) {
        if(n==0) return 1;
        //if(n==1) return 10;

        int fact = 9;

        for(int i=0;i<n-1;i++)
        {
            fact*=(9-i);
        }

        return fact + countNumbersWithUniqueDigits(n-1);
    }
};