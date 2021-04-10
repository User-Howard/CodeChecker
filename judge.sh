read -p "Please enter your folder:" t_PATH
read -p "Please enter your file(.exe):" RPOGRAM_FILE
echo $RPOGRAM_FILE

all_correct=true
for f in $t_PATH/*/*/*.in
do
    echo "${f}"
    $RPOGRAM_FILE < $f > tmp
    diff -c -b tmp ${f%.*}.ans
    if [ $? != 0 ]; then
        all_correct=false
        break
    fi
done
if [ $all_correct == true ]; then
    echo ""
    echo ""
    echo "ALL PASS"
    echo ""
    echo ""
fi
read -p "Press ENTER to exit." enter