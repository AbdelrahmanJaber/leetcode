#include <cstdio>
#include <iostream>
using namespace std;
class Solution {
public:
    bool is_valid(int hours, int minutes, unordered_set<int>& uset){
        int H1 = hours / 10;
        int H2 = hours % 10;
        int M1 = minutes /10;
        int M2 = minutes % 10;

        return (uset.count(H1) && uset.count(H2) && uset.count(M1) && uset.count(M2));
    }

    string formatClock(int minutes, int hours){
        int H1 = hours / 10;
        int H2 = hours % 10;
        int M1 = minutes /10;
        int M2 = minutes % 10;

        return to_string(H1) + to_string(H2) + ":" + to_string(M1) + to_string(M2);
    }

    string nextClosestTime(string time) {
        int minutes = (int(time[3] - '0') * 10) + int(time[4] - '0');
        int hours = (int(time[0] - '0') * 10) + int(time[1] - '0');

        unordered_set<int> uset;
        for(int i = 0 ; i < time.size() ; i++){
            if(i==2) i++;
            uset.insert(int(time[i] - '0'));
        }
        
        // increment the clock minute by minute
        while(true){
            minutes++;

            if(minutes == 60){
                hours++;
                minutes = 0;
            }
            if(hours == 24){
                hours = 0;
                minutes=0;
            }

            if(is_valid(hours, minutes, uset)) break;
        }

        // format the clock
        string foramattedClock = formatClock(minutes, hours);

        // return the clock
        return foramattedClock;
    }
};


// Time complexity = O(24(hour) * 60(minute)) = O(1440) = O(1)
// Space complexity = O((4 integers from uset)) = O(1)


// ---***&&&***--- //
