#include <iostream>

//// convert null to nullptr

using namespace std;

struct node{

public:
    int data;
    node *nextNode = NULL;
};


class listNodes{

public:
    node *rootNode = NULL;
public:


    void add(int data)
    {

        if(rootNode == NULL)
        {
            rootNode = new node;
            rootNode->data = data;
            return;
        }
        else
        {
            node *currentNode = rootNode;

            while(currentNode->nextNode != NULL)
            {
                currentNode = currentNode->nextNode;
            }

            currentNode->nextNode = new node;
            currentNode->nextNode->data = data;

        }
    }

    void deleteNode(int data)
    {

        if(rootNode->data == data)
        {
            rootNode = rootNode->nextNode;
            return;
        }

        node *tempNode = rootNode;
        while(tempNode->nextNode != NULL)
        {
            if(tempNode->nextNode->data == data)
            {
                cout<<tempNode->nextNode->data<<" deleted"<<endl;
                tempNode->nextNode = tempNode->nextNode->nextNode;
                break;
            }

            tempNode = tempNode->nextNode;
        }
    }

    void printList()
    {
        node *tempNode = rootNode;

        while(tempNode != NULL)
        {
            cout<<tempNode->data<<endl;

            tempNode = tempNode->nextNode;
        }
    }

};
int main()
{
    listNodes *listnodes= new listNodes();

    listnodes->add(3);
    listnodes->add(5);
    listnodes->add(6);
    listnodes->add(7);
    listnodes->add(7);
    listnodes->add(7);

    listnodes->printList();

    listnodes->deleteNode(6);
    listnodes->printList();

    listnodes->deleteNode(7);
    listnodes->printList();
    return 0;
}
