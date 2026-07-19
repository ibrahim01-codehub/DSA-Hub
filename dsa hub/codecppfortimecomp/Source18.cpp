#include <iostream>
#include <vector>
using namespace std;

void generateSubsets(vector<int>& nums, int index, vector<int>& current) {
    if (index == (int)nums.size()) {
        for (int x : current) cout << x << " ";
        cout << endl;
        return;
    }

    // Exclude current element
    generateSubsets(nums, index + 1, current);

    // Include current element
    current.push_back(nums[index]);
    generateSubsets(nums, index + 1, current);
    current.pop_back();
}

int main() {
    vector<int> nums = {1, 2, 3};
    vector<int> current;
    generateSubsets(nums, 0, current);
    return 0;
}
