﻿#include"character.h"
#include<string.h>
#include<time.h>
#include"character.h"
#include<string.h>

using namespace std;

void word::readword(char* filename){

}

void word::copycontent(char* str) {
	int len = strlen(str);
	m_content = (char*)malloc(len * sizeof(char));
	strcpy(m_content, str);
}

void word::enscript(int mode) {
	int len = strlen(m_content);
	m_enscript = (char*)malloc(len * sizeof(char));
	strcpy(m_enscript, m_content);
	if (len < 2)
		return;
	if (len == 2) {
		char c = m_enscript[1];
		m_enscript[1]= m_enscript[0];
		m_enscript[0] = c;
		return;
	}
	int ai = 0;
	int bi = 0;
	char* a = (char*)malloc(len - (len / 2)* sizeof(char));
	char* b = (char*)malloc((len / 2) * sizeof(char));
	for (int i = 0; i < len; i++) {
		if (i % 2 == 0) {
			*(a + ai) = *(m_content + i);
			ai++;
		}
		else {
			*(b + bi) = *(m_content + i);
			bi++;
		}
	}
	a[ai] = '\0';
	b[bi] = '\0';
	if (mode == 1) {
		strcpy(m_enscript, b);
		strcpy(m_enscript + bi, a);
	}
	else if(mode==2){
		strcpy(m_enscript, a);
		strcpy(m_enscript + ai, b);
	}
}

bool word::compare(char* charac) {

	return false;
}

int word::lenght() {
	int len = 0;
	while (*m_content++)
		len++;
	return len;
}

char* word::getcontent() const {
	return m_content;
}

char* word::getenscript() const {
	return m_enscript;
}

word::word():m_content(NULL), m_enscript(NULL), m_token(NULL){}

char* shift(char* str) {
	int len = strlen(str);
	if (len < 4)
		return str;
	else {
		srand(time(NULL));
		int deviation = rand() % (len-4);				
		if (deviation > len)
			deviation = deviation - len;
		char* str1 = (char*)malloc(len+1);
		char* str2 = (char*)malloc(len + 1);
		strcpy(str1, str);
		for (int i = 0; i < len; i++) {
			if (i - deviation < 0)
				*(str2 + (i - deviation + len)) = *(str1 + i);
			else
				*(str2 + (i - deviation)) = *(str1 + i);
		}
		strcpy(str1, str2);
		str1[len] = '\0';
		return str1;
		delete[]str1;
		delete[]str2;
	}
}

