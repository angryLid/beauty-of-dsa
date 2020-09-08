#pragma once
#include <stdio.h>
#include <assert.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>

typedef int HTBKeyType;
typedef int HTBValueType;

//每一个关键码对应位置的数据结构
typedef struct HashNode
{
    struct HashNode *_next;
    HTBKeyType _key;
    HTBValueType _value;
} HashNode;
//哈希桶的数据结构
typedef struct HashTableBucket
{
    HashNode **_tables;
    size_t _size;
    size_t _len;
} HTB;
//哈希桶初始化
void HTBInit(HTB *htb, size_t len);
//哈希桶销毁
void HTBDestory(HTB *htb);
//哈希桶插入
int HTBInsert(HTB *htb, HTBKeyType key, HTBValueType value);
//哈希桶删除
int HTBRemove(HTB *htb, HTBKeyType key);
//查找
HashNode *HTBFind(HTB *htb, HTBKeyType key);
//哈希桶大小
int HTBSize(HTB *htb);
//判断桶是否为空
int HTBEmpty(HTB *htb);
//测试
void TestHashTableBucket();
