// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
 
 double averageWaitingTime(vector<vector<int>>& cus) {
        
        double waitingTime = 0;
        int n = cus.size();
        int finish = cus[0][0];                     //this is the time at which the cooking starts
        
        for(int i = 0 ; i < n ; i++){
            
            int start  = cus[i][0];                                      // 5 5 10  20
            finish     = max(finish + cus[i][1], start + cus[i][1]);     // 7 11 14 15
            
            waitingTime += finish - start;
        }
        
        return waitingTime / n;
        
    }