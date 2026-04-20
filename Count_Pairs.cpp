#include <cstdio>

char c[10000001];

int main() {
    for (int i = 2; i < 10000001; ++i)
        if (!c[i]) 
            for (int j = i; j < 10000001; j += i) 
                c[j]++;

    int T, N;
    scanf("%d", &T);
    
    while (T--) {
            scanf("%d", &N);
            printf("%lld\n", 1LL << c[N]);
    }
    return 0;
}
