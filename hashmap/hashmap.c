#include "hashmap.h"
//计算容量
int ExpendCapacity(size_t len)
{
    size_t i = 0;
    //使用素数表对齐做哈希表的容量，降低哈希冲突
    const int _PrimeSize = 28;
    static const unsigned long _PrimeList[28] = {
        53ul, 97ul, 193ul, 389ul, 769ul, 1543ul, 3079ul, 6151ul,
        12289ul, 24593ul, 49157ul, 98317ul, 196613ul, 393241ul,
        786433ul, 1572869ul, 3145739ul, 6291469ul, 12582917ul,
        25165843ul, 50331653ul, 100663319ul, 201326611ul, 402653189ul,
        805306457ul, 1610612741ul, 3221225473ul, 4294967291ul};
    for (; i < 28; i++)
    {
        if (_PrimeList[i] > len)
            return _PrimeList[i];
    }
    return _PrimeList[28 - 1];
}
//计算关键码所在的位置,除留余数法
int HashFunc(HTBKeyType key, size_t len)
{
    return key % len;
}
//检查是否需要扩容
//在哈希桶中扩容的条件为当它的存储的数据大小等于哈希桶的长度时,证明需要扩容
int CheckCapacity(HTB *htb)
{
    if (htb->_size == htb->_len)
        return 1;
    else
        return 0;
}
//哈希桶初始化
void HTBInit(HTB *htb, size_t len)
{
    assert(htb);
    htb->_tables = (HashNode **)malloc(sizeof(HashNode *) * ExpendCapacity(len));
    htb->_len = ExpendCapacity(len);
    htb->_size = 0;
    //将所有数据置空
    memset(htb->_tables, 0, sizeof(HashNode *) * ExpendCapacity(len));
}
//哈希桶销毁
//注意:这里使用的是二级指针,不能直接将htb->tables直接销毁,这就相当于
//将单链表的头结点删除而它的后继节点并没有被删除一样,所以这里应该先
//将哈希桶中每个单链表的所有节点释放,然后再将htb->tables销毁
void HTBDestory(HTB *htb)
{
    size_t i = 0;
    HashNode *cur;
    for (i = 0; i < htb->_len; i++)
    {
        cur = htb->_tables[i];
        //将链表中所有节点释放
        while (cur)
        {
            HashNode *tmp = cur->_next;
            free(cur);
            cur = tmp;
        }
        htb->_tables[i] = NULL;
    }
    htb->_tables = NULL;
    htb->_len = htb->_size = 0;
}
//申请节点
HashNode *BuyHashNode(HTBKeyType key, HTBValueType value)
{
    HashNode *cur = (HashNode *)malloc(sizeof(HashNode));
    cur->_key = key;
    cur->_value = value;
    cur->_next = NULL;
    return cur;
}
//插入
//这里插入节点时,使用的是头插法,这样可以避免去遍历整个单链表
//注意:这里当检查到需要扩容时,就建一个新的哈希桶,将旧的哈希桶所有的有
//效节点以头插的方法搬迁到新哈希桶中,然后再将新哈希桶的所有信息重新给
//到旧哈希桶中这样就实现了扩容
int HTBInsert(HTB *htb, HTBKeyType key, HTBValueType value)
{
    size_t index;
    HashNode *newNode = NULL;
    assert(htb);
    //检查是否需要扩容
    while (CheckCapacity(htb))
    {
        HTB newhtb;
        HashNode *ptr;
        size_t i = 0;
        HTBInit(&newhtb, htb->_len);
        for (; i < htb->_len; i++)
        {
            ptr = htb->_tables[i];
            //将该关键码所在的单链表所有节点重新插入到新哈希桶中
            while (ptr)
            {
                HashNode *cur = ptr;
                ptr = ptr->_next;
                cur->_next = newhtb._tables[HashFunc(cur->_key, newhtb._len)];
                newhtb._tables[HashFunc(cur->_key, newhtb._len)] = cur;
            }
        }
        free(htb->_tables);
        htb->_tables = newhtb._tables;
        htb->_len = newhtb._len;
    }
    index = HashFunc(key, htb->_len);
    newNode = BuyHashNode(key, value);
    //采用头插法插入节点信息
    newNode->_next = htb->_tables[index];
    htb->_tables[index] = newNode;
    htb->_size++;
    return 1;
}
//删除
//使用一个prv指针记录要删除节点的前置节点
int HTBRemove(HTB *htb, HTBKeyType key)
{
    size_t index;
    HashNode *cur = NULL, *prv = NULL;
    assert(htb);
    index = HashFunc(key, htb->_len);
    cur = htb->_tables[index];
    while (cur)
    {
        //删除的节点为头结点
        if (cur->_key == key && prv == NULL)
        {
            htb->_tables[index] = cur->_next;
            free(cur);
            cur = NULL;
            htb->_size--;
            return 1;
        }
        //删除的节点为非头结点
        if (cur->_key == key)
        {
            prv->_next = cur->_next;
            free(cur);
            cur = NULL;
            return 1;
        }
        prv = cur;
        cur = prv->_next;
    }
    return -1;
}
//查找
HashNode *HTBFind(HTB *htb, HTBKeyType key)
{
    size_t index;
    HashNode *cur = NULL;
    assert(htb);
    index = HashFunc(key, htb->_len);
    cur = htb->_tables[index];
    while (cur)
    {
        if (cur->_key == key)
            return cur;
        cur = cur->_next;
    }
    return NULL;
}
//哈希桶数据的个数
int HTBSize(HTB *htb)
{
    assert(htb);
    return htb->_size;
}
//判断哈希桶是否为空
int HTBEmpty(HTB *htb)
{
    assert(htb);
    return htb->_size > 0 ? 1 : 0;
}
//打印哈希桶
void HashPrint(HTB *htb)
{
    int count = 0;
    HashNode *cur = NULL;
    size_t i;
    assert(htb);
    for (i = 0; i < htb->_len; i++)
    {
        cur = htb->_tables[i];
        count = 0;
        while (cur)
        {

            printf("[%d]->", cur->_key);
            cur = cur->_next;
        }
        printf("NULL\n");
    }
    printf("\n");
}
//测试
void TestHashTableBucket()
{
    size_t i;
    HTB htb;
    HTBInit(&htb, 5);
    srand(time(0));
    for (i = 0; i < 50; i++)
        HTBInsert(&htb, rand(), 0);
    HashPrint(&htb);
    HTBDestory(&htb);
}