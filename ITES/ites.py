
from Queue import Queue

gLastSignal = 0

def gen() :
   
    global gLastSignal

    gLastSignal = ( ( gLastSignal *  214013 ) + 2531011 ) & 0xFFFFFFFF 

    return gLastSignal % 10000 + 1
 
def ites( aNumCount, aSumValue ) :

    sQueue = Queue()
    global gLastSignal

    gLastSignal = 1983

    sValue = gLastSignal
    sSumValue = sValue
    sCaseCount = 0

    if sSumValue == aSumValue :
         sSumValue = sSumValue - sValue
         sCaseCount = sCaseCount + 1
    else :
        sQueue.put( sValue );

        for sIndex in range( 1, aNumCount ) :
            sValue = gen()
            sQueue.put( sValue )
            sSumValue = sSumValue + sValue

            if sSumValue == aSumValue :
                sValue = sQueue.get()
                sSumValue = sSumValue - sValue;
                sCaseCount = sCaseCount + 1
            elif sSumValue > aSumValue :
                while sSumValue > aSumValue :
                    sValue = sQueue.get()
                    sSumValue = sSumValue - sValue

            if sSumValue == aSumValue :
                sValue = sQueue.get()
                sSumValue = sSumValue - sValue
                sCaseCount = sCaseCount + 1

    return sCaseCount


def main() :
    sCount = input()

    for i in range( sCount ) :
        sInput = raw_input()
        sInput_list = sInput.split()
        print ites( int( sInput_list[1] ), 
                    int( sInput_list[0] ) )

main()
#print ites( 20, 8791 )
#print ites( 5000, 5265 )
#print ites( 5000000, 3578452 )
