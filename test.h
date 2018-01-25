/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/23 18:27:22 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/21 10:38:36 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ********************************************************************r***** */
#ifndef TEST_H
# include <strings.h>
# define ANSI_COLOR_RED "\x1b[31m"
# define ANSI_COLOR_GREEN "\x1b[32m"
# define ANSI_COLOR_RESET "\033[0m"
# define TEST_H
# define TAB_L 256
# define ATOI_NB 12
# define ATOI0 "0"
# define ATOI1 "1"
# define ATOI2 "-10"
# define ATOI3 "    -+543"
# define ATOI4 "-2147483648"
# define ATOI5 "2147483647"
# define ATOI6 "-2147483649"
# define ATOI7 "-2147483650"
# define ATOI8 "2147483648"
# define ATOI9 "0"
# define ATOI10 "99999999999999999999999999"
# define ATOI11 "-99999999999999999999999999"
# define ISALPHA_NB 3
# define ISALPHA0 '4'
# define ISALPHA1 'A'
# define ISALPHA2 'z'
# define ISALNUM_NB 3
# define ISALNUM0 '@'
# define ISALNUM1 '1'
# define ISALNUM2 'Z'
# define ISASCII_NB 3
# define ISASCII0 0
# define ISASCII1 -1
# define ISASCII2 56888
# define ISDIGIT_NB 3
# define ISDIGIT0 'c'
# define ISDIGIT1 '1'
# define ISDIGIT2 'Z'
# define ISPRINT_NB 3 
# define ISPRINT0 0
# define ISPRINT1 -1
# define ISPRINT2 127
# define TOUPPER_NB 3
# define TOUPPER0 32
# define TOUPPER1 48
# define TOUPPER2 265897
# define TOLOWER_NB 3
# define TOLOWER0 0
# define TOLOWER1 100
# define TOLOWER2 -500
# define SRC_NB 9
# define TAB_L_SRC TAB_L*SRC_NB + SRC_NB
# define SRC_EMPTY ""
# define SRC_SHORT "ab"
# define SRC_SHORT2 "abcd"
# define SRC_SHORT3 "abcdefgh"
# define SRC_SHORT4 "fg"
# define SRC_SHORT5 "u"
# define SRC_LONG "gtry0\0\0\0\0\0\0\0\0\0"
# define INT_SMALL 4 
# define INT_BIG 20000000
# define INT_LONG 372036854775808
# define INT_1 1
# define INT_NEG -10

// memset, memchr
void	tests_voidp_voidp_int_sizet(char *test_name, void *(*f_ft)(void*, int, size_t), void *(*f_nat)(void*, int, size_t), int nb_tests, void *data1[TAB_L], int data[TAB_L], size_t data3[TAB_L]);
// bzero
void	tests_void_voidp_sizet(char *test_name, void (*f_ft)(void*, size_t), void (*f_nat)(void*, size_t), int nb_tests, char *data1[TAB_L], size_t data2[TAB_L]);
// memcpy,  memmove
void	tests_voidp_voidp_voidp_sizet(char *test_name, void *(*f_ft)(void*, const void*, size_t), void * (*f_nat)(void*, const void*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L]);
//  memccpy
void	tests_voidp_voidp_voidp_int_sizet(char *test_name, void *(*f_ft)(void*, const void*, int, size_t), void * (*f_nat)(void*, const void*, int, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], int data3[TAB_L], size_t data4[TAB_L]);
// strlcat
void	tests_sizet_charp_charp_sizet(char *test_name, size_t (*f_ft)(char*, const char*, size_t), size_t (*f_nat)(char*, const char*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L]);
// strlen
void	tests_sizet_charp(char *test_name, size_t (*f_ft)(const char*), size_t (*f_nat)(const char*), int nb_tests, char *data1[TAB_L]);
// memcmp
void	tests_int_voidp_voidp_sizet(char *test_name, int (*f_ft)(const void*, const void*, size_t), int (*f_nat)(const void*, const void*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L]);
// strcmp
void	tests_int_charp_charp(char *test_name, int (*f_ft)(const char*, const char*), int (*f_nat)(const char*, const char*), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L]);
// strncmp
void	tests_int_charp_charp_sizet(char *test_name, int (*f_ft)(const char*, const char*, size_t), int (*f_nat)(const char*, const char*, size_t), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L]);
// is...
void	tests_int_int(char *test_name, int (*f_ft_int_int)(int), int (*f_nat_int_int)(int), int nb_tests, int data[TAB_L]);
// atoi
void	tests_int_charp(char *test_name, int (*f_ft_int_charp)(const char*), int (*f_nat_int_charp)(const char*), int nb_tests, const char *data[TAB_L]);
// strdup
void	tests_charp_charp(char *test_name, char *(*f_ft_int_charp)(const char*), char *(*f_nat_int_charp)(const char*), int nb_tests, char *data[TAB_L]);
// strcpy, strcat
void	tests_charp_charp_charp(char *test_name, char *(*f_ft)(char*, const char*), char *(*f_nat)(char*, const char*), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L]);
// strncpy
void	tests_charp_charp_charp_sizet(char *test_name, char *(*f_ft)(char*, const char*, size_t), char *(*f_nat)(char*, const char*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L]);
// strchr, strnrstr
void	tests_charp_charp_int(char *test_name, char *(*f_ft)(const char*, int), char *(*f_nat)(const char*, int), int nb_tests, char *data1[TAB_L], int data2[TAB_L]);
//stirstr
void	tests_charp_charp_charp_2(char *test_name, char *(*f_ft)(const char*, const char*), char *(*f_nat)(const char*, const char*), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L]);
// strnstr
void	tests_charp_charp_charp_sizet_2(char *test_name, char *(*f_ft)(const char*, const char*, size_t), char *(*f_nat)(const char*, const char*, size_t), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L]);

