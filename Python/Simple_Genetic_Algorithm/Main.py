import PySimpleGUI as sg
import random, sys, os
from Entity import Entity
from operator import attrgetter
import matplotlib.pyplot as plt

#My equation: sen(x^(3))+cos(y^(2)) + 4z
#Creating the Window: 

def createGraph(bestIndividualsFitness, worstIndividualsFitness, averageIndividualsFitness,generationsList):
    plt.plot(bestIndividualsFitness)
    plt.plot(worstIndividualsFitness)
    plt.plot(averageIndividualsFitness)
    plt.legend((['Best case', 'Worst case', 'Average case']))
    plt.title('Resultados obtenidos')
    plt.xlabel('Generacion')
    plt.ylabel('Fitness')
    plt.show()

def printList(entitiesList):
    for i in range(len(entitiesList)):
        print("Entity: " + entitiesList[i].name)
        print("X: " + str(entitiesList[i].xValue))
        print("Y: " + str(entitiesList[i].yValue))
        print("Z: " + str(entitiesList[i].zValue))
        print("Fitness (f(x)) value: " + str(entitiesList[i].fitness))
        print("*********************************************************")

def updateTotalFitness(entitiesList):
    totalFitness = 0
    for entity in entitiesList:
        totalFitness += entity.fitness
    return totalFitness

def updateRoulettePercentages(totalFitness,entitiesList):
    placeInGraph = 0
    for entity in entitiesList:
        rangeInGraph = []
        rangeInGraph.append(placeInGraph)
        percentage = ((entity.fitness * 100)/totalFitness)
        placeInGraph += percentage
        rangeInGraph.append(placeInGraph)
        entity.updatePercentage(percentage)
        entity.updateRangeInGraph(rangeInGraph)

def calculate(entitiesList,generations,minRange,maxRange, maxPopulation,maximize):
    breedProbabilty = random.randint(60,90)/100
    print("Probabilidad de cruza: " + str(breedProbabilty))
    createdIndividuals = len(entitiesList)

    bestIndividualsFitness = []
    worstIndividualsFitness = []
    averageIndividualsFitness = []
    generationsList = []

    for i in range(generations):
        print("___________________________________GENERATION:___________________________________ " + str(i+1))
        totalFitness = updateTotalFitness(entitiesList)
        updateRoulettePercentages(totalFitness,entitiesList)
        #Selecting entities randomly to breed
        population = len(entitiesList)
        probabilities = []
        selectedParents = []
        for i in range(population):
            probabilities.append(random.random() * 100)
        
        for entity in entitiesList:
            for probability in probabilities:
                if probability >= entity.rangeInGraph[0] and probability <= entity.rangeInGraph[1]:
                    selectedParents.append(entity)

        probabilitiesOfMating = []
        numberOfPairs = int(len(selectedParents)/2)
        for i in range(numberOfPairs):
            if(maximize):
                probabilitiesOfMating.append(random.randint(0,100)/100)
            else:
                probabilitiesOfMating.append(random.randint(-100,100)/100)
        breedingPoint = random.randint(0,24) #Chromosome size
        counter = 0
        pair = 0
        matingCounter = 0
        matingPartners = []
        children = []
        breed = True
        for parent in selectedParents:
            if counter < len(probabilitiesOfMating)-1:
                if probabilitiesOfMating[counter] <= breedProbabilty or (pair == 1 and breed):
                    matingPartners.append(parent)
                else:
                    breed = False  
                    
                pair += 1

                if pair == 2 and breed:
                    parent1 = matingPartners[matingCounter]
                    parent2 = matingPartners[matingCounter+1]
                    firstDescendant = '' + parent1.chromosome[0:breedingPoint] + parent2.chromosome[breedingPoint:24]
                    secondDescendant = '' + parent2.chromosome[0:breedingPoint] + parent1.chromosome[breedingPoint:24]

                    xValue = firstDescendant[0:8]
                    yValue = firstDescendant[8:16]
                    zValue = firstDescendant[16:24]

                    createdIndividuals += 1
                    child1 = Entity("EN" + str(createdIndividuals), int(xValue,2), int(yValue,2), int(zValue,2))
                    entitiesList.append(child1)
                    children.append(child1)

                    xValue = secondDescendant[0:8]
                    yValue = secondDescendant[8:16]
                    zValue = secondDescendant[16:24]

                    createdIndividuals += 1
                    child2 = Entity("EN" + str(createdIndividuals), int(xValue,2), int(yValue,2), int(zValue,2))
                    entitiesList.append(child2)
                    children.append(child2)
                    matingCounter += 2
                    pair = 0
                    counter += 1
                elif pair == 2:
                    pair = 0
                    counter += 1
                    breed = True

        updateTotalFitness(entitiesList)
        updateRoulettePercentages(totalFitness,entitiesList)
        #END OF BREEDING

        #*****************************************MUTATION*****************************************

        population = len(entitiesList)

        mutationProbability1 = int((1/population)*100)
        mutationProbability2 = int((1/24)*100)
        mutationProbability = 0

        if mutationProbability1 > mutationProbability2:
            mutationProbability = random.randint(mutationProbability2,mutationProbability1)
        else:
            mutationProbability = random.randint(mutationProbability1, mutationProbability2)

        mutationProbability = mutationProbability/100
        print("Probabilidad de mutacion: " + str(mutationProbability))

        for child in children:
            newChromosome = ''
            for chromosome in child.chromosome:
                mutate = (random.randint(0,100))/100
                if mutate <= mutationProbability:
                    if chromosome == 0:
                        chromosome = 1
                    else:
                        chromosome = 0  

                newChromosome += str(chromosome)
            xValue = newChromosome[0:8]
            yValue = newChromosome[8:16]
            zValue = newChromosome[16:24]
            child.mutate(int(xValue,2), int(yValue,2), int(zValue,2)) 


        totalFitness = updateTotalFitness(entitiesList)
        updateRoulettePercentages(totalFitness,entitiesList)
        population = len(entitiesList)

        #END OF MUTATION

        ##CONSISTENCY
        extinctList = []
        for entity in entitiesList:
            if entity.xValue < minRange or entity.xValue > maxRange:
                extinctList.append(entity)
            elif entity.yValue < minRange or entity.yValue > maxRange:
                extinctList.append(entity)
            elif entity.zValue < minRange or entity.zValue > maxRange:
                extinctList.append(entity)
                

        

        for extinct in extinctList:
            entitiesList.remove(extinct)
        ##END OF CONSISTENCY

        ##PODA
        entitiesList = sorted(entitiesList, key = attrgetter('fitness'))
        while(population > maxPopulation and entitiesList):
            if maximize:
                entitiesList.pop(0)
            else:
                entitiesList.pop()
            population -= 1
        
        ##END OF PODA

        ##START OF GRAPH: 
        if entitiesList:
            totalFitness = updateTotalFitness(entitiesList)
            updateRoulettePercentages(totalFitness,entitiesList)
            population = len(entitiesList)

            bestFitness = entitiesList[len(entitiesList) - 1].fitness
            worstFitness = entitiesList[0].fitness
            averageFitness = totalFitness/population

            if maximize: 
                bestIndividualsFitness.append(bestFitness)
                worstIndividualsFitness.append(worstFitness)
                averageIndividualsFitness.append(averageFitness)
            else:
                bestIndividualsFitness.append(worstFitness)
                worstIndividualsFitness.append(bestFitness)
                averageIndividualsFitness.append(averageFitness)

            generationsList.append(i)
            
    createGraph(bestIndividualsFitness,worstIndividualsFitness,averageIndividualsFitness,generationsList)
    


