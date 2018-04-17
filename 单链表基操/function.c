#include "index.h"

//************************************不带头结点************************************
typedef struct SList{
    DataType data;
    struct SList * next;
};

// 链表的初始化 s
void SListInit(PNode* pHead)
{
    assert(pHead);
   *pHead = NULL;
}

PNode AddNode(DataType data)
{
    PNode p = (PNode)malloc(sizeof(Node));
    if (p != NULL)
    {
        p->data = data;
        p->next = NULL;
        return p;
    }
    assert(p);
    return NULL;
}

// 尾插 
void SListPushBack(PNode *pHead, DataType data)
{
    assert(pHead);
    if (*pHead == NULL) //链表为空链表,则直接增加一个结点
    {
        *pHead = AddNode(data);
    }
    else    
    {
        PNode p = *pHead;
        while (p->next)
        {
            p = p->next;
        }
        p->next = AddNode(data);
    }
}

//尾删
void SListPopBack(PNode* pHead)
{ 
    assert(pHead);  //若链表不存在，报错
    if (*pHead == NULL) //若链表为空（没有结点），则不删
    {
        return;
    }                   
    if ((*pHead)->next == NULL) //只有一个结点，直接free掉，并将指向该结点的指针置空
    {
        free(*pHead);
        *pHead = NULL;
    }
    else                    //有多个结点
    {
        PNode pDel = *pHead;
        PNode pPre = pDel;
        while (pDel->next)
        {
            pPre = pDel;
            pDel = pPre->next;
        }
        free(pDel);
        pPre->next = NULL;
    }
}

// 头插 
void SListPushFront(PNode* pHead, DataType data)
{
    assert(pHead);
    if (*pHead == NULL)   //若为空链表，则直接加一个结点
    {
        *pHead = AddNode(data);
    }
    else                   //若有多个结点
    {
        PNode pCur = AddNode(data);
        pCur->next = *pHead;
        *pHead = pCur;
    }
}

// 头删 
void SListPopFront(PNode* pHead)
{
    assert(pHead);
    if (*pHead == NULL)   //若只有一个结点,直接free掉,并将指向该结点的指针置空
    {
        free(*pHead);
        *pHead = NULL;
    }
    else                  //若有多个结点
    {
        PNode pCur = (*pHead)->next;
        free(*pHead);
        *pHead = pCur;
    }
}

// 在链表中查找值为data的元素，找到后返回值为data的结点 
PNode SListFind(PNode pHead, DataType data)
{ 
    if (pHead == NULL) //若链表为空，则返回NULL
    {
        return NULL;         
    }
    else
    {
        PNode pCur = pHead;
        while(pCur)
        {
            if (pCur->data == data)
            {
                return pCur;
            }
            pCur = pCur->next;
        }
        return NULL;
    }
}

// 在pos位置插入值为data的结点 
void SListInsert(PNode* pHead, PNode pos, DataType data)
{
    PNode pCur = NULL;
    PNode pPre = NULL;
    assert(pHead);
    if (*pHead == NULL) //若链表为空，位置pos无意义，返回
    {
        printf("链表为空，位置pos无意义，返回\n");
        return;
    }
    pCur = *pHead;
    pPre = pCur;
    while(pCur)
    {
        if (pCur == pos && pCur == *pHead)  //若位置在第一个结点，则修改一条next
        {
            pPre = AddNode(data);
            pPre->next = pCur;
            *pHead = pPre;
            return;
        }
        if (pCur == pos)               //位置不是第一个结点，则修改两条next
        {
            pPre->next = AddNode(data);
            pPre->next->next = pCur;
            return;
        }
        pPre = pCur;
        pCur = pCur->next;
    }   //循环结束，说明pCur指向了最后一个结点的next，即没找到
    printf("插入失败，该位置不存在\n");
    
}

// 删除pos位置的结点 
void SListErase(PNode* pHead, PNode pos)
{
    assert(pHead);
    if (*pHead == NULL) //若链表为空，则删除失败。
    {
        printf("链表为空，位置pos无意义，返回\n");
        return;
    }
    if (*pHead == pos)  //若是第一个结点，直接将*pHead后移，接着free掉*pHead之前的结点
    {
        PNode pH = *pHead;
        *pHead = (*pHead)->next;
        free(pH);
    }
    else                //若是中间结点或最后一个结点，则需分情况
    {
        PNode pCur = *pHead;
        PNode pPre = pCur;
        while(pCur)
        {
            if (pCur == pos && pCur->next == NULL)  //若为最后一个结点，则只需将倒数第二个结点的next置空
            {
                pPre->next = NULL;
                free(pCur);
                return;
            }
            if (pCur == pos)        //若为中间结点，则需将该结点的前一结点的next指向该结点的next            
            {
                pPre->next = pCur->next;
                free(pCur);
                return;
            }
            pPre = pCur;
            pCur = pCur->next;
        }   //若循环结束，则pCur走到空，说明没找到
        printf("该位置买找到，删除失败\n");
    }
}

// 获取链表的长度
int SListSize(PNode pHead)
{
    PNode pCur;
    int count = 0;
    if (pHead == NULL)
    {
        return count;
    }
    pCur = pHead;
    while(pCur)
    {
        pCur = pCur->next;
        count++;
    }
    return count;
}

// 判断链表是否为空 
int SListEmpty(PNode pHead)
{
    if (pHead == NULL)  //链表为空返回0；链表不为空则返回1。
    {
        return 0;
    }
    return 1;
}

// 销毁链表 
void SListDestroy(PNode* pHead)
{
    PNode pCur = NULL;
    PNode pNex = NULL;
    assert(pHead);
    pCur = *pHead;
    pNex = pCur;
    if (pCur == NULL)   //若链表为空，直接返回
    {
        return;
    }
    if (pCur->next == NULL) //若只有一个结点，则将第一个结点free掉后将pHead置空
    {
        free(pCur);
        *pHead = NULL;
        return;
    }
    pNex = pCur->next;
    while(pCur->next->next) //若有多个结点，则将各个结点从头往后逐一free，最后将pHead置空。
    {
        free(pCur);
        pCur = pNex;
        pNex = pNex->next;
    }
    free(pCur);
    free(pNex);
    *pHead = NULL;
}

//打印链表
void SListPrint(PNode pHead)
{
    PNode p = pHead;
    while(p)
    {
        printf("%d-->", p->data);
        p = p->next;
    }
    printf("NULL\n");
}