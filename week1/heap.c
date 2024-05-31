#include <stdio.h>

#define HEAP_SIZE 100  // 힙의 최대 크기

// 힙 구조체 정의
typedef struct {
    int data[HEAP_SIZE];  // 힙 데이터를 저장할 배열
    int size;             // 현재 힙에 있는 요소의 수
} Heap;

// 힙 초기화 함수
void initializeHeap(Heap* heap) {
    heap->size = 0;  // 힙의 크기를 0으로 초기화
}

// 힙에 요소를 삽입하는 함수
void insertHeap(Heap* heap, int value) {
    if (heap->size == HEAP_SIZE) {  // 힙이 가득 찼는지 확인
        printf("Heap overflow\n");
        return;
    }

    // 새 요소를 힙의 끝에 추가
    int i = heap->size++;
    heap->data[i] = value;

    // 힙 속성을 유지하기 위해 요소를 위로 이동
    while (i != 0 && heap->data[(i - 1) / 2] < heap->data[i]) {
        int temp = heap->data[i];
        heap->data[i] = heap->data[(i - 1) / 2];
        heap->data[(i - 1) / 2] = temp;
        i = (i - 1) / 2;
    }
}

// 힙에서 최대 값을 삭제하고 반환하는 함수
int deleteMax(Heap* heap) {
    if (heap->size <= 0) {  // 힙이 비어있는지 확인
        printf("Heap underflow\n");
        return -1;
    }

    // 최대 값을 힙의 루트에서 가져오기
    int root = heap->data[0];

    // 마지막 요소를 루트로 이동
    heap->data[0] = heap->data[--heap->size];

    // 힙 속성을 유지하기 위해 요소를 아래로 이동
    int i = 0;
    while (i * 2 + 1 < heap->size) {
        int leftChild = i * 2 + 1;
        int rightChild = i * 2 + 2;
        int largerChild = leftChild;

        if (rightChild < heap->size && heap->data[rightChild] > heap->data[leftChild]) {
            largerChild = rightChild;
        }

        if (heap->data[i] >= heap->data[largerChild]) {
            break;
        }

        int temp = heap->data[i];
        heap->data[i] = heap->data[largerChild];
        heap->data[largerChild] = temp;

        i = largerChild;
    }

    return root;
}

int main() {
    Heap heap;  // 힙 변수 선언
    initializeHeap(&heap);  // 힙 초기화

    // 테스트 코드
    insertHeap(&heap, 10);
    insertHeap(&heap, 20);
    insertHeap(&heap, 30);

    printf("Max element is %d\n", deleteMax(&heap));  // 최대 값을 삭제하고 출력 (30)
    printf("Max element is %d\n", deleteMax(&heap));  // 최대 값을 삭제하고 출력 (20)
    printf("Max element is %d\n", deleteMax(&heap));  // 최대 값을 삭제하고 출력 (10)
    printf("Max element is %d\n", deleteMax(&heap));  // 힙 언더플로우 테스트, -1 출력

    return 0;
}