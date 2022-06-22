#include "Huffman_Tree.h"


Node* CreateNode(int data)
{
    Node* new_node = CreateNode(data);
    new_node->data = data;
    new_node->pRight = NULL;
    new_node->pLeft = NULL;
    return new_node;
}
void Delete_Duplicated_String(string& str)
{
    for (int i = 0; i < str.length()-1; i++)
    {
        for (int j = i + 1; j < str.length(); j++)
        {
            if (str[i] == str[j]) {
                str.erase(str.begin() + j);
                j--;
            }
        }
    }
}
int main()
{
    string str;
    cout << "Input string = "; getline(cin, str);
    string str1 = str;
    Delete_Duplicated_String(str1);
    Node* arr1 = new Node[str1.length()]; 
    for (int i = 0; i < str1.length(); i++)
    {
        int count = 0;
        for (int j = 0; j < str.length(); j++)
        {
            if (str1[i] == str[j])
            {
                count++;
            }
        }
        arr1[i].data = count;
        arr1[i].str += str1[i];
    }

    minHeap<Node> a(arr1, str1.length());
    Huffman_Tree tree;
    cout << endl;
    Node* head = nullptr;
    if (a.Size() > 1)
    {
        while (a.Size() > 1)
        {
            Node *node = new Node(a.getRoot());
            Node *node1 = new Node(a.getRoot());
            head = tree.CreateHead(node, node1);
            a.insert(*head);

        }
    }
    else {
        *head = a.getRoot();
        head->str_ki_tu += "0";
    }
    vector<Node*> arr2;
    //cout << str << endl;
    //cout << "-------------" << endl;
    string str123;
    
    if (head && head->str_ki_tu == "") {
        string str_ki_tu = "";
        tree.AddString(head, str_ki_tu, arr2);
    }
    
    for (int i = 0; i < arr2.size(); i++)
    {
        cout << arr2[i]->str << "-" << arr2[i]->str_ki_tu << "-" << arr2[i]->data << endl;
    }

    tree.printBST_2D(head, 0);
    string* str_encode = new string[str.length()];

    cout << "-------------" << endl;
    tree.Encode(arr2, str, str123);
    cout <<str <<" : "<< str123 << endl;

    cout << "-------------" << endl;
    string str_decoded = tree.decode(str123, arr2);
    cout << str123 << " : " << str_decoded << endl;
    cin.get();
    return 0;
}
