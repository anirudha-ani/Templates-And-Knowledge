#include <bits/stdc++.h>

using namespace std ;

struct weight_type
{
    int weight ;
    int IQ;
    int index ;
};

struct IQ_type
{
    int IQ ;
    int weight ;
    int index ;
};

bool sortByWeight (weight_type x , weight_type y)
{
    if(x.weight == y.weight)
    {
        if(x.IQ == y.IQ)
            return x.index > y.index;
        else return (x.IQ < y.IQ);

    }

    return x.weight < y.weight;
}

bool sortByIQ(IQ_type x , IQ_type y)
{
    if(x.IQ == y.IQ)
    {
        if(x.weight == y.weight)
            return x.index < y.index;
        else return x.weight>y.weight;
        return x.index < y.index;
    }

    return x.IQ > y.IQ;
}

int memorization[2000][2000];


int main()
{
    int counter = 0 , WW , II;

    weight_type w ;
    IQ_type iq;


    vector <weight_type> weightData ;
    vector <IQ_type> iqData ;

    while(scanf("%d %d", &WW , &II) != EOF )
    {
        counter++;
        w.weight = WW ;
        w.index = counter ;
        w.IQ = II;
        iq.IQ = II ;
        iq.index = counter ;
        iq.weight = WW ;

        weightData.push_back(w);
        iqData.push_back(iq);

    }

    sort(weightData.begin() , weightData.end() , sortByWeight);
    sort(iqData.begin() , iqData.end() , sortByIQ);

    for(int i = 1 ; i <= counter ; i++)
    {
        for(int j = 1 ; j <= counter ; j++)
        {
            if(weightData[i-1].index == iqData[j-1].index)
            {
                memorization[i][j] = 1 + memorization[i-1][j-1];
            }
            else
            {
                memorization[i][j] = max(memorization[i-1][j] , memorization[i][j-1]);

            }
        }
    }

    printf("%d\n",memorization[counter][counter]);

    vector <int> answer;
    //vector <int> ans_w;
    //vector <int> ans_i  ;
    int ii = counter ;
    int jj = counter ;

    while(ii != 0 && jj != 0)
    {
        //cout << ii << "::" << jj << endl;
        if(memorization[ii][jj] == memorization[ii-1][jj])
        {
            ii = ii-1;
        }
        else if(memorization[ii][jj] == memorization[ii][jj-1])
        {
            jj = jj-1;
        }
        else
        {
            answer.push_back(iqData[jj-1].index);
            //ans_i.push_back(iqData[jj-1].IQ);
            //ans_w.push_back(weightData[ii-1].weight);
            ii = ii-1;
            jj = jj-1;
        }
    }
    reverse(answer.begin() , answer.end());
    //reverse(ans_i.begin() , ans_i.end());
    //reverse(ans_w.begin() , ans_w.end());

    int length = answer.size();

    for(int i = 0 ; i < length ; i++)
    {
        printf("%d\n", answer[i] );
    }
    return 0 ;
}
