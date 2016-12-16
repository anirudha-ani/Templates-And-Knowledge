#include <bits/stdc++.h>

using namespace std;

#define MAX 100005

int segment_tree_array[4*MAX];
int data[MAX];

void buildSegmentTree(int current_node , int data_start , int data_finish)
{
    if(data_start == data_finish)
    {
        segment_tree_array[current_node] = data[data_finish];
    }
    else
    {
        int data_mid = (data_start + data_finish) / 2 ;

        int left_node = current_node * 2 ;
        int right_node = current_node * 2 + 1 ;

        buildSegmentTree(left_node , data_start , data_mid);
        buildSegmentTree(right_node , data_mid + 1 , data_finish);

        segment_tree_array[current_node] = segment_tree_array[left_node] + segment_tree_array[right_node];
    }
}

int query(int current_node , int data_start , int data_finish , int query_start , int query_finish)
{
    if(data_start > query_finish || data_finish < query_start)
    {
        return 0 ;
    }
    else if(data_start >= query_start && data_finish <= query_finish)
    {
        return segment_tree_array[current_node];
    }
    else
    {
        int data_mid = (data_finish + data_start) / 2 ;

        int left_node = current_node * 2 ;
        int right_node = current_node * 2 + 1 ;

        int left_answer = query(left_node , data_start , data_mid , query_start , query_finish);
        int right_answer = query(right_node , data_mid + 1 , data_finish , query_start , query_finish);

        return left_answer + right_answer ;
    }
}

void update(int current_node , int data_start , int data_finish , int index , int value)
{
    if(index <data_start || index > data_finish)
    {
        return ;
    }
    else if(index == data_finish && data_finish == data_start)
    {
        segment_tree_array[current_node] += value;
        return ;
    }
    else
    {
        segment_tree_array[current_node] += value;

        int data_mid = (data_finish + data_start) / 2 ;

        int left_node = current_node * 2 ;
        int right_node = current_node * 2 + 1;

        if(index <= data_mid)
        {
            update(left_node , data_start , data_mid , index , value);
        }
        else
        {
            update(right_node , data_mid + 1 , data_finish , index , value);
        }
    }
}

int main()
{
    int T ;

    scanf("%d", &T);

    for(int test_case = 1 ; test_case <= T ; test_case++)
    {
        memset(data , 0 , sizeof(data));
        memset(segment_tree_array , 0 , sizeof(segment_tree_array));

        int n , q , root = 1 ;

        scanf("%d %d", &n , &q);

        for(int i = 1 ; i <= n ; i++)
        {
            scanf("%d", &data[i]);
        }

        buildSegmentTree(root , 1 , n);

        printf("Case %d:\n", test_case);

        for(int i = 0 ; i < q ; i++)
        {
            int query_no ;

            scanf("%d",  &query_no);

            switch(query_no)
            {
                int index , value , i , j ;
                case 1:
                    scanf("%d", &index);
                    index++;
                    printf("%d\n", data[index]);
                    update(root , 1 , n , index , -1*data[index]);
                    data[index] = 0;
                    break;
                case 2:
                    scanf("%d %d",&index , &value);
                    index++;
                    update(root , 1 , n , index , value);
                    data[index] += value ;
                    break;
                case 3:
                    scanf("%d %d", &i , &j);
                    i++;
                    j++;
                    printf("%d\n",query(root, 1 , n , i , j));
                    break;
            }
        }
    }
    return 0 ;
}
