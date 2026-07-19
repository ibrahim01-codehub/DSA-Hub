#include <iostream>
#include <vector>
using namespace std;

void generatePermutations(vector<int>& nums, int start) {
    if (start == (int)nums.size()) {
        for (int x : nums) cout << x << " ";
        cout << endl;
        return;
    }

    for (int i = start; i < (int)nums.size(); i++) {
        swap(nums[start], nums[i]);
        generatePermutations(nums, start + 1);
        swap(nums[start], nums[i]);
    }
}

int main() {
    vector<int> nums = {1, 2, 3};
    generatePermutations(nums, 0);
    return 0;
}
