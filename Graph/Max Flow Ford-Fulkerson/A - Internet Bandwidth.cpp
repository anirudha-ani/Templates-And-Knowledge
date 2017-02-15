#include <bits/stdc++.h>

using namespace std ;

int adjacency_matrix[105][105];
//int reverse_edge[105][105];
//vector <int> adjacency_list[105];
int s , t , c , node1 , node2 , capacity;
int N;
int T ;

int BFS(int source)
{
    //int length = adjacency_list[source].size();


    queue <int> node_list ;
    queue <int> min_cost ;
    //queue <int> father ;

    int parent[105];
    bool visited[105];
    for(int i = 0 ; i < 105 ; i++)
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

        if(current_node == t)
        {
            minimum = current_min_cost;
            found = true ;
        }

        for(int j = 0 ; j < 105 ; j++)
        {
            //cout << adjacency_matrix[current_node][j] << endl ;
            if(visited[j] != true && adjacency_matrix[current_node][j] > 0)
            {
                int mini = min(current_min_cost , adjacency_matrix[current_node][j]);

                node_list.push(j);
                min_cost.push(mini);
                parent[j] = current_node;
                visited[j] = true ;
                //father.push(current_father);
            }
        }
    }
   // cout << minimum << endl ;
    if(found)
    {
        int nodes = t;

        while(parent[nodes] != s)
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

int main()
{


    scanf("%d", &T);

    for(int i = 0 ; i < T ; i++)
    {
        memset(adjacency_matrix , 0 , sizeof(adjacency_matrix));

        scanf("%d", &N);

        scanf("%d %d %d", &s , &t , &c);

        for(int j = 0 ; j < c ; j++)
        {
            scanf("%d %d %d", &node1 , &node2 , &capacity);

            adjacency_matrix[node1][node2] += capacity;
            adjacency_matrix[node2][node1] += capacity;

            //adjacency_list[node1].push_back(node2);
            //adjacency_list[node2].push_back(node1);
        }

        int ans = 0 ;

        int flowing = BFS(s);
        while(flowing!=0)
        {
            //cout << flowing
            ans += flowing;
            flowing = BFS(s);
        }

        printf("Case %d: %d\n",i+1, ans);
    }
    return 0 ;
}
