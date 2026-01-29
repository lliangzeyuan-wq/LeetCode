#include<iostream>
#include<vector>
using namespace std;
class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        //这种要提前注意的小情况
        if (nums.size() <= 1) {
            return nums.size();
        }
        int result = 1;//序列默认记录最右边有一个峰值
        int preDiff = 0;//前一对差值
        int curDiff = 0;//当前一对差值
        for (int i = 0; i < nums.size() - 1; i++) {
            curDiff = nums[i + 1] - nums[i];
            if (preDiff <= 0 && curDiff > 0 || preDiff >= 0 && curDiff < 0) {
                result++;
                preDiff = curDiff;//注意：只在摆动变化的时候更新preDiff
            }
        }
        return result;
    }
}; 