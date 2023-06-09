#python code for mkonty hall simulator game

import random
from random import seed, randint
import numpy

def game(winningdoor, selecteddoor, change=False):
    assert winningdoor < 3
    assert winningdoor >= 0

    # Presenter removes the first door that was not selected neither winning
    removeddoor = next(i for i in range(3) if i != selecteddoor and i != winningdoor)

    # Player decides to change its choice
    if change:
        selecteddoor = next(i for i in range(3) if i != selecteddoor and i != removeddoor)

    # We suppose the player never wants to change its initial choice.
    return selecteddoor == winningdoor


if __name__ == '__main__':
    playerdoors = numpy.random.random_integers(0,2, (1000 * 1000 * 1,))

    winningdoors = [d for d in playerdoors if game(1, d)]
    print("Winning percentage without changing choice: ", len(winningdoors) / len(playerdoors))

    winningdoors = [d for d in playerdoors if game(1, d, change=True)]
    print("Winning percentage while changing choice: ", len(winningdoors) / len(playerdoors))
