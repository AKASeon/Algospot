#include <stdio.h>
#include <string.h>

#define MAX_ARRAY_COUNT     50000

int     gInputArray[MAX_ARRAY_COUNT];
int     gOutputArray[MAX_ARRAY_COUNT];

void swap( int  * a,
           int  * b )
{
    int temp = 0;

    temp = *a;
    *a = *b;
    *b = temp;
}

void printArray( int    * aArray,
                 int      aLength )
{
    for ( int i = 0; i < aLength; i++ )
    {
        printf( "%d ", aArray[i] );
    }
    printf("\n");
}

void solve( int    * aMoveArray,
            int      aLength )
{
    printf("%s Length :%d", __FUNCTION__, aLength );

    for ( int i = 0; i < aLength; i++ )
    {
#if 0
        if ( aMoveArray[i] != 0 )
        {
            int sTemp = gInputArray[i];

            memcpy( &gInputArray[i-aMoveArray[i]+1],
                    &gInputArray[i-aMoveArray[i]],
                    aMoveArray[i] * sizeof(int) );
            gInputArray[i-aMoveArray[i]] = sTemp;
        }
#else
        for ( int j = 0; j < aMoveArray[i]; j++ )
        {
            swap( &gInputArray[i-j], &gInputArray[i-j-1] );
        }
#endif
    }
    
    for ( int i = 0; i < aLength; i++ )
    {
        if ( gInputArray[i] >= MAX_ARRAY_COUNT )
        {
            printf("fuck\n");
        }
        gOutputArray[gInputArray[i]] = i + 1;
        gInputArray[i] = i;
    }

    printArray( gOutputArray, aLength );
}

int main( void )
{
    int sTestCount = 0;
    int sArrayCount = 0;
    int sMoveArray[MAX_ARRAY_COUNT];

    /* init */
    for ( int i = 0; i < MAX_ARRAY_COUNT; i++ )
    {
        gInputArray[i] = i;
    }

    scanf( "%d", &sTestCount );

    for ( int i = 0; i < sTestCount; i++ )
    {
        scanf( "%d", &sArrayCount );

        printf("Input Count : %d\n", sArrayCount );

        for ( int j = 0; j < sArrayCount; j++ )
        {
            scanf( "%d", &sMoveArray[j] );
        }

        solve( sMoveArray, sArrayCount );
    }
}
