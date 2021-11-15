import tkinter as tk
import string


class Application(tk.Frame):
    def __init__(self, master):
        super().__init__(master)
        self.master = master
        self.create_widget()
        self.grid()
        self.alphabet = list(string.ascii_letters)
        self.alphabetCopy = list(string.ascii_letters)
        self.alphaKey = []


    def decrypt(self):
        # Get the text fromt the encryption message pasted
        self.fullText = self.encryptedMessage.get('1.0', tk.END)

        # Split the full text to get the length of the encrypted message
        self.fullText = self.fullText.split('$')
        n = int(self.fullText[0])

        # split the remaining text to get the encrypted message and the key for decryption
        self.encryption = self.fullText[1][:n]
        self.keyword = self.fullText[1][n:]
        self.decryptedList = []

        # Use the key to create the encryption alphabet
        for k in self.keyword:
            if k in self.alphabetCopy:
                self.alphabetCopy.remove(k)
                self.alphaKey.append(k)

        self.alphaKey += self.alphabetCopy

        # Decryption Process
        for e in self.encryption:
            if e in self.alphaKey:
                i = self.alphaKey.index(e)
                self.decryptedList.append(self.alphabet[i])
            elif e == '#':
                self.decryptedList.append(' ')
            elif e == '0':
                self.decryptedList.append(',')
            elif e == '1':
                self.decryptedList.append("'")
            elif e == '2':
                self.decryptedList.append('?')
            elif e == '3':
                self.decryptedList.append('.')
            elif e not in self.alphabet:
                self.decryptedList.append(e)

        self.message = ''.join(self.decryptedList)

        # Print out the decrypted message
        self.decryptedMessage.delete('1.0', tk.END)
        self.decryptedMessage.insert(tk.END, self.message)

    def create_widget(self):
        self.decryptionFrame = tk.LabelFrame(self, text="Paste encrypted message")
        self.DLabel = tk.Label(self.decryptionFrame, text="Encrypted Message:")
        self.encryptedMessage = tk.Text(self.decryptionFrame, width=40, height=10)
        self.decryptBtn = tk.Button(self.decryptionFrame, text="Decrypt", command=self.decrypt, pady=5)

        self.screenFrame = tk.LabelFrame(self, text="Decryption")
        self.decryptedMessage = tk.Text(self.screenFrame, width=57, height=2)

        self.exit = tk.Button(self, text="Exit", command=self.master.destroy)

        self.decryptionFrame.grid(row=0, column=0, columnspan=3)
        self.DLabel.grid(row=0, column=0)
        self.encryptedMessage.grid(row=0, column=1, columnspan=2)
        self.decryptBtn.grid(row=1, column=2)

        self.screenFrame.grid(row=1, column=0, columnspan=3)
        self.decryptedMessage.grid(row=0, column=0, columnspan=3)
        tk.Label(self.screenFrame).grid(row=1)
        self.exit.grid(row=3, column=2)


if __name__ == "__main__":
    root = tk.Tk()
    root.title("Message Decryption")
    app = Application(root)
    app.mainloop()
