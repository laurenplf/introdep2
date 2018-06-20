#include <stdio.h>
#include <stdlib.h>
#include "main.h"
#define SIZE 2000
//Bonjour c'est RYAAAAAN
int main()
{
    char s1[SIZE];
    create_str(s1, 1);

    char s2[SIZE];
    create_str(s2, 2);
    printf("\n");
    printf("Compare : %d\n", compare(s1, s2));
    printf("Chaine 1 palindrome ? %d\n", is_pal(s1));
    printf("Chaine 2 palindrome ? %d\n", is_pal(s2));
    return 0;
}

int mylen(char s[]){
  /* fonction renvoyant la longueur d'une chaine de caracteres */
    int i = 0;
    while (s[i] != '\0'){
        i++;
    }
    return i;
}

void create_str(char s[], int num){
    int size = SIZE;
    printf("Chaine numero %d (pas plus de ", num);
    printf("%d caracteres) : ", SIZE);
    scanf("%s", s);
    int c;
    while ((c = getchar ()) != '\n' && c != EOF);
}
int compare(char s1[], char s2[]){
    int mini = mylen(s1), maxi = mylen(s2);
    if (maxi < mini){
        maxi = mylen(s1);
        mini = mylen(s2);
    }
    int egales = 1, plus_petite = 0, i = 0;
    while (i < mini && (plus_petite == 0)){
        int l1 = s1[i], l2 = s2[i];
        if (l1 - l2){
            egales = 0;
            if (l1 < l2){
                plus_petite = 1;
            }
            else{
                plus_petite = 2;
            }
        }
        i++;
    }
    if (mini < maxi){
        egales = 0;
    }
    if (egales == 1){
        return 0;
    }
    else{
        if (plus_petite == 1){
            return -1;
        }
        else{
            return 1;
        }
    }
}

int is_pal(char s[]){
    int len = mylen(s), pal = 1, i = 0;
    if (len & 1){
        while (pal && i < (len-1)/2){
            pal = (s[i] == s[len - 1 - i]);
            i++;
        }
    }
    else{
        while (pal && i < len/2){
            pal = (s[i] == s[len - 1 - i]);
            i++;
        }
    }
    return pal;
}
