class Solution {
public:
    string addBinary(string a, string b) {
        int n = a.size();
        int m = b.size();
        if(n < m) return addBinary(b, a);

        int M = max(n, m);
        int carry = 0;
        string result = "";
        int j = m - 1;

        for(int i = M-1 ; i >= 0 ; i--){
            int sum = int(a[i]-'0') + carry;
            if(j >= 0) sum += int(b[j]-'0');

            if(sum == 1){
                result += '1';
                carry = 0;
            }else if(sum == 2){
                result += '0';
                carry = 1;
            } else if(sum == 3){
                result += '1';
                carry = 1;
            }else{
                result += '0';
                carry = 0;   
            }

            j--;
        }

        if(carry == 1) result += '1';
        reverse(result.begin(), result.end());

        return result;
    }
};