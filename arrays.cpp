// Contains Duplicate
#include <bits/stdc++.h>
using namespace std;

bool containsDuplicate(int nums[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] == nums[j]) {
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nums[] = {1, 2, 3, 1};
    int size = sizeof(nums) / sizeof(nums[0]);
    cout << boolalpha << containsDuplicate(nums, size);
    return 0;
}






// Valid Anagram
#include <bits/stdc++.h>
using namespace std;

bool isAnagram(char s[], char t[]) {
    int n1 = strlen(s);
    int n2 = strlen(t);
    if (n1 != n2) return false;

    sort(s, s + n1);
    sort(t, t + n2);

    for (int i = 0; i < n1; i++) {
        if (s[i] != t[i]) {
            return false;
        }
    }
    return true;
}

int main() {
    char s[] = "anagram";
    char t[] = "nagaram";
    cout << boolalpha << isAnagram(s, t);
    return 0;
}










// Two Sum
#include <bits/stdc++.h>
using namespace std;

bool twoSum(int nums[], int size, int target) {
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j < size; j++) {
            if (nums[i] + nums[j] == target) {
                cout << "Indices: " << i << ", " << j << endl;
                return true;
            }
        }
    }
    return false;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    if (!twoSum(nums, size, target)) {
        cout << "No valid pair found.";
    }
    return 0;
}










// Group Anagrams
#include <bits/stdc++.h>
using namespace std;

void groupAnagrams(char strs[][10], int size) {
    bool visited[size] = {false};
    
    for (int i = 0; i < size; i++) {
        if (visited[i]) continue;
        visited[i] = true;
        cout << "Group: " << strs[i];
        for (int j = i + 1; j < size; j++) {
            if (visited[j]) continue;
            char temp1[10], temp2[10];
            strcpy(temp1, strs[i]);
            strcpy(temp2, strs[j]);
            sort(temp1, temp1 + strlen(temp1));
            sort(temp2, temp2 + strlen(temp2));
            if (strcmp(temp1, temp2) == 0) {
                visited[j] = true;
                cout << ", " << strs[j];
            }
        }
        cout << endl;
    }
}

int main() {
    char strs[][10] = {"eat", "tea", "tan", "ate", "nat", "bat"};
    int size = sizeof(strs) / sizeof(strs[0]);
    groupAnagrams(strs, size);
    return 0;
}










// Top K Frequent Elements
#include <bits/stdc++.h>
using namespace std;

void topKFrequent(int nums[], int size, int k) {
    int count[101] = {0}; // Assuming elements are between 0 and 100

    for (int i = 0; i < size; i++) {
        count[nums[i]]++;
    }

    while (k > 0) {
        int maxCount = 0;
        int index = -1;
        for (int i = 0; i < 101; i++) {
            if (count[i] > maxCount) {
                maxCount = count[i];
                index = i;
            }
        }
        if (index != -1) {
            cout << index << " ";
            count[index] = 0;
        }
        k--;
    }
}

int main() {
    int nums[] = {1, 1, 1, 2, 2, 3};
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 2;
    topKFrequent(nums, size, k);
    return 0;
}










// Encode and Decode Strings   
#include <bits/stdc++.h>
using namespace std;

void encode(char strs[][20], int size, char result[]) {
    strcpy(result, "");
    for (int i = 0; i < size; i++) {
        strcat(result, strs[i]);
        strcat(result, "|"); // Use '|' as a delimiter
    }
}

void decode(char encodedStr[], char decodedStrs[][20], int &size) {
    size = 0;
    char *token = strtok(encodedStr, "|");
    while (token != nullptr) {
        strcpy(decodedStrs[size++], token);
        token = strtok(nullptr, "|");
    }
}

