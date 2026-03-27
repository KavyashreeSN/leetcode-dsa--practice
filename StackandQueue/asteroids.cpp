/*Asteroid Collision

We are given an array asteroids of integers representing asteroids in a row. The indices of the asteroid in the array represent their relative position in space.

For each asteroid, the absolute value represents its size, and the sign represents its direction (positive meaning right, negative meaning left). Each asteroid moves at the same speed.

Find out the state of the asteroids after all collisions. If two asteroids meet, the smaller one will explode. If both are the same size, both will explode. Two asteroids moving in the same direction will never meet.

 TC -->O(2N)
 SC -->O(N)*/



#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> st;

        for (int i = 0; i < asteroids.size(); i++) {
            if (asteroids[i] > 0) {
                st.push_back(asteroids[i]);
            } 
            else {
                while (!st.empty() && st.back() > 0 && st.back() < abs(asteroids[i])) {
                    st.pop_back();
                }

                if (!st.empty() && st.back() == abs(asteroids[i])) {
                    st.pop_back();
                }
                else if (st.empty() || st.back() < 0) {
                    st.push_back(asteroids[i]);
                }
                
            }
        }

        return st;
    }
};

int main() {
    Solution obj;
    vector<int> asteroids = {10, 2, -5};
    vector<int> result = obj.asteroidCollision(asteroids);

    for (int x : result) cout << x << " ";
}