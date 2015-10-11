
def alphabetToNumber( aAlphabet ) :
    return ord(aAlphabet) - ord('a')

def numberToAlphabet( aNumber ) :
    return chr(aNumber+ord('a'))

class Vertex:
    def __init__(self,key):
        self.id = numberToAlphabet( key )
        self.connectedTo = {}
        self.color =''

    def addNeighbor(self,nbr,weight=0):
        self.connectedTo[nbr] = weight

    def __str__(self):
        return str(self.id) + ' connectedTo: ' + str([x.id for x in self.connectedTo])

    def getConnections(self):
        return self.connectedTo.keys()

    def getId(self):
        return self.id

    def getWeight(self,nbr):
        return self.connectedTo[nbr]
 
    def setColor(self,color) :
        self.color = color

    def getColor(self) :
        return self.color

class Graph:
    def __init__(self):
        self.vertList = {}
        self.numVertices = 0

    def addVertex(self,key):
        self.numVertices = self.numVertices + 1
        newVertex = Vertex(key)
        self.vertList[key] = newVertex
        return newVertex

    def getVertex(self,n):
        if n in self.vertList:
            return self.vertList[n]
        else:
            return None

    def __contains__(self,n):
        return n in self.vertList

    def addEdge(self,f,t,cost=0):
        self.vertList[f].addNeighbor(self.vertList[t], cost)

    def getVertices(self):
        return self.vertList.keys()

    def __iter__(self):
        return iter(self.vertList.values())
 
    # add user-defined function
    def printGraph(self) :
        for n in self.vertList :
            print self.vertList[n]

class TopologicalSort(Graph) :
    def __init__( self ) :
        Graph.__init__(self)
        self.resultValueList = []
        self.isCycle = False

    def TopologicalSort(self):
        path = []

        for aVertex in self:
            aVertex.setColor('white')
            
        for aVertex in self:
            if aVertex.getColor() == 'white':
                self.dfsvisit(aVertex, path)
                
        self.resultValueList.reverse()

    def dfsvisit(self, startVertex, path):

        if self.isCycle is True :
            return 

        startVertex.setColor('gray')
        path.append( startVertex )

        for nextVertex in startVertex.getConnections():
           
            if nextVertex.getColor() == 'white':
                self.dfsvisit(nextVertex, path)
            else : 
                if nextVertex in path :
                    self.isCycle = True
                
        startVertex.setColor('black')
        path.remove( startVertex )
        self.resultValueList.append( startVertex )
        
    def printSortedList(self) :
        if self.isCycle is not True :
            print ''.join( sItem.getId() for sItem in self.resultValueList )
        else :
            print 'INVALID HYPOTHESIS'

def findCommonPatterns( aString1,
                        aString2 ) :
    sMatchEndIndex = -1

    for i in range(1,len(aString1)+1) :
        substr = aString1[0:i]
        sIndex = aString2.find( substr )

        if sIndex is not 0 :
            break
        else :
            sMatchEndIndex = i

    return sMatchEndIndex

def makeGraph( aGraph,  aInput ) :
   
    sBeforeString = ''

    for sString in aInput : 
        sIndex = findCommonPatterns( sBeforeString, sString )

        if sIndex is -1 :
            sIndex = 0

        if len(sBeforeString) > sIndex and \
           len(sString) > sIndex :
            aGraph.addEdge( alphabetToNumber( sBeforeString[sIndex]),
                            alphabetToNumber( sString[sIndex] ) )
        
        sBeforeString = sString 
        
def dictionary( aInput ) :

    dict = TopologicalSort();
    for i in range(26) :
        dict.addVertex(i)

    makeGraph( dict, aInput )

    dict.TopologicalSort()
    dict.printSortedList()

def main() :
    sTestCount = input()

    for i in range( sTestCount ) :
        sStringList = []

        sStringCount = input() 

        for sStringIndex in range( sStringCount ) :
            sString = raw_input()
            sStringList.append( sString )

        dictionary( sStringList )

main()
