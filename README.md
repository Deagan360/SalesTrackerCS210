# SalesTrackerCS210

# Sales tracker program with C++ and Python

# Summary
This program opens to a menu with C++ with 4 options:
  1: check all sales
  2: check sales of a specific item
  3: create a histogram of all sales
  4: exit program
Option 1 calls Python function to display each item sold and the number of times that item has sold
option 2 asks for which item you would like to check, calls python with item as string parameter and returns how many times that item has sold
  if the item is not listed, it tells you item has not yet sold
option 3 calls python function to create a .dat file which will be read in C++ to display a histogram of all items sold

Journal:

What did you do particularly well?
  I feel as though I did a good job reading input from the file and iterating though the data to display the results properly thoughout the project. With this program
  I had to read through multiple files, write to a file, and iterate through the data several times. Doing this efficiently and not missing any data while still not
  running any iteration twice or messing up with blank space is a challenge I feel I accomplished correctly. 
  
Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?
  One opportunity that I see with my program is how I coded the user input validation. I hardcoded it into the loop to ensure it was proper. Instead I could have used
  try-catch blocks making the code more professional. This could also have made the code more secure because even with me not being able to break my code, someone else
  might and there isn't any proper exception handling. 
  
Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?
  The piece of code I had the most trouble with was the histogram. When reading the "frequency.dat" file I initially ended each line with a "\n" character. When I was
  entering the while(!eof) loop it would get stuck at the newline and run the last cout twice. It took me a while to figure out why that was happening. I ended up
  putting the newline character at the beginning of each instead. I now know to pay more attention to blank space in files.
  
What skills from this project will be particularly transferable to other projects or course work?
  I feel like I am in a position where any experience I can get and challenge I can conquer will benefit me. Learning more and finding new ways to accomplish whatever
  tasks are thrown at me will give me more confidence in my craft and widen my skills. Being able to practice input/output, accessing/writing to files, creating
  functions, in;ut validation, etc. will get me closer to acheiving my goal of entering a new career.
  
How did you make this program maintainable, readable, and adaptable?
  Making a program maintainable, readable, and adaptable is something that requires multiple habits. For one thing you have to have varaiable and function names that 
  describe what they are used for without being too long making it more difficult to read and follow. Following industry standards with lower case and upper case letters
  in variable and function names is also important because it makes the different things easier to identify. Another way to keep a code maintainable and adaptable is
  having plenty of comments that express what the code is doing properly and using comments to block off different sections of the code desribing what the next section
  will accomplish. 
