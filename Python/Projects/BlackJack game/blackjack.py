import random

suits = ('Hearts', 'Diamonds', 'Spades', 'Clubs')
ranks = ('Two', 'Three', 'Four', 'Five', 'Six', 'Seven', 'Eight', 'Nine', 'Ten', 'Jack', 'Queen', 'King', 'Ace')
values = {'Two':2, 'Three':3, 'Four':4, 'Five':5, 'Six':6, 'Seven':7, 'Eight':8, 'Nine':9, 'Ten':10, 'Jack':10,
         'Queen':10, 'King':10, 'Ace':11}

playing = True


class Card:

    def __init__(self,suit,rank):
        self.suit = suit
        self.rank = rank
        
    def __str__(self):
        return self.rank + ' of ' + self.suit


class Deck:
    
    def __init__(self):
        self.deck = []  
        for suit in suits:
            for rank in ranks:
                self.deck.append(Card(suit,rank))  

    def __str__(self):
        deck_comp = ''  # start with an empty string
        for card in self.deck:
            deck_comp += '\n '+card.__str__() 
            return 'The deck has:' + deck_comp

    def shuffle(self):
        random.shuffle(self.deck)
        
    def deal(self):
        single_card = self.deck.pop()
        return single_card


class Hand:
    def __init__(self):
        self.cards = []
        self.value = 0
        self.aces = 0

    def add_card(self,card):
        self.cards.append(card)
        self.value += values[card.rank]
        if card.rank == "Ace":
            self.aces += 1
    
    def adjust_for_ace(self):
        if self.aces > 0 and self.value > 21:
            self.value -= 10
            self.aces -= 1


class Chips:
    
    def __init__(self):
        self.total = 100
        self.bet = 0
        
    def win_bet(self):
        self.total += self.bet
    
    def lose_bet(self):
        self.total -= self.bet




def take_bet(chips):
    while True:
        try:
            chips.bet = int(input('How much do you wanna bet?'))
        except ValueError:
            print('Please input a number')
        else:
            if chips.bet > chips.total:
                print('Ínsufficient Chips')
            else:
                print(f"You are betting {chips.bet} chips.")
                break


def hit(deck,hand):
    single_card = deck.deal()
    hand.add_card(single_card)
    hand.adjust_for_ace()


def hit_or_stand(deck,hand):
    global playing  # to control an upcoming while loop
    
    while True:
        x = input("Would you like to Hit or Stand? Enter 'h' or 's' ")
        
        if x[0].lower() == 'h':
            hit(deck,hand) 

        elif x[0].lower() == 's':
            print("Player stands. Dealer is playing.")
            playing = False

        else:
            print("Sorry, please try again.")
            continue
        break


def show_some(player,dealer):
    print("\nDealer's Hand:")
    print(" <card hidden>")
    print('',dealer.cards[1])  
    print("\nPlayer's Hand:", *player.cards, sep='\n ')
    
def show_all(player,dealer):
    print("\nDealer's Hand:", *dealer.cards, sep='\n ')
    print("Dealer's Hand =",dealer.value)
    print("\nPlayer's Hand:", *player.cards, sep='\n ')
    print("Player's Hand =",player.value)


def player_busts(player,dealer,chips):
    print("Player busts!")
    chips.lose_bet()

def player_wins(player,dealer,chips):
    print("Player wins!")
    chips.win_bet()

def dealer_busts(player,dealer,chips):
    print("Dealer busts!")
    chips.win_bet()
    
def dealer_wins(player,dealer,chips):
    print("Dealer wins!")
    chips.lose_bet()
    
def push(player,dealer):
    print("Dealer and Player tie! It's a push.")


while True:
    # Print an opening statement
    print('rpg dice all')
    
    # Create & shuffle the deck, deal two cards to each player
    thedeck = Deck()
    thedeck.shuffle()
    
    theplayer = Hand()
    npc = Hand()
    theplayer.add_card(thedeck.deal())
    theplayer.add_card(thedeck.deal())
    npc.add_card(thedeck.deal())
    npc.add_card(thedeck.deal())
    
    # Set up the Player's chips
    playerchips = Chips()
    
    
    # Prompt the Player for their bet
    take_bet(playerchips)
    
    # Show cards (but keep one dealer card hidden)
    show_some(theplayer,npc)
    
    while playing:  # recall this variable from our hit_or_stand function
        
        # Prompt for Player to Hit or Stand
        hit_or_stand(thedeck,theplayer)
        
        # Show cards (but keep one dealer card hidden)
        show_some(theplayer,npc)
        
        # If player's hand exceeds 21, run player_busts() and break out of loop
        if theplayer.value > 21:
            player_busts(theplayer,npc,playerchips)
            break

    # If Player hasn't busted, play Dealer's hand until Dealer reaches 17
    if theplayer.value <= 21:
        while npc.value < 17:
            hit(thedeck,npc)
                
        # Show all cards
        show_all(theplayer,npc)
        # Run different winning scenarios
        if npc.value > 21:
            dealer_busts(theplayer,npc,playerchips)
        elif theplayer.value > npc.value:
            player_wins(theplayer,npc,playerchips)
        elif theplayer.value < npc.value:
            dealer_wins(theplayer,npc,playerchips)
        else:
            push(theplayer,npc)
    
    # Inform Player of their chips total 
    print("\nPlayer's winnings stand at",playerchips.total)    
    # Ask to play again
    new_game = input("Would you like to play another hand? Enter 'y' or 'n' ")
    
    if new_game[0].lower()=='y':
        playing=True
        continue
    else:
        print("Thanks for playing!")
        break