int main() {
    char strs[][20] = {"hello", "world", "coding", "fun"};
    int size = sizeof(strs) / sizeof(strs[0]);

    char encoded[100];
    encode(strs, size, encoded);
    cout << "Encoded: " << encoded << endl;

    char decodedStrs[10][20];
    int decodedSize;
    decode(encoded, decodedStrs, decodedSize);

    cout << "Decoded: ";
    for (int i = 0; i < decodedSize; i++) {
        cout << decodedStrs[i] << " ";
    }
    return 0;
}










// Product of Array Except Self
#include <bits/stdc++.h>
using namespace std;

void productExceptSelf(int nums[], int size, int result[]) {
    for (int i = 0; i < size; i++) {
        result[i] = 1;
        for (int j = 0; j < size; j++) {
            if (i != j) {
                result[i] *= nums[j];
            }
        }
    }
}

int main() {
    int nums[] = {1, 2, 3, 4};
    int size = sizeof(nums) / sizeof(nums[0]);
    int result[size];

    productExceptSelf(nums, size, result);

    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    return 0;
}










// Valid Sudoku
#include <bits/stdc++.h>
using namespace std;

bool isValidSudoku(char board[9][9]) {
    int row[9][9] = {0}, col[9][9] = {0}, box[9][9] = {0};
    
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (board[i][j] == '.') continue;
            int num = board[i][j] - '1';
            int k = (i / 3) * 3 + j / 3;
            if (row[i][num] || col[j][num] || box[k][num])
                return false;
            row[i][num] = col[j][num] = box[k][num] = 1;
        }
    }
    return true;
}

int main() {
    char board[9][9] = {
        {'5', '3', '.', '.', '7', '.', '.', '.', '.'},
        {'6', '.', '.', '1', '9', '5', '.', '.', '.'},
        {'.', '9', '8', '.', '.', '.', '.', '6', '.'},
        {'8', '.', '.', '.', '6', '.', '.', '.', '3'},
        {'4', '.', '.', '8', '.', '3', '.', '.', '1'},
        {'7', '.', '.', '.', '2', '.', '.', '.', '6'},
        {'.', '6', '.', '.', '.', '.', '2', '8', '.'},
        {'.', '.', '.', '4', '1', '9', '.', '.', '5'},
        {'.', '.', '.', '.', '8', '.', '.', '7', '9'}
    };

    cout << boolalpha << isValidSudoku(board);
    return 0;
}










// Longest Consecutive Sequence
#include <bits/stdc++.h>
using namespace std;

int longestConsecutive(int nums[], int size) {
    int maxLen = 0;
    for (int i = 0; i < size; i++) {
        int currentNum = nums[i];
        int currentLen = 1;
        for (int j = 0; j < size; j++) {
            if (nums[j] == currentNum + 1) {
                currentNum++;
                currentLen++;
                j = -1; // Restart the loop to check for next number
            }
        }
        if (currentLen > maxLen) {
            maxLen = currentLen;
        }
    }
    return maxLen;
}

int main() {
    int nums[] = {100, 4, 200, 1, 3, 2};
    int size = sizeof(nums) / sizeof(nums[0]);

    cout << longestConsecutive(nums, size);
    return 0;
}










// Valid Palindrome
#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(char s[]) {
    int left = 0, right = strlen(s) - 1;
    while (left < right) {
        while (left < right && !isalnum(s[left])) left++;
        while (left < right && !isalnum(s[right])) right--;
        if (tolower(s[left]) != tolower(s[right])) return false;
        left++;
        right--;
    }
    return true;
}

int main() {
    char s[] = "A man, a plan, a canal: Panama";
    cout << boolalpha << isPalindrome(s);
    return 0;
}









// Two Sum II Input Array Is Sorted
#include <bits/stdc++.h>
using namespace std;

