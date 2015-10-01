#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

#define HASH_SIZE 35023
#define HASH_FUNC(x) (abs(x) % HASH_SIZE)
#define TRUE 1
#define FALSE 0

int check_num_in_idx_hash(int num, int* nums, int* nums_idx_hash)
{
    // printf("check_num_in_idx_hash: %d\n", num);
    int num_hash = HASH_FUNC(num);
    int loop_check = FALSE;
    while (nums_idx_hash[num_hash] != 0)
    {
        if (nums[nums_idx_hash[num_hash] - 1] == num)
            return nums_idx_hash[num_hash];
        num_hash++;
        if (num_hash >= HASH_SIZE)
        {
            if (loop_check == TRUE)
            {
                return -1;
            }
            loop_check = TRUE;
            num_hash = 0;
        }
    }
    // printf("end\n");
    return -1;
}

int insert_num_to_idx_hash(int num, int num_idx, int* nums_idx_hash)
{
    // printf("insert_num_to_idx_hash: %d\n", num);
    int num_hash = HASH_FUNC(num);
    int loop_check = FALSE;
    while (nums_idx_hash[num_hash] != 0)
    {
        num_hash++;
        if (num_hash >= HASH_SIZE)
        {
            if (loop_check == TRUE)
            {
                return FALSE;
            }
            loop_check = TRUE;
            num_hash = 0;
        }
    }
    nums_idx_hash[num_hash] = num_idx;
    // printf("end\n");
    return TRUE;
}

/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* twoSum(int* nums, int numsSize, int target)
{
    int* nums_idx = malloc(sizeof(int) * 2);
    int* nums_idx_hash = malloc(sizeof(int) * HASH_SIZE);
    memset(nums_idx_hash, 0, sizeof(int) * HASH_SIZE);
    int i;
    int num, num_hash;
    int pair_num_idx;
    int insert_flag;
    for (int i = 0; i < numsSize; i++)
    {
        num = nums[i];
        if ((pair_num_idx = check_num_in_idx_hash(target - num, nums, nums_idx_hash)) != -1)
        {
            nums_idx_hash[0] = pair_num_idx;
            nums_idx_hash[1] = i + 1;
            return nums_idx_hash;
        }
        insert_flag = insert_num_to_idx_hash(num, i + 1, nums_idx_hash);
        if (insert_flag == FALSE)
           return NULL; 
    }
    return NULL;
}

int main()
{
    int* nums = malloc(sizeof(int) * 5);
    nums[0] = -1;
    nums[1] = -2;
    nums[2] = -3;
    nums[3] = -4;
    nums[3] = -5;
    int target = -8;
    int* answer = twoSum(nums, 4, target);
    printf("index1=%d, index2=%d\n", answer[0], answer[1]);
    return 0;
}
