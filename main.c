/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaron <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 09:24:55 by mbaron            #+#    #+#             */
/*   Updated: 2017/12/21 14:47:05 by mbaron           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"
#include "../libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <unistd.h>
#include <limits.h>
int		main(void)
{
	int			i;
	int			j;
	/*---------- STRS ------*/
	char 		*tab_dest[TAB_L] = {SRC_EMPTY, SRC_EMPTY, SRC_EMPTY, SRC_SHORT, SRC_SHORT, SRC_SHORT, SRC_LONG, SRC_LONG, SRC_LONG};
	char 		*t_dest[TAB_L] = {SRC_LONG, SRC_SHORT3, SRC_EMPTY, SRC_SHORT, SRC_SHORT, SRC_SHORT, SRC_LONG, SRC_LONG, SRC_LONG};
					const char	*tab_src[TAB_L] = {SRC_EMPTY, SRC_SHORT, SRC_LONG, SRC_EMPTY, SRC_SHORT, SRC_LONG, SRC_EMPTY, SRC_SHORT, SRC_LONG};
	const char	*t_src[TAB_L] = {SRC_EMPTY, SRC_SHORT, SRC_LONG, SRC_EMPTY, SRC_SHORT, SRC_LONG, SRC_EMPTY, SRC_SHORT, SRC_LONG};
	const char	*t_s1[TAB_L] = {SRC_EMPTY, SRC_EMPTY, SRC_SHORT3, SRC_SHORT3, SRC_SHORT3, SRC_SHORT3, SRC_SHORT3, SRC_SHORT, SRC_SHORT};
	const char	*t_s2[TAB_L] = {SRC_EMPTY, SRC_SHORT, SRC_EMPTY, SRC_SHORT, SRC_SHORT4, SRC_SHORT5, SRC_SHORT3, SRC_SHORT3, SRC_LONG};
	const char	*t_cmp1[TAB_L] = {SRC_EMPTY, SRC_EMPTY, SRC_EMPTY, SRC_SHORT3, SRC_SHORT3, SRC_SHORT3, SRC_SHORT3, SRC_SHORT, SRC_SHORT};
	const char	*t_cmp2[TAB_L] = {SRC_EMPTY, SRC_SHORT, SRC_SHORT3, SRC_EMPTY, SRC_SHORT, SRC_SHORT3, SRC_EMPTY, SRC_SHORT, SRC_SHORT4};
	int			tab_int[TAB_L] = {INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL};
	int			tab_int_nbr[TAB_L] = {0, INT_SMALL, INT_BIG, INT_1,  INT_NEG, INT_MAX, INT_MIN, 10, 12};
	int			tab_c[TAB_L] = {97, 98, 99, 100, 101, 102, 103, 104, 0};
	//int			t_int[TAB_L];
	size_t		tab_sizet[TAB_L] = {INT_SMALL, 2, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, INT_SMALL, 0};
