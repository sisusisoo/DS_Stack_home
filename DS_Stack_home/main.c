#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define MAX_STACK_SIZE 10

typedef int element;




typedef struct {
	element data[MAX_STACK_SIZE];
	int top;
}StackType;

void init_stack(StackType *s){

	s->top = -1;

}
int is_empty(StackType* s) {
	return(s->top == -1);
}

int is_full(StackType* s) {
	return(s->top == (MAX_STACK_SIZE - 1));

}

int push(element item, StackType* s) {
	if (is_full(s)) {
		fprintf(stderr, "���� ��ȭ ����\n");
		return 0;//���� ��ȭ ���� �߻��� �ٷ� ���κ��� ���븸 ��µɼ� �ְ� �߽��ϴ�. 

	}
	else {
		s->data[++(s->top)] = item;
		return 1;
	}


}

element pop(StackType * s) {
	if (is_empty(s)) {
		fprintf(stderr, "���� ���� ����\n");
		return 0;//���� ���� ���� �߻��� �ٷ� ���κ��� ���븸 ��µɼ� �ְ� �߽��ϴ�. 
	}
	else return s->data[(s->top)--];
}




int main() {

	StackType s;
	init_stack(&s);

	srand(time(NULL));
	for (int i = 0; i < 30; i++) {


		int temp_ran = rand() % 100 + 1;

		if (temp_ran % 2 == 1) {
			int p = pop(&s);
			if (p == 0) {
				printf("\n");
			}
			else {
				printf("[ %d ]", i + 1);
				printf("pop %d\n", p);
			}
		}
		else {

			int p = push(temp_ran,&s);
			if (p == 0) {
				printf("\n");

			}
			else {
				printf("[ %d ]", i + 1);
				printf("push %d\n", temp_ran);
			}

		}

	}

}