# Smart Parking System: training and testing data

The program has no machine-learning step, so the data are input scripts for the console menu.
Each case has `NAME.in` (keystrokes fed to the program) and `NAME.out` (what the program printed
when run, compiled with g++).

- training_data/ : 10 sample sessions used while building and debugging (normal use).
- testing_data/  : 16 cases for checking behaviour: boundary, invalid input and bug cases.
- manifest.csv   : description and correct behaviour for every case; the last column says
                   whether the CURRENT code gives that behaviour (PASS) or not (KNOWN BUG).
- run_tests.sh   : compile your code, then `./run_tests.sh ./your_program`.
                   It checks the program still prints exactly what is saved in the .out files.

Run one case by hand:  ./your_program < testing_data/te13_negative_hours.in
