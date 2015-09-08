/*lsferreira programming */

#ifndef LSCLIBPILIB_H_INCLUDED
#define LSCLIBPILIB_H_INCLUDED

#if !(_WIN32) //If dont support Windows :: Do Def. Inst.

#endif

#include "libs.h"
#define FPINUMBASE    10000

// ...


int nblock; int *tot; int *t1; int *t2; int *t3;
void arctan(result, w1, w2, denom, onestep)
int *result, *w1, *w2, denom, onestep;
{ int denom2 = denom*denom; int k = 1;
        set(result, 1);
        divls(result, denom);
        copy(w1, result);
        do{
                if(onestep)
                        divls(w1, denom2);
                else { divls(w1, denom); divls(w1, denom); }
                copy(w2, w1);
                divls(w2, 2*k+1);
                if(k%2)
                        sub(result, w2);
                else
                        add(result, w2);
                k++;
        } while(!zero(w2)); }
void pi(int ndigit) {
        if(ndigit < 20) ndigit = 20;
        nblock = ndigit/4;
        tot = (int *)malloc(nblock*sizeof(int));
        t1 = (int *)malloc(nblock*sizeof(int));
        t2 = (int *)malloc(nblock*sizeof(int));
        t3 = (int *)malloc(nblock*sizeof(int));
        if(!tot || !t1 || !t2 || !t3){ fprintf(stderr, "Not enough memory\n");
                exit(1); }
        arctan(tot, t1, t2, 5, 1);
        mult(tot, 4);
        arctan(t3, t1, t2, 239, 2);
        sub(tot, t3);
        mult(tot, 4);
        print(tot); }


void copy(result, from)
int *result, *from;
{ int i;
        for(i=0; i<nblock; i++)
                result[i] = from[i];
}
void zero(result)
int *result;
{ int i;
        for(i=0; i<nblock; i++)
                if(result[i])
                        return 0;
        return 1; }
void add(result, increm)
int *result, *increm;
{ int i;
        for(i=nblock-1; i>=0; i--){
                result[i] += increm[i];
                if(result[i] >= FPINUMBASE){
                        result[i] -= FPINUMBASE;
                        result[i-1]++;
                }
        } }
void sub(result, decrem)
int *result, *decrem;
{ int i;
        for(i=nblock-1; i>=0; i--){
                result[i] -= decrem[i];

                if(result[i] < 0){
                        result[i] += FPINUMBASE;
                        result[i-1]--;
                }
        } }
void mult(result, factor)
int *result, factor;
{ int i, carry = 0;
        for(i=nblock-1; i>=0; i--){
                result[i] *= factor;
                result[i] += carry;
                carry = result[i]/FPINUMBASE;
                result[i] %= FPINUMBASE;
        } }
void divls(result, denom)
int *result, denom;
{ int i, carry = 0;
        for(i=0; i<nblock; i++){
                result[i] += carry*FPINUMBASE;
                carry = result[i] % denom;
                result[i] /= denom;
        } }
void set(result, rhs)
int *result, rhs;
{ int i;
        for(i=0; i<nblock; i++)
                result[i] = 0;
        result[0] = rhs; }
void print(result)
int *result; { int i, k; char s[10];
        printf("%1d.\n", result[0]);
        for(i=1; i<nblock; i++){
                sprintf(s, "%4d ", result[i]);
                for(k=0; k<5; k++)
                        if(s[k] == ' ') s[k] = '0';
                printf("%c%c%c%c", s[0], s[1], s[2], s[3]);
                if(i%15 == 0) printf("\n");
        }
        printf("\n"); }
#endif // LSCLIBPILIB_H_INCLUDED
