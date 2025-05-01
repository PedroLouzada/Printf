/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbongiov <pbongiov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/01 17:31:18 by pbongiov          #+#    #+#             */
/*   Updated: 2025/05/01 20:05:50 by pbongiov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int printstr(char *str)
{
    int n;

    n = 0;
    while (str[n])
        n++;
    return (write (1, str, n));
}
int ft_numlen(int n)
{
    int i;
    
    i = 0;
    if (n < 0)
    {
        n = -n;
        i++;
    }
    while (n > 0)
    {
        n /= 10;
        i++;
    }
    return (i);
}
int ft_putnbr(int n)
{
    char	c;
    unsigned int num;
    
	if (n < 0)
	{
		write(1, "-", 1);
		num = -n;
	}
    else
    {
        num = n;
    }
	if (num >= 10)
	    ft_putnbr(num / 10);
	c = num % 10 + '0';
	write(1, &c, 1);
    return (ft_numlen(n));
}
int	ft_printf(const char *str, ...)
{
    char type;
    int n;
    va_list ap; 

    n = 0;
    va_start(ap, str);
    while (*str)
    {
        if (*str == '%' &&  str++)
        {
            if (*str == 's')
               n +=  printstr(va_arg(ap, char *));
            else if (*str == 'c')
            {    
                type =  va_arg(ap, int);
                n +=  write (1, &type, 1);
            }
            else if (*str == 'i' || *str == 'd')
                n += ft_putnbr(va_arg(ap, int));
            str++;
            else if (*str == )
        }
        else
            n +=  write(1, str++, 1);

    }
    return (n);
}

int main(void)
{
    printf(" - %i\n",
        ft_printf("testando o teste %c %s %i", 'a', "sla", -123)
    );
    printf("\n=======\n");
    printf(" - %i\n",
        printf("testando o teste %c %s %i", 'a', "sla", -123)
    );

}