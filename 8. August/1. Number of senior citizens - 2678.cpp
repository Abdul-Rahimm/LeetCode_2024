// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
 
int countSeniors(vector<string>& details) {
        
        int count = 0;
        for(int i = 0 ; i < details.size() ; i++){
            
            string current = details[i];
            
            char first  = current[11];
            char second = current[12];
            
            if(first > '6'){
                count++;
            }
            else if(first == '6' && second > '0'){
                count++;
            }
            
        }
        
        return count;
    }