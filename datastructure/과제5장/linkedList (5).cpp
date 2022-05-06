
#define _CRT_SECURE_NO_WARNINGS
#define MAXWORD 80

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


typedef struct element {
	char word[MAXWORD];
	int count;
} element;
typedef struct ListNode {
	element data;
	struct ListNode* link;
} ListNode;

// �ʱ�ȭ �Լ�
ListNode* init(ListNode* head)
{
	head = (ListNode*)malloc(sizeof(ListNode));
	if (head == NULL) exit(1);
	head->link = NULL;
	return head;
}
//��� ��带 �̿��� ���� �Լ�
void insert_node(ListNode* head, char* key) {
	int cmp;
	ListNode* prev, * ptr;
	//�Ʒ��� �ϼ��Ͻÿ�
	/*prev = (ListNode*)malloc(sizeof(ListNode));
	ptr = (ListNode*)malloc(sizeof(ListNode));*/
	prev = head;
	ptr = head->link;
	
	ListNode* new_node = new ListNode;
	strcpy(new_node->data.word, key);
	new_node->data.count = 1;
	new_node->link = NULL;
	while (ptr != NULL) {
		cmp = strcmp(ptr->data.word, key);
		if (cmp < 0) {
			
			prev = ptr;
			ptr = ptr->link;
			
	
		}
		else if (cmp == 0) {
			ptr->data.count++;
			return;
			
		}
		else{
	
			new_node->link = ptr->link;
			ptr->link = new_node;
			return;
			
		}
	}
	if (ptr == NULL) {
		prev->link = new_node;
	}

}
//��� ��带 �̿��� ���� �Լ�
void delete_node(ListNode* head, char* key)
{
	int cmp;
	ListNode* prev, * ptr, * removed;

	prev = head;
	ptr = head->link;
	while (ptr != NULL) {
		cmp = strcmp(ptr->data.word, key);
		if (cmp < 0) {
			prev = ptr;
			ptr = ptr->link;
		}
		else if (cmp == 0) {
			removed = ptr;
			prev->link = ptr->link;
			//free(removed);
			delete removed;
			return;
		}
		else
			return;
	}
}
void sort_print(ListNode* head) {
	ListNode* ptr = head->link;

	printf("�ܾ� \tȸ��\n");
	while (ptr) {
		printf("%s \t%d\n", ptr->data.word, ptr->data.count);
		ptr = ptr->link;
	}
}
int main()
{
	FILE* fp;
	char word[MAXWORD];
	ListNode* head = NULL;

	head = init(head);

	//fopen_s(&fp, "data.txt", "r");
	fp = fopen("data.txt", "r");
	//while (fscanf_s(fp, "%s", word, sizeof(word)) != EOF) {
	while (fscanf(fp, "%s", word) != EOF) {
		printf("%s ", word);
		insert_node(head, word);
	}
	printf("\n");
	fclose(fp);

	sort_print(head);

	printf("������ �ܾ�(����:0): ");
	scanf_s("%s", word, sizeof(word));
	while (word[0] != '0') {
		delete_node(head, word);
		sort_print(head);
		printf("������ �ܾ�: ");
		//scanf_s("%s", word, sizeof(word));
		scanf("%s", word);
	}

	return 0;
}
/* ���� ��� ���
* ���� ����� ����ϴ� ���� ����� ���� ���� �ƴմϴ� �ٸ� ������� ���� ȫ�ȸ��� ����������� ����� ���� ��ߵ� ����ϴ� ����Դϴ�
�ܾ�    ȸ��
����    1
����Դϴ�      1
����    1
����    1
����    1
�����  1
����    1
�����  1
�����  1
�ٸ�    1
����ϴ�        2
��ߵ�  1
�������        1
����    1
�����������    1
�ƴմϴ�        1
ȫ�ȸ���        1
������ �ܾ�(����:0): ����
�ܾ�    ȸ��
����    1
����Դϴ�      1
����    1
����    1
����    1
�����  1
����    1
�����  1
�����  1
�ٸ�    1
����ϴ�        2
��ߵ�  1
�������        1
�����������    1
�ƴմϴ�        1
ȫ�ȸ���        1
������ �ܾ�: 0

C:\Users\morat\source\repos\hongPractice\Debug\hongPractice.exe (process 127292) exited with code 0.
Press any key to close this window . . .


*/
/* ���� ��� ���
���� ����� ����ϴ� ���� ����� ���� ���� �ƴմϴ� �ٸ� ������� ���� ȫ�ȸ���
����������� ����� ���� ��ߵ� ����ϴ� ����Դϴ�
�ܾ�    ȸ��
����    1
����    1
�����  1
����Դϴ�      1
����    2
����    1
�ٸ�    1
�����  1
�����  1
��ߵ�  1
�������        1
����ϴ�        2
�����������    1
�ƴմϴ�        1
����    1
ȫ�ȸ���        1
������ �ܾ�(����:0): ����
�ܾ�    ȸ��
����    1
����    1
�����  1
����Դϴ�      1
����    2
����    1
�ٸ�    1
�����  1
�����  1
��ߵ�  1
�������        1
����ϴ�        2
�����������    1
�ƴմϴ�        1
ȫ�ȸ���        1
������ �ܾ�: 0
����Ϸ��� �ƹ� Ű�� �����ʽÿ� . . .
*/