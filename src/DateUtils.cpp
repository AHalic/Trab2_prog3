/**
 *  DateUtils.cpp
 *  Utility functions for date manipulation.
 *
 *  @author Vítor E. Silva Souza (vitorsouza@gmail.com)
 *  @since Jul 9, 2014
**/

#include <iostream>
#include "../include/DateUtils.h"

using namespace std;

/* Maximum size of the string buffer used to format dates. */
#define DATE_SIZE 11

namespace cpp_util {

    /* Converts dates in human-readable format to machine-processable format for storing in objects. */
    time_t parseDate(const string& str) {
        // Creates an empty calendar.
        struct tm calendar = { 0, 0, 0, 0, 0, 0, 0, 0, 0 };

        // Fills the calendar fields (year, month, day, etc.) based on the date string following the given format.
        strptime(str.c_str(), "%d/%m/%Y", &calendar);

        // Creates a time_t, machine-friendly date value from the calendar and returns.
        time_t t = mktime(&calendar);
        return t;
    }

    /* Converts dates in machine-processable format to human-readable format for printing. */
    string formatDate(const time_t& t) {
        // Creates a calendar structure from the machine-friendly time value.
        struct tm *tm = localtime(&t);

        // Writes in a string buffer the date from the calendar following the given format.
        char buffer[DATE_SIZE];
        strftime(buffer, DATE_SIZE, "%d/%m/%Y", tm);

        // Returns the buffer, which gets copied to the receiving string via copy constructor or assignment operator.
        return buffer;
    }

    bool validDate(const string& str) {
        struct tm tm;
        return strptime(str.c_str(), "%d/%m/%Y", &tm);
    }

}