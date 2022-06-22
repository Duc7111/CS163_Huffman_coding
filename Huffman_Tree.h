#pragma once
#include "vector"
#include "Heap.h"
#include <iostream>
#include <string>
using namespace std;

struct Node {
    string str = "";
    string str_ki_tu = "";
    int data = 0;
    Node* pRight = NULL;
    Node* pLeft = NULL;
};
class Huffman_Tree {
private:
    Node* pHead;
public:
    Huffman_Tree() {
        pHead = NULL;
    }
    Node* CreateHead( Node *Left, Node *Right)
    {  
        Node *new_node = new Node;
        new_node->data = Left->data + Right->data;
        new_node->pLeft = Left;
        new_node->pRight = Right;
        pHead = new_node;
        return pHead;
    }
    string decode(string str, vector<Node*> arr) 
    {
        string decoded_str = "";
        string temp = ""; 
        int j;
        for (int i = 0; i < str.length(); ++i) 
        {
            temp += str[i];
            for (j = 0; j < arr.size(); ++j) {
                if (temp == arr[j]->str_ki_tu && arr[j]->data) {
                    --arr[j]->data;
                    decoded_str += arr[j]->str;
                    break;
                }
            }
            if (j != arr.size()) {
                temp = "";
            }
        } 
        return decoded_str;
    }

    void Print_NLR(Node* root)
    {
        if (root != NULL) {
            cout << root->str << " " << root->data << endl;
            Print_NLR(root->pLeft);
            Print_NLR(root->pRight);
        }
    }
    void printBST_2D(Node* pRoot, int space) {
        if (!pRoot) return;
        space += 10;

        printBST_2D(pRoot->pRight, space);
        cout << endl;
        for (int i = 10; i < space; ++i) cout << " ";
        cout <<pRoot->str <<"-"<< pRoot->data<<"-"<<pRoot->str_ki_tu << endl;
        printBST_2D(pRoot->pLeft, space);
    }
    void AddString(Node* pRoot,string str,vector<Node*>&arr)
    {
        if (pRoot->str != "") {
            arr.push_back(pRoot);
        }
        pRoot->str_ki_tu = str;
        if (pRoot->pLeft)
        {
            AddString(pRoot->pLeft,  str + "0",arr);
        }
        if (pRoot->pRight)
        {
            AddString(pRoot->pRight, str + "1",arr);
        }
    }

    void Encode(vector<Node*>arr, string str, string& huffman_str)
    {
        for (int i = 0; i < str.length(); i++)
        {
            string str1 = "";
            str1 += str[i];
            for (int j = 0; j < arr.size(); j++)
            {

                if (arr[j]->str == str1) {
                    huffman_str+=arr[j]->str_ki_tu;
                    break;
                }
            }
        }    }
};


/* template<class T>
class minHeap
{
private: 
    T heap;
public:
    minHeap(T arr) : heap(arr)
    {
        Sort();
    }
    void Print()
    {
        for (int i = 0; i < heap.size(); i++)
        {
            cout << heap[i]->str << " " << heap[i]->data << endl;
        }
    };

    void Sort() 
    {
        for (int i = 1; i < heap.size() ; ++i)
        {
            int t = i;
            while (t)
            {
                if (heap[t]->data > heap[(t - 1) / 2]->data) break;
                else
                {
                    int k = t;
                    t = (t - 1) / 2;
                    swap(heap[t], heap[k]);
                }
            }
        }
    }
    Node *Get()
    {
        Node *temp = heap[0];
        heap.erase(heap.begin());
        Sort();
        return temp;
    }
    void Recieve(Node *node)
    {
        heap.push_back(node);
        Sort();
    }
    int Size()
    {
        return heap.size();
    }
    ~minHeap()
    {

    }
}; */