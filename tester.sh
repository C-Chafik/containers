make -j re
valgrind ./ft_vector > FT
echo
echo "<=========================VALGRIND==========================>"
echo
valgrind ./std_vector > STD
echo "FT : "
cat FT
echo
echo "<=========================OUTPUT==========================>"
echo
echo "STD : "
cat STD
rm -rf FT STD
make -j fclean