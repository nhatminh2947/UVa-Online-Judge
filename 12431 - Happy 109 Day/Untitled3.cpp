#include <cstdio>
#include <cstring>

using namespace std;

long long M;

long long mult(long long a, long long b){
    long long ret = 0;

    while(b){
        if(b & 1)
			ret += a;
        if(ret >= M) ret -= M;

        a <<= 1;
        if(a >= M) a -= M;

        b >>= 1;
    }

    return ret;
}

struct Matrix{
    long long m[2][2];

    Matrix operator * (Matrix &X){
        Matrix ret;

        memset(ret.m,0,sizeof ret.m);

        for(int i = 0;i < 2;++i){
            for(int j = 0;j < 2;++j){
                for(int k = 0;k < 2;++k)
                    ret.m[i][j] += mult(m[i][k],X.m[k][j]);

                if(ret.m[i][j] >= M) ret.m[i][j] -= M;
            }
        }

        return ret;
    }

    Matrix pow(long long n){
        Matrix ret;
        Matrix aux = *this;

        ret.m[0][0] = 1; ret.m[0][1] = 0;
        ret.m[1][0] = 0; ret.m[1][1] = 1;

        while(n){
            if(n & 1)
				ret = ret * aux;
            aux = aux * aux;
            n >>= 1;
        }

        return ret;
    }
};

int main(){
	freopen("12431 - Happy 109 Day.INP","r",stdin);
	freopen("12431 - Happy 109 Day.OUT","w",stdout);
    int T,b,d;
    long long n;
    Matrix X,Y;

    X.m[0][1] = 1;
    X.m[1][0] = 0;
    X.m[1][1] = 1;

    scanf("%d",&T);

    for(int tc = 1;tc <= T;++tc){
        scanf("%lld %d %d %lld",&n,&b,&d,&M);

        X.m[0][0] = b;
        Y = X.pow(n);

        printf("Case %d: %lld\n",tc,mult(Y.m[0][1],d));
    }

    return 0;
}

