#include <stdio.h>
#include <string.h>

#define TRUE 1
#define FALSE 0

// Answer begin
int lengthOfLongestSubstring(char* s) {
    int word_flags[256];
    char* head = s+1;
    char* tail = s;
    int current_len = 1;
    int answer = 1;

    if (*s == 0)
    	return 0;

    memset(word_flags, 0, sizeof(int)*256);
    word_flags[*s] = TRUE;
    
    while (*head != 0)
    {
    	// printf("head = %s\n", head);
    	// printf("tail = %s\n", tail);
    	// printf("current_len = %d\n", current_len);
    	// printf("answer = %d\n", answer);
    	if (word_flags[*head] == 0)
    	{
    		word_flags[*head] = 1;
    		current_len++;
    	}
    	else
    	{
    		// Update answer
    		if(current_len > answer)
    		{
    			answer = current_len;
    		}
    		// update tail
    		while (*tail != *head)
    		{
    			// printf("*head = %c\n", *head);
    			// printf("*tail = %c\n", *tail);
    			word_flags[*tail] = 0;
    			current_len--;
    			tail = tail + 1;
    		}
    		tail = tail + 1; 
    	}
    	head = head + 1;
    }
    if (current_len > answer)
    {
    	answer = current_len;
    }
    return answer;
}
// Answer end

int main()
{
	char* s = "au";
	int answer = lengthOfLongestSubstring(s);
	printf("answer = %d\n", answer);
	return 0;
}