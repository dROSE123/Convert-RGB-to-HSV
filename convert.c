#include<stdio.h>
#include<math.h>

double max (double R1, double G1, double B1)
{
    if ( (R1 > G1 > B1) || (R1 > B1 > G1) )
    {
        return R1;
    }
    if ( (G1 > B1 > R1) || (G1 > R1 > B1) ) // intoarce booleana
    {
        return G1;
    }
    if ( (B1 > G1 > R1) || (B1 > R1 > G1) )
    {
        return B1;
    }
}

double min (double R1, double G1, double B1)
{
    if ( (R1 < G1 < B1) || (R1 < B1 < G1) )
    {
        return R1;
    }
    if ( (G1 < R1 < B1) || (G1 < B1 < R1) )
    {
        return G1;
    }
    if ( (B1 < G1 < R1) || (B1 < R1 < G1) )
    {
        return B1;
    }
}

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
       H = 60 * ( (R1 - G1) / d +4 );
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
    int i, j = 0;
    double x;
    double R, G, B, R1, G1, B1;
    double H, S, V, H1, S1, V1;
    double Cmax, Cmin, d;

    printf("Dati latimea, respectiv inaltimea lungimii: ");
    scanf("%d %d", &N, &M);

    printf("Dati valoare pentru factorul de modoficare a caracteristii: ");
    scanf("%lf", &x);

    printf("Alegeti litera prin care se face selectia operatiei aplicate: ");
    scanf(" %c", &c);

    do 
    {
        for (i == 0 ; i < M ; i++)
        {
            printf("Dati valori pentru R G si B: ");
            scanf("%lf %lf %lf", &R, &G, &B);

            R1 = R / 255;
            G1 = G / 255;
            B1 = B / 255;

            printf("\n%0.5f %0.5f %0.5f\n\n", R1, G1, B1);

            Cmax = max(R1, G1, B1);
            Cmin = min(R1, G1, B1);

            printf("Max: %0.5f\nMin: %0.5f\n\n", Cmax, Cmin);

            d = Cmax - Cmin;

            if (d == 0)
            {
                H = 0;
            }
            else
            {
                H = getH (Cmax, d, R1, G1, B1);
            }

            S = getS (Cmax, d);

            V = Cmax;

            printf("%.5f %.5f %.5f\n", H, S, V);


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

                default:
                {
                    break;
                }
                
            }

            printf("%0.5f %0.5f %0.5f\n", H1, S1, V1);

        }
    
        j++;
    }
    while (j <= N);

//    printf("%d %d %d %c", N, M, x, c);


    return 0;
}