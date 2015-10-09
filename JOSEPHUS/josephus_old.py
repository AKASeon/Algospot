
class Node :
    def __init__( self, aValue ) :
        self.mValue = aValue
        self.mNext = None

    def getValue( self ) :
        return self.mValue 

    def getNext( self ) :
        return self.mNext

    def setNext( self, aNext ) :
        self.mNext = aNext

    def __iter__( self ) :
        return self
 
    def next( self ) :
        if self.mNext is not None :
            print self, self.mNext
            return self.mNext
        else :
            raise StopIteration

class Node_Iter :

    mNext = [];
    def next( self )
        if self.mNext is not None :
            a = self.mNext
            self.mNext =self.mNext
            #print self, self.mNext
            return a
        else :
            raise StopIteration

class CircularList :

    def __init__( self ) :
        self.mHead = None
        self.mTail = None
        self.mCount = 0

    def append( self, aValue ) :
        sNode = Node( aValue )
        self.mCount = self.mCount + 1

        if self.mTail is not None :
            self.mTail.setNext( sNode )
            self.mTail = sNode
        else :
            self.mTail = sNode

        if self.mHead is None :
            self.mHead = sNode 

    def remove( self, aValue ) :
        sPrevious = None

        for sNode in self.mHead :
            if sNode.getValue() is aValue :
                if sPrevious is not None :
                    sPrevious.setNext( sNode.getNext() ) 
                    
            sPrevious = sNode 

        if self.mHead is sNode :
            self.mHead = None 

        if self.mTail is sNode :
            mTail = sPrevious


    def printList( self ) :

        #while True :
        #    print sNode.getValue()
        #    sNode = sNode.next()
        #    if sNode is None :
        #        break;
        sCount = 0

        print self.mHead.getValue()

        for sNode in self.mHead :
            print sNode, sNode.getValue()

            sCount = sCount + 1
            if sCount is 4 :
                break

            #self.remove( sNode.getValue() )



test = CircularList()
test.append( 1 )
test.append( 2 )
test.append( 3 )
test.append( 4 )

test.printList()

