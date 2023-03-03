class Solution {
public:
    vector<char> extractNumber(int num){
        vector<char> res;

        while(num){
            int digit = num % 10;
            num /= 10;

            res.push_back(digit + '0');
        }

        reverse(res.begin(), res.end());
        return res;
    }

    int writeCounter(vector<char>& chars, int counter, int writingPointer){
        // write the counter
        if(counter > 1 && counter < 10){
            chars[writingPointer] = counter + '0';
            writingPointer++;
        } 
        else if(counter >= 10){
            vector<char> extracted = extractNumber(counter);
            for(int i = 0 ; i < extracted.size() ; i++){
                chars[writingPointer] = extracted[i];
                writingPointer++;
            }
        }

        return writingPointer;
    }


    int compress(vector<char>& chars) {
        int counter = 1;
        int writingPointer = 1;

        for(int i = 1 ; i < chars.size() ; i++){
            if(chars[i] == chars[i-1]){
                counter++;
            }
            else{
                // write the counter
                writingPointer = writeCounter(chars, counter, writingPointer);

                // reset the counter
                counter = 1;

                // write the next char
                chars[writingPointer] = chars[i];
                writingPointer++;
            }
        }

        // write the counter for the last chars
        writingPointer = writeCounter(chars, counter, writingPointer);

        int n = chars.size();
        return min(writingPointer, n);
    }
};