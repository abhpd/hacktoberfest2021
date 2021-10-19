from itertools import cycle

def repeated_xor(string, key):
	result = ""
	for c, k in zip(string, cycle(key)):
		result += chr(ord(c) ^ ord(k))
	return result

repeated_xor("KRIPTOGRAFI", "KEY")
print(repeated_xor)
