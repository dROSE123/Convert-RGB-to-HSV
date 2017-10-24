#include<stdio.h>
#include<math.h>
#include"MaxMin.h"

double getH (double Cmax, double d, double R1, double G1, double B1)
{
    double H;

    if (Cmax == R1)
    {
        H = 60 * fmod( (G1 - B1) / d, 6);
    }
    if (Cmax == G1)
    {
        H = 60 * ( (B1 - R1) / d + 2 );
    }
    if (Cmax == B1)
    {
       H = 60 * ( (R1 - G1) / d + 4 );
    }

    return H;
}

double getS (double Cmax, double d)
{
    double S;

    if (Cmax == 0)
    {
        S = 0;
    }
    else 
    {
        S = d / Cmax;
    }

    return S;

}

int main()
{
    char c;
    int N, M;
    unsigned int i;
    float x;
    int R, G, B;
    float R1, G1, B1;
    float H, S, V, H1, S1, V1;
    float Cmax, Cmin, d;

    scanf("%d %d", &N, &M);
    scanf(" %c", &c);
    scanf("%f", &x);
    
    for (i = 0 ; i < N * M ; i++)
        {
            scanf("%d %d %d", &R, &G, &B);

            R1 = R / 255.0;
            G1 = G / 255.0;
            B1 = B / 255.0;

            Cmax = max(R1, G1, B1);
            Cmin = min(R1, G1, B1);

            d = Cmax - Cmin;

// In functie de d, Cmax si Cmin am calculat valoarea lui H, S, V

            if (d == 0)
            {
                H = 0;
            }
            else
            {
                H = getH (Cmax, d, R1, G1, B1);
                if (H < 0)
                {
                    H = H + 360.0;
                }
            }
            H /= 360;

            S = getS (Cmax, d);
            
            V = Cmax;

// In functie de valoarea caracterului c am calculat noile valori ale lui H, S, V

            switch (c)
            {
                case 'h' :
                {
                    H1 = H + x;
                    S1 = S;
                    V1 = V;
                    break; 
                }

                case 's' :
                {
                    H1 = H;
                    S1 = S * x;
                    V1 = V;
                    break;
                }

                case 'v' :
                {
                    H1 = H;
                    S1 = S;
                    V1 = V * x;
                    break;
                }               
            }

            if (H1 < 0)
            {
                H1 = 0;
            }

            if (H1 > 1)
            {
                H1 = 1;
            }

            if (S1 > 1)
            {
                S1 = 1;
            }

            if (V1 > 1)
            {
                V1 = 1;
            }

            printf("%0.5f %0.5f %0.5f\n", H1, S1, V1);
            
        }
        return 0;
}
