# Use of grep command

## Grep a pattern in a forder recursively
grep -nr 'yourString*' .
-n            Show relative line number in the file
'yourString*' String for search, followed by a wildcard character
-r            Recursively search subdirectories listed
.             Directory for search (current directory)

Example:
```
pi@raspberrypi:~/workspace/PythonLesson $ grep -nr 'thread' L09-16/Lesson14_MutithreadingAndMultiprocessing/
L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex1_ThreadingIntro.py:1:import threading
L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex1_ThreadingIntro.py:2:from threading import Thread
L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex6.py:2:import threading
L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex6.py:8:        logging.debug("worker thread checking in")
L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex6.py:15:        format="%(relativeCreated)6d %(threadName)s %(message)s"
```

## grep a pattern in a file
Example: Match something
```
pi@raspberrypi:~/workspace/PythonLesson $ grep -n thread L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex1_ThreadingIntro.py
1:import threading
2:from threading import Thread

pi@raspberrypi:~/workspace/PythonLesson $ cat L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex1_ThreadingIntro.py | grep -n --color -i thread
1:import threading
2:from threading import Thread
7:    print("Thread 1 starts")
9:    print("Thread 1 ends")
13:    print("Thread 2 starts")
15:    print("Thread 2 ends")
18:thrd1 = Thread(target=thrd_1_Func)
19:thrd2 = Thread(target=thrd_2_Func)
26:Thread 1 starts
27:Thread 2 starts
28:Thread 2 ends
29:Thread 1 ends
32:Thread 1 starts
33:Thread 1 ends
34:Thread 2 starts
35:Thread 2 ends

pi@raspberrypi:~/workspace/PythonLesson $ cat L09-16/Lesson14_MutithreadingAndMultiprocessing/3_MultithreadingMultiprocessing/Ex1_ThreadingIntro.py | grep -n --color -i -c thread
16

pi@raspberrypi:~/workspace/new-folder $ cat sample_log.log 
Title 1
    Subtitle 1
    Contain 1: Somethings here

Title 2
    Subtitle 2
    Contain 2: Some more things here

pi@raspberrypi:~/workspace/new-folder $ grep -e "Title" -e "Contain" sample_log.log 
Title 1
    Contain 1: Somethings here
Title 2
    Contain 2: Some more things here

pi@raspberrypi:~/workspace/new-folder $ grep -v "Contain" sample_log.log 
Title 1
    Subtitle 1

Title 2
    Subtitle 2

```
Example:

grep and remove line

## Match one of pattern
grep -E 'patternx|patterny' input.txt
## grep a pattern from a pipe (other command's output)

search for folders/files' name 
Example 
```
pi@raspberrypi:~/workspace $ tree . | grep 'thread'
│   │   ├── Lesson14_MutithreadingAndMultiprocessing
│   │   │   ├── 3_MultithreadingMultiprocessing
│   │   │   │   └── threading.Condition(.py
    ├── threadtest.py
```


