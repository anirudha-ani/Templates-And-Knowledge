#include <bits/stdc++.h>

using namespace std;


#define PI acos(-1.0)
#define bigPrime1 743
#define bigPrime2 751
struct point
{
    long long int x;
    long long int y;

    point(long long int given_x , long long int given_y)
    {
        x = given_x;
        y = given_y;
    }

    point()
    {
        x = 0;
        y = 0;
    }
};


struct myvector
{
public:
    point start;
    point finish;
    long long int x ;
    long long int y ;

    myvector(point given_start , point given_finish)
    {
        start = given_start;
        finish = given_finish;

        x = finish.x - start.x;
        y = finish.y - start.y;
    }

    double magnitude()
    {
        return sqrt(x*x + y*y);
    }
    long long int magnitude_square()
    {
        return x*x + y*y;
    }
};

long long int dotProduct(myvector vector1 , myvector vector2) // vector2 is considered as counterclock wise position from vector 1
{
    return vector1.x * vector2.x + vector1.y * vector2.y;
}

long long int crossProduct(myvector vector1 , myvector vector2) // vector2 is considered as counterclock wise position from vector 1
{
    return vector1.x * vector2.y - vector1.y * vector2.x;
}

double smallestAngle(myvector vector1 , myvector vector2) //position doesn't matter
{
    return acos(dotProduct(vector1,vector2) / (vector1.magnitude()*vector2.magnitude())) * 180 / PI;
}

double counterClockWiseAngle(myvector vector1 , myvector vector2)  // vector2 is considered as counterclock wise position from vector 1
{
    if(crossProduct(vector1 , vector2) > 0)
    {
        return smallestAngle(vector1 , vector2);
    }
    else
    {
        return 360 - smallestAngle(vector1 , vector2);
    }
}

int intersected(long long int x1 , long long int y1 , long long int x2 , long long int y2 , long long int x3 , long long int y3 , long long int x4 , long long int y4) //Checking (x1 , y1) -> (x2 , y2) line interesected with (x3 , y3) -> (x4 , y4)
{

    /**
        return 0 if not intersected
        return 1 if intersected
        return 2 if (x3 , y3) is on (x1`, y1) to (x2 , y2) line
    **/

    //cout << x1 << " " << y1 << " " << x2 << " " << y2 << " " << x3 << " " << y3 << " " << x4 << " " << y4 <<"==" << endl ;
    long long int first_cross_product;
    long long int second_cross_product;
    long long int third_cross_product ;
    long long int fourth_cross_product ;

    first_cross_product = crossProduct(myvector(point(x1 , y1) , point(x2 , y2)) , myvector(point(x1 , y1) , point(x3 ,y3)));
    second_cross_product = crossProduct(myvector(point(x1 , y1) , point(x2 , y2)) , myvector(point(x1 , y1) , point(x4 ,y4)));
    third_cross_product = crossProduct(myvector(point(x3 , y3) , point(x4 , y4)) , myvector(point(x3 , y3) , point(x1 ,y1)));
    fourth_cross_product = crossProduct(myvector(point(x3 , y3) , point(x4 , y4)) , myvector(point(x3 , y3) , point(x2 ,y2)));





    if(first_cross_product == 0)
    {
        if(x1 > x2) swap(x1 , x2);
        if(y1 > y2) swap(y1 , y2);

        if(x3 >= x1 && x3 <=x2 && y3>=y1 && y3 <= y2)
        return 2;
        else return 0;
    }
    //cout << first_cross_product << "::" << second_cross_product << "::" << third_cross_product <<"::" << fourth_cross_product << endl ;
    bool check1 = false ;
    bool check2 = false ;

    if((first_cross_product <=0 && second_cross_product >=0) || (first_cross_product >=0 && second_cross_product <=0) )
    {
        check1 = true;
    }
    if((third_cross_product <=0 && fourth_cross_product >=0) || (third_cross_product >=0 && fourth_cross_product <=0))
    {
        check2 = true;
    }

    if(check1 && check2)
    {
        return 1;
    }
    else return 0 ;

}

