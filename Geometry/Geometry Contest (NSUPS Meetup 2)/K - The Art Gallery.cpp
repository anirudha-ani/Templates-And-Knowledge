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

bool intersected(long long int x1 , long long int y1 , long long int x2 , long long int y2 , long long int x3 , long long int y3 , long long int x4 , long long int y4) //Checking (x1 , y1) -> (x2 , y2) line interesected with (x3 , y3) -> (x4 , y4)
{
    long long int first_cross_product;
    long long int second_cross_product;
    long long int third_cross_product ;
    long long int fourth_cross_product ;

    first_cross_product = crossProduct(myvector(point(x1 , y1) , point(x2 , y2)) , myvector(point(x1 , y1) , point(x3 ,y3)));
    second_cross_product = crossProduct(myvector(point(x1 , y1) , point(x2 , y2)) , myvector(point(x1 , y1) , point(x4 ,y4)));
    third_cross_product = crossProduct(myvector(point(x3 , y3) , point(x4 , y4)) , myvector(point(x3 , y3) , point(x1 ,y1)));
    fourth_cross_product = crossProduct(myvector(point(x3 , y3) , point(x4 , y4)) , myvector(point(x3 , y3) , point(x2 ,y2)));





    if(first_cross_product == 0 || second_cross_product == 0 || third_cross_product == 0 || fourth_cross_product == 0)
    {
        return true;
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
        return true;
    }
    else return false ;

}

bool online(long long int x1 , long long int y1 , long long int x2 , long long int y2 , long long int x3 , long long int y3 ) // check  (x3 , y3) on the line of x1 , y1) -> (x2 , y2) line
{
    long long int first_cross_product = crossProduct(myvector(point(x1 , y1) , point(x2 , y2)) , myvector(point(x1 , y1) , point(x3 ,y3)));

    if(first_cross_product == 0)
    {
        return true;
    }
    else return false ;
}
int main()
{
    long long int N , M , x , y , problem_counter = 1 ;

    while(scanf("%lld",&N) == 1 && N!=0)
    {
        vector <long long int> x_data , y_data;

        for(int i = 0 ; i < N ; i++)
        {
            scanf("%lld %lld", &x , &y);

            x_data.push_back(x);
            y_data.push_back(y);
        }

        long long int start_x = x_data[0] , start_y = y_data[0] , end_x = x_data[1] , end_y = y_data[1] , current_x , current_y  ;

        int initial_side ;
        int temp_side ;
        bool not_polygon = false ;

        for(int i = 2 ; i <= N+1 ; i++)
        {
            if(i < N)
            {
                current_x = x_data[i];
                current_y = y_data[i];
            }
            else if(i == N+1)
            {
                current_x = x_data[1];
                current_y = y_data[1];
                start_x = x_data[N-1];
                start_y = y_data[N-1];
                end_x = x_data[0];
                end_y = y_data[0];
            }
            else
            {
                current_x = x_data[0];
                current_y = y_data[0];
                start_x = x_data[N-2];
                start_y = y_data[N-2];
                end_x = x_data[N-1];
                end_y = y_data[N-1];
            }

            if(i==2)
            {
                if(crossProduct(myvector(point(start_x , start_y) , point(end_x , end_y)) , myvector(point(start_x , start_y) , point(current_x , current_y))) < 0)
                {
                    initial_side = -1;
                }
                 else if(crossProduct(myvector(point(start_x , start_y) , point(end_x , end_y)) , myvector(point(start_x , start_y) , point(current_x , current_y))) > 0)
                {
                    initial_side = 1;
                }
            }
            else
            {
                if(crossProduct(myvector(point(start_x , start_y) , point(end_x , end_y)) , myvector(point(start_x , start_y) , point(current_x , current_y))) < 0)
                {
                    temp_side = -1;
                }
                 else if(crossProduct(myvector(point(start_x , start_y) , point(end_x , end_y)) , myvector(point(start_x , start_y) , point(current_x , current_y))) > 0)
                {
                    temp_side = 1;
                }

                if(temp_side != initial_side)
                {
                    printf("Yes\n");
                    not_polygon = true;
                    break;
                }
            }



            start_x = end_x ;
            start_y = end_y ;
            end_x = current_x ;
            end_y = current_y ;

        }
        if(!not_polygon)
        {
            printf("No\n");
        }
    }
    return 0 ;
}

