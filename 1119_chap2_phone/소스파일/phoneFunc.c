/* Name: phoneFunc.c  ver 1.0
 * Content: 전화번호 컨트롤 함수.
 * Implementation: YSW
 *
 * Last modified 2008/01/01
 */

#define _CRT_SECURE_NO_WARNINGS
#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM   100

int numOfData = 0;
phoneData phoneList[LIST_NUM];

/* 함    수: void InputPhoneData(void)
 * 기    능: 전화번호 관련 데이터 입력 받아서 저장.
 * 반    환: void.
 *
 */
void InputPhoneData(void)
{
	phoneData data;

	if (numOfData >= LIST_NUM)
	{
		printf("\n메모리 공간이 부족합니다.");
		return;
	}

	printf("━━━━━━━━━━━━━━━━ \n");
	printf("이름 》 ");
	gets(data.name);

	printf("번호 》 ");
	gets(data.phoneNum);

	numOfData ++;
	printf("입력이 완료되었습니다. \n");

}

/* 함    수: void ShowAllData(void)
 * 기    능: 저장된 데이터 전체 출력.
 * 반    환: void.
 *
 */
void ShowAllData(void)

{
	printf("━━━━━━━━━━━━━━━━ \n");
	phoneData phone;

	if (numOfData >= LIST_NUM)
	{
		printf("\n메모리 공간이 부족합니다.");
		return;
	}

	for (int i = 0; i < numOfData; i++)
		ShowPhoneInfo;


	printf("출력이 완료되었습니다. \n");
	

}

/* 함    수: void SearchPhoneData(void)
 * 기    능: 저장된 데이터 검색.
 * 반    환: void.
 *
 */
void SearchPhoneData(void)

{
	printf("━━━━━━━━━━━━━━━━ \n");
	phoneData phone;

	if (numOfData >= LIST_NUM)
	{
		printf("\n메모리 공간이 부족합니다.");
		return;
	}

	for (int i = 0; i < numOfData; i++)
		ShowPhoneInfo;


	printf("검색이 완료되었습니다. \n");


}

/* 함    수: void DeletePhoneData(void)
 * 기    능: 저장된 데이터 삭제.
 * 반    환: void.
 *
 */
void DeletePhoneData(void)

{
	printf("━━━━━━━━━━━━━━━━ \n");
	phoneData phone;

	if (numOfData >= LIST_NUM)
	{
		printf("\n메모리 공간이 부족합니다.");
		return;
	}

	for (int i = 0; i < numOfData; i++)
		ShowPhoneInfo;


	printf("삭제가 완료되었습니다. \n");


}

/* end of file */
