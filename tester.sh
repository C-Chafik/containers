make -j re
valgrind ./ft > FT
echo
echo "<=========================VALGRIND==========================>"
echo
valgrind ./std > STD
echo "FT : "
cat FT
echo
echo "<=========================OUTPUT==========================>"
echo
echo "STD : "
cat STD
rm -rf FT STD
make -j fclean