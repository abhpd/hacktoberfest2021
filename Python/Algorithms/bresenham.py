import matplotlib.pyplot as plt

x1= int(input()) # data sebagai masukkan x1
x2= int(input()) # masukkan x2
y1= int(input()) # masukkan y1
y2= int(input()) # masukkan y2

def bresenham(x1,y1,x2, y2):
	m = 2 * (y2 - y1) # jika y2 dikurangi y1, lalu dikalikan 2 menjad 2
	slope_error = m - (x2 - x1) # sedangkan slope_error, hasil kurang dari m dengan hasil x2 dikurangi x1
	y=y1 # jika y sebagai y1
	for x in range(x1,x2+1): # lakukan perulangan antara x1 sampai setiap tambahan 1 untuk x2
		print("(",x ,",",y ,")\n") # cetak data x dan y
		slope_error =slope_error + m # hasil slope_error terbaru ditambah dengan nilai m
		if (slope_error >= 0): # jika nilai slope error lebih dari 0, maka
			y=y+1 # setiap y ditambah 1
			slope_error =slope_error - 2 * (x2 - x1) # setiap nilai slop yang baru hasil kurang dari
			point1 = [x1,y1] 			 #nilai x2-x1, lalu dikalikan 2.
			point2 = [x2, y2]
			x_values = [point1[0], point2[0]] #definis seitpa nilai ke x_values.
			y_values = [point1[1], point2[1]]
			plt.plot(x_values,y_values) # cetak data x_values, day values..
			plt.show()

