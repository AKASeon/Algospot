def getLeftMax( aFenceList, aIndex, aListCount ) :

    sContinueCount = 0
    sIndex = 0
    for sIndex in xrange( 0, aIndex ) :
        if aFenceList[sIndex] > aFenceList[aIndex] :
            sContinueCount = sContinueCount + 1
        elif aFenceList[sIndex] == aFenceList[aIndex] :
            sContinueCount = sContinueCount + 1
        else :
            print 'LeftMax : ', sIndex, aIndex, sContinueCount 
            return sContinueCount 

    print 'LeftMax1 : ', sIndex, aIndex, sContinueCount

    return sContinueCount

def getRightMax( aFenceList, aIndex, aListCount ) :

    sContinueCount = 0
    sIndex = 0
    for sIndex in xrange( aIndex+1, aListCount ) :
        if aFenceList[sIndex] > aFenceList[aIndex] :
            sContinueCount = sContinueCount + 1
        elif aFenceList[sIndex] == aFenceList[aIndex] :
            sContinueCount = sContinueCount + 1
        else :
            print 'RightMax : ', sIndex, aIndex, sContinueCount
            return sContinueCount

    print 'RightMax1 : ', sIndex, aIndex, sContinueCount

    return sContinueCount

def getMaxSize( aFenceList, aIndex, aListCount ) :

    sContinueCount = 0;

    sContinueCount = getLeftMax( aFenceList, aIndex, aListCount ) + getRightMax( aFenceList, aIndex, aListCount )

    print 'getMaxSize', aFenceList[aIndex],  sContinueCount

    return aFenceList[aIndex] * sContinueCount

def solve( aFenceList, aListCount ):

    sTempMaxSize = 0
    sMaxSize = 0
    sContinue = True
    sContinueCount = 0

    for sIndex in xrange(0, len(aFenceList)) :
        sTempMaxSize = getMaxSize( aFenceList, sIndex, aListCount )
        print 'Temp MAX : ', aFenceList[sIndex], sIndex, sTempMaxSize
        if sTempMaxSize > sMaxSize :
            sMaxSize = sTempMaxSize

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
