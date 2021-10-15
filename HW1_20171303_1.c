#include <stdio.h>

int Pair(char a, char b);
int WellFormed(char *str);
char matchingparenthesis(char a);
void MakeWellForm(char* str);

char wellformstr[50];
char stack[50];
char stack2[50];
int sp = 0;
int sp2 = 0;


void main() {
	char str[50];

	printf("Enter a String : ");

	fgets(str, sizeof(str), stdin); // 문자열 입력

	if (WellFormed(str)==0) {
		printf("well formed string\n");
	}
	else {
		printf("not well formed string\n");
		MakeWellForm(str);
	}
}

int Pair(char a, char b) {
	if (a == '(' && b == ')') {
		return 1;
	}
	else if (a == '{' && b == '}') {
		return 1;
	}
	else if (a == '[' && b == ']') {
		return 1;
	}
	else return 0;
}

int WellFormed(char *str) {
	int i;
	
	for (i = 0; i < 50; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			stack[sp] = str[i];
			sp++;		//push
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (sp == 0) {
				return 1;
			}
			else {
				if (Pair(stack[sp-1], str[i])==1) {
					sp--;
					stack[sp] = '\0'; // pop
				}
				else return 1;
			}
		}
		else if (str[i] == '\0') {
			break;   // 문자열 끝나면 자동으로 for문 종료
		}
		else continue;
	}

	if (sp != 0) {
		return 1;
	}
	else {
		return 0;
	}

}

void MakeWellForm(char* str) {
	int i;
	int j = 0;
	int addparen=0;

	for (i = 0; i < 50; i++) {
		if (str[i] == '(' || str[i] == '{' || str[i] == '[') {
			wellformstr[j] = str[i];
			stack2[sp2] = str[i];
			j++;
			sp2++;
		}
		else if (str[i] == ')' || str[i] == '}' || str[i] == ']') {
			if (sp2==0) {
				wellformstr[j] = matchingparenthesis(str[i]);
				addparen++;
				wellformstr[j + 1] = str[i];
				j+=2;
			}
			else {
				if (Pair(stack2[sp2-1], str[i]) == 1) {
					sp2--;
					stack2[sp2] = '\0';
					wellformstr[j] = str[i];
					j++;
				}
				else {
					wellformstr[j] = matchingparenthesis(str[i]);
					addparen++;
					wellformstr[j + 1] = str[i];
					j += 2;
				}
			}
		}
		else if (str[i] == '\0') {
			j--;
			break;  
		}
		else {
			wellformstr[j] = str[i];
			j++;
		}
	}
	for (i = sp2-1; i >= 0; i--) {
		wellformstr[j] = matchingparenthesis(stack2[i]);
		addparen++;
		j++;
	}
	printf("추가되는 괄호 수 : %d\n", addparen);
	printf("%s", wellformstr);
}

char matchingparenthesis(char a) {
	if (a == ')') {
		return '(';
	}
	else if (a == '}') {
		return '{';
	}
	else if (a == ']') {
		return '[';
	}
	else if (a == '(') {
		return ')';
	}
	else if (a == '{') {
		return '}';
	}
	else if (a == '[') {
		return ']';
	}
	else return 0;
}
