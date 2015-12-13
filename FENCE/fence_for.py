`def solve( aFenceList, aListCount ):

    sTempMaxSize = 0
    sMaxSize = 0
    sContinue = True
    sContinueCount = 0

    sSize = max( aFenceList )

    #print "MaxSIze = ", sSize
    #print aFenceList
    while ( sContinue ) :

        #sContinue = False
        sTempMaxSize = 0

        for sIndex in xrange(0, len(aFenceList)) :
            #print sIndex, sSize, aFenceList[sIndex]
            #print aFenceList
            if aFenceList[sIndex] > sSize :
                sContinueCount = sContinueCount + 1
                #sContinue = True
            elif aFenceList[sIndex] == sSize :
                sContinueCount = sContinueCount + 1
                #sContinue = True
            else :
                sTempMaxSize = sContinueCount * sSize

                if sMaxSize < sTempMaxSize :
                    #print "DEBUG ", sIndex, sSize, aFenceList[sIndex]
                    #print "MAX Size = ", sTempMaxSize, sContinueCount
                    sMaxSize = sTempMaxSize;

                sContinueCount = 0

        sTempMaxSize = sContinueCount * sSize

        if sMaxSize < sTempMaxSize :
            #print "DEBUG ", sIndex, sSize, aFenceList[sIndex]
            #print "MAX Size = ", sTempMaxSize, sContinueCount
            sMaxSize = sTempMaxSize;
            sContinueCount = 0

        sSize = sSize - 1
        sContinueCount = 0

        if sSize < 1 :
            sContinue = False

        sTempMaxSize = sSize * aListCount
        if sTempMaxSize < sMaxSize :
            sContinue = False

    return sMaxSize

def main() :
    sCount = input()

    for i  in range( sCount ) :
        sNumCount = input()
        sInput = raw_input()
        sFenceList = sInput.split()

        sFenceList = [int(num) for num in sFenceList ]

        print solve( sFenceList, sNumCount )

main()
