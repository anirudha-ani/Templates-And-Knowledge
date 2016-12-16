//Problem Link - http://www.spoj.com/problems/GSS1/
/*
    Need to know how to find max sum of any subset from a given range using Segment Tree
*/

#include <bits/stdc++.h>
using namespace std;
int data[50005];

struct node
{
    int sum;
    int max_suffix;
    int max_prefix;
    int max_subset_sum;
};

node segment_tree_array[4*50005];

void buildSegmentTree(int current_node , int data_start , int data_finish)
{
    if(data_finish == data_start)
    {
        segment_tree_array[current_node].sum = data[data_start];
        segment_tree_array[current_node].max_suffix = data[data_start];
        segment_tree_array[current_node].max_prefix = data[data_start];
        segment_tree_array[current_node].max_subset_sum = data[data_start];
    }
    else
    {
        int data_mid = (data_start + data_finish) / 2;

        int left_node = 2*current_node;
        int right_node = 2*current_node + 1 ;

        buildSegmentTree(left_node , data_start , data_mid);
        buildSegmentTree(right_node , data_mid+1 , data_finish);

        segment_tree_array[current_node].sum = segment_tree_array[left_node].sum + segment_tree_array[right_node].sum;
        segment_tree_array[current_node].max_prefix = segment_tree_array[left_node].max_prefix > segment_tree_array[left_node].sum + segment_tree_array[right_node].max_prefix ? segment_tree_array[left_node].max_prefix : segment_tree_array[left_node].sum + segment_tree_array[right_node].max_prefix ;
        segment_tree_array[current_node].max_suffix = segment_tree_array[right_node].max_suffix > segment_tree_array[right_node].sum + segment_tree_array[left_node].max_suffix ? segment_tree_array[right_node].max_suffix : segment_tree_array[right_node].sum + segment_tree_array[left_node].max_suffix ;
        segment_tree_array[current_node].max_subset_sum = segment_tree_array[left_node].max_suffix + segment_tree_array[right_node].max_prefix > max(segment_tree_array[left_node].max_subset_sum , segment_tree_array[right_node].max_subset_sum) ? segment_tree_array[left_node].max_suffix + segment_tree_array[right_node].max_prefix : max(segment_tree_array[left_node].max_subset_sum , segment_tree_array[right_node].max_subset_sum);
    }
}

node query(int current_node , int data_start , int data_finish , int query_start , int query_finish)
{

    if(data_start > query_finish || data_finish < query_start)
    {
        node blankNode ;
        blankNode.max_prefix = -1000000;
        blankNode.max_subset_sum = -1000000;
        blankNode.sum = -1000000;
        blankNode.max_subset_sum = -1000000;
        return blankNode ;
    }
    else if(data_start >=query_start && data_finish <= query_finish)
    {
        return segment_tree_array[current_node];
    }
    else
    {
        int data_mid = (data_start + data_finish) / 2 ;

        int left_node = 2 * current_node ;
        int right_node = 2 * current_node + 1 ;

        node leftSide = query(left_node , data_start , data_mid , query_start , query_finish);
        node rightSide = query(right_node , data_mid + 1 , data_finish , query_start , query_finish);

        node answer_node ;

        answer_node.sum = leftSide.sum + rightSide.sum;
        answer_node.max_prefix = leftSide.max_prefix > leftSide.sum + rightSide.max_prefix ? leftSide.max_prefix : leftSide.sum + rightSide.max_prefix ;
        answer_node.max_suffix = rightSide.max_suffix > rightSide.sum + leftSide.max_suffix ? rightSide.max_suffix : rightSide.sum + leftSide.max_suffix ;
        answer_node.max_subset_sum = leftSide.max_suffix + rightSide.max_prefix > max(leftSide.max_subset_sum , rightSide.max_subset_sum) ? leftSide.max_suffix + rightSide.max_prefix : max(leftSide.max_subset_sum , rightSide.max_subset_sum);
        return answer_node;
    }

}
int main()
{
    int N , M , xi , yi ;

    scanf("%d" , &N);

    for(int i = 1 ; i <= N ; i++)
    {
        scanf("%d", &data[i]);
    }
    int root = 1 ;

    buildSegmentTree(root , 1 ,N);
    scanf("%d", &M);

    for(int i = 0 ; i < M ; i++)
    {
        scanf("%d %d", &xi , &yi);

        node answer_node = query(root , 1 , N , xi , yi);

        printf("%d\n", answer_node.max_subset_sum);
    }
    return 0 ;
}
