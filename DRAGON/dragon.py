
def getLength( aArray,
               aTarget ) :

    if aTarget == 0 :
        aArray[0] = 2
        return aArray[0]

    if aArray[aTarget] != 0 :
        return aArray[aTarget]

    sLength = 0

    if aArray[aTarget-1] != 0 :
        sLength = aArray[aTarget-1]
    else :
        sLength = getLength( aArray,
                             aTarget - 1 )

    sLength = sLength * 2 + 1
    aArray[aTarget] = sLength

    return aArray[aTarget]


def solveX( aArray,
            aGen,
            aTarget,
            aLength ) :

    if aLength == 0 :
        return ''

    if aGen == 0 :
        if aLength == 1 :
            return 'F'
        else :
            return 'FX'

    sResult = ''

    sTarget = aTarget - aArray[aGen-1]

    print 'X', sTarget, aTarget, aArray[aGen-1], aGen, aLength

    if sTarget < 0 :
        sResult = solveX( aArray, aGen-1, aTarget, aLength )

        sLength = aLength - len(sResult)

        if sLength == 1 :
            sResult = sResult + '+'
        elif sLength > 1 :
            sResult = sResult + '+' + solveY( aArray, aGen-1, 1, sLength - 1 )
    elif sTarget == 1 :
        sResult = '+' + solveY( aArray, aGen-1, 1, aLength - 1 )
    else :
        sResult = solveY( aArray, aGen-1, sTarget-1, aLength )

    return sResult

def solveY( aArray,
            aGen,
            aTarget,
            aLength ) :

    if aLength == 0 :
        return ''

    if aGen == 0 :
        if aLength == 1 :
            return 'Y'
        else :
            return 'YF'

    sResult = ''

    sTarget = aTarget - aArray[aGen-1]

    print 'Y', sTarget, aTarget, aArray[aGen-1], aGen, aLength

    if sTarget < 0 :
        sResult = solveX( aArray, aGen-1, aTarget, aLength )

        sLength = aLength - len(sResult)
        if sLength == 1 :
            sResult = sResult + '-'
        elif sLength > 1 :
            sResult = sResult + '-' + solveY( aArray, aGen-1, 1, sLength - 1 )
    elif sTarget == 1 :
        sResult = '-' + solveY( aArray, aGen-1, 1, aLength - 1 )
    else :
        sResult = solveY( aArray, aGen-1, sTarget-1, aLength )

    return sResult

def solve() :

    sArray = [0] * 51
    getLength( sArray, 50 )

    sTestCount = input()

    for _ in range( sTestCount ) :
        sInput = raw_input().split()

        print solveX( sArray, int(sInput[0]), int(sInput[1]), int(sInput[2]) )

solve()
