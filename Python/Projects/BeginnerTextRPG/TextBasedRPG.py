def start():
  print("\nYou are standing in a dim room.")
  print("There is a door to your left and right, which one do you take? (l or r)")
  
  answer = input(">").lower()

  if "l" in answer:
    bear_room()
  elif "r" in answer:
    monster_room()
  else:
    game_over("The room fades to black and you find no way out!")

start()

def bear_room():
  print("\nThere is a bear here.")
  print("Behind the bear is another door.")
  print("The bear is eating tasty honey!")
  print("What would you do? (1 or 2)")
  print("1). Take the honey.")
  print("2). Taunt the bear.")

  answer = input(">")
  
  if answer == "1":
    game_over("The bear killed you.")
  elif answer == "2":
    print("\nYour Good time, the bear moved from the door. You can go through it now!")
    diamond_room()
  else:
    game_over("Don't you know how to type a number?")

def monster_room():
  print("\nNow you entered the room of a monster!")
  print("The monster is sleeping.\nBehind the monster, there is another door. What would you do? (1 or 2)")
  print("1). Go through the door silently.")
  print("2). Kill the monster and show your courage!")

  answer = input(">")

  if answer == "1":
    diamond_room()
  elif answer == "2":
    game_over("The monster was hungry, he/it ate you.")
  else:
    game_over("Go and learn how to type a number.")

def diamond_room():
  print("\nYou are now in a room filled with diamonds!")
  print("And there is a door too!")
  print("What would you do? (1 or 2)")
  print("1). Take some diamonds and go through the door.")
  print("2). Just go through the door.")

  answer = input(">")
  
  if answer == "1":
    game_over("They were cursed diamonds! The moment you touched it, the building collapsed, and you die!")
  elif answer == "2":
    print("\nNice, you're are an honest man! Congrats you win the game!")
    play_again()
  else:
    game_over("Go and learn how to type a number.")

def game_over(reason):
  print("\n" + reason)
  print("Game Over!")
  play_again()

def play_again():
  print("\nDo you want to play again? (y or n)")
  
  answer = input(">").lower()

  if "y" in answer:
    start()
  else:
    exit()