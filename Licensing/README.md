# Licening of software

## Check application's LICENSE before using
Most Linux applications are free and open-source, but always verify the license for commercial use.
To check whether an application is free to use in Linux:

- Check the package manager:
Use commands like apt show <package>, dnf info <package>, or pacman -Qi <package> to view license info.

- Look for license files:
Check /usr/share/doc/<package>/ or the application's source directory for files named LICENSE, COPYING, or similar.

- Visit the official website or repository:
Most open-source Linux apps display their license and usage terms.

- Check the application's documentation:
Manuals or README files often mention if the app is free.

- Search online:
Forums and Linux communities can confirm if an app is free to use.

## Copyright and copyleft

### Copyright: 
- Grants exclusive rights:
Copyright automatically gives creators control over their original works, including the right to reproduce, distribute, and create derivative works. 

- Restricts use:
Copyright holders can choose to restrict access, modification, and distribution of their work, often through licensing agreements. 

- Focus on individual control:
Copyright primarily benefits the creator by giving them sole authority over their creation. 

### Copyleft:
- Uses copyright to promote freedom:
Copyleft leverages copyright law to ensure that a work remains free for anyone to use, modify, and distribute. 

- Requires reciprocal sharing:
Any modifications or derivative works created under a copyleft license must also be licensed under the same copyleft terms, ensuring the freedoms are preserved for future users. 

- Focus on community and collaboration:
Copyleft promotes a collaborative environment where users can freely build upon each other's work, fostering innovation and widespread access. 

## Experience
Check that the licenses are free software licenses (some free licenses may be missing from there, but most free software packages use one of these licenses), and that the package has complete source code available. You can check the license by downloading the source code. For the GNU licenses and some other licenses, there should be a copy of the license itself distributed along with the software; not complying with this requisite doesn't makes the program proprietary; but it's a sign that the developer is sloppy about licensing and he may unintentionally have included proprietary dependencies or failed to unambiguously make his program free software. It must be clear which license apply to each file. Just including the license in the source distribution without further licensing information leaves uncertain whether the license applies to the program, and hence it can not be considered free software (See the GNU GPL FAQ).

Check the section How to Apply These Terms to Your New Programs in the GNU General Public License. These are guidelines, though. It's not a necessary condition to follow these guidelines in order for a program to be free software, but it's a sufficient condition provided that entire package is under that license, and that source code is included.

Some software packages have no license, and that makes them proprietary (See the GNU GPL FAQ § No License). If you find software like this that would be useful in a fully free system, consider writing to the author to make him aware that because of the lack of license, his software is proprietary (despite that he may have intended otherwise), and ask him to make it free software (preferentially under the GNU GPL). This is almost always due to indolence of the author, specifically, a disliking for Copyright law coupled with the erroneous belief that ignoring it will make it not apply.

Note that sometimes there is object code in the form of human readable programming language code. Notably, this is the case with Linux, but I don't know of any other package doing the same.

Apart from being fully free itself, you should make sure that the program doesn't has mandatory proprietary dependencies but this not necessary to do explicitly if you have checked that the package itself is free and you have no proprietary software installed (you would notice if that was the case because the package will not compile or will not run properly).
### The list of license in GNU project
https://www.gnu.org/licenses/license-list.html