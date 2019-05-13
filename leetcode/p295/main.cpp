#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

//≈≈–Ú≥¨ ±
/*
class MedianFinder {
public:
    vector<int> arr;
    MedianFinder() {
        ;
    }

    void addNum(int num) {
        arr.push_back(num);
        sort(arr.begin(),arr.end());
    }

    double findMedian() {
        if(arr.size()==0){
            return 0;
        }else if(arr.size()%2==1){
            return arr[arr.size()/2];
        }else if(arr.size()%2==0){
            double ret = arr[arr.size()/2] + arr[arr.size()/2-1];
            return ret/2;
        }
        return 0;
    }
};
*/
class MedianFinder {
public:

    priority_queue<int,vector<int>, less<int> > maxHeap;
    priority_queue<int,vector<int>, greater<int> > minHeap;

    MedianFinder() {
        ;
    }

    void addNum(int num) {
        if(minHeap.empty()){
            minHeap.push(num);
        }else{
            if( num>=minHeap.top() ){
                minHeap.push(num);
            }else{
                maxHeap.push(num);
            }
        }
        if( int(maxHeap.size()-minHeap.size()) > 1 ){
            minHeap.push(maxHeap.top());
            maxHeap.pop();
        }else if( int(maxHeap.size()-minHeap.size()) < -1 ){
            maxHeap.push(minHeap.top());
            minHeap.pop();
        }
    }

    double findMedian() {
        if(maxHeap.empty() && minHeap.empty()){
            return 0;
        }
        if(maxHeap.size()>minHeap.size()){
            return maxHeap.top();
        }else if(maxHeap.size()<minHeap.size()){
            return minHeap.top();
        }else{
            double ret = minHeap.top()+maxHeap.top();
            return ret/2;
        }
        return 0;
    }
};
int main()
{


    MedianFinder MedianFinder1;
    MedianFinder1.addNum(1);
    MedianFinder1.addNum(2);
    cout<<MedianFinder1.findMedian()<<endl;
    return 0;
}
