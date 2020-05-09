__author__ = 'somnath'

'''
LinkedList: Python Implementation
Operations:
-Create LinkedList()
-Display()
-Reverse()
-Sort()
-RemoveDuplicate()
'''

class LinkedList:

    def __init__(self, value):
        self.data = value
        self.next = None



    # Display LinkedList Elements
    def display(self):
        linkedList= ''
        curr = self
        while curr :
            linkedList += (curr.data).__str__() + '->'
            curr = curr.next
        print "{0}None".format(linkedList)

    # Reverse Elements in LinekdList
    def reverse(self):
        prev = None
        curr = self
        next = None

        while(curr):
            next = curr.next # Hold next node
            curr.next = prev # Point next node
            prev      = curr # Point the current node
            curr      = next # Current node progress

        return prev

    # Sort LinkedList
    def sort(self):

        # return if empty or single node LinkedList
        if self == None:
            print "Empty LinkedList:"
        elif self.next == None:
            print "Single Node LinkedList:"
        else:
            ptr = self
            endPtr = None

            # Bubble sort
            while ptr.next != endPtr:
                currPtr = ptr
                prevPtr = None  # Initial case set to None
                # Display Here
                while currPtr.next != endPtr:
                    if currPtr.data > currPtr.next.data:
                        # Say Link is like a->b->c->d , swapping b,c
                        temp   = currPtr.next # Store Next Pointer, storing c
                        currPtr.next= currPtr.next.next # Pointing to next to next , thats how breaking link, b is pointing to d
                        temp.next   = currPtr # c is pointing to b
                        if prevPtr == None:
                            ptr = temp  # For the frist node 8->2 , should be 2->8
                        else:
                            prevPtr.next = temp # a is pointing to c

                        currPtr = temp


                    prevPtr = currPtr
                    currPtr = currPtr.next

                # Point current pointer to the end pointer
                endPtr = currPtr

        # Update head
        return ptr
                


    # Remove duplicate entry from linkedlist
    def removeDuplicate(self):
        ptr = self

        dict= {}
        prevPtr = None
        while ptr != None:
            if ptr.data not in dict.keys():
                dict[ptr.data] = 1
                prevPtr = ptr  # Store the previous pointer
            else:
                # Delete element
                prevPtr.next = ptr.next

            ptr = ptr.next # Change the pointer


def main():

    # Create Instance of LinkedList
    #print "Create LinkedList"
    #Node = LinkedList(10)
    Ptr  = None
    Nodes = []
    

    #print "Enter Nodes:"
    with open('NodeList.txt', 'r') as fileObj:
        lines = fileObj.readlines()
        for line in lines:
            line = line.strip()
            if not line:
                continue
            numbers = line.split()
            count = 0
            Ptr = None
            #print numbers
            headPtr =  LinkedList(numbers.pop(0)) 
            Ptr = headPtr
            while count < len(numbers) :
                Ptr.next = LinkedList(numbers[count])
                Ptr = Ptr.next
                count += 1
            
            print "Linked List Created:"
            headPtr.display()
            Nodes.append(headPtr)

    # Display Linked List
    Nodes[0].display()

    # Reverse LinkedList
    print "LinkedList Reversed"
    Nodes[0] = Nodes[0].reverse()

    # Display LinkedList
    Nodes[0].display()

    # Sort LinkedList
    print "LinkedList Sorted"
    Nodes[0] = Nodes[0].sort()
    # Display
    Nodes[0].display()

    # Remove Duplicate Entry
    print "LinkedList Unique ( Removed Duplicate Entries)"
    Nodes[0].removeDuplicate()
    # Display LinkedList
    Nodes[0].display()



if __name__== "__main__":
    main()
