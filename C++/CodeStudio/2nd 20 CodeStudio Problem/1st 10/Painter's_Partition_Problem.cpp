#include <iostream>
#include <vector>
using namespace std;

bool isPossible(vector<int> &boards, int k, int mid) {
    int painterCount = 1;
    int boardSum = 0;
    int n = boards.size();

    for (int i = 0; i < n; i++)
    {
        if (boardSum + boards[i] <= mid)
        {
            boardSum += boards[i];
        }
        else{
            painterCount++;
            if (painterCount > k || boards[i] > mid)
            {
                return false;
            }
            boardSum = boards[i];
        }
        if(painterCount > k)
        {
            return false;
        }
    }
    return true;
}

int findLargestMinDistance(vector<int> &boards, int k) {
    int s = 0;
    int sum = 0;
    int n = boards.size();

    for (int i = 0; i < n; i++) {
        sum += boards[i];
    }

    int e = sum;
    int ans = -1;
    int mid = s + (e - s) / 2;

    while (s <= e)
    {
        if (isPossible(boards, k, mid))
        {
            ans = mid;
            e = mid - 1;
        }
        else {
            s = mid + 1;
        }
        mid = s + (e - s) / 2;
    }
    return ans;
}

int main() {
    vector<int> boards = {2, 1, 5, 6, 2, 3};
    int k = 2;

    int result = findLargestMinDistance(boards, k);
    cout << "The largest minimum distance is: " << result << endl;

    return 0;
}
