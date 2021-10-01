import os
import sys
import PyPDF2

inputfile = sys.argv[1]


merger = PyPDF2.PdfFileMerger()
for pdf in os.listdir(inputfile):
    merger.append(f"{inputfile}{pdf}")
merger.write(f"{inputfile}Super.pdf")
print("All your pdfs are merged")



