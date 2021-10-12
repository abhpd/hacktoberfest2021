import matplotlib.pyplot as plt
from math import sqrt

#Defing a function that draws a line between two points (given as tuples)
def plot_line(p1,p2):
    x = [p1[0], p2[0]]
    y = [p1[1], p2[1]]
    plt.plot(x, y)

#A function that draws a line between every given point in a tuple og tuples
def complete_graph(points):
    #For every point in points, the loop finds p1 and connects it to every other
    #point in 'points' by looping through the list again
    for i in range(1, len(points)):
        p1 = points[i-1]
        for n in range(i, len(points)):
            p2 = points[n]
            plot_line(p1, p2)
    plt.show()

    
a = sqrt(2)/2
complete_graph(((1, 0),(a, a),(0, 1),(-a, a),(-1, 0),(-a, -a),(0, -1),(a, -a)))
