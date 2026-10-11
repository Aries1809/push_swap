/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_only_func+thendelete.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ykabbani <ykabbani@student.42vienna.c      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/11 19:05:22 by ykabbani          #+#    #+#             */
/*   Updated: 2026/10/11 22:05:33 by ykabbani         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
In case of error, it must display "Error" followed by a \n on the standard error.
Errors include, for example: arguments that are not integers, integers outside the
valid range, or duplicate values.

																			  */

int	check_dup_disorder(int arr[], size_t i, size_t *mistakes)
//We do need to check if the input is only valid int range.
//Also if no params given.
{
	i = 0;
	if (newest_int != arr[i]) //This is not readable 		
		if (newest_int > arr[i])// &not worth optimizing if_cond order...
			*mistakes++;
	else
		return (found_dupe(!!!)); // D:
}

int	main(int argc, char *argv[])
{
	int		arr[];
	size_t	i;
	size_t	mistakes;
	//reuse argc for arr_size

	arr = (int *)malloc(sizeof(int) * (argc - 1));
	if (arr == NULL)
		return (...); //check required Error messages &stuff.
	i = 1;
	while(i < argc)
	{
		arr[i - 1] = ft_atoi(argv[i]);
		if (check_dup_disorder(arr, i, &mistakes)) //for checking valid range:
			return (failure_dup);			//itoa(atoi(nbr)) == OG_string
		i++;									  		//Stupid, but should work
	}
}
