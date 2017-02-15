#include <bits/stdc++.h>

using namespace std ;

#define INF 1000000000

int adjacency_matrix[500][500];
int T , N , M , start , finish , C ,B , D;

void initialize()
{
    memset(adjacency_matrix , 0 , sizeof(adjacency_matrix));
}

int FLOW()
{
    //int length = adjacency_list[source].size();

    int source = 0 ;

    queue <int> node_list ;
    queue <int> min_cost ;
    //queue <int> father ;

    int parent[500];
    bool visited[500];
    for(int i = 0 ; i < 500 ; i++)
    {
        parent[i] = i ;
        visited[i] = false ;
    }

    int minimum = 1000000000;

    node_list.push(source);
    min_cost.push(minimum);
    visited[source] = true ;
    bool found = false ;

    while(node_list.empty()!= true)
    {
        int current_node = node_list.front();
        int current_min_cost = min_cost.front();
        //out << current_node << " : " << current_node << endl ;
        //int current_father = father.front();


        node_list.pop();
        min_cost.pop();
        //father.pop();

        if(current_node == 2*N+1)
        {
            minimum = current_min_cost;
            found = true ;
        }

        for(int j = 0 ; j < 500 ; j++)
        {
            if(visited[j] != true && adjacency_matrix[current_node][j] > 0)
            {
                int mini = min(current_min_cost , adjacency_matrix[current_node][j]);

                node_list.push(j);
                min_cost.push(mini);
                parent[j] = current_node;
                visited[j] = true ;
            }
        }
    }
    if(found)
    {
        int nodes = 2*N+1;

        while(parent[nodes] != 0)
        {
            adjacency_matrix[parent[nodes]][nodes] -= minimum;
            adjacency_matrix[nodes][parent[nodes]] += minimum;
            nodes = parent[nodes];
        }
        adjacency_matrix[parent[nodes]][nodes] -= minimum;
        adjacency_matrix[nodes][parent[nodes]] += minimum;
        nodes = parent[nodes];
        return minimum;
    }
    else return 0 ;

}

int solve()
{
    initialize();
    scanf("%d", &N);

    for(int j = 1 ; j <= N ; j++)
    {
        scanf("%d" , &adjacency_matrix[j][N+j]);
    }

    scanf("%d", &M);

    for(int j = 0 ; j < M ; j++)
    {
        scanf("%d %d %d", &start , &finish , &C);

        adjacency_matrix[N+start][finish] = C ;
    }

    scanf("%d %d", &B , &D);

    for(int j = 0 ; j < B ; j++)
    {
        scanf("%d", &start);

        adjacency_matrix[0][start] = INF ;
    }
    for(int j = 0 ; j < D ; j++)
    {
        scanf("%d", &finish);

        adjacency_matrix[N+finish][2*N+1] = INF ;
    }

     int ans = 0 ;

    int flowing = FLOW();
    while(flowing!=0)
    {
        ans += flowing;
        flowing = FLOW();
    }
    return ans ;
}

int main()
{


    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
       printf("Case %d: %d\n" , i+1 , solve());
    }
    return 0;
}
