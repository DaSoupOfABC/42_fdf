/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keycodes.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jenlee <jenlee@student.42kl.edu.my>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 18:32:34 by jenlee            #+#    #+#             */
/*   Updated: 2025/06/27 18:32:34 by jenlee           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef KEYCODES_H
# define KEYCODES_H

# ifdef __linux__
#  define KEY_ESC       65307
#  define KEY_LEFT      65361
#  define KEY_RIGHT     65363
#  define KEY_UP        65362
#  define KEY_DOWN      65364
#  define KEY_PLUS      61
#  define KEY_KP_PLUS   65451
#  define KEY_MINUS     45
#  define KEY_KP_MINUS  65453
#  define KEY_PAGE_UP   65365
#  define KEY_PAGE_DOWN 65366

# elif defined(__APPLE__)
#  define KEY_ESC       53
#  define KEY_LEFT      123
#  define KEY_RIGHT     124
#  define KEY_UP        126
#  define KEY_DOWN      125
#  define KEY_PLUS      24
#  define KEY_KP_PLUS   69
#  define KEY_MINUS     27
#  define KEY_KP_MINUS  78
#  define KEY_PAGE_UP   116
#  define KEY_PAGE_DOWN 121

# else
#  define KEY_ESC       65307
#  define KEY_LEFT      65361
#  define KEY_RIGHT     65363
#  define KEY_UP        65362
#  define KEY_DOWN      65364
#  define KEY_PLUS      61
#  define KEY_KP_PLUS   65451
#  define KEY_MINUS     45
#  define KEY_KP_MINUS  65453
#  define KEY_PAGE_UP   65365
#  define KEY_PAGE_DOWN 65366

# endif

#endif