/*  ------------- VOID MALLOC/STR ------------*/
// memalloc
void	tests2_voidp_sizet(char *test_name, void *(*f_ft)(size_t), int nb_tests, size_t data[TAB_L]);
// strnew
void	tests2_charp_sizet(char *test_name, char *(*f_ft)(size_t), int nb_tests, size_t data[TAB_L]);
// memdel
void	tests2_void_voidpp(char *test_name, void (*f_ft)(void **), int nb_tests, char ***data);
void	tests2_void_charpp(char *test_name, void (*f_ft)(char **), int nb_tests, char **data[TAB_L]);
// strclr
void	tests2_void_charp(char *test_name, void (*f_ft)(char *), int nb_tests, char *data[TAB_L]);
// strstriter
void	tests2_void_charp_fp_void_charp(char *test_name, void (*f_ft)(char *, void (*f)(char *)), int nb_tests, char **data, void (*f)(char *), char **result);
// strstriteri
void	tests2_void_charp_fp_void_int_charp(char *test_name, void (*f_ft)(char *, void (*f)(unsigned int, char *)), int nb_tests, char **data, void (*f)(unsigned int, char *), char **result);
/*  ------------- CHAR  STR    ----------*/
// strmap
void	tests2_charp_charp_fp_char_char(char *test_name, char *(*f_ft)(const char *, char (*f)(char)), int nb_tests, char *data[TAB_L], char (*f)(char), char *result[TAB_L]);
// strmapi
void	tests2_charp_charp_fp_char_int_char(char *test_name, char *(*f_ft)(const char *, char (*f)(unsigned int, char)), int nb_tests, char *data[TAB_L], char (*f)(unsigned int, char), char *result[TAB_L]);
// strsub
void	tests2_charp_charp_int_size(char *test_name, char *(*f_ft)(const char *, unsigned int, size_t), int nb_tests, const char *data1[TAB_L], unsigned int data2[TAB_L], size_t data3[TAB_L], char *result[TAB_L]);
// strjoin
void	tests2_charp_charp_charp(char *test_name, char *(*f_ft)(const char *, const char *), int nb_tests, const char *data1[TAB_L], const char * data2[TAB_L], char *result[TAB_L]);
// strtrim
void	tests2_charp_charp(char *test_name, char *(*f_ft)(const char *), int nb_tests, const char *data[TAB_L], const char *result[TAB_L]);
// strsplit
void	tests2_charpp_charp_char(char *test_name, char **(*f_ft)(const char *, char), int nb_tests, char *data1[TAB_L], char data2[TAB_L], char ***result);
void	tests2_charp_int(char *test_name, char *(*f_ft)(int), int nb_tests, int data1[TAB_L], char *result[TAB_L]);
/*  ------------- INT  STR    -----------*/
// strequ
void	tests2_int_charp_charp(char *test_name, int (*f_ft)(const char *, const char *), int nb_tests, const char *data1[TAB_L], const char * data2[TAB_L], int result[TAB_L]);
// strnequ
void	tests2_int_charp_charp_sizet(char *test_name, int (*f_ft)(const char *, const char *, size_t), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L], int result[TAB_L]);

/* -------------- VOID PUT --------------*/
void	tests_void_putstr(int nb_tests, char const *data[TAB_L]);
void	tests_void_putnbr(int nb_tests, int	data[TAB_L]);

void	subf_void_charp(char *s);
void	subf_void_int_charp(unsigned int i, char *s);
char	subf_char_char(char s);
char	subf_char_int_char(unsigned int i, char c);
	
#endif
