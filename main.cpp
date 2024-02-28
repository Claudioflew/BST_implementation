#include <vector>
#include "BST.h"

using namespace std;

int main() {
    vector<int> initialNums {8, 4, 2, 5, 12, 29};
    BST myBST{BST()};

    for (int num : initialNums) {
        myBST.insert(num);
        cout << "Inserted key " << num << " into BST!" << endl;
    }
    cout << endl;

    myBST.preOrderDisplay();
    myBST.inOrderDisplay();
    myBST.postOrderDisplay();
    myBST.levelOrderDisplay();
    cout << endl;

    int val = myBST.search(29);
    if (val == 29) cout << "Found the key " << val << " in BST!" << endl;
    cout << endl;

    myBST.remove(8);
    cout << "Removed key 8 from BST!" << endl;
    myBST.search(8);
    myBST.preOrderDisplay();
    cout << endl;

    cout << "The height of BST is " << myBST.getHeight() << endl;
    cout << "The min key of BST is " << myBST.getMinKey() << endl;
    cout << "The max key of BST is " << myBST.getMaxKey() << endl;
}
