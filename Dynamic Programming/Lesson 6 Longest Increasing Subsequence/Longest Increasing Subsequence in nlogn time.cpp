/**
    Base code for Longest Increasing Subsequence in O(N * logN) time
    Also a solution of - https://www.hackerrank.com/challenges/longest-increasing-subsequent
    Learning Material - https://www.youtube.com/watch?v=S9oUiVYEq7E
**/

#include <bits/stdc++.h>

using namespace std;

int lastIndexOfLISlength[1000005];
int thisIndexComingFrom[1000005];
vector <int> dataSet;
int number_of_elements , input ;


int main()
{



    scanf("%d" , &number_of_elements);

    for(int i = 0 ; i < number_of_elements ; i++)
    {
        scanf("%d", &input);
        dataSet.push_back(input);
    }
    if(number_of_elements == 0 )
    {
        printf("0\n");
        return 0;
    }
    else if(number_of_elements == 1)
    {
        printf("1\n");
        return 0 ;
    }
    memset(thisIndexComingFrom , -1 , sizeof(thisIndexComingFrom));
    lastIndexOfLISlength[1] = 0 ;
    thisIndexComingFrom[1] = -1 ;

    int currentMaxLISlength = 1 ;

    for(int i = 1 ; i < number_of_elements ; i++)
    {
        //cout << "Current data = " << dataSet[i] << " Current Max Length = " << currentMaxLISlength << " Current last data of Max Length = " << dataSet[lastIndexOfLISlength[currentMaxLISlength]] << endl ;
        if(dataSet[i] < dataSet[lastIndexOfLISlength[1]])
        {
            lastIndexOfLISlength[1] = i ;
        }
        else if(dataSet[i] > dataSet[lastIndexOfLISlength[currentMaxLISlength]])
        {
            currentMaxLISlength++;
            lastIndexOfLISlength[currentMaxLISlength] = i;
            thisIndexComingFrom[i] = lastIndexOfLISlength[currentMaxLISlength-1];
        }
        else
        {


                int start = 1 ;
                int finish = currentMaxLISlength -1;
                //int len = finish ;
                //cout << "h" << endl ;
                int mid  = start ;
                int counter = 0 ;
                while(start <= finish && counter < 100)
                {

                    mid = (start + finish ) / 2 ;
                    //cout << mid << endl ;

                    if(dataSet[i] > dataSet[lastIndexOfLISlength[mid]] && dataSet[i] < dataSet[lastIndexOfLISlength[mid + 1]])
                    {
                        mid = mid + 1 ;
                        break;
                    }
                    if(dataSet[i] > dataSet[lastIndexOfLISlength[mid]])
                    {
                        start = mid + 1 ;
                    }
                    else
                    {
                        finish = mid ;
                    }
                    counter++ ;
                }
                lastIndexOfLISlength[mid] = i ;
                thisIndexComingFrom[i] = lastIndexOfLISlength[mid-1];
                //cout << "ASD" << endl ;
        }
    }

    /**
    FOR PRINTING USE THIS . IT will print LIS in reverse

//    int printIndex = lastIndexOfLISlength[currentMaxLISlength];
//
//    while(printIndex != -1)
//    {
//        printf("%d " , dataSet[printIndex]);
//        printIndex = thisIndexComingFrom[printIndex];
//    }

    **/

    printf("%d\n",currentMaxLISlength);

    return 0 ;
}
