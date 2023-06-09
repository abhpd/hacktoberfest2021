import qrcode 

message=input("Enter the URL/Message : ")

image= qrcode.make(message)

image.save("qrcode.jpg")

print("Your qrcode is successfully created and saved in current directory.")
