class Solution {
	public:
	bool canweplace(vector<int> &arr, int dist, int k) {
		int cntCows = 1, last = arr[0];
		for (int i = 1; i<arr.size(); i++) {
			if (arr[i] - last >= dist) {
				cntCows++;
				last = arr[i];
			}
			if (cntCows >= k){
				return true;
			}
		}
		return false;
	}
	int aggressiveCows(vector<int> &arr, int k) {
		// code here
		sort(arr.begin(), arr.end());
		int n = arr.size();
		int low = 1;
		int high = arr[n - 1] - arr[0];
		while (low <= high) {
			int mid = (low + high)/2;
			if (canweplace(arr, mid, k) = = true) {
				low = mid + 1;
			}
			else {
				high = mid - 1;
			}
		}
		return high;
		
	}
};
