// #include "lumumbash.h"

// size_t    ft_strlcpy(char *dest, const char *src, size_t size)
// {
//     size_t    srcsize;
//     size_t    i;

//     srcsize = 0;
//     i = 0;
//     if (!src || !dest)
//         return (0);
//     srcsize = strlen(src);
//     if (size != 0)
//     {
//         while (src[i] != '\0' && i < (size - 1))
//         {
//             dest[i] = src[i];
//             i++;
//         }
//         dest[i] = '\0';
//     }
//     return (srcsize);
// }

// char    *ft_substr(char const *s, unsigned int start, size_t len)
// {
//     char    *str;
//     size_t    str_len;

//     if (!s)
//         return (0);
//     str_len = strlen((char *)s);
//     if (start > str_len)
//         return (strdup(""));
//     if (str_len - start >= len)
//         str = (char *)malloc((len + 1) * sizeof(char));
//     else
//         str = (char *)malloc((str_len - start + 1) * sizeof(char));
//     if (!str)
//         return (0);
//     ft_strlcpy(str, (s + start), (len + 1));
//     return (str);
// }

// static size_t    ft_countword(char const *s, char c)
// {
//     size_t    count;

//     if (!*s)
//         return (0);
//     count = 0;
//     while (*s)
//     {
//         while (*s == c)
//             s++;
//         if (*s)
//             count++;
//         while (*s != c && *s)
//             s++;
//     }
//     return (count);
// }

// char    **ft_split(char const *s, char c)
// {
//     char    **lst;
//     size_t    word_len;
//     int        i;

//     lst = (char **)malloc((ft_countword(s, c) + 1) * sizeof(char *));
//     if (!s || !lst)
//         return (0);
//     i = 0;
//     while (*s)
//     {
//         while (*s == c && *s)
//             s++;
//         if (*s)
//         {
//             if (!strchr(s, c))
//                 word_len = strlen(s);
//             else
//                 word_len = strchr(s, c) - s;
//             lst[i++] = ft_substr(s, 0, word_len);
//             s += word_len;
//         }
//     }
//     lst[i] = NULL;
//     return (lst);
// }