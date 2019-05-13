#include <iostream>
#include <limits.h>
#include <vector>
#include <stack>

using namespace std;
#define debug(x) cout<<#x<<": "<<x<<endl;
/*
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int ret = 0;
        for(int i=0;i<heights.size();i++){
            for(int j=i;j<heights.size();j++){
                int min1 = INT_MAX;
                for(int k=i;k<=j;k++){
                    min1 = min(heights[k],min1);
                }
                ret = max(ret,min1* ( j-i+1) );
            }
        }
        return ret;
    }
};
*/

/*
//dp³¢ÊÔ1 O(N^2) ÒÀ¾É³¬Ê±
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        if(heights.size()==0){
            return 0;
        }else if(heights.size()==1){
            return heights[0];
        }
        vector<int>dp(heights);
        int ret = 0;
        for(int i=0;i<heights.size();i++){
            int min1 = heights[i];
            for(int j=i+1;j<heights.size();j++){
                min1 = min(min1,heights[j]);
                dp[j] = max( dp[j],(j-i+1)*min1 );
            }
            ret = max(dp[i],ret);
        }
        return ret;
    }
};
*/

//µ¥µ÷Õ»
struct point{
    int x,y;
    int val;
    point(int pos,int val):x(pos),y(pos),val(val){}
    point(){}
};
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<point> st;
        int ret = 0;
        for(int i = 0;i < heights.size();i ++){
            if(st.empty()){
                st.push(point(i,heights[i]));
            }else{

                 if( st.top().val < heights[i]){
                    //st.top().y = i;
                    st.push(point(i,heights[i]));
                 }else{

                    point ptt(i,heights[i]);
                    while(!st.empty() && st.top().val >= heights[i] ){
                        point pt = st.top();
                        st.pop();
                        //debug(pt.val);
                        //debug(pt.x);
                        //debug(pt.y);
                        ret = max(ret, (pt.y-pt.x+1)*pt.val );
                        if(!st.empty()){
                            st.top().y = pt.y;
                        }
                        ptt.x = pt.x;
                    }

                    if(!st.empty()){
                        st.top().y = ptt.y;
                    }
                    st.push( ptt );
                 }
            }
        }
        while(!st.empty()){
            point pt = st.top();
            st.pop();
            if(!st.empty()){
                st.top().y = pt.y;
            }
            ret = max(ret, (pt.y-pt.x+1)*pt.val );
            //debug(pt.val);
            //debug(pt.x);
            //debug(pt.y);
        }
        //debug(ret);
        return ret;
    }
};

int main()
{
    Solution Solution1;
    vector<int> heights = {1,2,3,4,5};
    cout << Solution1.largestRectangleArea(heights) << endl;
    return 0;
}
