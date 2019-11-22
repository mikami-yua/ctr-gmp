#include<cstdio>
#include <iostream>
#include <gmp.h>
#include <gmpxx.h>
#include "stdio.h"
#define LL long long
#define in(x) scanf("%lld",x)
//#define add(a,b) a=(a+b)%s
//把crt改为gmp的版本
LL k,i,ans=0,b1;
mpz_t x,y,t;
void exgcd(mpz_t a,mpz_t b){//扩欧
    gmp_printf ("a number is %Zd\n", a);
    if(!b){
        mpz_init_set_str (x,"1", 10);
        mpz_init_set_str (y,"0", 10);;
        return;
    }
    gmp_printf ("y3 number is %Zd\n", y);
    mpz_t r,q,mul;
    mpz_init2(r,64);
    gmp_printf ("a %Zd\n", a);
    gmp_printf ("b %Zd\n", b);
    mpz_mod(r,a,b);
    gmp_printf ("r is %Zd\n", r);
    exgcd(b,r);
    mpz_set(t,x);
    mpz_set(t,x);
    //y=t-a/b*y;
    mpz_cdiv_q(q,a,b);
    mpz_mul(mul,q,y);
    mpz_sub(y,t,mul);
    gmp_printf ("y4 number is %Zd\n", y);
}
/*
LL mul(LL a,LL b){//快速乘
    LL r=0;
    while(b){
        if(b&1)add(r,a);
        add(a,a);
        b>>=1;
    }
    return r;
}
*/
//divde 6045543775609435370---4326988345921354220
//divde 5702390195418369968---2684802520824466932
//divde 8071573130764401181---7233736861377144393
//divde 2375858263533767804---36520252443832300
//原数 45911199988959465183765912664616310275170336168741130658429954235029908138100
int main(){
    //in(&k);

    mpz_t a[4],div[4],original,s;
    mpz_init2(s,256);
    mpz_init_set_str (s, "1", 10);
    mpz_init_set_str (div[0], "6045543775609435370", 10);
    mpz_init_set_str (div[1], "5702390195418369968", 10);
    mpz_init_set_str (div[2], "8071573130764401181", 10);
    mpz_init_set_str (div[3], "2375858263533767804", 10);
    mpz_init_set_str (a[0], "4326988345921354220", 10);
    mpz_init_set_str (a[1], "2684802520824466932", 10);
    mpz_init_set_str (a[2], "7233736861377144393", 10);
    mpz_init_set_str (a[3], "36520252443832300", 10);
    //mp_limb_t a1[4];
    //a1[0]=4326988345921354220;
    //a1[1]=2684802520824466932;
    //a1[2]=7233736861377144393;
    //a1[3]=36520252443832300;
    mpz_init_set_str (original, "45911199988959465183765912664616310275170336168741130658429954235029908138100", 10);
    //gmp_printf ("original number is %Zd\n", original);
    //gmp_printf("a1 array is  %Md\n",a1[0]);

    k=4;

    mpz_t temp1,temp2,temp3,temp4,temp5;
    for(i=1;i<=k;i++){
        mpz_mul(s,s,div[i]);
    }//求lcm
    gmp_printf ("s number is %Zd\n", s);
    for(i=1;i<=k;++i){
        mpz_t q1,r1,add;
        mpz_div(q1,s,div[i]);
        gmp_printf ("q1 number is %Zd\n", q1);
        gmp_printf ("y1 number is %Zd\n", y);
        exgcd(q1,div[i]);
        gmp_printf ("y2 number is %Zd\n", y);
        //x=(x%b[i]+b[i])%b[i];//求xi最小非负整数解
        mpz_mod(r1,x,div[i]);
        mpz_add(add,r1,div[i]);
        mpz_mod(x,add,div[i]);

        //add(ans,mul(s/b[i]*x,(a[i]%b[i]+b[i])%b[i]));//别忘处理ai
        //mpz_t temp1,temp2,temp3,temp4,temp5;
        mpz_mod(temp1,a[i],div[i]);
        mpz_add(temp2,temp1,div[i]);
        mpz_mod(temp3,temp2,div[i]);
        mpz_mul(temp4,div[i],x);
        mpz_div(temp5,s,temp4);
        gmp_printf ("div number is %Zd\n", temp5);
    }
    gmp_printf ("div number is %Zd\n", temp5);
    return 0;

}
