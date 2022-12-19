// SqliteExterno.cpp : Este archivo contiene la función "main". La ejecución del programa comienza y termina ahí.
//

#include <iostream>
#include <sqlite3.h>

int main()
{
    sqlite3* db;
    char* zErrMsg = 0;
    int rc;

    rc = sqlite3_open("test.db", &db);

    if (rc) {
        std::cout << "Error opening SQLite3 database: " << sqlite3_errmsg(db) << std::endl;
        sqlite3_close(db);
        return 1;
    }

    std::cout << "Opened database successfully" << std::endl;

    sqlite3_close(db);
    return 0;
}

