# atm_application

Description :   
This ATM application for beginners includes some added features in addition to performing standard ATM transactions.<br /> 
Dynamic memory allocation is something I just recently learnt about, therefore I used it in my application.<br />                                           Dynamic memory helps to allocate memory at run-time.<br />
It took me a while to find a way to insert each transaction successfuly in the dynamic array. I finally did it by declaring a dynamic variable and incrementing it at the end of case in switch statement and using the same variable to specify index of dynamic array.<br />
In future hopefully, I would like to add a check for characters while selecting the option from the main-menu. <br />

Run project : <br />

VISUAL STUDIO CODE:

1. CLONE:
    1. Open visual studio code
    2. Command + shift + p (Mac users)
    3. Select Git: Clone
    4. Copy and paste: https://github.com/Tushardeep-Singh/atm_application
    5. Press enter and open the clone’d project
2. CONFIGURE:
    1. Enter main.cpp
    2. Terminal -> Configure Tasks… -> C/C++: clang++ build active file
    3.  tasks.json gets created
    4. Add at top of array args:

 	      "-std=c++17",       
        "-stdlib=libc++",

	5. Replace "${file}" with "*.cpp"

3. BUILD:
    1. Enter main.cpp
    2. Terminal -> Run Build Task… -> C/C++: clang++ build active file
    3. Build finished successfully.
4. COMPILATION:
    1. Click in terminal area and press any key
    2. Type ./main and press enter.


Usage : <br />
1. Select any one option from main-menu. There is no check for a character input.!! <br />
2. All the options are self explainatory. <br />
3. There are many different checks implemented, so be sure to play around. <br />
4. A transaction summary will be printed out when exited.

Checks : <br />
1. There is a transaction limit of 4 executions of deposit, withdrawl per program execution. <br /> <br />
  Deposit : <br />
  1. A minimum deposit amount has been set to 1$. <br />
  2. A maximum deposit amount has been set to 50,000$. <br />
  3. Bank account can not hold more than 100,000$. <br /> <br />
  Withdraw : <br />
  1. A minimum withdrawl limit has been set to 50$.
  2. A maximum withdrawl limit has been set to 2,000$.
 
 
Credits : <br />
This project idea was taken from : https://www.youtube.com/watch?v=wccZgjs90S8  <br />
I have implemented a lot more things as compared to the one shown in the youtube video. <br />

I hope you like my effort.<br />
Thankyou..<br />
  

