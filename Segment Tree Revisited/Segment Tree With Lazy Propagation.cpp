#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

long long int  segment_tree_array[4*MAX];
long long int  propagate_array[4*MAX];
long long int  data[MAX];


long long int  query(long long int  current_node , long long int  data_start , long long int  data_finish , long long int  query_start , long long int  query_finish , long long int  propagate_value)
{
    if(data_start > query_finish || data_finish < query_start)
    {
        return 0 ;
    }
    else if(data_start >= query_start && data_finish <= query_finish)
    {
        return segment_tree_array[current_node] + propagate_value * (data_finish - data_start +1 );
    }
    else
    {
        long long int  data_mid = (data_finish + data_start) / 2 ;

        long long int  left_node = current_node * 2 ;
        long long int  right_node = current_node * 2 + 1 ;

        long long int  left_answer = query(left_node , data_start , data_mid , query_start , query_finish , propagate_value + propagate_array[current_node]);
        long long int  right_answer = query(right_node , data_mid + 1 , data_finish , query_start , query_finish , propagate_value + propagate_array[current_node]);

        return left_answer + right_answer ;
    }
}

void update(long long int  current_node , long long int  data_start , long long int  data_finish , long long int  index_start , long long int  index_finish , long long int  value)
{
    if(data_start > index_finish || data_finish < index_start)
    {
        return  ;
    }
    else if(data_start >= index_start && data_finish <= index_finish)
    {
        segment_tree_array[current_node] += (data_finish - data_start + 1) * value;
        propagate_array[current_node] += value;
        return ;
    }
    else
    {


        long long int  data_mid = (data_finish + data_start) / 2 ;

        long long int  left_node = current_node * 2 ;
        long long int  right_node = current_node * 2 + 1;


        update(left_node , data_start , data_mid , index_start , index_finish , value);

        update(right_node , data_mid + 1 , data_finish , index_start ,index_finish , value);

        segment_tree_array[current_node] = segment_tree_array[left_node] + segment_tree_array[right_node] + (data_finish - data_start + 1) * propagate_array[current_node];
    }
}


int  main()
{
    long long int  T , C , N , p , q , v , command;

    scanf("%lld" , &T);

    for(long long int  i = 0 ; i < T ; i++)
    {
        scanf("%lld %lld", &N , &C);

        memset(segment_tree_array , 0 , sizeof(segment_tree_array));
        memset(propagate_array , 0 , sizeof(propagate_array));
        memset(data, 0 , sizeof(data));

        for(long long int  i = 0 ; i < C ; i++)
        {
            scanf("%lld", &command);

            if(command == 0)
            {
                scanf("%lld %lld %lld", &p , &q , &v);
                update(1 , 1 , N , p , q , v);
            }
            else
            {
                scanf("%lld %lld", &p , &q);
                printf("%lld\n", query(1 , 1 , N , p , q , 0));
            }
        }
    }
    return 0 ;
}
