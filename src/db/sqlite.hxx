#pragma once
//#ifndef __MEMORY
//#define __MEMORY

//#include <cstdarg>
#include <string>
#include <map>
//#include <stdio.h>
#include <sqlite3.h>

//#include "../../../name.h++"
//#include "../../content/value.h++"
//#include "../../../math.h++"
//#include "../var.hxx"
//#include "../array.hxx"
//#include "../../containers/entity.h++"
//#include "../../communication/messaging.h++"
//#include "../network/peers.h++"
// #include "../../network/mpi.h++"
//#include "../network/ip.h++"
//#include "../threads.h++"
//#include "../../cluster/machine.h++"
//#include "../resource.h++"
//#include "../../../sqlite/3.h"
#include <noware/nr.hxx>

// Custom SQLite.
//#include "sqlite.h"

//typedef std::string value, key;

//#include "../../containers/entity-pre.h++"

//#include "sqlite.h++"
// #include "../../../mathematics.h++"

// #include <iostream>
// #include <assert.h>

namespace noware
{
	//namespace container
	//{
		namespace db
		{
			class sqlite
			{
				public:
					//sqlite (const std::string & = ":memory:");
					sqlite (void);
					//sqlite (const std::string &);
					~sqlite (void);
					
					const bool connect (const std::string &);
					const bool disconnect (void);
					// get the connected state
					const bool connected (void) const;
					
					//const bool query (std::map <std::string, std::map <std::string, std::string>> &/* result*/, const std::string &/* query*/, const std::map <int, std::string> &/* arguments*/, const noware::nr &/* tries_max*/ = tries_dft);
					const bool query (std::map <std::string, std::map <std::string, std::string>> &/* result*/, const std::string &/* query*/, const std::map <int, std::string> &/* arguments*/, const unsigned int &/* tries_max*/ = tries_dft);
					//const bool query (std::map <std::string, std::map <std::string, std::string>> &/* result*/, const std::string &/* query*/, const noware::nr &/* tries_max*/ = tries_dft);
					const bool query (std::map <std::string, std::map <std::string, std::string>> &/* result*/, const std::string &/* query*/, const unsigned int &/* tries_max*/ = tries_dft);
					//const bool query (const std::string &/* query*/, const std::map <int, std::string> &/* arguments*/, const noware::nr &/* tries_max*/ = tries_dft);
					const bool query (const std::string &/* query*/, const std::map <int, std::string> &/* arguments*/, const unsigned int &/* tries_max*/ = tries_dft);
					//const bool query (const std::string &/* query*/, const noware::nr &/* tries_max*/ = tries_dft);
					const bool query (const std::string &/* query*/, const unsigned int &/* tries_max*/ = tries_dft);
					
					//noware::nr const effect (void) const;	// Affected rows
					unsigned int const effect (void) const;	// Affected rows
					
					unsigned short int const static tries_dft;
					//noware::nr const static tries_dft;
					//math::nr::integer tries;
					
					//const sqlite & operator = (const sqlite &);
					bool const operator == (const sqlite &) const;
					sqlite3 const * const operator * (void) const;
				protected:
					//#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
					//	const bool effect/*_set*/ (const int &/* = 0*/);
					//#endif
					
					sqlite3 * db;
					//noware::methematics::nr::integer success;
					
					// set the connected state
					//const bool connected (const bool &/* new_value*/);
					bool _connected;
			};
		}
	//}
}
