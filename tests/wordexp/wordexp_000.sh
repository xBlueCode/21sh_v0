echo A.B
export IFS="."
echo A.B
echo "A.B"
echo `echo A.B`
echo $(echo A.B)
echo X"A.B"Y
echo X$(echo A.B)Y
echo X`echo A.B`Y
echo random_text > ign_$(echo c.d)
