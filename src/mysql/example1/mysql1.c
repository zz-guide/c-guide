//
// Created by xulei on 2018/6/17.
//

#include "mysql1.h"

#include <stdio.h>
#include <string.h>
#include <mysql.h>

unsigned int port;
char *host;
char *user;
char *pwd;
char *dbname;

void TMysql()
{
    port = 3306;
    host = "127.0.0.1";
    user = "root";
    pwd = "xl123456?";
    dbname = "test";


    MYSQL mysql;
    MYSQL_RES *table_list;
    MYSQL_ROW table_row;

    mysql_init(&mysql);
    mysql_options(&mysql, MYSQL_SET_CHARSET_NAME, "utf8");
    mysql_real_connect(&mysql, host, user, pwd, dbname, port, NULL, 0);

    FILE *fp;
    fp = fopen("doc.md", "w+");


    char get_table_sql[300] = "select table_name,TABLE_COMMENT from INFORMATION_SCHEMA.TABLES where table_schema = \'";
    strcat (get_table_sql, dbname);
    strcat (get_table_sql, "\'");

    mysql_query(&mysql, get_table_sql);
    table_list = mysql_store_result(&mysql);

    while ((table_row = mysql_fetch_row (table_list))) {
        fprintf (fp, "\n## %s - %s\n\n", table_row[0], table_row[1]);
        char get_column_sql[300] = "";
        strcat (get_column_sql, "show full columns from ");
        strcat (get_column_sql, table_row[0]);

        MYSQL_RES *table_column;
        MYSQL_ROW column_row;

        printf ("%s\n", get_column_sql);
        mysql_query (&mysql, get_column_sql);
        table_column = mysql_store_result (&mysql);

        fprintf (fp, "字段名 | 类型 | 编码 | 是否为空 | key | 默认值 | Extra | 描述\n");
        fprintf (fp, "------ | ---- | ---- | -------- | --- | ------ | ----- | ----\n");
        while ((column_row = mysql_fetch_row (table_column))) {
            fprintf (fp, "%s | %s | %s | %s | %s | %s | %s | %s\n", column_row[0], column_row[1]
                    , column_row[2], column_row[3], column_row[4]
                    , column_row[5], column_row[6], column_row[8]);


            printf ("%s | %s | %s | %s | %s | %s | %s | %s\n", column_row[0], column_row[1]
                    , column_row[2], column_row[3], column_row[4]
                    , column_row[5], column_row[6], column_row[8]);
        }
        mysql_free_result (table_column);
    }
    fclose (fp);

    mysql_free_result (table_list);

    printf("文档生成成功！！！");
}