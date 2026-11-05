class Solution {
public:
    string reverseWords(string s) {
        int n = s.size();
        int i = 0;

        while(i < n && s[i] == ' ') {
            i++;
        }

        int j = n - 1;

        while(j >= 0 && s[j] == ' ') {
            j--;
        }

        string ans = "";
        int start = i;

        while(i <= j) {

            if(s[i] == ' ') {

                if(start < i) {
                    if(ans != "") {
                        ans = s.substr(start, i-start) + " " + ans;
                    }
                    else {
                        ans = s.substr(start, i-start);
                    }
                }

                start = i + 1;
            }

            i++;
        }

        // Last word
        if(start <= j) {
            if(ans != "") {
                ans = s.substr(start, j-start+1) + " " + ans;
            }
            else {
                ans = s.substr(start, j-start+1);
            }
        }

        return ans;
    }
};