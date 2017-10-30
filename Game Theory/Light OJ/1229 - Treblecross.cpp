#include <bits/stdc++.h>

using namespace std ;

int grundy[300];
int calculate_grundy(int number)
{
    if(grundy[number] != -1)
    {
        return grundy[number];
    }

    number--;

    set <int> MEX_SET ;

    for(int i = 1 ; i <= number/2 ; i++)
    {
        MEX_SET.insert(calculate_grundy(i) ^ calculate_grundy(number - i)) ;
    }
    for(int j = 0 ; j <= number ; j++ )
    {
        if(MEX_SET.find(j) == MEX_SET.end())
        {
            grundy[number] = j;
            return j;
        }
    }
}

int main()
{
    int test_case ;
    string input ;

    memset(grundy , -1 , sizeof(grundy));

    grundy[1] = 0 ;
    grundy[2] = 0 ;
    grundy[3] = 0 ;
    grundy[4] = 0 ;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        cin >> input ;

        int length = input.length() , counter = 0 , nim_sum = 0;
        vector <int> moves ;
        for(int j = 0 ; j < length ; j++)
        {
            int counter = 0 ;
            if(input[j] == '.')
            {
                //cout << "ASDASD" << endl;
                int k = j;
                while(k-1 >= 0 && input[k-1] == 'X')
                {
                    k--;
                    counter++;
                }
                k = j;
                while(k+1 < length && input[k+1] == 'X')
                {
                    k++;
                    counter++;
                }
                if(counter >= 2)
                {
                    moves.push_back(j+1);
                    //cout << " HERE " << endl ;
                }
                counter = 0 ;
            }



        }
        int sizes = moves.size();

        if(sizes != 0)
        {


            for(int j = 0 ; j < sizes ; j++)
            {
                printf("%d",moves[j]);

                if(j != sizes-1)
                {
                    printf(" ");
                }
                else
                {
                    printf("\n");
                }
            }
            continue;
        }


//        if(input[0]!='X')
//        {
//            counter += 2;
//        }
//
//        for(int j = 0 ; j < length ; j++)
//        {
//            if(input[j] == '.')
//            {
//                counter++;
//            }
//            else
//            {
//                nim_sum ^= (calculate_grundy(counter));
//                counter=0;
//            }
//        }
//        if(counter != 0)
//        {
//            nim_sum ^= (calculate_grundy(counter+2));
//        }
//
//        if(nim_sum == 0)

    }
    return 0;
}
