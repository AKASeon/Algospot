#include <stdio.h>

#include <queue>

typedef struct signalSet
{
    std::queue<unsigned short> mQueue;
    int                        mSumValue;
} signalSet;

unsigned int gLastSignal = 0;

unsigned short gValue[50000000];

unsigned short gen( void )
{
    //unsigned long     sSignal = 0;
    unsigned int      sSignal = 0;
    unsigned short    sResult = 0;

    sSignal = ( ( gLastSignal *  214013 ) + 2531011 );// % 4294967296;
    gLastSignal = sSignal;
    sResult = gLastSignal % 10000 + 1;

    return sResult;
}

int handleSignal( signalSet     * aSignalSet,
                  unsigned short  aNewValue,
                  int             aSumValue )
{
    unsigned short  sValue = 0;
    int             sCaseCount = 0;

    aSignalSet->mQueue.push( aNewValue );
    aSignalSet->mSumValue += aNewValue;

    while( aSumValue < aSignalSet->mSumValue )
    {
        sValue = aSignalSet->mQueue.front();
        aSignalSet->mQueue.pop();

        aSignalSet->mSumValue -= sValue;
    }

    if ( aSumValue == aSignalSet->mSumValue )
    {
        sValue = aSignalSet->mQueue.front();
        aSignalSet->mQueue.pop();

        aSignalSet->mSumValue -= sValue;

        sCaseCount++;
    }

    return sCaseCount;
}

int getCaseCount( int aNumCount, int aSumValue )
{
    int sIndex = 0;
    int sCaseCount = 0;
    int sValue = 0;

    signalSet   sSignalSet;

    sSignalSet.mSumValue = 0;

    sValue = 1983;
    gLastSignal = sValue;

    sCaseCount += handleSignal( &sSignalSet,
                                sValue,
                                aSumValue );
    
    for ( sIndex = 1; sIndex < aNumCount; sIndex++ )
    {
        sValue = gen();

        sCaseCount += handleSignal( &sSignalSet,
                                    sValue,
                                    aSumValue );
    }

    return sCaseCount;
}

int main( void )
{
    int     sIndex = 0;
    int     sCaseCount = 0;
    int     sNumValue = 0;
    int     sSumValue = 0;

    scanf("%d", &sCaseCount );

    for ( sIndex = 0; sIndex < sCaseCount; sIndex++ )
    {
        scanf("%d %d", &sSumValue, &sNumValue );
        printf("%d\n", getCaseCount( sNumValue, sSumValue ) );
    }

    return 0;
}
