#ifndef _SQL_
#define _SQL_

#include <iostream>
#include <string>
#include "mysql.h"
#include <string.h>
#include <stdlib.h>


class sqlApi{
	public:
		sqlApi(const std::string &_h,\
				const int &_port,\
    			const std::string &_u,\
    			const std::string &_p,\
                const std::string &_db);
		int connect();
        int insert(const std::string &_player_name,\
        		   const std::string &_game_name,\
        		   const std::string  &_play_age,\
                   const std::string &_pay_money);
		int select();
		~sqlApi();
	private:
		MYSQL *conn;
		sqlApi();
		MYSQL_RES *res;
		std::string host;
		std::string user;
		std::string passwd;
		std::string db;
		int port;
};


#endif
