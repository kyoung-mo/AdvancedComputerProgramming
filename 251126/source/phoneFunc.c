/* Name: phoneFunc.c  ver 1.2
 * Content: 전화번호 컨트롤 함수.
 * Implementation: YSW
 *
 * Last modified 2008/01/01
 */

#include "common.h"
#include "phoneData.h"
#include "screenOut.h"

#define LIST_NUM   100

int numOfData = 0;
phoneData *phoneList[LIST_NUM];

/* 함    수: void InputPhoneData(void)
 * 기    능: 전화번호 관련 데이터 입력 받아서 저장.
 * 반    환: void.
 *
 */
void InputPhoneData(void)
{
    phoneData *pdata;

    if (numOfData >= LIST_NUM)
    {
        puts("메모리 공간이 부족합니다.");
        return;
    }

    pdata = (phoneData*)malloc(sizeof(phoneData));

    fputs("이름 입력: ", stdout);
    gets(pdata->name);

    fputs("전화번호 입력: ", stdout);
    gets(pdata->phoneNum);

    phoneList[numOfData] = pdata;
    numOfData++;

    puts("입력이 완료되었습니다.");
    getchar();
}

/* 함    수: void ShowAllData(void)
 * 기    능: 저장된 데이터 전체 출력.
 * 반    환: void.
 *
 */
void ShowAllData(void)
{
    int i;

    for (i = 0; i < numOfData; i++)
    {
        ShowPhoneInfoByPtr(phoneList[i]);
    }

    puts("출력이 완료되었습니다.");
    getchar();
}

/* 함    수: void SearchPhoneData(void)
 * 기    능: 이름을 통한 데이터 검색.
 * 반    환: void.
 *
 */
void SearchPhoneData(void)
{
    int i;
    int cnt = 0;
    char searchName[NAME_LEN];

    fputs("찾는 이름은? ", stdout);
    gets(searchName);

    for (i = 0; i < numOfData; i++)
    {
        if (!strcmp(phoneList[i]->name, searchName))
        {
            ShowPhoneInfoByPtr(phoneList[i]);
            cnt++;
        }

    }
    if (cnt > 0)
        puts("검색이 완료되었습니다.");
    else
        puts("찾는 이름의 데이터가 존재하지 않습니다.");

    getchar();
}

/* 함    수: void DeletePhoneData(void)
 * 기    능: 이름을 참조하여 데이터 삭제.
 * 반    환: void.
 *
 */
void DeletePhoneData(void)
{
    int i, j;
    int cnt = 0;
    char delName[NAME_LEN];

    fputs("찾는 이름은? ", stdout);
    gets(delName);

    for (i = 0; i < numOfData; i++)
    {
        if (!strcmp(phoneList[i]->name, delName)) // strcmp > 같으면 0 다르면 1 반환, !strcmp면 같으면 1 다르면 0 반환
        {
            free(phoneList[i]);
            for (j = i; j < numOfData - 1; j++)
            {
                phoneList[j] = phoneList[j + 1];
            }

            numOfData--;
            cnt++;
        }
    }

    if(cnt>0)
        puts("삭제가 완료되었습니다.");
    else
        puts("찾는 이름의 데이터가 존재하지 않습니다.");
    getchar();
}


/* end of file */
