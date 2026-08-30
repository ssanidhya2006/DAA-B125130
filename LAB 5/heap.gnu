set terminal png size 900,650
set output 'heap_complexity.png'
set title 'Heap Sort Complexity - O(n log n)'
set xlabel 'Input Size (N)'
set ylabel 'Execution Time'
set grid
plot 'heap.dat' using 1:2 with linespoints lw 3 pt 7 lc rgb 'purple' title 'O(n log n)'
