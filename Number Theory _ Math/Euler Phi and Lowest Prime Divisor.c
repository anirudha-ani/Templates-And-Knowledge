//Linear sieve algo from http://e-maxx.ru/algo/prime_sieve_linear with this feature

const int N = 10000000;
int lowest_prime_factor[N + 1];
int phi[N + 1];
vector<int> prime_list;

void calc_sieve()
{
    phi[1] = 1;
    for (int i = 2; i <= N; ++i)
    {
        if (lowest_prime_factor[i] == 0)
        {
            lowest_prime_factor[i] = i;
            phi[i] = i - 1;
            pr.push_back(i);
        }
        else
        {
            //Calculating phi
            if (lowest_prime_factor[i] == lowest_prime_factor[i / lowest_prime_factor[i]])
                phi[i] = phi[i / lowest_prime_factor[i]] * lowest_prime_factor[i];
            else
                phi[i] = phi[i / lowest_prime_factor[i]] * (lowest_prime_factor[i] - 1);
        }
        for (int j = 0; j < (int)prime_list.size() && prime_list[j] <= lowest_prime_factor[i] && i * prime_list[j] <= N; ++j)
            lowest_prime_factor[i * prime_list[j]] = prime_list[j];
    }
}
