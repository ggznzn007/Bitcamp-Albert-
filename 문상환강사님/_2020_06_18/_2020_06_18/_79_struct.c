/*
 배열 : 동일한 성격의 변수가 여러 개 필요
     ex) 3명 학생의 국어점수
 구조체 : 하나의 사물/업무에 필요한 정보가 여러 개
     ex) 학생의 신상정보
        이름, 나이, 주소, 키, 몸무게
       - 미리 학생 자료형을 제공할 수 없으니까
        필요할 때 학생관련정보를 묶어서
        학생 자료형을 만들어 사용해라.
       - 학생 자료형으로 만든 변수는
        학생에 관련된 정보를 저장할 수 있다.
*/
/* 프로그래밍의 그룹
1) 로직을 그루핑하고 싶으면 => 함수
2) 변수들을 그루핑하고 싶으면 => 구조체
*/
#include <stdio.h>
#include <string.h>

struct Student
{
    // 구조체의 멤버변수들
    char name[20];
    int age;
    char address[30];
    float height;
    float weight;
};

/* 구조체는 리소스가 크기 때문에
인자 전달시에도 복사하기 보다는
포인터로 가리키게 하는 경우가  많다.

아래처럼 포인터를 사용하게 되면
62byte가 복사되는 것이 아니라
포인터 크기인 4byte 주소만 복사된다.
*/
void showStudent(struct Student* pSt)
{
    printf("이름 : %s\n", pSt->name);
    printf("나이 : %d\n", pSt->age);
    printf("주소 : %s\n", pSt->address);
    printf("키 : %.2f\n", pSt->height);
    printf("몸무게 : %.2f\n", pSt->weight);
}

void main()
{
    struct Student st;

    strcpy_s(st.name, sizeof(st.name), "홍길동");
    st.age = 24;
    strcpy_s(st.address, sizeof(st.address), "지리산");
    st.height = 175.6f;
    st.weight = 78.3f;

    showStudent(&st);
}