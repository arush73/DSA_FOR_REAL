#include <bits/stdc++.h>
using namespace std;

void combination_sum_2(vector<int> array, int index, int target, set<vector<int>> &ans, vector<int> temp)
{
    if (target == 0)
    {
        ans.insert(temp);
        return;
    }

    for (int i = index; i < array.size(); i++)
    {
        if (i > index && array[i] == array[i - 1])
        {
            continue;
        }
        if (array[i] > target)
        {

            break;
        }

        temp.push_back(array[index]);
        combination_sum_2(array, index + 1, target - array[i], ans, temp);
        temp.pop_back();
    }
}

void printArray(vector<int> array)
{
    cout << "[ ";
    for (int i : array)
    {
        cout << i << " ";
    }
    cout << "]";
}

void printSet(set<vector<int>> ans)
{
    for (auto i : ans)
    {
        printArray(i);
    }
    cout << endl;
}

int main()
{
    vector<int> array = {10, 1, 2, 7, 6, 1, 5};
    sort(array.begin(), array.end());

    set<vector<int>> ans;

    int target = 8;

    combination_sum_2(array, 0, target, ans, {});
    cout << "The answer is: " << endl;
    printSet(ans);
    return 0;
}