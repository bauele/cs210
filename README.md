# CS-210 Programming Languages
Investment interest calculator written in C++.

<img  src="http://data.bauele.com/cs210-project-two.png" width="650" />

**Summarize the project and what problem it was solving.**

This project calculates the amount of interest that will be accrued in an account based on the supplied term, interest rate, and additional monthly funds. The program will compare the difference in balances based on the entered additional monthly funds, as well as the balances if there was no extra money added. This allows a user to quickly see the results of their investment strategy.

**What did you do particularly well?**

I am happy with the presentation of this program. Specifically, I enjoyed working to make the input menu more "dynamic" in terms of allowing the user to scroll through the available fields. I wanted to avoid prompting the user for specific pieces of information the way beginner C++ programs typically do. 

**Where could you enhance your code? How would these improvements make your code more efficient, secure, and so on?**

As it stands, I believe this program will not work under any other operating systems besides Windows. The reason is because I used the system("CLS") command in order to clear the screen. To make this program more efficient and more compatible, I would add some additional logic to detect which operating system the user is running on and call an appropriate command to clear the terminal window.

***Which pieces of the code did you find most challenging to write, and how did you overcome this? What tools or resources are you adding to your support network?**

I actually found the user input menu the hardest part to write. I designed the Menu class to hold all of the fields the user would be entering values for. However, I also created a Field class in order to contain the logic for these fields. From main, I called menu.addField() in order to add new Field objects to the menu, but by doing this way I did not have access to the values of the menu fields from within main. My way of solving this was to pass in variables from main as references within each field, so that any changes made in the menu's fields would modify the variables declared in main. I was then able to pass these user-supplied values to the report functions. To assist me with writing all of my code for this project, I made heavy use of C++ documentation.

**What skills from this project will be particularly transferable to other projects or course work?***

I think that my experience breaking down this program into small, modular steps will benefit me going forward in my other projects.

**How did you make this program maintainable, readable, and adaptable?**

I made sure to use descriptive names for my file names, function names, and variable names. I also made sure to use comments where necessary to explain what my code is doing and why I chose to do it as such.
