import random

dice = [[" ------- ","|       |","|   *   |","|       |"," ------- "],
        [" ------- ","|     * |","|       |","| *     |"," ------- "],
        [" ------- ","|     * |","|   *   |","| *     |"," ------- "],
        [" ------- ","| *   * |","|       |","| *   * |"," ------- "],
        [" ------- ","| *   * |","|   *   |","| *   * |"," ------- "]]
flag = True

while(flag):

    x = random.randrange(5)
    y = random.randrange(5)
    print("\n")

    for i in range(5):
        print(dice[x][i],dice[y][i])

    print("\n")
    val = input("Would you like to roll again? y = yes, n = no \n")

    if val.lower() == "n":
        flag = False
