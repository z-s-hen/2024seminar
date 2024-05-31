#include <stdio.h>
#include <stdbool.h>

#define STACK_SIZE 100  // 스택의 최대 크기를 100으로 정의

// 스택 구조체 정의
typedef struct {
    int data[STACK_SIZE];  // 스택의 데이터를 저장할 배열
    int top;               // 스택의 최상단 요소의 인덱스
} Stack;

// 스택 초기화 함수
void initializeStack(Stack* stack) {
    stack->top = -1;  // 스택이 비어있음을 나타내기 위해 top을 -1로 설정
}

// 스택이 비어있는지 확인하는 함수
bool isEmpty(Stack* stack) {
    return stack->top == -1;  // top이 -1이면 스택이 비어있음
}

// 스택이 가득 찼는지 확인하는 함수
bool isFull(Stack* stack) {
    return stack->top == STACK_SIZE - 1;  // top이 STACK_SIZE - 1이면 스택이 가득 찼음
}

// 스택에 값을 푸시하는 함수
bool push(Stack* stack, int value) {
    if (isFull(stack)) {  // 스택이 가득 찼는지 확인
        printf("Stack overflow\n");  // 스택 오버플로우 메시지 출력
        return false;  // 푸시 실패
    }
    stack->data[++stack->top] = value;  // top을 증가시키고 값을 스택에 저장
    return true;  // 푸시 성공
}

// 스택에서 값을 팝하는 함수
int pop(Stack* stack) {
    if (isEmpty(stack)) {  // 스택이 비어있는지 확인
        printf("Stack underflow\n");  // 스택 언더플로우 메시지 출력
        return -1;  // 스택이 비어있을 때는 -1을 반환
    }
    return stack->data[stack->top--];  // top의 값을 반환하고 top을 감소시킴
}

// 스택의 꼭대기 값을 반환하는 함수
int peek(Stack* stack) {
    if (isEmpty(stack)) {  // 스택이 비어있는지 확인
        printf("Stack is empty\n");  // 스택이 비어있음을 알리는 메시지 출력
        return -1;  // 스택이 비어있을 때는 -1을 반환
    }
    return stack->data[stack->top];  // top의 값을 반환 (top은 변화하지 않음)
}

int main() {
    Stack stack;  // 스택 변수 선언
    initializeStack(&stack);  // 스택 초기화

    // 테스트 코드
    push(&stack, 10);  // 스택에 10 푸시
    push(&stack, 20);  // 스택에 20 푸시
    push(&stack, 30);  // 스택에 30 푸시

    printf("Top element is %d\n", peek(&stack));  // 스택의 꼭대기 값을 출력 (30)
    printf("Popped element is %d\n", pop(&stack));  // 스택에서 값을 팝하고 출력 (30)
    printf("Popped element is %d\n", pop(&stack));  // 스택에서 값을 팝하고 출력 (20)
    printf("Popped element is %d\n", pop(&stack));  // 스택에서 값을 팝하고 출력 (10)
    printf("Popped element is %d\n", pop(&stack));  // 스택 언더플로우 테스트, -1 출력

    return 0;
}