## Git Config 

## Git index.lock
fatal: Unable to create '.git/index.lock': File exists.
whenever you run a git process, git creates an index.lock file within the .git directory. For example, if you run the command git add . to stage all local changes within your current repository, git will create this index.lock file while the git add command is running:
Upon successful completion of the git add process, the index.lock file is removed. What this does is ensure that simultaneous changes to your local git repo do not occur, as this would cause your git repo to be in an indeterminate state. 
is essentially telling you, "Hey, a git process is running in this git repo—you will have to wait to run the command you are attempting to run." However, it may be that there is no git process running! Sometimes, for whatever reason, a git process will not end gracefully. There are a number of reasons why this would happen. In this case, you can resolve the problem simply by removing the index.lock file manually via this command or a similar command on your operating system: rm .git/index.lock.