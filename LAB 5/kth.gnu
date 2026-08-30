set terminal png size 800,600
set output 'kth_complexity.png'
set title 'Quickselect Kth Smallest Complexity - O(n)'
set xlabel 'Input Size (N)'
set ylabel 'Execution Time'
set grid
plot 'kth.dat' using 1:2 with linespoints lw 2 pt 7 title 'O(n)'
