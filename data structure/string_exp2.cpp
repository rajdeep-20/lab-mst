#include <bits/stdc++.h>
using namespace std;
int main()
{
    char intstr[100] = "this is the lab of data sturcture";
    char ptrn[50] = "data sturcture";
    char repl[20] = "machine learning";
    int pos = 0, flag = 0, pos_last = 0, j = 0;

    for (int i = 0; i < 50; i++)
    {
        if (intstr[i] == ptrn[j])
        {
            j++;

            if (flag == 0)
            {
                pos = i;
                flag++;
            }
            // cout<< j;
        }
        else
        {
            flag = 0;
            pos_last = pos + j;
            j = 0;
        }
    }
    // cout << intstr[pos] <<" " <<ptrn[pos_last]<<endl;
    char final_char[100];
    for (int i = 0; i < pos; i++)
    {
        final_char[i] = intstr[i];
    }
    for (int i = 0; i < 20; i++)
    {
        final_char[pos + i] = repl[i];
    }

    // for (int i=0; i<100; i++)
    // {
    cout << final_char;
    // }
}

/* this is your string
t h i s i s y o u r s t r i n g
repplce kna hai your se sath
 */