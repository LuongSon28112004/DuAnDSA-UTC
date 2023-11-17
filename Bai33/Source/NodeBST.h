
#ifndef NODE_BST_
#define NODE_BST_

#include "../Source/CongViecTrongNgay.h"

#include <iostream>
#include <string>
#include <vector>
#include "../Source/CayBST.h"

using namespace std;

class NodeBST
{
private:
    CongViecTrongNgay cv;
    NodeBST *left;
    NodeBST *right;
    friend class CayBST;
public:
    NodeBST()
    {
        left = NULL;
        right = NULL;
    }
    ~NodeBST()
    {
        left = NULL;
        right = NULL;
    }

    CongViecTrongNgay getcv()
    {
        return cv;
    }

    void setcv(const CongViecTrongNgay &a)
    {
        cv = a;
    }

    friend NodeBST *makenode(CongViecTrongNgay a);
};

NodeBST *makenode(CongViecTrongNgay a)
{
    NodeBST *tmp = new NodeBST;
    tmp->cv = a;
    tmp->left = NULL;
    tmp->right = NULL;
    return tmp;
}

#endif