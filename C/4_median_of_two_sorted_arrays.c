#include <stdio.h>
#define DEBUG

// Answer start
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size)
{
	int count;
    int median_index = (int) (nums1Size + nums2Size + 1) / 2;
    int nums1_index = 0;
    int nums2_index = 0;
    if (nums1Size == 0)
    {
    	if (nums2Size % 2 == 1)
    		return nums2[(int) nums2Size / 2];
    	else
    		return (nums2[(int) (nums2Size - 1) / 2] + nums2[(int) nums2Size / 2]) / 2.0;
    }
    if (nums2Size == 0)
    {
    	if (nums1Size % 2 == 1)
    		return nums1[(int) nums1Size / 2];
    	else
    		return (nums1[(int) (nums1Size - 1) / 2] + nums1[(int) nums1Size / 2]) / 2.0;
    }
    for (count = 1; count < median_index; count++)
    {
#ifdef DEBUG
	    printf("nums1_index = %d\n", nums1_index);
	    printf("nums2_index = %d\n", nums2_index);
#endif
    	if (nums2_index >= nums2Size || (nums1_index < nums1Size && nums1[nums1_index] < nums2[nums2_index]))
    		nums1_index++;
    	else
    		nums2_index++;
    }
#ifdef DEBUG
    printf("nums1_index = %d\n", nums1_index);
    printf("nums2_index = %d\n", nums2_index);
#endif
    if ((nums1Size + nums2Size) % 2 == 1)
    {
    	if (nums2_index >= nums2Size || (nums1_index < nums1Size && nums1[nums1_index] < nums2[nums2_index]))
    		return nums1[nums1_index];
    	else
    		return nums2[nums2_index];
    }
    else
    {
    	if (nums2_index >= nums2Size || (nums1_index < nums1Size && nums1[nums1_index] < nums2[nums2_index]))
    	{
    		if (nums2_index >= nums2Size || (nums1_index < nums1Size - 1 && nums1[nums1_index + 1] < nums2[nums2_index]))
    		{
    			return ((nums1[nums1_index] + nums1[nums1_index + 1]) / 2.0);
    		}
    		else
    		{
    			return ((nums1[nums1_index] + nums2[nums2_index]) / 2.0);
    		}
    	}
    	else
    	{
    		if (nums1_index >= nums1Size || (nums2_index < nums2Size - 1 && nums2[nums2_index + 1] < nums1[nums1_index]))
    		{
    			return ((nums2[nums2_index] + nums2[nums2_index + 1]) / 2.0);
    		}
    		else
    		{
    			return ((nums2[nums2_index] + nums1[nums1_index]) / 2.0);
    		}
    	}
    }
}
// Answer end

int main()
{
	// int nums1[] = {1, 2, 3, 4};
	// int nums1Size = 4;
	// int nums2[] = {5, 6, 7, 8};
	// int nums2Size = 4;
	// printf("findMedianSortedArrays =  %.2lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums1Size));

	// int nums1[] = {5, 6, 7, 8};
	// int nums1Size = 4;
	// int nums2[] = {1, 2, 3, 4};
	// int nums2Size = 4;
	// printf("findMedianSortedArrays =  %.2lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

	// int nums1[] = {1, 2, 3};
	// int nums1Size = 3;
	// int nums2[] = {};
	// int nums2Size = 0;
	// printf("findMedianSortedArrays =  %.2lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

	// int nums1[] = {};
	// int nums1Size = 0;
	// int nums2[] = {1, 2, 3};
	// int nums2Size = 3;
	// printf("findMedianSortedArrays =  %.2lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

	// int nums1[] = {1, 2, 9};
	// int nums1Size = 3;
	// int nums2[] = {3, 4};
	// int nums2Size = 2;
	// printf("findMedianSortedArrays =  %.2lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

	// int nums1[] = {1};
	// int nums1Size = 1;
	// int nums2[] = {2, 3};
	// int nums2Size = 2;
	// printf("findMedianSortedArrays =  %.2lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));

	int nums1[] = {2, 3, 4};
	int nums1Size = 3;
	int nums2[] = {1};
	int nums2Size = 1;
	printf("findMedianSortedArrays =  %.2lf\n", findMedianSortedArrays(nums1, nums1Size, nums2, nums2Size));
	return 0;
}