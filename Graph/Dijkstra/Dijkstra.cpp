#include <bits/stdc++.h>

//Dijkstra Base Code
//IT is also a solution of - http://codeforces.com/contest/20/problem/C#
//Learned it from Tarongo Khan aka flash_7

using namespace std;

#define maxDistance 10000000000000000



struct nodeDistance
{
    int index ;
    int distance ;

    nodeDistance(int givenIndex , int givenDistance)
    {
        index = givenIndex;
        distance = givenDistance ;
    }

    bool operator < (const nodeDistance &another) const
    {
        return distance > another.distance;
    }
};


vector <nodeDistance> adjacencyList[100005] ;


int main()
{
    int n , m ;
    int node1 , node2 , distance;
    map <int  , int> found;

    scanf("%d %d", &n , &m);

    for(int i = 0 ; i < m ; i++)
    {
        scanf("%d %d %d", &node1 , &node2 , &distance);
        found[node1] = 1;
        found[node2] = 1;
        adjacencyList[node1].push_back(nodeDistance(node2 , distance));
        adjacencyList[node2].push_back(nodeDistance(node1 , distance));
    }

    long long int minDistance[100005];
    int updatedFrom[100005];

    for(int i = 0 ; i < 100005 ; i++)
    {
        minDistance[i] = maxDistance;
        updatedFrom[i] = i;
    }

    if(found[1] == 0 || found[n] == 0)
    {
        printf("-1\n");
    }
    else
    {
        priority_queue <nodeDistance> Dijkstra ;

        Dijkstra.push(nodeDistance(1, 0));
        minDistance[1] = 0;

        while(Dijkstra.empty() != true)
        {
            nodeDistance currentNode = Dijkstra.top();

            Dijkstra.pop();

            int adjacencyNodeNumbers = adjacencyList[currentNode.index].size();

            for(int i = 0 ; i < adjacencyNodeNumbers ; i++)
            {
                long long int newDistance = adjacencyList[currentNode.index][i].distance + minDistance[currentNode.index] ;
                long long int prevDis =  minDistance[adjacencyList[currentNode.index][i].index] ;
               // int x ;
                //cin  >> x ;
                if(newDistance < prevDis)
                {
                    minDistance[adjacencyList[currentNode.index][i].index] = adjacencyList[currentNode.index][i].distance + minDistance[currentNode.index] ;
                    updatedFrom[adjacencyList[currentNode.index][i].index] = currentNode.index;
                    Dijkstra.push(nodeDistance(adjacencyList[currentNode.index][i].index , minDistance[adjacencyList[currentNode.index][i].index]));
                }
            }
        }

        if(updatedFrom[n] == n && n != 1)
        {
            printf("-1\n");
        }
        else
        {
            vector<int> pathPrint;
            int currentNode = n;
            pathPrint.push_back(n);
            while(updatedFrom[currentNode] != 1)
            {
                pathPrint.push_back(updatedFrom[currentNode]);
                currentNode = updatedFrom[currentNode];
            }
            pathPrint.push_back(1);

            int length = pathPrint.size();

            for(int i = length-1 ; i >= 0 ; i--)
            {
                printf("%d" , pathPrint[i]);

                if(i != 0)
                {
                    printf(" ");
                }
            }
            printf("\n");
        }
    }

    return 0;
}
