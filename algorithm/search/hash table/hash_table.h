#pragma once
#include <iostream>


//开放定址法

/*
线性探测法
*/
void linear_probing(int arr[], int len);


/*
平方探测法
*/
void quadratic_probing(int arr[], int len);


/*
再散列法
*/
void double_hashing(int arr[], int len);


/*
打印开放定址法的hash_table
*/
void print_hash_table(int hash_table[], int hash_len);



//拉链法
void separate_chain(int arr[], int len);
