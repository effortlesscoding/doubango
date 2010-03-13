/*
* Copyright (C) 2009 Mamadou Diop.
*
* Contact: Mamadou Diop <diopmamadou@yahoo.fr>
*	
* This file is part of Open Source Doubango Framework.
*
* DOUBANGO is free software: you can redistribute it and/or modify
* it under the terms of the GNU General Public License as published by
* the Free Software Foundation, either version 3 of the License, or
* (at your option) any later version.
*	
* DOUBANGO is distributed in the hope that it will be useful,
* but WITHOUT ANY WARRANTY; without even the implied warranty of
* MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
* GNU General Public License for more details.
*	
* You should have received a copy of the GNU General Public License
* along with DOUBANGO.
*
*/

/**@file tsip_header_P_Associated_URI.h
 * @brief SIP header 'P-Associated-URI'.
 *
 * @author Mamadou Diop <diopmamadou(at)yahoo.fr>
 *
 * @date Created: Sat Nov 8 16:54:58 2009 mdiop
 */
#ifndef _TSIP_HEADER_P_ASSOCIATED_URI_H_
#define _TSIP_HEADER_P_ASSOCIATED_URI_H_

#include "tinySIP_config.h"
#include "tinySIP/headers/tsip_header.h"

#include "tinySIP/tsip_uri.h"

TSIP_BEGIN_DECLS

/**@def TSIP_HEADER_P_ASSOCIATED_URI_CREATE
* Creates new sip 'P-Associated-URI' header.  You must call @ref TSK_OBJECT_SAFE_FREE to free the header.
* @sa TSK_OBJECT_SAFE_FREE.
*/
#define TSIP_HEADER_P_ASSOCIATED_URI_VA_ARGS(uri)		tsip_header_P_Associated_URI_def_t, (const tsip_uri_t*)uri
#define TSIP_HEADER_P_ASSOCIATED_URI_CREATE(uri)		tsk_object_new(TSIP_HEADER_P_ASSOCIATED_URI_VA_ARGS(uri))
#define TSIP_HEADER_P_ASSOCIATED_URI_CREATE_NULL()		TSIP_HEADER_P_ASSOCIATED_URI_CREATE(0)

////////////////////////////////////////////////////////////////////////////////////////////////////
/// @struct	
///
/// @brief	SIP header 'P-Associated-URI' as per RFC 3455.
/// @author	Mamadou
/// @date	12/3/2009
///
/// @par ABNF: P-Associated-URI	= 	"P-Associated-URI" HCOLON p-aso-uri-spec *(COMMA p-aso-uri-spec)
/// p-aso-uri-spec	= 	name-addr *( SEMI ai-param )
/// ai-param	= 	generic-param
/// 	
////////////////////////////////////////////////////////////////////////////////////////////////////
typedef struct tsip_header_P_Associated_URI_s
{	
	TSIP_DECLARE_HEADER;

	char *display_name;
	tsip_uri_t *uri;
}
tsip_header_P_Associated_URI_t;

typedef tsk_list_t tsip_header_P_Associated_URIs_L_t;

tsip_header_P_Associated_URIs_L_t *tsip_header_P_Associated_URI_parse(const char *data, size_t size);

TINYSIP_GEXTERN const void *tsip_header_P_Associated_URI_def_t;

TSIP_END_DECLS

#endif /* _TSIP_HEADER_P_ASSOCIATED_URI_H_ */

