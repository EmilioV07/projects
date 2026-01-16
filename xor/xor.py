"""
Emilio Vasquez-Pettit

Citations:
MS Copilot: Used as syntax guide for python imports (ex .encode & .decode for base64)
"""
#WORKING
"""
import base64
with open ("hex1.txt", "r") as file:
	hex = file.read().strip()
bin = bytes.fromhex(hex)
b64 = base64.b64encode(bin)
print("out:" + b64.decode())
print("ans:" + "SSdtIGtpbGxpbmcgeW91ciBicmFpbiBsaWtlIGEgcG9pc29ub3VzIG11c2hyb29t")
"""
#WORKING
"""
b1 = input("Enter the first string: ")
b2 = input("Enter the second string: ")
hex1 = bytes.fromhex(b1) #wrong variable name, could be bin
hex2 = bytes.fromhex(b2)
def cmp(h1, h2):
	return  bytes(a ^ b for a, b in zip(hex1, hex2)) #copilot xor operator, & zip (corresponds)
ans = cmp(hex1,hex2)
print(ans.hex())
"""
#WORKING
"""
with open ("hex2.txt","r") as file:
	hex = file.read().strip()
bin = bytes.fromhex(hex) #converts to raw bytes
#note, xor-ing against the same character un-xors
def unxor(b):
	rslt = [] #works as buffer for holding variables to manipulate
	rsltcmp = [] #stores final product for later comparison
	score = 0 #holds score
	cmnchars = "etaoin shrdlu" #common chars provided on challenge page
	for i in range(32, 127): #iterates through all printable ASCII characters (chr(i))
		key = chr(i).encode() * len(b) #converts ASCII character to bytes for later XOR
		msg = bytes(a ^ b for a, b in zip(b, key)) #XORs bytes of original hex with character
		dmsg = msg.decode(errors="ignore").lower() #converts the message to a lowercase string for comparison
		rslt.append((chr(i), dmsg)) #prints xor character and output against encoded string bytes
		for j in rslt[0][1]: #scores every xor option for english detection
			if j in cmnchars:
				score += 2
			if j.isalpha():
				score += 1
			if j == " ":
				score += 3
			if j in ")(*&^%$#@~+_{}[]\|<>`":
				score -=2
		rslt.append(score) #stores score in print buffer
		rsltcmp.append((chr(i),dmsg,score))
		score = 0
		print(rslt)
		rslt.clear()
	print("Answer: " + str(max(rsltcmp, key=lambda x: x[2]))) #copilot lambda solution for max grabbing incorrect tuple element to compare score
unxor(bin)
"""
#WORKING
"""
with open ("hex3.txt","r") as file:
	hexlines = file.read().strip().split()
#bin = bytes.fromhex(hex) #converts to raw bytes
#note, xor-ing against the same character un-xors
#print(bin)

def findit(h):
	anslist = []
	for line in hexlines:
		binline = bytes.fromhex(line) #individually converts line to raw bytes
		unxor(binline, anslist)
		print(anslist)
	print("Answer: " + str(max(anslist, key=lambda x: x[2])))

def unxor(b,a): #brute forces single printable character xors for ONE LINE
	rslt = [] #works as buffer for holding variables to manipulate
	rsltcmp = [] #stores final product for later comparison
	score = 0 #holds score
	cmnchars = "etaoin shrdlu ETAOIN SHRDLU" #common chars provided on challenge page
	for i in range(32, 127): #iterates through all printable ASCII characters (chr(i))
		key = chr(i).encode() * len(b) #converts ASCII character to bytes for later XOR
		msg = bytes(a ^ b for a, b in zip(b, key)) #XORs bytes of original hex with character
		dmsg = msg.decode(errors="ignore") #converts the message to a lowercase string for comparison
		rslt.append((chr(i), dmsg)) #prints xor character and output against encoded string bytes
		for j in rslt[0][1]: #scores every xor option for english detection
			if j in cmnchars:
				score += 2
			if j.isalpha():
				score += 1
			if j == " ":
				score += 3
			if j in ")(*&^%$#@~+_{}[]\|<>`":
				score -=2
		rslt.append(score) #stores score in print buffer
		rsltcmp.append((chr(i),dmsg,score))
		score = 0
		#print(rslt)
		rslt.clear()
	print("Answer: " + str(max(rsltcmp, key=lambda x: x[2]))) #copilot lambda solution for max grabbing incorrect tuple element to compare score
	a.append(max(rsltcmp, key=lambda x: x[2]))

findit(hexlines)
"""
#WORKING
"""
import itertools
with open ("hex4.txt","r") as file:
	lines = file.read().strip()
	print(lines)
def unxor(lines):
	result = []
	keycycle = itertools.cycle(b"ICE") #sets cycle for each line individually
	for line in lines:
		xdline = []
		byteline = line.encode()
		for char in byteline: #cycles through line once
			xdline.append(char ^ next(keycycle)) #XORs the one character of the line by current character of key
		hexline = bytes(xdline).hex()
		#print(hexline)
		result.append(hexline) #adds line to list as a seperate list element
	print(''.join(result))
unxor(lines)
"""
#
import base64
import itertools
with open ("hex5.txt","r") as file:
	lines64 = file.read().strip()
	bytelines = base64.b64decode(lines64)
#print(bytelines) #raw bytes, WORK WITH THIS
#s1 = "this is a test"
#s2 ="wokka wokka!!!"

def brk(bytelines, keysize): #breaks into keysize sizes chunks AND transposes (1,1,1) (2,2,2), etc...
	chunklist = [] #CHUNKLIST: List of broken segments BEFORE transposing
	for i in range(0, len(bytelines), keysize):
		chunklist.append(bytelines[i:i+keysize])
	return chunklist
