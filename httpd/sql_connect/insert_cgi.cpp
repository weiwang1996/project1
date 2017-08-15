#include "sql_api.h"

using namespace std;

void insertToDb(const char *string_arg)
{
	char arg_buff[1024];
	//name="a"&sem="man"&age="12"&hobby="sleeping"&school="SUST"
	char *myargv[6];
	strcpy(arg_buff, string_arg);
	char *start = arg_buff;
	int i = 0;
	while(*start){
		if(*start == '='){
			start++;
			myargv[i++] = start;
			continue;
		}
		if(*start == '&'){
			*start=0;
		}
		start++;
	
    }
    cout<<"enter!!!!"<<endl;
	myargv[i] = NULL;
    sqlApi mydb("127.0.0.1",3306,"root","123456","game");
	mydb.connect();
mydb.insert(myargv[0], myargv[1], myargv[2], myargv[3]);
    //mydb.insert("zhangsan","man", "18", "play&coding", "qinghua");
}

int main()
{
	char *method = NULL;
	char *query_string = NULL;
	char *string_arg = NULL;
	int content_len = -1;
	char buf[1024];
	if((method=getenv("METHOD"))){
		if(strcasecmp(method, "GET") == 0){
			if((query_string=getenv("QUERY_STRING"))){
				string_arg = query_string;
			}
		}else{
			if(getenv("CONTENT_LENGTH")){
				content_len = atoi(getenv("CONTENT_LENGTH"));
				int i = 0;
				for(; i < content_len; i++){
					read(0, &buf[i], 1);
				}
				buf[i] = '\0';
				string_arg = buf;
			}
		}
	}
    cout<<"i  am reading\n";
	insertToDb(string_arg);
	return 0;
}
