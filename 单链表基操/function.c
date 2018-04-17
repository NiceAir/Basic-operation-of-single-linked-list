#include "index.h"

//************************************����ͷ���************************************
typedef struct SList{
    DataType data;
    struct SList * next;
};

// ����ĳ�ʼ�� s
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

// β�� 
void SListPushBack(PNode *pHead, DataType data)
{
    assert(pHead);
    if (*pHead == NULL) //����Ϊ������,��ֱ������һ�����
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

//βɾ
void SListPopBack(PNode* pHead)
{ 
    assert(pHead);  //���������ڣ�����
    if (*pHead == NULL) //������Ϊ�գ�û�н�㣩����ɾ
    {
        return;
    }                   
    if ((*pHead)->next == NULL) //ֻ��һ����㣬ֱ��free��������ָ��ý���ָ���ÿ�
    {
        free(*pHead);
        *pHead = NULL;
    }
    else                    //�ж�����
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

// ͷ�� 
void SListPushFront(PNode* pHead, DataType data)
{
    assert(pHead);
    if (*pHead == NULL)   //��Ϊ��������ֱ�Ӽ�һ�����
    {
        *pHead = AddNode(data);
    }
    else                   //���ж�����
    {
        PNode pCur = AddNode(data);
        pCur->next = *pHead;
        *pHead = pCur;
    }
}

// ͷɾ 
void SListPopFront(PNode* pHead)
{
    assert(pHead);
    if (*pHead == NULL)   //��ֻ��һ�����,ֱ��free��,����ָ��ý���ָ���ÿ�
    {
        free(*pHead);
        *pHead = NULL;
    }
    else                  //���ж�����
    {
        PNode pCur = (*pHead)->next;
        free(*pHead);
        *pHead = pCur;
    }
}

// �������в���ֵΪdata��Ԫ�أ��ҵ��󷵻�ֵΪdata�Ľ�� 
PNode SListFind(PNode pHead, DataType data)
{ 
    if (pHead == NULL) //������Ϊ�գ��򷵻�NULL
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

// ��posλ�ò���ֵΪdata�Ľ�� 
void SListInsert(PNode* pHead, PNode pos, DataType data)
{
    PNode pCur = NULL;
    PNode pPre = NULL;
    assert(pHead);
    if (*pHead == NULL) //������Ϊ�գ�λ��pos�����壬����
    {
        printf("����Ϊ�գ�λ��pos�����壬����\n");
        return;
    }
    pCur = *pHead;
    pPre = pCur;
    while(pCur)
    {
        if (pCur == pos && pCur == *pHead)  //��λ���ڵ�һ����㣬���޸�һ��next
        {
            pPre = AddNode(data);
            pPre->next = pCur;
            *pHead = pPre;
            return;
        }
        if (pCur == pos)               //λ�ò��ǵ�һ����㣬���޸�����next
        {
            pPre->next = AddNode(data);
            pPre->next->next = pCur;
            return;
        }
        pPre = pCur;
        pCur = pCur->next;
    }   //ѭ��������˵��pCurָ�������һ������next����û�ҵ�
    printf("����ʧ�ܣ���λ�ò�����\n");
    
}

// ɾ��posλ�õĽ�� 
void SListErase(PNode* pHead, PNode pos)
{
    assert(pHead);
    if (*pHead == NULL) //������Ϊ�գ���ɾ��ʧ�ܡ�
    {
        printf("����Ϊ�գ�λ��pos�����壬����\n");
        return;
    }
    if (*pHead == pos)  //���ǵ�һ����㣬ֱ�ӽ�*pHead���ƣ�����free��*pHead֮ǰ�Ľ��
    {
        PNode pH = *pHead;
        *pHead = (*pHead)->next;
        free(pH);
    }
    else                //�����м�������һ����㣬��������
    {
        PNode pCur = *pHead;
        PNode pPre = pCur;
        while(pCur)
        {
            if (pCur == pos && pCur->next == NULL)  //��Ϊ���һ����㣬��ֻ�轫�����ڶ�������next�ÿ�
            {
                pPre->next = NULL;
                free(pCur);
                return;
            }
            if (pCur == pos)        //��Ϊ�м��㣬���轫�ý���ǰһ����nextָ��ý���next            
            {
                pPre->next = pCur->next;
                free(pCur);
                return;
            }
            pPre = pCur;
            pCur = pCur->next;
        }   //��ѭ����������pCur�ߵ��գ�˵��û�ҵ�
        printf("��λ�����ҵ���ɾ��ʧ��\n");
    }
}

// ��ȡ����ĳ���
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

// �ж������Ƿ�Ϊ�� 
int SListEmpty(PNode pHead)
{
    if (pHead == NULL)  //����Ϊ�շ���0������Ϊ���򷵻�1��
    {
        return 0;
    }
    return 1;
}

// �������� 
void SListDestroy(PNode* pHead)
{
    PNode pCur = NULL;
    PNode pNex = NULL;
    assert(pHead);
    pCur = *pHead;
    pNex = pCur;
    if (pCur == NULL)   //������Ϊ�գ�ֱ�ӷ���
    {
        return;
    }
    if (pCur->next == NULL) //��ֻ��һ����㣬�򽫵�һ�����free����pHead�ÿ�
    {
        free(pCur);
        *pHead = NULL;
        return;
    }
    pNex = pCur->next;
    while(pCur->next->next) //���ж����㣬�򽫸�������ͷ������һfree�����pHead�ÿա�
    {
        free(pCur);
        pCur = pNex;
        pNex = pNex->next;
    }
    free(pCur);
    free(pNex);
    *pHead = NULL;
}

//��ӡ����
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