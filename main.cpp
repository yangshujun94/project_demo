#include <vector>
#include <iostream> // 包含 cout 和 endl
#include <unordered_map> // 包含 unordered_map
using namespace std;
int maxOperations(vector<int>& nums, int k) {
    unordered_map<int, int> count;
    int operations = 0;

    // Count the occurrences of each number
    for (int num : nums) {
        count[num]++;
    }

    // Find pairs that sum up to k
    for (int num : nums) {
        if (count[k - num] > 0) {
            operations++;
            count[k - num]--;
            if (count[k - num] == 0) {
                count.erase(k - num);
            }
            count[num]--;
            if (count[num] == 0) {
                count.erase(num);
            }
        }
    }

    return operations;
}

// 示例 1
int main() {
    vector<int> nums = {1,2,3,4};
    int k = 5;
    cout << maxOperations(nums, k) << endl;  // 输出 2
    return 0;
}

//// 示例 2
//int main2() {
//    vector<int> nums = {3,1,3,4,3};
//    int k = 6;
//    cout << maxOperations(nums, k) << endl;  // 输出 1
//    return 0;
//}