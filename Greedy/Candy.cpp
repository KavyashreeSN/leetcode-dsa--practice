/*135.Candy

Level = Hard

There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.

You are giving candies to these children subjected to the following requirements:

Each child must have at least one candy.
Children with a higher rating get more candies than their neighbors.
Return the minimum number of candies you need to have to distribute the candies to the children.

 TC -->O(N)*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        if (n == 0) return 0;

        int sum = 1, i = 1;

        while (i < n) {
            if (ratings[i] == ratings[i - 1]) {
                sum = sum + 1;
                i++;
                continue;
            }

            int peak = 1;
            while (i < n && ratings[i] > ratings[i - 1]) {
                peak++;
                sum += peak;
                i++;
            }

            int down = 1;
            while (i < n && ratings[i] < ratings[i - 1]) {
                sum += down;
                i++;
                down++;
            }

            if (down > peak) {
                sum += (down - peak);
            }
        }

        return sum;
    }
};

int main() {
    int n;
    cout << "Enter number of children: ";
    cin >> n;

    vector<int> ratings(n);

    cout << "Enter ratings: ";
    for (int i = 0; i < n; i++) {
        cin >> ratings[i];
    }

    Solution obj;
    cout << "Minimum candies required: " << obj.candy(ratings) << endl;

    return 0;
}