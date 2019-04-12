#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Interval {
    int start;
    int end;
    Interval() : start(0), end(0) {}
    Interval(int s, int e) : start(s), end(e) {}
};

class Solution {
public:
    static bool cmp(Interval a, Interval b){
        return a.start < b.start;
    }

    bool ischong(Interval a,Interval b){
        if(a.start>b.end || b.start>a.end){
            return false;
        }else{
            return true;
        }
    }
    vector<Interval> merge(vector<Interval>& intervals) {

        vector<Interval> ret;
        if(intervals.size()==0){
            return ret;
        }else if(intervals.size()==1){
            ret.push_back(intervals[0]);
            return ret;
        }
        sort(intervals.begin(),intervals.end() ,cmp);
        Interval temp = intervals[0];
        for(int i=1;i<intervals.size();i++){
            if(ischong(intervals[i],temp)){
                temp.start = min(temp.start,intervals[i].start);
                temp.end = max(temp.end,intervals[i].end);
            }else{
                ret.push_back(temp);
                temp = intervals[i];

            }
            if(i==intervals.size()-1){
                    ret.push_back(temp);
            }
        }
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<Interval> vi;
    vi.push_back(Interval(1,4));
    vi.push_back(Interval(4,5));
    //vi.push_back(Interval(8,10));
    //vi.push_back(Interval(15,18));

    vector<Interval> ret = Solution1.merge(vi);
    for(auto i :ret){
        cout<<i.start<<" "<<i.end<<endl;
    }
    return 0;
}

