gOutputArray = [ i for i in range(50000) ]
gInputArray = [ i for i in range(50000) ]

def solve(aMoveArray, aLength) :

    for sIndex in range( aLength ) :
        #print '1st: ', sIndex, aMoveArray[sIndex]

        for sMove in range( 0, int(aMoveArray[sIndex]) ) :
            #print '2nd: ', sIndex-sMove, sIndex-sMove-1
            gInputArray[sIndex-sMove], gInputArray[sIndex-sMove-1] = \
                    gInputArray[sIndex-sMove-1], gInputArray[sIndex-sMove]

    for sIndex in range( aLength ):
        gOutputArray[gInputArray[sIndex]] = sIndex + 1
        gInputArray[sIndex] = sIndex

    print ' '.join(str(item) for item in gOutputArray[:aLength])

def main() :
    sCount = input()

    for i in range( sCount ) :
        sLength = input();
        sMoveArray = raw_input().split()

        solve( sMoveArray, sLength )

main()
