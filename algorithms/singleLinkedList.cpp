#include <iostream>
class NodeImplementation {
    public: 
     virtual int getData() = 0;
     virtual NodeImplementation* getNextNodeAddress() = 0;
};

class Node: public NodeImplementation {
 private:
   int data;
   Node* next;
  public:
   Node(int nodeData) {
       data = nodeData;
       next = nullptr;
   }
    int getData() {
    return data;
   }
    Node* getNextNodeAddress() {
     return next;
   }
    void setNextNodeAddress(Node* node) {
      next = node;
      return;
  }
};

class LLInterface {
    public:
    //  virtual Node * getElements() = 0;
     virtual void addElement(int data) = 0;
     virtual int getCurrentLength() = 0;
     virtual void print() = 0;
     virtual void addAtBegining(int data) = 0;
     virtual void addAtEnd(int data) = 0;
     virtual void addAtSpecificPosition(int pos, int data) = 0;
     virtual void removeFromBegining() = 0;
     virtual void removeFromEnd() = 0;
     virtual void removeFromSpecificPosition(int) = 0;
     virtual void removeAllOccurrence(int data) = 0;
     virtual bool clearList() = 0;
     virtual bool replaceAtPosition(int data, int position) = 0;
     virtual int middlePosition() = 0;
     
};

class SingleLinkedList : public LLInterface {
  private:
   Node* head;
   int length;
  public: 
   SingleLinkedList() {
       length = 0;
       head = nullptr;
   }
   int getCurrentLength() {
       int length = 0;
       Node* tempHead = head;
       while(tempHead != nullptr) {
           tempHead = tempHead -> getNextNodeAddress();
           length ++;
       }
       return length;
   }
   void addElement(int data) {
        Node* node = new Node(data);
        Node* tempHead = head;
       if(head == nullptr) {
          head = node;
       }
       else {
           while (tempHead -> getNextNodeAddress() != nullptr ) {
           tempHead = tempHead -> getNextNodeAddress();
           }
           tempHead -> setNextNodeAddress(node);
       }
           length ++;
           return ;
   }
    
    void print() {
        Node* tempHead = head;
        if(tempHead == nullptr) 
          std::cout << "The list is empty" << std::endl;
        else {
            while(tempHead != nullptr) {
               std::cout << tempHead -> getData() <<" -> ";
                tempHead = tempHead ->getNextNodeAddress();
            }
            std::cout<<"Null";
            std::cout<<std::endl;
        }
        return;
     }
     void addAtBegining(int data) {
         Node* node = new Node(data);
         node -> setNextNodeAddress(head);
         head  = node;
     }
     void addAtEnd(int data) {
         Node* node = new Node(data);
         Node* tempHead = head;
         while(tempHead -> getNextNodeAddress() != nullptr){
             tempHead = tempHead -> getNextNodeAddress();
         }
         tempHead -> setNextNodeAddress(node);
     }
     void addAtSpecificPosition(int pos, int data) { 
             Node* node = new Node(data);
             Node* tempHead = head;
             bool actionCompleted = false;
             for(int i = 0; i < pos -1; i++)
             {
                 if(tempHead == nullptr) {
                     actionCompleted = false;
                     break;
                 };
                 tempHead = tempHead -> getNextNodeAddress();
                 actionCompleted = true;
             }
             if(actionCompleted) {
                 node->setNextNodeAddress(tempHead->getNextNodeAddress());
                 tempHead -> setNextNodeAddress(node);
             }
             else {
                 std::cout<< "Invalid Position"<< std::endl;
             }
         }
      void removeFromBegining(){
          Node* tempHead = head -> getNextNodeAddress();
          delete head;
          head = tempHead;
      }

      void removeFromEnd() {
          Node* tempHead = head;
          Node* aheadPointer = head -> getNextNodeAddress();
          while(aheadPointer -> getNextNodeAddress() != nullptr) {
              aheadPointer = aheadPointer -> getNextNodeAddress();
              tempHead = tempHead -> getNextNodeAddress();
          }
          Node* nodeToBeDeleted = aheadPointer;
          delete nodeToBeDeleted;
          tempHead -> setNextNodeAddress(nullptr);
      }
      void removeFromSpecificPosition(int position) {
          bool spec = true;
          Node* tempHead = head -> getNextNodeAddress();
          Node* currentHead = head;
          for(int i = 0; i < position -1 ; i++)
          {
              if(tempHead -> getNextNodeAddress() == nullptr) {
                  spec = true;
                  break;
              }
              tempHead = tempHead -> getNextNodeAddress();  
              spec = false;
          }
          if(spec) std::cout<<"No element found at the position"<<std::endl;
          Node* deletedNode = tempHead -> getNextNodeAddress();
          Node* nextToDeletedNode = deletedNode -> getNextNodeAddress();
          tempHead ->setNextNodeAddress(nextToDeletedNode);
          delete deletedNode;          
      }
     void removeAllOccurrence(int data) {
        Node* currentNode = head;
        if(currentNode -> getData() == data) {
            Node* deleteNode = currentNode;
            currentNode = currentNode -> getNextNodeAddress();
            delete deleteNode;
            head = currentNode;
        }
        Node* nextNode = currentNode -> getNextNodeAddress();
        while(nextNode != nullptr) {
            if(nextNode -> getData() == data) {
               Node* toBeDeletedNode = nextNode;
               currentNode -> setNextNodeAddress(toBeDeletedNode -> getNextNodeAddress());
               delete toBeDeletedNode;
            }
            currentNode = currentNode -> getNextNodeAddress();
            nextNode = nextNode -> getNextNodeAddress();
        }
     }  
     bool clearList() {
         while(head != nullptr) {
              Node* toBeDeletedNode = head;
              head = head -> getNextNodeAddress();
              delete toBeDeletedNode;
         }
         return true;
     }
     bool replaceAtPosition(int data, int position) {
       Node* node = new Node(data);
       Node* tempHead = head;
       for(int i = 0; i < position -2; i++)
       {
           tempHead = tempHead -> getNextNodeAddress();

       }
       Node* nextDeletedNode = tempHead -> getNextNodeAddress();
       tempHead->setNextNodeAddress(node);
       node->setNextNodeAddress(nextDeletedNode -> getNextNodeAddress());
       delete nextDeletedNode;
       return true;
     }
    int middlePosition() {
        Node* tempHead  = head;
        Node* doublePtr = head;
        while(doublePtr -> getNextNodeAddress() != nullptr) {
            tempHead = tempHead -> getNextNodeAddress();
            doublePtr = doublePtr -> getNextNodeAddress();
            doublePtr = doublePtr -> getNextNodeAddress();
        }
        return tempHead -> getData(); 
    }
};

int main() {
    SingleLinkedList sl;
    sl.addElement(2);
    sl.addElement(3);
    sl.addElement(5);
    sl.addAtBegining(1);
    sl.addElement(1);
    sl.addAtBegining(222);
    sl.addAtEnd(444);
    sl.addAtSpecificPosition(2, -1);
    std::cout<<"Linked List Created of size " << sl.getCurrentLength()<< std::endl;
    sl.print();
    sl.removeFromBegining();
    sl.removeFromEnd();
    sl.removeFromSpecificPosition(2);
    sl.removeAllOccurrence(1);
    sl.replaceAtPosition(10, 2);
    sl.print();
    std::cout<<sl.middlePosition()<<std::endl;
    sl.print();
    std::cout<<"Delete Started and length of the list "<<sl.getCurrentLength()<<std::endl;
   return 0;
}