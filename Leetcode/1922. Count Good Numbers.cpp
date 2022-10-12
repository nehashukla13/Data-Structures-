#define mod 1000000007
class Solution 
{
private:

long long int modPower(int num,long long int ind)
{
    if(ind==0)
    {
        return 1;
    }

    long long int temp=modPower(num,ind/2);

    if(ind%2==0)
    {
        return (temp%mod * temp%mod)%mod;
    }


    return (((long long int)num%mod) * (temp%mod) * (temp%mod))%mod;
}

public:
    int countGoodNumbers(long long n) 
    {

        if(n%2==0)
        {
            (modPower(5,n/2)%mod *modPower(4,n/2)%mod)%mod;
        }

        return (modPower(5,n/2+1)*modPower(4,n/2))%mod;
    }
};
