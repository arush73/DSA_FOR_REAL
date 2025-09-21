#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string s, int start, int end)
{
    while (start <= end)
    {
        if (s[start] != s[end])
            return false;
        start++;
        end--;
    }
    return true;
}

void partition(string s, int index, vector<vector<string>> &ans, vector<string> &temp)
{
    if (index == s.length())
    {
        ans.push_back(temp);
        return;
    }

    for (int i = index; i < s.length(); ++i)
    {
        if (isPalindrome(s, index, i))
        {
            temp.push_back(s.substr(index, i - index + 1));
            partition(s, i + 1, ans, temp);
            temp.pop_back();
        }
    }
}

void printString(vector<string> &array)
{
    cout << "[ ";
    for (string &i : array)
    {
        cout << i << " ";
    }
    cout << "]";
}

void printAns(vector<vector<string>> &ans)
{
    for (auto &i : ans)
    {
        printString(i);
        cout << endl;
    }
}

int main()
{
    string a = "aab";
    string b = "aabb";

    vector<vector<string>> ans1;
    vector<vector<string>> ans2;
    vector<string> temp1;
    vector<string> temp2;

    cout << "Answer for 'aab': " << endl;
    partition(a, 0, ans1, temp1);
    printAns(ans1);

    cout << "\nAnswer for 'aabb': " << endl;
    partition(b, 0, ans2, temp2);
    printAns(ans2);

    return 0;
}
