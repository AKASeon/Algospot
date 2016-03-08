#include <stdio.h>
#include <string.h>

#define TRUE    1
#define FALSE   0

char    gArray[10][11] = { 0, };

int     gArrayBlockCount[10] = { 0, };
int     gArrayCount = 0;

int     gMaxX = 0;
int     gMaxY = 0;

/* original */
char    gBlock1[10][11] = { 0, };
int     gBlock1MaxX = 0;
int     gBlock1MaxY = 0;

char    gBlock2[10][11] = { 0, };
int     gBlock2MaxX = 0;
int     gBlock2MaxY = 0;

char    gBlock3[10][11] = { 0, };
int     gBlock3MaxX = 0;
int     gBlock3MaxY = 0;

char    gBlock4[10][11] = { 0, };
int     gBlock4MaxX = 0;
int     gBlock4MaxY = 0;

int     gBlockCount = 0;


int     gTempMaxCount = 0;
int     gMaxCount = 0;

int     gMaxFitBlockCount = 0;

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

void process( int x, int y, int step );


void rotateBlock( char aSrcBlock[10][11],
                  int  aSrcBlockMaxX,
                  int  aSrcBlockMaxY,
                  char aDstBlock[10][11] )
{
    int x = 0;
    int y = 0;

    for ( x = 0; x < aSrcBlockMaxX; x++ )
    {
        for ( y = 0; y < aSrcBlockMaxY; y++ )
        {
            aDstBlock[y][aSrcBlockMaxX-x-1] = aSrcBlock[x][y];
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

void doNextStep( int x, int y, int aBlockMaxX, int aBlockMaxY, int step )
{
    y++;

    //if ( ( x == gMaxX-1 ) && 
    //     ( y == gMaxY-1 ) )
    //{
    //    setMaxCount( gTempMaxCount );
    //    return;
    //}

    /* 
     * 더이상 옆으로 이동을 못한다.
     * block 의 가로 길이가 남은길이보다 크다 
     */
    if ( ( gMaxY-1 == y ) ||
         ( aBlockMaxY > gMaxY-y ) )
    {
        x++;
        y = 0;

        if ( step == 0 )
        {
            gArrayCount -= gArrayBlockCount[x-1];
        }
    }

    /*
     * block의 세로길이가 남은 길이보다 크다 
     */
    if ( aBlockMaxX > gMaxX - x )
    {
        setMaxCount( gTempMaxCount );
        return;
    }

    if ( gArrayCount < gBlockCount )
    {
        setMaxCount( gTempMaxCount );
        return;
    }

    process( x, y, step );
}

int fitBlockFromArray( int  aX,
                       int  aY,
                       char aBlock[10][11],
                       int  aBlockMaxX,
                       int  aBlockMaxY )
{
    int     i = 0;
    int     j = 0;
    int     sRC = TRUE;

    for ( i = 0; i < aBlockMaxX; i++ )
    {
        for ( j = 0; j < aBlockMaxY; j++ )
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
                         char aBlock[10][11],
                         int  aBlockMaxX,
                         int  aBlockMaxY )
{
    int i = 0;
    int j = 0;
    int sRemain = gBlockCount;

    for ( i = 0; i < aBlockMaxX; i++ )
    {
        for ( j = 0; j < aBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                gArray[aX+i][aY+j] = '#';
                sRemain--;
            }
            else
            {
                /* do nothing */
            }

            if ( sRemain == 0 )
                return;
        }
    }
}

void recoverArrayFromBlock( int  aX,
                            int  aY,
                            char aBlock[10][11],
                            int  aBlockMaxX,
                            int  aBlockMaxY )
{
    int i = 0;
    int j = 0;
    int sRemain = gBlockCount;

    for ( i = 0; i < aBlockMaxX; i++ )
    {
        for ( j = 0; j < aBlockMaxY; j++ )
        {
            if ( aBlock[i][j] == '#' )
            {
                gArray[aX+i][aY+j] = '.';
                sRemain--;
            }
            else
            {
                /* do nothing */
            }

            if ( sRemain == 0 )
                return;
        }
    }
}
                        
int processArray( int  aX, 
                  int  aY,
                  char aBlock[10][11],
                  int  aBlockMaxX,
                  int  aBlockMaxY,
                  int  aStep)
{
    if ( fitBlockFromArray( aX,
                            aY,
                            aBlock,
                            aBlockMaxX,
                            aBlockMaxY )
         == TRUE )
    {
        gTempMaxCount++;

        fillArrayFromBlock( aX, aY, aBlock, aBlockMaxX, aBlockMaxY );
        gArrayCount -= gBlockCount;

        doNextStep( aX, aY, aBlockMaxX, aBlockMaxY, aStep );

        if ( gMaxCount == gMaxFitBlockCount )
            return FALSE;

        recoverArrayFromBlock( aX, aY, aBlock, aBlockMaxX, aBlockMaxY );
        gArrayCount += gBlockCount;

        gTempMaxCount--;
    }

    return TRUE;
}

void process( int x, int y, int step )
{
    int     sIndex = 0;
    int     sTemp = 0;
    int     sContinue = TRUE;

    sContinue = processArray( x, 
                  y, 
                  gBlock1,
                  gBlock1MaxX,
                  gBlock1MaxY,
                  step+1);

    if ( sContinue == TRUE )
        sContinue = processArray( x, 
                  y, 
                  gBlock2,
                  gBlock2MaxX,
                  gBlock2MaxY,
                  step+1);


    if ( sContinue == TRUE )
        sContinue = processArray( x, 
                  y, 
                  gBlock3,
                  gBlock3MaxX,
                  gBlock3MaxY,
                  step+1);

    if ( sContinue == TRUE )
        sContinue = processArray( x, 
                  y, 
                  gBlock4,
                  gBlock4MaxX,
                  gBlock4MaxY,
                  step+1);

    if ( sContinue == TRUE )
        doNextStep( x, y, gBlock1MaxX, gBlock1MaxY, step );
}

void makeBlock( void )
{
    rotateBlock( gBlock1, gBlock1MaxX, gBlock1MaxY, gBlock2 );
    gBlock2MaxX = gBlock1MaxY;
    gBlock2MaxY = gBlock1MaxX;

    rotateBlock( gBlock2, gBlock2MaxX, gBlock2MaxY, gBlock3 );
    gBlock3MaxX = gBlock2MaxY;
    gBlock3MaxY = gBlock2MaxX;

    rotateBlock( gBlock3, gBlock3MaxX, gBlock3MaxY, gBlock4 );
    gBlock4MaxX = gBlock3MaxY;
    gBlock4MaxY = gBlock3MaxX;
}

int getBlockCount( char    aBlockArray[10][11],
                   int     aMaxX,
                   int     aMaxY )
{
    int i = 0;
    int j = 0;
    int sCount = 0;

    for ( i = 0; i < aMaxX; i++ )
    {
        for ( j = 0; j < aMaxY; j++ )
        {
            if ( aBlockArray[i][j] == '#' )
            {
                sCount++;
            }
        }
    }

    return sCount;
}

void getArrayBlockCount( void )
{
    int i = 0;
    int j = 0;

    gArrayCount = 0;

    for ( i = 0; i < gMaxX; i++ )
    {
        gArrayBlockCount[i] = 0;

        for ( j = 0; j < gMaxY; j++ )
        {
            if ( gArray[i][j] == '.' )
            {
                gArrayBlockCount[i]++;
            }
        }
        gArrayCount += gArrayBlockCount[i];
    }
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
        scanf( "%d %d %d %d", &gMaxX, &gMaxY, &gBlock1MaxX, &gBlock1MaxY );

        /* input gArray */
        for ( sRowIndex = 0; sRowIndex < gMaxX; sRowIndex++ )
        {
            scanf( "%s", gArray[sRowIndex] );
        }

        /* input gBlock */
        for ( sRowIndex = 0; sRowIndex < gBlock1MaxX; sRowIndex++ )
        {
            scanf( "%s", gBlock1[sRowIndex] );
        }

        makeBlock();
    
        gBlockCount = getBlockCount( gBlock1,
                                     gBlock1MaxX,
                                     gBlock1MaxY );

        getArrayBlockCount();

        gMaxFitBlockCount = 50 / gBlockCount;

        process( 0, 0, 0 );

        printf( "%d\n", gMaxCount );
    }

    return 0;
}
