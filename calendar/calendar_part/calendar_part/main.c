#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <time.h>

// �ش� ���� �ϼ��� ����ϴ� �Լ�
int getNumberOfDays(int month, int year) {
    if (month == 2) {
        if ((year % 400 == 0) || (year % 4 == 0 && year % 100 != 0))
            return 29;
        else
            return 28;
    }
    else if (month == 1 || month == 3 || month == 5 || month == 7 || month == 8 || month == 10 || month == 12)
        return 31;
    else
        return 30;
}

// �޷��� �׸��� �Լ�
void printCalendar(const char* weekDays[], int firstWeekDayOfMonth, int numberOfDays) {
    int w, d;
    for (w = 0; w < 7; w++) {
        printf("%s    ", weekDays[w]);
    }
    printf("\n-------------------------------------------------\n\n");

    int tempBreak = 1;
    for (w = 0; w < firstWeekDayOfMonth; w++) {
        printf("       ");
        tempBreak++;
    }
    for (d = 1; d <= numberOfDays; d++) {
        printf("%2d     ", d);
        if (tempBreak >= 7) {
            printf("\n");
            tempBreak = 0;
        }
        tempBreak++;
    }
    printf("\n");
}

// �����δ��� �ۼ��ϴ� �Լ�
void writeReminder() {

}

// �����δ��� �����ϰ� �ҷ����� �Լ�
void saveReminder() {

}

int main() {
    const char* months[12] = { "January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December" };
    const char* weekDays[7] = { "Sun","Mon","Tue","Wed","Thu","Fri","Sat" };

    time_t currentTime = time(0);   // ���� �ð� ��������
    struct tm now;
    _localtime64_s(&now, &currentTime);

    int currentDay = now.tm_mday;
    int currentMonth = now.tm_mon + 1; // tm_mon�� 0���� �����ϹǷ� 1�� ������
    int currentYear = now.tm_year + 1900; // tm_year�� 1900������� �⵵ ����
    int numberOfDays = getNumberOfDays(currentMonth, currentYear);

    // �ش� ���� ù ��° ��¥�� ���� ���
    struct tm tFirst = { 0, 0, 0, 1, now.tm_mon, now.tm_year };
    time_t time_temp = mktime(&tFirst);
    struct tm firstTime;
    _localtime64_s(&firstTime, &time_temp);

    int firstWeekDayOfMonth = firstTime.tm_wday;

    printf("Current Date: %d-%s-%02d\n\n",  currentYear,months[currentMonth - 1], currentDay);
    printf("%s\n\n", months[currentMonth - 1]);

    printCalendar(weekDays, firstWeekDayOfMonth, numberOfDays);

    return 0;
}
