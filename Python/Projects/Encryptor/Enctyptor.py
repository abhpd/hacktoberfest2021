from cryptography.fernet import Fernet

key = Fernet.generate_key()
print("Key : ", key.decode())
f = Fernet(key)

encrypted_data = f.encrypt(b"Secret message")
print("After encryption : ", encrypted_data)

decrypted_data = f.decrypt(encrypted_data)
print(decrypted_data)
print("After decryption : ", decrypted_data.decode())
