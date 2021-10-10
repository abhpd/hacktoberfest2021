import tkinter as tk
import random
import string


class Application(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.master = master
        self.createWidget()
        self.grid()

        # Gets the Alphabets
        self.alphabet = list(string.ascii_letters)
        self.alphabetCopy = list(string.ascii_letters)

        self.keyword = random.choices(self.alphabet, k=10)

        while not self.is_unique(self.keyword):
            self.keyword = random.choices(self.alphabet, k=10)

        self.alphaKey = []

        # Removes the keyword characters from the alphabet and add it to the front of the remainder
        for k in self.keyword:
            if k in self.alphabetCopy:
                self.alphabetCopy.remove(k)
                self.alphaKey.append(k)

        self.alphaKey += self.alphabetCopy

    def is_unique(self, word):
        if len(word) > len(set(word)):
            uniqueness = False
        else:
            uniqueness = True

        return uniqueness

    def encrypt(self):
        self.cryptedList = []

        # Gets the message
        self.message = list(self.messageEntry.get('1.0', tk.END).strip())

        # Iterate through the message and encrypt the message by swapping the characters
        for m in self.message:
            if m in self.alphabet:
                i = self.alphabet.index(m)
                self.cryptedList.append(self.alphaKey[i])
            elif m == ' ':
                self.cryptedList.append('#')
            elif m == ',':
                self.cryptedList.append('0')
            elif m == "'":
                self.cryptedList.append('1')
            elif m == '?':
                self.cryptedList.append('2')
            elif m == '.':
                self.cryptedList.append('3')
            elif m not in self.alphabet:
                self.cryptedList.append(m)

        # print(self.alphabet)
        # print(self.alphaKey)

        n = str(len(self.cryptedList))

        # Join the keyword and the length of the crypted message for decryption purpose
        self.fullEncryption = n + '$' + ''.join(self.cryptedList) + ''.join(self.keyword)
        # Inserts the encrypted message to the ouput screen
        self.encryptedMessage.delete('1.0', tk.END)
        self.encryptedMessage.insert(tk.END, self.fullEncryption)

    def createWidget(self):
        self.screenFrame = tk.LabelFrame(self, text="Enter your message")
        self.messageEntry = tk.Text(self.screenFrame, width=57, height=2)
        self.encryptBtn = tk.Button(self.screenFrame, text="Encrypt", command=self.encrypt, pady=5)

        self.encryptionFrame = tk.LabelFrame(self, text="Encryption")
        self.ELabel = tk.Label(self.encryptionFrame, text="Encrypted Message:")
        self.encryptedMessage = tk.Text(self.encryptionFrame, width=40, height=10)

        self.exit = tk.Button(self, text="Exit", command=self.master.destroy)

        self.screenFrame.grid(row=0, column=0, columnspan=3)
        self.messageEntry.grid(row=0, column=0, columnspan=3)
        self.encryptBtn.grid(row=1, column=2)

        self.encryptionFrame.grid(row=1, column=0, columnspan=3)
        self.ELabel.grid(row=0, column=0)
        self.encryptedMessage.grid(row=0, column=1, columnspan=2)
        tk.Label(self.encryptionFrame).grid(row=1)

        self.exit.grid(row=3, column=2)


if __name__ == "__main__":
    root = tk.Tk()
    root.title("Message Encryption")
    app = Application(root)
    app.mainloop()