def brk2(bytelines, keysizes): #second brk function specifically made to break based on top 3 keysizes
	chunklist1 = []
	chunklist2 = []
	chunklist3 = []
	pieceslist1 = [[] for _ in range(keysizes[0])] #PIECESLIST: List of broken segments AFTER transposing, (1,1,1) (2,2,2), etc...
	pieceslist2 = [[] for _ in range(keysizes[1])]
	pieceslist3 = [[] for _ in range(keysizes[2])]
	for j in range(0,len(bytelines), keysizes[0]):
		chunklist1.append(bytelines[j:j+keysizes[0]])
	for j in range(0,len(bytelines), keysizes[1]):
		chunklist2.append(bytelines[j:j+keysizes[1]])
	for j in range(0,len(bytelines), keysizes[2]):
		chunklist3.append(bytelines[j:j+keysizes[2]])
	for chunk in chunklist1:
		for index in range(len(chunk)):
			pieceslist1[index].append(chunk[index])
	for chunk in chunklist2:
		for index in range(len(chunk)):
			pieceslist2[index].append(chunk[index])
	for chunk in chunklist3:
		for index in range(len(chunk)):
			pieceslist3[index].append(chunk[index])
	return pieceslist1, pieceslist2, pieceslist3
def findkey(bytelines, pieces):
	result = []
	foundkeys = []
	for piece in pieces:
		pieceresult = []
		for block in piece:
			temp = []
			for i in range(32, 127): #iterates through all printable ASCII characters (chr(i))
				key = chr(i).encode() * len(block) #converts ASCII character to bytes for later XOR
				msg = [a ^ b for a, b in zip(block, key)] #XORs bytes of original hex with character
				dmsg = bytes(msg).decode(errors="ignore").lower() #converts the message to a lowercase string for comparison
				temp.append((chr(i), engtest(dmsg)))
			temp.sort(key=lambda x: x[1][0], reverse=True) #sort for best score on top
			best=temp[0]
			pieceresult.append(best)
		result.append(pieceresult)

		key4piece = ''.join([char for char, score in pieceresult])
		foundkeys.append(key4piece)
	#for i in foundkeys:
		#print(i)
	bestkey = []
	for i in foundkeys:
		bestkey.append(engtest(i))
	bestkey.sort(key=lambda x: x[0], reverse=True)
	print("\nThe Key Is: '" + bestkey[0][1] + "'\n")
	return bestkey[0][1]
def kcontend(bytelines): #finds the keysize using ham, RETURNS SMALLEST 3 NORMALIZED HAMMING DISTANCES AND CORRESPONDING KEYSIZE
	all = []
	#first, get sample pairs of every keysize chunk (first 2 keysize sized chunks for every keysize)
	temp = []
	for i in range(2,41):
		keysize = i
		broken = brk(bytelines, keysize) #makes a chunklist for given i keysize
		temp.append((broken[0], broken[1], broken[3], broken[4], keysize)) #adds first 4 elements of new chunklist into temp for hamming
		broken.clear()
	#then, get their hamming distance P.S. ELEMENTS ALREADY PAIRED
	for pair in temp:
		all.append(ham(pair[0],pair[1],pair[2],pair[3],pair[4]))
	all.sort(key=lambda x: x[0]) #sorts by smallest to largest normalized hamming distances
	return all
def engtest(sample): #scores input in english likeness
	cmnchars = "etaoin shrdlu ETAOIN SHRDLU"
	score = 0
	for j in sample: #scores every xor option for english detection
		if j in cmnchars:
			score += 2
		if j.isalpha():
			score += 1
		if j == " ":
			score += 3
		if j in ")(*&^%$#@~+_{}[]\|<>`":
			score -=2
	return score, sample
def ham(s1, s2, s3, s4, keysize): #hamming distance of 2 BYTE inputs EDIT: CHANGE TO SECOND HAMMING OPTION
	sum1, sum2, sum3, sum4, sum5, sum6 = 0, 0, 0, 0, 0, 0
	for a, b in zip(s1, s2):
		sum1 += (bin(a^b).count("1"))/keysize
	for a, b in zip(s1, s3):
		sum2 += (bin(a^b).count("1"))/keysize
	for a, b in zip(s1, s4):
		sum3 += (bin(a^b).count("1"))/keysize
	for a, b in zip(s2, s3):
		sum4 += (bin(a^b).count("1"))/keysize
	for a, b in zip(s2, s4):
		sum5 += (bin(a^b).count("1"))/keysize
	for a, b in zip(s3, s4):
		sum6 += (bin(a^b).count("1"))/keysize
	return sum([sum1, sum2, sum3, sum4, sum5, sum6])/6, keysize #returns the iterated normalized sum of differing bytes in the strings

def unxor(bytelines, key):
	result = []
	if isinstance(bytelines, (bytes,bytearray)):
		bytelines = [bytelines] #copilot debug suggestion for wrong filetype
	for byteline in bytelines:
		keycycle = itertools.cycle(key.encode()) #sets cycle for each line individually
		xdline = []
		for char in byteline: #cycles through line once
			xdline.append(char ^ next(keycycle)) #XORs the one character of the line by current character of key
		decodedxdline = bytes(xdline).decode(errors="ignore")
		result.append(decodedxdline) #adds line to list as a seperate list element
	print("And the decoded message is: \n")
	print(''.join(result))



def main(bytelines):
	all = kcontend(bytelines)
	top3 = brk2(bytelines, (all[0][1],all[1][1],all[2][1]))
	key = findkey(bytelines, top3)
	unxor(bytelines, key)
main(bytelines)
