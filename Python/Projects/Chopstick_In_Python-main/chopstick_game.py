def UserIn_for_move1():
    n = input("\nEnter move for Player 1 -")
    return n


def UserIn_for_move2():
    n = input("\nEnter move for Player 2 -")
    return n


def UserIn_for_combination_attack():
    n = input("\nEnter the move combination for attack: ")
    return n


def UserIn_for_combination_split():
    n = input("\nEnter the move combination for split: ")
    return n


def current_status(hand_1_l, hand_1_r, hand_2_l, hand_2_r):
    print("\nCurrent status :")
    print("Player1- %s %s" % (hand_1_l, hand_1_r))
    print("Player2- %s %s" % (hand_2_l, hand_2_r))


def working():
    hand_1_l = 1
    hand_1_r = 1
    hand_2_l = 1
    hand_2_r = 1

    current_status(hand_1_l, hand_1_r, hand_2_l, hand_2_r)

    num = 1
    while(True):
        if(num % 2 != 0):
            move_of_player = UserIn_for_move1().upper()
        if(num % 2 == 0):
            move_of_player = UserIn_for_move2().upper()

        if(move_of_player == "A"):
            attack_combination = UserIn_for_combination_attack().upper()

            flag = 1
            for i in range(len(attack_combination)):
                if(attack_combination[i] != " " and flag == 1):
                    left_move = attack_combination[i]
                    flag += 1

                if(attack_combination[i] != " " and flag == 2):
                    right_move = attack_combination[i]

            if(num % 2 != 0):
                if(left_move == "R" and right_move == "L"):
                    hand_2_l += hand_1_r
                elif(left_move == "L" and right_move == "R"):
                    hand_2_r += hand_1_l
                elif(left_move == "R" and right_move == "R"):
                    hand_2_r += hand_1_r
                elif(left_move == "L" and right_move == "L"):
                    hand_2_l += hand_1_l

            elif(num % 2 == 0):
                if(left_move == "R" and right_move == "L"):
                    hand_1_l += hand_2_r
                elif(left_move == "L" and right_move == "R"):
                    hand_1_r += hand_2_l
                elif(left_move == "R" and right_move == "R"):
                    hand_1_r += hand_2_r
                elif(left_move == "L" and right_move == "L"):
                    hand_1_l += hand_2_l

        elif(move_of_player == "S"):
            split_combination_of_player = UserIn_for_combination_split().upper()
            print(split_combination_of_player)
            slag = 1

            for i in range(len(split_combination_of_player)):
                if(split_combination_of_player[i] != " " and slag == 1):
                    split_move = split_combination_of_player[i]
                    slag += 1

                elif(split_combination_of_player[i] != " " and slag == 2):
                    fst_hand = ord(split_combination_of_player[i])-48
                    slag += 1

                elif(split_combination_of_player[i] != " " and slag == 3):
                    scnd_hand = ord(split_combination_of_player[i])-48
                else:
                    pass

            if(num % 2 != 0):
                hand_1_l = fst_hand
                hand_1_r = scnd_hand
            elif(num % 2 == 0):
                hand_2_l = fst_hand
                hand_2_r = scnd_hand

        if(hand_1_l >= 5):
            hand_1_l = 0
        if(hand_1_r >= 5):
            hand_1_r = 0
        if(hand_2_l >= 5):
            hand_2_l = 0
        if(hand_2_r >= 5):
            hand_2_r = 0

        if(hand_1_l == 0 and hand_1_r == 0):
            print("Player2 won the game!")
            current_status(hand_1_l, hand_1_r, hand_2_l, hand_2_r)
            break

        elif(hand_2_l == 0 and hand_2_r == 0):
            print("Player1 won the game!")
            current_status(hand_1_l, hand_1_r, hand_2_l, hand_2_r)
            break

        else:
            current_status(hand_1_l, hand_1_r, hand_2_l, hand_2_r)

        num += 1


def restart_game():

    restart = input("Do you want to play again?(yes/no):\n>>").lower()
    if restart == "yes":
        main()

    else:
        exit()


def main():
    working()
    restart_game()


main()