//	size_t		t_sizet[TAB_L];
	const char		*tab_d3[TAB_L] = {"","","","toti","toti","toti","ratitu","ratitu","ratitu"};
	unsigned int tab_i3[TAB_L] = {0, 1, 10, 0, 0, 0, 0, 1, 1, 10};
	size_t		 tab_s3[TAB_L] = {0, 1, 10, 0, 1, 10, 0, 2, 10};
	char		*tab_r3[TAB_L] = {"","","","","t","toti","","at","atitu"};
	const char		*tab_d4[TAB_L] = {"","toto","toti","toti","","ratitu","ratitu","", ""};
	char		*tab_r4[TAB_L] = {"","toto","toti","totitoti","toti", "totiratitu","ratituratitu","ratitu","ratitu"};
	const char		*tab_d5[TAB_L] = {"tu",	"toto   ",	"to to",	"toti\t",	"\ntoti",	"toti   ",	"  \rratitu",	"rat\nitu",	"rat\titu"};
	const char		*tab_r5[TAB_L] = {"tu",	"toto",		"to to",	"toti",		"toti",		"toti",		"\rratitu",		"rat\nitu",	"rat\titu"};
	char		*tab_d6[TAB_L] = {"to*","to*ti","*to*ti*","**to***ti*tu", "to*ti","to","to***ti","***", ""};
	char		tab_c6[TAB_L] = {'*',' ','*','*', '*','*','*','*', '*'};
	char		***tab_r6;
	int			testr6;
	size_t		tab_i7[TAB_L] = {2, 	4, 			5, 			10, 		4, 			0, 			10, 			4, 			10};
	int 	tab_r7[TAB_L] = {		1, 		0, 			1, 			0, 			0, 			0, 			0, 				1, 			1};
	int 	tab_r8[TAB_L] = {		1, 		1, 			1, 			0, 			0, 			1, 			0, 				1, 			1};
	int		tab_intitoa[TAB_L] = {-2147483648,	-100,	-1000,	-1,	0,	1,	100,	+1000,	2147483647};
	char	*tab_chritoa[TAB_L] = {"-2147483648",	"-100",	"-1000",	"-1",	"0",	"1",	"100",	"1000",	"2147483647"};

	testr6 = 0;
	if (!(tab_r6 = (char***)malloc(sizeof(char**) * SRC_NB)))
		return (1);
	i = 0;
	while (i < SRC_NB)
	{
		if (!(tab_r6[i] = (char**)malloc(sizeof(char*) * SRC_NB)))
		{
			while (i) {
				j = SRC_NB;
				while (j)
				{
					free(tab_r6[i - 1][j - 1]);
					j--;
				}
				free(tab_r6[i - 1]);
				i--;
			}
			free(tab_r6);
			return (1);
		}
		j = 0;
		while (j < SRC_NB)
		{
			if (!(tab_r6[i][j] = (char*)malloc(sizeof(char) * SRC_NB)))
			{
				while (i)
				{
					if (testr6)
					{
						j = SRC_NB;
						testr6 = 1;
					}
					while (j)
					{
						free(tab_r6[i - 1][j - 1]);
						j--;
					}
					free(tab_r6[i - 1]);
					i--;
				}
				free(tab_r6);
				return (1);
			}
			j++;
		}
		i++;
	}

	strcpy(tab_r6[0][0], "to");
	tab_r6[0][1] = NULL;
	strcpy(tab_r6[1][0], "to*ti");
	tab_r6[1][1] = NULL;
	strcpy(tab_r6[2][0], "to");
	strcpy(tab_r6[2][1], "ti");
	tab_r6[2][2] = NULL;
	strcpy(tab_r6[3][0], "to");
	strcpy(tab_r6[3][1], "ti");
	strcpy(tab_r6[3][2], "tu");
	tab_r6[3][3] = NULL;
	strcpy(tab_r6[4][0], "to");
	strcpy(tab_r6[4][1], "ti");
	tab_r6[4][2] = NULL;
	strcpy(tab_r6[5][0], "to");
	tab_r6[5][1] = NULL;
	strcpy(tab_r6[6][0], "to");
	strcpy(tab_r6[6][1], "ti");
	tab_r6[6][2] = NULL;
	tab_r6[7][0] = NULL;
	tab_r6[8][0] = NULL;

	char		*t_d_memcpy[TAB_L] = {SRC_SHORT5, SRC_SHORT, SRC_SHORT4, SRC_SHORT2, SRC_SHORT3, SRC_LONG, SRC_LONG, SRC_LONG, SRC_LONG};
	const char	*t_s_memcpy[TAB_L] = {SRC_EMPTY, SRC_SHORT5, SRC_SHORT, SRC_SHORT4, SRC_SHORT2, SRC_SHORT3, SRC_LONG, SRC_LONG, SRC_LONG};
	size_t		t_i_memcpy[TAB_L] = {1, 2, 2, 3, 3, 4, 4, 4, 4};


	/*----------- POINTER/POINTER-------*/
	char		***tab_pointer;

	/*---------- ATOI -------*/
	const char	*tab_atoi[TAB_L] = {ATOI0, ATOI1, ATOI2, ATOI3, ATOI4, ATOI5, ATOI6, ATOI7, ATOI8, ATOI9, ATOI10, ATOI11};

	/*---------- IS ALPHA/DIGIT/ALNUM/PRINT/ASCII/ -------*/
	int			tab_isalpha[TAB_L] = {ISALPHA0, ISALPHA1, ISALPHA2};
	int			tab_isdigit[TAB_L] = {ISDIGIT0, ISALPHA1, ISALPHA2};
	int			tab_isalnum[TAB_L] = {ISALNUM0, ISALNUM1, ISALNUM2};
	int			tab_isprint[TAB_L] = {ISPRINT0, ISPRINT1, ISPRINT2};
	int			tab_isascii[TAB_L] = {ISASCII0, ISASCII1, ISASCII2};
	int			tab_tolower[TAB_L] = {TOLOWER0, TOLOWER1, TOLOWER2};
	int			tab_toupper[TAB_L] = {TOUPPER0, TOUPPER1, TOUPPER2};

	/*---------- MEMS ------*/
	void		*tab_mem[2] = {SRC_SHORT2, SRC_SHORT3};
	int			tab_memc[2] = {65, 300};
	size_t		tab_mems[2] = {2, 4};
	char		*tab_bz[2] = {"bbbbbb", "cccccc"};
	size_t		tab_bzs[2] = {3, 2};

	/* ----------- FONCTION ---------*/
	char	**tab_d2;
	char	**tab_r2;

	/*---------- MEMS ------*/
	tests_voidp_voidp_int_sizet("memset",&ft_memset,&memset, 2, tab_mem, tab_memc, tab_mems);
	tests_void_voidp_sizet("bzero", &ft_bzero, &bzero, 2, tab_bz, tab_bzs);
	tests_voidp_voidp_voidp_sizet("memcpy", &ft_memcpy, &memcpy, SRC_NB, t_d_memcpy, t_s_memcpy, t_i_memcpy);

	memcpy(t_dest, tab_dest, TAB_L);
	tests_voidp_voidp_voidp_int_sizet("memccpy", &ft_memccpy, &memccpy, SRC_NB, t_d_memcpy, t_s_memcpy, tab_int, t_i_memcpy);

	tests_int_voidp_voidp_sizet("memcmp", &ft_memcmp, &memcmp, SRC_NB, t_dest, t_src, tab_sizet);

	/* ----------------- SEGFAULT ------------- */
