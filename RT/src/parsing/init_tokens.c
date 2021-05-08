/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_tokens.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: talemari <talemari@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/18 13:31:55 by talemari          #+#    #+#             */
/*   Updated: 2017/06/08 11:52:55 by talemari         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../inc/rt.cuh"

static void	init_tokens2(t_parse_tools *t);
static void	init_tokens3(t_parse_tools *t);
/*
** Initializes the list of tokens for the parser.
** These are strings that the user must match in their rt file.
*/

void		init_tokens(t_parse_tools *t)
{
	if (!(t->tokens = (char **)ft_memalloc(sizeof(char *) * T_COUNT + 1)))
		ft_errno_exit();
	if ((!(t->tokens[T_OPEN_BRACKET] = ft_strdup("{"))) ||
		(!(t->tokens[T_CLOSE_BRACKET] = ft_strdup("}"))) ||
		(!(t->tokens[T_EMPTY_LINE] = ft_strdup(""))) ||
		(!(t->tokens[T_SCENE] = ft_strdup("scene"))) ||
		(!(t->tokens[T_CAMERA] = ft_strdup("camera"))) ||
		(!(t->tokens[T_LIGHT] = ft_strdup("light"))) ||
		(!(t->tokens[T_KFLARE] = ft_strdup("kflare"))) ||
		(!(t->tokens[T_PLANE] = ft_strdup("plane"))) ||
		(!(t->tokens[T_DISK] = ft_strdup("disk"))) ||
		(!(t->tokens[T_SPHERE] = ft_strdup("sphere"))) ||
		(!(t->tokens[T_CYLINDER] = ft_strdup("cylinder"))) ||
		(!(t->tokens[T_CONE] = ft_strdup("cone"))) ||
		(!(t->tokens[T_PARABOLOID] = ft_strdup("paraboloid"))) ||
		(!(t->tokens[T_RESOLUTION] = ft_strdup("resolution"))) ||
		(!(t->tokens[T_RAY_DEPTH] = ft_strdup("ray depth"))) ||
		(!(t->tokens[T_BACKGROUND_COLOR] = ft_strdup("background color"))) ||
		(!(t->tokens[T_KA] = ft_strdup("ka"))))
		ft_errno_exit();
	init_tokens2(t);
}

static void	init_tokens2(t_parse_tools *t)
{
	if ((!(t->tokens[T_AMBIENT_LIGHT_COLOR] =
		ft_strdup("ambient light color"))) ||
		(!(t->tokens[T_POSITION] = ft_strdup("position"))) ||
		(!(t->tokens[T_DIRECTION] = ft_strdup("direction"))) ||
		(!(t->tokens[T_LOOK_AT] = ft_strdup("look at"))) ||
		(!(t->tokens[T_COLOR] = ft_strdup("color"))) ||
		(!(t->tokens[T_RADIUS] = ft_strdup("radius"))) ||
		(!(t->tokens[T_HEIGHT] = ft_strdup("height"))) ||
		(!(t->tokens[T_DIFFUSE_COEF] = ft_strdup("kd"))) ||
		(!(t->tokens[T_REFRACTION_INDEX] = ft_strdup("ior"))) ||
		(!(t->tokens[T_REFLECTION] = ft_strdup("reflection"))) ||
		(!(t->tokens[T_SPECULAR_EXPONENT] = ft_strdup("specular exponent"))) ||
		(!(t->tokens[T_SPECULAR_COEF] = ft_strdup("ks"))) ||
		(!(t->tokens[T_TRANSPARENCY] = ft_strdup("transparency"))) ||
		(!(t->tokens[T_FOV] = ft_strdup("fov"))) ||
		(!(t->tokens[T_INTENSITY] = ft_strdup("intensity"))) ||
		(!(t->tokens[T_FILTER] = ft_strdup("filter"))) ||
		(!(t->tokens[T_READ_NORMAL_MAP] = ft_strdup("normal map"))) ||
		(!(t->tokens[T_READ_TEXTURE_FILE] = ft_strdup("texture"))))
		ft_errno_exit();
	init_tokens3(t);
}

static void	init_tokens3(t_parse_tools *t)
{
	if ((!(t->tokens[T_READ_MATERIAL_FILE] =
			ft_strdup("read material file"))) ||
		(!(t->tokens[T_PARENT_INDEX] =
			ft_strdup("parent index"))) ||
		(!(t->tokens[T_BEER_LAMBERT] = ft_strdup("beer lambert"))) ||
		(!(t->tokens[T_HASHTAG] = ft_strdup("#"))) ||
		(!(t->tokens[T_INVALID_TOKEN] = ft_strdup("invalid token"))))
		ft_errno_exit();
	t->tokens[T_COUNT] = NULL;
}
