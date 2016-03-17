set terminal png 
set output "binary_search.png"
set timestamp
set ylabel "Time (ms)"
set xlabel "Size Vector"
set title "Binary Search -> Iterative x Recursive"
set key top right
set grid
set style data lines
plot "thirdFour/binary_search_ite_thirdFour.dat" title "Third Four Iterative",\
     "thirdFour/binary_search_rec_thirdFour.dat" title "Third Four Recursive"
