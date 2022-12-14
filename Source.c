#include <stdio.h>
#include <windows.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>

#define rows 3

void init()
{
	system("title Typing practice");
}
void launch()
{
	printf("c프로그래밍 기말프로젝트\n");
	printf("22114187이도형\n");
	printf("영문타자연습프로그램");
	Sleep(1000);
	system("cls");
}
int main(void)
{
	init();
	launch();
	while (1) {
		char c[1000], str[1000] = { '\0' };
		char strl[rows][1000] = { "Once upon a time a Wolf was lapping at a spring on a hillside, when, look","ing up, what should he see but a Lamb just beginning to drink a little","lower down." };
		int menu, wrongcount = 0, i, j, k, length, ran;
		float time;
		while (1) {
			FILE* fs = NULL;
			printf("Select menu\n1.Short sentence, 2.Long sentence, 3.Exit\n>");
			scanf_s("%d", &menu);

			if (menu == 1) {//shortsentence random fopen
				while (1) {
					ran = rand() % 6;
					if (ran > 0)
					{
						break;
					}
				}
				switch (ran) {
				case 1:
					fopen_s(&fs, "short_sentence1.txt", "r");
					break;
				case 2:
					fopen_s(&fs, "short_sentence2.txt", "r");
					break;
				case 3:
					fopen_s(&fs, "short_sentence3.txt", "r");
					break;
				case 4:
					fopen_s(&fs, "short_sentence4.txt", "r");
					break;
				case 5:
					fopen_s(&fs, "short_sentence5.txt", "r");
					break;
				}
				fgets(str, sizeof(str), fs);
				if (fs == NULL) {
					printf("File Error!\n");
					exit(-1);
				}
				fclose(fs);
				break;
			}
			else if (menu == 2) { //longsentence
				break;
			}
			else if (menu == 3) {
				break;
				return 0;
			}
			else {
				system("cls");
				continue;
			}
		}

		system("cls");
		if (menu == 3) {
			printf("Bye.");
			break;
		}

		if (menu == 1) { // shortsentence
			wrongcount = 0;
			time = clock();
			length = strlen(str);
			printf("Short sentence practice\n");

			printf("------------------------------------------------------------------------------------------------------------------------\n");
			printf(" %s\n>", str);
			for (i = 0; i <= length; i++) {
				c[i] = _getch();
				printf("%c", c[i]);
				if (i > 0 && c[i] == 8) { // backspace
					c[i - 1] = ' ';
					printf("%c\b", c[i - 1]);
					i -= 2;
				}
				else if (c[i] != '\r' && i == length) { // at final alphabet
					str[length + 1] = NULL;
					printf("\b%c", str[length + 1]);
					printf("\n");
				}
				else if (c[i] == '\r' && i == length) { // if press enter on sentence of middle
					printf("\n");
					break;
				}
				else if (c[i] == '\r') {
					for (j = 0; j < i; j++) {
						printf("%c", c[j]);
					}
					i--;
				}
			}
			for (i = 0; i < length; i++) {
				if (c[i] != str[i]) {
					wrongcount++;
				}
			}
			time = clock() - time;
			time /= 1000;
			printf("\nTyping error : %d\n", wrongcount);
			printf("Accuracy : %.f%%\n", 100 - ((float)wrongcount / ((float)length + 1) * 100));
			printf("Character per minute : %.f\n\n", (60 / time) * 30);
			printf("Press any key to continue\n");
			_getch();
			system("cls");
		}
		else if (menu == 2) { // longsentence
			system("cls");
			printf("Long sentence practice\n");
			printf("------------------------------------------------------------------------------------------------------------------------\n");
			wrongcount = 0;
			time = clock();
			if (menu == 2) {
				for (i = 0; i < rows; i++) {
					length = strlen(strl[i]);
					printf("%s\n", strl[i]);
					for (j = 0; j < length + 1; j++) {
						c[j] = _getch();
						printf("%c", c[j]);
						if (j > 0 && c[j] == 8) { // backspace
							c[j - 1] = ' ';
							printf("%c\b", c[j - 1]);
							j -= 2;
						}
						else if (c[j] != 'r' && j == length) { //at final alphabet
							strl[i][length + 1] = NULL;
							printf("\b%c", strl[i][length + 1]);
							printf("\n\n");
						}
						else if (c[j] == '\r' && j == length) { //if press enter on sentence of middle
							printf("\n\n");
							break;
						}
						else if (c[j] == '\r') {
							for (k = 0; k < j; k++) {
								printf("%c", c[k]);
							}
							j--;
						}
					}
					for (j = 0; j < length; j++) {
						if (c[j] != strl[i][j]) {
							wrongcount++;
						}
					}
				}
				time = clock() - time;
				time /= 1000;
				printf("\nTyping error : %d\n", wrongcount);
				printf("Accuracy : %.f%%\n", 100 - ((float)wrongcount / ((float)length + 1) * 100));
				printf("Character per minute : %.f\n\n", (60 / time) * 30);
				_getch();
				system("cls");
			}
		}
	}
}