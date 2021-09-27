#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

//RETURNS TEORICAL PROBABILITY
float t_function(
    int s //POBLATION
    )
{
    int result = 1; //TEORICAL PROBABILITY

    for (int i = 0; i < s; i++)
    {
        float r = (float) result * (float) (1 - i / 365);

        result = r;
        printf("\n entero (r): %i", r);
        printf("\n float (r): %0.2f", r);
    }

    return result;
}

void printArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
        printf("i: %d, value: %d\n\n", i, arr[i]);
}


int buscarEnArreglo(const int arreglo[], int busqueda, int longitud) {
    for (int x = 1; x < longitud; x++) {
        if (arreglo[x] == busqueda) return x;
    }
    return 0;
}
int birthdayParadox(
    int s, //Poblation
    int k  //Repetitions
)
{
    float t = t_function(s); //Teoric Probability of NOT having two o more people with the same birthday
    int n = 0;               //How many times were found a repetition
    int longitud=0;
    for (int j = 0; j < k; j++)
    {
        int noRepetitionFlag = 1; //0=FALSE, 1=TRUE WORKING WITH BOOLEANS IN C IS COMPLICATED, IS BETTER TO USE BINARY
        int birthdaylist[s];
        memset(birthdaylist, -1, s * sizeof(n));
        int i = 0; //How many times a repetition where found
        while (noRepetitionFlag && (i < s))
        {
            float u = (float)rand() / (float)(RAND_MAX);
            birthdaylist[i] = (round(364 * u) + 1);
            //printf("%d , %d\n", i, birthdaylist[i]);
            longitud++;
            //noRepetitionFlag = repetition(birthdaylist, i + 1);
            noRepetitionFlag=buscarEnArreglo(birthdaylist,birthdaylist[i+1],longitud);
            if (noRepetitionFlag==1){
                n++;
                break;
            }
            i++;
        }
    }
    float p; //No repetition probability
    p = 1 - (n / k);
    int d; //Relative error
    d = (int)abs(t - p) / t;
    printf("\n Subjects (s): %i",s);
    printf("\n Expected Probability of not repetition (t): %e", t);
    printf("\n Cycles without repetition (n): %i", n);
    printf("\n Total Cycles (k): %i", k);
    printf("\n Generated probability of not repetition (p): %i", p);
    printf("\n Relative Error (d): %0.2f", d);
    //printf("%d\n", 2, "\n");
}

int main()
{
    srand(time(NULL)); //ONLY CALL ONCE
    birthdayParadox(320, 10);
    return 0;
}
