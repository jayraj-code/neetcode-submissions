class TimeMap {
public:
    unordered_map<string, vector<pair<int, string>>> mp;

    TimeMap() {

    }

    void set(string key, string value, int timestamp) {
        mp[key].push_back({timestamp, value});
    }

    string get(string key, int timestamp) {

        if (mp.find(key) == mp.end())
            return "";

        vector<pair<int, string>>& values = mp[key];

        int left = 0;
        int right = values.size() - 1;
        int answer = -1;

        while (left <= right) {
            int mid = left + (right - left) / 2;

            if (values[mid].first <= timestamp) {
                answer = mid;
                left = mid + 1;
            } else {
                right = mid - 1;
            }
        }

        if (answer == -1)
            return "";

        return values[answer].second;
    }
};