#include<bits/stdc++.h>
using namespace std;

ofstream outfile0;
ofstream outfile1;
ofstream outfile2;
ofstream outfile3;
ofstream outfile4;
ofstream outfile5;
ofstream outfile6;
ofstream outfile7;
ofstream outfile8;

/*
    ����˵����
        ���Ժ���������DestoryList_Sq/MergeList_Sq
        ListTraverse_Sq��ֻ����*2��/2����(���mul2)

    �����ʽ��
    ���� ����1 ����2 ...


    ������Ӧ��
    "Init"   InitList_Sq
    "Clear"  ClearList_Sq
    "Empty"  ListEmpty_Sq
    "Length" ListLength_Sq
    "Get"    GetElem_Sq
    "Locate" LocateElem_Sq
    "Prior"  PriorElem_Sq
    "Next"   NextElem_Sq
    "Insert" ListInsert_Sq
    "Delete" ListDelete_Sq
    "Travel" ListTraverse_Sq

*/
//----------|Test|-------------
#define Init        0
#define Clear       1
#define Empty       2
#define Length      3
#define Get         4
#define Locate      5
#define Prior       6
#define Next        7
#define Insert      8
#define Delete      9
#define Travel      10
//-----------------------------

//----------|Status|-----------
typedef int    Status;
#define TRUE        1
#define FALSE       0
#define OK          1
#define ERROR       0
#define INFEASIBLE -1
#define OVERFLOW   -2
//-----------------------------

//---------|Typedef|-----------
#define LIST_INIT_SIZE 100    //˳���洢�ռ�ĳ�ʼ������
#define LISTINCREMENT   10    //˳���洢�ռ�ķ�������
typedef int ElemType;         //˳���洢����������
struct SqList{
    ElemType  *elem;          //����ռ��ַ
    int       length;         //��ǰ����
    int       listsize;       //��ǰ����Ĵ�������(��sizeof(ElemType)Ϊ��λ)
};
//-----------------------------

//---------|FuncList|----------
Status InitList_Sq(struct SqList*);
    //����һ���յ�˳���L
Status DestroyList_Sq(struct SqList*);
    //����˳���L
void ClearList_Sq(struct SqList*);
    //��L����Ϊ�ձ�
Status ListEmpty_Sq(struct SqList*);
    //�ж�L�Ƿ�Ϊ�ձ�
int ListLength_Sq(struct SqList*);
    //����L������Ԫ�صĸ���
Status GetElem_Sq(struct SqList*, int, ElemType*);
    //��e����L�е�i������Ԫ�ص�ֵ
int compare(ElemType, ElemType);
    //Ԫ�صıȽϺ���
int LocateElem_Sq(struct SqList*, ElemType, int (*compare)(ElemType, ElemType));
    //��˳��˳���L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
Status PriorElem_Sq(struct SqList*, ElemType, ElemType*);
    //����cur_e��ǰ���ڵ�pre_e
Status NextElem_Sq(struct SqList*, ElemType, ElemType*);
    //����cur_e�ĺ�̽ڵ�next_e
Status ListInsert_Sq(struct SqList*, int, ElemType);
    //��˳���L�е�i��λ��֮ǰ�����µ�Ԫ��e
Status ListDelete_Sq(struct SqList*, int, ElemType*);
    //��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
void MergeList_Sq(struct SqList*, struct SqList*, struct SqList*, int (*compare)(ElemType, ElemType));
    //��֪˳���La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
Status ListTraverse_Sq(struct SqList*, Status (*visit)(ElemType*));
    //���ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ��
Status PrintList_Sq(struct SqList*);
    //��ӡ˳���L
//-----------------------------

SqList List;
list<ElemType> stdList;
int version = 0;
//��ǰ�汾
//����ǰ��Ķ������ݻ�ֱ����std0,std1��my0,my1��,versionΪ���β�����������ļ����

int ComCount = 0;
//��ִ��������

int StateNow;
int StateStdNow;
int AnsNow;
int AnsStdNow;

void printState(Status state)
{
    StateNow = state;

    outfile1 << state << endl;

}

void printstdState(Status state)
{
    StateStdNow = state;

    outfile2 << state << endl;
}

void printAns(int x)
{
    AnsNow = x;

    outfile3 << x << endl;

}

void printstdAns(int x)
{
    AnsStdNow = x;

    outfile4 << x << endl;
}


Status mul2(ElemType *a)
{
    if (a == NULL) return ERROR;
    if (*a > 200) (*a)/=2;
        else (*a)*=2;
    return OK;
}