//memcpy(t_dest, tab_dest, TAB_L);
//tests_voidp_voidp_voidp_sizet("memmove", &ft_memmove, &memmove, SRC_NB, t_dest, tab_src, tab_sizet);
//memset(t_int, 'a', TAB_L);
//memset(t_sizet, 2, TAB_L);
//tests_voidp_voidp_int_sizet("memchr",&ft_memchr,&memchr, SRC_NB, tab_src, t_int, t_sizet);

	/*---------- STRS ------*/
	tests_sizet_charp("strlen", &ft_strlen, &strlen, SRC_NB, t_dest);
	tests_charp_charp("strdup", &ft_strdup, &strdup, SRC_NB, tab_dest);
	tests_charp_charp_charp("strcpy", &ft_strcpy, &strcpy, SRC_NB, t_dest, t_src);
	tests_charp_charp_charp_sizet("strncpy", &ft_strncpy, &strncpy, SRC_NB, t_dest, tab_src, tab_sizet);
	tests_charp_charp_charp("strcat", &ft_strcat, &strcat, SRC_NB, t_dest, tab_src);
	tests_charp_charp_charp_sizet("strncat", &ft_strncat, &strncat, SRC_NB, t_dest, tab_src, tab_sizet);
	tests_sizet_charp_charp_sizet("strlcat", &ft_strlcat, &strlcat, SRC_NB, t_dest, tab_src, tab_sizet);
	tests_charp_charp_int("strchr", &ft_strchr, &strchr, SRC_NB, tab_dest, tab_c);
	tests_charp_charp_int("strrchr", &ft_strrchr, &strrchr, SRC_NB, tab_dest, tab_c);
	tests_charp_charp_charp_2("strstr", &ft_strstr, &strstr, SRC_NB, t_s1, t_s2);
	tests_charp_charp_charp_sizet_2("strnstr", &ft_strnstr, &strnstr, SRC_NB, t_s1, t_s2, tab_sizet);
	tests_int_charp_charp("strcmp", &ft_strcmp, &strcmp, SRC_NB, t_cmp1, t_cmp2);
	tests_int_charp_charp_sizet("strncmp", &ft_strncmp, &strncmp, SRC_NB, t_cmp1, t_cmp2, tab_sizet);
	/*---------- ATOI -------*/
	tests_int_charp("atoi", &ft_atoi, &atoi, ATOI_NB, tab_atoi);
	
	/*---------- IS ALPHA/DIGIT/ALNUM/PRINT/ASCII/ -------*/
	tests_int_int("isalpha", &ft_isalpha, &isalpha, ISALPHA_NB, tab_isalpha);
	tests_int_int("isdigit", &ft_isdigit, &isdigit, ISDIGIT_NB, tab_isdigit);
	tests_int_int("isalnum", &ft_isalnum, &isalnum, ISALNUM_NB, tab_isalnum);
	tests_int_int("isprint", &ft_isprint, &isprint, ISPRINT_NB, tab_isprint);
	tests_int_int("isascii", &ft_isascii, &isascii, ISASCII_NB, tab_isascii);
	tests_int_int("toupper", &ft_toupper, &toupper, TOUPPER_NB, tab_toupper);
	tests_int_int("tolower", &ft_tolower, &tolower, TOLOWER_NB, tab_tolower);

	/*------------ PART 2 ----------------*/
	tests2_voidp_sizet("memalloc", &ft_memalloc, SRC_NB, tab_sizet);
	tests2_charp_sizet("strnew", &ft_strnew, SRC_NB, tab_sizet);
	
	i = 0;
	if (!(tab_pointer = (char ***)malloc(sizeof(char **) * SRC_NB)))
		return (1);
	while (i < SRC_NB)
	{
		if (!(tab_pointer[i] = (char **)malloc(sizeof(char *) * SRC_NB)))
			return (1);
		j = 0;
		while (j < SRC_NB)
		{
			if (!(tab_pointer[i][j] = (char *)malloc(sizeof(char))))
				return (1);
			tab_pointer[i][j][0] = 'a';
			j++;
		}
		i++;
	}
	tests2_void_voidpp("memdel", &ft_memdel, SRC_NB, tab_pointer);
	free(tab_pointer);
	tests2_void_charp("strclr", &ft_strclr, SRC_NB, tab_dest);

	tab_d2 = (char**)malloc(SRC_NB * sizeof(char *));
	tab_r2 = (char**)malloc(SRC_NB * sizeof(char *));
	i = 0;
	while (i < SRC_NB)
	{
		tab_d2[i] = (char*)malloc(TAB_L * sizeof(char));
		tab_r2[i] = (char*)malloc(TAB_L * sizeof(char));
		strcpy(tab_d2[i], t_dest[i]);
		strcpy(tab_r2[i], t_dest[i]);
		j = 0;
		while (tab_r2[i][j])
		{
			tab_r2[i][j]++;
			j++;
		}
		i++;
	}
	
	
	tests2_void_charp_fp_void_charp("striter", &ft_striter, SRC_NB, tab_d2, &subf_void_charp, tab_r2);
	tests2_void_charp_fp_void_int_charp("striteri", &ft_striteri, SRC_NB, tab_d2, &subf_void_int_charp, tab_r2);
	tests2_charp_charp_fp_char_char("strmap", &ft_strmap, SRC_NB, tab_d2, &subf_char_char, tab_r2);
	tests2_charp_charp_fp_char_int_char("strmapi", &ft_strmapi, SRC_NB, tab_d2, &subf_char_int_char, tab_r2);
	tests2_charp_charp_int_size("strsub", &ft_strsub, SRC_NB, tab_d3, tab_i3, tab_s3, tab_r3);
	tests2_charp_charp_charp("strjoin", &ft_strjoin, SRC_NB, tab_d3, tab_d4, tab_r4);
	tests2_charp_charp("strtrim", &ft_strtrim, SRC_NB, tab_d5, tab_r5);
	tests2_charpp_charp_char("strsplit", &ft_strsplit, SRC_NB, tab_d6, tab_c6, tab_r6);
	tests2_int_charp_charp("strequ", &ft_strequ, SRC_NB, tab_d5, tab_r5, tab_r7);
	tests2_int_charp_charp_sizet("strnequ", &ft_strnequ, SRC_NB, tab_d5, tab_r5, tab_i7, tab_r8);
	tests2_charp_int("itoa", &ft_itoa, SRC_NB, tab_intitoa, tab_chritoa);
	/*------------ VOID PUT --------------*/
	tests_void_putstr(SRC_NB, t_cmp1);
	tests_void_putnbr(SRC_NB, tab_int_nbr);
	return (0);
}
