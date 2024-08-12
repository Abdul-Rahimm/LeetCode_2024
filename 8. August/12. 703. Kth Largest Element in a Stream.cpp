// بِسْمِ اللهِ الرَّحْمٰنِ الرَّحِيْمِ
#include <bits/stdc++.h>
using namespace std;
#define all(x) x.begin(), x.end()
typedef vector<int> vi;
typedef vector<vi> vii;
 
class KthLargest {
public:
    int k;
    priority_queue<int, vector<int>, greater<int>> pq;
    
    void addNumber(int num){
        pq.push(num);
        
        while(pq.size() > k){
            pq.pop();
        }
    }
    
    KthLargest(int num, vector<int>& array) {
        k = num;
        
        for(int i: array){
            addNumber(i);
        }
    }
    
    int add(int val) {
        addNumber(val);
        
        return pq.top();
    }
};
