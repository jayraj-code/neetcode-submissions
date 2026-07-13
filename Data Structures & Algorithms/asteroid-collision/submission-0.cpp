class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> collision; 
        for (int i = 0; i < asteroids.size(); i++)
        {
            int curr = asteroids[i];
            bool survived = true; 
            while (!collision.empty() && curr < 0 && collision.top() > 0)
            {
                int top = collision.top(); 
                if (abs(top) == abs(curr))
                {
                    collision.pop(); 
                    survived = false; 
                    break; 
                }
                else if (abs(top) < abs(curr))
                {
                
                    collision.pop(); 
                }
                else
                {
                    survived = false; 
                    break;
                }

            }
            if (survived)
            {
                collision.push(curr); 
            }
        }

        vector<int> result; 
        while (!collision.empty())
        {
            result.push_back(collision.top());
            collision.pop(); 
        }

        reverse(result.begin(), result.end()); 
        return result; 
    }
};