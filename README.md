# Epoch-Time-Conversion-difference
Date Time Difference Calculator
A C program that calculates the precise time difference between two user-input dates. The program converts dates to epoch time and displays the difference in multiple formats including days, hours, minutes, and seconds.
It can be usefull for daily-life problem solving, for example:
* Time Tracking for Work or Study Sessions
* Age Calculation
## 🚀 Features

Calculate time difference between any two dates after 1970 (Unix epoch)
Input validation for date and time components
Display results in both local time and epoch time formats
Break down time differences into days, hours, minutes, and seconds
Error handling for invalid date inputs

## 🚀 Requirements

* C compiler (GCC recommended)
* Standard C libraries:
  * `stdio.h`
  * `stdlib.h`
  * `time.h`
## 🚀 Program Structure

* `struct`: Stores date and time components
* `union`: Provides flexibility to store either DateTime or epoch time
* `mktime()`: Converts DateTime to epoch time
* `difftime()`: calculates the difference between the two dates
* `main()`: Handles user input and program flow

## 🚀 Error Handling
* The program includes basic error handling:
  * Validates input ranges for date/time components
  * Checks for conversion errors when converting to epoch time
  * Returns appropriate error messages for invalid inputs
## 🚀 Limitations
* Only handles dates from January 1, 1970 onwards (Unix epoch limitation)
* Does not handle timezone conversions
* Basic input validation (does not check for invalid dates like February 30th)
