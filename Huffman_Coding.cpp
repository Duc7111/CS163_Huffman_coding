#include "Header.h"


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
    vector<Node*>arr1;
    string str;
    cout << "Input string = "; getline(cin, str);
    string str1 = str;
    Delete_Duplicated_String(str1);
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

        Node *node = new Node;
        node->data = count;
        node->str += str1[i];
        arr1.push_back(node);
    }

    minHeap<vector<Node*>>a(arr1);
    Huffman_Tree tree;
    cout << endl;
    Node* head = nullptr;
    if (a.Size() > 1)
    {
        while (a.Size() > 1)
        {
            Node* node = a.Get();
            Node* node1 = a.Get();
            head = tree.CreateHead(node, node1);
            a.Recieve(head);

        }
    }
    else {
        head = a.Get();
        head->str_ki_tu += "0";
    }
    
    //cout << str << endl;
    //cout << "-------------" << endl;
    string str123;
    if (head && head->str_ki_tu == "") {
        string str_ki_tu = "";
        
        arr1.clear();
        tree.AddString(head, str_ki_tu, arr1);
    }
    
    for (int i = 0; i < arr1.size(); i++)
    {
        cout << arr1[i]->str << "-" << arr1[i]->str_ki_tu << "-" << arr1[i]->data << endl;
    }

    //tree.printBST_2D(head, 0);
    string* str_encode = new string[str.length()];

    cout << "-------------" << endl;
    tree.Encode(arr1, str, str123);
    cout <<str <<" : "<< str123 << endl;

    cout << "-------------" << endl;
    string str_decoded = tree.decode(str123, arr1);
    cout << str123 << " : " << str_decoded << endl;
    return 0;
}
