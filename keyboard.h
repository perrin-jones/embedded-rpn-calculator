#ifndef _KEYBOARD_H
#  define KEYBOARD_H

// Maximum value an integer can hold
#  define INT_MAX 2147483647

struct entry {
  char operation; /* Operation, e.g., '+' */
  int number; /* Entered number; INT_MAX if none */
};

/* Keyboard Layout

   Rows and columns on HP 20b schematic are reversed from what you'd expect

   Columns are outputs; rows are read

            Row0  Row1  Row2 Row3 Row4 Row5
            PC11  PC12  PC13 PC14 PC15 PC26

Col0  PC0     N   I/YR  PV   PMT   FV  Amort
Col1  PC1   CshFI  IRR  NPV  Bond  %    RCL
Col2  PC2   INPUT   (    )   +/-   <-
Col3  PC3    UP     7    8    9    /                             
Col4  PC4   DOWN    4    5    6    *                                
Col5  PC5   SHIFT   1    2    3    -                             
Col6  PC6           0    .    =    +         

  ON/CE is separate
 */

// Initialize the keyboard and set all columns high with pullups on the rows
extern void keyboard_init(void);

// Set the given column high
extern void keyboard_column_high(int column);

// Set the given column low
extern void keyboard_column_low(int column);

// Return true if the row is high, false otherwise
extern int keyboard_row_read(int row);

// Return a character indicating which key was pressed or 0
// See keyboard.c for which character is returned by each key
extern int keyboard_key(void);

// Get a number and command from the keyboard
extern void keyboard_get_entry(struct entry *);

#endif
