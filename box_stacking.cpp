#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Box {
    int length, width, height;

    Box(int l, int w, int h) : length(l), width(w), height(h) {}

    int baseArea() const {
        return length * width;
    }
};

// Comparison function to sort boxes by base area (non-increasing order)
bool compareBoxes(const Box& b1, const Box& b2) {
    return b1.baseArea() > b2.baseArea();
}

// Function to find the maximum height of stack
int maxStackHeight(vector<Box>& boxes) {
    int n = boxes.size();

    // Sort boxes by base area
    sort(boxes.begin(), boxes.end(), compareBoxes);

    // Initialize an array to store the maximum height at each index
    vector<int> maxHeight(n);

    // Each box alone is the initial height
    for (int i = 0; i < n; i++) {
        maxHeight[i] = boxes[i].height;
    }

    // Calculate the maximum stack height
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (boxes[i].length < boxes[j].length && boxes[i].width < boxes[j].width) {
                maxHeight[i] = max(maxHeight[i], maxHeight[j] + boxes[i].height);
            }
        }
    }

    // Find the overall maximum height
    return *max_element(maxHeight.begin(), maxHeight.end());
}

int main() {
    int n;
    cout << "Enter the number of boxes: ";
    cin >> n;

    vector<Box> boxes;

    cout << "Enter length, width, and height of each box:\n";
    for (int i = 0; i < n; i++) {
        int l, w, h;
        cin >> l >> w >> h;

        // Generate all rotations of the box
        boxes.emplace_back(l, w, h);
        boxes.emplace_back(w, h, l);
        boxes.emplace_back(h, l, w);
    }

    int result = maxStackHeight(boxes);
    cout << "The maximum height of the stack is: " << result << endl;

    return 0;
}
