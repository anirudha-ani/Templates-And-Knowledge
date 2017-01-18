#include <bits/stdc++.h>

using namespace std;

//Tarif Ezaz taught me this . Contest link - https://vjudge.net/contest/103847#overview

void update(vector<int> *data ,  int index ,int value)
{
    while(index < data->size())
    {
        data->at(index) += value;
        index += ((index) & (-index));
    }
}

int query(vector <int> *data , int index)
{
    int sum  = 0;
    while(index > 0)
    {
        sum += data->at(index);
        index -= ((index) & (-index));
    }
    return sum;
}

int main()
{
    return 0;
}
