#include <bits/stdc++.h>
using namespace std ;

#define INF 1000000000
double eps = numeric_limits<double>::epsilon();

int t ;
int N  , n , m , x , y;
double D;
int FLOW[205][205];
int temp_flow[205][205];
vector <int> graph[205];

struct ice
{
    int index ;
    int x ;
    int y ;
    int currently_in ;
    int capacity ;
}data[105];

int flow(int destination);

int calculateFlow(int source , int destination)
{
    memcpy(temp_flow , FLOW , sizeof(FLOW));

    int total_flow = 0 ;

    int current_flow = flow(destination);
    while(current_flow !=0)
    {
        total_flow += current_flow ;
        current_flow = flow(destination);
    }
    return total_flow;
}

int flow(int destination)
{
    queue <int> node_list ;
    queue <int> min_cost ;
    //queue <int> father ;

    int parent[205];
    bool visited[205];
    for(int i = 0 ; i < 205 ; i++)
    {
        parent[i] = i ;
        visited[i] = false ;
    }

    int minimum = 1000000000;

    node_list.push(0);
    min_cost.push(minimum);
    visited[0] = true ;
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

        if(current_node == destination)
        {
            minimum = current_min_cost;
            found = true ;
            break ;
        }

        int length = graph[current_node].size();

        for(int j = 0 ; j < length ; j++)
        {
            //cout << adjacency_matrix[current_node][j] << endl ;
            int current_connection = graph[current_node][j];

            if(visited[current_connection] != true && temp_flow[current_node][current_connection] > 0)
            {
                int mini = min(current_min_cost , temp_flow[current_node][current_connection]);

                node_list.push(current_connection);
                min_cost.push(mini);
                parent[current_connection] = current_node;
                visited[current_connection] = true ;
                //father.push(current_father);
            }
        }
    }
   // cout << minimum << endl ;
    if(found)
    {
        int nodes = destination;

        while(parent[nodes] != 0)
        {
            temp_flow[parent[nodes]][nodes] -= minimum;
            temp_flow[nodes][parent[nodes]] += minimum;
            nodes = parent[nodes];
        }
        temp_flow[parent[nodes]][nodes] -= minimum;
        temp_flow[nodes][parent[nodes]] += minimum;
        nodes = parent[nodes];
        return minimum;
    }
    else return 0 ;
}

int main()
{
    //freopen("output.txt" , "w" , stdout);
    //cout << numeric_limits<double>::epsilon() << endl ;
    scanf("%d", &t);

    for(int i = 0 ; i < t ; i++)
    {
        memset(FLOW , 0 , sizeof(FLOW));


        scanf("%d %lf", &N , &D);
        int total = 0 ;
        graph[0].clear();
        for(int j = 1 ; j <= N ; j++)
        {
            graph[j].clear();
            scanf("%d %d %d %d", &x , &y , &n , &m);

            data[j].x = x ;
            data[j].y = y ;
            data[j].currently_in = n ;
            data[j].capacity = m ;
            data[j].index = j;

            total += n ;
        }

        for(int j = 1 ; j <= N ; j++)
        {
            for(int k = 1 ; k <= N ; k++)
            {
                if(j!=k)
                {
                    if(sqrt((data[j].x - data[k].x)*(data[j].x - data[k].x) + (data[j].y - data[k].y)*(data[j].y - data[k].y) ) <= D)
                    {
                        graph[100+j].push_back(k);
                        graph[k].push_back(100+j);

                        FLOW[100+j][k] = INF;
                    }
                }
            }

            FLOW[j][100+j] = data[j].capacity;
            FLOW[0][j] = data[j].currently_in;

            graph[j].push_back(100+j);
            graph[100+j].push_back(j);
            graph[0].push_back(j);
            graph[j].push_back(0);


        }
        printf("Case %d:" , i+1);
        bool found = false ;
        for(int k = 1 ; k <= N ; k++)
        {
            if(calculateFlow(0 , k) == total)
            {
                found = true ;
                printf(" %d", k-1 );
            }
        }
        if(!found)
        {
            printf(" -1");
        }
        printf("\n");

    }
    return 0 ;
}
