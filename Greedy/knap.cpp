/*Fractional Knapsack

You have n items; the i-th item has value val[i] and weight wt[i].

A knapsack can carry at most capacity units of weight.



You may take any fraction of an item (i.e. split items).

Return the maximum total value that can be placed in the knapsack, rounded to exactly 6 decimal places.

TC -->O(N+NlogN)
SC -->O(1)*/


#include<bits/stdc++.h>
using namespace std;

// Struct to represent an item with value and weight
struct Item {
    int value;
    int weight;
};

class Solution {
public:
    // Comparator function to sort items by value/weight ratio
    bool static comp(Item a, Item b) {
        double r1 = (double) a.value / (double) a.weight;
        double r2 = (double) b.value / (double) b.weight;
        return r1 > r2;  // Return true if the ratio of item a is greater than item b
    }

    // Function to calculate the maximum value we can get with fractional knapsack
    double fractionalKnapsack(int W, Item arr[], int n) {
        
        // Sort items based on the value/weight ratio
        sort(arr, arr + n, comp);

        int curWeight = 0;  // Current weight of knapsack
        double finalvalue = 0.0;  // Final value we can achieve

        // Iterate through the sorted items
        for (int i = 0; i < n; i++) {

            // If the current item can be fully added to the knapsack
            if (curWeight + arr[i].weight <= W) {
                curWeight += arr[i].weight;
                finalvalue += arr[i].value;  // Add the full value of the item
            } else {
                // If the current item can't be fully added, take the fractional part
                int remain = W - curWeight;
                finalvalue += (arr[i].value / (double) arr[i].weight) * (double) remain;
                break;  // Break as we have filled the knapsack
            }
        }

        return finalvalue;  // Return the maximum value that can be carried
    }
};

int main() {
    int n = 3, weight = 50;  // Number of items and capacity of knapsack
    // Item values and weights
    Item arr[n] = { {100,20},{60,10},{120,30} };
    Solution obj;

    // Calculate the maximum value we can get with the fractional knapsack
    double ans = obj.fractionalKnapsack(weight, arr, n);
    
    // Output the result
    cout << "The maximum value is " << setprecision(2) << fixed << ans;
    
    return 0;
}