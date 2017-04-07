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
    long long int n , x , y , m , test_x , test_y , counter = 1;

    while(scanf("%lld", &n) == 1 && n!=0)
    {
        scanf("%lld", &m);
        vector <long long int> polygon_x ;
        vector <long long int> polygon_y ;

        for(long long int i = 0 ; i < n ; i++)
        {
            scanf("%lld %lld", &x ,&y);

            polygon_x.push_back(x);
            polygon_y.push_back(y);
        }


        if(counter != 1)
        {
            printf("\n");
        }

        printf("Problem %d:\n",counter);
        counter++;

        for(long long int i = 0 ; i < m ; i++)
        {
            scanf("%lld %lld",&test_x , &test_y);
            bool on = false ;
            int counter = 0 ;

            for(int j = 0 ; j < n ; j++)
            {
                int result;
                if(j != n-1)
                {
                    result = intersected(polygon_x[j] , polygon_y[j] , polygon_x[j+1] , polygon_y[j+1] , test_x , test_y , 1000000007 + test_x , 1000000009 + test_y);

                    if(result == 2)
                    {
                        on = true;
                        break;
                    }
                    else if(result == 1)
                    {
                        counter++;
                    }
                }
                else if(j == n-1)
                {
                    result = intersected(polygon_x[j] , polygon_y[j] , polygon_x[0] , polygon_y[0] , test_x , test_y , 1000000007 + test_x , 1000000009 + test_y);

                    if(result == 2)
                    {
                        on = true;
                        break;
                    }
                    else if(result == 1)
                    {
                        counter++;
                    }
                }

            }
            if(on == true)
            {
                printf("Within\n");
            }
            else
            {
                if(counter % 2 == 0)
                {
                    printf("Outside\n");
                }
                else printf("Within\n");
            }

        }
    }


    return 0 ;
}
