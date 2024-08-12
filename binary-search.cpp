// Binary Search
#include <bits/stdc++.h>
using namespace std;

int binarySearch(int nums[], int size, int target) {
    int left = 0, right = size - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}

int main() {
    int nums[] = {1, 3, 5, 7, 9, 11};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 7;
    int result = binarySearch(nums, size, target);
    if (result != -1) {
        cout << "Element found at index " << result;
    } else {
        cout << "Element not found";
    }
    return 0;
}






// Search a 2D Matrix
#include <bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& matrix, int target) {
    if (matrix.empty()) return false;
    int rows = matrix.size(), cols = matrix[0].size();
    int left = 0, right = rows * cols - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        int midValue = matrix[mid / cols][mid % cols];
        if (midValue == target) {
            return true;
        } else if (midValue < target) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return false;
}

int main() {
    vector<vector<int>> matrix = {{1, 3, 5, 7}, {10, 11, 16, 20}, {23, 30, 34, 60}};
    int target = 3;
    cout << boolalpha << searchMatrix(matrix, target);
    return 0;
}






// Koko Eating Bananas
#include <bits/stdc++.h>
using namespace std;

int minEatingSpeed(vector<int>& piles, int h) {
    int left = 1, right = *max_element(piles.begin(), piles.end());
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        int hours = 0;
        for (int pile : piles) {
            hours += ceil((double)pile / mid);
        }
        if (hours <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }
    return left;
}

int main() {
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;
    cout << "Minimum Eating Speed: " << minEatingSpeed(piles, h);
    return 0;
}






// Find Minimum In Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;

int findMin(vector<int>& nums) {
    int left = 0, right = nums.size() - 1;
    
    while (left < right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] > nums[right]) {
            left = mid + 1;
        } else {
            right = mid;
        }
    }
    return nums[left];
}

int main() {
    vector<int> nums = {4, 5, 6, 7, 0, 1, 2};
    cout << "Minimum Element: " << findMin(nums);
    return 0;
}






// Search In Rotated Sorted Array
#include <bits/stdc++.h>
using namespace std;

int search(int nums[], int size, int target) {
    int left = 0, right = size - 1;
    
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (nums[mid] == target) return mid;
        if (nums[left] <= nums[mid]) {
            if (target >= nums[left] && target < nums[mid]) {
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        } else {
            if (target > nums[mid] && target <= nums[right]) {
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }
    }
    return -1;
}

int main() {
    int nums[] = {4, 5, 6, 7, 0, 1, 2};
    int target = 0;
    int result = search(nums, 7, target);
    if (result != -1) {
        cout << "Element found at index " << result;
    } else {
        cout << "Element not found";
    }
    return 0;
}






// Time Based Key Value Store
#include <bits/stdc++.h>
using namespace std;

struct KeyValue {
    string key;
    string value;
    int timestamp;
};

class TimeMap {
private:
    KeyValue store[1000];
    int count;

public:
    TimeMap() : count(0) {}

    void set(string key, string value, int timestamp) {
        store[count].key = key;
        store[count].value = value;
        store[count].timestamp = timestamp;
        count++;
    }

    string get(string key, int timestamp) {
        int left = 0, right = count - 1;
        string result = "";

        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (store[mid].key == key && store[mid].timestamp <= timestamp) {
                result = store[mid].value;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        return result;
    }
};

int main() {
    TimeMap timeMap;
    timeMap.set("foo", "bar", 1);
    cout << timeMap.get("foo", 1) << endl;
    timeMap.set("foo", "bar2", 4);
    cout << timeMap.get("foo", 4) << endl;
    return 0;
}






// Median of Two Sorted Arrays
#include <bits/stdc++.h>
using namespace std;

double findMedianSortedArrays(int nums1[], int size1, int nums2[], int size2) {
    if (size1 > size2) {
        return findMedianSortedArrays(nums2, size2, nums1, size1);
    }

    int x = size1;
    int y = size2;
    int low = 0, high = x;
    
    while (low <= high) {
        int partitionX = (low + high) / 2;
        int partitionY = (x + y + 1) / 2 - partitionX;

        int maxX = (partitionX == 0) ? INT_MIN : nums1[partitionX - 1];
        int minX = (partitionX == x) ? INT_MAX : nums1[partitionX];
        
        int maxY = (partitionY == 0) ? INT_MIN : nums2[partitionY - 1];
        int minY = (partitionY == y) ? INT_MAX : nums2[partitionY];

        if (maxX <= minY && maxY <= minX) {
            if ((x + y) % 2 == 0) {
                return (double)(max(maxX, maxY) + min(minX, minY)) / 2;
            } else {
                return (double)max(maxX, maxY);
            }
        } else if (maxX > minY) {
            high = partitionX - 1;
        } else {
            low = partitionX + 1;
        }
    }
    throw invalid_argument("Input arrays are not sorted.");
}

int main() {
    int nums1[] = {1, 3};
    int nums2[] = {2};
    cout << "Median: " << findMedianSortedArrays(nums1, 2, nums2, 1);
    return 0;
}
