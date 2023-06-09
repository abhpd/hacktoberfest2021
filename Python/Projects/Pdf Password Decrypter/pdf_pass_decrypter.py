from PyPDF2 import PdfFileWriter, PdfFileReader
import emoji
  
pw = PdfFileWriter()
inpf = input("Enter the file name: ")
file = PdfFileReader(inpf)
passwd = input("Enter the password: ")
  
if file.isEncrypted:
    
    file.decrypt(passwd)
  
    for index in range(file.numPages):
        page = file.getPage(index)  
        pw.addPage(page)
    
    outf = input("Enter the output file name: ")
    
    with open(outf, "wb") as f:
        
        pw.write(f)

    print("Your file is decrypted Successfully!!"+"\U0001f600")
else:
       print("Your file is already decrypted :)" + "\U0001f600")
