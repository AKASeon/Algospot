#include <stdio.h>

#define TRUE    (0)
#define FALSE   (1)

int solve( int * aFenceArray, 
           int   aMaxValue,
           int   aListCount )
{
    int sCount = 0;
    int sContinue = TRUE;
    int sIndex = 0;
    int sContinueCount = 0;
    int sTempMaxSize = 0;
    int sMaxSize = 0;
    int sSize = 0;

    sSize = aMaxValue;

    while ( sContinue == TRUE )
    {
        for ( sIndex = 0; sIndex < aListCount; sIndex++ )
        {
            if ( aFenceArray[sIndex] >= sSize )
            {
                sContinueCount++;
            }
            else
            {
                sTempMaxSize = sContinueCount * sSize;

                if ( sMaxSize < sTempMaxSize )
                {
                    sMaxSize = sTempMaxSize;
                }

                sContinueCount = 0;
                sTempMaxSize = 0;
            }
        }

        sTempMaxSize = sContinueCount * sSize;
        if ( sMaxSize < sTempMaxSize )
        {
            sMaxSize = sTempMaxSize;
        }

        sContinueCount = 0;
        sTempMaxSize = 0;

        sSize--;

        if ( sSize == 0 )
        {
            sContinue = FALSE;
        }

        sTempMaxSize = sSize * aListCount;
        if ( sTempMaxSize < sMaxSize )
        {
            sContinue = FALSE;
        }
    }

    return sMaxSize;
}

int main( void )
{
    int sCount = 0;
    int sListCount = 0;
    int sMaxValue = 0;
    int sFenceArray[20000];
    int i = 0;
    int j = 0;

    scanf( "%d", &sCount );

    for ( i = 0; i < sCount; i++ )
    {
        scanf( "%d", &sListCount );

        for ( j = 0; j < sListCount; j++ )
        {
            scanf( "%d ", &sFenceArray[j] );

            if ( sFenceArray[j] > sMaxValue )
            {
                sMaxValue = sFenceArray[j];
            }
        }

        printf( "%d\n", solve( sFenceArray,
                               sMaxValue,
                               sListCount ) );
                               
    }

    return 0;
}
