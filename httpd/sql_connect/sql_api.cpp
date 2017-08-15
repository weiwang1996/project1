#include "sql_api.h"

using namespace std;

sqlApi::sqlApi(const std::string &_h="127.0.0.1",\
			   const int &_port=3306,\
			   const std::string &_u="root",\
			   const std::string &_p="",\
			   const std::string &_db="game")
{
	host = _h;
	user = _u;
	passwd = _p;
	db = _db;
	port = _port;
	res = NULL;
	conn = mysql_init(NULL);
    cout<<"gouzaohanshu"<<endl;
}

int sqlApi::connect()
{
    cout<<"hehehehh\n";
	if(mysql_real_connect(conn, host.c_str(), user.c_str(), "123456",\
				db.c_str(), port, NULL, 0)){
		cout<<"connect success!"<<endl;
	}else{
		cout<<"connect error!"<<endl;
	}
}

//player_name game_name play_age pay_money
int sqlApi::insert(const std::string &_player_name,\
		   const std::string &_game_name,\
		   const std::string  &_play_age,\
		   const std::string &_pay_money)
{
	std::string sql = "INSERT INTO player_tbl (player_name,game_name,play_age,pay_money) VALUES ('";
	sql += _player_name;
	sql += "','";
	sql += _game_name;
	sql += "','";
	sql += _play_age;
	sql += "','";
	sql += _pay_money;
	sql += "')";

	cout<<sql<<endl;
	int ret = mysql_query(conn, sql.c_str());
	if(ret != 0){
		cout<<"insert error!"<<endl;
	}
}

int sqlApi::select()
{
	std::string sql = "select * from player_tbl";
	if(mysql_query(conn, sql.c_str()) == 0){
		res = mysql_store_result(conn);
		if(res){
			int nums = mysql_num_rows(res);
			int col  = mysql_num_fields(res);
			cout<<"nums: "<<nums<<" col: "<<col<<endl;
		    MYSQL_FIELD *fd;
		    for(; fd = mysql_fetch_field(res); ){
		    	cout<<fd->name<<" ";
		    }

		    cout<<endl;

		    int i = 0;
		    int j = 0;
			for(; i < nums; i++){
				MYSQL_ROW row_res = mysql_fetch_row(res);
				j = 0;
				for(; j < col; j++){
					cout<<row_res[j]<<"   ";
				}
				cout<<endl;
			}
			cout<<endl;
		}
	}

}


sqlApi::~sqlApi()
{
	mysql_close(conn);
}













