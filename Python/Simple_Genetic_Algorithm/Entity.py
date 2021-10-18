import math

class Entity:
    
    def __init__(self,name,xValue,yValue,zValue):
        self.name = name
        self.xValue = xValue
        self.yValue = yValue
        self.zValue = zValue
        self.chromosome = self.calculateChromosome(xValue,yValue,zValue)
        self.fitness = self.calculateFitness(xValue,yValue,zValue)

    #My equation: sen(x^(3))+cos(y^(2)) + 4z
    def calculateFitness(self, xValue,yValue,zValue):
        solvedEquation = math.sin(math.pow(xValue,3)) + math.cos(math.pow(yValue,2)) + (4 * zValue) #Change equation
        return solvedEquation

    def calculateChromosome(self, xValue, yValue, zValue):
        fullBinary = ''
        for i in range(3):
            if i == 0:
                binary= format(xValue,'b')
            elif i == 1:
                binary= format(yValue,'b')
            elif i == 2: 
                binary = format(zValue,'b')

            while len(binary) < 8:
                binary = '0' + binary  
            fullBinary += binary 
        return fullBinary

    def updatePercentage(self,percentage):
        self.percentage = percentage

    def updateRangeInGraph(self,rangeInGraph):
        self.rangeInGraph = rangeInGraph
        
    def mutate(self,xValue, yValue, zValue):
        self.xValue = xValue
        self.yValue = yValue
        self.zValue = zValue
        self.chromosome = self.calculateChromosome(xValue,yValue,zValue)
        self.fitness = self.calculateFitness(xValue,yValue,zValue)
