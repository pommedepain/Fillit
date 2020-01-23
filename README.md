# Fillit

3rd C project for 42 school.

This programm will take a file as parameter, which contains a list of Tetriminos, and arrange them in order to create the smallest square possible.

(Group project carried out with @Clemzerdu75)

![GIF](./fillit.gif?raw=true "GIF")

# What is Fillit ?

<ul>
<li>Fillit is a programme that parse a file, check its validation and use backtracking to find the best solution possible to sort the data contained within.</li>

<li>The expected file needs to have a list of "tetriminos", separated by a white line. A tetriminos needs to have 4 lines of 4 characters. It can only contains "." and "#".</li>

<li>"." represents empty spaces.</li>

<li>"#" represents one block of tetrimino.</li>

<li>A tetrimino is a classic piece of Tetris composed of 4 blocks. Each block of a tetrimino needs to touch at least one side of another block ( up, down, left, right ).</li>

<li>The resulted grid is ordered by tetriminos apparition in the file. Amongst all the possibilities where tetriminos can be placed, the most upper-left position will always be favoured.</li>

<li>To visually identify tetriminos in the final square solution, a capital letter is assigned to each and every one of them, starting with an 'A' and increasing ( Following this logic, there cannot be more than 26 tetriminos ).</li>

<li>If a file is invalid the programm will return "error". If no file is provided, it will display its usage.</li>
</ul>

# How to us it ?

<ul>
<li>Run: make</li>
<li>Run: ./fillit ./examples/ok/TEST_FILE_NAME</li>
OR
<li>Run: ./fillit ./examples/nok/TEST_FILE_NAME (if you want to see the error handling)</li>
</ul>

![Grade](./grade_fillit.png?raw=true "Grade")
