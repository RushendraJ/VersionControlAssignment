#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Node {
    public:
    int uniqueID;
    string revision;
    Node* next;
    Node(int id,string s) {
        uniqueID = id;
        revision = s;
        next = NULL;
    }
};

class NaiveVersionControl {
private:
    Node *head;
    int idCounter;

public:
    NaiveVersionControl() {
        head = NULL;
        idCounter = 0;
    }
    void addRevision(string content) {
        Node* nn = new Node(idCounter++,content);
        Node* temp = head;
        if(temp == NULL) {
            head = nn;
            return;
        }
        else {
            while(temp->next != NULL) {
                temp = temp->next;
            }
            temp->next = nn;
        }
    }

    string getRevision(int revisionId) {
        Node* temp = head;
        if(temp == NULL) {
            return "No revisions present";
        }
        else {
            while(temp != NULL) {
                if(temp->uniqueID == revisionId) {
                    return temp->revision;
                }
                temp = temp->next;
            }
            return "Revision not found with the provided revisionId";
        }
    }

    string getLatestRevision() {
        Node* temp = head;
        if(temp == NULL) {
            return "No revisions present";
        }
        else {
            while(temp->next != NULL) {
                temp = temp->next;
            }
            return temp->revision;
        }
    }

    Node* getAllRevisions() {
        return head;
    }
};

int main() {
    NaiveVersionControl naiveVC;
    
    naiveVC.addRevision("Revision 1 content");
    naiveVC.addRevision("Revision 2 content");
    naiveVC.addRevision("Revision 3 content");
    naiveVC.addRevision("Revision 4 content");
    
    cout<<"Latest Revision: " << naiveVC.getLatestRevision()<<endl;
    cout<<"Revision 0: "<<naiveVC.getRevision(0)<<endl;
    
    Node* allRevisions = naiveVC.getAllRevisions();
    cout<<"All Revisions: "<<endl;
    Node* temp = allRevisions;
    while(temp != NULL) {
        cout<<"uniqueID : "+to_string(temp->uniqueID)+" -> "+temp->revision<<endl;
        temp = temp->next;
    }

    return 0;
}
