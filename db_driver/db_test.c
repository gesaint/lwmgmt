#include <bson.h>
#include <bcon.h>
#include <mongoc.h>

int main (int argc, char *argv[])
{
   mongoc_client_t      *client;
   mongoc_database_t    *database;
   mongoc_collection_t  *collection;
   bson_t               *command,
                         reply,
                        *insert;
   bson_error_t          error;
   char                 *str;
   bool                  retval;
   /*
    * Required to initialize libmongoc's internals
    */
   mongoc_init ();//初始化libmongoc驱动
   /*
    * Create a new client instance
    */
   client = mongoc_client_new ("mongodb://localhost:27017");//创建连接对象
   /*
    * Get a handle on the database "db_name" and collection "coll_name"
    */
   database = mongoc_client_get_database (client, "db_name");//获取数据库
   collection = mongoc_client_get_collection (client, "db_name", "coll_name");//获取指定数据库和集合
   /*
    * Do work. This example pings the database, prints the result as JSON and
    * performs an insert
    */
   command = BCON_NEW ("ping", BCON_INT32 (1));
   retval = mongoc_client_command_simple (client, "admin", command, NULL, &reply, &error);//执行命令
   if (!retval) {
      fprintf (stderr, "%s\n", error.message);
      return EXIT_FAILURE;
   }
   str = bson_as_json (&reply, NULL);
   printf ("%s\n", str);
   insert = BCON_NEW ("hello", BCON_UTF8 ("world"));//字段为hello，值为world字符串
   if (!mongoc_collection_insert (collection, MONGOC_INSERT_NONE, insert, NULL, &error)) {//插入文档
      fprintf (stderr, "%s\n", error.message);
   }
   bson_destroy (insert);
   bson_destroy (&reply);
   bson_destroy (command);
   bson_free (str);
   /*
    * Release our handles and clean up libmongoc
    */
   mongoc_collection_destroy (collection);//释放表对象
   mongoc_database_destroy (database);//释放数据库对象
   mongoc_client_destroy (client);//释放连接对象
   mongoc_cleanup ();//释放libmongoc驱动
   return 0;
}
