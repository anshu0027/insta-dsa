// Valid Parentheses
#include <bits/stdc++.h>
using namespace std;

bool isValid(string s) {
    char stack[1000];
    int top = -1;
    
    for (char c : s) {
        if (c == '(' || c == '{' || c == '[') {
            stack[++top] = c;
        } else {
            if (top == -1) return false;
            char topChar = stack[top--];
            if ((c == ')' && topChar != '(') || 
                (c == '}' && topChar != '{') || 
                (c == ']' && topChar != '[')) {
                return false;
            }
        }
    }
    
    return top == -1;
}

int main() {
    string s = "({[]})";
    cout << boolalpha << isValid(s);
    return 0;
}





// Min Stack
#include <bits/stdc++.h>
using namespace std;

class MinStack {
    int stack[1000];
    int minStack[1000];
    int top;
    int minTop;

public:
    MinStack() : top(-1), minTop(-1) {}

    void push(int val) {
        stack[++top] = val;
        if (minTop == -1 || val <= minStack[minTop]) {
            minStack[++minTop] = val;
        }
    }

    void pop() {
        if (stack[top] == minStack[minTop]) {
            --minTop;
        }
        --top;
    }

    int topElement() {
        return stack[top];
    }

    int getMin() {
        return minStack[minTop];
    }
};

int main() {
    MinStack minStack;
    minStack.push(-2);
    minStack.push(0);
    minStack.push(-3);
    cout << minStack.getMin() << endl;
    minStack.pop();
    cout << minStack.topElement() << endl;
    cout << minStack.getMin() << endl;
    return 0;
}





// Evaluate Reverse Polish Notation
#include <bits/stdc++.h>
using namespace std;

int evalRPN(string tokens[], int size) {
    int stack[1000];
    int top = -1;
    
    for (int i = 0; i < size; i++) {
        string token = tokens[i];
        if (token == "+" || token == "-" || token == "*" || token == "/") {
            int b = stack[top--];
            int a = stack[top--];
            if (token == "+") stack[++top] = a + b;
            else if (token == "-") stack[++top] = a - b;
            else if (token == "*") stack[++top] = a * b;
            else stack[++top] = a / b;
        } else {
            stack[++top] = stoi(token);
        }
    }
    
    return stack[top];
}

int main() {
    string tokens[] = {"2", "1", "+", "3", "*"};
    cout << evalRPN(tokens, 5);
    return 0;
}





// Generate Parentheses
#include <bits/stdc++.h>
using namespace std;

void generateParenthesis(int n, int open, int close, string s, string result[], int &index) {
    if (open == n && close == n) {
        result[index++] = s;
        return;
    }

    if (open < n) {
        generateParenthesis(n, open + 1, close, s + "(", result, index);
    }

    if (close < open) {
        generateParenthesis(n, open, close + 1, s + ")", result, index);
    }
}

int main() {
    int n = 3;
    string result[1000];
    int index = 0;
    generateParenthesis(n, 0, 0, "", result, index);

    for (int i = 0; i < index; i++) {
        cout << result[i] << endl;
    }
    return 0;
}





// Daily Temperatures
#include <bits/stdc++.h>
using namespace std;

void dailyTemperatures(int temperatures[], int size, int result[]) {
    int stack[1000];
    int top = -1;
    
    for (int i = size - 1; i >= 0; i--) {
        while (top != -1 && temperatures[stack[top]] <= temperatures[i]) {
            --top;
        }
        result[i] = (top == -1) ? 0 : stack[top] - i;
        stack[++top] = i;
    }
}

int main() {
    int temperatures[] = {73, 74, 75, 71, 69, 72, 76, 73};
    int size = sizeof(temperatures) / sizeof(temperatures[0]);
    int result[1000];
    dailyTemperatures(temperatures, size, result);

    for (int i = 0; i < size; i++) {
        cout << result[i] << " ";
    }
    return 0;
}





// Car Fleet
#include <bits/stdc++.h>
using namespace std;

int carFleet(int target, int position[], int speed[], int size) {
    pair<int, double> cars[1000];

    for (int i = 0; i < size; i++) {
        cars[i] = {position[i], (double)(target - position[i]) / speed[i]};
    }

    sort(cars, cars + size);

    int fleets = 0;
    double lastTime = 0.0;

    for (int i = size - 1; i >= 0; i--) {
        if (cars[i].second > lastTime) {
            lastTime = cars[i].second;
            fleets++;
        }
    }

    return fleets;
}

int main() {
    int target = 12;
    int position[] = {10, 8, 0, 5, 3};
    int speed[] = {2, 4, 1, 1, 3};
    cout << carFleet(target, position, speed, 5);
    return 0;
}





// Largest Rectangle In Histogram
#include <bits/stdc++.h>
using namespace std;

int largestRectangleArea(int heights[], int size) {
    int maxArea = 0;
    int stack[1000];
    int top = -1;

    for (int i = 0; i <= size; i++) {
        int h = (i == size) ? 0 : heights[i];
        while (top != -1 && h < heights[stack[top]]) {
            int height = heights[stack[top--]];
            int width = (top == -1) ? i : i - stack[top] - 1;
            maxArea = max(maxArea, height * width);
        }
        stack[++top] = i;
    }

    return maxArea;
}

int main() {
    int heights[] = {2, 1, 5, 6, 2, 3};
    int size = sizeof(heights) / sizeof(heights[0]);
    cout << largestRectangleArea(heights, size);
    return 0;
}
