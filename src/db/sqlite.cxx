#pragma once

#include "sqlite.hxx"

//#include "../../math.h++"
//#include "../var.cxx"
//#include "../array.cxx"

#include <string>
#include <map>
//#include <iostream>
//#include <assert.h>

//#include "../../../name.h++"
#include <noware/nr.cxx>

const unsigned short int noware::db::sqlite::tries_dft = 1;
//const noware::nr noware::db::sqlite::tries_dft = 1;

/*
noware::db::sqlite::sqlite (const std::string & name)
{
	_connected = false;
	
	//sqlite3_open (name.c_str (), & db);
	connect (name);
}
*/

noware::db::sqlite::sqlite (void)
{
	_connected = false;
}

noware::db::sqlite::~sqlite (void)
{
	//sqlite3_close (db);
	//while (connected ())
	//{
		disconnect ();
	//}
}

const bool noware::db::sqlite::connect (const std::string & name)
{
	if (connected () && !disconnect ())
	{
		return false;
	}
	else if (sqlite3_open (name.c_str (), & db) == SQLITE_OK)
	{
		_connected = true;
		
		return true;
	}
	else
	{
		return false;
	}
}

const bool noware::db::sqlite::disconnect (void)
{
	if (!connected ())
	{
		return true;
	}
	else if (sqlite3_close (db) == SQLITE_OK)
	{
		_connected = false;
		
		return true;
	}
	else
	{
		return false;
	}
}

const bool noware::db::sqlite::connected (void) const
{
	return _connected;
}
/*
const sqlite & noware::db::operator = (const sqlite & other)
{
	return *this;
}
*/
const bool noware::db::sqlite::operator == (const noware::db::sqlite & other) const
{
	return this == &other;
}

sqlite3 const * const noware::db::sqlite::operator * (void) const
{
	return db;
}