bool online(long long int x1 , long long int y1 , long long int x2 , long long int y2 , long long int x3 , long long int y3 ) // check  (x3 , y3) on the line of x1 , y1) -> (x2 , y2) line
{
    long long int first_cross_product = crossProduct(myvector(point(x1 , y1) , point(x2 , y2)) , myvector(point(x1 , y1) , point(x3 ,y3)));

    if(first_cross_product == 0)
    {
        if(x1 > x2) swap(x1 , x2);
        if(y1 > y2) swap(y1 , y2);

        if(x3 >= x1 && x3 <=x2 && y3>=y1 && y3 <= y2)
        return true;

    }
    else return false ;
}
int main()
{
    long long int no_of_submarine , no_of_island , no_of_points, x1 , y1 , x2 , y2 ;

    vector <long long int> submarine_position_start_x ;
    vector <long long int> submarine_position_start_y ;
    vector <long long int> submarine_position_end_x ;
    vector <long long int> submarine_position_end_y ;
    vector <long long int> island_x[100];
    vector <long long int> island_y[100];
    long long int submarine_status[105] ; // 1 = still in water ; 2 = partially on land ; 3 = Entirely on land
    memset(submarine_status , 0 , sizeof(submarine_status));

    scanf("%lld", &no_of_submarine);

    for(int i = 0 ; i < no_of_submarine ; i++)
    {
        scanf("%lld %lld %lld %lld", &x1 , &y1 , &x2 , &y2);

        submarine_position_start_x.push_back(x1);
        submarine_position_start_y.push_back(y1);
        submarine_position_end_x.push_back(x2);
        submarine_position_end_y.push_back(y2);
    }


    scanf("%lld", &no_of_island);

    for(int i = 0 ; i < no_of_island ; i++)
    {
        scanf("%lld" , &no_of_points);

        for(int j = 0 ; j < no_of_points ; j++)
        {
            scanf("%lld %lld", &x1 , &y1);
            island_x[i].push_back(x1);
            island_y[i].push_back(y1);
        }
    }

    for(int i = 0 ; i < no_of_submarine ; i++)
    {
        int result ;

        for(int k = 0 ; k < no_of_island ; k++)
        {
            if(submarine_status[i] == 2)
            {
                break ;
            }
            no_of_points = island_x[k].size();

             for(int j = 0 ; j < no_of_points ; j++)
             {
                 if(j != no_of_points - 1)
                 {
                     result = intersected(submarine_position_start_x[i] , submarine_position_start_y[i] , submarine_position_end_x[i] , submarine_position_end_y[i] , island_x[k][j] , island_y[k][j] , island_x[k][j+1] , island_y[k][j+1]);
                 }
                 else
                 {
                     result = intersected(submarine_position_start_x[i] , submarine_position_start_y[i] , submarine_position_end_x[i] , submarine_position_end_y[i] , island_x[k][j] , island_y[k][j] , island_x[k][0] , island_y[k][0]);

                 }
                 if(result == 1)
                 {
                     //cout << "Here" << endl ;
                     submarine_status[i] = 2;
                     break;
                 }
             }


        }

    }

    for(int i = 0 ; i < no_of_submarine ; i++)
    {
        if(submarine_status[i] == 2)
        {
            continue;
        }
        int result1 , result2 ;

        for(int k = 0 ; k < no_of_island ; k++)
        {
            int counter1 = 0  , counter2 = 0 ;
            if(submarine_status[i] == 3)
            {
                continue;
            }

            no_of_points = island_x[k].size();

             for(int j = 0 ; j < no_of_points ; j++)
             {
                 if(j != no_of_points - 1)
                 {
                     result1 = intersected(island_x[k][j] , island_y[k][j] , island_x[k][j+1] , island_y[k][j+1],submarine_position_start_x[i] , submarine_position_start_y[i] , 1000000007 + submarine_position_start_x[i] , 1000000009 + submarine_position_start_y[i] );
                 }
                 else
                 {
                     result1 = intersected(island_x[k][j] , island_y[k][j] , island_x[k][0] , island_y[k][0],submarine_position_start_x[i] , submarine_position_start_y[i] , 1000000007 + submarine_position_start_x[i] , 1000000009 + submarine_position_start_y[i] );

                 }
                 if(j != no_of_points - 1)
                 {
                     result2 = intersected(island_x[k][j] , island_y[k][j] , island_x[k][j+1] , island_y[k][j+1],submarine_position_end_x[i] , submarine_position_end_y[i] , 1000000007 + submarine_position_end_x[i] , 1000000009 + submarine_position_end_y[i] );
                 }
                 else
                 {
                     result2 = intersected(island_x[k][j] , island_y[k][j] , island_x[k][0] , island_y[k][0] , submarine_position_end_x[i] , submarine_position_end_y[i] , 1000000007 + submarine_position_end_x[i] , 1000000009 + submarine_position_end_y[i]);

                 }
                 if(result1 == 1 || result1 == 2)
                 {
                     counter1++;
                 }
                 if(result2 == 1 || result2 == 2)
                 {
                     counter2++;
                 }
             }

           // cout << counter1 << "::" << counter2 << endl ;

             if(counter1 == counter2 && counter1 % 2 == 1)
             {
                 submarine_status[i] = 3 ;
             }
        }
        if(submarine_status[i] == 0)
        {
            submarine_status[i] = 1 ;
        }

    }

    for(int i = 0 ; i < no_of_submarine ; i++)
    {
        if(submarine_status[i] == 1)
        {
            printf("Submarine %d is still in water.\n", i+1);
        }
        else if(submarine_status[i] == 2)
        {
            printf("Submarine %d is partially on land.\n", i+1);
        }
        else if(submarine_status[i] == 3)
        {
            printf("Submarine %d is completely on land.\n", i+1);
        }
    }


    return 0 ;
}



