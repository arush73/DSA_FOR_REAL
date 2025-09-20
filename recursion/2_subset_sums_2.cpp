#include <bits/stdc++.h>
using namespace std;

void subset_sum_2(vector<int> array, int index, set<vector<int>> &ans, vector<int> temp)
{
    if (index == array.size())
    {
        sort(temp.begin(), temp.end());
        ans.insert(temp);
        return;
    }

    // picking this time
    temp.push_back(array[index]);
    subset_sum_2(array, index + 1, ans, temp);

    // not picking this time
    temp.pop_back();
    subset_sum_2(array, index + 1, ans, temp);
}

void printArray(vector<int> array)
{
    for (int i : array)
    {
        cout << i << " ";
    }
}

void printSet(set<vector<int>> arr)
{
    for (vector<int> i : arr)
    {
        cout << "[ ";
        printArray(i);
        cout << "]";
    }
}

int main()
{
    set<vector<int>> ans;
    vector<int> array = {1, 2, 2};

    subset_sum_2(array, 0, ans, {});

    printSet(ans);
    return 0;
}