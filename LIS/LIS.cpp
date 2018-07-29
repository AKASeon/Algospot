#include <stdio.h>

int gList[500];
int gListCount = 0;
int gLIS[501];

int getLIS( int       aIndex ) 
{
    int i = 0;
    int j = 0;
    int sLIS = 0;
    int sTempLIS = 0;

    /* already get it */
    if ( gLIS[aIndex+1] != 0 )
    {
        printf( "return %d : %d\n", aIndex, gLIS[aIndex+1] );
        return gLIS[aIndex+1];
    }

    for ( i = aIndex+1; i < gListCount; i++ )
    {
        if ( gList[aIndex] < gList[i] )
        {
            sTempLIS = getLIS( i+1 );
            if ( sLIS < sTempLIS )
            {
                sLIS = sTempLIS + 1;
            }
        }
    }

    gLIS[aIndex+1] = sLIS;

    return sLIS;
}

int main( void )
{
    int sCount = 0;
    int i = 0;
    int j = 0;

    scanf( "%d", &sCount );
    for ( i = 0; i < sCount; i++ )
    {
        scanf( "%d", &gListCount );
        for ( j = 0; j < gListCount; j++ )
        {
            scanf( "%d ", &gList[j] );
        }

        gLIS[gListCount] = 1;
        printf( "%d\n", getLIS( -1 ) );
    }

    return 0;
}
