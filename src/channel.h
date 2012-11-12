/*
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU Lesser General Public
 * License as published by the Free Software Foundation; either
 * version 2.1 of the License, or (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 * Lesser General Public License for more details.
 * 
 * You should have received a copy of the GNU Lesser General Public
 * License along with main.c; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor Boston, MA 02110-1301,  USA
 */

#ifndef __IRC_CHANNEL__
#define __IRC_CHANNEL__

typedef struct irc_channel_s
{
	int			pending;		/* fully joined? */
    uint8_t*	name;			/* name of the channel */
    uint8_t*    pass;           /* the channel password */
    uint8_t*    topic;          /* channel topic */
	uint8_t*	part_msg;		/* part message */
    /*int32_t     mode[MODE_WORDS];*//* mode flags */
    list_t*		clients;        /* list of clients in the channel */
	list_t*		join_msgs;		/* list of join messages */
} irc_channel_t;

irc_channel_t * irc_channel_new( uint8_t const * const name,
								 uint8_t const * const pass,
								 uint8_t const * const part_msg );
void irc_channel_delete( void * c );

uint8_t * irc_channel_get_name( irc_channel_t * const c );
uint8_t * irc_channel_get_topic( irc_channel_t * const c );

/* join and part channels */
irc_ret_t irc_channel_join( irc_channel_t * const c, irc_conn_t * const conn );
irc_ret_t irc_channel_part( irc_channel_t * const c, irc_conn_t * const conn );

#endif
