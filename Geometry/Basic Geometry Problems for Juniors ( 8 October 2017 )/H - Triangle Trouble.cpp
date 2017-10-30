#include <bits/stdc++.h>

using namespace std ;

int main()
{
    int test_case , no_of_data ;

    scanf("%d", &test_case);

    for(int i = 0 ; i < test_case ; i++)
    {
        scanf("%d", &no_of_data);

        vector <double> data_set ;
        double max_area = 0.0 , input;

        for(int j = 0 ; j < no_of_data ; j++)
        {
            scanf("%lf", &input);

            data_set.push_back(input);
        }

        sort(data_set.begin() , data_set.end());

        for(int j = 0 ; j < no_of_data - 2 ; j++)
        {
            if(data_set[j] + data_set[j+1] > data_set[j+2])
            {
                double s = (data_set[j] + data_set[j+1] + data_set[j+2])/2.0;

                double area = sqrt(s * (s-data_set[j]) * (s - data_set[j+1]) * (s - data_set[j+2]));

                max_area = max(max_area , area);
            }
        }

        printf("%.2f\n", max_area);
    }
}
