class Solution {
public:
    string removeOuterParentheses(string s) {
        string res;
        int count  = 0;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                count++;
                if(count > 1){
                    res += s[i];
                }
                
            }
            else{
                count--;
                if(count > 0){
                    res += s[i];
                }
                
            }
        }
        return res;
    }
};