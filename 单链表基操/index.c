#include "index.h"

//************************************²»´øÍ·½áµã************************************
int main()
{
    PNode pHead = NULL;
//*********test_PushBack**********

    //SListPrint(pHead);
    //SListPushBack(&pHead, 1);
    //SListPrint(pHead);
    //SListPushBack(&pHead, 2);
    //SListPrint(pHead);
    //SListPushBack(&pHead, 3);
    //SListPrint(pHead);
    //SListPushBack(&pHead, 4);
    //SListPrint(pHead);
    //SListPushBack(&pHead, 5);
    //SListPrint(pHead);
    //free(pHead);
    //printf("*****************************************\n\n");


//*********test_PopBack************
    //SListInit(&pHead);
    //SListPushBack(&pHead, 1);
    //SListPushBack(&pHead, 2);
    //SListPushBack(&pHead, 3);
    //SListPushBack(&pHead, 4);
    //SListPushBack(&pHead, 5);
    //SListPushBack(&pHead, 6);
    //SListPrint(pHead);
    //SListPopBack(&pHead); //É¾6
    //SListPrint(pHead);
    //SListPopBack(&pHead); //É¾5
    //SListPrint(pHead);
    //SListPopBack(&pHead); //É¾4
    //SListPrint(pHead);
    //SListPopBack(&pHead); //É¾3
    //SListPrint(pHead);
    //SListPopBack(&pHead); //É¾2
    //SListPrint(pHead);
    //SListPopBack(&pHead); //É¾1
    //SListPrint(pHead);
    //SListPopBack(&pHead); //É¾³ý¿ÕÁ´±í
    //SListPrint(pHead);
    //printf("*****************************************\n\n");

//**************test_PushFront**********************
    //SListPrint(pHead);
    //SListPushFront(&pHead,1);
    //SListPrint(pHead);
    //SListPushFront(&pHead,2);
    //SListPrint(pHead);
    //SListPushFront(&pHead,3);
    //SListPrint(pHead);
    //SListPushFront(&pHead,4);
    //SListPrint(pHead);
    //printf("*****************************************\n\n");

//********************test_PopFront**************************

     //SListPushFront(&pHead,1);
     //SListPushFront(&pHead,2);
     //SListPushFront(&pHead,3);
     //SListPushFront(&pHead,4);
     //SListPrint(pHead);
 
    // SListPopFront(&pHead);
    // SListPrint(pHead);
    // SListPopFront(&pHead);
    // SListPrint(pHead);
    // SListPopFront(&pHead);
    // SListPrint(pHead);
    // SListPopFront(&pHead);
    // SListPrint(pHead);
    // SListPopFront(&pHead);
    // SListPrint(pHead);
    //printf("*****************************************\n\n");

//********************test_SListFind***************************
    //PNode pRes = NULL;
    //SListPushFront(&pHead,1);
    //SListPushFront(&pHead,2);
    //SListPushFront(&pHead,3);
    //SListPushFront(&pHead,4);
    //SListPrint(pHead);
    //pRes = SListFind(pHead, 1);
    //SListPrint(pRes);
    //pRes = SListFind(pHead, 2);
    //SListPrint(pRes);
    //pRes = SListFind(pHead, 3);
    //SListPrint(pRes);
    //pRes = SListFind(pHead, 4);
    //SListPrint(pRes);
    //pRes = SListFind(pHead, 0);
    //SListPrint(pRes);
    //printf("*****************************************\n\n");

//********************test_SListInsert*******************************
    //SListPushFront(&pHead,1);
    //SListPushFront(&pHead,2);
    //SListPushFront(&pHead,3);
    //SListPushFront(&pHead,4);
    //SListPrint(pHead);
    //SListInsert(&pHead, SListFind(pHead, 0), 1);
    //SListPrint(pHead);
    //SListInsert(&pHead, SListFind(pHead, 4), 5);
    //SListPrint(pHead);
    //SListInsert(&pHead, SListFind(pHead, 3), 6);
    //SListPrint(pHead);
    //SListInsert(&pHead, SListFind(pHead, 2), 7);
    //SListPrint(pHead);
    //SListInsert(&pHead, SListFind(pHead, 1), 8);
    //SListPrint(pHead);
    //SListInsert(&pHead, NULL, 9);
    //SListPrint(pHead);
    //printf("*****************************************\n\n");

//**************test_SListErase**********************************************
    //SListPushFront(&pHead,1);
    //SListPushFront(&pHead,2);
    //SListPushFront(&pHead,3);
    //SListPushFront(&pHead,4);
    //SListPrint(pHead);
    //SListErase(&pHead, SListFind(pHead, 1));
    //SListPrint(pHead);
    //SListErase(&pHead, SListFind(pHead, 4));
    //SListPrint(pHead);
    //SListErase(&pHead, SListFind(pHead, 2));
    //SListPrint(pHead);
    //SListErase(&pHead, SListFind(pHead, 3));
    //SListPrint(pHead);
    //SListErase(&pHead, SListFind(pHead, 3));
    //SListPrint(pHead);
    //printf("*****************************************\n\n");

//**********************test_SListSize**********************************

    //printf("%d\n", SListSize(pHead));
    //SListPushFront(&pHead,1);
    //printf("%d\n", SListSize(pHead));
    //SListPrint(pHead);

    //SListPushFront(&pHead,2);
    //printf("%d\n", SListSize(pHead));
    //SListPrint(pHead);

    //SListPushFront(&pHead,3);
    //printf("%d\n", SListSize(pHead));
    //SListPrint(pHead);

    //SListPushFront(&pHead,4);
    //printf("%d\n", SListSize(pHead));
    //SListPrint(pHead);
    //printf("*****************************************\n\n");

//*************************test_SListDestroy**********************************
    SListPushFront(&pHead,1);
    SListPushFront(&pHead,2);
    SListPushFront(&pHead,3);
    SListPushFront(&pHead,4);
    SListPrint(pHead);
    SListDestroy(&pHead);
    SListPrint(pHead);
    printf("\n\n");

    SListPushFront(&pHead,1);
    SListPushFront(&pHead,2);
    SListPushFront(&pHead,3);
    SListPrint(pHead);
    SListDestroy(&pHead);
    SListPrint(pHead);
    printf("\n\n");


    SListPushFront(&pHead,1);
    SListPushFront(&pHead,2);
    SListPrint(pHead);
    SListDestroy(&pHead);
    SListPrint(pHead);
    printf("\n\n");

    SListPushFront(&pHead,1);
    SListPrint(pHead);
    SListDestroy(&pHead);
    SListPrint(pHead);
    printf("\n\n");

    SListPrint(pHead);
    SListDestroy(&pHead);
    SListPrint(pHead);
    printf("\n\n");

    SListPrint(NULL);
    SListDestroy(&pHead);
    SListPrint(pHead);
    printf("\n\n");
    return 0;
}