bool execute(int x)
{
    int y, wz; ElemType ans = 0,number;
    bool flag;
    switch(x){
        case 0:
            printState(InitList_Sq(&List));
            printstdState(OK);
            printAns(0);
            printstdAns(0);
            break;
        case 1:
            printState(OK);
            printstdState(OK);
            printAns(0);
            printstdAns(0);
            break;
        case 2:
            printState(OK);
            printstdState(OK);
            printAns(ListEmpty_Sq(&List));
            printstdAns(stdList.empty());
            break;
        case 3:
            printState(OK);
            printstdState(OK);
            printAns(ListLength_Sq(&List));
            printstdAns(stdList.size());
            break;
        case 4:
            scanf("%d",&y);
            ans = 0;
            printState(GetElem_Sq(&List, y, &ans));
            printstdState((y >= 1 && y <= stdList.size())? OK : ERROR);
            printAns(ans);
            wz = 1;
            if (y >= 1 && y <= stdList.size())
            {
                int wz = 1;
                for(list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
                {
                    if (wz == y)
                    {
                        printstdAns(*iter);
                        break;
                    }else ++wz;
                }

            }else printstdAns(0);
            break;
        case 5:
            scanf("%d",&y);
            printState(OK);
            printstdState(OK);
            printAns(LocateElem_Sq(&List, y, compare));
            flag = false;
            wz = 1;
            for(list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
            {
                if (*iter == y)
                {
                    flag = true;
                    break;
                }
                else
                    ++wz;
            }
            if (!flag) printstdAns(0);
                else printstdAns(wz);
            break;
        case 6:
            scanf("%d",&y);
            ans = 0;
            printState(PriorElem_Sq(&List, y ,&ans));
            printAns(ans);
            flag = false;
            wz = 1;
            for(list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
            {
                if (*iter == y)
                {
                    flag = true;
                    break;
                }
                else
                    ++wz;
            }

            if (!flag || wz < 2){
                printstdState(ERROR);
                printstdAns(0);
            }else{
                printstdState(OK);
                {
                    --wz;
                    int wz2 = 1;
                    for(list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
                    {
                        if (wz2 == wz)
                        {
                            printstdAns(*iter);
                            break;
                        }else ++wz2;
                    }
                }
            }
            break;
        case 7:
            ans = 0;
            scanf("%d",&y);
            printState(NextElem_Sq(&List, y ,&ans));
            printAns(ans);

            wz = 1;
            flag = false;
            for(list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
            {
                if (*iter == y)
                {
                    flag = true;
                    break;
                }
                else
                    ++wz;
            }

            if (!flag || wz >= stdList.size()){
                printstdState(ERROR);
                printstdAns(0);
            }else{
                printstdState(OK);
                {
                    ++wz;
                    int wz2 = 1;
                    for(list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
                    {
                        if (wz2 == wz)
                        {
                            printstdAns(*iter);
                            break;
                        }else ++wz2;
                    }
                }
            }
            break;
        case 8:
            scanf("%d%d",&y,&number);
            printState(ListInsert_Sq(&List, y, number));
            printAns(0);
            wz = 1;
            if (y >= 1 && y <= stdList.size() + 1)
            {
                printstdState(OK);
                if (y == stdList.size() + 1)
                {
                    stdList.insert(stdList.end(),number);
                }else
                for (list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
                {
                    if (wz == y)
                    {
                        stdList.insert(iter,number);
                        break;
                    }else ++wz;
                }
            }else printstdState(ERROR);
            printstdAns(0);
            break;
        case 9:
            ans = 0;
            scanf("%d",&y);
            printState(ListDelete_Sq(&List, y, &ans));
            printAns(ans);
            wz = 1;
            if (y >= 1 && y <= stdList.size())
            {
                for (list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
                {
                    if (wz == y)
                    {
                        printstdAns(*iter);
                        stdList.erase(iter);
                        break;
                    }else ++wz;
                }
                printstdState(OK);
            }else printstdState(ERROR), printstdAns(0);
            break;
        case 10:
            printState(ListTraverse_Sq(&List, mul2));
            printAns(0);
            for (list<int>::iterator iter = stdList.begin();iter != stdList.end();iter++)
                if (*iter > 200)
                    *iter /= 2;
                else
                    *iter *= 2;
            printstdState(stdList.empty() ? ERROR : OK);
            printstdAns(0);
            break;
    }
    if (version == 0)
    {
        outfile5 << List.length << endl;
        for(int i = 0;i < List.length;++i)
            outfile5 << List.elem[i] << " ";
        outfile5 << endl;
    }else{
        outfile7 << List.length << endl;
        for(int i = 0;i < List.length;++i)
            outfile7 << List.elem[i] << " ";
        outfile7 << endl;
    }


    if (version == 0)
    {
        outfile6 << stdList.size() << endl;
        for (list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
            outfile6 << *iter << " ";
        outfile6 << endl;
    }else{
        outfile8 << stdList.size() << endl;
        for (list<int>::const_iterator iter = stdList.begin();iter != stdList.end();iter++)
            outfile8 << *iter << " ";
        outfile8 << endl;
    }

    if (stdList.size() != List.length)
        return false;
    list<int>::const_iterator iter = stdList.begin();
    for(int i = 0;i < List.length;++iter,++i)
    {
        if (*iter != List.elem[i])
            return false;
    }

    if (StateNow != StateStdNow)
        return false;
    if (AnsNow != AnsStdNow)
        return false;

    return true;
}

int main()
{
    int n;
    freopen("Sqtest.in","r",stdin);
    outfile1.open("State.txt");
    outfile2.open("stdState.txt");
    outfile3.open("ans.txt");
    outfile4.open("stdans.txt");
    outfile5.open("version0.txt");
    outfile6.open("versionStd0.txt");
    outfile7.open("version1.txt");
    outfile8.open("versionStd1.txt");
    scanf("%d",&n);
    for(int i=1;i<=n;++i)
    {
        int x;
        scanf("%d",&x);
        if (!execute(x))
        {
            outfile0.open("Log.txt");
            outfile0 << "ERROR IN COM " << ComCount + 1 << "\nNow The Version Is " << version << endl;
            outfile0.close();
            outfile1.close();
            outfile2.close();
            outfile3.close();
            outfile4.close();
            outfile5.close();
            outfile6.close();
            outfile7.close();
            outfile8.close();
            return 0;
        }
        version^=1;
        ++ComCount;
    }
    outfile1.close();
    outfile2.close();
    outfile3.close();
    outfile4.close();
    outfile5.close();
    outfile6.close();
    outfile7.close();
    outfile8.close();

    return 0;
}

//-----------------------------
Status InitList_Sq(struct SqList *L)
{
    //����һ���յ�˳���L
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if(!L->elem) exit(OVERFLOW);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;

    return OK;
}//InitList_Sq

Status DestroyList_Sq(struct SqList *L)
{
    //����˳���L
    if(!L->listsize) return ERROR; //���ǿձ�
    free(L->elem);
    L->length = 0;
    L->listsize = 0;
    return OK;
}//DestroyList_Sq

void ClearList_Sq(struct SqList *L)
{
    //��L����Ϊ�ձ�
    L->length = 0;
}//ClearList_Sq

Status ListEmpty_Sq(struct SqList *L)
{
    //�ж�L�Ƿ�Ϊ�ձ�
    if(L->length == 0)
        return TRUE;
    else return FALSE;
}//ListEmpty_Sq

int ListLength_Sq(struct SqList *L)
{
    //����L������Ԫ�صĸ���
    return L->length;
}//ListLength_Sq

Status GetElem_Sq(struct SqList *L, int i, ElemType *e)
{
    //��e����L�е�i������Ԫ�ص�ֵ
    //i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)
    if((i < 1) || (i > L->length)) return ERROR; //iֵ���Ϸ�
    *e = L->elem[i - 1];
    return OK;
}//GetElem_Sq

int compare(ElemType a, ElemType b)
{
    //Ԫ�صıȽϺ���
    return a-b;
}

int LocateElem_Sq(struct SqList *L, ElemType e, int (*compare)(ElemType, ElemType))
{
    //��˳��˳���L�в��ҵ�1��ֵ��e����compare()��Ԫ�ص�λ��
    //���ҵ����򷵻�����L�е�λ�򣬷��򷵻�0
    ElemType *p;
    int i = 1;    //i�ĳ�ֵΪ��1��Ԫ�ص�λ��
    p = L->elem;   //p�ĳ�ֵΪ��1��Ԫ�صĴ���λ��
    while(i <= L->length && (*compare)(*p++, e)) ++i;
    if(i <= L->length) return i;
    else return 0;
}//LocateElem_Sq

Status PriorElem_Sq(struct SqList *L, ElemType cur_e, ElemType *pre_e)
{
    //����cur_e��ǰ���ڵ�pre_e
    int Location;
    Location = LocateElem_Sq(L, cur_e, compare);
    if(Location < 2) return ERROR;
    else *pre_e = L->elem[Location - 2];
    return OK;
}//PriorElem_Sq

Status NextElem_Sq(struct SqList *L, ElemType cur_e, ElemType *next_e)
{
    //����cur_e�ĺ�̽ڵ�next_e
    int Location;
    Location = LocateElem_Sq(L, cur_e, compare);
    if(Location == 0 || Location == L->length) return ERROR;
    else *next_e = L->elem[Location];
    return OK;
}//NextElem_Sq

Status ListInsert_Sq(struct SqList *L, int i, ElemType e)
{
    //��˳���L�е�i��λ��֮ǰ�����µ�Ԫ��e
    //i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)+1
    ElemType *newbase, *q, *p;
    if(i < 1 || i > L->length+1) return ERROR; //iֵ���Ϸ�
    if(L->length >= L->listsize)
    {
        newbase = (ElemType *)realloc(L->elem, (L->listsize + LISTINCREMENT) * sizeof(ElemType));
        if(!newbase) exit(OVERFLOW);           //�������ʧ��
        L->elem = newbase;                     //�»�ַ
        L->listsize += LISTINCREMENT;          //���Ӵ�������
    }
    q = &(L->elem[i-1]);                       //qΪ�����ַ
    for(p = &(L->elem[L->length-1]); p >= q; --p)
        *(p + 1) = *p;                         //����λ�ü�֮���Ԫ������
    *q = e;                                    //����e
    L->length++;                               //����1
    return OK;
}//ListInsert_Sq

Status ListDelete_Sq(struct SqList *L, int i, ElemType *e)
{
    //��˳���L��ɾ����i��Ԫ�أ�����e������ֵ
    //i�ĺϷ�ֵΪ1<=i<=ListLength_Sq(L)
    ElemType *p, *q;
    if((i < 1) || (i > L->length)) return ERROR; //iֵ���Ϸ�
    p = &(L->elem[i - 1]);                       //pΪ��ɾ��Ԫ�ص�λ��
    *e = *p;                                    //��ɾ��Ԫ�ص�ֵ����e
    q = L->elem + L->length - 1;                  //��βԪ�ص�λ��
    for(++p; p <= q; ++p) *(p-1) = *p;          //��ɾ��Ԫ��֮���Ԫ������
    L->length--;                                 //����1
    return OK;
}//ListDelete_Sq

void MergeList_Sq(struct SqList *La, struct SqList *Lb, struct SqList *Lc, int (*compare)(ElemType, ElemType))
{
    //��֪˳���La��Lb��Ԫ�ذ�ֵ�ǵݼ�����
    //�鲢La��Lb�õ��µ�˳���Lc��Lc��Ԫ��Ҳ��ֵ�ǵݼ�����
    ElemType *pa, *pb, *pc, *pa_last, *pb_last;
    Lc->listsize = La->length + Lb->length;
    Lc->length = La->length + Lb->length;
    Lc->elem = (ElemType*)malloc(Lc->listsize * sizeof(ElemType));
    if(!Lc->elem) exit(OVERFLOW);
    pa = La->elem; pb = Lb->elem; pc = Lc->elem;
    pa_last = La->elem + La->length - 1;
    pb_last = Lb->elem + Lb->length - 1;
    while(pa <= pa_last && pb <= pb_last)//�鲢
    {
        if((*compare)(*pa, *pb) < 0)
            *pc++ = *pa++;
        else *pc++ = *pb++;
    }
    while(pa <= pa_last) *pc++ = *pa++; //����Laʣ��Ԫ��
    while(pb <= pb_last) *pc++ = *pb++; //����Lbʣ��Ԫ��
}//MergeList_Sq

Status ListTraverse_Sq(struct SqList *L, Status (*visit)(ElemType*))
{
    //���ζ�L��ÿ������Ԫ�ص��ú���visit()��һ��visit()ʧ�ܣ������ʧ��
    int i = 0;
    if (ListEmpty_Sq(L) == TRUE)
        return ERROR;
    while(i < L->length && visit(L->elem + i) == OK)
        i++;
    if(i >= L->length) return OK;
    else return ERROR;
}

Status PrintList_Sq(struct SqList *L)
{
    //��ӡ˳���L
    int i;
    for(i = 0; i < L->length; i++)
        printf("%d\t", *(L->elem + i));
    printf("\n");
}
