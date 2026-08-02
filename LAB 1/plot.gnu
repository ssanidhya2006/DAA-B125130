set terminal pngcairo size 900,600
set output 'bubble_sort.png'
set title 'Performance Analysis of Bubble Sort'
set xlabel 'Input Size (n)'
set ylabel 'Number of Comparisons'
set grid
set key top left
plot 'bubble.dat' using 1:2 with linespoints lw 2 pt 7 title 'Optimized Bubble Sort',\
'bubble.dat' using 1:3 with linespoints lw 2 pt 5 title 'Normal Bubble Sort'
