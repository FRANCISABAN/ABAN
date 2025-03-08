#include <iostream> 

using namespace std;

typedef struct Node{
    string songName;
    Node *link;
}Node;
Node *createNode(string data){
    Node *newNode = new Node;
    newNode->songName = data; 
    newNode->link = NULL;
    return newNode;
}
void traverse(Node *head){
    Node *temp = new Node;
    temp = head;

    cout << "My Playlist" <<endl;
    while(temp != NULL){
        cout << temp->songName<< "->"<<endl;
        if(temp->link == NULL){
            cout << "NULL"<<endl;
        }

        temp = temp->link;
    }
}

// Insert at the end
Node *insertAtEnd(string data, Node *head) {
    if (head == NULL) { // if the linked list is empty
        Node *newNode = createNode(data); // create node
        head = newNode; // assign new node as head
        cout << "A new node has been inserted at the end\n" << endl; // print out message
        return head;
    }
    Node *temp = new Node; // create a temporary node
    temp = head; // assign temporary node as head

    while (temp->link != NULL) { // traverse until the end is found, i.e., link == NULL
        temp = temp->link;
    }

    Node *newNode = createNode(data); // create new node
    temp->link = newNode; // link the new node to the last element

    cout << "A new node has been inserted at the end\n" << endl;
    return head;
}
Node *insertAtTheBeginning(string data, Node *head){
    Node *newNode = createNode(data);
    newNode->link = head;

    head = newNode;

    cout << "A new node has been inserted at the beginning \n" <<endl;

    return head;
}
//Insert at the after a given node
string insertAfter(string after, string data, Node *head){
    Node *temp = new Node; // create temporary node
    temp = head; // assign temporary node as head

    while(temp->songName.compare(after) != 0){ // search for the node
        if(temp == NULL){ // if no such node exist, break and return error message
            return "No such song exist, please try again later.";
        }
        temp = temp->link;
    }

    Node *newNode = createNode(data); // create new node
    newNode->link = temp->link; // assign the link of the new node to the node after the given node
    temp->link = newNode; // link new node to the given node

    return "An new node has been added after " + after + "\n"; // return confirmation message
}

int main(){

    Node *head = createNode ("Sanctuary by Joji");
    insertAtEnd("Sunday Morning by Maroon 5", head);
    insertAtEnd("Holy is The Lamb by Bishop Art", head);
    insertAtEnd("Bawat Sandali by Amiel", head);
    insertAtEnd("The Blessing by Elevation Worship", head);
    head = insertAtTheBeginning("Rain Rain Go Away by Cocomelon", head);
    head = insertAtTheBeginning("My Heart's Desire by Musikatha", head);
    head = insertAtTheBeginning("Ikaw at Ako by Moira Dela Torre", head);
    head = insertAtTheBeginning("Bawat Sandali By Amiel", head);
    
    traverse(head);
      return 0;
}
