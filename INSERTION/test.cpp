#include <stdio.h>

int     gInputArray[50000];
int     gOutputArray[50000];

void swap( int  * a,
           int  * b )
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

void solve( int    * aMoveArray,
            int      aLength )
{
    for ( int i = 0; i < aLength; i++ )
    {
        for ( int j = 0; j < aMoveArray[i]; j++ )
        {
            swap( &gInputArray[i-j], &gInputArray[i-j-1] );
        }
    }

    for ( int i = 0; i < aLength; i++ )
    {
        gOutputArray[gInputArray[i]] = i + 1;
        gInputArray[i] = i;
    }

    for ( int i = 0; i < aLength; i++ )
    {
        printf( "%d ", gOutputArray[i] );
    }
    printf("\n");
}


int main( void )
{
    int sTestCount = 0;
    int sArrayCount = 0;
    int sMoveArray[50000];

    /* init */
    for ( int i = 0; i < 50000; i++ )
    {
        gInputArray[i] = i;
    }

    scanf( "%d", &sTestCount );

    for ( int i = 0; i < sTestCount; i++ )
    {
        scanf( "%d", &sArrayCount );

        for ( int j = 0; j < sArrayCount; j++ )
        {
            scanf( "%d", &sMoveArray[j] );
        }

        solve( sMoveArray, sArrayCount );
    }
}
