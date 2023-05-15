#include <stdlib.h>
#include <stdio.h>
#include <string.h>
char **tokenizer(char str[], int *size);
int main()
{
    char str1[100 + 1], str2[100 + 1];
    char **word1 = NULL;
    char **word2 = NULL;
    int size1 = 0, size2 = 0;
    int i;
    gets(str1);
    gets(str2);

    word1 = tokenizer(str1, &size1);
    word2 = tokenizer(str2, &size2);
    if (!word1 || !word2)
    {
        return -1;
    }

    // for(i = 0; i<size1; i++) puts(word1[i]);
    // for(i = 0; i<size2; i++) puts(word2[i]);

    for (i = 0; i < size2; i++)
    {
        for (int j = 1; j < size2; j++)
        {
            if (strlen(word2[j - 1]) < strlen(word2[j]) || strlen(word2[j - 1]) == strlen(word2[j]) && strcmp(word2[j - 1], word2[j]) > 0)
            {
                char *t = word2[j - 1];
                word2[j - 1] = word2[j];
                word2[j] = t;
            }
        }
    }

    int arr[50], ai = 0;
    for (int i2 = 0; i2 < size2; i2++)
    {
        char *tmp;
        int pass = 0;
        for (i = 0; i < size1; i++)
        {
            for (int j = 0; j < size1; j++)
            {
                if (j == i)
                    continue;

                tmp = (char *)malloc((strlen(word1[i]) + strlen(word1[j]) + 1) * sizeof(char));
                if (!tmp)
                {
                    return -1;
                }
                strcpy(tmp, word1[i]);
                strcat(tmp, word1[j]);

                if (strcmp(tmp, word2[i2]) == 0)
                {
                    int alreadyExist = 0;
                    for (int k = 0; k < ai; k++)
                    {
                        if (arr[k] == i2)
                        {
                            alreadyExist = 1;
                            break;
                        }
                    }
                    if (!alreadyExist)
                    {
                        arr[ai++] = i2;
                        puts(tmp);
                        pass = 1;
                        break;
                    }
                }
                if (pass)
                    break;
            }
        }
    }

    for (i = 0; i < size1; i++)
        free(word1[i]);
    for (i = 0; i < size2; i++)
        free(word2[i]);
    free(word1);
    free(word2);

    return 0;
}

char **tokenizer(char str[], int *size)
{
    char *p;
    char **word = NULL;
    int i = 0;
    int cnt = 0;

    for (p = str; *p; p++)
        if (*p == ' ')
            cnt++;
    *size = cnt + 1;
    word = (char **)malloc((cnt + 1) * sizeof(char *));
    if (!word)
    {
        return NULL;
    }

    cnt = 0;
    for (p = str; *p; p++)
    {
        if (*p != ' ')
            cnt++;
        else
        {
            word[i] = (char *)malloc((cnt + 1) * sizeof(char));
            if (!word[i])
            {
                return NULL;
            }
            strncpy(word[i], p - cnt, cnt);
            i++;
            cnt = 0;
        }
    }
    word[i] = (char *)malloc((cnt + 1) * sizeof(char));
    if (!word[i])
    {
        return NULL;
    }
    strncpy(word[i], p - cnt, cnt);
    i++;
    cnt = 0;
    return word;
}

/*
apple or ange pineapple coconuts lemons ora nge
appleapple orange orlemons
*/