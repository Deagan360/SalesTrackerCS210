from os import strerror
import re
import string


def printSales():
    salesDict={}    #Dictionary for holding file items
    with open('CS210ProjectThreeInputFile.txt') as file:    #opening file to read
        for line in file:   #for each line in the opened file
            tempStr = str(line)     #save line to string
            tempStr = tempStr.strip()   #cut off blank space
            if tempStr in salesDict.keys():     #check if item is already in dictionary
                salesDict[tempStr] = salesDict[tempStr] +1  #increase count in dictionary
            else:           
                salesDict[tempStr.strip()] = 1  #create new dictionary item if not already in dictionary
    for key in salesDict.keys():    #cycle through items for printing
        print(str(key) + " " + str(salesDict[key]))     #print item, space, and count
    file.close()    #make sure file is closed


def checkSingleItem(v):
    salesDict= {}    #Dictionary for holding file items
    with open('CS210ProjectThreeInputFile.txt') as file:    #opening file to read
        for line in file:   #for each line in the opened file
            tempStr = str(line)     #save line to string
            tempStr = tempStr.strip()   #cut off blank space
            if tempStr in salesDict.keys():     #check if item is already in dictionary
                salesDict[tempStr] = salesDict[tempStr] +1  #increase count in dictionary
            else:           
                salesDict[tempStr.strip()] = 1  #create new dictionary item if not already in dictionary
    if v in salesDict.keys():
        print(str(v) + " " + str(salesDict[v]))     #print item, space, and count
    else:
        print("Item " + v + " has not been sold")
    return 100;

def printsomething():
    print("Thank you for using my program!")

def createDatFile():
    salesDict= {}    #Dictionary for holding file items
    outFile = open("frequency.dat","w")
    with open('CS210ProjectThreeInputFile.txt') as inFile:    #opening file to read
        for line in inFile:   #for each line in the opened file
            tempStr = str(line)     #save line to string
            tempStr = tempStr.strip()   #cut off blank space
            if tempStr in salesDict.keys():     #check if item is already in dictionary
                salesDict[tempStr] = salesDict[tempStr] +1  #increase count in dictionary
            else:           
                salesDict[tempStr.strip()] = 1  #create new dictionary item if not already in dictionary
    for key in salesDict.keys():
        outFile.write("\n" + key + " " + str(salesDict[key]))   # for every item in dictionary, write out to frequency.dat file "item count"




def PrintMe(v):
    print("You sent me: " + v)
    return 100;

def SquareValue(v):
    return v * v



    
