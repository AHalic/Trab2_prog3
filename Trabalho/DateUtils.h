/**
 *  DateUtils.h
 *  Utility functions for date manipulation.
 *
 *  @author Vítor E. Silva Souza (vitorsouza@gmail.com)
 *  @since Jul 9, 2014
**/

#ifndef DATEUTILS_H
#define DATEUTILS_H

#include <ctime>
#include <string>

namespace cpp_util {

    using namespace std;

    /* Converts dates in human-readable format to machine-processable format for storing in objects. */
    time_t parseDate(const string& str);

    /* Converts dates in machine-processable format to human-readable format for printing. */
    string formatDate(const time_t& t);

    /* Verifies if a string contains a valid date according to a format. */
    bool validDate(const string& str);

}
#endif