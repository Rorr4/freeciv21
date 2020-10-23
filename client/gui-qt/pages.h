/**************************************************************************
 Copyright (c) 1996-2020 Freeciv21 and Freeciv contributors. This file is
 part of Freeciv21. Freeciv21 is free software: you can redistribute it
 and/or modify it under the terms of the GNU  General Public License  as
 published by the Free Software Foundation, either version 3 of the
 License,  or (at your option) any later version. You should have received
 a copy of the GNU General Public License along with Freeciv21. If not,
 see https://www.gnu.org/licenses/.
**************************************************************************/

#ifndef FC__PAGES_H
#define FC__PAGES_H

struct connection;
struct player;
struct server_scan;

void create_conn_menu(player *, connection *);
void server_scan_error(server_scan *, const char *);

#endif /* FC__PAGES_H */
