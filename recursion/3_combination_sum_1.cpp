#include <bits/stdc++.h>
using namespace std;

void combination_sum_1(vector<int> array, int index, int target, int sum, vector<int> temp, set<vector<int>> &ans)
{
    if (sum == target)
    {
        ans.insert(temp);
        return;
    }
    if (index == array.size())
    {
        return;
    }

    // picking
    temp.push_back(array[index]);
    combination_sum_1(array, index + 1, target, sum + array[index], temp, ans);

    // not picking
    temp.pop_back();
    combination_sum_1(array, index + 1, target, sum, temp, ans);
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

    vector<int> array = {2, 3, 6, 7};
    int target = 7;

    combination_sum_1(array, 0, target, 0, {}, ans);

    printSet(ans);

    return 0;
}