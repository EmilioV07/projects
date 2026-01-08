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
#
import itertools
keycycle = itertools.cycle(["I","C","E"])
result = []
with open ("hex4.txt","r") as file:
	lines = file.read().strip().split("\n")
def unxor(l,r):
	for line in lines:
		for char in line: #cycles through line once
			result.append(char.encode() ^ next(keycycle).encode()) #XORs the one character of the line by current character of key
	print(result)
unxor(lines,result)
