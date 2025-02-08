class Solution {
public:
    void reverseString(vector<char>& s) {
        int forw = 0;
        int back = s.size() - 1;

        while( forw < back)
        {
            char temp = s[back];
            s[back] = s[forw];
            s[forw] = temp;
            forw++;
            back--;
        }
    }
};