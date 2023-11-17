
#ifndef CAY_BST_H
#define CAY_BST_H

#include "../Source/NodeBST.h"
#include "../Source/CongViecTrongNgay.h"
#include "../Source/LinkList.h"

#include <iostream>

using namespace std;

class CayBST
{
private:
    NodeBST *headBST;
    int cnt;

public:
    CayBST()
    {
        headBST = NULL;
        cnt = 0;
    }
    ~CayBST()
    {
        headBST = NULL;
        cnt=0;
    }

    NodeBST *&getheadBST()
    {
        return headBST;
    }

    void setheadBST(NodeBST *head)
    {
        headBST = head;
    }
    int getcnt() const
    {
        return cnt;
    }

    void setcnt(int count)
    {
        cnt = count;
    }

    bool is_empty()
    {
        if (headBST == NULL)
        {
            return true;
        }
        return false;
    }

    void insertNodeBST(NodeBST *&a, CongViecTrongNgay x)
    {
        NodeBST *tmp = new NodeBST;

        tmp = makenode(x);
        if (a == NULL)
        {
            cnt++;
            a = tmp;
            return;
        }
        else if (tmp->cv.getten_ngay() < a->cv.getten_ngay())
        {
            insertNodeBST(a->left, x);
        }
        else if (tmp->cv.getten_ngay() > a->cv.getten_ngay())
        {
            insertNodeBST(a->right, x);
        }
        else if (tmp->cv.getten_ngay() == a->cv.getten_ngay())
        {
            if (a->cv.gethead() == NULL)
            {
                node p = tmp->cv.gethead();
                a->cv.sethead(p);
            }
            else
            {
                int n = Size(tmp->cv.gethead());
                node node1_ = a->cv.gethead();
                node node2_ = tmp->cv.gethead();
                for (int i = 0; i < n; i++)
                {
                    CongViec p = node2_->data;
                    insertLast(node1_, p);
                    node2_ = node2_->next;
                }
                sapxep(node1_);
            }
            return;
        }
    }

    void XemLichCongTacTheoNgayYeuCau(NodeBST *a, int ngay)
    {
        if (a != NULL)
        {
            if (a->cv.getten_ngay() == ngay)
            {
                a->cv.inDS();
                return;
            }
            else if (a->cv.getten_ngay() < ngay)
            {
                XemLichCongTacTheoNgayYeuCau(a->right, ngay);
            }
            else if (a->cv.getten_ngay() > ngay)
            {
                XemLichCongTacTheoNgayYeuCau(a->left, ngay);
            }
        }
    }

    void XemLichCongTacTheoTinhChatYeuCau(NodeBST *a, string tinh_chat)
    {
        if (a != NULL)
        {
            XemLichCongTacTheoTinhChatYeuCau(a->left, tinh_chat);
            a->cv.inDS_Theo_Tinh_Chat_Cong_Viec(tinh_chat);
            XemLichCongTacTheoTinhChatYeuCau(a->right, tinh_chat);
        }
    }

    void DanhDauCacCongViecDaHoanThanh(NodeBST *a, int ngay, string giobatdau, string tencv)
    {
        if (a != NULL)
        {
            if (a->cv.getten_ngay() == ngay)
            {
                node p = a->cv.gethead();
                TickCongViecHoanThanh(p, giobatdau, tencv);
                return;
            }
            DanhDauCacCongViecDaHoanThanh(a->right, ngay, giobatdau, tencv);
            DanhDauCacCongViecDaHoanThanh(a->left, ngay, giobatdau, tencv);
        }
    }

    void XemCacCongViecDaHoanhThanh(NodeBST *a)
    {
        if (a != NULL)
        {
            XemCacCongViecDaHoanhThanh(a->left);
            a->cv.inDS_Theo_Cong_Viec_Da_Hoan_Thanh();
            XemCacCongViecDaHoanhThanh(a->right);
        }
    }

    void XemCacCongViecChuaHoanhThanh(NodeBST *a)
    {
        if (a != NULL)
        {
            XemCacCongViecChuaHoanhThanh(a->left);
            a->cv.inDS_Theo_Cong_Viec_Chua_Hoan_Thanh();
            XemCacCongViecChuaHoanhThanh(a->right);
        }
    }

    void XemCacCongViecTuNgayaDenNgayb(NodeBST *a, int x, int y)
    {
        if (a != NULL)
        {
            XemCacCongViecTuNgayaDenNgayb(a->left, x, y);
            if (a->cv.getten_ngay() >= x && a->cv.getten_ngay() <= y)
            {
                a->cv.inDS();
            }
            XemCacCongViecTuNgayaDenNgayb(a->right, x, y);
        }
    }

    void DeleteCacCongViecDaHoanThanh(NodeBST *a)
    {
        if (a != NULL)
        {
            node &tmp = a->cv.gethead();
            while (findPos(tmp) != 0)
            {
                if (findPos(tmp) == 1)
                {
                    deleteDau(tmp);
                }
                else if (findPos(tmp) == Size(tmp))
                {
                    deleteCuoi(tmp);
                }
                else
                {
                    deleteGiua(tmp, findPos(tmp));
                }
            }
            DeleteCacCongViecDaHoanThanh(a->right);
            DeleteCacCongViecDaHoanThanh(a->left);
        }
    }

    void FindNodeTheMang(NodeBST *&x, NodeBST *&y)
    {
        if (y->left != NULL)
        {
            FindNodeTheMang(x, y->left);
        }
        else
        {
            x->cv = y->cv;
            x = y;
            y = y->right;
        }
    }

    void DeleteNode(NodeBST *&a, int ten_ngay)
    {
        if (a == NULL)
        {
            return;
        }
        if (a->cv.getten_ngay() == ten_ngay)
        {
            NodeBST *p = a;
            if (a->left == NULL)
            {
                a = a->right;
                --cnt;
            }
            else if (a->right == NULL)
            {
                a = a->left;
                --cnt;
            }
            else if (a->left != NULL && a->right != NULL) // ca cay con trai va cay con phai deu khác NULL
            {
                NodeBST *q = a;
                FindNodeTheMang(p, q->right);
                --cnt;
            }
            delete p; // xoa node
            return;
        }
        else if (a->cv.getten_ngay() < ten_ngay)
        {
            DeleteNode(a->right, ten_ngay);
        }
        else if (a->cv.getten_ngay() > ten_ngay)
        {
            DeleteNode(a->left, ten_ngay);
        }
    }

    void DieuChinhLichCongTac(NodeBST *a, NodeBST *&b)
    {
        if (a != NULL)
        {
            if (a->cv.gethead() == NULL)
            {
                DeleteNode(b, a->cv.getten_ngay());
            }
            DieuChinhLichCongTac(a->left, b);
            DieuChinhLichCongTac(a->right, b);
        }
    }

    void xuat(NodeBST *a)
    {
        if (a != NULL)
        {
            xuat(a->left); // duyet trai
            a->cv.inDS();
            xuat(a->right); // duyet phai
        }
    }
};

#endif
