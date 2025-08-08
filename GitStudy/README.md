## Git Config 

## Git index.lock
fatal: Unable to create '.git/index.lock': File exists.
whenever you run a git process, git creates an index.lock file within the .git directory. For example, if you run the command git add . to stage all local changes within your current repository, git will create this index.lock file while the git add command is running:
Upon successful completion of the git add process, the index.lock file is removed. What this does is ensure that simultaneous changes to your local git repo do not occur, as this would cause your git repo to be in an indeterminate state. 
is essentially telling you, "Hey, a git process is running in this git repo—you will have to wait to run the command you are attempting to run." However, it may be that there is no git process running! Sometimes, for whatever reason, a git process will not end gracefully. There are a number of reasons why this would happen. In this case, you can resolve the problem simply by removing the index.lock file manually via this command or a similar command on your operating system: rm .git/index.lock.

Git alias
Git hook

## Q&A and ever encountered troubles
### Why HTTP is recommended to clone reporsitory instead of SSH
HPPTS is recommended by the most significant reason is the setting of SSH is more complicated than that of HTTPS, of course.

The majority of people who advocate SSH say it is much more convenient compare to SSH, password less is the point. According to [Do you clone Git repos via HTTPS or SSH?](https://dev.to/lostintangent/do-you-clone-git-repos-via-https-or-ssh-3gp2). SSH also offer signed commit which guarantee that only permitted people can contribute to the repo.

According to a question on Github community [Bandwidth difference between HTTPS and SSH cloning #22844](https://github.com/orgs/community/discussions/22844). The question is about why cloning repositories by HTTPS is much slower than SSH. However some guys from China say the opposit - SSH is slower. The answer is the speed can vary, there is no certain relation between speed and protocol.

An conclusion found in [SSH vs. HTTPS: which is better?](https://graphite.dev/guides/git-clone-ssh-vs-https):
Choosing between SSH and HTTPS depends on your workflow requirements and setup preferences:
* Choose SSH if:
   -  You want secure, password-free operations.
   -  You have access to set up SSH keys on the repository host.

* Choose HTTPS if:
   - You want a straightforward setup without generating keys.
   - You’re working in environments that block SSH traffic (e.g., corporate networks with firewalls).
