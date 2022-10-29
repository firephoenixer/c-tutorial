# Git utility
In this file, it will record the utility of Git. 

If there is any mistake you found in this file, please feel free to set a pull request.

For details, please google.

Happy coding! Let's built tommorow together.

## How to show files under the local repository:
### Show local repository's status.
    git status

## How to add some files under watching:
### Add or track or change all files to commit:
    git add .

### Add or track or change  specified file to commit:
    git add <filename>

## How to comfirm changes to local repository.
    git commit -m "Title" -m "Content" :

## How to update the local changes to Github.
### Push to default repository.
    git push
### Push to specified repository/branch.
    git push origin <master>
set default push.
    git push -u origin <master>

## How to pull the changes of Github to local repository.
### Sometimes the Github's repository has changed, then you may need a sync. 
    git pull

## How to copy a new repository from Github to local.
    git clone "HTTPadd"

## Trun a new dir into a git repository.
    git init

## How to transit a new repository to Github at the first time.
You need create some name repository on Github first.
    git remote add origin "HTTPadd"
Check remote origin.
    git remote -v

## How to show branches in local.
    git branch

## How to create a new branch in local.
    git checkout -b <feature-12345-instruction>
    
## How to switch branches in local.
    git checkout <main>


## How to show the different of two branch in local.
    git diff <other-repository>
    
## How to merge branches in local.
But usually only useful when you are the master of the Github repository.
    git merge <object-name>

## How to push a change to branches to Github, if not exsited then create a new branch.
    git push -u origin <same-name>
Then you can apply a pull request on Github.

## How to delete a branch in local.
    git branch -d <name>

## If no new file created, how to add and commit in one line.
    git commit -am "title"

## If there is a conflict in merge, then you should deal the conflict in editer frist.

## How to reset "add" status.
    git reset

## How to reset a "commit" command.
    git reset HEAD~1

## Show command log.
    git log
Then we will get some history inclue hash code.

Press "q" quit the log file.

## How to return to history.
Return with "M" sign.(the changes keeped in editer)
    git reset <hash-code>
Return without "M" sign.(the changes won't keeped in editer)
    git reset --hard <hash-code>

## You can use fork on Github, then you will have full access of the repository.
When you finsh your local work, Then you can do PR to the original repository if you wish.
