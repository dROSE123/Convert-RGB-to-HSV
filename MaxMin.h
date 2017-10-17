#include<stdio.h>

double Max (double R1, double G1, double B1)
{
    if (R1 > G1)
    {
        if (G1 > B1)
        {
            return R1;
        }
        else
        {
            return R1;
        }
    }

    if (G1 > R1)
    {
        if (R1 > B1)
        {
            return G1;
        }
        else
        {
            return G1;
        }
    }

    if (B1 > R1)
    {
        if (R1 > G1)
        {
            return B1;
        }
        else
        {
            return B1;
        }
    }
}

double Min (double R1, double G1, double B1)
{
    if (R1 < G1)
    {
        if (G1 < B1)
        {
            return R1;
        }
        else
        {
            return R1;
        }
    }

    if (G1 < R1)
    {
        if (R1 < B1)
        {
            return G1;
        }
        else
        {
            return G1;
        }
    }

    if (B1 < R1)
    {
        if (R1 < G1)
        {
            return B1;
        }
        else
        {
            return B1;
        }
    }
}