//const bool noware::db::sqlite::query (std::map <std::string, std::map <std::string, std::string>> & result, const std::string & qry, const std::map <int, std::string> & arguments, const noware::nr & tries_max)
const bool noware::db::sqlite::query (std::map <std::string, std::map <std::string, std::string>> & result, const std::string & qry, const std::map <int, std::string> & arguments, const unsigned int & tries_max)
{
	if (!connected ())
		return false;
	
	//noware::var val;
	//noware::nr::integer count;
	//
	//va_list argv;
	//va_start (argv, count);
	//
	//val = va_arg (argv, noware::var);
	//
	//va_end (argv);
	
	
	// Try to reset the counter representing the number of changed rows.
	/*
	if (sqlite3_mutex_held (db -> mutex) != 0)
	{
		std::cout << "Trying to reset the counter." << std::endl;
		db -> nChange = 0;
		std::cout << "effect (after resetting the counter) == [" << effect () << ']' << std::endl;
	}
	*/
	/*
	#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
		//std::cout << "effect (before resetting the counter) == [" << effect () << ']' << std::endl;
		//std::cout << "Trying to reset the counter." << std::endl;
		//sqlite3VdbeSetChanges (db, 0);
		effect (0);
		//std::cout << "effect (after resetting the counter) == [" << effect () << ']' << std::endl;
	#endif
	*/
	
	sqlite3_stmt * statement;
	char const * query_remainder;	// Placeholder. It should normally not be used.
	//sqlite3_value val;
	int result_code;
	
	//noware::nr column_count;
	int column_count;
	//int column;
	noware::nr column;
	
	noware::nr row;
	//int row;
	
	//noware::nr tries;
	int tries;
	
	//std::cout << "effect (before 'prepare ()') == [" << effect () << ']' << std::endl;
	
	if (sqlite3_prepare_v2 (db, qry.c_str (), qry.size (), &statement, &query_remainder) != SQLITE_OK)
	{
		sqlite3_finalize (statement);
		
		return false;
	}
	
	//std::cout << "effect (after 'prepare ()') == [" << effect () << ']' << std::endl;
	
	
	if (/*arguments != NULL && */!arguments.empty ())
	{
		//int i = 1;
		//for (const noware::array <noware::var, int>::container & argument : arguments)
		for (const std::pair <int, std::string> & argument : arguments)
		{
			//std::cout << "noware::db::sqlite::query()::i==[" << i << ']' << std::endl;
			
			//if (value.v.is_string ())
			//{
				//val = value.v;
				//sqlite3_bind_value (statement, value.k, & val);
				//if (argument.v.is_numeric ())
			/*
				std::cout << "\t\targument.k == [" << argument.k << "]" << std::endl;
				std::cout << "\t\targument.v == [" << argument.v << "]" << std::endl;
				if (argument.v.type () == noware::var::container::type::numeric)
				{
					std::cout << "argument.v.type () == noware::var::container::type::numeric" << std::endl;
					sqlite3_bind_double (statement, argument.k, argument.v);
				}
				else
				{
					std::cout << "argument.v.type () != noware::var::container::type::numeric" << std::endl;
			*/		//std::cout << "noware::db::sqlite::query()::argument.k==[" << argument.k << ']' << std::endl;
					// std::cout << "noware::db::sqlite::query()::argument.k.text()==[" << argument.k.text() << ']' << std::endl;
					//std::cout << "noware::db::sqlite::query()::argument.v==[" << argument.v << ']' << std::endl;
					//std::cout << "noware::db::sqlite::query()::argument.v.text()==[" << argument.v.text() << ']' << std::endl;
					
					//sqlite3_bind_text (statement, argument.k, argument.v.to_string ().c_str (), argument.v.to_string ().size (), SQLITE_STATIC);
			//		sqlite3_bind_text (statement, argument.k, argument.v.text ().c_str (), argument.v.text ().length (), SQLITE_TRANSIENT);
		//			sqlite3_bind_text (statement, argument.k, argument.v.c_str (), argument.v.length (), SQLITE_TRANSIENT);
						sqlite3_bind_text (statement, argument.first, argument.second.c_str (), argument.second.size (), SQLITE_TRANSIENT);
				//	sqlite3_bind_text (statement, i, argument.v.text ().c_str (), argument.v.text ().length (), SQLITE_TRANSIENT);
					//sqlite3_bind_text (statement, argument.k, argument.v.text ().c_str (), sizeof (argument.v.text ().c_str ()), SQLITE_STATIC);
					
					//sqlite3_bind_value (statement, argument.k, & argument.v);
			//	}
				/*
				std::cout << "\t\targument.k == " << argument.k << std::endl;
				std::cout << "\t\targument.v == " << argument.v << std::endl;
				std::cout << "\t\targument.v.to_string () == " << argument.v.to_string () << std::endl;
				std::cout << "\t\targument.v.to_string ().c_str () == " << argument.v.to_string ().c_str () << std::endl;
				std::cout << "\t\targument.v.to_string ().size () == " << argument.v.to_string ().size () << std::endl;
				*/
				//sqlite3_bind_text (statement, argument.k, argument.v.to_string ().c_str (), argument.v.to_string ().size (), SQLITE_STATIC);
				//sqlite3_bind_value (statement, argument.k, & argument.v);
			//}
			
			//++i;
		}
	}
	
	//if (result != NULL)
	//{
		column_count = sqlite3_column_count (statement);
		row = 1;
		tries = 1;
		// The next line is the fist try to evaluate the expression:
		// std::cout << "qry == (" << qry << ')' << std::endl;
		// std::cout << "column_count == " << column_count << std::endl;
		//std::cout << "effect (after 'column_count ()') == [" << effect () << ']' << std::endl;
		result_code = sqlite3_step (statement);
		//std::cout << "result_code == " << result_code << std::endl;
		//std::cout << "effect (after 'step ()') == [" << effect () << ']' << std::endl;
		while (result_code == SQLITE_ROW || (result_code == SQLITE_BUSY && tries_max <= 0) || (result_code == SQLITE_BUSY && tries < tries_max))
		{
			for (column = 0; column < column_count; ++column)
			{
				//result [row] [column + 1] = sqlite3_column_value (statement, /*(signed int) */column);
				
			//	result [row] [noware::nr (column + 1)] = sqlite3_column_text (statement, /*(signed int) */column);
				result [row.operator std::string const ()] [(column + 1).operator std::string const ()] = (char const *) sqlite3_column_text (statement, /*(signed int) */column);
				
				//result [noware::var (row)] [noware::var (column + 1)] = std::string ((char *) sqlite3_column_text (statement, /*(signed int) */column));
				//std::cout << "result [" << row << "] [" << column + 1 << "] == " << result [row] [column + 1] << std::endl;
			}
			
			if (result_code == SQLITE_ROW)
			{
				++row;
				tries = 1;
			}
			//else if (result_code == SQLITE_BUSY && tries_max > noware::nr::integer (0))
			else if (result_code == SQLITE_BUSY && tries_max > 0)
			{
				++tries;
			}
			
			result_code = sqlite3_step (statement);
			//std::cout << "effect (after 'step ()', subsequent) == [" << effect () << ']' << std::endl;
		}
	//}
	
	sqlite3_finalize (statement);
	//std::cout << "effect (after 'finalize ()') == [" << effect () << ']' << std::endl;
	
	return result_code == SQLITE_OK || result_code == SQLITE_DONE;
}

//const bool noware::db::sqlite::query (std::map <std::string, std::map <std::string, std::string>> & result, const std::string & qry, const noware::nr & tries_max)
const bool noware::db::sqlite::query (std::map <std::string, std::map <std::string, std::string>> & result, const std::string & qry, const unsigned int & tries_max)
{
	const std::map <int, std::string> arguments;
	
	return query (result, qry, arguments, tries_max);
}

//const bool noware::db::sqlite::query (const std::string & qry, const std::map <int, std::string> & arguments, const noware::nr & tries_max)
const bool noware::db::sqlite::query (const std::string & qry, const std::map <int, std::string> & arguments, const unsigned int & tries_max)
{
	std::map <std::string, std::map <std::string, std::string>> result;
	
	return query (result, qry, arguments, tries_max);
}

//const bool noware::db::sqlite::query (const std::string & qry, const noware::nr & tries_max)
const bool noware::db::sqlite::query (const std::string & qry, const unsigned int & tries_max)
{
	std::map <std::string, std::map <std::string, std::string>> result;
	std::map <int, std::string> arguments;
	
	return query (result, qry, arguments, tries_max);
}

/*
#if defined (SQLITE_CHANGES_SET) && SQLITE_CHANGES_SET
	const bool noware::db::sqlite::effect (const int & val)
	{
		sqlite3_changes_set (db, val);
		
		return true;
	}
#endif
*/
unsigned int const noware::db::sqlite::effect (void) const
{
	return sqlite3_changes (db);
}
