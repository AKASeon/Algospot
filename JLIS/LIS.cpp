#include <stdio.h>

int getLIS( int     * aList,
            int       aListCount,
            int       aIndex,
            int     * aLIS )
{
    int i = 0;
    int j = 0;
    int sLIS = 0;
    int sTempLIS = 0;

    /* already get it */
    if ( aLIS[aIndex+1] != 0 )
    {
        return aLIS[aIndex+1];
    }

    for ( i = aIndex; i < aListCount-1; i++ )
    {
        sTempLIS = getLIS( aList, 
                           aListCount,
                           i+1,
                           aLIS );

        if ( aList[i] < aList[i+1] )
        {
            if ( sLIS <= sTempLIS )
            {
                sLIS = sTempLIS+1;
            }
        }
    }

    aLIS[aIndex+1] = sLIS;

    return sLIS;
}

int printLIS( int * aList,
              int * aLIS,
              int   aListCount )
{
    int i = 0;

    for ( i = 0; i < aListCount; i++ )
    {
        printf( "Index : %d, Value : %d, LIS : %d\n", i, aList[i], aLIS[i+1] );
    }
}

int solve( void )
{
    int sCount;

    return sCount;
}

int main( void )
{
    int sList1[100];
    int sList2[100];
    int sJLIS[101][101];

    sList1[0] = 1;
    sList1[1] = 2;
    sList1[2] = 4;

    sList2[0] = 3;
    sList2[1] = 4;
    sList2[2] = 7;

    sJLIS[0][6] = 1;
    getLIS( sList1, 6, 0, sJLIS[0] );
    getLIS( sList2, 6, 0, sJLIS[0] );
    printLIS( sList1, sJLIS[0], 6 );

    return 0;
}
