class MedianFinder {
public:

    // Left half → Max Heap
    priority_queue<int> left;

    // Right half → Min Heap
    priority_queue<int, vector<int>, greater<int>> right;

    MedianFinder() {
        
    }
    
    void addNum(int num) {

        // 1. Number ko correct heap mein daalo
        if (left.empty() || num <= left.top()) {
            left.push(num);
        }
        else {
            right.push(num);
        }

        // 2. Heaps ko balance karo

        // left mein 2 extra ho gaye
        if (left.size() > right.size() + 1) {
            right.push(left.top());
            left.pop();
        }

        // right mein left se zyada elements ho gaye
        if (right.size() > left.size()) {
            left.push(right.top());
            right.pop();
        }
    }
    
    double findMedian() {

        // Odd number of elements
        if (left.size() > right.size()) {
            return left.top();
        }

        // Even number of elements
        return (left.top() + right.top()) / 2.0;
    }
};