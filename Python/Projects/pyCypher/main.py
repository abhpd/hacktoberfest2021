# This is a program designed to demonstrate basic encryption and decryption

# Actions that can be taken, representing encryption, decryption and exiting the program, respectively
opts = ["e", "d", "exit"]

# Represent the shorthand inputs for the cypher selection and the full names of the cyphers
# --- Must align, with the exception of "back" for program to work properly ---
cypher_short = ["c", "back"]
cyphers = ["Caesar"]


# Use Caesar or Shift Cipher to encrypt a string
def caesar_encrypt():
    plaintext = input("Enter the text you wish to encrypt. Letters and spaces only\n")

    # Ensure that string only contains alphanumeric characters
    if not all(x.isalpha() or x.isspace() for x in plaintext):
        plaintext = input("Bad input. Please try again. Letters and spaces only\n")

    shift = input("Enter the number or letter to use as the key (A-Z or 0-25)\n")

    # Ensure shift is valid, whether a letter or number is used
    while not (shift.isalpha() and len(shift) == 1) and not (shift.isnumeric() and 0 <= int(shift) <= 25):
        shift = input("Bad input. Please try again.\nEnter the number or letter to use as the key (A-Z or 0-25)\n")
    if shift.isalpha() and shift.isupper():
        shift = ord(shift) - 65
    elif shift.isalpha() and shift.islower():
        shift = ord(shift) - 97

    # Encrypt the text with the given key and return the resulting ciphertext
    print("Encrypting " + plaintext + "\n" + "With shift " + str(shift))
    ciphertext = ""
    for i in range(len(plaintext)):
        char = plaintext[i]
        if char.isupper():
            ciphertext += chr((ord(char) + int(shift) - 65) % 26 + 65)
        else:
            ciphertext += chr((ord(char) + int(shift) - 97) % 26 + 97)
    return ciphertext


# Decrypt a string encrypted using a Caesar or Shift Cipher
def caesar_decrypt():
    ciphertext = input("Enter the text you wish to decrypt. Letters and spaces only\n")

    # Ensure that string only contains alphanumeric characters
    if not all(x.isalpha() or x.isspace() for x in ciphertext):
        ciphertext = input("Bad input. Please try again. Letters and spaces only\n")
    shift = input("Enter the number or letter to use as the key (A-Z or 0-25)\n")

    # Ensure shift is valid, whether a letter or number is used
    while not (shift.isalpha() and len(shift) == 1) and not (shift.isnumeric() and 0 <= int(shift) <= 25):
        shift = input("Bad input. Please try again.\nEnter the number or letter to use as the key (A-Z or 0-25)\n")
    if shift.isalpha() and shift.isupper():
        shift = ord(shift) - 65
    elif shift.isalpha() and shift.islower():
        shift = ord(shift) - 96

    # Decrypt the text with the given key and return the resulting plaintext
    print("Decrypting " + ciphertext + "\n" + "With shift " + str(shift))
    plaintext = ""
    for i in range(len(ciphertext)):
        char = ciphertext[i]
        if char.isupper():
            plaintext += chr((ord(char) - int(shift) - 65) % 26 + 65)
        else:
            plaintext += chr((ord(char) - int(shift) - 97) % 26 + 97)
    return plaintext


def main():
    print("Welcome to PyCypher!")
    while True:
        print("Select an option below\nEncrypt -- e\nDecrypt -- d\nExit ----- exit")
        opt = input("Type your choice here: ")
        while opt not in opts:
            opt = input("Invalid selection, try again: ")
        if opt == "exit":
            print("Bye!")
            quit()
        print("Choose a cypher method below\nCaesar -- c\nBack ---- back")
        cyp = input("Type your choice here: ")
        while cyp not in cypher_short:
            cyp = input("Invalid selection, try again: ")
        if cyp == "back":
            print("Returning to the top\n")
            continue

        task = None
        if opt == "d":
            task = "decrypt"
        else:
            task = "encrypt"

        cypher_full = cyphers[cypher_short.index(cyp)]

        print("You have chosen to " + task + " with a " + cypher_full + " cypher")
        if task == "encrypt" and cypher_full == "Caesar":
            result = caesar_encrypt()
            print("Your encrypted message is: " + result)
        elif task == "decrypt" and cypher_full == "Caesar":
            result = caesar_decrypt()
            print("Your decrypted message is: " + result)


if __name__ == "__main__":
    main()
