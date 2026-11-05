class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int count = n; 

        for (int i = 0; i < flowerbed.size(); i++)
        {
            if (flowerbed[i] == 0)
            {
                bool left_empty = (i == 0 || flowerbed[i - 1] == 0);
                bool right_empty = (i == flowerbed.size() - 1 || flowerbed[i + 1] == 0);

                if (left_empty && right_empty)
                {
                    count--;
                    flowerbed[i] = 1; 
                }
            }
        }

        return count <= 0; 
    }
};
