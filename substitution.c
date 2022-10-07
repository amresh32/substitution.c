#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>

int get_key(string s, int k[]);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
    string s = argv[1];
    int n = strlen(s);
    int k[26];
    if (n != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    for (int i = 0; i < n; i++)
    {
        if (isalpha(s[i]))
        {
            int a = 64;
            int b = 96;
            for (int j = 0; j < 26; j++)
            {
                a++;
                b++;
                if (isupper(s[j]))
                {
                    k[j] = (int) s[j] - a;

                    if (k[j] < 0)
                    {
                        k[j] = k[j] + 26;
                    }
                }
                else if (islower(s[j]))
                {
                    k[j] = (int) s[j] - b;

                    if (k[j] < 0)
                    {
                        k[j] = k[j] + 26;
                    }
                }
            }
        }
        else
        {
            printf("Usage: ./substitution key\n");
            return 1;
        }
    }
    string p = get_string("plaintext:  ");
    printf("ciphertext: ");
    int m = strlen(p);
    char c[m];
    int q[m];

    for (int x = 0; x < m; x++)
    {
        if (isalpha(p[x]))
        {
            if (isupper(p[x]))
            {
                q[x] = p[x] - 65;
                c[x] = p[x] + 0;
                for (int l = 0; l < k[q[x]]; l++)
                {
                    c[x]++;
                    if (c[x] > 90)
                    {
                        c[x] = c[x] - 26;
                    }
                }
            }
            else
            {
                q[x] = p[x] - 97;
                c[x] = p[x] + 0;
                for (int o = 0; o < k[q[x]]; o++)
                {
                    c[x]++;
                    if (c[x] > 122)
                    {
                        c[x] = c[x] - 26;
                    }
                }
            }

        }
        else
        {
            c[x] = p[x];
        }
        printf("%c", c[x]);
    }
    printf("\n");
    return 0;
}

int duplicate(string s)
{
    for (int e = 0; e < 26; e++)
    {
        for (int f = e + 1; f < 27; f++)
        {
            if (s[e] == s[f])
            {
                printf("Usage: ./substitution key\n");
                return 1;
            }
        }

    }
    return 0;
}