bool twoSumSorted(int nums[], int size, int target) {
    int left = 0, right = size - 1;
    while (left < right) {
        int sum = nums[left] + nums[right];
        if (sum == target) {
            cout << "Indices: " << left << ", " << right << endl;
            return true;
        } else if (sum < target) {
            left++;
        } else {
            right--;
        }
    }
    return false;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int size = sizeof(nums) / sizeof(nums[0]);
    int target = 9;
    if (!twoSumSorted(nums, size, target)) {
        cout << "No valid pair found.";
    }
    return 0;
}









// 3Sum
#include <bits/stdc++.h>
using namespace std;

void threeSum(int nums[], int size) {
    sort(nums, nums + size);
    for (int i = 0; i < size - 2; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) continue; // Skip duplicates
        int left = i + 1, right = size - 1;
        while (left < right) {
            int sum = nums[i] + nums[left] + nums[right];
            if (sum == 0) {
                cout << "Triplet: " << nums[i] << ", " << nums[left] << ", " << nums[right] << endl;
                while (left < right && nums[left] == nums[left + 1]) left++; // Skip duplicates
                while (left < right && nums[right] == nums[right - 1]) right--; // Skip duplicates
                left++;
                right--;
            } else if (sum < 0) {
                left++;
            } else {
                right--;
            }
        }
    }
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int size = sizeof(nums) / sizeof(nums[0]);
    threeSum(nums, size);
    return 0;
}









// Container With Most Water
#include <bits/stdc++.h>
using namespace std;

int maxArea(int height[], int size) {
    int maxWater = 0;
    int left = 0, right = size - 1;
    while (left < right) {
        int width = right - left;
        int h = min(height[left], height[right]);
        maxWater = max(maxWater, width * h);
        if (height[left] < height[right]) {
            left++;
        } else {
            right--;
        }
    }
    return maxWater;
}

int main() {
    int height[] = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    int size = sizeof(height) / sizeof(height[0]);
    cout << "Maximum Water: " << maxArea(height, size);
    return 0;
}









// Trapping Rain Water
#include <bits/stdc++.h>
using namespace std;

int trap(int height[], int size) {
    if (size == 0) return 0;
    int leftMax[size], rightMax[size];
    leftMax[0] = height[0];
    rightMax[size - 1] = height[size - 1];
    
    for (int i = 1; i < size; i++) {
        leftMax[i] = max(leftMax[i - 1], height[i]);
    }
    for (int i = size - 2; i >= 0; i--) {
        rightMax[i] = max(rightMax[i + 1], height[i]);
    }

    int water = 0;
    for (int i = 0; i < size; i++) {
        water += min(leftMax[i], rightMax[i]) - height[i];
    }
    return water;
}

int main() {
    int height[] = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    int size = sizeof(height) / sizeof(height[0]);
    cout << "Trapped Water: " << trap(height, size);
    return 0;
}









// Best Time to Buy And Sell Stock
#include <bits/stdc++.h>
using namespace std;

int maxProfit(int prices[], int size) {
    int minPrice = INT_MAX, maxProfit = 0;
    for (int i = 0; i < size; i++) {
        if (prices[i] < minPrice) {
            minPrice = prices[i];
        } else if (prices[i] - minPrice > maxProfit) {
            maxProfit = prices[i] - minPrice;
        }
    }
    return maxProfit;
}

int main() {
    int prices[] = {7, 1, 5, 3, 6, 4};
    int size = sizeof(prices) / sizeof(prices[0]);
    cout << "Maximum Profit: " << maxProfit(prices, size);
    return 0;
}









// Longest Substring Without Repeating Characters
#include <bits/stdc++.h>
using namespace std;

