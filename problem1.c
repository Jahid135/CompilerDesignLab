

#include<stdio.h>
char str[100], letters[100],digits[100],others[100],vowel[70],consonent[70],vowelword[100],consonentword[100];
int inl=0,ind=0,ino=0, markl[300],markd[300],marko[300],mr[200],i,j,x,vowelcount=0,consonentcount=0,vowelin=0,
consonentin=0,vowelwordin=0,consonentwordin=0;
int is_digit(char ch){
    if(ch>='0'&&ch<='9') return 1;
    return 0;
}

int is_char(char ch){
    if(ch>='A'&&ch<='Z') return 1;
    if(ch>='a'&&ch<='z') return 1;
    return 0;
}
int is_vowel(char ch){
    if(ch=='a'||ch=='e'||ch=='i'||ch=='o'||ch=='u'||ch=='A'||ch=='E'||ch=='I'||ch=='O'||ch=='U') return 1;
    return 0;
}


void cnt(){

    int wordcount=1,letter_cnt=0,digit_count=0, other = 0;
    for(i=0;str[i];i++){
        x = (int)str[i];

        if(str[i]==' '&&(is_char(str[i+1])||is_digit(str[i+1]))){
           wordcount++;
        }

        if(is_char(str[i])){
            letter_cnt++;
           if(is_char(str[i])&&!markl[x]){
            letters[inl++] = str[i];
            letters[inl++] = ' ';
            markl[x] = 1;
           }
        }
        if(is_digit(str[i])){
            digit_count++;
            if(is_digit(str[i])&&!markl[x]){
            digits[ind++] = str[i];
            digits[ind++] = ' ';
            markd[x] = 1;
        }
        }
        if(!is_digit(str[i])&&!is_char(str[i])){
            other++;
            if(!is_digit(str[i])&&!is_char(str[i])&&!markl[x]){
            others[ino++] = str[i];
            others[ino++] = ' ';
            marko[x] = 1;
        }
    }
    if(is_vowel(str[i])){
           vowelcount++;
            if(!mr[x])
                vowel[vowelin++] = str[i];
           //printf("%c\n",vw[vow-1]);
        }
        else if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z'){
            consonentcount++;
            if(!mr[x])
                consonent[consonentin++] = str[i];
        }
        mr[(int)str[i]] = 1;
    letters[inl] = '\0';
    digits[ind] = '\0';
    others[ino] = '\0';

}
printf("\n\nNumbers of words : %d\n",wordcount);
    printf("Numbers of letters : %d\n",letter_cnt);
    printf("Numbers of digit : %d\n",digit_count);
    printf("Numbers of Other char : %d\n",other);
    printf("Separated letters : %s\n",letters);
    printf("Separated digits : %s\n",digits);
    printf("Separated others : %s\n",others);
     printf("Numbers of VOWELS : %d\n",vowelcount);
    printf("Numbers of CONSONANTS : %d\n",consonentcount);
    printf("Vowels : ");
    for(i=0;i<vowelin;i++){
        printf("%c ",vowel[i]);
    }
    printf("\nConsonants : ");
    for(i=0;i<consonentin;i++){
        printf("%c ",consonent[i]);
    }
}
void separateword(){

    for(i=0;str[i];i++){
        if(is_vowel(str[i])){
            while(str[i]!=' '&&str[i]!='\0'){
                vowelword[vowelwordin++] = str[i++];
            }
            vowelword[vowelwordin++]  = ' ';
        }
        else if(str[i]>='A'&&str[i]<='Z'||str[i]>='a'&&str[i]<='z'){
            while(str[i]!=' '&&str[i]!='\0'){
                consonentword[consonentwordin++] = str[i++];
            }
            consonentword[consonentwordin++]  = ' ';
        }
    }
    vowelword[vowelwordin] = '\0';
    consonentword[consonentwordin] = '\0';
    printf("\n\nWords started with vowel : %s\n",vowelword);
    printf("Words started with consonant : %s\n",consonentword);
}

int main()
{

    freopen("input.txt","r",stdin);
    scanf("%[^\n]",str);
    printf("The input string is\n %s ",str);
    cnt();
    separateword();

}
