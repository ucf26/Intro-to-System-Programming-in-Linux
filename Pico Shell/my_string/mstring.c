#include "mystring.h"


int min(int a, int b){
    if(a<=b) return a;
    else return b;
}
int str_len(const char *str){
    if(NULL == str){
        return 0;
    }
    else  {
        int i=0;
        while(str[i]!='\0'){
            i++;
        }
        return i;
    }
}

int str_cmp(const char *s1, const char *s2){
    if(NULL == s1 || NULL == s2){
        return -1;
    }
    else {
        int sz1 = str_len(s1);
        int sz2 = str_len(s2);
        int i=0;
        while(i<min(sz1, sz2)){
            if(s1[i] != s2[i]){
                return 0;
            }
            i++;
        }
        return i;
    }
}


int str_parse(char *str, char **args){
    if(NULL == str || NULL == args){
        return -1;
    }
    else {
        char *comm = strtok(str, " ");
        int i=0;
        while(comm != NULL){
            args[i]=comm;
            i++;
            comm = strtok(NULL, " ");
        }
        args[i] = NULL;
        return i;
    }
}