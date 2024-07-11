#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

void bucketSort(vector<int>& arr) {
    int n = arr.size();
    int max_val = *max_element(arr.begin(), arr.end());
    int min_val = *min_element(arr.begin(), arr.end());
    int bucket_range = (max_val - min_val) / n + 1;
    vector<vector<int>> buckets(n);
    for (int i = 0; i < n; ++i) {
        int bucket_index = (arr[i] - min_val) / bucket_range;
        buckets[bucket_index].push_back(arr[i]);
    }
        for (int i = 0; i < n; ++i)
    {
        sort(buckets[i].begin(), buckets[i].end());
    }
    int index = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < buckets[i].size(); ++j)
        {
            arr[index++] = buckets[i][j];
        }
    }
   }

int main() {
    srand(time(NULL));
    int n = 1 + rand() % 10;
    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        arr[i] = rand() % 100;
    }
    cout << "Before: ";
    for (int i = 0; i < arr.size(); i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    bucketSort(arr);
    cout << "After: ";
    for (int i = 0; i < arr.size(); i++) {
        cout << arr[i] << " ";
    }
    return 0;
}

