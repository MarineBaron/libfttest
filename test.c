/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/24 09:04:08 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/21 14:33:57 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

/*-----------------VOID ------------*/

void	put_ok_ko(int test)
{
	if (test)
		printf("%s ---------> OK%s\n", ANSI_COLOR_GREEN, ANSI_COLOR_RESET);
	else
		printf("%s ---------> KO%s\n", ANSI_COLOR_RED, ANSI_COLOR_RESET);
}

// memset, memchr
void	tests_voidp_voidp_int_sizet(char *test_name, void *(*f_ft)(void*, int, size_t), void *(*f_nat)(void*, int, size_t), int nb_tests, void *data1[TAB_L], int data2[TAB_L], size_t data3[TAB_L])
{
	int		test;
	int		tests_ko;
	char	dst1[TAB_L];
	char	dst2[TAB_L];
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		memcpy(dst1, data1[i], TAB_L);
		memcpy(dst2, data1[i], TAB_L);
		test = !(memcmp(f_nat(dst1, data2[i], data3[i]), f_ft(dst2, data2[i], data3[i]), data3[i]));
		printf("|%s|%d|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// bzero
void	tests_void_voidp_sizet(char *test_name, void (*f_ft)(void*, size_t), void (*f_nat)(void*, size_t), int nb_tests, char *data1[TAB_L], size_t data2[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;
	void	*dst1;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		if (!(dst1 = (void *)malloc(data2[i])))
			return ;
		memcpy(dst1, data1[i], data2[i]);
		f_ft((void *)dst1, data2[i]);
		test = !(strlen(dst1));
		printf("|%s|%ld|", data1[i], data2[i]);
		put_ok_ko(test);
		tests_ko += !test;
		f_nat((void *)dst1, data2[i]);
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// memcpy,  memmove
void	tests_voidp_voidp_voidp_sizet(char *test_name, void *(*f_ft)(void*, const void*, size_t), void * (*f_nat)(void*, const void*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L])
{
	int		test;
	int		tests_ko;
	char	dst1[TAB_L];
	char	dst2[TAB_L];
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		strcpy(dst1, data1[i]);
		strcpy(dst2, data1[i]);
		test = !(strcmp(f_ft((void *)dst1, (const void*)data2[i], data3[i]),f_nat((void *)dst2, (const void*)data2[i], data3[i])));
		printf("|%s|%s|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		;i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

//  memccpy
void	tests_voidp_voidp_voidp_int_sizet(char *test_name, void *(*f_ft)(void*, const void*, int, size_t), void *(*f_nat)(void*, const void*, int, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], int data3[TAB_L], size_t data4[TAB_L])
{
	int		test;
	int		tests_ko;
	char	dst1[TAB_L];
	char	dst2[TAB_L];
	char	*datar1;
	char	*datar2;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		strcpy(dst1, data1[i]);
		strcpy(dst2, data1[i]);
		datar1 = f_ft((void*)dst1, (const void*)data2[i], data3[i], data4[i]);
		datar2 = f_nat((void*)dst2, (const void*)data2[i], data3[i], data4[i]);
		if (!datar1 && !datar2)
			test = 1;
		else if ((!datar1 && datar2) || (datar1 && !datar2))
			test = 0;
		else
			test = !strcmp(datar1, datar2);
		printf("|%s|%s|%d|%ld|", data1[i], data2[i], data3[i], data4[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

/* ------------------ SIZET ----------------*/

// strlcat
void	tests_sizet_charp_charp_sizet(char *test_name, size_t (*f_ft)(char*, const char*, size_t), size_t (*f_nat)(char*, const char*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L])
{
	
	int		test;
	int		test1;
	int		test2;
	int		tests_ko;
	char	dst1[TAB_L];
	char	dst2[TAB_L];
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		strcpy(dst1, data1[i]);
		strcpy(dst2, data1[i]);
		test1 = (f_ft(dst1, data2[i], data3[i]) == f_nat(dst2, data2[i], data3[i]));
		test2 = (!strcmp(dst1, dst2));
		test = (test1 && test2);
		printf("|%s|%s|%ld", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strlen
void	tests_sizet_charp(char *test_name, size_t (*f_ft)(const char*), size_t (*f_nat)(const char*), int nb_tests, char *data1[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft(data1[i]) == f_nat(data1[i]));
		printf("|%s|", data1[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

/* ------------------------ INT ----------------*/
// memcmp
void	tests_int_voidp_voidp_sizet(char *test_name, int (*f_ft)(const void*, const void*, size_t), int (*f_nat)(const void*, const void*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft((const void*)data1[i], (const void*)data2[i], data3[i]) == f_nat((const void*)data1[i], (const void*)data2[i], data3[i]));
		printf("|%s|%s|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strcmp
void	tests_int_charp_charp(char *test_name, int (*f_ft)(const char*, const char*), int (*f_nat)(const char*, const char*), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft(data1[i], data2[i]) == f_nat(data1[i], data2[i]));
		printf("|%s|%s|", data1[i], data2[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strncmp
void	tests_int_charp_charp_sizet(char *test_name, int (*f_ft)(const char*, const char*, size_t), int (*f_nat)(const char*, const char*, size_t), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft(data1[i], data2[i], data3[i]) == f_nat(data1[i], data2[i], data3[i]));
		printf("|%s|%s|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// is...
void	tests_int_int(char *test_name, int (*f_ft_int_int)(int), int (*f_nat_int_int)(int), int nb_tests, int data[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft_int_int(data[i]) == f_nat_int_int(data[i]));
		printf("|%c|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// atoi
void	tests_int_charp(char *test_name, int (*f_ft)(const char*), int (*f_nat)(const char*), int nb_tests, const char *data[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft(data[i]) == f_nat(data[i]));
		printf("|%s|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

/* ------------------- CHAR* -------------- */
// strdup
void	tests_charp_charp(char *test_name, char *(*f_ft)(const char*), char *(*f_nat)(const char*), int nb_tests, char *data[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = !(strcmp(f_ft(data[i]),f_nat(data[i])));
		printf("|%s|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strcpy, strcat
void	tests_charp_charp_charp(char *test_name, char *(*f_ft)(char*, const char*), char *(*f_nat)(char*, const char*), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L])
{
	int		test;
	int		test1;
	int		test2;
	int		tests_ko;
	char	dst1[TAB_L];
	char	dst2[TAB_L];
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		strcpy(dst1,data1[i]);
		strcpy(dst2,data1[i]);
		test1 = !(strcmp(f_ft(dst1, data2[i]),f_nat(dst2, data2[i])));
		test2 = (!strcmp(dst1, dst2));
		test = (test1 && test2);
		printf("|%s|%s|", data1[i], data2[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strncpy
void	tests_charp_charp_charp_sizet(char *test_name, char *(*f_ft)(char*, const char*, size_t), char *(*f_nat)(char*, const char*, size_t), int nb_tests, char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L])
{
	int		test;
	int		test1;
	int		test2;
	int		tests_ko;
	char	dst1[TAB_L];
	char	dst2[TAB_L];
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		strcpy(dst1,data1[i]);
		strcpy(dst2,data1[i]);
		test1 = !(strcmp(f_ft(dst1, data2[i], data3[i]),f_nat(dst2, data2[i], data3[i])));
		test2 = (!strcmp(dst1, dst2));
		test = (test1 && test2);
		printf("|%s|%s|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strchr, strrstr, strnrstr
void	tests_charp_charp_int(char *test_name, char *(*f_ft)(const char*, int), char *(*f_nat)(const char*, int), int nb_tests, char *data1[TAB_L], int data2[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;
	char	*p_ft;
	char	*p_nat;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		p_ft = f_ft(data1[i], data2[i]);
		p_nat = f_nat(data1[i], data2[i]);
		if ((!p_ft && p_nat) || (p_ft && !p_nat))
			test = 0;
		else if (!p_ft && !p_nat)
			test = 1;
		else 
			test = !(strcmp(p_ft, p_nat));
		printf("|%s|%d|", data1[i], data2[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strstr
void	tests_charp_charp_charp_2(char *test_name, char *(*f_ft)(const char*, const char*), char *(*f_nat)(const char*, const char*), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft(data1[i], data2[i]) == f_nat(data1[i], data2[i]));
		printf("|%s|%s|", data1[i], data2[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

// strnstr
void	tests_charp_charp_charp_sizet_2(char *test_name, char *(*f_ft)(const char*, const char*, size_t), char *(*f_nat)(const char*, const char*, size_t), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L])
{ 
	int		test;
	int		tests_ko;
	int		i;
	char	*p_ft;
	char	*p_nat;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		p_ft = f_ft(data1[i], data2[i], data3[i]);
		p_nat = f_nat(data1[i], data2[i], data3[i]);
		if ((!p_ft && p_nat) || (p_ft && !p_nat))
			test = 0;
		else if (!p_ft && !p_nat)
			test = 1;
		else 
			test = !(strcmp(p_ft, p_nat));
		printf("|%s|%s|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

/* ----------------- PART 2 --------------*/

void	subf_void_charp(char *s)
{
	(*s)++;
}

void	subf_void_int_charp(unsigned int i, char *s)
{
	i = i + 0;
	(*s)++;
}

char	subf_char_char(char c)
{
	return (c + 1);
}
char	subf_char_int_char(unsigned int i, char c)
{
	return (i % 2 ? c + 1 : c + 1);
}


/*  ------------- VOID MALLOC/STR ------------*/
// memalloc
void	tests2_voidp_sizet(char *test_name, void *(*f_ft)(size_t), int nb_tests, size_t data[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft(data[i]) ? 1 : 0);
		printf("|%ld|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strnew
void	tests2_charp_sizet(char *test_name, char *(*f_ft)(size_t), int nb_tests, size_t data[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft(data[i]) ? 1 : 0);
		printf("|%ld|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// memdel
void	tests2_void_voidpp(char *test_name, void (*f_ft)(void **), int nb_tests, char ***data)
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = 1;
		printf("|%p|", *(data[i]));
		put_ok_ko(test);
		f_ft((void **)data[i]);
		tests_ko += !test;
		i++;
	}
	printf(" -------just test--> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strdel
void	tests2_void_charpp(char *test_name, void (*f_ft)(char **), int nb_tests, char **data[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		f_ft(data[i]);
		test = 1;
		printf("|%p|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" -------just test--> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strclr
void	tests2_void_charp(char *test_name, void (*f_ft)(char *), int nb_tests, char *data[TAB_L])
{
	int		test;
	int		tests_ko;
	char	datao[TAB_L];
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		strcpy(datao, (const char*)data[i]);
		f_ft(datao);
		test = (!strlen(datao));
		printf("|%s|", datao);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// striter
void	tests2_void_charp_fp_void_charp(char *test_name, void (*f_ft)(char *, void (*f)(char *)), int nb_tests, char **data, void (*fp)(char *), char **result)
{
	int		test;
	int		tests_ko;
	int		i;
	char	*datai;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		datai = (char *)malloc(sizeof(char) * strlen(data[i]) + 1);
		strcpy(datai, (const char*)data[i]);
		f_ft(datai, fp);
		test = (!strcmp(datai, result[i]));
		free(datai);
		if (!data[i][0])
			test = 1;
		printf("|%s|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// striteri
void	tests2_void_charp_fp_void_int_charp(char *test_name, void (*f_ft)(char *, void (*f)(unsigned int, char *)), int nb_tests, char **data, void (*fp)(unsigned int, char *), char **result)
{
	int		test;
	int		tests_ko;
	int		i;
	char	*datai;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		datai = (char *)malloc(sizeof(char) * strlen(data[i]) + 1);
		strcpy(datai, (const char*)data[i]);
		f_ft(datai, fp);
		test = (!strcmp(datai, result[i]));
		printf("|%s|%s %s", data[i], datai, result[i]);
		free(datai);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
/*  ------------- CHAR  STR    ----------*/
// strmap
void	tests2_charp_charp_fp_char_char(char *test_name, char *(*f_ft)(const char *, char (*f)(char)), int nb_tests, char *data[TAB_L], char (*fp)(char), char *result[TAB_L])
{
	int			test;
	int			tests_ko;
	int			i;
	char		*datai;
	char		*datar;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		datai = (char *)malloc(sizeof(char) * strlen(data[i]) + 1);
		strcpy(datai, (const char*)data[i]);
		datar = f_ft((const char*)datai, fp);
		test = (!strcmp(datar, result[i]));
		free(datar);
		free(datai);
		printf("|%s|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strmapi
void	tests2_charp_charp_fp_char_int_char(char *test_name, char *(*f_ft)(const char *, char (*f)(unsigned int, char)), int nb_tests, char *data[TAB_L], char (*fp)(unsigned int, char), char *result[TAB_L])
{
	int			test;
	int			tests_ko;
	int			i;
	char		*datai;
	char		*datar;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		datai = (char *)malloc(sizeof(char) * strlen(data[i]) + 1);
		strcpy(datai, (const char*)data[i]);
		datar = f_ft((const char*)datai, fp);
		test = (!strcmp(datar, result[i]));
		free(datar);
		free(datai);
		printf("|%s|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strsub
void	tests2_charp_charp_int_size(char *test_name, char *(*f_ft)(const char *, unsigned int, size_t), int nb_tests, const char *data1[TAB_L], unsigned int data2[TAB_L], size_t data3[TAB_L], char *result[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;
	char	*datar;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		datar = f_ft(data1[i], data2[i], data3[i]);
		test = (i == 1 || i == 2 ? 1 : (!strcmp(datar, result[i])));
		printf("|%s|%d|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strjoin
void	tests2_charp_charp_charp(char *test_name, char *(*f_ft)(const char *, const char *), int nb_tests, const char *data1[TAB_L], const char * data2[TAB_L], char *result[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (!strcmp(f_ft(data1[i], data2[i]), result[i]));
		printf("|%s|%s|", data1[i], data2[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strtrim
void	tests2_charp_charp(char *test_name, char *(*f_ft)(const char *), int nb_tests, const char *data[TAB_L], const char *result[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;
	char	*datar;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		datar = f_ft(data[i]);
		test = (!datar) ? 0 : (!strcmp(datar, result[i]));
		printf("|%s|", data[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strsplit
void	tests2_charpp_charp_char(char *test_name, char **(*f_ft)(const char *, char), int nb_tests, char *data1[TAB_L], char data2[TAB_L], char ***result)
{
	int		test;
	int		tests_ko;
	char	**res;
	int		i;
	int		j;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		j = 0;
		test = 0;
		res = f_ft((const char*)data1[i], data2[i]);
		if ((!res || !res[j]) && (!result[i] || !result[i][j]))
			test = 1;
		else
		{

			while ((test || !j) && result[i] && (result[i])[j])
			{
				test = (!res || !res[j]) ? 0 : (!strcmp(res[j], result[i][j]));
				j++;	
			}
		}
		printf("|%s|%c|", data1[i], data2[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
/*  ------------- INT  STR    -----------*/
// strequ
void	tests2_int_charp_charp(char *test_name, int (*f_ft)(const char *, const char *), int nb_tests, const char *data1[TAB_L], const char * data2[TAB_L], int result[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft((const char*)data1[i], (const char*)data2[i]) ==  result[i]);
		printf("|%s|%s| %d", data1[i], data2[i], result[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// strnequ
void	tests2_int_charp_charp_sizet(char *test_name, int (*f_ft)(const char *, const char *, size_t), int nb_tests, const char *data1[TAB_L], const char *data2[TAB_L], size_t data3[TAB_L], int result[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = (f_ft((const char*)data1[i], (const char*)data2[i], data3[i]) ==  result[i]);
		printf("|%s|%s|%ld|", data1[i], data2[i], data3[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}
// itoa
void	tests2_charp_int(char *test_name, char *(*f_ft)(int), int nb_tests, int data1[TAB_L], char *result[TAB_L])
{
	int		test;
	int		tests_ko;
	int		i;

	printf("\n---------> %s\n", test_name);
	tests_ko = 0;
	i = 0;
	while (i < nb_tests)
	{
		test = !(strcmp(f_ft(data1[i]), result[i]));
		printf("|%d|", data1[i]);
		put_ok_ko(test);
		tests_ko += !test;
		i++;
	}
	printf(" ------------------> %s ", test_name);
	put_ok_ko(!tests_ko);
}

/* -------------------------- PUT -----------*/

void tests_void_putstr(int nb_tests, char const *data[TAB_L])
{
	int		i;
	
	dprintf(1, "\n---------> Tests PUT STR\n");
	i = 0;
	while (i < nb_tests)
	{
		dprintf(1, "\n!!!!!!!!!!!!! String :      %s\n", data[i]);
		dprintf(1, "\n----------- ft_putchar -----------\n");
		if (data[i][0])
			ft_putchar(data[i][0]);
		else
			dprintf(1, "!!!!!!!!!! Empty String !!!!!!!!");
		dprintf(1, "\n");
		dprintf(1, "\n----------- ft_putstr -----------\n");
		ft_putstr(data[i]);
		dprintf(1, "\n");
		dprintf(1, "\n----------- ft_putendl -----------\n");
		ft_putendl(data[i]);
		dprintf(1, "\n");
		dprintf(1, "\n----------- ft_putchar_fd -----------\n");
		if (data[i][0])
			ft_putchar_fd(data[i][0], 1);
		else
			dprintf(1, "!!!!!!!!!! Empty String !!!!!!!!\n");
		dprintf(1, "\n");
		dprintf(1, "\n----------- ft_putstr_fd -----------\n");
		ft_putstr_fd(data[i], 1);
		dprintf(1, "\n");
		dprintf(1, "\n----------- ft_putendl_fd -----------\n");
		ft_putendl_fd(data[i], 1);
		dprintf(1, "\n");
		i++;
	}
}

void tests_void_putnbr(int nb_tests, int data[TAB_L])
{
	int		i;
	
	dprintf(1, "\n---------> Tests PUT NBR\n");
	i = 0;
	while (i < nb_tests)
	{
		dprintf(1, "\n\n!!!!!!!!!!!!! Nb :      %d\n", data[i]);
		dprintf(1, "\n-------- ft_putnbr :    ");
		ft_putnbr(data[i]);
		dprintf(1, "\n----- ft_putnbr_fd :    ");
		ft_putnbr_fd(data[i], 1);
		i++;
	}
}
