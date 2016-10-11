/**
Knuth Morris Pratt aka KMP Algorithm

Thanks to - Raihat Zaman Niloy from Jahangirnagar University for teaching this awesome algorithm

And also thanks to Tushar Roy from youtube

Resource -

Part 1 - https://www.youtube.com/watch?v=GTJr8OvyEVQ
Part 2 - https://www.youtube.com/watch?v=KG44VoDtsAA

What does this algorithm do ?

- This algorithm takes a particular range of a string from the starting index and tells what is the highest
length of Suffix which is matched with the Prefix within this range

**/

#include <bits/stdc++.h>

using namespace std;

void buildingTemporarySubArray(string input_String , int KMP_Number[])
{
    int length = input_String.length();

    int i = 0 , j = 1 ;

    KMP_Number[0] = 0;

    while(j != length)
    {
        if(input_String[i] == input_String[j])
        {
            KMP_Number[j] = i + 1;
            i++;
            j++;

        }
        else if (i == 0)
        {
            KMP_Number[j] = 0;
            j++;

        }
        else
        {
            i = KMP_Number[i-1];

        }
    }
}

int matchCounter(string mainString , string patternString)
{
    int counter = 0 ;

    int mainString_length = mainString.length();
    int patternString_length = patternString.length();

    int KMP_Number[100000];

    buildingTemporarySubArray(patternString , KMP_Number);

    int i = 0 , j = 0 ;

    while(i != mainString_length)
    {
        if(patternString[j] == mainString[i])
        {
            i++;
            j++;


            if(j == patternString_length)
            {
                counter++;
                j = KMP_Number[j - 1];
            }
        }
        else if(j == 0)
        {
            i++;
        }
        else
        {
            j = KMP_Number[j - 1];
        }
    }

    return counter ;
}

int main()
{
    ios::sync_with_stdio(false);

    string mainString ,  patternString;

    getline(cin , mainString);
    getline(cin , patternString);

    cout << matchCounter(mainString , patternString);
    return 0 ;
}
