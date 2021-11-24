/****************** Prime Generator **********************/ 
const int N=1e7+10; 
int prime[20000010]; 
bool isprime[N]; 
int nprime; 

//template <typename T> void Sieve(T a) 
//{nprime = 0;memset(isprime,true,sizeof(isprime));
//isprime[1]=false;for(int i=2;i<N;i++){
//if(isprime[i]){prime[nprime++]=i;for(int j=2;i*j<N;j++)
//isprime[i*j]=false;}}}

template <typename T> inline T PrimeFactors(T n)
{ll cnt=0,sum=1;for(int i=0; prime[i]*prime[i]<=n 
and i<nprime;i++){cnt=0;while(n%prime[i]==0)
{cnt++;n/=prime[i];}sum*=(cnt+1);}
if(n>1)sum*=2;return sum;} 
/****************** Prime Generator End **********************/ 