#################################################################################


def createFirstIndividuals(minRange, maxRange,startingPopulation):
    entitiesList = []
    totalFitness = 0
    for i in range(startingPopulation):
        #self,name,xValue,yValue,zValue
        entitiesList.append(Entity( name= "EN" + str((i+1)), xValue= random.randint(minRange,maxRange), yValue= random.randint(minRange,maxRange), zValue= random.randint(minRange,maxRange)))
        totalFitness += entitiesList[i].fitness

    print("Total fitness: " + str(totalFitness))

    updateRoulettePercentages(totalFitness,entitiesList)

    return entitiesList



#**************************************
#*****************MAIN*****************
#**************************************


sg.theme('DarkTanBlue')   

layout = [  [sg.Text('Ingrese los valores solicitados.',size=(0,0),auto_size_text=True)],
            [sg.Text('Población inicial:   '), sg.InputText(key='startingPopulation')],
            [sg.Text('Población máxima:'), sg.InputText(key='maxPopulation')],
            [sg.Text('# generaciones:     '), sg.InputText(key='generations')],
            [sg.Radio('Maximizar','radioGroup',default= True,key='max'), sg.Radio('Minimizar','radioGroup',default=False, key='min')],
            [sg.Text('Rango a evaluar: '), sg.InputText(key = 'minRange',size = (5,5)), sg.Text(' - '), sg.InputText(key = 'maxRange', size=(5,5)) ],
            [sg.Submit("Ok"), sg.Cancel('Cancel')] ]

window = sg.Window('Algoritmo genético', layout,margins=(100,50))

while True:
    event, values = window.read()
    if event == sg.WIN_CLOSED or event == 'Cancel': # if user closes window or clicks cancel
        break

    #try:
    startingPopulation = values['startingPopulation']
    maxPopulation = values['maxPopulation']
    generations = values['generations']
    maximizeInput = values['max']
    minRange = values['minRange']
    maxRange = values['maxRange']
    if startingPopulation.strip() and maxPopulation.strip() and generations.strip() and minRange and maxRange:
        startingPopulation = int(startingPopulation)
        maxPopulation = int(maxPopulation)
        generations = int(generations)
        minRange = int(minRange)
        maxRange = int(maxRange)
        entitiesList = createFirstIndividuals(minRange,maxRange,startingPopulation)
        calculate(entitiesList, generations,minRange,maxRange,maxPopulation,maximizeInput)
        
    else:
        sg.Popup('An error has occured!','Please, fill all the fields.')
#except Exception as e:
#    exc_type, exc_obj, exc_tb = sys.exc_info()
#    fname = os.path.split(exc_tb.tb_frame.f_code.co_filename)[1]
#   print(exc_type, fname, exc_tb.tb_lineno)
#    print(e)

     #   sg.Popup('An error has occured!', 'Please, only use numbers.')
    

window.close()