int lengthOfLongestSubstring(char s[]) {
    int maxLen = 0, start = 0;
    int lastIndex[256];
    fill(lastIndex, lastIndex + 256, -1);

    for (int i = 0; i < strlen(s); i++) {
        if (lastIndex[s[i]] >= start) {
            start = lastIndex[s[i]] + 1;
        }
        lastIndex[s[i]] = i;
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

int main() {
    char s[] = "abcabcbb";
    cout << "Length of Longest Substring: " << lengthOfLongestSubstring(s);
    return 0;
}









// Longest Repeating Character Replacement
#include <bits/stdc++.h>
using namespace std;

int characterReplacement(char s[], int k) {
    int count[26] = {0};
    int maxCount = 0, maxLen = 0, start = 0;

    for (int i = 0; i < strlen(s); i++) {
        count[s[i] - 'A']++;
        maxCount = max(maxCount, count[s[i] - 'A']);

        if (i - start + 1 - maxCount > k) {
            count[s[start] - 'A']--;
            start++;
        }
        maxLen = max(maxLen, i - start + 1);
    }
    return maxLen;
}

int main() {
    char s[] = "AABABBA";
    int k = 1;
    cout << "Longest Repeating Character Replacement: " << characterReplacement(s, k);
    return 0;
}









// Permutation In String
#include <bits/stdc++.h>
using namespace std;

bool checkInclusion(char s1[], char s2[]) {
    int s1Len = strlen(s1), s2Len = strlen(s2);
    if (s1Len > s2Len) return false;

    int countS1[26] = {0}, countS2[26] = {0};
    for (int i = 0; i < s1Len; i++) {
        countS1[s1[i] - 'a']++;
        countS2[s2[i] - 'a']++;
    }

    for (int i = s1Len; i < s2Len; i++) {
        if (memcmp(countS1, countS2, 26 * sizeof(int)) == 0) {
            return true;
        }
        countS2[s2[i] - 'a']++;
        countS2[s2[i - s1Len] - 'a']--;
    }

    return memcmp(countS1, countS2, 26 * sizeof(int)) == 0;
}

int main() {
    char s1[] = "ab";
    char s2[] = "eidbaooo";
    cout << boolalpha << checkInclusion(s1, s2);
    return 0;
}









// Minimum Window Substring
#include <bits/stdc++.h>
using namespace std;

string minWindow(char s[], char t[]) {
    int sLen = strlen(s), tLen = strlen(t);
    if (sLen < tLen) return "";

    int countT[128] = {0}, countS[128] = {0};
    for (int i = 0; i < tLen; i++) {
        countT[t[i]]++;
    }

    int start = 0, minStart = 0, minLen = INT_MAX, matchCount = 0;
    for (int end = 0; end < sLen; end++) {
        char endChar = s[end];
        if (countT[endChar] == 0) continue;

        countS[endChar]++;
        if (countS[endChar] <= countT[endChar]) {
            matchCount++;
        }

        while (matchCount == tLen) {
            if (end - start + 1 < minLen) {
                minStart = start;
                minLen = end - start + 1;
            }
            char startChar = s[start];
            if (countT[startChar] == 0) {
                start++;
                continue;
            }
            if (countS[startChar] == countT[startChar]) {
                matchCount--;
            }
            countS[startChar]--;
            start++;
        }
    }

    return minLen == INT_MAX ? "" : string(s).substr(minStart, minLen);
}

int main() {
    char s[] = "ADOBECODEBANC";
    char t[] = "ABC";
    cout << "Minimum Window Substring: " << minWindow(s, t);
    return 0;
}









// Sliding Window Maximum
#include <bits/stdc++.h>
using namespace std;

void maxSlidingWindow(int nums[], int size, int k) {
    deque<int> dq;
    for (int i = 0; i < size; i++) {
        if (!dq.empty() && dq.front() == i - k) {
            dq.pop_front();
        }
        while (!dq.empty() && nums[dq.back()] <= nums[i]) {
            dq.pop_back();
        }
        dq.push_back(i);
        if (i >= k - 1) {
            cout << nums[dq.front()] << " ";
        }
    }
}

int main() {
    int nums[] = {1, 3, -1, -3, 5, 3, 6, 7};
    int size = sizeof(nums) / sizeof(nums[0]);
    int k = 3;
    maxSlidingWindow(nums, size, k);
    return 0;
}
