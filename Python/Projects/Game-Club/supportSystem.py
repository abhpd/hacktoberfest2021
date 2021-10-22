class Error:
    @staticmethod
    def is_Error():
        while True:
            x = input().lower()
            if x != "yes" and x != "no":
                print("Need be yes or no ")
            else:
                return x

    @staticmethod
    def Error_bet(have_Chip):
        while True:
            try:
                x = int(input())
            except Exception:
                print("need to be int ")
            else:
                if x > have_Chip:
                    print("Sorry, You do not have enough Chips , you have {} ".
                          format(have_Chip))
                elif x <= 0:
                    print("num need to be > 0")
                else:
                    return x
            finally:
                print("")

#------------------------------------------------------------------------------------------------------------

class Chips:  #  player Chips
    def __init__(self):
        self.total = 100

    def add(self, num):
        self.total = self.total + num

    def remove(self, num):
        self.total = self.total - num

#------------------------------------------------------------------------------------------------------------

class Card:
    def __init__(self):
        self.cart = {
            "A": 11,
            "K": 10,
            "Q": 10,
            "J": 10,
            "10": 10,
            "9": 9,
            "8": 8,
            "7": 7,
            "6": 6,
            "5": 5,
            "4": 4,
            "3": 3,
            "2": 2
        }
        self.keys = self.cart.keys()
        self.suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
        self.all_card = []
        for i in self.keys:
            for j in self.suits:
                self.all_card.append((i, j))

    def __len__(self):
        return len(self.all_card)

#------------------------------------------------------------------------------------------------------------

class Hand:
    def __init__(self):
        self.Card_in_hand = []
        self.value = 0
        self.aces = 0

    def add_card(self, cart, value):
        self.Card_in_hand.append(cart)
        if value == 11:
            self.aces = self.aces + 1
        self.value = self.value + value

        if self.value > 21 and self.aces >= 1:
            self.value = self.value - 10  # if i have 21+ and i have 1 ace , ace now == 1 and not 11
            self.aces = self.aces - 1  # -1 ace its no more ace now i have 1 and not 11

    def hand_win(self):
        if (self.value) == 21:
            return "Win"
        elif (self.value) > 21:
            return "Lose"
        else:
            return "Go on"

    def __str__(self):
        return "{" + str(self.Card_in_hand) + "," + str(self.value) + "}"


class Presentation:
    @staticmethod
    def Hand_printing(player):
        x = str(player)
        x = x.replace(" ", "")
        x = x[3:len(x) - 5]
        x = x.replace("[", "")
        x = x.replace("]", "")
        x = x.replace(")", "")
        x = x.replace("(", "")
        x = x.replace("'", "")
        x = x.split(',')
        y = 0
        for _ in range(len(x)):
            if (y + 1) < len(x):
                print(" ---------------------")
                print("  | {} {}     |".format(x[y], x[y + 1]))
                print(" ---------------------")
                y = y + 2
        print(player.value)  # For people who do not understand in Card

    @staticmethod
    def dealer_printing(dealer):
        x = str(dealer)
        x = x.replace(" ", "")
        x = x[3:len(x) - 5]
        x = x.replace("[", "")
        x = x.replace("]", "")
        x = x.replace(")", "")
        x = x.replace("(", "")
        x = x.replace("'", "")
        x = x.split(',')
        print("~ Dealer Hand  ~")
        print("~~~~~~~~~~~~~~~~")
        if x[0] == '':
            print("No cart")

        elif len(x) == 2:
            print(" ------------------")
            print("  | {} {}     |".format(x[0], x[1]))
            print(" ------------------")

        else:
            print(" ---------------------     -------------------")
            print("  | {} {}        |     |#################|".format(
                x[0], x[1]))
            print(" ---------------------     -------------------")
        print(" ")

#------------------------------------------------------------------------------------------------------------

class Deck(Card):
    def __init__(self, cards):
        Card.__init__(self)
        self.cards = cards

    def Deck_pop(self, i):
        self.cards.pop(i)

    def find_idx(self, x):
        return self.cards.index(x)

    def __str__(self):
        return str(self.cards)

    def __len__(self):
        return len(self.cards)
