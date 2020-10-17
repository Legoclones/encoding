all:
	g++ -o enc enc.cpp EncryptionObj.cpp
clean:
	rm enc