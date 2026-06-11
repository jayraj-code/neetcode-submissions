class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        int left = 0, right = people.size() - 1, boats = 0; 
        sort(people.begin(), people.end());

        while (left <= right)
        {
            if (right == left)
            {
                boats++;
                break; 
            }

            if ( people[left] + people[right]  <= limit )
            {
                left++;
                right--;
                boats++;
            }
            else
            {
                right--;
                boats++; 
            }
        }
        return boats;
    }
};