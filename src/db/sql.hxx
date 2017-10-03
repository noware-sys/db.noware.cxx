#pragma once
/*
//#ifndef __MEMORY
//#define __MEMORY

//#include <cstdarg>
#include <string>
//#include <stdio.h>
// #include <sqlite3.h>

#include "../../value.h++"
#include "../../mathematics.h++"
#include "../../container/array.h++"
#include "../../container/variable.h++"
//#include "../../containers/entity.h++"
//#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
//#include "../../cluster/machine.h++"
//#include "../resource.h++"
*/
#include "../../name.h++"
#include ".sql/preindex.h++"

// Custom SQLite.
//#include "sqlite.h"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

namespace LIB
{
	namespace container
	{
		namespace db
		{
			class sql
			{
				public:
					#include ".sql/index.h++"
					
					//sql (void);
					//~ sql (void);
				public:
					#include ".sql/postinnerindex.h++"
			};
		}
	}
	
	//namespace database = container::database;
}

#include ".sql/postindex.h++"

