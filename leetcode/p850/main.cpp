#include <vector>
#include <set>
#include <iostream>
#include <algorithm>
#include <map>

using namespace std;

const int MOD = 1e9 + 7;

struct Segment {
    int x1;
    int x2;
    int y;
    bool start;

    Segment(): x1(0), x2(0), y(0), start(false) {
    }

    Segment(int x1, int x2, int y, bool start): x1(x1), x2(x2), y(y), start(start) {
    }
};

bool comp(const Segment& s1, const Segment& s2) {
    if (s1.y == s2.y) {
        return s1.x1 < s2.x1;
    }
    return s1.y < s2.y;
}

class Solution {
private:
    vector<Segment> segs;
    map<pair<int, int>, int> cover; // have to use map here in case of dup segments

    int coverRange() {
        if (cover.empty()) {
            return 0;
        }

        int res = 0;
        auto it = cover.begin();
        auto pr = it->first;
        int start = pr.first;
        int end = pr.second;

        ++it;
        while (it != cover.end()) {
            pr = it->first;
            if (pr.first > end) {
                res += (end - start);
                start = pr.first;
                end = pr.second;
            } else {
                end = max(end, pr.second);
            }
            ++it;
        }
        res += (end - start);

        return res;
    }
public:
    int rectangleArea(vector<vector<int>>& rectangles) {
        if (rectangles.empty()) {
            return 0;
        }

        for (auto& pt : rectangles) {
            int x1 = pt[0];
            int y1 = pt[1];
            int x2 = pt[2];
            int y2 = pt[3];
            segs.push_back(Segment(x1, x2, y1, true));
            segs.push_back(Segment(x1, x2, y2, false));
        }
        sort(segs.begin(), segs.end(), comp);

        long long res = 0;
        int n = segs.size();
        int y = segs[0].y;
        for (int i = 0; i < n; ++i) {
            int cov = coverRange();
            res = (res + (segs[i].y - y) * (long long)cov) % MOD;

            y = segs[i].y;
            auto pr = make_pair(segs[i].x1, segs[i].x2);
            if (segs[i].start) {
                ++cover[pr];
            } else {
                --cover[pr];
                if (cover[pr] == 0) {
                    cover.erase(pr);
                }
            }
        }

        return res;
    }
};


int main(int argc, char** argv) {
    Solution sol;
    return 0;
}

