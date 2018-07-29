
gBracketMap = { "}": "{",
                ")": "(",
                "]": "[" }

def isOpen( aBracket ) :
    if ( aBracket in ( "{", "(", "[" ) ) :
        return True
    else :
        return False

def solve( aInput ) :

    sStack = []

    for sItem in aInput :
        if isOpen( sItem ) is True :
            sStack.append( sItem )
        else :
            if len( sStack ) == 0 :
                return "NO"

            if sStack.pop() != gBracketMap.get( sItem ) :
                return "NO"

    if len( sStack ) != 0 :
        return "NO"

    return "YES"


def main() :
    sCount = input()

    for i in range( sCount ) :
        print solve( raw_input() )

main()





