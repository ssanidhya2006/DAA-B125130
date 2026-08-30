set terminal png size 800,600
set output 'median_complexity.png'
set title 'Quickselect Median Complexity - O(n)'
set xlabel 'Input Size (N)'
set ylabel 'Time Complexity'
set grid
plot 'median.dat' using 1:2 with linespoints lw 2 pt 7 title 'O(n)'
