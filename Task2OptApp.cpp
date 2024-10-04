#include <iostream>
#include <map>
#include <vector>
#include <string>
using namespace std;

class OptimizedVersionControl {
private:
    map<int,string> revisions;
    int latestRevisionId;

public:
    OptimizedVersionControl() {
        latestRevisionId = -1;
    }

    void addRevision(string content) {
        latestRevisionId++;
        revisions[latestRevisionId] = content;
    }

    string getRevision(int revisionId) {
        if(latestRevisionId == -1) {
            return "No revisions available";
        }
        else if (revisions.find(revisionId) != revisions.end()) {
            return revisions[revisionId];
        }
        else return "Revision not found";
    }

    string getLatestRevision() {
        if (latestRevisionId >= 0) {
            return revisions[latestRevisionId];
        }
        return "No revisions available";
    }

    vector<pair<int,string>> getAllRevisions() {
        vector<pair<int,string>> allRevs;
        for (auto rev : revisions) {
            allRevs.push_back({rev.first,rev.second});
        }
        return allRevs;
    }
};

int main() {
    OptimizedVersionControl optimizedVC;

    optimizedVC.addRevision("Revision 1 content");
    optimizedVC.addRevision("Revision 2 content");
    optimizedVC.addRevision("Revision 3 content");
    optimizedVC.addRevision("Revision 4 content");

    cout<<"Latest Revision: "<<optimizedVC.getLatestRevision()<<endl;
    cout<< "Revision 0: "<<optimizedVC.getRevision(0)<< endl;

    vector<pair<int,string>> allRevisions = optimizedVC.getAllRevisions();
    cout<<"All Revisions: "<<endl;
    for(auto revision : allRevisions) {
        cout<<"uniqueID : "+to_string(revision.first)+" -> "+revision.second<<endl;
    }

    return 0;
}
