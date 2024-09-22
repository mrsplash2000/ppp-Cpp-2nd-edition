# Programming, Principles And Practice Using C++ - 2nd Edition
This repository is dedicated for files and exercises for the book "Programming, Principles And Practice Using C++" written by "Bjarne Stroustrup". 
All rights of the contents and the exercises and drills belong to the original author of the book. This repository is not aiming to infringe copyright 
laws by any means, but rather providing solutions and helping the community reading the book and seeing different kinds of  solutions to a problem.

### How to use?

1. First thing to do is to cd into the directory you want to clone the files.
   For example on windows it would be something like this: 

```cd C:\Users\Sapphire\Documents\Projects\C++```

2. Now that you're in your desired directory, all you need to do is cloning the repo:

```git clone https://github.com/mrsplash2000/ppp-Cpp-2nd-edition.git```

3. When cloning, the entire folder appears and you can see the files in that folder. In
   order to push code or use any other commands, you need to cd into the directory you
   just cloned

```cd C:\Users\Sapphire\Documents\Projects\C++\ppp-Cpp-2nd-edition```

### Seeing other solutions and submitting your solutions
*  To see other people's solutions and files, you need to switch branches. To see the full
   list of branches, you can run this command

```git branch -a```

*  The main branch contains my files and solutions. When switching to other branches, files 
   and their contents may change entirely. This is what is expected as it allows us to see 
   different solutions. By default, you are always on the main branch. To switch to another
   branch, you can run this command (replace branchname with one of the branches available 
   from the above command):

```git checkout <branch>```

   After running this branch you can go to the files and see that they have changed entirely.

*  To submit your own solutions, you must create your own branch. To create your own branch,
   run this command (Set branchname with your desired name of your choice):

```git checkout -b <branchname>```

   This command creates your branch and then switches to that branch. In order to submit your
   solutions and files to the repository, you must first push your branch to the repository. To
   that, run this command (Set branchname with the name you gave to your branch previously):

```git push --set-upstream origin <branchname>```  

   After that, place your exercises files inside the directory called "Exercises(Your solutions)". 
   This directory by default is empty and when you put files in here, you are basically doing that 
   in your branch. First thing to do, make sure you are on your branch. To do that run this command:

```git branch```

   When you run this command, it shows your branch name in green with a * next to it. If you are on 
   your correct branch, then you are on the right track. If not, you must switch to the correct branch. 
   Do that with this command (Set correct-branchname with the branchname you set for yourself):

```git checkout <branchname>```

   After that, you have to add your files and commit them. to do that you must run these two commands 
   (Replace files with the path of your files. And replace MESSAGE with a meaningful message, saying 
   what you have added. For example: "Added exercises for chapter 5"):

```
git add <files>
git commit -m "MESSAGE"
```

   After all this, you must push your code. To push your code in your branch to the repository, you can
   do that by running this command: 

```git push```

   At this point, your files are pushed to your branch in the repo. You can even view and confirm it by
   going to the branches section and see that your branch is added along with the files. 
