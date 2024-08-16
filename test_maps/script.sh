# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    script.sh                                          :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: inazaria <inazaria@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/07/02 18:50:33 by inazaria          #+#    #+#              #
#    Updated: 2024/07/02 18:55:39 by inazaria         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

#!/bin/bash

for file in "$@" ; do
	export LINECOUNT=$(cat $file | wc -l)
	if [ $LINECOUNT -gt 100 ]; then
		echo $file
	fi
done
