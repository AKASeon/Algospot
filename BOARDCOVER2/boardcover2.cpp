#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

char    gArray[10][11] = { "..........",
                          "..........",
                          "..........",
                          "..........",
                          ".........." };

int     gMaxX = 0;
int     gMaxY = 0;

/* original */
char    gBlock1[10][11] = { ".#.",
                            "###",
                            "..#" };

char    gBlock2[10][11] = { 0, };

char    gBlock3[10][11] = { 0, };

char    gBlock4[10][11] = { 0, };

int     gBlockMaxX = 0;
int     gBlockMaxY = 0;
int     gBlockCount = 0;

int     gTempMaxCount = 0;
int     gMaxCount = 0;

void printArray( void )
{
    for ( int i = 0; i < gMaxX; i++ )
    {
        for ( int j = 0; j < gMaxY; j++ )
        {
            printf("%c", gArray[i][j] );
        }
        printf("\n");
    }
}
void printBlock( char aBlock[10][11],
                 int  aBlockMaxX,
                 int  aBlockMaxY )
{
    int i = 0;

    printf( "%d %d\n", aBlockMaxX, aBlockMaxY );
    for ( i = 0; i < aBlockMaxX; i++ )
    {
        printf("%s\n", aBlock[i] );
    }
}

void process( int x, int y );

int getBlockCount( char aBlock[10][11],
                   int  aBlockMaxX,
                   int  aBlockMaxY )
{
    int i = 0, j = 0;
    int sBlockCount = 0;

    for ( i = 0; i < aBlockMaxX; i++ )
    {
        for ( j = 0; j < aBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                sBlockCount++;
            }
        }
    }

    return sBlockCount;
}

void swap( int  * aX, int   * aY )
{
    int sTemp = 0;

    sTemp = *aX;
    *aX = *aY;
    *aY = *aX;
}

void rotateBlock( char aSrcBlock[10][11],
                  char aDstBlock[10][11] )
{
    int x = 0;
    int y = 0;

    for ( x = 0; x < gBlockMaxX; x++ )
    {
        for ( y = 0; y < gBlockMaxY; y++ )
        {
            aDstBlock[y][gBlockMaxX-x-1] = aSrcBlock[x][y];
        }
    }
}

void setMaxCount( int aTempMaxCount )
{
    if ( gMaxCount < aTempMaxCount )
    {
        gMaxCount = aTempMaxCount;
    }
    else
    {
        /* do nothing */
    }
}

void doNextStep( int x, int y )
{
    int sRemainX = 0;
    int sRemainY = 0;
    int sRemainBlockCount = 0;

    y++;

    if ( ( x == gMaxX-1 ) && 
         ( y == gMaxY-1 ) )
    {
        setMaxCount( gTempMaxCount );
        return;
    }

    /* 
     * 더이상 옆으로 이동을 못한다.
     * block 의 가로 길이가 남은길이보다 크다 
     */
    if ( ( gMaxY-1 == y ) ||
         ( gBlockMaxY > gMaxY-y ) )
    {
        x++;
        y = 0;
    }

    //sRemainX = gMaxX - x;
    //sRemainY = gMaxY - y;
    //sRemainBlockCount = sRemainX * sRemainY;

    //if ( sRemainBlockCount < gBlockCount )
    //{
    //    setMaxCount( gTempMaxCount );
    //    return;
    //}

    ///* block의 세로길이가 남은 길이보다 크다 */
    if ( gBlockMaxX > gMaxX - x )
    {
        setMaxCount( gTempMaxCount );
        return;
    }

    process( x, y );
}

int fitBlockFromArray( int  aX,
                       int  aY,
                       char aBlock[10][11] )
{
    int     i = 0;
    int     j = 0;
    int     sRC = TRUE;

    for ( i = 0; i < gBlockMaxX; i++ )
    {
        for ( j = 0; j < gBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                if ( gArray[aX+i][aY+j] == '.' )
                {
                    /* do nothing */
                }
                else
                {
                    /* do not fit */
                    sRC = FALSE;
                    break;
                }
            }
            else
            {
                /* do nothing */
            }
        }
    }

    return sRC;
}

void fillArrayFromBlock( int  aX,
                         int  aY,
                         char aBlock[10][11] )
{
    int i = 0;
    int j = 0;

    for ( i = 0; i < gBlockMaxX; i++ )
    {
        for ( j = 0; j < gBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                gArray[aX+i][aY+j] = '#';
            }
            else
            {
                /* do nothing */
            }
        }
    }
}

void recoverArrayFromBlock( int  aX,
                            int  aY,
                            char aBlock[10][11])
{
    int i = 0;
    int j = 0;

    for ( i = 0; i < gBlockMaxX; i++ )
    {
        for ( j = 0; j < gBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                gArray[aX+i][aY+j] = '.';
            }
            else
            {
                /* do nothing */
            }
        }
    }
}
                        
void processArray( int  aX, 
                   int  aY,
                   char aBlock[10][11] )
{
    if ( fitBlockFromArray( aX,
                            aY,
                            aBlock )
         == TRUE )
    {
        gTempMaxCount++;

        fillArrayFromBlock( aX, aY, aBlock );

        doNextStep( aX, aY );

        recoverArrayFromBlock( aX, aY, aBlock );

        gTempMaxCount--;
    }
}

void process( int x, int y )
{
    int     sIndex = 0;
    int     sTemp = 0;

    processArray( x, 
                  y, 
                  gBlock1 );

    swap( &gBlockMaxX, &gBlockMaxY );

    processArray( x, 
                  y, 
                  gBlock2 );
    swap( &gBlockMaxX, &gBlockMaxY );

    processArray( x, 
                  y, 
                  gBlock3 );
    swap( &gBlockMaxX, &gBlockMaxY );

    processArray( x, 
                  y, 
                  gBlock4 );
    swap( &gBlockMaxX, &gBlockMaxY );

    doNextStep( x, y );
}

void makeBlock( void )
{
    rotateBlock( gBlock1, gBlock2 );
    swap( &gBlockMaxX, &gBlockMaxY );

    rotateBlock( gBlock2, gBlock3 );
    swap( &gBlockMaxX, &gBlockMaxY );

    rotateBlock( gBlock3, gBlock4 );
    swap( &gBlockMaxX, &gBlockMaxY );
}

int main( void )
{
    int     sTestCount = 0;
    int     sIndex = 0;
    int     sRowIndex = 0;

    int     sTemp = 0;
    scanf( "%d", &sTestCount );

    for ( sIndex = 0; sIndex < sTestCount; sIndex++ )
    {
        gMaxCount = 0;
        gTempMaxCount = 0;

        /* input Arrary Size and Block Size */
        scanf( "%d %d %d %d", &gMaxX, &gMaxY, &gBlockMaxX, &gBlockMaxY );

        /* input gArray */
        for ( sRowIndex = 0; sRowIndex < gMaxX; sRowIndex++ )
        {
            scanf( "%s", gArray[sRowIndex] );
        }

        /* input gBlock */
        for ( sRowIndex = 0; sRowIndex < gBlockMaxX; sRowIndex++ )
        {
            scanf( "%s", gBlock1[sRowIndex] );
        }

        makeBlock();
        gBlockCount = getBlockCount( gBlock1,
                                     gBlockMaxX,
                                     gBlockMaxY );
        process( 0, 0 );

        printf( "%d\n", gMaxCount );
    }

    return 0;
}
