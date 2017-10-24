#include<stdio.h>

float max (float a, float b, float c)
{
    if ( (a >= b) && (a >= c) )
    {
        return a;
    }
    if ( (b >= a) && (b >= c) )
    {
        return b;
    }
    if ( (c >= a) && (c >= b) )
    {
        return c;
    }
}

float min (float a, float b, float c)
{
    if ( (a <= b) && (a <= c) )
    {
        return a;
    }
    if ( (b <= a) && (b <= c) )
    {
        return b;
    }
    if ( (c <= a) && (c <= b) )
    {
        return c;
    }
}
