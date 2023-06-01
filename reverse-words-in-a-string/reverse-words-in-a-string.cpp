class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());
        int i=0, j=0, lastIndex = 0;
        int n = s.size();

        while(j<n){
            while(j<n && s[j] == ' '){
                j++;
            }

            int startIndex = i;

            while(j<n && s[j] != ' '){
                s[i] = s[j];
                i++;
                j++;
                lastIndex = i;
            }
            reverse(s.begin() + startIndex, s.begin()+ lastIndex);
            s[i] = ' ';
            i++;
        }
        s.resize(lastIndex);
        return s;
    }
};