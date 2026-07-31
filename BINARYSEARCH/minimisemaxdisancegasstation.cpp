class Solution {
public:
    double minMaxDist(vector<int> &stations, int k) {

        int n = stations.size();

        if (n <= 1) return 0.0;

        vector<int> howMany(n - 1, 0);

        for (int gasStations = 0; gasStations < k; gasStations++) {

            long double maxSection = -1;
            int maxInd = -1;

            for (int i = 0; i < n - 1; i++) {

                long double diff = stations[i + 1] - stations[i];
                long double sectionLength = diff / (howMany[i] + 1);

                if (sectionLength > maxSection) {
                    maxSection = sectionLength;
                    maxInd = i;
                }
            }

            if (maxInd != -1)
                howMany[maxInd]++;
        }

        long double ans = 0;

        for (int i = 0; i < n - 1; i++) {
            long double diff = stations[i + 1] - stations[i];
            long double sectionLength = diff / (howMany[i] + 1);
            ans = max(ans, sectionLength);
        }

        return (double)ans;
    }
};