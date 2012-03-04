#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include "hiredis/hiredis.h"
#include "hiredis/adapters/libevent.h"

int main()
{
	printf("Redis Connect Start\n");

	redisContext *c = redisConnect("127.0.0.1", 6379);
	redisReply *reply;

	if(c->err) {
		printf("Error: %s\n", c->errstr);
	}

	reply = redisCommand(c, "SET foo bar");
	printf("SET:%s\n", reply->str);
	freeReplyObject(reply);
	
	redisFree(c);
	return 0;
}
