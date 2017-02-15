#include <stdio.h>
#include <stdlib.h>

/*
 * Input:(2->4->3) + (5->6->4)
 * output: 7->0->8
 * */


struct ListNode {
	int val;
	struct ListNode *next; 
};
struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	if(NULL == l1 || NULL == l2)
	{
		return NULL;
	}

	struct ListNode *add1 = l1, *add2 = l2;
	struct ListNode *ResultList = NULL;
	struct ListNode *tmp = NULL;
	struct ListNode *tmp1 = NULL;

	int sum = 0;
	int last_flow = 0;
	while(add1 && add2)
	{
		tmp = malloc(sizeof(struct ListNode));
		if(NULL == tmp)
		{
			struct ListNode *next = NULL;
			tmp = ResultList;
			while(tmp)
			{
				next = tmp->next;
				free(tmp);
				tmp = next;
			}
			return NULL;
		}
		sum = (add1->val + add2->val);

		tmp->val = (sum + last_flow) % 10;
		tmp->next = NULL;
		//next overflow
		last_flow = (sum + last_flow) / 10;

		tmp1 = ResultList;
		do
		{
			if(NULL == tmp1)
			{
				ResultList = tmp;
				//printf("tmp->val = %d\n", tmp->val);
				break;
			}

			if(NULL == tmp1->next)
			{
				tmp1->next = tmp;
				printf("tmp->val = %d\n", tmp->val);
				break;
			}
			tmp1 = tmp1->next;
		}while(tmp1);

		add1 = add1->next;
		add2 = add2->next;
	}

	if(last_flow != 0)
	{
		tmp = malloc(sizeof(struct ListNode));
		if(NULL == tmp)
		{
			struct ListNode *next = NULL;
			tmp = ResultList;
			while(tmp)
			{
				next = tmp->next;
				free(tmp);
				tmp = next;
			}
			return NULL;
		}
		tmp->val = last_flow;
		tmp->next = NULL;
		tmp1 = ResultList;
		while(tmp1)
		{
			if(NULL == tmp1->next)
			{
				tmp1->next = tmp;
				break;
			}
			printf("test\n");
			tmp1 = tmp1->next;
		}
	}

	return ResultList;
}

int main(int argc, char *argv[])
{
	int i;

	int arr1[4] = {9,21,19,15};
	int arr2[4] = {9,9,9,9};

	struct ListNode *a1 = malloc(sizeof(struct ListNode));
	struct ListNode *a2 = malloc(sizeof(struct ListNode));
	struct ListNode *tmp = NULL;

	struct ListNode *tmp1 = NULL;

	a1->val = 1;
	a1->next = NULL;
	a2->val = 9;
	a2->next = NULL;

	tmp1 = a1;
	for(i = 0; i < 4; ++i)
	{
		tmp = malloc(sizeof(struct ListNode));
		tmp->val = arr1[i];
		tmp->next = NULL;
		while(tmp1)
		{
			if(NULL == tmp1->next)
			{
				tmp1->next = tmp;
				break;
			}
		    	tmp1 = tmp1->next;
		}
	}
	tmp1 = a2;
	for(i = 0; i < 4; ++i)
	{
		tmp = malloc(sizeof(struct ListNode));
		tmp->val = arr2[i];
		tmp->next = NULL;
		while(tmp1)
		{
			if(NULL == tmp1->next)
			{
				tmp1->next = tmp;
				break;
			}

		    	tmp1 = tmp1->next;
		}
	}

	tmp = addTwoNumbers(a1, a2);


	while(tmp)
	{
		tmp1 = tmp->next;
		printf("%d ", tmp->val);
		free(tmp);
		tmp = tmp1;
	}
	printf("\n");

	tmp = a1;
	while(tmp)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}
	tmp = a2;
	while(tmp)
	{
		tmp1 = tmp->next;
		free(tmp);
		tmp = tmp1;
	}

	return 0;
}
