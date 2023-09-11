#include<stdio.h>
#include <math.h>
int main(int argc, char **argv)
{
    double n, l;
    scanf("%lf",&n);
    int s=0,ans=0;
    l=pow(2,(double)n);
    int a[(int) ((int) n + 1)];
    for (int i=0;i<n;i++) {
        scanf("%d",&a[i]);
    }
    int q=1;
    while (q<l) {
        int k=q;
        int j=0;
        while(j<n) {
            if (k & 1) {
                s+=a[j];
            }
            k = k/pow(2,1);
            j++;
        }
        while (s&&(s%2==0)) {
            s=s/2;
        }
        if (s==1) {
            ans++;
        }
        s=0;
        q++;
    }
    printf("%d",ans);
}v
