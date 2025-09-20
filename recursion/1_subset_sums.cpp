#include <bits/stdc++.h>
using namespace std;

void subset_sum(vector<int> array, int index, int sum, vector<int> &ans)
{
    if (index == array.size())
    {
        ans.push_back(sum);
        return;
    }

    // picking the element
    subset_sum(array, index + 1, sum + array[index], ans);

    // not picking the element
    subset_sum(array, index + 1, sum, ans);
}

void printArray(vector<int> array)
{
    for (int i : array)
    {
        cout << i << " ";
    }
    cout << endl;
}

int main()
{
    vector<int> array = {3, 1, 2};
    vector<int> ans;

    subset_sum(array, 0, 0, ans);

    sort(ans.begin(), ans.end());

    printArray(ans);

    return 0;
}