class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        if(tokens.size()==1) return stoi(tokens[0]);
        
        stack<int> ints;

        int first,second;
        int res;

        for(string c: tokens )
        {
            if( c=="+" || c=="-" || c=="*" || c=="/"){
                first = ints.top();
                ints.pop();
                second = ints.top();
                ints.pop();
                res=solve(c,second,first);
                ints.push(res);

                cout << first << endl;
                cout << second << endl;
                cout << res << endl;
            }
            else{
                ints.push(stoi(c));
            }
        }
        return res;
    }

    int solve(string op, int a, int b){
        if( op=="+") return a+b;
        if( op=="-") return a-b;
        if( op=="*") return a*b;
        if( op=="/") return a/b;
        return -1;
    }
};