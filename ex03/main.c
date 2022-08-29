/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mcheng < mcheng@student.42kl.edu.my>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 00:08:17 by mcheng            #+#    #+#             */
/*   Updated: 2022/08/30 00:08:17 by mcheng           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include <string.h>

int     ft_whitespaces(char *str, int *i)
{
    int     i;
    int     sign;

    i = 0;
    sign = 1;
	while ((str[i] >= 9 && str[i] <= 13 ) || str[i] == 32) //checks for whitespace characters
		i++;
    while ((str[i] == 43) || (str[i] == 45)) //checks for plus or minus, enters while loop
    {
        if (str[i] == 45) //if minus, then multiply the current sign by -1 so even -- = + and odd --- = -
        {
            sign *= -1;
        }
    }
    *i = i;
    return(sign);
}

int     ft_atoi(char *str)
{
    int     i;
    int     sign;
    sign = ft_whitespaces(str, &i);
    int     corrector;

    while (str[i] >= 48 || str[i] <= 57)
    {
        corrector *= 10;
        corrector += str[i] - 48;
        i++;
    }
    corrector *= sign;
    return(corrector);
}

int     main(void)
{
    char    str[] = " ---+--+1234ab567";
    printf("%s\n", str);
    printf("%d\n", ft_atoi(str));
}