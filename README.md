De Anza College<BR>
Manish Goel<BR>
Fall 2017<BR>
CIS22C Data Abstract & Structures<BR>

# Instructions
This is a makeup lab - it will allow you to replace points of any one lab where you got a low score. Since not everyone, e.g. both partners in a HW team, will need the makeup lab, this one should be done and uploaded individually. In the comment block of the submission - clearly mention which lab's grade you want replaced. No comment, no grade.

Write a program to do the following:

1. Use the sample data file I provided for verifying the results of your BST homework (Lab 5) to enter data into a hash table.
2. Your hash table should have 10 entries
3. The birthday should be used as the hash key by adding the digits repeatedly until it ends up being a number between 0 and 9, which will be the index of the data in the hash table. So, today's date of 2017-12-04 will reduce as 2+0+1+7+1+2+0+4 = 17 which will further reduce as 1+7 = 8 and its associated data record (name + birthday) will be added to index 8 in the hash table.
4. For collision resolution, use quadratic probing.
5. Your main will first load the data file into the hash table and print the number of data items loaded, load factor and number of collisions. 
6. Then it will ask the user in a loop to enter a birthdate - any date. If the birthdate is found in the hash table, it will print the name associated with that date, otherwise it will print 'Invalid Data'. Then it will ask the user if they want to check again or end the program.
7. I will test your program with my own version of the data file which may exist in any folder on my machine.

To submit:
- Name all the necessary artifacts - projects, cpp file, zipfile, screenshots - as cis22c_lab6_\<yourname\>.\<file extension\>. Remember you need to replace text between < > appropriately.
- Upload only one zip file that contains everything including the full Visual Studio project files and exe.
- Remember to complete this lab SOLO.
- Also, remember to mention the lab whose score you wish to replace in the comment field. If there is no comment, this makeup will not be graded.
- There is only one submission deadline - before you come for the final.
- Since this is a makeup, this lab will be graded more strictly than usual.

# Outcome
Full Credit