//This code uses Fast Fourier Transformation to Multiply two huge integer in nlogn time where n is the length of the integer string
//This is the fastest way to multiply two integer number
//thanks to forthright48 for his main FFT implementation
//Thanks Erik Demaine for his awesome tutorial for understanding FFT (https://www.youtube.com/watch?v=iTMn0Kt18tg)

/*
    These awesome problems can be solved using this

    MUL - Fast Multiplication - http://www.spoj.com/problems/MUL/ (Can also be solved with Karatsuba multiplication but can not be solved with the generalized n^2 solution)
    VFMUL - Very Fast Multiplication - http://www.spoj.com/problems/VFMUL/ (Can not be solved with Karatsuba multiplication)

*/

#include <bits/stdc++.h>

using namespace std;
#define PI acos(-1.0)
typedef complex<double> base;

void fft (vector<base> & a, bool invert) {
	int n = (int) a.size();
	if (n == 1)  return;

    vector<base> a0 (n/2), a1 (n/2);
	for (int i=0, j=0; i<n; i+=2, ++j) {
        a0[j] = a[i];
        a1[j] = a[i+1];
	}
    fft (a0, invert);
    fft (a1, invert);

	double ang = 2*PI/n * (invert ? -1 : 1);
    base w (1), wn (cos(ang), sin(ang));
	for (int i=0; i<n/2; ++i) {
        a[i] = a0[i] + w * a1[i];
        a[i+n/2] = a0[i] - w * a1[i];
		if (invert)
            a[i] /= 2, a[i+n/2] /= 2;
        w *= wn;
	}
}


/*
1. Build two different vectors with coefficient of the equation ( 3 + x + 2x^2 will be [3,1,2] )
2. Send them to multiply ( arr, brr, res )
3. res vector contains result of multiplication.

WARNING: FFT causes precision error. multiply() rounds them to integer.
*/

void polynomial_multiply (const vector<int> & a, const vector<int> & b, vector<int> & res) {
    vector<base> fa (a.begin(), a.end()), fb (b.begin(), b.end());
	size_t n = 1;
	while (n < max (a.size(), b.size())) n <<= 1;
    n <<= 1;
    fa.resize (n), fb.resize (n);

    fft (fa, false), fft (fb, false);
	for (size_t i=0; i<n; ++i)
        fa[i] *= fb[i];
    fft (fa, true);

    res.resize (n);
	for (size_t i=0; i<n; ++i)
        res[i] = int (fa[i].real() + 0.5);
}

void int_multiply(string input1 , string input2)
{
        vector <int> a , b , result ;
        int length1 = input1.size();
        int length2 = input2.size();

        for(int k=length1-1 ; k>=0 ; k--)
        {
            a.push_back(input1[k] - '0');
        }
        for(int k=length2-1 ; k>=0 ;k--)
        {
            b.push_back(input2[k] - '0');
        }

        polynomial_multiply(a,b,result);

        bool flag = false;
        int length3 = result.size();
        int carry = 0 ;

        for(int j = 0 ; j < length3 ; j++)
        {
            result[j] += carry;
            carry = result[j]/10;
            result[j] = result[j] % 10;
        }

        for(int j = length3-1 ; j >= 0 ; j--)
        {
            if(result[j] != 0)
            {
                flag = true;
            }
            if(flag)
            printf("%d", result[j]);
            //carry = result[j] / 10;

        }
        if(carry != 0)
        {
            printf("%d", carry);
        }
        if(!flag)
        {
            printf("0");
        }
        printf("\n");
}

int main()
{
    int n ;

    string input1 , input2 ;

    scanf("%d", &n);

    for(int i = 0 ; i < n ; i++)
    {
        cin >> input1 >> input2 ;

        int_multiply(input1 , input2);

    }
    return 0;
}
