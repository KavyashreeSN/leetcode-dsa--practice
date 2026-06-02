/*1423.Maximum Points You can Obtain From Cards

There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.

In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.

Your score is the sum of the points of the cards you have taken.

Given the integer array cardPoints and the integer k, return the maximum score you can obtain.

TC -->O(2*k)
SC -->O(1)*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int lsum = 0, rsum = 0, maxsum = 0;

        for (int i = 0; i < k; i++) {
            lsum += cardPoints[i];
        }

        maxsum = lsum;
        int rindex = cardPoints.size() - 1;

        for (int i = k - 1; i >= 0; i--) {
            lsum -= cardPoints[i];
            rsum += cardPoints[rindex];
            rindex--;

            maxsum = max(maxsum, lsum + rsum);
        }

        return maxsum;
    }
};

int main() {
    int n, k;

    cout << "Enter number of cards: ";
    cin >> n;

    vector<int> cardPoints(n);

    cout << "Enter card points: ";
    for (int i = 0; i < n; i++) {
        cin >> cardPoints[i];
    }

    cout << "Enter k: ";
    cin >> k;

    Solution obj;
    cout << "Maximum Score = " << obj.maxScore(cardPoints, k) << endl;

    return 0;
}