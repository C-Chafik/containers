make -j ${1}
./ft > FT
./std > STD

diff -s FT STD

echo ======= TESTING FT SPEED =========

./b_ft

echo ======= TESTING STD SPEED =========

./b_std

rm -rf FT STD
make -j fclean